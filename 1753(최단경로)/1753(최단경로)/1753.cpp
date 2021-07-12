#include<cstdio>
#include<queue>
#include<vector>

#define INF 100000000

using namespace std;

struct Edge {
	int to;
	int value;
	Edge(int to, int value) : to(to), value(value){}
};

struct cmp {
	bool operator()(Edge a, Edge b) {
		return a.value > b.value;
	}
};

vector<Edge> line[20001];
bool visit[20001];
int dist[20001];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int start;
	scanf("%d", &start);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		line[a].push_back(Edge(b, c));
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dist[start] = 0;

	priority_queue<Edge, vector<Edge>, cmp> pq;
	pq.push(Edge(start,0));

	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		int x = p.to;
		if (visit[x]) continue;

		visit[x] = true;

		for (int i = 0; i < line[x].size(); i++) {
			int y = line[x][i].to;
			if (dist[y] > dist[x] + line[x][i].value) {
				dist[y] = dist[x] + line[x][i].value;
				pq.push(Edge(y, dist[y]));
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i] >= INF) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
}