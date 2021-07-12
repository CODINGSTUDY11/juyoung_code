/* 2096 �������� */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;// �� ��
int input[3]; // �Է°� ����
int d[3]; // i��° �ٱ��� ����� �ִ밪 ����
int d2[3]; // i��° �ٱ��� ����� �ּҰ� ����

int main() {

	int tmp0, tmp1, tmp2;
	cin >> n;

	// �ʱⰪ
	cin >> input[0] >> input[1] >> input[2];
	d2[0] = d[0] = input[0];
	d2[1] = d[1] = input[1];
	d2[2] = d[2] = input[2];

	for (int i = 1; i < n; i++) {
		
		cin >> input[0] >> input[1] >> input[2];
		
		// �ִ밪 ���ϱ�
		tmp0 = d[0];
		tmp1 = d[1];
		tmp2 = d[2];

		d[0] = input[0] + max(d[0], d[1]);
		d[1] = input[1] + max({ tmp0, d[1], d[2] });
		d[2] = input[2] + max(tmp1, tmp2);

		// �ּҰ� ���ϱ�
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