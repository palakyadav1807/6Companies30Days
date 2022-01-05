// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string>> Anagrams(vector<string>& string_list) {
        unordered_map<string,int> group;
        int counter=0;
        for(auto str:string_list){
            string temp=str;
            sort(temp.begin(),temp.end());
            if(group.find(temp)==group.end()){
                group[temp]=counter++;
            }
        }
        vector<vector<string>> res(counter,vector<string>(0,""));
        for(auto str:string_list){
            string temp=str;
            sort(temp.begin(),temp.end());
            auto it=group.find(temp);
            res[it->second].push_back(str);
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}