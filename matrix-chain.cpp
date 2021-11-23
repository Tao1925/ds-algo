#include<iostream>
#include<vector>
#include<string>
using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
void print_chain(vvpii& dp, vpii& mats);
string rec_print_chain(vvpii& dp, vpii& mats, int beg, int en);
int main(){
    vi inp = {5, 10, 3, 12, 5, 50, 6};
    vpii mats;
    for (int i = 0; i < inp.size() - 1; i++){
        mats.push_back(make_pair(inp[i], inp[i + 1]));
    }
    int len = mats.size();
    vvpii dp(len, vpii(len, make_pair(INT_MAX, -1)));
    // dp[i][j] = (cost, split) 
    // for example:
    // dp[2][4] = (750, 3) means (A2*A3)*A4
    for (int delta = 0; delta < len; delta++){
        for (int beg = 0; beg < len - delta; beg++){
            int en = beg + delta;
            if (beg == en){
                dp[beg][en].first = 0;
            }else{
                int min_pos = -1;
                int min_cost = INT_MAX;
                for (int split = beg; split < en; split++){
                    int temp_cost = 0;
                    temp_cost += dp[beg][split].first + dp[split + 1][en].first;
                    temp_cost += mats[beg].first * mats[split].second * mats[en].second;
                    if (temp_cost < min_cost){
                        min_cost = temp_cost;
                        min_pos = split;
                    }
                }
                dp[beg][en].first = min_cost;
                dp[beg][en].second = min_pos;
            }
        }
    }
    cout << "ans = " << dp[0][len - 1].first << endl;
    print_chain(dp, mats);
}
void print_chain(vvpii& dp, vpii& mats){
    cout << rec_print_chain(dp, mats, 0, mats.size() - 1) << endl;
}
string rec_print_chain(vvpii& dp, vpii& mats, int beg, int en){
    if (beg == en){
        string ans = "";
        ans += to_string(mats[beg].first);
        ans += "*";
        ans += to_string(mats[en].second);
        return ans;
    }
    int split = dp[beg][en].second;
    string ans = "";
    ans += "(";
    ans += rec_print_chain(dp, mats, beg, split);
    ans += ")(";
    ans += rec_print_chain(dp, mats, split + 1, en);
    ans += ")";
    return ans;
}