class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int count=0;
        for(char c:seq){
            if(c=='('){
                count++;
                ans.push_back(count%2);
            }
            else{
                ans.push_back(count%2);
                count--;
            }
        }
        return ans;
    }
};