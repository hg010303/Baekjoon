#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 100100;

long long n, m;
long long arr[MAX];

bool f(long long mid) {
	long long cnt = 0;
	for (int i = 0; i < n; i++) cnt += (mid / arr[i]);

	return cnt >= m;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);

	long long low = 1;
	long long high = arr[n-1]*m;

	long long ans = high;


	while (low <= high) {
		long long mid = low + high >> 1;
		
//		cout << mid << endl;
		if (f(mid)) {
			
			ans = min(ans, mid);
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	cout << ans << endl;
}