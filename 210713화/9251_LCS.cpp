/* 9251 LCS */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char A[1001]; // ù° ���ڿ�
char B[1001]; // ��° ���ڿ�
int d[1001][1001]; // A ���ڿ��� i��°���� ���ڿ� B ���ڿ��� j��°������ ���ڸ� ��

void dp() {

	for (int i = 1; i <= strlen(A); i++) {
		for (int j = 1; j <= strlen(B); j++) {
			if (A[i - 1] == B[j - 1]) // ������ ���ڰ� ���� ��� ���� �밢�� + 1
				d[i][j] = d[i - 1][j - 1] + 1;
			else // �� ���ڰ� �ٸ� ���, ���� ���� ���� �� �� ū �� ������
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