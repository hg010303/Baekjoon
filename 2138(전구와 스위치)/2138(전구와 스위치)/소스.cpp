#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n;
int arr[100100];
int arr1[100100];
int result[100100];
int cnt = 0;

bool compare(int a[], int n)
{
	for (int i = 1; i <= n; ++i) {
		if (a[i] != result[i])
			return false;
	}
	return true;
}

void change(int a[], int sw, int n)
{
	for (int j = -1; j < 2; ++j) {
		if (sw + j > 0 && sw + j <= n)
			a[sw + j] = 1 - a[sw + j];
	}
	cnt++;
}

int main() {
	cin >> n;

	string str;
	cin >> str;

	for (int i = 1; i <= n; i++) {
		arr[i] = str[i-1] - '0';
		arr1[i] = str[i-1] - '0';
	}
	cin >> str;

	for (int i = 1; i <= n; i++) {
		result[i] = str[i-1] - '0';
	}
	change(arr, 1, n);

	int cn = 1;
	int cn1 = 0;

	for (int i = 2; i <= n; i++) {
		if (arr[i - 1] != result[i - 1]) {
			change(arr, i, n);
			cn++;
		}
		if (arr1[i - 1] != result[i - 1]) {
			change(arr1, i, n);
			cn1++;
		}
	}
	int ans = -1;

	if (compare(arr, n)) ans = cn;
	else if (compare(arr1, n)) ans = cn1;
	
	if (compare(arr, n) && compare(arr1, n)) ans = cn < cn1 ? cn : cn1;

	cout << ans;

}