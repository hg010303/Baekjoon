#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cstring>

using namespace std;

int n;
int arr[100100];

int make_grundy(int idx) {
	if (idx == 0) return 0;

	if (idx % 2 == 1) return (idx + 1) / 2;
	else return (idx - 2) / 2;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];


	int answer = 0;

	for (int i = 0; i < n; i++) {
		int grundy = make_grundy(arr[i]);
		answer ^= grundy;
//		cout << grundy << endl;
	}

	if (answer) cout << "koosaga";
	else cout << "cubelover";
}