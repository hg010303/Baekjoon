#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>

using namespace std;

int s=0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	while (n--) {
		string a;
		int b;

		cin >> a;
		
		if (a == "add") {
			cin >> b;
			s |= (1 << b);
		}
		if (a == "check") {
			cin >> b;
			if (s&(1<<b)) printf("1\n");
			else printf("0\n");
		}
		if (a == "remove") {
			cin >> b;
			s &= ~(1 << b);
		}
		if (a == "toggle") {
			cin >> b;
			s ^= (1 << b);
		}
		if (a == "all") {
			s = (1 << 21) - 1;
		}
		if (a == "empty") s = 0;


	}
}