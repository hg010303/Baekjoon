#include<cstdio>

using namespace std;

void hanoi(int n, int a, int b, int c) {
	if (n > 0) {
		hanoi(n - 1, a, c, b);
		printf("%d %d\n", a, b);
		hanoi(n - 1, c, b, a);
	}
}

int main() {
	int n;
	scanf("%d", &n);

	printf("%d\n", (1 << n) - 1);

	hanoi(n, 1, 3, 2);

}