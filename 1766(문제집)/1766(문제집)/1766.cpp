#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int arr1[100001];
int arr2[100001];
int front[32001];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> arr1[i] >> arr2[i];
		front[arr2[i]] += 1;
	}

	priority_queue<int, vector<int>, greater<int> > pq;

	for (int i = 1; i <= n; i++)
		if (front[i] == 0) pq.push(i);

	while (pq.size() != 0) {
		int a = pq.top();
		pq.pop();
		cout << a << " ";
		for (int i = 0; i < m; i++) {
			if (arr1[i] == a) {
				front[arr2[i]] -= 1;
				if (front[arr2[i]] == 0) {
					pq.push(arr2[i]);
				}
			}
		}	
	}
}