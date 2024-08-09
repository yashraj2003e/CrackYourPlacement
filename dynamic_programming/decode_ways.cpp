class Solution {
private:
    int numWays(string s,int i,vector<int>& dp) {
        if(i<s.size() && s[i]=='0') return 0;
        if(i>=s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        int ans = 0;
        ans += numWays(s,i+1,dp);
        if(i<s.size()-1 && stoi(s.substr(i,2))<=26) {
            ans += numWays(s,i+2,dp);
        }
        return dp[i] = ans;
    }
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        vector<int> dp(s.size()+1,-1);
        return numWays(s,0,dp);
    }
};