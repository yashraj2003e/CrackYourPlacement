class Solution
{
    private:
    int maxCut(int n,int x,int y,int z,vector<int>& dp) {
        if(n==0) {
            return 0;
        }
        if(n<0) {
            return -1e9;
        }
        if(dp[n]!=-1) return dp[n];
        int cut_x = 1+maxCut(n-x,x,y,z,dp);
        int cut_y = 1+maxCut(n-y,x,y,z,dp);
        int cut_z = 1+maxCut(n-z,x,y,z,dp);
        
        return dp[n] = max(cut_x,max(cut_y,cut_z));
    }
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> dp(n+1,-1);
        int res = maxCut(n,x,y,z,dp);
        return res < 0 ? 0 : res;
    }
};