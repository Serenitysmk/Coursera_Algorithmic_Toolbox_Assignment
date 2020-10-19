#include <iostream>
#include <string>
#include <vector>

using std::string;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  size_t m = str1.size();
  size_t n = str2.size();
  
  // initialize dynamic programming matrix
  std::vector<std::vector<int>> dp(m+1); 
  for(size_t i = 0;i < m+1;i++){
	  dp[i].resize(n+1, 0);
  }

  for(size_t i = 0;i < m + 1;i++){
	  dp[i][0] = i;
  }
  for(size_t j = 0;j < n + 1; j++){
	  dp[0][j] = j;
  }

  //fill up the dynamic programming matrix
  for(size_t i = 1; i < m+1;i++){
	  for(size_t j = 1; j < n + 1; j++){
		  if(str1[i-1] == str2[j-1]){
			  dp[i][j] = dp[i-1][j-1];
		  }else{
			  int smaller = std::min(dp[i-1][j], dp[i][j-1]);
			  dp[i][j] = std::min(dp[i-1][j-1], smaller) + 1;
		  }
	  }
  }
  return dp[m][n];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
