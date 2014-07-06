
/*all copyright reversed by KenLee@2014*/
#include	<cstdlib>
#include	<cstring>
#include	<cmath>
#include	<iostream>
#include	<string>
#include	<algorithm>
#include	<queue>
#include	<stack>
#include	<fstream>
#include	<sstream>
#include	<boost/property_tree/ptree.hpp>
#include	<boost/property_tree/json_parser.hpp>
using namespace std;

int main (){
	std::ifstream fin("agenda.data");
	if(!fin.good())
		return 3;
	std::string str;
	fin>>str;
		cout<<"str: "<<str<<endl;
	using namespace boost::property_tree;
	ptree pt;
	stringstream ss;
	ss<<str;
	read_json<ptree>(ss,pt);
	string collection = pt.get<string>("collection"); 
	int total = pt.get<int>("total");
	cout<<"collection :"<<collection<<endl;
	cout<<"total :"<<total<<endl;
	return 0;
}
