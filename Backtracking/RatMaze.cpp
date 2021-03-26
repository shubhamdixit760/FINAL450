// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    string dir[4] = {"U","D","L","R"};
    vector<string>path;
    vector<vector<int>>vis;
    bool isSafe(vector<vector<int>>&m,int x,int y,int N)
    {
        if(x < N && x >= 0 && y < N && y>=0 && m[y][x]==1 && !vis[y][x])  
            return true;
            
        return false;
            
    }
    bool solve(vector<vector<int>>&m,int x,int y,int N ,string osf)
    {
       if(x==N-1 && y==N-1)
       {
           path.push_back(osf);
           return true;
       }
       bool res = false;
       for(int i=0;i<4;i++)
       {
           if(isSafe(m,x+dx[i],y+dy[i],N))
           {
              vis[y+dy[i]][x+dx[i]] = 1;
              res = solve(m,x+dx[i],y+dy[i],N,osf+dir[i]) || res;
              vis[y+dy[i]][x+dx[i]] = 0;
           }
       }
       return res;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0)return vector<string>();
        vis = vector<vector<int>>(n,vector<int>(n,0));
        path.clear();
        vis[0][0] = 1;
        if(solve(m,0,0,n,"")){
            sort(path.begin(),path.end());
            return path;
        }

        else 
            return vector<string>();
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    char board[2][3] = {{'.','.','\0'},{'Q','Q','\0'}};
    string s(board[0]);
    cout << s << "\n";
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}