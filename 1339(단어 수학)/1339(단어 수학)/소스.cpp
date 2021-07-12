#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n;
string str[11];
vector<int> alpha;
int ans = 0;

int main() {
	cin >> n;
	alpha = vector<int>(26);
	for (int i = 0; i < n; i++) {
		cin >> str[i];
		reverse(str[i].begin(), str[i].end());
		int cnt = 1;
		for (int j = 0; j < str[i].size(); j++) {
			alpha[str[i][j] - 'A'] += cnt;
			cnt *= 10;
		}
	}

	sort(alpha.begin(), alpha.end(), greater<int>());

//	for (int i = 0; i < alpha.size(); i++) cout << alpha[i] << " ";
//	cout << endl;
	int tmp = 9;
	for (int i = 0; i < alpha.size(); i++) {
		if (alpha[i] == 0) break;
		ans += alpha[i] * tmp;
		tmp -= 1;
	}

	cout << ans;
}