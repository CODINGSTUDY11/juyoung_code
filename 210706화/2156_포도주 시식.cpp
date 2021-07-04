/* 2156 ������ �ý� */

#include <iostream>
#include <algorithm>
using namespace std;

int n, ans; // ������ ���� ����, ��������� �ִ� ������ ��
int wine[10001]; // ������ ��
int d[10001][3]; // i��° ���� ���� �� ���ӵ� ������ ���� �ִ� ������ ��

int dp() {

	// �ʱ�ȭ
	d[1][1] = d[1][2] = d[2][0] = wine[1];
	d[2][1] = wine[2];
	d[2][2] = wine[1] + wine[2];
	ans = max({ d[2][0], d[2][1], d[2][2] });
	
	for (int i = 3; i <= n; i++) { 
		// 0: ���� �� �� �Դ� ���, 1: ���� X(�� ��°), 2: ���� O(���� �� ��°)
		d[i][0] = max({ d[i - 1][0], d[i - 1][1], d[i - 1][2] }); // i-1��°������ �ִ� ������ ��
		d[i][1] = wine[i] + max({ d[i - 2][0], d[i - 2][1], d[i - 2][2] }); // ���� ������ �� + i-2��°������ �ִ� ������ ��
		d[i][2] = wine[i - 1] + wine[i] + max({ d[i - 3][0], d[i - 3][1], d[i - 3][2] }); // i-1��° ������ �� + ���� ������ �� + i-3��°������ �ִ� ������ ��
						
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