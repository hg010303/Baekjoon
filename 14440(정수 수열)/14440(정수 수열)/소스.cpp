#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef vector<vector<int> > matrix;
const int MOD = 100;

int x, y;
int n;


matrix mul(matrix a, matrix b) {
	int rows = a.size();

	matrix res(rows, vector<int>(rows));

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			for (int k = 0; k < rows; k++) {
				res[i][j] += a[i][k] * b[k][j];
			}
			res[i][j] %= MOD;
		}
	}
	return res;
}

matrix pow(matrix a, int n) {
	if (n % 2 == 0) {
		matrix now = pow(mul(a,a),n/2);
		return mul(now, now);

	else return pow(a)
}

int main() {
	int a0, a1;
	cin >> x >> y >> a0 >> a1 >> n;

	cout << a0 << a1 << endl;
}