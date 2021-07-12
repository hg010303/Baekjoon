#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int n;
int k;
set<int> s;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		s.insert(a);
	}

	cin >> k;
	while (k--) {
		int a;
		cin >> a;
		if (s.find(a) != s.end()) cout << 1 << " ";
		else cout << "0" << " ";
	}
}