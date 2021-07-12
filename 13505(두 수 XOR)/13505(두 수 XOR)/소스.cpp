#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

const int TRIENODE = 2;

vector<int> v;
vector<int> v1;

struct Trie {
	Trie* next[TRIENODE];

	Trie() {
		fill(next, next + TRIENODE, nullptr);
	}

	~Trie() {
		for (int i = 0; i < TRIENODE; i++)
			if (next[i]) delete next[i];
	}

	void insert(const char* key) {
		if (*key == '\0') {
			return;
		}

		int nextKey = *key - '0';

		if (!next[nextKey]) next[nextKey] = new Trie;


		next[nextKey]->insert(key + 1);

	}

	int find(const char* key,int pos) {
		//cout << pos << endl;
		if (*key == '\0') {
			return pos;
		}

		int nextKey = *key - '0';

		//cout << pos << endl;

		if (next[1 - nextKey] != NULL) {
			return next[1 - nextKey]->find(key + 1, pos*2+1);
		}
		else if(next[nextKey]!=NULL){
			return next[nextKey]->find(key + 1, pos * 2);
		}
		return 0;
	}
};

int ans = 0;

int main() {
	int n;

	cin >> n;

	Trie trie;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
		v1.push_back(a);
	}

	for (int i = 0; i < n; i++) {
		char arr[35];
		for (int j = 31; j >= 0; j--) {

			if (v[i] & 1) arr[j] = '1';
			else arr[j] = '0';
			v[i] >>= 1;
		}
		arr[32] = '\0';

		trie.insert(arr);
	}

	for (int i = 0; i < n; i++) {
		char arr[35];
		for (int j = 31; j >= 0; j--) {

			if (v1[i] & 1) arr[j] = '1';
			else arr[j] = '0';
			v1[i] >>= 1;
		}
		arr[32] = '\0';

		//for (int j = 0; j <= 31; j++) cout << arr[j];
		//cout << endl;



		int tmp = trie.find(arr, 0);
		
		ans = max(ans, tmp);
		
	}

	cout << ans << endl;

}