class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> vec;
        if (s.empty() || words.empty()) return vec;

        int len = words[0].size();
        int wc = words.size();
        int tlen = len * wc;

        if (s.size() < tlen) return vec;

        unordered_map<string,int> mp;
        for (string c : words) mp[c]++;

        for (int r = 0; r < len; r++) {
            int left = r;
            int no = 0;
            unordered_map<string,int> tempu;

            for (int rr = r; rr + len <= s.size(); rr += len) {
                string ss = s.substr(rr, len);

                if (mp.count(ss)) {
                    tempu[ss]++;
                    no++;

                    while (tempu[ss] > mp[ss]) {
                        string leftWord = s.substr(left, len);
                        tempu[leftWord]--;
                        left += len;
                        no--;
                    }

                    if (no == wc) {
                        vec.push_back(left);
                    }
                } else {
                    tempu.clear();
                    no = 0;
                    left = rr + len;
                }
            }
        }

        return vec;
    }
};
