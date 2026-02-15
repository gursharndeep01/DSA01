class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> vec;
        int j=1;
        for (int i=0;i<n;i++){
            vec.push_back(j);
            if(j*10<=n) j*=10;
            else{
                if(j>=n) j/=10;
                j++;
                while(j%10==0) j/=10;
            } 
        }
        return vec;
    }
};