#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                (long long)numbers[first] * (long long)numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const std::vector<int> & numbers){
	int max_index1 = -1;
	int max_index2 = -1;
	int max1 = -1e9;
	int max2 = -1e9;
	int n = numbers.size();
	for(int i = 0; i < n ; i++){
		if(numbers[i] > max1){
			max_index1 = i;
			max1 = numbers[i];
		}
	}

	for(int i = 0; i < n ; i++){
		if((i != max_index1) && (numbers[i] > max2)){
			max_index2 = i;
			max2 = numbers[i];
		}
	}
	return (long long)max1 * (long long)max2;
}


int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}
