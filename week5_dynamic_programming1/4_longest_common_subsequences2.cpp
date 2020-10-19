#include <iostream>
#include <vector>

using std::vector;

int longest_common_subsequences2(vector<int> &a, vector<int> &b) {
  //write your code here
  size_t m = a.size();
  size_t n = b.size();
  std::vector<int> subseq;

  std::vector<std::vector<int>> dp(m+1);
  std::vector<std::vector<std::pair<int,int>>> dp_paths(m+1);
  for(size_t i = 0;i < m+1;i++){
	  dp[i].resize(n+1, 0);
	  dp_paths[i].resize(n+1, std::make_pair(-1, -1));
  }

  // iniitialize the dynamic programming matrix
  for(size_t i = 0;i < m+1;i++){
	  dp[i][0] = i;
	  dp_paths[i][0] = std::make_pair(i-1, 0);
  }
  for(size_t j = 0; j < n+1; j++){
	  dp[0][j] = j;
	  dp_paths[0][j] = std::make_pair(0, j-1);
  }

  dp_paths[0][0] = std::make_pair(-1, -1);

  // fill up the dynamic programming matrix
  
  for(size_t i = 1;i < m + 1; i++){
	  for(size_t j = 1; j < n+1; j++){
		  if(a[i-1] == b[j-1]){
			  dp[i][j] = dp[i-1][j-1];
			  dp_paths[i][j] = std::make_pair(i-1,j-1);
		  }else{
			  dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + 1;
			  if(dp[i-1][j] <= dp[i][j-1]){
				  dp_paths[i][j] = std::make_pair(i-1,j);
			  }else{
				  dp_paths[i][j] = std::make_pair(i, j-1);
			  }
		  }
	  }
  }

  int i = m;
  int j = n;
  while(true){
	  if(a[i-1] == b[j-1]){
		  subseq.push_back(a[i-1]);
	  }
	  std::pair<int, int> path_to_curr = dp_paths[i][j];
	  i = path_to_curr.first;
	  j = path_to_curr.second;
	  if(i == 0 || j == 0){
		  break;
	  }
  }

  return subseq.size();
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << longest_common_subsequences2(a,b)<< std::endl;
}
