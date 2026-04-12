class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec;
        vector<int> veccc;
        for(int i=0;i<numRows;i++){
            vector<int>vecc;
            vecc.push_back(1);
            for(int j=1;j<=i;j++){
                if(j==i) {
                    vecc.push_back(1);
                    continue;
                    }
                int a=veccc[j]+veccc[j-1];
                vecc.push_back(a);
            }
            veccc=vecc;
            vec.push_back(vecc);
        }
        return vec;
    }
};