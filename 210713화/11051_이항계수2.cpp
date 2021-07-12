/* 11051 이항계수2 */
/* 파스칼의 삼각형 */

#include <iostream>
using namespace std;

int n, k, ans; // 이항계수를 위한 자연수, 정수, 답
int d[1002][1002]; // i!값을 저장 

void dp() {

	for(int i = 1; i <= n+1; i++)
		d[i][1] = d[i][i] = 1;

	for (int i = 3; i <= n+1; i++) {
		for (int j = 2; j <= n; j++) {
			d[i][j] = (d[i - 1][j - 1] + d[i - 1][j]) % 10007;
		}
	}
	cout << d[n + 1][k + 1] << endl;
}

int main() {

	cin >> n >> k;
	dp();

	return 0;
}