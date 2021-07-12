#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int T, N, K, W;
int cost[1005];
vector <int> adj[1005];
int indeg[1005];
int dp[1005]; //시간 계산하기 위해서
queue <int> q;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> K;
        for (int j = 1; j <= N; j++) {
            cin >> cost[j];
        }
        for (int k = 0; k < K; k++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            indeg[b]++;
        }
        cin >> W;

        for (int p = 1; p <= N; p++) {
                      dp[p] = cost[p];
            if (indeg[p] == 0) {
                q.push(p);
      

            }
        }

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int w = 0; w < adj[cur].size(); w++) {
                int next = adj[cur][w];
                indeg[next]--;



                   dp[next] = max(dp[cur] + cost[next], dp[next]) ;

                if (!indeg[next]) {
                    q.push(next);
                }


            }
        }
        cout << dp[W] << "\n";
        memset(dp, 0, sizeof(dp));
        memset(indeg, 0, sizeof(indeg));
        memset(cost, 0, sizeof(cost));

        for (int i = 0; i <= 1000; i++) adj[i].clear();
    }
    return 0;
}