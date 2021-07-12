#include<iostream>
#include<cstring>
#include<queue>
#include<string>

using namespace std;

struct Trie {
	Trie* next[26], * fail;
	bool finish;

	Trie() : finish(false), fail(NULL) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i]) delete next[i];
	}

	void insert(const char * key){
		if (*key == '\0') {
			finish = true;
			return;
		}

		int nextkey = *key - 'a';
		if (next[nextkey] == NULL) next[nextkey] = new Trie();

		next[nextkey]->insert(key+1);
	}
};

void make_aho(Trie* root) {
	queue<Trie*> q;

	q.push(root);

	while (!q.empty()) {
		Trie* current = q.front();
		q.pop();

		for (int i = 0; i < 26; i++) {
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

bool find_aho(Trie* root, const char* s) {

	int i;
	Trie* current = root;

	for (i = 0; s[i]; i++) {
		int next = s[i] - 'a';

		while (current != root && !current->next[next]) current = current->fail;

		if (current->next[next]) current = current->next[next];

		if (current->finish) return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	
	Trie* trie = new Trie;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		trie->insert(str.c_str());
	}

	make_aho(trie);

	int m;
	cin >> m;

	while (m--) {
		string str;
		cin >> str;

		if (find_aho(trie, str.c_str())) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}