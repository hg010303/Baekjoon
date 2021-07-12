#include<cstdio>

int main() {
	while (true) {
		int num = 0, small = 0, blank = 0, big = 0;
		
		while (true) {
			char c = getchar();
			if (c == EOF) return 0;

			if (c == '\n') break;
			if (c >= 'a' && c <= 'z') small++;
			if (c >= 'A' && c <= 'Z') big++;
			if (c >= '0' && c <= '9') num++;
			if (c == ' ') blank++;

		}

		printf("%d %d %d %d\n", small, big, num, blank);


		


	}
}