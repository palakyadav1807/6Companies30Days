#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}

string encode(string src)
{     
    string res="";
    int count=1;
    for(int i=1;i<src.size();i++){
        if(src[i]==src[i-1]){
            count++;
        }else{
            res+=src[i-1]+to_string(count);
            count=1;
        }
    }
    res+=src[src.size()-1]+to_string(count);
    return res;
} 