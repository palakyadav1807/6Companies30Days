#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    string printMinNumberForPattern(string S){
        string res="";
        int count=0;
        stack<int> st;
        for(char ch:S){
            if(ch=='D'){
                count++;
                st.push(count);
            }else{
                count++;
                st.push(count);
                while(st.empty()==false){
                    res+=to_string(st.top());
                    st.pop();
                }
            }
        }
        count++;
        st.push(count);
        while(st.empty()==false){
            res+=to_string(st.top());
            st.pop();
        }
        return res;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
}