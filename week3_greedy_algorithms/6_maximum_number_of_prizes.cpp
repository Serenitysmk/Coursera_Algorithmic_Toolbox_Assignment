#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int sum = 0;
  int a_i = 0;
  while(true){
	  if(sum + a_i+ 1 + a_i + 2 > n){
		  break;
	  }else{
		  a_i++;
		  sum += a_i;
		  summands.push_back(a_i);
	  }
  }
  a_i = n - sum;
  summands.push_back(a_i);
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
