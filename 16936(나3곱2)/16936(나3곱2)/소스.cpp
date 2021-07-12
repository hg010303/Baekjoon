#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef long long ll;

ll arr[110];
bool visit[110];
int n;
bool ans = false;
vector<ll> v;

bool chk(ll num) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == num) return true;
	}
	return false;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) {
		v.clear();
		v.push_back(arr[i]);
		while (true) {
			if (v.size() == n) {
				ans = true;
				break;
			}

			bool flag = false;
			if (chk(v[v.size() - 1] * 2)) {
				flag = true;
				v.push_back(v[v.size() - 1] * 2);
			}
			if (!(v[v.size() - 1] % 3)) {
				if (chk(v[v.size() - 1] / 3)) {
					flag = true;
					v.push_back(v[v.size() - 1] / 3);
				}
			}
			if (!flag) break;
		}
		if (ans) {
			for (int j = 0; j < v.size(); j++) cout << v[j] << " ";
			return 0;
		}
	}


}

