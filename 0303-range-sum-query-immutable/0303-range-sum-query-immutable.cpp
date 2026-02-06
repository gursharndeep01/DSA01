class NumArray {
public:

    vector<int> vec;
    int n;
    void make(int value,int i){
        i++;
        while(i<=n){
            vec[i]+=value;
            i=i+(i&(-i));
        }
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        vec.resize(n+1,0);
        for(int i=0;i<n;i++){
            make(nums[i],i);
        }
    }
    int sum(int i){
        i++;
        int add=0;
        while(i>0){
            add+=vec[i];
            i=i-(i&(-i));
        }
        return add;
    }
    int sumRange(int left, int right) {
        return sum(right)-sum(left-1);
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */