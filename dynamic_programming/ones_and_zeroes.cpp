class Solution {
private:
    int maxOnesAndZeroes(vector<pair<int,int>>& v,int i,int cur_zero,int cur_one,int& m,int& n,vector<vector<vector<int>>>& dp) {

        if(i>=v.size()) {
            return 0;
        }
        if(dp[i][cur_zero][cur_one]!=-1) return dp[i][cur_zero][cur_one];

        int take = 0,notTake = 0;
        
        if(cur_one+v[i].first <= n && cur_zero+v[i].second <= m) {
            take = 1+maxOnesAndZeroes(v,i+1,cur_zero+v[i].second,cur_one+v[i].first,m,n,dp);
        }
        notTake = maxOnesAndZeroes(v,i+1,cur_zero,cur_one,m,n,dp);
        return dp[i][cur_zero][cur_one] = max(take,notTake);
    }
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> v;
        for(int i=0;i<strs.size();i++) {
            int zero = 0;
            int one = 0;
            for(auto it:strs[i]) {
                if(it=='1') one++;
                else zero++;
            }
            v.push_back({one,zero});
        }
        int maxi = 0;

        vector<vector<vector<int>>> dp(v.size()+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return maxOnesAndZeroes(v,0,0,0,m,n,dp);
    }
};