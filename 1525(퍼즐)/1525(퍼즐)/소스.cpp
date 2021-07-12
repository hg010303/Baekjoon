#include<iostream>
#include<algorithm>
#include<set>
#include<queue>
#include<string>

using namespace std;

int arr[3][3];
int n1[4] = { 0,0,-1,1 };
int n2[4] = { 1,-1,0,0 };
string now;
set<string> s;
queue<pair<string,int> > q;

int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
			now += to_string(arr[i][j]);
		}
	}

	s.insert(now);
	q.push({ now,0 });
	int ans = -1;

	while (!q.empty()){
		auto qf = q.front();
		q.pop();

		string str1 = qf.first;
		int cnt = qf.second;

		if (str1 == "123456780") {
			ans = cnt;
			break;
		}

		int map[3][3];
		int idx = 0, pointx, pointy;;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				map[i][j] = str1[idx++]-'0';
				if (map[i][j] == 0) {
					pointx = i;
					pointy = j;
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = pointx + n1[i];
			int ny = pointy + n2[i];

			if (nx < 0 || ny < 0 || nx >= 3 || ny >= 3) continue;
			swap(map[pointx][pointy], map[nx][ny]);
			string str;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) str += to_string(map[i][j]);
			}

			if (s.find(str) == s.end()) {
				s.insert(str);
				q.push({ str,cnt + 1 });
			}

			swap(map[pointx][pointy], map[nx][ny]);
		}
	}
	cout << ans;
}