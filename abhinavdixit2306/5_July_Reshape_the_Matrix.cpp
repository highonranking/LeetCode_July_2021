class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if(m*n != r*c) return mat;
        
        vector<vector<int>> nums(r, vector<int>(c));
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                //2d to 1d
                int k = i*c +j;
                nums[i][j] = mat[k/n][k%n];  //2d
            }
        }
        return nums;
    }
};
