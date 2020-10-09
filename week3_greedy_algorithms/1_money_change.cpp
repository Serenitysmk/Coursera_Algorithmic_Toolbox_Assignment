#include <iostream>
#include <vector>

int get_change(int m) {
  //write your code here
  int num_changes = 0;
  std::vector<int> change{1,5,10};
  int mod = -1;
  while(m != 0){
	  for(int i = 2; i >= 0; i-- ){
		  int max_change = change[i];
		  num_changes += m / max_change;
		  m = m % max_change;
	  }
  }
  return num_changes;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
