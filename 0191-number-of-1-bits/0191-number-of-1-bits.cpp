class Solution {
public:
    int hammingWeight(int n) {
        int count;
        while(n>0){
            count++;
            n= n&(n-1);
        }
        return count;
    }
};