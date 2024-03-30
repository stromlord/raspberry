#include <iostream>
using namespace std;

const int arrSize = 8;

void swap(int &a, int &b);	// 交换值
void arr_display(int arr[]);	// 展示数组

void sort_bubble(int arr[], char mode='D');	// 冒泡排序

int main(){
	int arr[] = {5, 8, 3, 6, 7, 2, 1, 9};
	arr_display(arr);
	
	sort_bubble(arr);	

	arr_display(arr);
	return 0;
}

void sort_bubble(int arr[], char mode){
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

void arr_display(int arr[]){
	cout << "Display array:" << endl;
	for (int i = 0; i < arrSize; i++) {cout << "arr[" << i << "]=" << arr[i] << "; ";}
	cout << endl;
}
