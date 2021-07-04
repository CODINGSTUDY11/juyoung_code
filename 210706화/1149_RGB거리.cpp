/* 1149 RGB�Ÿ� */

#include <iostream>
#include <algorithm>
using namespace std;

int n, ans; // ���� ��, �ּ� ���
int d[1001][3]; // i��° ���� R/G/B�� ĥ���� ���� �ּ� ���

int dp() {

	int money[3];

	for (int i = 1; i <= n; i++) { 
		cin >> money[0] >> money[1] >> money[2];
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + money[0]; // i - 1��° ���� G Ȥ�� B�� ĥ�� �� �� �ּ� ��� + i��° ���� R�� ĥ�ϴ� ���
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + money[1]; // i - 1��° ���� R Ȥ�� B�� ĥ�� �� �� �ּ� ��� + i��° ���� G�� ĥ�ϴ� ���
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + money[2]; // i - 1��° ���� R Ȥ�� G�� ĥ�� �� �� �ּ� ��� + i��° ���� B�� ĥ�ϴ� ���
	}

	return min(min(d[n][0], d[n][1]), d[n][2]);
}

int main() {

	cin >> n;
	ans = dp();
	cout << ans << endl;

	return 0;
}