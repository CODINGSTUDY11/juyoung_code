/* 2096 내려가기 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;// 줄 수
int input[3]; // 입력값 저장
int d[3]; // i번째 줄까지 계산한 최대값 저장
int d2[3]; // i번째 줄까지 계산한 최소값 저장

int main() {

	int tmp0, tmp1, tmp2;
	cin >> n;

	// 초기값
	cin >> input[0] >> input[1] >> input[2];
	d2[0] = d[0] = input[0];
	d2[1] = d[1] = input[1];
	d2[2] = d[2] = input[2];

	for (int i = 1; i < n; i++) {
		
		cin >> input[0] >> input[1] >> input[2];
		
		// 최대값 구하기
		tmp0 = d[0];
		tmp1 = d[1];
		tmp2 = d[2];

		d[0] = input[0] + max(d[0], d[1]);
		d[1] = input[1] + max({ tmp0, d[1], d[2] });
		d[2] = input[2] + max(tmp1, tmp2);

		// 최소값 구하기
		tmp0 = d2[0];
		tmp1 = d2[1];
		tmp2 = d2[2];

		d2[0] = input[0] + min(d2[0], d2[1]);
		d2[1] = input[1] + min({ tmp0, d2[1], d2[2] });
		d2[2] = input[2] + min(tmp1, tmp2);

	}
	cout << max({ d[0], d[1], d[2] }) << " " << min({ d2[0], d2[1], d2[2] }) << endl;

	return 0;
}