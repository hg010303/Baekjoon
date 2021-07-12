#include<iostream>
#include<cstdio>

using namespace std;

int arr[1000001];

int main() {
	int a;

	for (int i = 1; i <= 1000000; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= 1000000; i++) {
		if (arr[i] != i) continue;
		int tmp = i;

		for (int j = 2; tmp * j <= 1000000; j++) {
			arr[tmp * j] = tmp;
		}
	}

	while (true) {
		int n;
		scanf("%d", &n);

		if (n == 0) break;

		int a=0, b=0;

		for (int i = 3; i < n; i++) {
			if (arr[i] != i) continue;
			if (arr[n - i] == n - i) {
				a = i;
				b = n - i;
				break;
			}
		}

		if (a == 0) {
			printf("Goldbach's conjecture is wrong.\n");
			continue;
		}

		printf("%d = %d + %d\n", n, a, b);

	}

}