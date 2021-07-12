#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define MAX 10000+1

using namespace std;

int arr[MAX];
int n;
vector<int> edge[MAX];

int dp[MAX][2] = {};
int parent[MAX] = { -1,-1, };
vector<int> path;

void find_parent(int a) {
	for (int i : edge[a]) {
		if (i == parent[a]) continue;
		else {
			parent[i] = a;
			find_parent(i);
		}
	}
}

int dfs(int a,int b) {
	if (dp[a][b]!=-1) return dp[a][b];
	int ans = 0;
	if (b == 0) { //노드를 사용했을 경우
		for (int i : edge[a]) {
			if (i == parent[a]) continue;
			ans += dfs(i, 1);
			
		}
		return dp[a][b]= arr[a] + ans;
	}
	else { //노드를 사용하지 않았을 경우
		for (int i : edge[a]) {
			if (i == parent[a]) continue;
			ans += max(dfs(i, 1), dfs(i, 0));
			
		}
		return dp[a][b]= ans;
	}
	return dp[a][b]=0;
}

void tracking(int a,int cnt) {
	if (!cnt) {
		path.push_back(a);
		for (int i : edge[a]) {
			if (i == parent[a]) continue;
			tracking(i, 1);
		}
	}
	else {
		for (int i : edge[a]) {
			if (i == parent[a]) continue;

			if (dp[i][1] <= dp[i][0]) tracking(i, 0);
			else tracking(i, 1);
		}
	}

}


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for(int i=0;i<n-1;i++){
		int a,b;
		cin >> a>>b;

		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	memset(dp, -1, sizeof(dp));

	find_parent(1);

	int x = dfs(1, 0);
	int y = dfs(1, 1);
	int ans = max(x, y);

	if (x >= y) tracking(1, 0);
	else tracking(1, 1);

	sort(path.begin(), path.end());
	cout << ans << endl;
	for (int i = 0; i < path.size(); i++) {
		cout << path[i] << " ";
	}
}