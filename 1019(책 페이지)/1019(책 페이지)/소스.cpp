#include<iostream>
#include<algorithm>

using namespace std;

long long arr[10];

void cal(int num, int tmp) {
	while (num > 0) {
		arr[num % 10] += tmp;
		num /= 10;
	}
}


int main() {
	int n;
	cin >> n;

	int start = 1;
	int tmp = 1;

	while (start <= n) {
		while (n % 10 != 9 && start <= n) {
			cal(n, tmp);
			n--;
		}

		if (n < start) break;

		while (start % 10 != 0 && start <= n) {
			cal(start, tmp);
			start++;
		}

		start /= 10;
		n /= 10;

		for (int i = 0; i < 10; i++) {
			arr[i] += (n - start + 1) * tmp;
		}
		tmp *= 10;
	}

	for (int i = 0; i < 10; i++) cout << arr[i] << " ";
	
}