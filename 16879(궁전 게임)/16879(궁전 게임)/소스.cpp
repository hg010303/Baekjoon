#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int grunt[32][32];


void make_grunt() {
	grunt[0][0] = 0;

	bool visit[500];

	

	for (int i = 0; i <=30; i++) {
		for (int j = 0; j <= 30; j++) {
			memset(visit, false, sizeof(visit));

			for (int k = 0; k < i; k++) {
				visit[grunt[k][j]] = true;
			}

			for (int k = 0; k < j; k++) {
				visit[grunt[i][k]] = true;
			}

			if (i > 0 && j > 0) visit[grunt[i - 1][j - 1]] = true;

			for (int k = 0; k < 500; k++) {
				if (visit[k] == false) {
					grunt[i][j] = k;
					break;
				}
			}
		}
	}

	for (int i = 0; i <= 30; i++) {
		for (int j = 0; j <= 30; j++) {
			printf("%2d ", grunt[i][j]);
		}
		cout << endl;
	}
}

int main() {
	make_grunt();
}
