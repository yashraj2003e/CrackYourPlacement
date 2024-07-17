class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur = prices[0];
        int maxi = INT_MIN;

        for(int i=0;i<prices.size();i++) {

            maxi = max(maxi,prices[i]-cur);
            cur = min(prices[i],cur);

        }
        return maxi == INT_MIN ? 0 : maxi;
    }
};