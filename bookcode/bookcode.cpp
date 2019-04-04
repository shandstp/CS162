#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	
	string s1("Washington");
	string s2("California");
	cout << "The first character in s1 is " << s1[0] << endl;
	cout << "s1 + s2 is " << (s1 + s2) << endl;
	cout << "s1 < s2? " << (s1 < s2) << endl;

	vector<int> v;
	v.push_back(3);
	v.push_back(5);
	cout << "The first element in v is " << v[0] << endl;
}
