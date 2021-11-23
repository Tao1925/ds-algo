#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
int main(){
    int n = 7, k = 5;
    vvi dp(n + 1, vi(k + 1, 0));
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= min(i, k); j++){
            if (j == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    cout << "ans = " << dp[n][k] << endl;
    return 0;
}