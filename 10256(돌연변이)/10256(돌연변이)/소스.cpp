#include<iostream>
#include<cstring>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;

int findnextkey(char a) {
	if (a == 'A') return 0;
	else if (a == 'G') return 1;
	else if (a == 'C')return 2;
	else return 3;
}

struct Trie {
	Trie* next[4], * fail;
	bool finish;

	Trie() : finish(false), fail(NULL) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i <4; i++)
			if (next[i]) delete next[i];
	}

	void insert(const char* key) {
		if (*key == '\0') {
			finish = true;
			return;
		}

		int nextkey = findnextkey(*key);
		if (next[nextkey] == NULL) next[nextkey] = new Trie();

		next[nextkey]->insert(key + 1);
	}
};

void make_aho(Trie* root) {
	queue<Trie*> q;

	q.push(root);

	while (!q.empty()) {
		Trie* current = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			Trie* next = current->next[i];
			if (!next) continue;

			if (current == root) next->fail = root;
			else {
				Trie* dest = current->fail;

				while (dest != root && !dest->next[i]) dest = dest->fail;

				if (dest->next[i]) dest = dest->next[i];

				next->fail = dest;
			}

			if (next->fail->finish) next->finish = next->fail->finish;

			q.push(next);
		}

	}
}

int find_aho(Trie* root, const char* s) {

	int i;
	Trie* current = root;
	int ans = 0;

	for (i = 0; s[i]; i++) {
		int next = findnextkey(s[i]);

		while (current != root && !current->next[next]) current = current->fail;

		if (current->next[next]) current = current->next[next];

		if (current->finish) ans++;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	while (N--) {
		int n, m;
		cin >> n >> m;
		string str1, str2;
		cin >> str1;
		cin >> str2;

		Trie* trie = new Trie;

		for (int i = 0; i < m; i++) {
			for (int j = 1; j <= m - i; j++) {
				string str = str2.substr(i, j);
				reverse(str.begin(), str.end());
				string tmp = str2.substr(0, i) + str + str2.substr(i + j);
//				cout << 1 << endl;
				trie->insert(tmp.c_str());
				
			}
		}

//		cout << 1 << endl;
		make_aho(trie);
		cout << find_aho(trie, str1.c_str())<<'\n';

		delete trie;
	}
}