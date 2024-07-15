class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1);
        result[0] = 0;
        for(int i=1;i<=n;i++) {
            result[i] = result[i/2] + i%2;
        }
        return result;
    }
};