#include <stdio.h>

int main(void)
{
	int i, j, temp;
	int arr[10] = { 10,5,6,7,3,2,4,8,9,1 };

	for (i = 0; i < 10; i++) {
		//���������� �� pass�� ���� ������ 
		//����Ʈ�� �� ���� ���� ū ���� ���ĵǱ� ������ j�� ������ 9-i
		for (j = 0 ; j <9-i; j++) {
			//�ݺ��� �Ҷ����� ���� ���� ���ҿ� ��
			if (arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		} 
	} 
	for (int k = 0; k < 10; k++)
		printf("%d ", arr[k]);
	return 0;

}