#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n;
int map[20][20];
int answer = 0;

void dfs(int idx) {
	if (idx == 5) {
		int ret = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ret = max(ret, map[i][j]);

		answer = max(answer, ret);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int now[20][20];
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++) now[j][k] = map[j][k];

		for (int x = 0; x < n; x++) {
			vector<int> tmp;
			for (int y = 0; y < n; y++) 
				if ((i < 2 ? map[x][y] : map[y][x]) != 0)
					tmp.push_back((i < 2 ? map[x][y] : map[y][x]));

			if (i == 1 || i == 3)
				reverse(tmp.begin(), tmp.end());
			vector<int> perm;

			for (int y = 0; y < tmp.size(); y++)
				if (y + 1 < tmp.size() && tmp[y] == tmp[y + 1]) {
					perm.push_back(tmp[y] * 2);
					y++;
				}
				else
					perm.push_back(tmp[y]);

			for (int p = perm.size(); p < n; p++)
				perm.push_back(0);

			if (i == 1 || i == 3) reverse(perm.begin(), perm.end());

			for(int y=0;y<n;y++) (i < 2 ? map[x][y] : map[y][x]) = perm[y];
		}
		dfs(idx + 1);
		
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++) map[j][k] = now[j][k];
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	
	dfs(0);

	cout << answer << endl;
}