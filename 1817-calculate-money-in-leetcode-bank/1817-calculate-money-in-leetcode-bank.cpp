class Solution {
public:
    int totalMoney(int n) {
        int start=0,add=0,total=0;
        for(int i=1;i<=n;i++){
            if((i%7)==1){
                start++;
                add=start;
            }
            total+=add;
            add++;
        }
        return total;
    }
};