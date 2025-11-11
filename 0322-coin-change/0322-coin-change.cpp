class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> vec(amount+1,INT_MAX);
        vec[0]=0;
        for(int i=0;i<=amount;i++){
            for(int coin: coins){
                if(i>=coin && vec[i-coin]!=INT_MAX) vec[i]=min(vec[i],1+vec[i-coin]);
            }
        }
        return vec[amount]==INT_MAX?-1:vec[amount];
    }
};