class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size(), nn=n/3.0f;
        vector<int> vec;
        int r1=0,r2=11,c1=0,c2=0;
        for(int & i:nums){
            if(i==r1) c1++;
            else if(i==r2) c2++;
            else if(c1==0){ c1++;r1=i;}
            else if(c2==0){c2++; r2=i;}
            else {c1--;c2--;};
        }
        c1=0,c2=0;
        for(int &i: nums) {
            if(r1==i)c1++;
            if(r2==i) c2++;
        }
        if(c1>nn) vec.push_back(r1);
        if(c2>nn) vec.push_back(r2);
        return vec;
    }
};