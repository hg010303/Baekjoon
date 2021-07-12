#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

const int MAX = 1010;

int n, m;
int arr[MAX];
int maxi = 0;


bool cmp(const int& a, const int& b) {

	string astr = to_string(a);
	string bstr = to_string(b);
	//	cout << "str: " << astr << " " << bstr << endl;

	int leng = min(astr.size(), bstr.size());

	for (int i = 0; i < leng; i++) {
		if (astr[i] == bstr[i]) continue;
		else if (astr[i] > bstr[i]) return 1;
		else return 0;
	}
	if (astr.size() == bstr.size()) return 0;

	//			cout << stoi(astr + bstr) << endl;
	return astr + bstr > bstr + astr;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> arr[i];
	vector<int> ans;
	sort(arr, arr + n);
	
	for (int i = n; i < m; i++) ans.push_back(arr[n - 1]);


	for (int i = 0; i < n; i++) ans.push_back(arr[i]);

	sort(ans.begin(), ans.end(), cmp);

	for (auto i : ans) {
		cout << i;
	}
	return 0;
}