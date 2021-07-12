#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int INF = -987654321;

int n, a, b, c;
long long memo[11][110][110][110];

int f2(int idx) {
	if (idx == 2) return 2;
	if (idx == 4) return 6;
	if (idx == 6) return 20;
	if (idx == 8) return 70;
	if (idx == 10) return 252;
}

int f3(int idx) {
	if (idx == 3) return 6;
	if (idx == 6) return 90;
	if (idx == 9) return 1680;
}

long long f(int idx, int r, int g, int b) {
	if (idx == 0) return 1;
	if (r + g + b < idx * (idx + 1) / 2) return 0;

	long long& ret = memo[idx][r][g][b];
	if (ret != -1) return ret;
	ret = 0;
	//1개만 이용
	if (idx <= r) ret += f(idx - 1, r - idx, g, b);
	if (idx <= g) ret += f(idx - 1, r, g-idx, b);
	if (idx <= b) ret += f(idx - 1, r, g, b-idx);

	//2개를 이용
	if (idx % 2 == 0) {
		if (idx / 2 <= r && idx / 2 <= g) ret += f(idx - 1, r - idx / 2, g - idx / 2, b) * f2(idx);
		if (idx / 2 <= g && idx / 2 <= b) ret += f(idx - 1, r, g - idx / 2, b-idx/2) * f2(idx);
		if (idx / 2 <= r && idx / 2 <= b) ret += f(idx - 1, r - idx / 2, g, b-idx/2) * f2(idx);
	}

	if (idx % 3 == 0) {
		if (idx / 3 <= r && idx / 3 <= g && idx / 3 <= b) ret += (f(idx - 1, r - idx / 3, g - idx / 3, b - idx / 3)) * f3(idx);
	}

	return ret;

}

int main() {
	cin >> n >> a >> b >> c;

	memset(memo, -1, sizeof(memo));

	cout << f(n, a, b, c);
}