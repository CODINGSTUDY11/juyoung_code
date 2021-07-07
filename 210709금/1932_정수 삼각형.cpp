/* 1932 정수 삼각형 */

#include <iostream>
#include <algorithm>
using namespace std;

int n, ans = 0; // 삼각형의 크기, 현재까지의 합 최대값
int tri[501][501]; // 입력된 정수 삼각형 숫자 저장
int d[501][501]; // 크기가 i인 삼각형까지 봤을 때의 숫자 합의 최대값

int dp() {

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == 0) // 크기가 i인 삼각형의 제일 왼쪽 끝의 경우, 바로 위의 값 받아 해당하는 위치 값과 더함
				d[i][j] = d[i - 1][0] + tri[i][j];
			else if (j == n - 1) // 크기가 i인 삼각형의 제일 오른쪽 끝의 경우, 왼쪽 대각선의 값 받아 해당하는 위치 값과 더함
				d[i][j] = d[i - 1][n - 2] + tri[i][j];
			else // j = 1 ~ n - 2(그 외의 경우는 왼쪽 대각선과 바로 위의 값 중 큰 값을 받아 해당하는 위치 값과 더함
				d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + tri[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		if(ans < d[n][i])
			ans = d[n][i]; // 마지막 줄에서 최대값 도출
	}

	return ans;
}

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++)
			cin >> tri[i][j];
	}	

	ans = dp();
	cout << ans << endl;

	return 0;
}