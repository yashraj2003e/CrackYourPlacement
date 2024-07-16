class Solution {
private:
    int mod = 1000000007;
    vector<vector<vector<int>>> dp;

    int count(vector<vector<int>>& keypad, int i, int j, int n) {
        if (i < 0 || j < 0 || i >= keypad.size() || j >= keypad[0].size() || keypad[i][j] == -1) {
            return 0;
        }
        
        if (n == 0) {
            return 1;
        }
        
        if (dp[i][j][n] != -1) {
            return dp[i][j][n];
        }

        int result = 0;
        result = (result + count(keypad, i - 2, j - 1, n - 1)) % mod;
        result = (result + count(keypad, i - 2, j + 1, n - 1)) % mod;
        result = (result + count(keypad, i - 1, j + 2, n - 1)) % mod;
        result = (result + count(keypad, i + 1, j + 2, n - 1)) % mod;
        result = (result + count(keypad, i - 1, j - 2, n - 1)) % mod;
        result = (result + count(keypad, i + 1, j - 2, n - 1)) % mod;
        result = (result + count(keypad, i + 2, j - 1, n - 1)) % mod;
        result = (result + count(keypad, i + 2, j + 1, n - 1)) % mod;
        
        dp[i][j][n] = result;
        return result;
    }

public:
    int knightDialer(int n) {
        vector<vector<int>> keypad = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {-1, 0, -1}
        };

        dp = vector<vector<vector<int>>>(4, vector<vector<int>>(3, vector<int>(n, -1)));
        
        int c = 0;
        for (int i = 0; i < keypad.size(); i++) {
            for (int j = 0; j < keypad[0].size(); j++) {
                if (keypad[i][j] != -1) {
                    c = (c + count(keypad, i, j, n - 1)) % mod;
                }
            }
        }
        return c;
    }
};
