#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int n;
pair<int, int> arr[100100];

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

	sort(arr, arr + n, cmp);
	int b = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (b > arr[i].first) continue;
		else{
			ans += 1;
			b = arr[i].second;
		}
		
	}

	cout << ans;


}