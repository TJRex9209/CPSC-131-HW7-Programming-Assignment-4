class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int h = matrix.size(), w = (h ? matrix[0].size():0); //setting the value of h and w to the matrix size
        vector<vector<int>> dp(h, vector<int> (w, 0));// declares vector dp with h and another vector, int
        int maxlen = 0;
        for (int i = 0; i < h; ++i)// for loop for i
            for (int j = 0; j < w; ++j) //for loop for j
                maxlen = max(maxlen, dfsSearch(matrix, dp, INT_MIN, i, j)); // sets maxlens to dfs(matrix, dp, and INT_MIN,i,j)
        return maxlen;
    }
    int dfsSearch(vector<vector<int>> &mat, vector<vector<int>> &dp, int prev, int i, int j) {
        int h = mat.size(), w = mat[0].size(); //sets h to mat.size() and w to mat[0].size
        if (prev >= mat[i][j]) return 0; // if prev is greater mat[i][j] then return 0
        if (dp[i][j])  return dp[i][j]; //if dp[i][j] is true then return dp[i][j]
        
        int val = mat[i][j];
        int d[4] = {
            i ? dfsSearch(mat, dp, val, i-1, j):0, // will either evaluate dfsSearch(mat, dp, val, i-1, j) or 0 
                                                   //if i is true or false
            i+1 < h ? dfsSearch(mat, dp, val, i+1, j):0, // will evaluate dfsSearch(mat, dp, val, i+1, j) if statement is true
                                                         // or 0 if false
            j ? dfsSearch(mat, dp, val, i, j-1):0,  // will either evaluate dfsSearch(mat, dp, val, i-1, j) or 0 
                                                   //if j is true or false
            j+1 < w ? dfsSearch(mat, dp, val, i, j+1):0 // will evaluate dfsSearch(mat, dp, val, i+1, j) if statement is true
                                                         // or 0 if false
        };
        return dp[i][j] = max(d[0], max(d[1], max(d[2], d[3]))) + 1; // returns the int value
    }
};