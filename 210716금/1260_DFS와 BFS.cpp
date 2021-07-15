/* 1260 DFS와 BFS */

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int n, m, v; // 정점 개수, 간선 개수, 탐색 시작 정점
vector<int> graph[1001]; // 각 정점에서 연결된 정점만 표현해주는 리스트
bool visit[1001] = { false, }; // 방문 여부를 확인하는 배열
stack<int> st;
queue<int> que;

/* 재귀 함수를 이용한 dfs */
void dfs1(int v) {
	if (visit[v] == true) return;
	visit[v] = true;
	cout << v << " ";

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i]; // 인접 노드에 대한 재귀함수 호출
		dfs1(next);
	}
}

/* stack을 이용한 dfs */
void dfs2(int v) {
	st.push(v); // 루트 노드 삽입

	while (!st.empty()) {
		int t = st.top(); // 스택에서 노드 하나 꺼내고
		st.pop(); // 확인한 노드는 pop

		if (visit[t]) continue;
		visit[t] = true; // 방문했다 표시하기
		cout << t << " ";

		// 숫자가 작은 노드 먼저 방문하기 위해 순서 바꿔줌(늦게 들어간게 먼저 나오는 특징)
		for (int i = graph[t].size() - 1; i >= 0; i--) {
			int next = graph[t][i];
			st.push(next); // 인접 노드들 삽입
		}
	}
}

void bfs1(int v) {
	que.push(v); // 루트 노드 삽입

	while (!que.empty()) {
		int f = que.front(); // 큐에서 노드 하나 꺼내고
		que.pop(); // 확인한 노드는 pop

		if (visit[f]) continue;
		visit[f] = true; // 방문했다 표시하기
		cout << f << " ";

		for (int i = 0; i < graph[f].size(); i++) { 
			int next = graph[f][i];
			que.push(next); // 인접 노드들 삽입
		}
	}
}

int main() {

	int a, b;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end()); // 작은 값부터 들어가게 정렬
	}

	fill_n(visit, 1001, false); // 방문 여부 초기화
	dfs1(v);
	// dfs2(v);
	cout << endl;

	fill_n(visit, 1001, false);
	bfs1(v);

	return 0;
}