#include "Simple_window.h"
#include "Graph.h"
//g++ drill12.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill12   `fltk-config --ldflags --use-images`

#include <string>
#include <iostream>





using namespace Graph_lib;

int main(){

	try{
	
	Point t1 {100,100};
	Simple_window win{t1,600,400,"My window for the drill"};
	
	win.wait_for_button();
	
	Axis xa {Axis::x, Point{40,300},280,12,"x axis"};
	win.attach(xa);
	
	win.set_label("X axis");
	win.wait_for_button();
	
	Axis ya {Axis::y, Point{40,300},280,12,"y axis"};
	ya.set_color(Color::dark_red);
	ya.label.set_color(Color::cyan);
	win.attach(ya);
	
	win.set_label("Y axis");
	win.wait_for_button();
	
	Function sine {sin, 0, 100, Point{40, 150},1000, 50, 50};
	win.attach(sine);
	win.set_label("Sine function");
	win.wait_for_button();
	
	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	
	poly.set_color(Color::blue);
	poly.set_style(Line_style::solid);
	win.attach(poly);
	
	win.set_label("Polygon");
	win.wait_for_button();
	
	Rectangle r {Point{200,200},100,50};
	win.attach(r);
	win.set_label("Rectangle for the drill");
	win.wait_for_button();
	
	Closed_polyline poly_rect;
	
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	poly_rect.add(Point{50,75});
	win.attach(poly_rect);
	
	win.set_label("Rectangle");
	win.wait_for_button();
	
	r.set_fill_color(Color::blue);
	poly.set_style(Line_style(Line_style::solid,2));
	poly_rect.set_fill_color(Color::yellow);
	
	win.set_label("Fill");
	win.wait_for_button();
	
	Text t {Point{150,150}, "Hello, graphical world!"};
	win.attach(t);
	win.set_label("Text");
	win.wait_for_button();
	
	t.set_font(Font::helvetica);
	t.set_font_size(22);
	win.set_label("Text changes");
	win.wait_for_button();
	
	Image img {Point(100,50),"image.jpeg"};
	win.attach(img);
	win.set_label("My image");
	win.wait_for_button();
	
	img.move(100,200);
	win.set_label("image changes");
	win.wait_for_button();
	
	
	Circle kor{Point(100,200),50};
	Ellipse elipsz {Point(100,200),75,25};
	elipsz.set_color(Color::yellow);
	Mark m {Point(100,200),'x'};
	win.attach(kor);
	win.attach(elipsz);
	win.attach(m);
	win.set_label("More");
	
	ostringstream oss;
	oss<<"screen size:" << x_max()<<"*"<< y_max() <<" ;window size:" << 		 win.x_max()<<"*"<<win.y_max();
	Text sizes {Point(100,20),oss.str()};
	win.attach(sizes);
	
	Image cal {Point(225,225),"gif.gif"};
	cal.set_mask(Point(40,40),200,150);
	win.attach(cal);
	win.wait_for_button();
	
			
	}catch(exception& e) {
	cerr<<"exception: "<<e.what()<<'\n';
	return 1;
	
	
	}catch(...) {
	cerr<<"error\n";
	return 2;
	}

}
