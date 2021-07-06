/* 10844 쉬운 계단 수 */

#include <iostream>
using namespace std;

int n, ans = 0; // 길이, 현재까지의 총 계단 수
int d[101][10]; // i자리 수의 마지막 숫자가 j일 때의 계단 수

int dp() {

	// 초기화
	for (int i = 1; i < 10; i++)
		d[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) // i 자리 수의 마지막 자리가 0인 경우 i - 1 자리 수의 마지막 자리는 1만 가능(-1 불가)
				d[i][j] = d[i - 1][1] % 1000000000;
			else if (j == 9) // i 자리 수의 마지막 자리가 9인 경우 i - 1 자리 수의 마지막 자리는 8만 가능(0 불가)
				d[i][j] = d[i - 1][8] % 1000000000;
			else // j = 1 ~ 8(그 외의 경우는 i - 1 자리 수의 마지막 자리에 +-1한 값이 올 수 있음
				d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % 1000000000;
		}
	}

	for (int i = 0; i < 10; i++) {
		ans = (ans + d[n][i]) % 1000000000; // n자리 수의 마지막 숫자가 i일 때의 모든 경우 합산
	}

	return ans;
}

int main() {

	cin >> n;
	ans = dp();
	cout << ans << endl;

	return 0;
}