class Solution {
private:
    bool dfs(vector<vector<char>>& board,string& word,vector<vector<int>>& vis,int row,int col,int index) {
        vis[row][col] = 1;
        
        if(index==word.size()) {
            return true;
        }
        
        
        for(int i=-1;i<=1;i++) {
            for(int j=-1;j<=1;j++) {
                if(abs(abs(i)-abs(j))>0) {
                    int nrow = row+i;
                    int ncol = col+j;
                    if(nrow>=0 && ncol>=0 && nrow<board.size() && ncol<board[0].size() && vis[nrow][ncol]==0 && word[index]==board[nrow][ncol]) {
                        if(dfs(board,word,vis,nrow,ncol,index+1)) return true;
                    }
                }
            }
        }
        vis[row][col] = 0;
        return false;
        
        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                if(board[i][j]==word[0]) {
                    if(dfs(board,word,vis,i,j,1)) return true;
                }
            }
        } 
        return false;
        
        
    }
};