class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0,r=0, dist=0;
        for(auto & m: moves){
            if(m=='L') l++;
            else if(m=='R') r++;
        }
        if(l>r){
            for( auto &m: moves){
                if(m=='R') dist++;
                else dist--;
            }
        }
        else {
            for( auto & m: moves){
                if(m=='L') dist--;
                else dist++;
            }
        }
        return abs(dist);
    }
};