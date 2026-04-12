class Solution {
public:
    int call(int a, int b){
        if(a==26) return 0;
        return abs(a/6-b/6)+abs(a%6-b%6);
    }
    int minimumDistance(string word) {
        vector<int> vec(27,INT_MAX); vec[26]=0;
        int n= word.size(); 
        for(int i=0;i<n;i++){
            int x= word[i]-'A';
            vector<int> vecc(27,INT_MAX);
            for(int j=0;j<27;j++){
                if(vec[j]==INT_MAX) continue;
                int pre= i>0? word[i-1]-'A':26;
                vecc[j]=min(vecc[j],vec[j]+call(pre,x));
                if(pre!=26) vecc[pre]=min(vecc[pre],vec[j]+call(j,x));
            }
            vec=vecc;
        }
        return *min_element(vec.begin(),vec.end());
    }
};