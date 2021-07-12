#include<stdio.h>
#include<iostream>
#include<algorithm>

int arr[8];
int list[8];
int n, m;
int visit[8] = { 0, };
int write[10010] = { 0, };
using namespace std;

void dfs(int now) {
	int i, k;
	if (now==m) {
		for (k = 0; k < m-1; k++) if (list[k] > list[k + 1]) break;
		if (k == m - 1) {
			for (int i = 0; i < m; i++) {
				printf("%d", list[i]);
				if (i != m - 1) printf(" ");
			}
			printf("\n");
		}
		return;
	}
	int before = -1;
	for (int i = 0; i < n; i++) {
		if (!visit[i]&&(i==0||before!=arr[i])){
			list[now] = arr[i];
			before = arr[i];
			dfs(now + 1);
		}
	}
}

int main() {
	std::cin >> n >> m;


	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	dfs(0);
}