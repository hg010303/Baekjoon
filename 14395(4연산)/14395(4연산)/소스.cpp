#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<queue>

using namespace std;

long long start, fin;
bool answer = false;
set<long long> S;
string ans;
string str[4] = { "*","+","-","/" };

long long cal(long long a, int idx) {
	if (idx == 1) return a + a;
	else if (idx == 2) return a - a;
	else if (idx == 0) return a * a;
	else if (idx == 3) return a / a;
}

int main() {
	cin >> start >> fin;

	if (start == fin) {
		cout << 0 << endl;
		return 0;
	}

	queue<pair<long long, string> > q;
	q.push({ start,"" });
	S.insert(start);

	while (q.empty() == 0) {
		long long x = q.front().first;
		string s = q.front().second;
		q.pop();

		if (x == fin) {
			answer = true;
			ans = s;
		}

		for (int i = 0; i < 4; i++) {
			long long nx = cal(x, i);
			if (nx < 1) continue;
			if (S.find(nx) != S.end()) continue;
			S.insert(nx);
			q.push({ nx,s + str[i] });
		}
	}


	if (answer == true) cout << ans << endl;
	else cout << -1 << endl;
}