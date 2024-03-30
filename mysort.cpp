#include <iostream>
using namespace std;

const int arrSize = 8;

void swap(int &a, int &b);
void arr_display(int arr[]);

int main(){
	int arr[] = {5, 8, 3, 6, 7, 2, 1, 9};
	arr_display(arr);
	cout << "arr[2]=" << arr[2] << "; arr[3]=" << arr[3] << endl;
	swap(arr[2], arr[3]);
	cout << "arr[2]=" << arr[2] << "; arr[3]=" << arr[3] << endl;
	arr_display(arr);
	return 0;
}

void swap(int &a, int &b){int temp; temp = a; a = b; b = temp;}

void arr_display(int arr[]){
	cout << "Display array:" << endl;
	for (int i = 0; i < arrSize; i++) {cout << "arr[" << i << "]=" << arr[i] << "; ";}
	cout << endl;
}
