#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 1e9;

vector< pair<int, int> >adj_list[N];
int d[N];

int main() {

    int n, m;
    cin >> n >> m;

    for(int i = 1 ; i <=  n ; i++) {
        d[i] = INF;
    }

    for(int i = 0 ; i < m ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({ v, w });
    }

    int src = 1;

    d[src] = 0;

    bool negative_cycle = false;

    for(int i = 1 ; i <= n ; i++) {
        for(int node = 1 ; node <= n ; node++) {
            for(pair<int, int> adj_node: adj_list[node]) {
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;

                if(d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    if(i == n) {
                        negative_cycle = true;
                    }
                }
            }
        }
    }
    if(negative_cycle == true) {
        cout<<"Graph has negative Cycle"<<endl;
    }
    else {
        for(int i = 1 ; i <= n ; i++) {
            cout<<d[i]<<" ";
        }
    }
    cout<<endl;
    return 0;
}
