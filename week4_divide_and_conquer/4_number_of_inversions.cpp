#include <iostream>
#include <vector>
#include <math.h>
using std::vector;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left){
	  b[left] = a[left];
   return number_of_inversions;
  } 
  size_t mid = floor((left + right) / 2);
  number_of_inversions += get_number_of_inversions(a, b, left, mid);
  number_of_inversions += get_number_of_inversions(a, b, mid+1, right);
  //write your code here

  std::vector<int> tmp;
  int pos_l = left;
  int pos_r = mid + 1;
  while(pos_l <= mid && pos_r <= right){
	 if(b[pos_l] <= b[pos_r]){
		 tmp.push_back(b[pos_l]);
		 pos_l++;
	 }else{
		 tmp.push_back(b[pos_r]);
		 pos_r++;
		 number_of_inversions += mid - pos_l + 1;
	 }
  }
  while(pos_l <= mid){
  	tmp.push_back(b[pos_l]);
	pos_l++;
  }
  while(pos_r <= right){
  	tmp.push_back(b[pos_r]);
	pos_r++;
  }
  for(int i =0;i < tmp.size();i++){
	  b[i + left] = tmp[i];
  }
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());

  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';

  /*
  for(int i =0;i < n;i++){
	  std::cout << b[i] << " ";
  }
  std::cout << std::endl;
  */

}
