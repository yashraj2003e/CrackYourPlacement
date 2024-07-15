class Solution {
private:
    int pathSum(vector<vector<int>>& grid,vector<vector<int>>& dp,int i,int j) {
        if(i>=grid.size() || j>=grid[0].size()) return 1e9;
        if(i==grid.size()-1 && j==grid[0].size()-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down = grid[i][j] + pathSum(grid,dp,i+1,j);
        int right = grid[i][j] + pathSum(grid,dp,i,j+1);
        return dp[i][j] = min(down,right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return pathSum(grid,dp,0,0);
    }
};