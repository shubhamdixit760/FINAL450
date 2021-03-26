// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string>sol;
    bool isSafe(string s,vector<string>&dict)
    {
        for(auto str:dict)
        {
            if(str==s)return true;
        }
        return false;
    }
    bool solve(vector<string>&dict,string osf,string s)
    {
        if(s.size()==0)
        {
            sol.push_back(osf);
            return true;
        }
        bool res = false;
        for(int j=1;j<=s.size();j++)
        {
            if(isSafe(s.substr(0,j),dict))
            {
                res = solve(dict,osf+s.substr(0,j)+" ",s.substr(j,s.size()-j))||res;
            }
        }
        return res;
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        if(solve(dict,"",s))
            return sol;
        else{
            return vector<string>();
        }
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends