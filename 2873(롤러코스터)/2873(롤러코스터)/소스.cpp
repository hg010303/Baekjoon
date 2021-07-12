#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int n, m;
int arr[1010][1010];
int mini = 1010;
pair<int, int> point;
string str = "";

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if ((i+j)%2==0) continue;
			if (mini > arr[i][j]) {
				mini = arr[i][j];
				point = { i,j };
			}
		}

	if (n % 2 == 1) {
		string ltmp, rtmp;

		for (int i = 0; i < m - 1; i++) {
			ltmp += "L";
			rtmp += "R";
		}

		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				str += rtmp;
			}
			else {
				str += ltmp;
			}
			if (i != n - 1) str += 'D';

		}
		cout << str;
	}
	else if (m % 2 == 1) {
		string utmp, dtmp;

		for (int i = 0; i < n - 1; i++) {
			utmp += "U";
			dtmp += "D";
		}

		for (int i = 0; i < m; i++) {
			if (i % 2 == 0) {
				str += dtmp;
			}
			else {
				str += utmp;
			}
			if (i != m - 1) str += 'R';

		}
		cout << str;
	}
	
	else{

		string ans = "", revans = "";
		int sr = 0, sc = 0, er = n - 1, ec = m - 1;

		while(er - sr > 1) {
			if (sr + 1 < point.first) {
				for (int i = 0; i < m - 1; i++) ans += 'R';
				ans += 'D';
				for (int i = 0; i < m - 1; i++) ans += 'L';
				ans += 'D';
				sr += 2;
			}
			if (er - 1 > point.first) {
				for (int i = 0; i < m - 1; i++) revans += 'R';
				revans += 'D';
				for (int i = 0; i < m - 1; i++) revans += 'L';
				revans += 'D';
				er -= 2;
			}
		}

		while (ec - sc > 1) {
			if (sc + 1 < point.second) {
				ans += "DRUR";
				sc += 2;
			}
			if (ec - 1 > point.second) {
				revans += "DRUR";
				ec -= 2;
			}
		}
//		cout << sr<<" " << er << endl;
		if (point.first == sr + 1) {
			ans += "RD";
		}
		else if (point.first == er - 1) {
			ans += "DR";
		}
//		cout << revans << endl;
		reverse(revans.begin(), revans.end());
		ans += revans;
		cout << ans;

	}
}