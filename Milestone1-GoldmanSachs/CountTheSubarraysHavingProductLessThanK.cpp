#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int res=0;
        long long curr_product=1;
        int start=0;
        int end=0;
        while(end<n){
            curr_product*=a[end];
            while(curr_product>=k&&start<n){
                    curr_product=curr_product/a[start];
                    start++;
            }
            if(curr_product<k){
                res+=(1+(end-start));
                end++;
            }
        }
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}