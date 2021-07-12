/* 9251 LCS */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char A[1001]; // 첫째 문자열
char B[1001]; // 둘째 문자열
int d[1001][1001]; // A 문자열의 i번째까지 문자와 B 문자열의 j번째까지의 문자를 비교

void dp() {

	for (int i = 1; i <= strlen(A); i++) {
		for (int j = 1; j <= strlen(B); j++) {
			if (A[i - 1] == B[j - 1]) // 비교중인 문자가 같은 경우 왼쪽 대각선 + 1
				d[i][j] = d[i - 1][j - 1] + 1;
			else // 두 문자가 다른 경우, 왼쪽 값과 위쪽 값 중 큰 값 가져옴
				d[i][j] = max(d[i][j - 1], d[i - 1][j]);
		}
	}

	cout << d[strlen(A)][strlen(B)] << endl;
}

int main() {

	cin >> A >> B;
	dp();

	return 0;
}