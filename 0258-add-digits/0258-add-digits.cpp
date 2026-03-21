class Solution {
public:
    int addDigits(int num) {
        
        while((num/10)!=0){
            int clone=0;
            while(num!=0){
                int dgt=num%10;
                clone+=dgt;
                num/=10;
            }
            num=clone;
        }
        return num;
    }
};