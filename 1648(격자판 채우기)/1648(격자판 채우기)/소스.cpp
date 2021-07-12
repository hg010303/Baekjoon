#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MOD = 9901;

int n, m;
vector<int> v;
int memo[15*15][(1 << 15)];

int f(int idx, int bin) {
//	cout << idx << " " << bin << endl;
	if (idx >= n*m) {
		if (bin == 0) return 1;
		else return 0;
	}
	
	int& ret = memo[idx][bin];
	if (ret != -1) return ret;
	ret = 0;

	int x = idx / m;
	int y = idx % m;

	if ((bin & 1) == 1) ret = f(idx + 1, (bin >> 1));
	else {
		if (y!=m-1&&((bin & 1) == 0) && ((bin & 2) == 0)) ret += f(idx + 2, (bin >> 2));
		ret += f(idx + 1, (bin >> 1) | (1 << (m - 1)));

	}
	ret %= MOD;
	return ret;

}

int main() {
	cin >> n >> m;

	memset(memo, -1, sizeof(memo));


	cout << f(0, 0);
}