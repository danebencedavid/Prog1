#include <vector>
#include <list>
#include <iostream>
#include <array>
#include <string>
#include <algorithm>
template <typename C> 
void print_contents(const C& c){
	for (auto& a: c)
		std::cout<< a << ' ';
	std::cout<<std::endl;
}

template <typename C>
void inc(C& c, int n){
	for(auto& a: c)
		a+=n;
}

template<typename Iter1, typename Iter2>
Iter2 ocopy(Iter1 f1, Iter1 e1,Iter2 f2)
	
	{
		for(Iter1 p=f1; p !=e1; ++p)
			*f2++ = *p;
		return f2;
	}
	



int main(){

	
	//std::list<int> lista = {0,1,2,3,4,5,6,7,8,9};	
	//std::vector<int> vect = {0,1,2,3,4,5,6,7,8,9};
	
	constexpr int size=10;
	int arr[size];
	for (int i = 0; i<size; i++) arr[i] = i;
	
	std::array<int,size> ai;
	std::copy(arr, arr + size, ai.begin());
	print_contents(arr);
	
	std::vector<int> vi(size);
	std::copy(arr,arr+ size, vi.begin());	
	print_contents(vi);
	
	std::list<int> li(size);
	std::copy(arr, arr + size, li.begin());
	print_contents(li);
	

	std::array<int, size> ai2 = ai;
	
	std::vector<int> vi2 = vi;
	
	std::list<int> li2 = li;

	inc(ai2,2);
	inc(vi2,3);
	inc(li2,5);
	
	
	
	print_contents(ai2);
	print_contents(vi2);
	print_contents(li2);
	
	
	ocopy(ai2.begin(), ai2.end(), vi2.begin());
	ocopy(li2.begin(), li2.end(), ai2.begin());	
	
	std::vector<int>::iterator vit;
	vit = std::find(vi2.begin(),vi2.end(), 3);
	if (vit != vi2.end()){
		std::cout<< "Found at:" << std::distance(vi2.begin(), vit);
	}
	else
		std::cout<<"Not found" ;
	
	std::list<int>::iterator lit;
    	lit = std::find(li2.begin(), li2.end(), 27);
    	if (lit != li2.end())
        	std::cout << "Found at: " << std::distance(li2.begin(), lit);
   	 else
        	std::cout << "Not found";
	
		
	
	
}
