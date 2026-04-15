class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans=INT_MAX;
        int n=words.size();
        for(int i=0;i<n;i++){
            if(words[i]!=target) continue;
            int strt= abs(i-startIndex);
            int nostrt= n-strt;
            ans=min(ans,(min(strt,nostrt)));
        }
        return ans==INT_MAX?-1:ans;
    }
};