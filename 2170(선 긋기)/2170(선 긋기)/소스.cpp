#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;



int n;
vector<pair<long long, long long> > v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());

	long long fin = -1000000001;
	long long ans = 0;


	for (int i = 0; i < v.size(); i++) {
		auto now = v[i];

		if (fin <= v[i].first) {
			ans += (v[i].second - v[i].first);
			fin = v[i].second;
		}
		else if (v[i].second <= fin) continue;
		else {
			ans += (v[i].second - fin);
			fin = v[i].second;
		}

	}

	cout << ans;
}