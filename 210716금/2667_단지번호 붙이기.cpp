/* 2667 ������ȣ ���̱� */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 25

int n; // ������ ũ��
bool graph[MAX][MAX]; // ���簢�� ����
bool visit[MAX][MAX]; // �湮 ����
vector<int> totCnt; // ���� ��
int cnt; // ���� ���� ��
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void dfs(int x1, int y1) {
	cnt++;
	visit[x1][y1] = true;

	// �ش� ��ġ�� ��, ��, ��, �� Ȯ��
	for (int i = 0; i < 4; i++) {
		int x2 = x1 + dx[i];
		int y2 = y1 + dy[i];
		if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= n) // ������ ����� ���
			continue;
		if (graph[x2][y2] == true && visit[x2][y2] == false)
			dfs(x2, y2);
	}
}

void bfs(int x1, int y1) {
	cnt++;
	visit[x1][y1] = true;

	queue< pair<int, int> > que;
	que.push(make_pair(x1, y1)); // ��-���� pair�� ����� queue�� �ֱ�

	while (!que.empty()) {
		x1 = que.front().first; // ���� ���� ������
		y1 = que.front().second;
		que.pop();

		// �ش� ��ġ�� ��, ��, ��, �� Ȯ��
		for (int i = 0; i < 4; i++) {
			int x2 = x1 + dx[i];
			int y2 = y1 + dy[i];
			if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= n)  // ������ ����� ���
				continue;
			if (graph[x2][y2] == true && visit[x2][y2] == false) {
				visit[x2][y2] = true;
				cnt++;
				que.push(make_pair(x2, y2)); // ť�� ���� ��ġ �߰�
			}
		}
	}

}

int main() {
	string tmp;
	cin >> n;
	
	// ������ �迭 �ʱ�ȭ
	fill(&graph[0][0], &graph[MAX - 1][MAX], false);
	fill(&visit[0][0], &visit[MAX - 1][MAX], false);

	// ���� ��� �Է� �ޱ�
	for (int i = 0; i < n; i++) { 
		cin >> tmp;
		for (int j = 0; j < n; j++) {
			if(tmp[j] - '0' == 1)
				graph[i][j] = true;
			else
				graph[i][j] = false;
		}
	}

	// ������ ���캸�� ���� �湮���� ���� ������ ������ dfs�� Ž�� 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == true && visit[i][j] == false) {
				cnt = 0;
				dfs(i, j);
				//bfs(i, j);
				totCnt.push_back(cnt);
			}
		}
	}

	// ���� �� �� ���� �� �� �� ������ ���� �� ���
	sort(totCnt.begin(), totCnt.end());
	cout << totCnt.size() << endl;
	for (int i = 0; i < totCnt.size(); i++)
		cout << totCnt[i] << endl;

	return 0;
}

