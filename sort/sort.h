#ifndef SORT_H_
#define SORT_H_

#include <vector>
using namespace std;

class sort{
private:
	int arr_size;
public:
	void sort_bubble(vector<int> & arr, char mode='D');		// 冒泡排序
	
	void swap(int &a, int &b);				// 交换值
	void display(vector<int> & arr);		// 展示数组
};
#endif
