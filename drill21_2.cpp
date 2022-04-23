#include<iostream>
#include<string>
#include<map>
#include<numeric>
#include<stdexcept>

void read(std::map<std::string, int>& m)
{
    std::string s;
    int i = 0;

    while (m.size() < 10){
        std::cin >> s >> i;
        m.insert(std::make_pair(s,i));
    }
}




template<typename K, typename V>
void print(const std::map<K,V>& m)
{

    for(std::pair<K,V>a: m)
    {
        std::cout << a.first << '\t' << a.second << std::endl;

    }

}
template<typename K, typename V>
void sum (const std::map<K,V>& m){int osszeg;
for (std::pair<K,V> a : m)
{
    osszeg = osszeg + a.second;
}
    std::cout << "Osszeg: "<< osszeg << std::endl;
}

int main()

try{
    std::map<std::string,int> msi;

    msi["a"]=1;
    msi["b"]=2;
    msi["c"]=4;
    msi["d"]=44;
    msi["e"]=31;
    msi["f"]=86;
    msi["g"]=57;
    msi["h"]=53;
    msi["i"]=73;
    msi["j"]=33;

    print (msi);
    sum(msi);

    std::cout << "Elements of map after erase: \n" << std::endl;

    msi.erase(msi.begin(),msi.end());

    print (msi);

    std::cout << "Enter 10 pairs: \n" << std::endl;
    read(msi);

    print(msi);

    std::map<int, std::string> mis;
    for(auto a : msi)
	{
		mis[a.second]=a.first;
	}
	std::cout<<std::endl<<"mis map: "<<std::endl;
	print(mis);


}
catch (std::exception& e)
{
	std::cerr<<"Exception: "<<e.what()<<'\n';
	return 1;
}
catch(...)
{
	std::cerr<<"Exception"<<'\n';
	return 2;
}

