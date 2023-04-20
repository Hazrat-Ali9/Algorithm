// problem link - https://atcoder.jp/contests/dp/tasks/dp_a

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
/*
- state: stone(n) -> cost of reaching n-th stone from 1st stone
- recurrance: stone(n) = min(  
                            stone(n-1) + abs( h[n] - h[n-1])
                            stone(n-2) + abs( h[n] - h[n-2])
                        )
- base case: stone(1) = 0
*/
int h[N];
int dp[N];

int main() {
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; i++) {
        cin >> h[i];
    }

    // 1. handle base case
    dp[1] = 0;

    // 2. loop through the states
    for(int i = 2 ; i <= n ; i++) {
        // 2.1. solve from smaller sub-problems

        int ans1 = dp[i-1] + abs(h[i] - h[i-1]);

        // corner case
        if(i == 2) {
            dp[i] = ans1;
            continue;
        }

        int ans2 = dp[i-2] + abs(h[i] - h[i-2]);
        dp[i] = min(ans1, ans2);
    }

    cout << dp[n] << endl;
    return 0;
}



