#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int CON = 1000;
typedef vector<vector<int> > matrix;

int n;
long long m;

matrix multi(matrix a, matrix b) {
	matrix ret(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
				ret[i][j] += a[i][k] * b[k][j];
			ret[i][j] %= 1000;
		}
	}
	return ret;
}

matrix matrixPow(matrix a, long long b) {
	matrix ret(n, vector<int>(n));

	if (b == 1) return a;
	if (b % 2 == 1) {
		return multi(matrixPow(a, b - 1), a);
	}
	else {
		ret = matrixPow(a, b / 2);
		return multi(ret, ret);
	}

}


int main() {
	cin >> n >> m;

	matrix a(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int d;
			cin >> d;
			a[i][j]=d%1000;
		}
	}

	matrix ret(n, vector<int>(n));

	ret = matrixPow(a, m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
}