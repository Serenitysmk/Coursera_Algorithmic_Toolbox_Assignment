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
  int i = 0;
  int j = 0;
  int length_l = sorted_left.size();
  int length_r = sorted_right.size();

  while(i < length_l && j < length_r){
    if(sorted_left[i] <= sorted_right[j]){
      merged.push_back(sorted_left[i]);
      i++;
    }else{
      merged.push_back(sorted_right[j]);
      j++;
    }
  }
  while(i < length_l){merged.push_back(sorted_left[i++]);}
  while(j < length_r){merged.push_back(sorted_right[j++]);}
  return merged;
}


std::vector<int> merge_sort(const std::vector<int>& nums){
  int n = nums.size();
  std::vector<int> merged = merge_sort_impl(nums, 0, n-1);
  return merged;
}
