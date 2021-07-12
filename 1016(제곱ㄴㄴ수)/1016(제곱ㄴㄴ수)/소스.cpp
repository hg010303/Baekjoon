#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int CON = 1000100;
long long a, b;
int arr[1010000];
int result[1000100];
vector<long long> prime;

int main() {
	cin >> a >> b;

	for (int i = 2; i <= CON; i++) arr[i] = 1;
	arr[0] = 0;
	arr[1] = 0;
	for (int i = 2; i <= CON; i++) {
		if (arr[i] == 1) {
			prime.push_back((long long)i*i);
			for (int j = i*2; j <= CON; j += i) {
				arr[j] = 0;
			}
		}
	}

	
	long long ans = b-a+1;
	
	for (auto j : prime) {
		long long mini = a;
		if (mini % j != 0) mini = (a / j + 1) * j;

		for (long long i = mini; i <= b; i += j) {
			if (!result[i - a]) {
				result[i - a] = true;
				ans--;
			}
		}
	}

	cout << ans;

}