#include "Simple_window.h"
#include "Graph.h"
//g++ drill15_1.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill15_1  `fltk-config --ldflags --use-images`

#include <string>
#include <iostream>
using namespace Graph_lib;

double one(double x) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x) {return cos(x)+slope(x);}




int main(){

try{

Point p1 (0,0);
Simple_window window(p1,600,600, "Function Graphs");


Axis x {Axis::x, Point{100,300},400,20,"1==20pixels"};
window.attach(x);
Axis y {Axis::y, Point{300,500},400,20,"1==20pixels"};
window.attach(y);

x.set_color(Color::red);
y.set_color(Color::red);

constexpr int range_min = -10;
constexpr int range_max = 10;
constexpr int n_points = 400;

Point p2 {300,300};
constexpr int x_scale = 20;
constexpr int y_scale = 20;

Function func1{one,range_min,range_max,p2,n_points,x_scale,y_scale};
Function func2{slope,range_min,range_max,p2,n_points,x_scale,y_scale};
Function func3{square,range_min,range_max,p2,n_points,x_scale,y_scale};
Function func4{cos,range_min,range_max,p2,n_points,x_scale,y_scale};
	func4.set_color(Color::blue);
Function func5 {sloping_cos,range_min,range_max,p2,n_points,x_scale,y_scale};


window.attach(func1);
window.attach(func2);
window.attach(func3);
window.attach(func4);
window.attach(func5);







window.wait_for_button();

}catch(exception& e) {
cerr<<"exception: "<<e.what()<<'\n';
return 1;


}catch(...) {
cerr<<"error\n";
return 2;
}




}
