class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int size= digits.size();
        vector<int> freq(10,0);
        for(int i: digits) freq[i]++;
        int ans=0;
        for(int i=1;i<10;i++){
            if(!freq[i]) continue;
            for(int j=0;j<9;j+=2){
                if(freq[j]-(j==i) <=0) continue;
                for(int t=0;t<10;t++){
                    if(freq[t]-(i==t)-(t==j)>0) ans++;
                }
            }  
        }
        return ans;
    }
};