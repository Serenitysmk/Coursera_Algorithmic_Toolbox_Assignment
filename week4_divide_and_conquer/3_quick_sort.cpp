#include <iostream>
#include <vector>

void quick_sort(std::vector<int>& nums);

void quick_sort_impl(std::vector<int>& nums, int left, int right);

int main(int argc, char * argv[]){
	int n ;
	std::cin >> n;

	std::vector<int> nums(n);
	for(int i =0; i < n;i++){
		std::cin >> nums[i];
	}

  quick_sort(nums);
	for(int i = 0 ; i < n;i++){
		std::cout << nums[i] << " ";
	}
	std::cout << std::endl;
}

/// implementation ///

void quick_sort(std::vector<int>& nums){
	quick_sort_impl(nums, 0, nums.size() - 1);	
}

void quick_sort_impl(std::vector<int>& nums, int left, int right){
  if(left >= right){
    return;
  }
  /// 2 way partition
//  int m = left + (std::rand() % (right - left + 1));
//  std::swap(nums[left], nums[m]);

//  int j = left;
//  for(int i = left + 1; i <= right; i++){
//    if(nums[i] <= nums[left]){
//      j++;
//      std::swap(nums[i], nums[j]);
//    }
//  }
//  std::swap(nums[left], nums[j]);

  /// 3 way partition

  int m = left + (std::rand() % (right - left) + 1);
  int m_pivot = nums[m];
  int m1 = left;
  int m2 = right;

  for(int i = left;i <= m2;i++){
    if(nums[i] < m_pivot){
      std::swap(nums[i], nums[m1]);
      m1++;
    }else if(nums[i] > m_pivot){
      std::swap(nums[i] , nums[m2]);
      m2--;
      i--;
    }
  }
  quick_sort_impl(nums, left, m1 - 1);
  quick_sort_impl(nums, m2 + 1, right);
}
