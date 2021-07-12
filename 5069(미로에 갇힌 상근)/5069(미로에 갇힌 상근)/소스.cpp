#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int n;
int memo[15][15][15];

int f(int dis, int idx, int flag) {
	if (dis > idx) return 0;
	if (idx == 0) return 1;
//	if (idx == 2) cout << dis << " " << flag << endl;
	int& ret = memo[dis][idx][flag];
	if (ret != -1) return ret;

	

	if (dis == 0) return ret = 6 * f(dis + 1, idx - 1,0);
	ret = 0;
	if (dis == 1) flag = 0;
	if (flag == 0||dis==1) {
		ret += f(dis - 1, idx - 1, 0);
		ret += f(dis, idx - 1, dis - 1);
		ret += f(dis, idx - 1, 1);
		ret += f(dis + 1, idx - 1, 0);
		ret += f(dis + 1, idx - 1, dis);
		ret += f(dis + 1, idx - 1, 1);
		return ret;
	}

	else if (flag == dis - 1) {
		ret += f(dis - 1, idx - 1, flag - 1);
		ret += f(dis - 1, idx - 1, 0);
		ret += f(dis, idx - 1, flag - 1);
		ret += f(dis, idx - 1, 0);
		ret += f(dis + 1, idx - 1, flag);
		ret += f(dis + 1, idx - 1, flag + 1);
		return ret;
	}
	
	else {
		ret += f(dis - 1, idx - 1, flag - 1);
		ret += f(dis - 1, idx - 1, flag);
		ret += f(dis, idx - 1, flag - 1);
		ret += f(dis, idx - 1, flag + 1);
		ret += f(dis + 1, idx - 1, flag);
		ret += f(dis + 1, idx - 1, flag + 1);
	}


	return ret;
	
}

int main() {
	int T;

	cin >> T;

	memset(memo, -1, sizeof(memo));

	while (T--) {
		cin >> n;

		cout << f(0,n,0) << endl;
	//	cout << memo[0][2][0] << endl;
	}
}