#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

vector<char> line[300];
int dist[300][300];

int visit[300];
int flow[300][300];
int ans = 0;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b;
		int c;
		cin >> a >> b >> c;
		line[a].push_back(b);
		dist[a][b] += c;
	}
	
	while (true) {
		char parent[150] = {};
		queue<char> q;
		q.push('A');
		memset(parent, ' ', sizeof(parent));
		parent['A'] = 'A';
		while (!q.empty()&&parent['Z']==' ') {
			char a = q.front();
			q.pop();
			for (int i = 0; i < line[a].size(); i++) {
				int c = line[a][i];
				if (dist[a][c] - flow[a][c] > 0 && parent[c] == ' ') {
					q.push(c);
					parent[c] = a;
				}
			}
		}
		if (parent['Z'] == ' ') break;
		int amount = 10000;
		for (char i = 'Z'; i != 'A'; i = parent[i]) {
			amount = min(amount, dist[parent[i]][i] - flow[parent[i]][i]);
		}
		for (char i = 'Z'; i != 'A'; i = parent[i]) {
			flow[parent[i]][i] += amount;
			flow[i][parent[i]] -= amount;
		}
		ans += amount;
	}
	cout << ans << endl;
}