class Solution {
private:
    int findMin(int i,vector<int>& coins,int amount,vector<vector<int>>& dp) {
        if(amount==0) return 0;
        if(amount<0 || i==coins.size()) return 1e5;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int x = 1e5,y = 1e5;
        x = 1 + findMin(i,coins,amount-coins[i],dp);
        y = findMin(i+1,coins,amount,dp);
        return dp[i][amount] = min(x,y);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int x = findMin(0,coins,amount,dp); 
        return x>=1e5 ? -1 : x;
    }
};