/* 1149 RGB거리 */

#include <iostream>
#include <algorithm>
using namespace std;

int n, ans; // 집의 수, 최소 비용
int d[1001][3]; // i번째 집을 R/G/B로 칠했을 때의 최소 비용

int dp() {

	int money[3];

	for (int i = 1; i <= n; i++) { 
		cin >> money[0] >> money[1] >> money[2];
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + money[0]; // i - 1번째 집을 G 혹은 B로 칠한 값 중 최소 비용 + i번째 집을 R로 칠하는 비용
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + money[1]; // i - 1번째 집을 R 혹은 B로 칠한 값 중 최소 비용 + i번째 집을 G로 칠하는 비용
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + money[2]; // i - 1번째 집을 R 혹은 G로 칠한 값 중 최소 비용 + i번째 집을 B로 칠하는 비용
	}

	return min(min(d[n][0], d[n][1]), d[n][2]);
}

int main() {

	cin >> n;
	ans = dp();
	cout << ans << endl;

	return 0;
}