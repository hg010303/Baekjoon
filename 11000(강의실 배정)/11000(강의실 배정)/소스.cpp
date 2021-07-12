#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 200100;
typedef pair<int, int> pii;

int n;
int arr[MAX];
vector<pii> v;

bool cmp(const pii& a, const pii& b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end(), cmp);

/*	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}*/
	

	priority_queue<int,vector<int>,greater<int> > q;
	q.push(v[0].second);
	int ans = 1;
	int size = 1;
	for (int i = 1; i < n; i++) {
		while (!q.empty() && q.top() <= v[i].first) {
			q.pop();
			size--;
		}
		
		q.push(v[i].second);
		size++;
		ans = max(ans, size);
	}

	cout << ans << endl;

}