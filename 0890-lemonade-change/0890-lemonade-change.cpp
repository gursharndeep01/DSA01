class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int panj =0, das=0;
        for(int &i :bills){
            if(i==5)panj++;
            else if(i==10) {
                if(panj==0) return false;
                panj--;das++;
                }
            else {
                if(panj>0 && das>0){
                    panj--;das--;
                }
                else if(panj>=3) panj-=3;
                else return false ;
            }   
        }
        return true;
    }
};