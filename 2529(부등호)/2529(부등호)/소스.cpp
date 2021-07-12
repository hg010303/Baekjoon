#include<iostream>
#include<algorithm>

using namespace std;

int n;
char arr[11];
int now[11];
int mini[11], maxi[11];
int visit[11];
long long minin = 9876543210, maxin = 0;


void f(int idx) {
	if (idx == n) {
		long long a = 0;
		for (int i = 0; i <= n; i++) {
			a *= 10;
			a += now[i];
		}
		if (minin > a) {
			minin = a;
			for (int i = 0; i <= n; i++) mini[i] = now[i];
		}
		if (maxin < a) {
			maxin = a;
			for (int i = 0; i <= n; i++) maxi[i] = now[i];
		}
	}

	for (int i = 0; i < 10; i++) {
		if (!visit[i]) {
			if (arr[idx] == '<' && now[idx] < i) {
				visit[i] = 1;
				now[idx + 1] = i;
				f(idx + 1);
				visit[i] = 0;
			}
			if (arr[idx] == '>' && now[idx] > i) {
				visit[i] = 1;
				now[idx + 1] = i;
				f(idx + 1);
				visit[i] = 0;
			}
		}
	}
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < 10; i++) {
		now[0] = i;
		visit[i] = 1;
		f(0);
		visit[i] = 0;
	}

	for (int i = 0; i <= n; i++) cout << maxi[i];
	cout << '\n';
	for (int i = 0; i <= n; i++) cout << mini[i];
}