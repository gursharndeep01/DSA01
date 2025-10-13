class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int minus=0;
        int bal=0;
        int start=0;
        int petrol;
        for(int i=0;i<gas.size();i++){
           petrol=bal+gas[i];
           if(petrol-cost[i]<0){
            minus=petrol-cost[i]+minus;
            bal=0;
            start=i+1;
           }
           else{
            bal=petrol-cost[i];
           }
        }
        if(bal+minus>=0) return start;
        return -1;
    }
};