#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int a, b;
	int ans = 0;

	scanf("%d %d", &a, &b);

	int n;
	scanf("%d", &n);

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int e; 
		scanf("%d", &e);
		v.push_back(e);
	}

	for(int i:v){
		ans *= a;
		ans += i;
	}

	vector<int>ans1;

	while (ans != 0) {
		ans1.push_back(ans % b);
		ans /= b;
	}

	reverse(ans1.begin(), ans1.end());

	for (int i : ans1) {
		printf("%d ", i);
	}


}