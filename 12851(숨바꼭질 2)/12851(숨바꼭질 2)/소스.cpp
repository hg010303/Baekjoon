#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n, k;
pair<int,int> visit[200100];

int answer = 0;
int cnt = 987654321;


int main() {
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	visit[n].first = 1;
	visit[n].second = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

//		cout << now << " " << visit[now].first << " "<<answer<< '\n';

		if (visit[now].first >= cnt) break;

		if (now + 1 <= 2 * k) {
			if (visit[now + 1].first == visit[now].first + 1) visit[now+1].second+=visit[now].second;
			else if(!visit[now + 1].first){
				visit[now + 1].first = visit[now].first + 1;
				visit[now + 1].second += visit[now].second;
				q.push(now + 1);
			}
		}

		if (2 * now <= 2 * k) {
			if (visit[2 * now].first == visit[now].first + 1) visit[2 * now].second += visit[now].second;
			else if (!visit[2 * now].first) {
				visit[2 * now].first = visit[now].first + 1;
				visit[2 * now].second += visit[now].second;
				q.push(2 * now);
			}
		}

		if (now - 1 >= 0) {
			if (visit[now - 1].first == visit[now].first + 1) visit[now - 1].second += visit[now].second;
			else if (!visit[now - 1].first) {
				visit[now - 1].first = visit[now].first + 1;
				visit[now - 1].second += visit[now].second;
				q.push(now - 1);
			}
		}

		if (now + 1 == k) {
//			cout << "hi"<<'\n';
			if (visit[now + 1].first == cnt) answer++;
			else if(visit[now+1].first<cnt) {
				cnt = visit[now + 1].first;
				answer+=visit[now+1].second;
			}
		}
		if (2*now == k) {
//			cout << "hi" << '\n';
			if (visit[2 * now].first == cnt) answer++;
			else if (visit[2 * now].first < cnt) {
				cnt = visit[2 * now].first;
				answer += visit[2 * now].second;
			}
		}
		if (now - 1 == k) {
//			cout << "hi" << '\n';
			if (visit[now - 1].first == cnt) answer++;
			else if (visit[now - 1].first < cnt) {
				cnt = visit[now - 1].first;
				answer += visit[now - 1].second;
			}
		}
	}

	cout << visit[k].first - 1<<'\n';
	cout << answer;
}