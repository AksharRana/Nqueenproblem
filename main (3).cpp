class Solution {
public:
    bool isSafe(vector<string>&board,int x,int y,int n){
        for(int row=0;row<x;row++){
            if(board[row][y]=='Q'){
            return false;
            }
        }
        int row=x;
        int col=y;
        while(row>=0&&col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row=x;
        col=y;
        while(row>=0&&col<n){
            if(board[row][col]=='Q'){
            return false;
            }
            row--;
            col++;
        }
        return true;
    }

    void Nqueen(vector<string>&board,vector<vector<string>>&ans,int x,int n){
        if(x==n){
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafe(board,x,col,n)){
                board[x][col]='Q';
                Nqueen(board,ans,x+1,n);
                board[x][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>>ans;
            vector<string>board(n);
            string s(n,'.');
            for(int i=0;i<n;i++){
                board[i]=s;
            }
            Nqueen(board,ans,0,n);
            return ans;
    }    
};