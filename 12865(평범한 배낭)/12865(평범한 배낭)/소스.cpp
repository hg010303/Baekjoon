#include<iostream>
#include<algorithm>

using namespace std;

int n, k;
pair<int, int> have[101];
int memo[100100][101];


int f(int volume,int cnt) {
	if (volume < 0) return 0;
	if (cnt >= n) return 0;
	if (memo[volume][cnt]) return memo[volume][cnt];


	int ans1 = 0;

	if (volume - have[cnt].first >= 0) ans1 = f(volume - have[cnt].first, cnt + 1) + have[cnt].second;

	int ans = max(ans1, f(volume, cnt + 1));
	memo[volume][cnt] = ans;

	return ans;
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> have[i].first >> have[i].second;

	int ans = f(k, 0);

	cout << ans;
}