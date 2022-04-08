#include <iostream>
#include <stdexcept>
#include <set>
#include <vector>
#include <fstream>
#include <list>
#include <algorithm>
#include <numeric>
struct Item {
	std::string name;
	int iid;
	double value;

	Item(const std::string& n, int i = 0, double v = 0.0): name{n}, 
	iid{i},value{v} {}

};

struct csokkeno {
	bool operator() (const Item& a, const Item& b){
		return a.value > b.value;
	}
};
class nev {
    std::string name;
public:
    nev(const std::string& nn) : name{nn} { }
    bool operator()(const Item& a) const { return a.name == name; }
};

class id {
    int iid;
public:
    id(const int& ii) : iid{ii} { }
    bool operator()(const Item& a) const { return a.iid == iid; }
};



/*struct ptr_cmp{
	bool operator()(const Item* a, const Item* b){
		return a->name < b->name;
		//return a->quantity < b->quantity;
	}
};
*/

int main()
try{
	//const std::string iname {"input.txt"};

	//std::ifstream ifs {iname};
    	//if (!ifs) throw std::runtime_error("Could not read from file: " + iname);

	//std::vector<Item> vi;
	//for (Item i ; ifs >> i;)  //hibat dob
		//vi.push_back(i);
	
	std::vector<Item> vi {
	Item("house",18,20.13),
	Item("car",3,222.23),
	Item("mouse",87,101.01),
	Item("truck",543,22.26),
	Item("window",76,17.86),
	Item("fork",32,33.33),
	Item("spoon",76,89.76),
	Item("sword",42,76.54),
	Item("star",44,54.32),
	Item("bell",111,22.11)
	};
	
	std::cout<< "Vector values:" <<std::endl;
	for (auto& i : vi){
		std::cout<< i.name << std::endl;
	}
	std::cout<<std::endl;
	
	std::sort(vi.begin(),vi.end(),[](const Item& a, const Item& b) { return a.name < b.name; });
	
	std::cout<< "Sorted vector values by name:" <<std::endl;
	for (auto& i : vi){
		std::cout<< i.name << std::endl;
	}
	std::cout<<std::endl;
	
	std::sort(vi.begin(),vi.end(),[](const Item& a, const Item& b) { return a.iid < b.iid; });
	
	std::cout<< "Sorted vector values by iid:" <<std::endl;
	for (auto& i : vi){
		std::cout<< i.iid << std::endl;
	}
	std::cout<<std::endl;
	
	std::sort(vi.begin(),vi.end(),csokkeno());
	
	std::cout<< "Sorted vector values by value (desc):" <<std::endl;
	for (auto& i : vi){
		std::cout<< i.value << std::endl;
	}
	std::cout<<std::endl;
	
	Item it1 {"horse shoe", 99, 1.32};
	Item it2 {"Canon S400", 9988, 499.95};
	
	vi.insert(vi.begin(),it1);
	vi.insert(vi.begin(),it2);
	
	std::cout<< " Vector values and added values:" <<std::endl;
	for (auto& i : vi){
		std::cout<< i.name << std::endl;
	}
	std::cout<<std::endl;
	
	vi.erase(std::find_if(vi.begin(),vi.end(),nev("star")));
	vi.erase(std::find_if(vi.begin(),vi.end(),nev("spoon")));
	
	std::cout<< " Vector values and without erased values:" <<std::endl;
	for (auto& i : vi){
		std::cout<< i.name << std::endl;
	}
	std::cout<<std::endl;
	
	vi.erase(std::find_if(vi.begin(),vi.end(),id(111)));
	vi.erase(std::find_if(vi.begin(),vi.end(),id(18)));
	
	std::cout<< " Vector values and without erased values:" <<std::endl;
	for (auto& i : vi){
		std::cout<< i.iid << std::endl;
	}
	std::cout<<std::endl;
	
	
	

	
} catch (std::exception& e){
	std::cerr<< e.what() << '\n';
	return 1;
} catch (...){
	std::cerr<< "Unknown exception\n";
}
