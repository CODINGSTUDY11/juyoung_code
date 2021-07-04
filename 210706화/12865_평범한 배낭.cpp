/* 12865 평범한 배낭 */
/* Knapsack 알고리즘 */

#include <iostream>
#include <algorithm>
using namespace std;

int n, k, ans = 0; // 물건의 개수, 최대 무게, 현재까지의 최대 가치값
int w[101]; // 물건의 무게
int v[101]; // 물건의 가치
int d[101][100001]; // i번째 물건까지 선택했고 선택한 물건의 총 무게가 j일때의 최대 가치값

int dp() {

	for (int i = 1; i <= n; i++) { // 물건은 1개부터 고려
		for (int j = 0; j <= k; j++) { // 무게는 0kg부터 고려
			d[i][j] = d[i - 1][j]; // 배낭에 물건을 넣을 수 없다면 i-1번째 물건까지 고려한 무게와 동일
			if (j - w[i] >= 0) { // 만약 배낭에 물건을 넣을 수 있다면(무게 초과 X)
				d[i][j] = max(d[i - 1][j], d[i - 1][j - w[i]] + v[i]); // 위의 값과 현재 물건의 무게인 w[i]가 들어오기 전의 최대 가치값(d[i - 1][j - w[i])에 현재 물건의 가치인 v[i]를 더한 값을 비교
				ans = max(ans, d[i][j]); // 현재까지의 최대 가치값 저장
			}
		}
	}
	return ans;
}

int main() {

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	ans = dp();
	cout << ans << endl;

	return 0;
}
