#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int arr[1010][1010];
int grunt[1010];

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}
	
	for (int i = 0; i < n; i++) {
		if (m == 1) grunt[i] = arr[i][0];
		else {
			if (arr[i][0] > arr[i][1]) grunt[i] = arr[i][0];
			else if (arr[i][0] < arr[i][1]) grunt[i] = arr[i][0] - 1;
			else {
				for (int j = 0; j < m-1; j++) {
					int cnt = 1;
					
					if (arr[i][j] == arr[i][j + 1]) cnt++;
					else {
						if (cnt % 2 == 0) {
							if (arr[i][j] > arr[i][j + 1]) grunt[i] = arr[i][j];
							else grunt[i] = arr[i][j] - 1;
						}
						else {
							if (arr[i][j] > arr[i][j + 1]) grunt[i] = arr[i][j]-1;
							else grunt[i] = arr[i][j];

						}
						break;
					}
					if (j == m - 2) {
						if (cnt % 2 == 0) grunt[i] = arr[i][0] - 1;
						else grunt[i] = arr[i][0];
					}
				}
			}
		}
	}
	int ans = 0;

	for (int i = 0; i < n; i++) {
		ans ^= grunt[i];
	}

	if (ans) cout << "koosaga";
	else cout << "cubelover";

}