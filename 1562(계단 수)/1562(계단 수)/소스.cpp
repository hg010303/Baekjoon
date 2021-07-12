#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int CON = 1000000000;

int n;
int memo[103][10][1050];

int f(int idx, int cnt, int flag) {
	if (cnt > 9 || cnt < 0) return 0;

	if (idx >= n-1) {
//		cout << flag << endl;
		if (flag == 1023) return 1;
		else return 0;
	}



	int& ret = memo[idx][cnt][flag];
	if (ret != -1) return ret;

	ret = f(idx + 1, cnt + 1, flag | (1 << (cnt + 1)));
	if(cnt>0)
		ret += f(idx + 1, cnt - 1, flag | (1 << (cnt - 1)));

	ret %= CON;

	return ret;
}

int main(){
	cin >> n;

	memset(memo, -1, sizeof(memo));

	if (n < 10) {
		cout << 0 << endl;
		return 0;
	}
	if (n == 10) {
		cout << 1 << endl;
		return 0;
	}

	int ans = 0;

	for (int i = 1; i <= 9; i++) {
		ans += f(0, i, (1 << i));
		ans %= CON;
	}
	cout << ans;

}