#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int arr[100100];
bool visit[100100];
bool done[100100];
int n, ans;

void dfs(int i) {
	visit[i] = true;

	int next = arr[i];

	if (!visit[next]) dfs(next);
	else if (!done[next]) {
		for (int j = next; j != i; j = arr[j])
			ans++;
		ans++;
	}

	done[i] = true;


	
}

int main() {
	int N;
	scanf("%d",&N);

	while (N--) {
		memset(visit, false, sizeof(visit));
		memset(done, false, sizeof(done));
		ans = 0;
		scanf("%d", &n);
		
		for (int i = 1; i <= n; i++) {
			int a;
			scanf("%d",&a);
			arr[i] = a;
		}

		for (int i = 1; i <= n; i++) {
			if (!visit[i])
				dfs(i);
		}
		printf("%d\n", n - ans);
	}
}