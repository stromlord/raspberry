#include <iostream>
#include "sort.h"

void sort_bubble(int arr[], int arrSize, char mode){
  using namespace std;
	for (int i = 0; i < arrSize-1; i++){
		for (int j = i; j >= 0; j--){
			if (mode == 'D') {if (arr[j] > arr[j+1]){swap(arr[j], arr[j+1]);}}	// 升序
			else if (mode == 'I') {if (arr[j] < arr[j+1]){swap(arr[j], arr[j+1]);}}	// 降序
			else {cout << "mode error!" << endl;}
		}
	}	
}

// 利用引用传递交换数值
void swap(int &a, int &b){int temp; temp = a; a = b; b = temp;}

void arr_display(int arr[], int arrSize){
  using namespace std;
	cout << "Display array:" << endl;
	for (int i = 0; i < arrSize; i++) {cout << "arr[" << i << "]=" << arr[i] << "; ";}
	cout << endl;
}
