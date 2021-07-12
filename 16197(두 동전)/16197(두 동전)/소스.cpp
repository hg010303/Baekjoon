#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

int n, m;
char arr[23][23];
pair<int, int> coin1, coin2;
int n1[4] = { 0,0,1,-1 };
int n2[4] = { 1,-1,0,0 };
bool flag = false;
bool out1 = false, out2 = false;
int answer = 987654321;

bool range_over(int a, int b) {
	if (a < 0 || b < 0 || a >= n || b >= m) return true;
	return false;
}

void move(int x1, int y1, int x2, int y2, int cnt, int dir) {
	if (answer < cnt) return;
	if (cnt > 10) {
		answer = min(answer, cnt);
		return;
	}

	int nx1 = x1 + n1[dir];
	int ny1 = y1 + n2[dir];
	int nx2 = x2 + n1[dir];
	int ny2 = y2 + n2[dir];

	if (range_over(nx1, ny1) == true && range_over(nx2, ny2) == true) return;
	else if (range_over(nx1, ny1) == true && range_over(nx2, ny2)  == false){
		answer = min(answer, cnt);
		return;
	}
	else if (range_over(nx1, ny1) == false && range_over(nx2, ny2) == true) {
		answer = min(answer, cnt);
		return;
	}

	if (arr[nx1][ny1] == '#') {
		nx1 = x1;
		ny1 = y1;
	}
	if (arr[nx2][ny2] == '#') {
		nx2 = x2;
		ny2 = y2;
	}
	for (int i = 0; i < 4; i++) {
		move(nx1, ny1, nx2, ny2, cnt + 1, i);
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j];
			if (arr[i][j] == 'o') {
				if (!flag) {
					coin1 = { i,j };
					flag = true;
				}
				else coin2 = { i,j };
			}
		}
	}

//	cout << coin1.first << " " << coin2.first << endl;

	for (int i = 0; i < 4; i++) {
		int x1 = coin1.first;
		int y1 = coin1.second;
		int x2 = coin2.first;
		int y2 = coin2.second;

		move(x1, y1, x2, y2, 1, i);
	}

	if (answer > 10) cout << -1;
	else cout << answer;

}