class Solution {
public:

    bool isSafe(int n , vector<string>& board , int row , int col){

        for(int i = 0 ; i < n ; i++){
            if(board[row][i] == 'Q') return false;
        }

        for(int i = 0 ; i < n ; i++){
            if(board[i][col] == 'Q') return false;
        }

        for(int k = row - 1 , l = col - 1 ; k >= 0 && l >= 0 ; k-- , l--){
            if(board[k][l] == 'Q') return false;
        }

        for(int k = row - 1 , l = col + 1; k >= 0 && l < n ; k-- , l++){
            if(board[k][l] == 'Q') return false;
        }
        return true;
    }

    void solve(int n , vector<string>& board , vector<vector<string>>& ans , int row){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int i = 0 ; i < n ; i++){
            if(isSafe(n , board , row , i)){
                board[row][i] = 'Q';
                solve(n , board , ans , row + 1);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n , string(n , '.'));
        vector<vector<string>>ans;
        solve(n , board , ans , 0);

        return ans;
    }
};
