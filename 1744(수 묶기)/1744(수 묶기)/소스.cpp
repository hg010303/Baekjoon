#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> pos;
vector<int> neg;

long long ans;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 1) ans += 1;
		else if (a > 0) pos.push_back(a);
		else neg.push_back(a);
	}

	sort(pos.begin(), pos.end(), greater<int>());
	sort(neg.begin(), neg.end());

	for (int i = 0; i < pos.size(); i+=2) {
		if (i == pos.size() - 1) ans += pos[i];
		else ans += pos[i] * pos[i + 1];
	}

	for (int i = 0; i < neg.size(); i += 2) {
		if (i == neg.size() - 1) ans += neg[i];
		else ans += neg[i] * neg[i + 1];
	}

	cout << ans;
}