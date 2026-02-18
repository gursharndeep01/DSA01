class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
        long long divi= labs(dividend);
        long long d=labs(divisor);
        long long  rtrn=0;
        while(divi>=d){
            long long tempu=d;
            long long  aato=1;
            while(divi>=(tempu<<1)){
                tempu<<=1;
                aato<<=1;
            }
            divi -= tempu;
            rtrn+=aato;
        }
        if ((dividend < 0) ^ (divisor < 0)) rtrn = -1*rtrn;
        return  rtrn;
    }
};