#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>

using namespace std;

struct node{
	vector<int> v;
	node(int a, int b, int c) {
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		sort(v.begin(), v.end());
	}
};

int a, b, c;

bool answer = false;

set<string> visit;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> a >> b >> c;

	string str = to_string(a) + "/" + to_string(b) + "/" + to_string(c);
	visit.insert(str);

	queue<node> q;
	q.push({ a,b,c });

	while (!q.empty()) {
		int x = q.front().v[0];
		int y = q.front().v[1];
		int z = q.front().v[2];
		q.pop();

		if (x == y && y == z) {
			answer = true;
			break;
		}

		if (x != y) {
			int nx = x + x;
			int ny = y - x;
			string str = to_string(nx) + "/" + to_string(ny)+"/" + to_string(z);

			if (visit.find(str) == visit.end()) {
				q.push({ nx,ny,z });
				visit.insert(str);
			}
		}
		if (x != z) {
			int nx = x + x;
			int nz = z - x;
			string str = to_string(nx) + "/" + to_string(y) + "/" + to_string(nz);

			if (visit.find(str) == visit.end()) {
				q.push({ nx,y,nz });
				visit.insert(str);
			}
		}
		if (y != z) {
			int ny = y + y;
			int nz = z - y;
			string str = to_string(x) + "/" + to_string(ny) + "/" + to_string(nz);

			if (visit.find(str) == visit.end()) {
				q.push({ x,ny,nz });
				visit.insert(str);
			}
		}
	}

	if (answer) cout << 1 << endl;
	else cout << 0 << endl;

}