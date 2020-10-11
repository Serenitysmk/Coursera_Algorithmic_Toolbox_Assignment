#include <iostream>
#include <vector>


void selection_sort(std::vector<int>& nums){
	int n = nums.size();
	for(int i = 0;i < n;i++){
		int min = 1e9;
		int min_pos = -1;
		for(int j = i; j < n; j++){
			if(nums[j] < min){
				min = nums[j];
				min_pos = j;
			}
		}
		if(min_pos != -1){
			int tmp = nums[i];
			nums[i] = nums[min_pos];
			nums[min_pos] = tmp;

		}
	}
}

int main(int argc, char * argv[]){
	int n;
	std::cin >> n;
	std::vector<int> nums(n);
	for(int i = 0;i < n; i++){
		std::cin >> nums[i];
	}
	selection_sort(nums);
	for(int i = 0;i < n;i++){
		std::cout << nums[i] << " ";
	}
	std::cout << std::endl;


}
