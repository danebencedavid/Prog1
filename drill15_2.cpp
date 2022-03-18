#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;


class Person{
	private:
		int age;
		string f_name;
		string l_name;
	public:
		Person(){}
		Person(string f_name, string l_name, int a){
			if (a<0 || a>=150)
				throw runtime_error("Invalid age");
		string n1 = f_name + l_name;	
		for (char k : n1){
			switch (k){
			case ';': case ':': case '"': case '[': case ']': case '*':
            		case '&': case '^': case '%': case '$': case '#': case '@':
            		case '!':
				throw runtime_error("Invalid name");
				break;
			default:
				break;
			}
				
		}
	};
		
		int get_age() const {return age;}
		string get_fname() const {return f_name;}
		string get_lname() const {return l_name;}
		
		
};

ostream& operator<< (ostream& os, const Person& p){
	return os << p.get_fname()<< p.get_lname() <<" " << p.get_age();
}
	
istream& operator>> (istream& is, Person& p){
	string f_name;
	string l_name;
	int age;
	is >> f_name >> l_name >> age;
	
	p = Person{f_name,l_name, age};
	return is;


}	
		
int main(){
	cout << "Enter names and ages, use *end* to terminate ";
	vector<Person> vecp;
	
	for (Person per;cin>>per;)
	{
		if (per.get_fname()=="end") break;
		vecp.push_back(per);
	}
	for (Person p: vecp)
		cout<<p<<endl;
	
	
	return 0;
	}
	
	
	
	

