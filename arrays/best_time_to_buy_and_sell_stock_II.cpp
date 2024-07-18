class Solution {
private:
    unordered_map<int, unordered_map<int, int>> dp;
    int maxP(vector<int>& prices,int i,int prev) {

        if(i>=prices.size()) {
            return 0;
        }

        if (dp[i].find(prev) != dp[i].end()) {
            return dp[i][prev];
        }

        int take = 0,notTake = 0;

        if(prev==-1 || prices[i]<prev) {
            prev = prices[i];
        }

        if(prices[i]>prev) {
            take = (prices[i]-prev) + maxP(prices,i+1,-1);
        }

        notTake = maxP(prices,i+1,prev);

        return dp[i][prev] = max(take,notTake);
    }
public:
    int maxProfit(vector<int>& prices) {
        return maxP(prices,0,-1);
    }
};