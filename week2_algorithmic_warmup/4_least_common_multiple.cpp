#include <iostream>

long long gcd(int a , int b);

long long lcm(int a, int b);

int main(int argc, char * argv[]){
	int a, b;
	std::cin >> a >> b;
	std::cout << lcm(a,b) << std::endl;
}

long long lcm(int a, int b){
	long long _gcd = gcd(a,b);
	long long mul = (long long)a * (long long)b;
	return mul / _gcd; 
}
long long gcd(int a, int b){
	if(b == 0) return a;
	int remainder = a % b;
	return gcd(b, remainder);
}
