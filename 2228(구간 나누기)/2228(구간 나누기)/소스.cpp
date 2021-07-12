#include<iostream>
#include<algorithm>

using namespace std;

const int INF = -987654321;
 
int n, m;
int memo[110][110];
int arr[110];
int sum[110];

int f(int idx, int cnt) {

//	cout << idx << " " << cnt << endl;
	if (cnt == 0) return 0;
	if (idx <2*cnt-1) return INF;
	int& ret = memo[idx][cnt];

	if (ret != INF) return ret;



	ret = f(idx - 1, cnt);


	for (int i = idx; i >= 1; i--) {
		memo[idx][cnt] = max(memo[idx][cnt], sum[idx] - sum[i - 1] + f(i - 2, cnt - 1));
	}
	return ret;
}


int main() {
	
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			memo[i][j] = INF;
		}
	}


	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	cout << f(n, m);
}