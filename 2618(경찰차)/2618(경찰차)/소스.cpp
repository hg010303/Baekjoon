#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define MAX 1000+1

using namespace std;

int n, w;
pair<int,int> clue[MAX];
int memo[MAX][MAX];

int f(int a,int b) {
	if (a == w || b == w) return 0;
	if (memo[a][b]) return memo[a][b];
	int cnt = max(a, b) + 1;
	int dis = 0;
	if (a == 0) {
		dis = clue[cnt].first + clue[cnt].second - 2;
	}
	else {
		dis = abs(clue[cnt].first - clue[a].first) + abs(clue[cnt].second - clue[a].second);
	}

	int ans1 = f(cnt, b) + dis;

	if (b == 0) {
		dis = 2 * n - clue[cnt].first - clue[cnt].second;
	}
	else {
		dis = abs(clue[cnt].first - clue[b].first) + abs(clue[cnt].second - clue[b].second);
	}
	int ans2 = f(a, cnt) + dis;

	return memo[a][b] = min(ans1, ans2);

}

vector<int> path;

void tracking(int a, int b) {
	if (a == w || b == w) return;
	int cnt = max(a, b) + 1;
	int dis = 0;
	if (a == 0) {
		dis = clue[cnt].first + clue[cnt].second - 2;
	}
	else {
		dis = abs(clue[cnt].first - clue[a].first) + abs(clue[cnt].second - clue[a].second);
	}

	int ans1 = memo[cnt][b] + dis;

	if (b == 0) {
		dis = 2 * n - clue[cnt].first - clue[cnt].second;
	}
	else {
		dis = abs(clue[cnt].first - clue[b].first) + abs(clue[cnt].second - clue[b].second);
	}
	int ans2 = memo[a][cnt] + dis;

	if (ans1 > ans2) {
		path.push_back(2);
		tracking(a, cnt);
	}
	else {
		path.push_back(1);
		tracking(cnt, b);
	}

}

int main() {
	cin >> n >> w;

	for (int i = 1; i <= w; i++) {
		int a, b;
		cin >> a >> b;
		clue[i] = { a, b };
	}

	//1,1/n,n

	

	cout << f(0, 0)<<endl;
	tracking(0, 0);
	for (int i = 0; i < path.size(); i++)
		cout << path[i] << endl;

}