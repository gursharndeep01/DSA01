class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n= asteroids.size();
        stack<int> stak;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(asteroids[i]>0) {
                stak.push(asteroids[i]);
                continue;
            }
            int a=-1*asteroids[i];
            int top=0;
            while(!stak.empty() && stak.top()<=a) {
                top=stak.top();stak.pop();
                if(top==a) break; 
            }
            if(stak.empty() && top!=a) ans.push_back(asteroids[i]);
        }
        int i=ans.size();
        while(!stak.empty()){
            ans.push_back(stak.top());
            stak.pop();
        }
        reverse(ans.begin()+i,ans.end());
        return ans;
    }
};