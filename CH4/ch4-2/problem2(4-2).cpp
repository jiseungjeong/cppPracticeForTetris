#include <iostream>
#include <math.h>

class Point {
  int x, y;

public:
  Point(int pos_x, int pos_y) {
    x = pos_x;
    y = pos_y;
  }
  int GetX() const { return x; }
  int GetY() const { return y; }
};

class Geometry {
public:
  Geometry() { num_points = 0; }

  void AddPoint(const Point &point) {
    point_array[num_points++] = new Point(point.GetX(), point.GetY());
  }

  void PrintDistance();
  void PrintNumMeets();
  int NumDotsInDiffSpace(Point dot1, Point dot2);
private:
  Point *point_array[100];
  int num_points;
};

double CalDistance(Point dot1, Point dot2) {
  int del_x = dot1.GetX() - dot2.GetX();
  int del_y = dot1.GetY() - dot2.GetY();
  double distance = sqrt(del_x * del_x + del_y * del_y);
  return distance;
}

int LineFunc(Point line_dot1, Point line_dot2, Point main_dot) {
  int a = line_dot1.GetX() - line_dot2.GetX();
  int b = line_dot1.GetY() - line_dot2.GetY();
  int c = -(a*line_dot1.GetX())-(b*line_dot2.GetY());
  return a*main_dot.GetX()+b*main_dot.GetY()+c;
}

void Geometry::PrintDistance() {
  for (int i = 0; i < num_points; i++) {
    for (int j = i + 1; j < num_points; j++) {
      std::cout << i + 1 << "번째 점과 " << j + 1 << "번째 점 사이의 거리는 "
                << CalDistance(*point_array[i], *point_array[j]) << "입니다."
                << std::endl;
    }
  }
}

void Geometry::PrintNumMeets() {
    int cnt=num_points;
    if (num_points<=3) {
        return;
    }
    for (int i=0; i<num_points-3;i++) {
        for (int j=i+1; j<num_points-2;j++) {
            for(int k=j+1; k<num_points-1;k++){
                for (int l=k+1;l<num_points;l++){
                    if(LineFunc(*point_array[i], *point_array[j],*point_array[k])*LineFunc(*point_array[i], *point_array[j], *point_array[l])<=0){
                        cnt++;
                    }
                }
            }
        }
    }
    std::cout<<"모든 점들을 잇는 직선들 간의 교점은 "<<cnt<<"개입니다."<<std::endl;
}

int main() {
  Geometry geometry;
  Point point1(0, 0);
  Point point2(3, 0);
  Point point3(0, 4);
  Point point4(3, 4);


  geometry.AddPoint(point1);
  geometry.AddPoint(point2);
  geometry.AddPoint(point3);
  geometry.AddPoint(point4);

  geometry.PrintDistance();
  geometry.PrintNumMeets();
  return 0;
}