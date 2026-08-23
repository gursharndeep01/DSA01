class Solution {
public:
    bool sumGame(string num) {
       int n=num.size();
       int suml=0,sumr=0;
       int qcntl=0,qcntr=0;
       for(int i=0;i<n/2;i++){
        if(num[i]=='?') qcntl++;
        else suml+=(num[i]-'0');
       }
       for(int i=n/2;i<n;i++){
        if(num[i]=='?') qcntr++;
        else sumr+=(num[i]-'0');
       }
       if((qcntl+qcntr)%2!=0) return true;
       int sum= suml-sumr;
       int cnt= qcntr - qcntl;
       return (2*sum!= cnt*9);
    }
};