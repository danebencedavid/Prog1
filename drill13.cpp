#include "Simple_window.h"
#include "Graph.h"
//g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13   `fltk-config --ldflags --use-images`

#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){

	try{

	Point t1 (30, 50);
	Simple_window win(t1,1000,800, "My window");
	win.wait_for_button();


	Lines grid;
	int x_size = 800;
	int y_size = 800;
	for (int i=100; i<x_size; i+=100){
		grid.add(Point{i,0},{i,y_size});
		grid.add(Point{0,i},{x_size,i});

	}

	win.attach(grid);
	win.wait_for_button();

	//for (int i=0;i<8;i++){
		//Rectangle r1 {Point{i*100,i*100},100,100};
		//r1.set_fill_color(Color::red);
		//win.attach(r1);
		//win.wait_for_button();
	//}

	Vector_ref<Rectangle> kitoltes;
	for (int i=0; i<x_size; i=i+100){
	kitoltes.push_back(new Rectangle{Point{i,i},Point{i+100,i+100}});
	kitoltes[kitoltes.size()-1].set_fill_color(Color::red);
	win.attach(kitoltes[kitoltes.size()-1]);
	}

	win.wait_for_button();

	Image img1 {Point{200,0},"badge.jpg"};
	Image img2 {Point{400,200},"images.jpeg"};
	Image img3 {Point{0,200},"badge.jpg"};

	img1.set_mask({200,0},200,200);
	img3.set_mask({0,200},200,200);
	win.attach(img1);
	win.attach(img2);
	win.attach(img3);
	win.wait_for_button();

	Image img4 {Point{0,0},"badge.jpg"};
	img4.set_mask({200,0},200,200);
	win.attach(img4);
	win.wait_for_button();

	Image img5 {Point{0,0},"badge.jpg"};
	img5.set_mask({100,0},100,100);
	win.attach(img5);
	win.wait_for_button();



	for (int i = 0; i<8; i++){
		for (int j = 0; j<7; j++ ){
			img5.move(100, 0);
            		win.wait_for_button();
		}
		 img5.move(-700, 100);
        	win.wait_for_button();
	}


	}catch(exception& e) {
	cerr<<"exception: "<<e.what()<<'\n';
	return 1;


	}catch(...) {
	cerr<<"error\n";
	return 2;
	}

}
