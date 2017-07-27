#include <cstdio>
#include <iostream>
#include <vector>
using std::vector;
#include <string>
using std::string;
using std::endl;
using std::cout;

string seq;
vector<int> c1;
vector<int> c2;
vector<int> c3;
string A = "A";
string Ainv = "Ainv";
string B = "B";
string Binv = "Binv";
string R = "R";

void a(vector<int>& vec){
	vector<int> tmp;
	while(vec != c1 && vec != c2 && vec != c3) {
		tmp = vec;
		if(vec[0] < 0 && vec[1] > 0) {
			vec[0]=tmp[1];vec[1]=-tmp[0];
			seq.insert(0,R);
		}
		else if(vec[0] < 0 && vec[1] < 0) {
			vec[0]=-tmp[0];vec[1]=-tmp[1];
			seq.insert(0,R);seq.insert(0,R);
		}
		else if(vec[0] > 0 && vec[1] < 0) {
			vec[0]=-tmp[1];vec[1]=tmp[0];
			seq.insert(0,R);seq.insert(0,R);seq.insert(0,R);
		}
		else if(vec[1] > vec[0]) {
			vec[1] = (-2*tmp[0]) + tmp[1];
			seq.insert(0,Binv);
		}
		else {
			vec[0] = (-2*tmp[1]) + tmp[0];
			seq.insert(0,Ainv);
		}
	}
}

int main(int argc, char* argv[]) {
/*	if(argc < 3) {
		std::cerr<<"Expected two integers"<<endl;
		return 1;
	}*/
	c1.push_back(1);c1.push_back(1);
	c2.push_back(1);c2.push_back(0);
	c3.push_back(0);c3.push_back(1);
	vector<int> v;
	int x = atoi(argv[0]);
	int y = atoi(argv[1]);
	v.push_back(x);
	v.push_back(y);
	a(v);
	cout<<"\n"<<seq<<endl;
	cout<<"Final vector is ("<<v[0]<<", "<<v[1]<<")\n";
	return 0;
}
