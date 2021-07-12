#include<algorithm>
#include<deque>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

int N;

int n1[4] = { 0,0,-1,1 };
int n2[4] = { 1,-1,0,0 };

int visit[110][110][3];
char arr[110][110];

int h, w;

vector<pair<int, int> > hi;

void bfs() {
	for (int I = 0; I < 3; I++) {
		int x1 = hi[I].first;
		int y1 = hi[I].second;
		deque<pair<int, int> > q;

		q.push_back({ x1,y1 });
		visit[x1][y1][I] = 0;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop_front();
			for (int i = 0; i < 4; i++) {
				int nx = x + n1[i];
				int ny = y + n2[i];

				if (nx<0 || nx>h + 1 || ny<0 || ny>w + 1) continue;

				if (visit[nx][ny][I] >= 0 || arr[nx][ny] == '*') continue;

				if (arr[nx][ny] == '.') {
					visit[nx][ny][I] = visit[x][y][I];
					q.push_front({ nx,ny });
				}
				else if (arr[nx][ny] == '#') {
					visit[nx][ny][I] = visit[x][y][I]+1;
					q.push_back({ nx,ny });
				}
			}
		}
	}
}

int main() {
	
	scanf("%d", &N);

	while (N--) {
		memset(visit, -1, sizeof(visit));
		hi.clear();
		hi.push_back({ 0,0 });

		scanf("%d %d", &h, &w);

		for (int i = 0; i <= h+1; i++) {
			for (int j = 0; j <= w+1; j++) {
				if (i == 0 || i == h + 1 || j == 0 || j == w + 1) arr[i][j] = '.';
				else scanf(" %1c", &arr[i][j]);

				if (arr[i][j] == '$') {
					arr[i][j] = '.';
					hi.push_back({ i,j });
				}
			}
		}

		bfs();

		int ans = 987654321;

		for (int i = 0; i <= h + 1; i++) {
			for (int j = 0; j <= w + 1; j++) {
				if (arr[i][j] == '*') continue;
				int k = visit[i][j][0] + visit[i][j][1] + visit[i][j][2];
				if (arr[i][j] == '#') k -= 2;

				if (visit[i][j][0] == -1 || visit[i][j][1] == -1 || visit[i][j][2] == -1) continue;
				ans = min(ans, k);
			}
		}
/*
		for (int i = 0; i <= h + 1; i++) {
			for (int j = 0; j <= w + 1; j++) {
				printf("%2d ", visit[i][j][0]);
			}
			printf("\n");
		}
		*/
		


		printf("%d\n", ans);


	}
}