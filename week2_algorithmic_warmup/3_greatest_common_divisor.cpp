#include <iostream>

int gcd_simple(int a , int b);

int gcd_recursive(int a , int b);

int main(int argc, char* argv[]){
	int a,b;
	std::cin >> a >> b;
	//std::cout << gcd_simple(a,b) << "\n";
	std::cout << gcd_recursive(a, b) << "\n";
}

/// implementation ///

int gcd_simple(int a , int b){
	int result = 1;
	for(int _s =1 ; _s < a + b; _s++ ){
		if(!(a % _s) && !(b % _s)) result = _s;
	}
	return result;
}

int gcd_recursive(int a , int b){
	if(b == 0) return a;
	int remainder = a % b;
	return gcd_recursive(b, remainder);
}
