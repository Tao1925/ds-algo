#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
int main(){
    string str1 = "abcde";
    string str2 = "ace";
    int len1 = str1.length();
    int len2 = str2.length();
    vvi dp(len1 + 1, vi(len2 + 1, 0));
    for (int i = 1; i <= len1; i++){
        for (int j = 1; j <= len2; j++){
            if (str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << "ans = " << dp[len1][len2] << endl;
}