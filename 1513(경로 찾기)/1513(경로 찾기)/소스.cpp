#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int CON = 1000007;

int n, m, c;
int memo[52][52][52][52];
vector<pair<int,int> > v;

int main() {
	cin >> n >> m >> c;

	for (int i = 0; i < c; i++) {
		int a, b;
		cin >> a >> b;

		v.push_back({ a,b });
	}

	if (v[0] == make_pair(1,1)) memo[1][1][1][1] = 1;
	else memo[1][1][0][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < c; k++) {
				if (memo[i][j][k]) {
					if (i + 1 <= n) {
						for (int l = k + 1; l < c; l++) {
							if (v[l] == make_pair(i + 1, j)) {
								memo[i + 1][j][l + 1] += memo[i][j][k];
								memo[i + 1][j][l + 1] %= CON;
							}
							else {
								memo[i + 1][j][k] += memo[i][j][k];
								memo[i + 1][j][k] %= CON;
							}
						}
					}
					

						if (j + 1 <= m) {
							for (int l = k + 1; l < c; l++) {
								if (v[l] == make_pair(i, j+1)) {
									memo[i][j+1][l+1] += memo[i][j][k];
									memo[i][j+1][l+1] %= CON;
								}
								else {
									memo[i][j+1][k] += memo[i][j][k];
									memo[i][j+1][k] %= CON;
								}
							}
						}
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << memo[i][j][0] << " ";
		}
		cout << endl;
	}


	for (int k = 0; k <= c; k++) {
		cout << memo[n][m][k] << " ";
	}
}