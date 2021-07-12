#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
int arr[21][21];
int ans = 987654321;
vector<int> a, b;

void f(int idx) {
	if (idx == n) {
		if (a.size() == n / 2 && b.size() == n / 2) {
			int suma = 0, sumb = 0;
			for (int i = 0; i < n / 2; i++) {
				for (int j = i+1; j < n / 2; j++) {
					if (i == j) continue;
					suma += arr[a[i]][a[j]] + arr[a[j]][a[i]];
					sumb += arr[b[i]][b[j]] + arr[b[j]][b[i]];

				}
			}
			ans = min(ans, abs(suma - sumb));
		}
		return;
	}

	a.push_back(idx);
	f(idx + 1);
	a.pop_back();

	b.push_back(idx);
	f(idx + 1);
	b.pop_back();
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	f(0);

	cout << ans;
}