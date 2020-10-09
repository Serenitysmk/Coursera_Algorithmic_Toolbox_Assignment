#include <iostream>
#include <vector>
long long get_fibonacci_huge_mod(long long n, long long m);

int main(int argc, char * argv[]){
	long long  m, n;
	std::cin >> n >> m;
	std::cout << get_fibonacci_huge_mod(n, m) << std::endl;
}


long long get_fibonacci_huge_mod(long long n, long long m){
	if(n <= 1) return n;
	std::vector<long long> period;
	long long last2 = 0;
	long long last1 = 1;
	period.push_back(last2);
	period.push_back(last1);
	int i = 2;
	while(true){
		long long sum = (last2 + last1) % m;
		last2 = last1;
		last1 = sum;
		period.push_back(sum);
		if(sum == 1 && period[i-1] == 0) break;
		i++;
	}
	period.pop_back();
	period.pop_back();
	int period_size = period.size();
	//std::cout << "period size = " << period_size << std::endl;
	long long remainder = n % period_size;
	//for(auto & i: period){
	//	std::cout << i << " "; 
	//}
	//std::cout << "\n";
	//std::cout << "remainder = " << remainder << std::endl;


	return period[remainder];
}
