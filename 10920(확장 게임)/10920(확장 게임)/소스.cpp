#include<iostream>
#include<algorithm>
#include<queue>
#include<string>

using namespace std;

const int MAX = 1010;
typedef pair<int, int> pii;

int n, m, p;
int dep[10];
int arr[MAX][MAX];
int cnt[MAX];
queue<pii> q[10];
int n1[4] = { 1,-1,0,0 };
int n2[4] = { 0,0,1,-1 };

int main() {
	cin >> n >> m >> p;

	for (int i = 1; i <= p; i++) cin >> dep[i];

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j];

			if (arr[i][j] >= '1' && arr[i][j] <= '9') {
				q[arr[i][j] - '0'].push({ i,j });
				cnt[arr[i][j] - '0']++;
			}

		}
	}
	int a = 1;
	while (true) {
		bool stop = true;
		for (int i = 1; i <= p; i++) {
			int length = dep[i];

			while(!q[i].empty()&&length--){
				int qsize = q[i].size();

				while (qsize--) {
					auto now = q[i].front();
					q[i].pop();

					for (int j = 0; j < 4; j++) {
						int nx = now.first + n1[j];
						int ny = now.second + n2[j];

						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (arr[nx][ny] != '.') continue;

						stop = false;
						cnt[i]++;
						arr[nx][ny] = i + '0';
						q[i].push({ nx,ny });
					}
				}
			}
		}
		if (stop) break;
	}


	for (int i = 1; i <= p; i++) {
		cout << cnt[i] << " ";
	}
}