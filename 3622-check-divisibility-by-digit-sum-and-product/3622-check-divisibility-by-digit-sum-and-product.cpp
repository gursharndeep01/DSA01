class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,product=1;
        int nn=n;
        while(nn>0){
            int digit= nn%10;
            sum+=digit;
            product*= digit;
            nn/=10;
        }
        return (n%(sum+product)==0)? true:false;
    }
};