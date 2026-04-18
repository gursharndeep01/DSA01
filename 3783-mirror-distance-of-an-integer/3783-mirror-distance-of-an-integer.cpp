class Solution {
public:
    int mirrorDistance(int n) {
        int digit=0,tempu=n;
        while(n>0){
            digit=digit*10+ n%10;n/=10;
        }
        return abs(tempu-digit);
    }
};