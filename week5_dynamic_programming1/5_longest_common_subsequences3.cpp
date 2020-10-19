#include <iostream>
#include <vector>

using std::vector;

int longest_common_subsequences3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  size_t m = a.size();
  size_t n = b.size();
  size_t p = c.size();

  std::vector<std::vector<std::vector<int>>> dp(m+1);

  for(size_t i = 0;i < m+1;i++){
    dp[i].resize(n+1);
    for(size_t j = 0;j < n+1; j++){
      dp[i][j].resize(p+1, 0);
    }
  }

  // fill up the dynamic programming matrix
  for(size_t i = 1; i < m+1; i++){
    for(size_t j = 1; j < n+1; j++){
      for(size_t k = 1; k < p+1; k++){
        if(a[i-1] == b[j-1] && a[i-1] == c[k-1] && b[j-1] && c[k-1]){
          dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
        }else{
          int larger = std::max(dp[i-1][j][k], dp[i][j-1][k]);
          dp[i][j][k] = std::max(dp[i][j][k-1], larger);
        }

      }
    }
  }

  return dp[m][n][p];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << longest_common_subsequences3(a, b, c) << std::endl;
}
