#include <iostream>
#include <cassert>
#include <vector>
#include <math.h>
using std::vector;

int binary_search_recursive(const vector<int>& a, int x, int left, int right) {
  //write your code here
  if(left > right) return -1; // not found;
  int mid = floor((left + right) / 2);
  if(a[mid] == x){
	  return mid;
  }else if(x > a[mid]){
	  return binary_search_recursive(a, x, mid + 1, right);
  }else if(x < a[mid]){
	  return binary_search_recursive(a, x, left, mid - 1);
  }
}

int binary_search_iteration(const vector<int>& a, int x){
	// write your code here
	int left = 0;
	int right = (int)a.size()- 1;

	while(left <= right){
		int mid = floor((left + right) / 2);
		if(a[mid] == x){
			return mid;
		}else if(x > a[mid]){
			left = mid + 1;
		}else{
			right = mid - 1;
		}
	}
	// not found
	return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    // using iteration implementation
     std::cout << binary_search_iteration(a, b[i]) << ' ';
   
    // using recursive implementation
    //int length = a.size();
    //std::cout << binary_search_recursive(a, b[i], 0, length - 1) << ' ';

  }
}
