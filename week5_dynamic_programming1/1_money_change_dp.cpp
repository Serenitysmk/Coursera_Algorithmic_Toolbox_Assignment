#include <iostream>
#include <vector>


int get_change(int m) {
 	 //write your code here
	std::vector<int> min_changes(m+1);
	min_changes[0] = 0;
	for(int i = 1; i <= m; i++){
    if(i < 3){
      int m1 = i-1;
			min_changes[i] = min_changes[m1] + 1;
    }else if(i <= 3 && i < 4 ){
      int m1 = i-1;
      int m2 = i-3;
			min_changes[i] = std::min(min_changes[m1] + 1, min_changes[m2] + 1);
		}else{
      int m1 = i-1;
      int m2 = i-3;
      int m3 = i-4;
			int smaller = std::min(min_changes[m1] + 1, min_changes[m2] + 1);
			min_changes[i] = std::min(smaller, min_changes[m3] + 1);
		}

	}

  	return min_changes[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
