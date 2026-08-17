class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if ((long long)m*k> n) return -1;
        int left=1,right=INT_MIN;
        for(int i: bloomDay) right=max(right,i);
        if((long long)m*k==n) return right;
        while(right>left){
            int mid=  left+(right-left)/2;
            int bouqet=0 ,adjacent=0;
            for(int i: bloomDay){
                if(i<=mid){
                    adjacent++;
                    if(adjacent==k){
                        bouqet++;
                        adjacent=0;
                    }
                }
                else adjacent=0; 
            }
            if(bouqet>=m) right=mid;
            else left=mid+1;
        }
        return left;
    }
};