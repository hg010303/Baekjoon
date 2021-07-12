#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX = 200100;

int t,m;
int arr[MAX][20];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m;

	for (int i = 1; i <= m; i++) {
		cin >> arr[i][0];
	}

	cin >> t;

	for (int i = 1; i <20; i++) {
		for (int j = 1; j <= m; j++) arr[j][i] = arr[arr[j][i - 1]][i - 1];
	}


	while (t--) {
		int n, x;

		cin >> n >> x;

		for (int i = 0; n; i++){
			if (n & 1) x = arr[x][i];
			n >>= 1;
		}

		cout << x << '\n';
	}
}