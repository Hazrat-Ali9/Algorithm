// problem link - https://atcoder.jp/contests/dp/tasks/dp_d

#include<bits/stdc++.h>
using namespace std;
/*
    - state: knapsack(n, cap) -> maximum profit considering objects 1 to n and capacity=cap
    - recurrance: 
        knapsack(n, cap) -> max {
                                val[n] + knapsack(n - 1, cap - wt[n]),
                                knapsack(n - 1, cap)
                            }
    - base_case: knapsack(0, x) = 0
*/
const int N = 102;
const int M = 1e5 + 5;

long long dp[N][M];
int wt[N], val[N];

long long knapsack(int n, int cap) {
    // 1. base case
    if(n == 0) {
        return 0;
    }
    // 2. if result is already calculated for this state return it
    if(dp[n][cap] != -1) {
        return dp[n][cap];
    }


    // 3. calculate result from smaller sub-problems
    if(cap < wt[n]) {
        long long ans = knapsack(n-1, cap);
        dp[n][cap] = ans;
        return ans;
    }

    long long ans1 = val[n] + knapsack(n - 1, cap - wt[n]);
    long long ans2 = knapsack(n-1, cap);

    long long ans = max(ans1, ans2);
    dp[n][cap] = ans;

    return ans;
}

int main() {
    int n, cap;
    cin >> n >> cap;

    for(int i = 1 ; i <= n ; i++) {
        cin >> wt[i] >> val[i];
    }

    for(int i = 0 ; i <= n ; i++) {
        for(int j = 0 ; j <= cap ; j++) {
            dp[i][j] = -1;
        }
    }

    cout << knapsack(n, cap) << endl;
    return 0;

}