#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n;

priority_queue<int, vector<int>, less<int> > maxheap;
priority_queue<int, vector<int>, greater<int> > minheap;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	while (n--) {
		int a;
		cin >> a;
		
		if (maxheap.size() == minheap.size()) maxheap.push(a);
		else minheap.push(a);

		if (!maxheap.empty() && !minheap.empty()) {
			if (maxheap.top() > minheap.top()) {
				int maxtop = maxheap.top();
				int mintop = minheap.top();

				maxheap.pop();
				minheap.pop();

				minheap.push(maxtop);
				maxheap.push(mintop);
			}
		}
		cout << maxheap.top() << '\n';

	}
}