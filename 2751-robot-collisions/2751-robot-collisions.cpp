class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n= positions.size();
        vector<int> vec(n);
        iota(vec.begin(),vec.end(),0);
        sort(vec.begin(),vec.end(),[&](int a, int b){
            return positions[a]<positions[b]; 
            });
        stack<int> stk;
        for(int &i : vec){
            if(directions[i]=='R') stk.push(i);
            else{
                while(!stk.empty() && healths[i]>0){
                int j=stk.top();
                if(healths[i]>healths[j]){
                    stk.pop();
                    healths[i]--;
                    healths[j]=0;
                }
                else if(healths[i]<healths[j]){
                    healths[j]--;
                    healths[i]=0;
                }
                else {
                    healths[i]=0;
                    healths[j]=0;
                    stk.pop();
                    }
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(healths[i]!=0) ans.push_back(healths[i]);
        }
        return ans;
    }
};