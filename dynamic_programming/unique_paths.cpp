class Solution {
private:
    int uniqPaths(vector<vector<int>>& dp,int i,int j) {
        if(i>=dp.size() || j>=dp[0].size()) return 0;
        if(i==dp.size()-1 && j==dp[0].size()-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int down = uniqPaths(dp,i+1,j);
        int right = uniqPaths(dp,i,j+1);
        return dp[i][j] = down+right;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return uniqPaths(dp,0,0);
    }
};