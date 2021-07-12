#include<iostream>
#include<algorithm>

using namespace std;

int grunt[1010];
bool visit[1010];

int main() {
	int n;
	cin >> n;

	grunt[0] = 0;
	grunt[1] = 0;
	grunt[2] = 1;

	for (int i = 3; i <= n; i++) {
		int cnt = i - 2;
		memset(visit, false, sizeof(visit));
		for (int j = 0; j <= cnt/2; j++) {
//			cout << i<<" "<<j<<" "<<(grunt[j] ^ grunt[(cnt - j)]) << endl;
			visit[(grunt[j] ^ grunt[(cnt - j)])] = true;
		}

		for (int j = 0; j <= i; j++) {
			if (visit[j] == false) {
				grunt[i] = j;
				break;
			}
		}
	}

//	cout << grunt[n] << endl;

	if (grunt[n]) cout << 1;
	else cout << 2;
}