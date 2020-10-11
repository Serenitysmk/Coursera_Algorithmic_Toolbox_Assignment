#include <iostream>
#include <vector>
#include <math.h>
std::vector<int> merge_sort_impl(const std::vector<int>& nums, int left, int right);

std::vector<int> merge_sort(const std::vector<int>& nums);

int main(int argc, char* argv[]){
  int n;
  std::cin >> n;
  std::vector<int> nums(n);
  for(int i = 0; i < n;i++){
    std::cin >> nums[i];
  }
  std::vector<int> sorted;
  sorted = merge_sort(nums);

  for(int i = 0;i < n;i++){
    std::cout << sorted[i] << " ";
  }

  std::cout << std::endl;
}

/// implementation ///


std::vector<int> merge_sort_impl(const std::vector<int>& nums, int left, int right){
  std::vector<int> merged;
  if(left == right){
    merged.push_back(nums[left]);
    return merged;
  }
  int mid = floor((left + right) / 2);
  // sort left
  std::vector<int> sorted_left = merge_sort_impl(nums, left, mid);
  // sort right
  std::vector<int> sorted_right =  merge_sort_impl(nums, mid + 1, right);
  // merge to a sorted vector
  auto it_l = sorted_left.begin();
  auto it_r = sorted_right.begin();
  while(sorted_left.size() != 0 && sorted_right.size() != 0){
    if(sorted_left[0] <= sorted_right[0]){
      merged.push_back(sorted_left[0]);
      it_l = sorted_left.erase(sorted_left.begin());
    }else{
      merged.push_back(sorted_right[0]);
      it_r = sorted_right.erase(sorted_right.begin());
    }
  }
  for(int i = 0;i < sorted_left.size();i++){
    merged.push_back(sorted_left[i]);
  }
  for(int i = 0;i < sorted_right.size();i++){
    merged.push_back(sorted_right[i]);
  }
  return merged;
}


std::vector<int> merge_sort(const std::vector<int>& nums){
  int n = nums.size();
  std::vector<int> merged = merge_sort_impl(nums, 0, n-1);
  return merged;
}
