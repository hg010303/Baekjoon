#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
int n;
int visit[2010][1050];
int answer = 0;
int main() {
	cin >> n;

	queue<pair<int, int> > q;

	q.push({ 1,0 });
	visit[1][0] = true;

	while (!q.empty()) {
		int pr = q.front().first;
		int clip = q.front().second;
		q.pop();

		if (pr == n) {
			answer = visit[pr][clip];
			break;
		}

		if (clip > 0 && pr + clip < 2000) {
			if (!visit[pr + clip][clip]) {
				visit[pr + clip][clip] = visit[pr][clip] + 1;
				q.push({ pr + clip,clip });
			}
		}

		if (pr > 0 && pr < 2000) {
			if (!visit[pr][pr]) {
				visit[pr][pr] = visit[pr][clip] + 1;
				q.push({ pr,pr });
			}
			if (!visit[pr - 1][clip]) {
				visit[pr - 1][clip] = visit[pr][clip] + 1;
				q.push({ pr - 1,clip });
			}
		}
		
	}

	cout << answer-1 << '\n';
}