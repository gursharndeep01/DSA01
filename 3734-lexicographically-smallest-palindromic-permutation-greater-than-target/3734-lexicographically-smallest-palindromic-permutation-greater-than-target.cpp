class Solution {
public:
    string buildPalindrome(vector<int>& D, int mid, int n) {
        string res(n, 'a');
        int h = D.size();
        for (int i = 0; i < h; i++) {
            res[i] = 'a' + D[i];
            res[n - 1 - i] = 'a' + D[i];
        }
        if (mid != -1) res[h] = 'a' + mid;
        return res;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char ch : s) freq[ch - 'a']++;

        int oddChar = -1, oddCount = 0;
        for (int i = 0; i < 26; i++)
            if (freq[i] % 2) { oddChar = i; oddCount++; }

        if ((n % 2 == 0 && oddCount > 0) || (n % 2 == 1 && oddCount != 1))
            return "";

        int h = n / 2;
        int mid = (n % 2) ? oddChar : -1;
        vector<int> half = freq;
        if (mid != -1) half[mid]--;
        for (int i = 0; i < 26; i++) half[i] /= 2;

        vector<int> T(n);
        for (int i = 0; i < n; i++) T[i] = target[i] - 'a';

        vector<int> remaining = half;
        int K = 0;
        for (int i = 0; i < h; i++) {
            if (remaining[T[i]] > 0) { remaining[T[i]]--; K++; }
            else break;
        }

        if (K == h) {
            vector<int> D(T.begin(), T.begin() + h);
            string cand = buildPalindrome(D, mid, n);
            if (cand > target) return cand;
        }

        int p = min(K, h - 1);
        if (K == h && h > 0) remaining[T[h - 1]]++;

        for (; p >= 0; p--) {
            for (int c = T[p] + 1; c < 26; c++) {
                if (remaining[c] > 0) {
                    remaining[c]--;
                    vector<int> D(T.begin(), T.begin() + p);
                    D.push_back(c);
                    for (int ch = 0; ch < 26; ch++)
                        D.insert(D.end(), remaining[ch], ch);
                    return buildPalindrome(D, mid, n);
                }
            }
            if (p > 0) remaining[T[p - 1]]++;
        }
        return "";
    }
};