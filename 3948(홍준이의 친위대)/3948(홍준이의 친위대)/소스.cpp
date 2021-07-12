#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long ll;

ll memo[21][21][2];

ll dp(int n, int idx, int cnt) {
	if (n == 1) return 1;

	ll& ret = memo[n][idx][cnt];

	if (ret != -1) return ret;


}

ll f(int a) {
	ll ans = 0;
	for (int i = 1; i <= a; i++) {
		ans += (dp(a, i, 1) + dp(a, i, 0));
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(memo, -1, sizeof(memo));

	int n;
	cin >> n;

	while (n--) {
		int a;
		cin >> a;
		cout << f(a) << endl;
	}
}