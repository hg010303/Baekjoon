#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

int n1[8] = { 1,1,2,2,-1,-1,-2,-2 };
int n2[8] = { 2,-2,1,-1,2,-2,1,-1 };

int visit[302][302];

int l;

int main() {
	int N;
	cin >> N;
	queue<pair<int,int> > q;
	queue<pair<int,int> > empty;
	while (N--) {
		cin >> l;
		
		pair<int, int> start;
		pair<int, int> end;
		memset(visit, 0, sizeof(visit));
		int a, b;
		q = queue<pair<int,int> >();

		cin >> a >> b;
		start.first = a;
		start.second = b;

		cin >> a >> b;
		end.first = a;
		end.second = b;
		q.push(start);
		bool flag = false;

		if (start.first==end.first&&start.second==end.second) {
			cout << 0 << endl;
			continue;
		}

		while (!q.empty()) {
			int i, j;
			i = q.front().first;
			j = q.front().second;
			q.pop();
			int k1, k2;

			for (int k = 0; k < 8; k++) {
				k1 = i + n1[k];
				k2 = j + n2[k];

				if (k1 < 0 || k1 >= l) continue;
				if (k2 < 0 || k2 >= l) continue;
				if (visit[k1][k2]) continue;

				q.push({ k1,k2 });
				visit[k1][k2] = visit[i][j] + 1;
				if (k1 == end.first && k2 == end.second) flag = true;
				if (flag) break;
			}
			if (flag) break;
		}
		cout << visit[end.first][end.second] << endl;
	}

}