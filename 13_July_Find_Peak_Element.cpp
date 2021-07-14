class Solution {
public:
    
    int solve(vector<int>&nums, int low, int high){
        if(low==high)
            return low;
        else {
            int mid1 = (low+high) >> 1;
            int mid2 = mid1+1;
            if(nums[mid1] > nums[mid2]){
                return solve(nums, low, mid1);
            }
            else{
                return solve(nums, mid2, high);
            }
}
    }
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        return solve(nums, 0, high);
    }
};
