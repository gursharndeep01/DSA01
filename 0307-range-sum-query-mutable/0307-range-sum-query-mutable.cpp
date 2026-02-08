class NumArray {
public:
    vector<int> vec;
    int n;
    void num(int idx,int low,int high,vector<int>& nums){
        if(low==high){
            vec[idx]=nums[low];
            return;
        }
        int mid= low+((high-low)>>1);
        num(2*idx+1,low,mid,nums);
        num(2*idx+2,mid+1,high,nums);
        vec[idx]=vec[2*idx+1]+vec[2*idx+2];
    }
    NumArray(vector<int>& nums) {
        n= nums.size();
        vec.resize(4*n,0);
        num(0,0,n-1,nums);
    }
    void make(int indx,int low,int high,int pos,int val){
        if(low==high){
            vec[indx]=val;
            return;
        }
        int mid= low+((high-low)>>1);
        if(mid>=pos) make(2*indx+1,low,mid,pos,val);
        else make(2*indx+2,mid+1,high,pos,val);
        vec[indx]=vec[2*indx+1]+vec[2*indx+2];
    }
    void update(int index, int val) {
     make(0,0,n-1,index,val);   
    }
    int sum(int indx,int low,int high,int left,int right){
        if(right<low || left>high){
            return 0;
        }
        if(left<=low && right>=high)  return vec[indx];
        int mid= low+((high-low)>>1);
        return sum(2*indx+1,low,mid,left,right) + 
        sum(2*indx+2,mid+1,high,left,right);
    }
    int sumRange(int left, int right) {
        return sum(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */