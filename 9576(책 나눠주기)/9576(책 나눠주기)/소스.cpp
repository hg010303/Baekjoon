#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

typedef pair<int, int> pii;
const int MAX = 1010;

pii arr[MAX];

bool cmp(const pii& a, const pii& b) {
	return a.second < b.second;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			arr[i] = { a,b };
		}

		sort(arr, arr + m, cmp);

/*		for (int i = 0; i < m; i++) {
			cout << arr[i].first << " " << arr[i].second << endl;
		}
*/

		bool visit[MAX];
		memset(visit, false, sizeof(visit));

		int ans = 0;

		for (int i = 0; i < m; i++) {
			for (int j = arr[i].first; j <= arr[i].second; j++) {
				if (!visit[j]) {
					visit[j] = true;
					ans++;
					break;
				}
			}


		}
		cout << ans << '\n';
	}


	
}