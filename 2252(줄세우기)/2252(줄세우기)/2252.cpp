#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int arr1[100001];
int arr2[100001];
int front[32001];

queue<int> q;

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin>>arr1[i]>>arr2[i];
		front[arr2[i]] += 1;
	}



	for (int i = 1; i <= n; i++) {
		if (front[i] == 0) q.push(i);
	}

	while (q.size() != 0) {
		int a = q.front();
		q.pop();
		cout << a << " ";
		for (int i = 0; i < m; i++) {
			if (arr1[i]==a) {
				front[arr2[i]] -= 1;
				if (front[arr2[i]] == 0) {
					q.push(arr2[i]);
				}
			}
		}
	}

}