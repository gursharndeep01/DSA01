class Solution {
public:
    long long countCommas(long long n) {
        long long low=1,high=9;
        long long ans=0;
        int digits=1;
        while(low<=n){
            long long more= min(n,high);
            long long count= more-low+1;
            int comas= (digits-1)/3;
            ans+= comas*count;
            low=high+1;
            digits++;
            high=high*10+9;
        }
        return ans;
    }
};