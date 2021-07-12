#include<iostream>
#include<algorithm>

using namespace std;

int arr[10];
int ans[10];

int main() {
	int su = 0;

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		su += arr[i];
	}

	su -= 100;
	int a, b;

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (su == arr[i] + arr[j]) {
				a = i;
				b = j;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < 9; i++) {
		if (i == a || i == b) continue;
		ans[cnt++] = arr[i];
	}

	sort(ans, ans + 7);

	for (int i = 0; i < 7; i++)
		cout << ans[i] << endl;


}