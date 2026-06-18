vector<int> kmpTable(const string& p) {
    int n = p.size();
    vector<int> lps(n, 0);
    for (int i = 1, len = 0; i < n;){
        if (p[i] == p[len]) lps[i++] = ++len;
        else if (len) len = lps[len - 1];
        else lps[i++] = 0;
    }
    return lps;
}
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int na = a.size(), nb = b.size();
        int maxReps = (nb + na - 1) / na + 1; 
        string text = "";
        for (int i = 0; i < maxReps; i++) text += a;
        vector<int> lps = kmpTable(b);
        for (int i = 0, j = 0; i < (int)text.size(); ) {
            if (text[i] == b[j]) { i++; j++; }
            if (j == nb) {
                int start = i - nb;
                return (i + na - 1) / na;  
            }
            else if (i <text.size() && text[i] != b[j])
                j ? j = lps[j-1] : i++;
        }
        return -1;
    }
};