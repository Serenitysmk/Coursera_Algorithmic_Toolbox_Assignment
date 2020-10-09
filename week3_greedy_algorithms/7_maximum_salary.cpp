#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool is_A_greater_or_equal_to_B(const std::string& A, const std::string& B){
	std::string s_num1 = A + B;
	std::string s_num2 = B + A;
	long long num1 = stoll(s_num1);
	long long num2 = stoll(s_num2);
	if(num1 >= num2){
		return true;
	}else{
		return false;
	}
}

string largest_number(vector<string> a) {
  //write your code here
  std::stringstream ret;
  while(!a.empty()){  
 	std::string max_num = "0";
	int max_pos = -1;
	for(int i = 0;i < a.size();i++){
		if(is_A_greater_or_equal_to_B(a[i], max_num)){
			max_num = a[i];
			max_pos = i;
		}
	}
	ret << max_num;
	a.erase(a.begin() + max_pos);
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a) << std::endl;
}
