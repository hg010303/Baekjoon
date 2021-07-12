#include<iostream>
#include<algorithm>

using namespace std;

int n;
long long ans = 0;
int v[500010], tmp[500010];

void merge(int s, int m, int e) {
	int idx = s;
	int i = s, j = m + 1;

	int cnt = 0;

	while (i <= m | j <= e) {
		if (i > m) {
			tmp[idx++] = v[j++];
			cnt++;
		}
		else if (j > e) {
			tmp[idx++] = v[i++];
			ans += (long long)cnt;
		}
		else if (v[i] <= v[j]) {
			tmp[idx++] = v[i++];
			ans += (long long)cnt;
		}
		else {
			tmp[idx++] = v[j++];
			cnt++;
		}
	}
	for (i = s; i <= e; i++) v[i] = tmp[i];
}

void mergesort(int s, int e) {
	int m;
	if (s < e) {
		m = (s + e) / 2;
		mergesort(s, m);
		mergesort(m + 1, e);
		merge(s, m, e);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	mergesort(0, n- 1);
	cout << ans;
}