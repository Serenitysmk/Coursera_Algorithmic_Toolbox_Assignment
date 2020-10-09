#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int num_refills = 0;
    int current_pos = 0;
    int current_dist = 0;
    int last_pos = current_pos;
    int num_stops = stops.size();
    stops.insert(stops.begin(), 0);
    stops.push_back(dist);

    while(current_pos <= num_stops){
      last_pos = current_pos;
      while((current_pos <= num_stops) && (stops[current_pos+1] <= current_dist + tank)){
        current_pos++;
      }
      if(current_pos == last_pos) return -1;
      if(current_pos <= num_stops){
        num_refills++;
        current_dist = stops[current_pos];
      }

    }
    return num_refills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
