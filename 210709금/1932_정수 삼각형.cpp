/* 1932 ���� �ﰢ�� */

#include <iostream>
#include <algorithm>
using namespace std;

int n, ans = 0; // �ﰢ���� ũ��, ��������� �� �ִ밪
int tri[501][501]; // �Էµ� ���� �ﰢ�� ���� ����
int d[501][501]; // ũ�Ⱑ i�� �ﰢ������ ���� ���� ���� ���� �ִ밪

int dp() {

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == 0) // ũ�Ⱑ i�� �ﰢ���� ���� ���� ���� ���, �ٷ� ���� �� �޾� �ش��ϴ� ��ġ ���� ����
				d[i][j] = d[i - 1][0] + tri[i][j];
			else if (j == n - 1) // ũ�Ⱑ i�� �ﰢ���� ���� ������ ���� ���, ���� �밢���� �� �޾� �ش��ϴ� ��ġ ���� ����
				d[i][j] = d[i - 1][n - 2] + tri[i][j];
			else // j = 1 ~ n - 2(�� ���� ���� ���� �밢���� �ٷ� ���� �� �� ū ���� �޾� �ش��ϴ� ��ġ ���� ����
				d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + tri[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		if(ans < d[n][i])
			ans = d[n][i]; // ������ �ٿ��� �ִ밪 ����
	}

	return ans;
}

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++)
			cin >> tri[i][j];
	}	

	ans = dp();
	cout << ans << endl;

	return 0;
}