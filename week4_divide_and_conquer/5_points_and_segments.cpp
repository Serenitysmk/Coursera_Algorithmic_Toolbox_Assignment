#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Segment{
public:
  Segment()=default;
  Segment(int start, int end):m_start(start), m_end(end){}
  int m_start;
  int m_end;

};

class AugPoint{
public:
  AugPoint() = default;
  AugPoint(int pos, int flag): m_pos(pos), m_flag(flag){}

  bool operator<(const AugPoint& other) const {
    if(m_pos == other.m_pos){
      return m_flag < other.m_flag;
    }else{
      return m_pos < other.m_pos;
    }
  }

public:
  int m_pos;
  int m_flag; // left:1, point:2 ,right: 3
  int m_point_idx = -1; // index of the input point
};

vector<int> fast_count_segments(std::vector<Segment>& segments, vector<int> points) {
  vector<int> cnt(points.size());
  //write your code here
  std::vector<AugPoint> aug_points;
  for(size_t i = 0;i < segments.size();i++){
    AugPoint aug_point1(segments[i].m_start, 1);
    AugPoint aug_point2(segments[i].m_end, 3);
    aug_points.push_back(aug_point1);
    aug_points.push_back(aug_point2);
  }
  for(size_t i = 0;i < points.size();i++){
    AugPoint aug_point(points[i], 2);
    aug_point.m_point_idx = i;
    aug_points.emplace_back(aug_point);
  }

  // sort aug points
  std::sort(aug_points.begin(), aug_points.end());

  size_t counter = 0;

  for(size_t i = 0;i < aug_points.size(); i++){
    AugPoint point = aug_points[i];
    if(point.m_flag == 1){
      counter++;
    }else if(point.m_flag == 2){
      size_t index = point.m_point_idx;
      cnt[index] = counter;
    }else{
      counter--;
    }
  }

  return cnt;
}

vector<int> naive_count_segments(std::vector<Segment>& segments, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < segments.size(); j++) {
      cnt[i] += segments[j].m_start <= points[i] && points[i] <= segments[j].m_end;
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<Segment> segments(n);
  for (size_t i = 0; i < n; i++) {
    Segment segment;
    std::cin >> segment.m_start >> segment.m_end;
    segments[i] = segment;
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(segments, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
  std::cout << std::endl;
}
