#include <stdio.h>

int main(void)
{
	int i, j, min, index, temp;

	int arr[10] = { 1,7,3,9,5,6,2,8,4,10 };

	for (i = 0; i < 10; i++) {
		min = 9999; //��� ���ҵ� ���� �� ū ���� ������. min���� �׻� �ּڰ��̿����ϱ� ������ ó���� �׻� ū ��
		// ���� Ž���ϴ� ���Ұ� ���� �ּڰ����� �۴ٸ� ���� Ž���ϴ� ���Ҹ� �ּڰ����� �ٲ���
		for (j = i; j < 10; j++) {
			if (min > arr[j]) {
				min = arr[j];
				index = j;
			}
		}
		// ������� swapping ����, ���� �ΰ��� ��ġ�� �ٲ۴�.
		// ���� �տ� �ִ� ���� min ���� ���� �ٲ��ְڴ�.
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
	for (int k = 0; k < 10; k++) {
		printf("%d ", arr[k]);
	}
	return 0;
}