#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int N;
int start, fin;
bool visit[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	while (N--) {
		string ans;
		memset(visit, false, sizeof(visit));
		cin >> start >> fin;
		visit[start] = true;

		queue<pair<int, string> > q = queue<pair<int,string> >();
		q.push({ start,"" });
		
		while (!q.empty()) {
			int num = q.front().first;
			string str = q.front().second;
			q.pop();

//			cout << num << " " << str << endl;

			if (num == fin) {
				ans = str;
				break;
			}

			int next = (2 * num) % 10000;
			if (!visit[next]) {
				visit[next] = true;
				q.push({ next,str + "D" });
			}
			
			next = num - 1;
			if (next < 0) next = 9999;
			if (!visit[next]) {
				visit[next] = true;
				q.push({ next,str + "S" });
			}

			next = (num % 1000) * 10 + num / 1000;
			if (!visit[next]) {
				visit[next] = true;
				q.push({ next,str + "L" });
			}

			next = (num % 10) * 1000 + num / 10;
			if (!visit[next]) {
				visit[next] = true;
				q.push({ next,str + "R" });
			}

		}

		cout << ans << endl;

	}
}