#include <stdio.h>

int main(void)
{
	int i, j, min, index, temp;

	int arr[10] = { 1,7,3,9,5,6,2,8,4,10 };

	for (i = 0; i < 10; i++) {
		min = 9999; //모든 원소들 보다 더 큰 숫자 무작위. min값은 항상 최솟값이여야하기 때문에 처음엔 항상 큰 값
		// 현재 탐색하는 원소가 현재 최솟값보다 작다면 현재 탐색하는 원소를 최솟값으로 바꿔줌
		for (j = i; j < 10; j++) {
			if (min > arr[j]) {
				min = arr[j];
				index = j;
			}
		}
		// 여기부터 swapping 과정, 원소 두개의 위치를 바꾼다.
		// 가장 앞에 있는 값과 min 값을 서로 바꿔주겠다.
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
	for (int k = 0; k < 10; k++) {
		printf("%d ", arr[k]);
	}
	return 0;
}