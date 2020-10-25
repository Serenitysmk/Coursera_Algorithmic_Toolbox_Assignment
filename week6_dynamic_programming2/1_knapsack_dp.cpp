#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  size_t num_w = w.size();
  std::vector<std::vector<int>> dp(W + 1, std::vector<int>(num_w + 1, 0));

  for(int i = 1; i <= W; i++){
    for(int j = 1; j <= num_w; j++){
      if(i >= w[j-1]){
        dp[i][j] = std::max(dp[i][j-1], dp[i-w[j-1]][j-1] + w[j-1]);
      }else{
        dp[i][j] = dp[i][j-1];
      }

    }

  }
  return dp[W][num_w];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
