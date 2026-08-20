class Solution {
public:
    pair<int,int> row_col(int n,int x){
        int row= (x-1)/n;
        int col= (x-1)%n;
        if(row%2==1) col= n-col-1;
        row= n-row-1;
        return {row,col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n= board.size();
        queue<int> q;
        q.push(1);
        vector<bool> visited(n*n+1,false);
        visited[1]=true;
        int count=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int curr=q.front();q.pop();
                if(curr==n*n) return count;
                for(int dice=1;dice<=6;dice++){
                    if(dice+curr>n*n) continue;
                    int next= curr+dice;
                    auto[row,col] =row_col(n,next);
                    int val= board[row][col];
                    int dest;
                    if(val==-1) dest= next;
                    else dest=val;
                    if(!visited[dest]){
                        visited[dest]=true;
                        q.push(dest);
                    }
                }
            }
            count++;
        }
        return -1;
    }
};