#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cstring>

using namespace std;

int n;
int arr[100100];
int ans[100100];
int grundy[3000100];

vector<int> prime;

void make_prime() {
	prime.push_back(1);
	prime.push_back(2);

	int a = 1;
	int b = 2;
	int c=a+b;

	while (c <= 3000000) {
		prime.push_back(c);
		a = b;
		b = c;
		c = a + b;
	}
}

void make_grundy() {
	grundy[0] = 0;

	bool visit[30];

	for (int i = 1; i <= 3000000; i++) {
//		cout << i << endl;
		memset(visit, false, sizeof(visit));
		for (int j = 0; j < prime.size(); j++) {
			if (i < prime[j]) break;

			visit[grundy[i-prime[j]]] = true;
		}

		for (int j = 0; j < 30; j++) {
			if (visit[j] == false) {
				grundy[i] = j;
				break;
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	make_prime();

	make_grundy();
	
	int answer = 0;

	for (int i = 0; i < n; i++) answer ^= grundy[arr[i]];

	if (answer) cout << "koosaga";
	else cout << "cubelover";
}