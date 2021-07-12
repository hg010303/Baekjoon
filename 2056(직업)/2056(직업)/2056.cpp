#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int time[10010];
int num[10010];
int gp[10010][103];
int ans[10010];


int main() {
	int n;
	cin >> n;

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		cin >> time[i] >> num[i];
		for (int j = 0; j < num[i]; j++) cin >> gp[i][j];
		if (num[i] == 0) {
			q.push(i);
			ans[i] = time[i];
		}
	}
	
	while (q.size()!=0) {
		int a = q.front();
		q.pop();
		for (int i = 0; i < num[a]; i++) {
			if (ans[gp[num[a]][i]] == 0) ans[gp[num[a]][i]] = ans[a] + time[i];
			else ans[gp[num[a]][i]] = max(ans[gp[num[a]][i]], ans[a] + time[i]);

		}
	}
	
}