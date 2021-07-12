#include<iostream>
#include<algorithm>

using namespace std;

int n;
int arr[12];
int op[4];
int maxi = -987654321, mini = 987654321;

void f(int plus, int minus, int mul, int div, int cnt, int sum) {
	if (cnt == n) {
		maxi = max(maxi, sum);
		mini = min(mini, sum);
	}

	if (plus > 0) f(plus - 1, minus, mul, div, cnt + 1, sum + arr[cnt]);
	if (minus > 0) f(plus, minus - 1, mul, div, cnt + 1, sum - arr[cnt]);
	if (mul > 0)f(plus, minus, mul - 1, div, cnt + 1, sum * arr[cnt]);
	if (div > 0)f(plus, minus, mul, div - 1, cnt + 1, sum / arr[cnt]);
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < 4; i++) cin >> op[i];

	f(op[0], op[1], op[2], op[3], 1, arr[0]);

	cout << maxi << endl;
	cout << mini << endl;
	
}