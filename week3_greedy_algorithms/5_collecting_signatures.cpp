#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <unordered_map>
using std::vector;

struct Segment {
  int start, end;
  bool operator < (const Segment& other) const
  {
    return end < other.end;
  }

  bool is_point_inside(int pos) const{
    if(pos >= start && pos <= end){
      return true;
    }else{
      return false;
    }
  }
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  // sort by right end
  std::sort(segments.begin(), segments.end());

  int pos = segments[0].end;
  points.push_back(pos);
  for(size_t i = 1;i < segments.size(); i++){
	  if(!segments[i].is_point_inside(pos)){
		  pos = segments[i].end;
		  points.push_back(pos);
	  }
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
