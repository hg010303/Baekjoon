#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, l, r, x;
vector<long long> v;
long long answer = 0;
vector<int> ans;

void dfs(int idx, long long now) {
	if (l <= now && now <= r&&v.size()>=2) {
		if (ans[ans.size() - 1] - ans[0] >= x) {
			answer++;

		}
			
	}
	if (now > r) return;
	if (idx >= n) return;

	for (int i = idx+1; i < n; i++) {
		if(idx==-1){
			ans.push_back(v[i]);
			dfs(i, now + v[i]);
			ans.pop_back();
		}
		else {
			ans.push_back(v[i]);
			dfs(i, now + v[i]);
			ans.pop_back();
		}
	}
}

int main() {
	cin >> n >> l >> r >> x;
	
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	dfs(-1, 0);

	cout << answer << endl;
}