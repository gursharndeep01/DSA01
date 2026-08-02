class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left= *max_element(weights.begin(),weights.end());
        int right= 0;
        for(int num:weights) right+=num;
        int dailywt;
        while(left<right){
            dailywt= left+(right-left)/2;
            int d=1;
            int daysum=0;
            for(int weight:weights){
                if(daysum+ weight >dailywt){
                    daysum=weight;
                    d++;
                    if(d>days) break;
                }
                else daysum+=weight;
            }
            if(d>days) left=dailywt+1;
            else right=dailywt;
        }
        return right;
    }
};