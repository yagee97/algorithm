#include <stdio.h>

int main(void)
{
	int i, j, temp;
	int arr[10] = { 10,5,6,7,3,2,4,8,9,1 };

	for (i = 0; i < 10; i++) {
		//버블정렬은 한 pass가 끝날 때마다 
		//리스트의 맨 끝에 가장 큰 값이 정렬되기 때문에 j의 범위는 9-i
		for (j = 0 ; j <9-i; j++) {
			//반복을 할때마다 당장 옆에 원소와 비교
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