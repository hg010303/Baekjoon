#include<iostream>
#include<algorithm>

using namespace std;

int arr[16];
int n;
bool pos(int, int);
long long f(int);

int main() {
	cin >> n;
	cout << f(0);
}

long long f(int depth) {
	if (depth == n) return 1;
	long long result = 0;
	for (int i = 0; i < n; i++) {
		arr[depth] = i;
		if (pos(depth, i))
			result += f(depth + 1);
	}
	return result;
}

bool pos(int depth, int t) {
	for (int i = 0; i < depth; i++) {
		if (t == arr[i]) return false;
		if (t == arr[i] - depth + i) return false;
		if (t == arr[i] + depth - i) return false;
	}
	return true;
}
