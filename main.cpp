#include "vector.h"
#include <iostream>
using namespace std;
using namespace myvector;

int main ()
{
	while (1) {
		vector<int> a;
//		vector<int> a(80);

		vector<int> b = a;
//		vector<double> c = a;

		vector<int> d(8); d = a;
//		vector<float> e(25); e = a;

		cout << a.size() << ' ' << a.memory() << endl;

		for (int i = 0; i < 257; i++) { a[i] = i * 10; cout << a.size() << ' ' << a.memory() << " | "; }
		cout << endl;
		for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
		cout << endl;

		vector<int> f(7); f = a;
//		vector<float> g(9); g = a;

		a.resize(80);
		cout << a.size() << ' ' << a.memory() << endl;

		a.resize(129);
		cout << a.size() << ' ' << a.memory() << endl;
	}

	return 0;
}
