class Solution {
public:
    int triangleNumber(vector<int>& nums) {
       vector<int> snums(nums);
        sort(snums.begin(), snums.end());
        int count = 0;
        for ( int n = nums.size(), k = n - 1; k > 1; --k ) {
            int i = 0, j = k - 1;
            while ( i < j ) {
                if ( snums[i] + snums[j] > snums[k] )
                    count += --j - i + 1;
                else
                    ++i;
            }
        }
        return count;
    }
};
