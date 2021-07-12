#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>

using namespace std;

const int TRIENODE = 26;

struct Trie {
	Trie* next[TRIENODE];
	bool finish;
	bool nextchild;

	Trie() {
		fill(next, next + TRIENODE, nullptr);
		finish = nextchild = false;
	}

	~Trie() {
		for (int i = 0; i < TRIENODE; i++)
			if (next[i]) delete next[i];
	}

	void insert(const char* key) {
		if (*key == '\0') {
			finish = true;
			return;
		}

		int nextKey = *key - 'a';

		if (!next[nextKey]) next[nextKey] = new Trie;

		nextchild = true;

		next[nextKey]->insert(key + 1);

	}

	bool find(const char* key) {
		if (*key == '\0') {
			if (finish == true) return true;
			else return false;
		}
		
		int nextKey = *key - 'a';

		if (next[nextKey] == NULL) return false;
		return next[nextKey]->find(key + 1);
		
	}
};

int main() {
	int n, m;

	cin >> n >> m;
	Trie trie;

	for (int i = 0; i < n; i++) {
		char a[510];
		scanf("%s", a);
		trie.insert(a);
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		char a[510];
		scanf("%s", a);

		if (trie.find(a)) ans++;
	}

	cout<<ans;
}