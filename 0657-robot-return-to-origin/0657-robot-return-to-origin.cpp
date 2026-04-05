class Solution {
public:
    bool judgeCircle(string moves) {
        int vertical=0,horizntl=0;
        for(char &i: moves ){
            if( i=='U') vertical++;
            else if(i=='D') vertical--;
            else if (i=='L') horizntl++;
            else horizntl--;
        }
        return vertical==0 && horizntl==0;
    }
};