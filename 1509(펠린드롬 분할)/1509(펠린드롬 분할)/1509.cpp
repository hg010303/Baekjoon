#include<cstdio>
#include<cstring>

using namespace std;

int memo[2600];
bool felin[2600][2600];

int main() {
	char s[2600];
	scanf("%s", s);

	memo[0] = 1;

	for (int i = 0; i < strlen(s); i++) {
		felin[i][i] = true;
	}

	for (int i = 0; i < strlen(s) - 1; i++) {
		if (s[i] == s[i + 1]) felin[i][i + 1] = true;
	}

	for (int k = 2; k < strlen(s); k++) {
		for (int i = 1; i <= strlen(s) - k; i++) {
			int j = i + k;
			felin[i][j] = (s[i] == s[j] && felin[i + 1][j - 1]);
		}
	}

	for (int i = 1; i < strlen(s); i++) {
		for (int j = i; j >= 0; j--) {

		}
	}
}