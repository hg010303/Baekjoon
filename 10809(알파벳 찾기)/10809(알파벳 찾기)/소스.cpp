#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int main() {
	int arr[27];
	string str;

	memset(arr, -1, sizeof(arr));

	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (arr[str[i] - 'a'] != -1) continue;
		arr[str[i] - 'a'] = i;
	}

	for (int i = 0; i < 26; i++) cout << arr[i] << " ";

}