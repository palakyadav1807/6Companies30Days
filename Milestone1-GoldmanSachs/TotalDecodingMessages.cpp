#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int CountWays(string str){
		    if(str[0]=='0'||str.find("00",0)!=string::npos){
		        return 0;
		    }else{
		        long long dp[str.size()];
		        dp[0]=1;
		        for(int i=1;i<str.size();i++){
		            if(str.substr(i-1,i+1)=="00"){
		                dp[i]=0;
		            }else if(str[i]=='0'&&str[i-1]!='0'){
		                if(str[i-1]=='1'||str[i-1]=='2'){
		                    dp[i]=(i>=2?dp[i-2]:1)%1000000007;
		                }else{
		                    dp[i]=0;
		                }
		            }else if(str[i]!='0'&&str[i-1]=='0'){
		                dp[i]=dp[i-1]%1000000007;
		            }else{
		                string sub=str.substr(i-1,2);
		                if(stoi(sub)<=26){
		                    dp[i]=(dp[i-1]+(i>=2?dp[i-2]:1))%1000000007;
		                }else{
		                    dp[i]=dp[i-1]%1000000007;
		                }
		            }
		        }
	            return dp[str.size()-1]%1000000007;
		    }
		}

};
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}