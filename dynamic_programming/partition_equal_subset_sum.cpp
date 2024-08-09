class Solution{
private:
    int canPartition(int arr[],int i,int N,int& sum,int cur,vector<vector<int>>& dp) {
        
        if(sum-cur == cur) {
            return 1;
        }
        
        if(i>=N) {
            return 0;
        }
        
        if(dp[i][cur]!=-1) return dp[i][cur];
        
        int take = 0,notTake = 0;
        take = canPartition(arr,i+1,N,sum,cur+arr[i],dp);
        notTake = canPartition(arr,i+1,N,sum,cur,dp);

        return dp[i][cur] = take | notTake;
    }
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0;i<N;i++) {
            sum+=arr[i];
        }
        
        vector<vector<int>> dp(N,vector<int>(sum+1,-1));
        
        return canPartition(arr,0,N,sum,0,dp);
        
    }
};