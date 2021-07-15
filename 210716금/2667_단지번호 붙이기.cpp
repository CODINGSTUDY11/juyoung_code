/* 2667 단지번호 붙이기 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 25

int n; // 지도의 크기
bool graph[MAX][MAX]; // 정사각형 지도
bool visit[MAX][MAX]; // 방문 여부
vector<int> totCnt; // 단지 수
int cnt; // 개별 단지 수
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void dfs(int x1, int y1) {
	cnt++;
	visit[x1][y1] = true;

	// 해당 위치의 상, 우, 하, 좌 확인
	for (int i = 0; i < 4; i++) {
		int x2 = x1 + dx[i];
		int y2 = y1 + dy[i];
		if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= n) // 범위를 벗어나는 경우
			continue;
		if (graph[x2][y2] == true && visit[x2][y2] == false)
			dfs(x2, y2);
	}
}

void bfs(int x1, int y1) {
	cnt++;
	visit[x1][y1] = true;

	queue< pair<int, int> > que;
	que.push(make_pair(x1, y1)); // 행-열을 pair로 만들어 queue에 넣기

	while (!que.empty()) {
		x1 = que.front().first; // 현재 원소 꺼내기
		y1 = que.front().second;
		que.pop();

		// 해당 위치의 상, 우, 하, 좌 확인
		for (int i = 0; i < 4; i++) {
			int x2 = x1 + dx[i];
			int y2 = y1 + dy[i];
			if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= n)  // 범위를 벗어나는 경우
				continue;
			if (graph[x2][y2] == true && visit[x2][y2] == false) {
				visit[x2][y2] = true;
				cnt++;
				que.push(make_pair(x2, y2)); // 큐에 현재 위치 추가
			}
		}
	}

}

int main() {
	string tmp;
	cin >> n;
	
	// 이차원 배열 초기화
	fill(&graph[0][0], &graph[MAX - 1][MAX], false);
	fill(&visit[0][0], &visit[MAX - 1][MAX], false);

	// 지도 모양 입력 받기
	for (int i = 0; i < n; i++) { 
		cin >> tmp;
		for (int j = 0; j < n; j++) {
			if(tmp[j] - '0' == 1)
				graph[i][j] = true;
			else
				graph[i][j] = false;
		}
	}

	// 지도를 살펴보며 아직 방문하지 않은 단지가 있으면 dfs로 탐색 
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

	// 정렬 후 총 단지 수 및 각 단지내 집의 수 출력
	sort(totCnt.begin(), totCnt.end());
	cout << totCnt.size() << endl;
	for (int i = 0; i < totCnt.size(); i++)
		cout << totCnt[i] << endl;

	return 0;
}

