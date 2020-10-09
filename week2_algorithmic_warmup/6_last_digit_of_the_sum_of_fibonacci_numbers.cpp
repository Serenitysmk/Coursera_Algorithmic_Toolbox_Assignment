#include <iostream>
#include <vector>
int get_fib_sum_last_digit(int n);

int get_fib_sum_last_digit2(long long n);

int get_fib_sum_last_digit_period(long long n);

int main(int argc, char * argv[]){
	long long n;
	std::cin >> n;
	std::cout << get_fib_sum_last_digit_period(n) << std::endl;
}


int get_fib_sum_last_digit(int n){
	if(n <= 1) return n;
	std::vector<long long> fibs(n+1);
	fibs[0] = 0;
	fibs[1] = 1;
	long long sum = 1;
	for(int i = 2; i <= n; i++){
		fibs[i] = fibs[i-1] + fibs[i - 2];
		sum += fibs[i];
	}
	std::cout << "fib : " << fibs[n] << "\n";
	std::cout << "sum : " << sum << "\n";
	return sum % 10;

}

int get_fib_sum_last_digit2(long long n){
	if(n <= 1) return n;
	long long last2 = 0;
	long long last1 = 1;
	int sum = last1 + last2;
	for(int i =2; i <= n;i++){
		int fib = (last2 + last1)% 10;
		last2 = last1;
		last1 = fib;
		sum += fib;
	}
	//std::cout << "fib : " << fibs[n] << "\n";
	return sum % 10;
}

int get_fib_sum_last_digit_period(long long n){
	if(n <= 1) return n;
	std::vector<int> period;
	long long last2 = 0;
	long long last1 = 1;
	int mod = 10;
	period.push_back(last2);
	period.push_back(last1);
	while(true){
		int fib_mod = (last2 + last1) % mod;
		period.push_back(fib_mod);
		if(fib_mod == 1 && last1 == 0) break;
		last2 = last1;
		last1 = fib_mod;
	}
	period.pop_back();
	period.pop_back();
	int num_period = period.size();
	long long  multiplier = n / num_period;
	long long  remainder = n % num_period;
	//std::cout << "num period = " << num_period << "\n";
	//for(auto & fib: period){
	//	std::cout << fib << " ";
	//}
	//std::cout << std::endl;
	//std::cout << "multiplier: " << multiplier << "\n";
	//std::cout << "remainder: " << remainder << "\n";
	int sum_period = 0;
	int sum_remainder = 0;
	for(int i = 0;i < num_period; i++){
		sum_period += period[i];
	}
	for(int i = 0;i <= remainder;i++){
		//std::cout << "period " << i << " : " << period[i];
		sum_remainder += period[i];
	}
	//std::cout << "\n";
	//std::cout << "sum remainder: " << sum_remainder << "\n";
	int sum = (multiplier * sum_period + sum_remainder) % 10 ;
	return sum;
	
}
