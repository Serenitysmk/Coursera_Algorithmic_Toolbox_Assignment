#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

struct Item{
public:
	Item(){}
	Item(int weight, int value){
		m_weight = weight;
		m_value = value;
		m_unit_value = (double)m_value / (double)m_weight;
	}

	bool operator < (const Item& other) const {
		return m_unit_value < other.m_unit_value ;
	}

	int m_weight;
	int m_value;
	double m_unit_value;

	
};


double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  int num_items = weights.size();
  std::vector<Item> items;

  for(int i = 0; i < num_items; i++){
	  Item item(weights[i], values[i]);
	  items.push_back(item);
  }
  std::sort(items.begin(), items.end());

  /// sort the items with value / weight
  //for(int i = 0;i < num_items;i++){
  //	  std::cout << "item: " << i << ", unit_value : " << items[i].m_unit_value << std::endl; 
  // }

  int remaining_capacity = capacity;
  for(int i = num_items ;i >= 0; i--){
	  if(remaining_capacity == 0) break;
	  Item item = items[i];

	  if(remaining_capacity >= item.m_weight){
	  	 value += item.m_unit_value * item.m_weight;
		 remaining_capacity -= item.m_weight;
	  }else{
		 value += item.m_unit_value * remaining_capacity;
		 remaining_capacity -= remaining_capacity;
	  }
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
