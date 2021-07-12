#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int n, m;
int arr[11][11];
int memo[1200][1200];

const int MAX = 10;


int main() {
	bool visit[100];

	for (int i = 0; i < (1 << MAX); i++) {
		for (int j = 0; j < (1 << MAX); j++) {
			if (i == 0 && j == 0) {
				memo[i][j] = 0;
				continue;
			}

			memset(visit, false, sizeof(visit));

			int now1 = 1;

			while (now1 < (1 << MAX)) {
				if (now1 & i) visit[memo[i - now1][j]] = true;
				if (now1 & j) visit[memo[i][j - now1]] = true;
				now1 <<= 1;
			}
			now1 = 1;
			while (now1 < (1 << (MAX-1))) {
				if ((now1 & i) && (now1 & j) && ((now1 * 2) & i) && ((now1 * 2) & j)){
					visit[memo[i - now1 * 3][j - now1 * 3]] = true;
//					if (i == 15 && j == 15) cout << now1 << endl;
				}
				now1 <<= 1;
			}
			
			for (int k = 0; k < 100; k++) {
				if (visit[k] == false) {
					memo[i][j] = k;
					break;
				}
			}

//			cout << i << " " << j << " " << memo[i][j] << endl;

		}
	}










	int T = 3;

	while (T--) {
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char a;
				cin >> a;

				if (a == '.') arr[i][j] = 1;
				else arr[i][j] = 0;
				
			}
		}

		int ans = 0;

		for (int i = 0; i < n; i +=2) {
			int t1 = 0;
			int t2 = 0;
			for (int j = 0; j < m; j++) {
				t1 *= 2;
				t2 *= 2;
				t1 += arr[i][j];
				t2 += arr[i+1][j];
			}
//			cout << t1 << t2 << endl;
			ans ^= memo[t1][t2];

		}

		if (m % 2 == 1) {
			int t1 = 0;
			for (int i = 0; i < n; i++) {
				t1 *= 2;
				t1 += arr[n-1][i];
			}
			ans ^= memo[t1][0];
		}

		if (ans) cout << "Y" << endl;
		else cout << "M" << endl;
	}
}