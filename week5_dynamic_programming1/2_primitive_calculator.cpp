#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  std::vector<int> min_operation(n+1);
  std::vector<int> min_operator(n+1);

  min_operation[0] = 0;
  min_operation[1] = 0;
  min_operator[0] = 0;
  min_operator[1] = 0;
  for(int i = 2; i <= n; i++){
    int min_index = -1;
    int min_flag = -1;
    if(i % 2 == 0 && i % 3 == 0){
      int m1 = i-1;
      int m2 = i/2;
      int m3 = i/3;
      if(min_operation[m1] + 1 <= min_operation[m2] + 1){
        min_index = m1;
        min_flag = 1;
      }else{
        min_index = m2;
        min_flag = 2;
      }
      if(min_operation[min_index] + 1 <= min_operation[m3] + 1){
        min_index = min_index;
        min_flag = min_flag;
      }else{
        min_index = m3;
        min_flag = 3;
      }

      min_operation[i] = min_operation[min_index] + 1;
      min_operator[i] = min_flag;
    }else if(i % 2 == 0 && i % 3 != 0){
      int m1 = i-1;
      int m2 = i/2;
      if(min_operation[m1] +1 <= min_operation[m2]+1){
        min_index = m1;
        min_flag = 1;
      }else{
        min_index = m2;
        min_flag = 2;
      }
      min_operation[i] = min_operation[min_index] + 1;
      min_operator[i] = min_flag;

    }else if(i % 2 != 0 && i % 3 == 0){
      int m1 = i-1;
      int m3 = i/3;

      if(min_operation[m1] + 1 <= min_operation[m3] + 1){
        min_index = m1;
        min_flag = 1;
      }else{
        min_index = m3;
        min_flag = 3;
      }
      min_operation[i] = min_operation[min_index] + 1;
      min_operator[i] = min_flag;

    }else if(i % 2 != 0 && i % 3 != 0){
      int m1 = i-1;
      min_flag = 1;
      min_operation[i] = min_operation[m1] + 1;
      min_operator[i] = min_flag;
    }
  }

  while (n >= 1) {
    sequence.push_back(n);
    int flag = min_operator[n];
    if(flag == 1){
      n = n-1;
    }else if(flag == 2){
      n = n/2;
    }else if(flag == 3){
      n = n/3;
    }else if(flag == 0){
      break;
    }
  }
  std::reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
