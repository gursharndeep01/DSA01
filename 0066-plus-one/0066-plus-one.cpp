class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n= digits.size();
        if(digits[n-1]!=9) {
            int x= digits[n-1];
            digits.pop_back();
            x++;
            digits.push_back(x);
            return digits;
        }
        else {
            digits.resize(n+1);
            digits[n]=0;
            n--;
            while(n>0 && digits[n-1]==9){
                digits[n]=0;
                n--;
            }
            if(digits[0]==9 && n==0) {
                digits[1]=0;
                digits[0]=1;
                return digits;
            }
            else {
                digits[n]=digits[n-1]+1;
                n--;
                while(n>0){
                    digits[n]=digits[n-1];
                    n--;
                }
                return vector<int>(digits.begin()+1,digits.end());
                }
        }
    }
};