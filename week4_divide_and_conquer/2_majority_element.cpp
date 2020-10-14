#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using std::vector;

long long get_majority_element(vector<long long> &a, long long left, long long right) {
  std::unordered_map<int, int> _map;
  for(int i = left;i <= right; i++){
    _map[a[i]]++;

  }
  int n = right - left + 1;
  int th = n / 2;
  for(auto it : _map){
    if(it.second > th){
      return it.first;
    }
  }
  return -1;

}

int main() {
  int n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()-1) != -1) << '\n';
}
