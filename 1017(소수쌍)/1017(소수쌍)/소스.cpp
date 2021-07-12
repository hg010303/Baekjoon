#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>

using namespace std;

const int MAX = 60;
const int MAXNUM = 2100;

bool iseven = false;
vector<int> a;
vector<int> b;
int n;
vector<int> v[MAX];
int isprime[MAXNUM];
int bmat[MAX];
bool visit[MAX];
int flag = 0;

void prime() {
	for (int i = 2; i < MAXNUM; i++) isprime[i] = i;

	for (int i = 2; i < sqrt(MAXNUM); i++) {
		if (isprime[i] == 0) continue;

		for (int j = i + i; j < MAXNUM; j += i) isprime[j] = 0;
	}
}

bool dfs(int now) {
	if (visit[now]) return false;
	visit[now] = true;

	for (auto next : v[now]) {
		if (flag == next||bmat[next]==0) continue;
		if (bmat[next] == -1 || dfs(bmat[next])) {
			bmat[next] = now;
			return true;
		}
	}
	return false;
}


int main() {
	prime();
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		if (i == 0) {
			if (k % 2 == 0) iseven = true;
			else iseven = false;
		}
		if (k % 2 == 1) a.push_back(k);
		else b.push_back(k);
	}

	if (a.size() != b.size()) {
		cout << -1 << endl;
		return 0;
	}

	if (iseven) swap(a, b);

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (isprime[a[i] + b[j]]) {
				v[i].push_back(j);
			}
		}
	}

	vector<int> ans;

	for (auto first : v[0]) {
		memset(bmat, -1, sizeof(bmat));
		bmat[first] = 0;

		int	ret = 1;
		flag = first;

		for (int i = 1; i < a.size(); i++) {
			memset(visit, false, sizeof(visit));
			visit[0] = true;
			if (dfs(i)) ret++;
		}

		if (ret == a.size()) {
			ans.push_back(b[first]);
		}
	}

	if (ans.size() == 0) cout << -1;
	else {
		sort(ans.begin(), ans.end());
		for (auto i : ans) cout << i << " ";
	}
}