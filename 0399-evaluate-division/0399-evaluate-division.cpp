class Solution {
public:
      unordered_map<string,string> parent;
      unordered_map<string,double> wt;
    string find(string a){
        if(a!=parent[a]){
            string op=parent[a];
            parent[a]=find(parent[a]);
            wt[a]=wt[a]*wt[op];
        }
        return parent[a];
    }
    void uni (string a , string b,double value){
        if(!parent.count(a)){
            parent[a]=a;
            wt[a]=1.0;
        }
        if(!parent.count(b)){
            parent[b]=b;
            wt[b]=1.0;
        }
        string x=find(a);
        string y=find(b);
        if(x!=y){
            parent[x]=y;
            wt[x]=(wt[b]*value)/wt[a];
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0;i<equations.size();i++){
            uni(equations[i][0],equations[i][1],values[i]);
        }
        vector<double> ans;
        for( auto &it: queries){
            string a= it[0],b=it[1];
            if(!parent.count(a)||!parent.count(b)) ans.push_back(-1.0);
            else{
                string x=find(a),y=find(b);
                if(x!=y) ans.push_back(-1.0);
                else ans.push_back(wt[a]/wt[b]);
            }
        }
        return ans;
    }
};