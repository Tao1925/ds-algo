// LIS - longest increasing subsequence
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int len = nums.size();
    vector<int> dp(len, 0);
    for (int i = 0; i < len; i++){
        dp[i] = 1;
        for (int j = 0; j < i; j++){
            if (nums[j] < nums[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << "ans = " << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}