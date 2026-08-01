class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=0;
        for(int pile: piles) if(pile>high) high=pile;
        while(high>low){
            int speed=  low+(high-low)/2;
            int hours=0;
            for(int pile: piles) hours+= (pile+speed-1)/speed;
            if(hours>h) low=speed+1;
            else high=speed;
        }
        return high;
    }
};