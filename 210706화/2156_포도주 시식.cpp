/* 2156 포도주 시식 */

#include <iostream>
#include <algorithm>
using namespace std;

int n, ans; // 포도주 잔의 개수, 현재까지의 최대 포도주 양
int wine[10001]; // 포도주 양
int d[10001][3]; // i번째 잔을 마실 때 연속된 개수에 따른 최대 포도주 양

int dp() {

	// 초기화
	d[1][1] = d[1][2] = d[2][0] = wine[1];
	d[2][1] = wine[2];
	d[2][2] = wine[1] + wine[2];
	ans = max({ d[2][0], d[2][1], d[2][2] });
	
	for (int i = 3; i <= n; i++) { 
		// 0: 현재 잔 안 먹는 경우, 1: 연속 X(한 잔째), 2: 연속 O(연속 두 잔째)
		d[i][0] = max({ d[i - 1][0], d[i - 1][1], d[i - 1][2] }); // i-1번째까지의 최대 포도주 양
		d[i][1] = wine[i] + max({ d[i - 2][0], d[i - 2][1], d[i - 2][2] }); // 현재 포도주 양 + i-2번째까지의 최대 포도주 양
		d[i][2] = wine[i - 1] + wine[i] + max({ d[i - 3][0], d[i - 3][1], d[i - 3][2] }); // i-1번째 포도주 양 + 현재 포도주 양 + i-3번째까지의 최대 포도주 양
						
		ans = max(ans, max({ d[i][0], d[i][1], d[i][2] }));
	}

	return ans;
}

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> wine[i];

	ans = dp();
	cout << ans << endl;

	return 0;
}