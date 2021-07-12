#include<iostream>

using namespace std;

int map[113][113];
long long visit[113][113];

int main() {
	int n;
	
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}

	visit[1][1] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 0) continue;
			if(i + map[i][j]<=n) visit[i + map[i][j]][j] += visit[i][j];
			if (j + map[i][j] <= n)	visit[i][j + map[i][j]] += visit[i][j];
			

		}
	}


	cout << visit[n][n] << endl;
	return 0;
	
}