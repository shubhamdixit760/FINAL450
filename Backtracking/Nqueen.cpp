#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>>sol;
    bool isSafe(char board[][100],int N,int row, int col)
    {
        //checking forqueen in coulmn
        for(int i=0;i<row;i++)
        {
            if(board[i][col]=='Q')
                return false;
        }
        //checking in the left diaogonal
        for(int i=row,j=col;i>=0&&j>=0;i--,j--)
        {
            if(board[i][j]=='Q')
                return false;
        }
        //checking in the right diagonal
        for(int i=row,j=col;i>=0&&j<N;i--,j++)
        {
            if(board[i][j]=='Q')
                return false;
        }
        return true;
    }
    bool solve(char board[][100],int n,int row)
    {
        if(row==n)
        {
            vector<string>temp;
            for(int i=0;i<n;i++)
            {
                board[i][n] = '\0';
                string s(board[i]);
                temp.push_back(s);
            }
            sol.push_back(temp);
            return true;
        }
        bool res = false;
        for(int i=0;i<n;i++)
        {
            if(isSafe(board,n,row,i))
            {
                board[row][i] = 'Q';
                res = solve(board,n,row+1)||res;
                board[row][i] = '.';
            }
        }
        return res;
    }
    vector<vector<string>> solveNQueens(int n) {
        sol.clear();
        sol = vector<vector<string>>();
        char board[n][100];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                board[i][j] = '.';
        }
        solve(board,n,0);
        return sol;
        
    }
};
int main()
{
    int n;
    cin >> n;
    Solution obj;
    vector<vector<string>>sol = obj.solveNQueens(n);
    int cnt = 1;
    for(auto x:sol){
        cout << "Configuration : " << cnt++ << endl;
        for(auto y:x)
            cout << y << endl;
        cout << endl;
    }
}