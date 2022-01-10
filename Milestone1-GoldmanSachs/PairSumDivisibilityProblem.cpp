#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        if(nums.size()%2!=0){
            return false;
        }
        int rem[nums.size()];
        for(int i=0;i<nums.size();i++){
            rem[i]=nums[i]%k;
        }
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            if(map.count(k-rem[i])==1){
                map[k-rem[i]]--;
                if(map[k-rem[i]]==0){
                    map.erase(k-rem[i]);
                }
            }else if(rem[i]==0&&map.count(0)==1){
                map[0]--;
                if(map[0]==0){
                    map.erase(0);
                }
            }else{
                map[rem[i]]++;
            }
        }
        if(map.empty()==true) return true;
        else return false;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}