class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int flag1 = 0,flag2 = 0;
        int n = matrix.size(),m = matrix[0].size();
        for(int i=0;i<n;i++) {
            if(matrix[i][0] == 0) {
                flag1 = 1;
            }
        }

        for(int i=0;i<m;i++) {
            if(matrix[0][i]==0) {
                flag2 = 1;
            }
        }

        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                if(matrix[i][j]==0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                if(matrix[0][j]==0 || matrix[i][0]==0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(flag1==1) {
            for(int i=0;i<n;i++) {
                matrix[i][0] = 0;
            }
        }

        if(flag2==1) {
            for(int i=0;i<m;i++) {
                matrix[0][i] = 0;
            }
        }
    }
};