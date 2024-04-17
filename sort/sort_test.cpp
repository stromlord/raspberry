#include <iostream>
#include <vector>
#include "sort.h"

const int arrSize = 8;

int main(){
	sort st;
	std::vector<int> arr = {5, 10, 16, 18, 15, 3, 6, 9, 7};
	st.display(arr);
	st.sort_bubble(arr);
	st.display(arr);
  return 0;
}

