// problem link - https://atcoder.jp/contests/dp/tasks/dp_c

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
/*
- state: fun(n, x) -> maximum happiness till day-n
                      if we pick task-x on day-n

- recurrance: fun(n, x) = max {
                            fun(n - 1, y) where x != y
                            + happiness[n][x]
                         }
- base case: fun(1, x) = happiness[1][x]
*/

int happiness[N][4], dp[N][4];

int fun(int day, int current_task) {
    // 1. handle base case
    if( day == 1) {
        return happiness[day][current_task];
    }

    // 2. if answer is already calculated return it
    if(dp[day][current_task] != -1) {
        return dp[day][current_task];
    }

    int max_profit = 0;

    // 3. calculate the answer from smaller sub problems
    for(int last_task = 1 ; last_task <= 3 ; last_task++) {
        if(last_task != current_task) {
            int candidate_profit = fun(day - 1, last_task) + happiness[day][current_task];
            max_profit = max(max_profit, candidate_profit);
        }
    }

    dp[day][current_task] = max_profit;
    return max_profit;
}

int main() {
    int n;
    cin >> n;

    for(int i = 1 ; i <= n ; i++) {
        // int a, b, c;
        // cin >> a >> b >> c;
        // happiness[i][1] = a;
        // happiness[i][2] = b;
        // happiness[i][3] = c;
        for(int j = 1 ; j <= 3 ; j++) {
            cin >> happiness[i][j];
        }
    }

    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= 3 ; j++) {
            dp[i][j] = -1;
        }
    }

    int ans_1 = fun(n, 1);
    int ans_2 = fun(n, 2);
    int ans_3 = fun(n, 3);

    cout << max({ans_1, ans_2, ans_3}) << endl;
    return 0;
}

// max(a, b)

// max({1 ,2 , 3 , 4})