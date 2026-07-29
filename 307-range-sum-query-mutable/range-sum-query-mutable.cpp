class NumArray {
public:
    vector<int> segTree;
    vector<int> arr;
    int n;

    void buildSeg(int left, int right, int i){
        if(left == right){
            segTree[i] = arr[left];
            return;
        }
        int mid = (left+right)/2;
        buildSeg(left,mid,2*i+1);
        buildSeg(mid+1,right,2*i+2);

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    void updateTree(int left, int right, int i, int updateIndex, int value){
        if(left == right){
            segTree[i] = value;
            return;
        }
        int mid = (left+right)/2;
        if(updateIndex <= mid){
            updateTree(left,mid,2*i+1,updateIndex,value);
        }
        else updateTree(mid+1,right,2*i+2,updateIndex,value);
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    int query(int start, int end, int left, int right, int node){
        //complete overlap
        if(left >= start && right<= end){
            return segTree[node];
        }
        if(right<start || left>end){
            return 0;
        }
        int mid = (left+right)/2;
        return query(start, end, left, mid, 2 * node + 1) + query(start, end, mid + 1, right, 2 * node + 2);
    }

    NumArray(vector<int>& nums) {
        arr = nums;
        n = nums.size();
        segTree.resize(4*n);
        buildSeg(0,n-1,0);
    }
    
    void update(int index, int val) {
        arr[index] = val;
        updateTree(0,n-1,0,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(left,right,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */