class Solution {
public:
    int compareVersion(string version1, string version2) {
        long long i1=0,i2=0;
        vector<long long> vec1,vec2;
        for(char & c: version1){
            if(c=='.'){
                vec1.push_back(i1);
                i1=0;
                continue;
            }
            i1= (10*i1+ c-'0');
        }
        vec1.push_back(i1);
        for(char & c: version2){
            if(c=='.'){
                vec2.push_back(i2);
                i2=0;
                continue;
            }
            i2=10*i2+ c-'0';
        }
        vec2.push_back(i2);
        int k= max(vec1.size(),vec2.size());
        for(int i=0;i<k;i++){
            i1= i<vec1.size()?vec1[i]:0;
            i2= i<vec2.size()?vec2[i]:0;
            
        if(i1>i2) return 1;
        else if(i1<i2) return -1;
        }
        return 0;
    }
};