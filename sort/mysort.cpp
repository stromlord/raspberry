#include <iostream>
using namespace std;

#include <vector>
#include "sort.h"
using std::vector;

void sort::sort_bubble(vector<int> & arr, char mode){
	using namespace std;
	arr_size = arr.size();
	for (int i = 0; i < arr_size-1; i++){
		for (int j = i; j >= 0; j--){
			if (mode == 'D') {if (arr[j] > arr[j+1]){swap(arr[j], arr[j+1]);}}	// 升序
			else if (mode == 'I') {if (arr[j] < arr[j+1]){swap(arr[j], arr[j+1]);}}	// 降序
			else {cout << "mode error!" << endl;}
		}
	}	
}

// 利用引用传递交换数值
void sort::swap(int &a, int &b){int temp; temp = a; a = b; b = temp;}

void sort::display(vector<int> & arr){
	using namespace std;
	cout << "Display array:" << endl;
	arr_size = arr.size();
	for (int i = 0; i < arr_size; i++) {cout << "arr[" << i << "]=" << arr[i] << "; ";}
	cout << endl;
}
