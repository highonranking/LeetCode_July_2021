class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        // we are bascially finding the maximum from left for which it is smaller than minimum from right
        int n = nums.size();
        int leftmax[n];
        int rightmin[n];
        int tmp = nums[0];
        for(int i=0; i<n; i++){
            tmp = max(tmp, nums[i]);
            leftmax[i] = tmp;
        }
        
        tmp = nums[n-1];
        for(int i= n-1; i>=0; i--){
            tmp = min(tmp, nums[i]);
            rightmin[i] = tmp;
        }
        
        for(int i=1; i<n; i++){
            if(leftmax[i-1] <= rightmin[i])
                return i;
        }
        return -1;
                                              
    }
};
