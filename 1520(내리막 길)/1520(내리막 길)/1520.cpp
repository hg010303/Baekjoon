#include<iostream>
#include<cstring>

using namespace std;

int map[510][510];
long long visit[510][510];
int m, n;

int go(int i, int j) {
	if (visit[i][j] != -1) return visit[i][j];
	int nx[] = { -1,1,0,0 };
	int ny[] = { 0,0, - 1,1 };

	visit[i][j] = 0;
	for (int k = 0; k < 4; k++) {
		int ni = i + nx[k];
		int nj = j + ny[k];
		if (ni < 0 || ni >= m) continue;
		if (nj < 0 || nj >= n) continue;

		if(map[i][j]>map[ni][nj])
			visit[i][j]+=go(ni, nj);
	}
	return visit[i][j];
}

int main() {

	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	memset(visit, -1, sizeof(visit));
	visit[m-1][n-1] = 1;

	

	cout << go(0, 0) << endl;

}