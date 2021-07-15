/* 1260 DFS�� BFS */

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int n, m, v; // ���� ����, ���� ����, Ž�� ���� ����
vector<int> graph[1001]; // �� �������� ����� ������ ǥ�����ִ� ����Ʈ
bool visit[1001] = { false, }; // �湮 ���θ� Ȯ���ϴ� �迭
stack<int> st;
queue<int> que;

/* ��� �Լ��� �̿��� dfs */
void dfs1(int v) {
	if (visit[v] == true) return;
	visit[v] = true;
	cout << v << " ";

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i]; // ���� ��忡 ���� ����Լ� ȣ��
		dfs1(next);
	}
}

/* stack�� �̿��� dfs */
void dfs2(int v) {
	st.push(v); // ��Ʈ ��� ����

	while (!st.empty()) {
		int t = st.top(); // ���ÿ��� ��� �ϳ� ������
		st.pop(); // Ȯ���� ���� pop

		if (visit[t]) continue;
		visit[t] = true; // �湮�ߴ� ǥ���ϱ�
		cout << t << " ";

		// ���ڰ� ���� ��� ���� �湮�ϱ� ���� ���� �ٲ���(�ʰ� ���� ���� ������ Ư¡)
		for (int i = graph[t].size() - 1; i >= 0; i--) {
			int next = graph[t][i];
			st.push(next); // ���� ���� ����
		}
	}
}

void bfs1(int v) {
	que.push(v); // ��Ʈ ��� ����

	while (!que.empty()) {
		int f = que.front(); // ť���� ��� �ϳ� ������
		que.pop(); // Ȯ���� ���� pop

		if (visit[f]) continue;
		visit[f] = true; // �湮�ߴ� ǥ���ϱ�
		cout << f << " ";

		for (int i = 0; i < graph[f].size(); i++) { 
			int next = graph[f][i];
			que.push(next); // ���� ���� ����
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
		sort(graph[i].begin(), graph[i].end()); // ���� ������ ���� ����
	}

	fill_n(visit, 1001, false); // �湮 ���� �ʱ�ȭ
	dfs1(v);
	// dfs2(v);
	cout << endl;

	fill_n(visit, 1001, false);
	bfs1(v);

	return 0;
}