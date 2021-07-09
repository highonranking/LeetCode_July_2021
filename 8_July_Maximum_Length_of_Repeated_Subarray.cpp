class Solution {
public:
    
                                /// M1///////////////////////
//     int solve(vector<int>&nums1, int n, vector<int>&nums2, int m, vector<vector<vector<int>>> &dp, int count ){
//         if(dp[n][m][count]!=-1) return dp[n][m][count];
//         if(n==0 || m==0) return dp[n][m][count] = 0;
//         int count1 = count;
//             if(nums1[n-1] == nums2[m-1])    count1 = solve(nums1, n-1, nums2, m-1, dp, count+1);
//             int count2 = solve(nums1, n-1, nums2, m-1, dp, 0);
//         int count3 = solve(nums1, n-1, nums2, m-1, dp, 0);
        
//         return dp[n][m][count] = max(count1, max(count2, count3));
//     }
//     int findLength(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         int m = nums2.size();
//         int count=0;
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(-1)));
        
//         return solve(nums1, n, nums2, m, dp, count);
//     }
    
    
    ////////////////////////m2//////////////////////////
    
//     int solve(vector<int>&nums1, int n, vector<int>&nums2, int m, int count){
//         if(n<=0 || m<=0) return count;
//         int count1 = count;
//         if(nums1[n-1] == nums2[m-1]) count1 = solve(nums1, n-1, nums2, m-1, count+1);
//         int count2 = solve(nums1, n, nums2, m-1,0);
//         int count3 = solve(nums1, n-1, nums2, m, 0);
        
//         return max(count1, max(count2, count3));
//     }
//     int findLength(vector<int>& nums1, vector<int>& nums2){
//          int n = nums1.size();
//          int m = nums2.size();
//         int count =0;
//         return solve(nums1, n, nums2, m, count);
//     }
    
    //////////////////////m3////////////////////////////
    int findLength(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        if (!m || !n) return 0;
        vector<int> dp(n + 1);
        int res = 0;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                res = max(res, dp[j] = a[i] == b[j] ? 1 + dp[j + 1] : 0);
            }
        }
        return res;
    }
};
