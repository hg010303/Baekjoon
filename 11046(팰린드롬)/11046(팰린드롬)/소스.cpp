#include<iostream>
#include<algorithm>

using namespace std;
const int MAX = 1000005;
const long long D = (1ll << 30);
const long long D2 = (1e9 + 7);
int arr[MAX];
int arr1[MAX];
pair<long long, long long> has1[MAX];
pair<long long, long long> has2[MAX];
pair<long long, long long> b[MAX];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n;
	b[0] = { 1,1 };

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		has1[i].first = (has1[i - 1].first * 100001 + arr[i]) % D;
		has1[i].second = (has1[i - 1].second * 100001 + arr[i]) % D2;
		b[i].first = b[i - 1].first * 100001 % D;
		b[i].second = b[i - 1].second * 100001 % D2;
	}
	for (int i = n; i >= 1; i--) {
		has2[i].first = (has2[i + 1].first * 100001 + arr[i]) % D;
		has2[i].second = (has2[i + 1].second * 100001 + arr[i]) % D2;
	}
	
	cin >> m;
	while (m--) {
		int a, c;
		cin >> a >> c;

		if(((has1[c].first - has1[a - 1].first * b[c - a + 1].first % D + D) % D == (has2[a].first - has2[c+1].first * b[c - a + 1].first % D+D)%D)&& ((has1[c].second - has1[a - 1].second * b[c - a + 1].second % D2 + D2) % D2 == (has2[a].second - has2[c+1].second * b[c - a + 1].second % D2 + D2) % D2))
			cout<<1;
		else cout<<0;
		
		cout<<'\n';
	}
}