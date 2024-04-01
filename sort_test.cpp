#include <iostream>
#include "sort.h"

const int arrSize = 8;

int main(){
  int arr[] = {5, 8, 3, 6, 7, 2, 1, 9};
  arr_display(arr, arrSize);

  sort_bubble(arr, arrSize);

  arr_display(arr, arrSize);

  return 0;
}

