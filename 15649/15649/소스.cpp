#include<cstdio>
#include<iostream>

int n, m;
int visit[9] = { 0, };
int list[8];

void dfs(int cnt) {
	int i, k;
	if (cnt == m) {
			for (i = 0; i < m; i++) {
				printf("%d ", list[i]);
			}
			printf("\n");
		return;
	}

	for (i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			list[cnt] = i;
			dfs(cnt + 1);
			visit[i] = false;
		}
	}

}


int main() {

	std::cin >> n >> m;

	dfs(0);
}