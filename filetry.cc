#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int main(){
	ifstream input("input.txt");
	int a;
	double b;
	input >> a >> b;
	cout << setfill('0') << setw(10) << a << endl << setw(10) << b;
	input.close();
	ofstream out("input.txt");
	out << a << endl << b;
	out.close();
	return 0;
}
