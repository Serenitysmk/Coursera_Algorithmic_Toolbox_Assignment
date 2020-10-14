#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <limits.h>

#include <random>

using std::vector;
using std::string;
using std::pair;
using std::min;

class Point{
public:
  Point(){}
  Point(long long x, long long y):m_x(x), m_y(y){}
  double distanceTo(const Point& other);
  long long m_x;
  long long m_y;
};

bool sort_by_x(const Point & a, const Point & b);

bool sort_by_y_decrease(const Point & a, const Point & b);


double minimal_distance_impl(std::vector<Point>& points, size_t left, size_t right);

double minimal_distance(std::vector<Point>& points);

double minimal_distance_naive(std::vector<Point>& points);

void stress_test(size_t num_trials, size_t max_num_points, long long min, long long max);

int main() {
  bool run_normal = true;
  if(run_normal){
    size_t n;
    std::cin >> n;
    std::vector<Point> points(n);
    for (size_t i = 0; i < n; i++) {
      Point p;
      std::cin >> p.m_x >> p.m_y;
      points[i] = p;
    }

    std::cout << std::fixed;
    std::cout << std::setprecision(9) << minimal_distance(points) << "\n";
  }

  bool run_stress_test = false;
  if(run_stress_test){
    stress_test(10000, 100, -100, 100);
  }

}

/// implementation ///


double Point::distanceTo(const Point& other){
  double diff_x = m_x - other.m_x;
  double diff_y = m_y - other.m_y;

  return sqrt(diff_x * diff_x + diff_y * diff_y);
}

bool sort_by_x(const Point& a, const Point & b){
  return a.m_x < b.m_x;
}

bool sort_by_y_decrease(const Point& a, const Point& b){
  return a.m_y > b.m_y;
}


double minimal_distance_impl(std::vector<Point>& points, size_t left, size_t right){
//  // parition into 2 parts
  if(left >= right){
    return std::numeric_limits<double>::max();
  }
  size_t mid = floor((left + right) / 2);
  double min_dist_l = minimal_distance_impl(points, left, mid);
  double min_dist_r = minimal_distance_impl(points, mid+1, right);

  double smaller_dist = std::min(min_dist_l, min_dist_r);

  double mid_line = points[mid].m_x;

  double min_dist = std::numeric_limits<double>::max();
  std::vector<Point> points_in_strip;
  for(size_t i = left; i <= right; i++){
    if(std::abs((double)points[i].m_x - mid_line) <= smaller_dist){
      points_in_strip.push_back(points[i]);
    }
  }

  // sort by y decrease
  std::sort(points_in_strip.begin(), points_in_strip.end(), sort_by_y_decrease);

  // find the closes pair among the points in the strip
  size_t num_points_in_strip = points_in_strip.size();
  if(num_points_in_strip >= 2 && num_points_in_strip <= 8){
    for(size_t i = 0;i < num_points_in_strip; i++){
      for(size_t j = i + 1; j < num_points_in_strip; j++){
        Point p_i = points_in_strip[i];
        Point p_j = points_in_strip[j];
        double d = p_i.distanceTo(p_j);
        if(d <= min_dist){
          min_dist = d;
        }
      }
    }

  }else if(num_points_in_strip > 8){
    for(size_t i = 0;i < points_in_strip.size();i++){
      for(size_t j = 1; j <= 7 && i + j < points_in_strip.size(); j++){
        Point p_i = points_in_strip[i];
        Point p_j = points_in_strip[i + j];
        double d = p_i.distanceTo(p_j);
        if(d <= min_dist){
          min_dist = d;
        }
      }
    }
  }


  return std::min(min_dist , smaller_dist);
}

double minimal_distance(std::vector<Point>& points){
  //write your code here
  std::sort(points.begin(), points.end(), sort_by_x);
  double min_dist = minimal_distance_impl(points, 0, points.size() -1);
  return min_dist;
}


double minimal_distance_naive(std::vector<Point>& points){
  double min_dist = std::numeric_limits<double>::max();
  size_t n = points.size();
  for(size_t i = 0;i < n; i++){
    for(size_t j = i + 1;j < n;j++){
      double dist = points[i].distanceTo(points[j]);
      if(dist <= min_dist){
        min_dist = dist;
      }
    }
  }
  return min_dist;
}


void stress_test(size_t num_trials, size_t max_num_points, long long min, long long max){
  std::default_random_engine generator(unsigned(time(0)));
  std::uniform_int_distribution<int> int_generator(2, max_num_points);
  for(size_t tr = 0; tr < num_trials; tr++){
    // create a point set
    int num_points = int_generator(generator);
    std::uniform_int_distribution<int> point_generator(min, max);
    std::vector<Point> points;
    for(size_t i = 0; i < num_points; i++){
      long long x = point_generator(generator);
      long long y = point_generator(generator);
      points.emplace_back(Point(x,y));
    }
    double min_dist_naive = minimal_distance_naive(points);
    double min_dist = minimal_distance(points);

    bool correct = abs(min_dist_naive - min_dist) < 1e-5;
    if(correct){
      std::cout << "!!solution correct!!" << std::endl;
    }else{
      std::cout << "!!! solution incorrect !!! , correct answer: " << min_dist_naive << " , your answer: " << min_dist << " , trial id : " << num_trials << " , input points: " << std::endl;
      std::cout << points.size() << std::endl;
      for(auto & p : points){
        std::cout << p.m_x   << " " << p.m_y << std::endl;
      }
      std::cout << std::endl;
      break;
    }
  }

}












