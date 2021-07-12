#include<iostream>
#include<set>

using namespace std;

int n;
bool visit[1001];
int answer = 0;

int arr[4] = { 1,5,10,50 };

void bfs(int idx,int cnt, int ans) {
	if (idx == n) {
		if (visit[ans] == false) {
			visit[ans] = true;
			answer++;
		}
		return;
	}

	for (int i = cnt; i < 4; i++) {
		bfs(idx + 1, i,ans + arr[i]);
	}
}


int main() {
	cin >> n;

	bfs(0, 0,0);

	cout << answer;


}