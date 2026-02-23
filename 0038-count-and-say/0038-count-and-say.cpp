class Solution {
public:
    string countAndSay(int n) {
        string rtrn = "1";
        for(int j=1;j<n;j++){
        string prev= "";
        int cnt=1;
        for(int i=1;i<rtrn.size();i++){
            if(rtrn[i]==rtrn[i-1]) cnt++;
            else{
                prev+=to_string(cnt);
                prev+= rtrn[i-1];
                cnt=1;
            }
        }
        prev+=to_string(cnt);
        prev+=rtrn.back();
        rtrn=prev;
        }
        return rtrn;
    }
};