#include <iostream>
#include <cstdlib>
#include <inttypes.h>
#include "List.h"
using namespace std;

int main(){
	List<double> list(1.3);
	list.add_end(3.12);
	list.add_end(.12);
	list.add_end(5.211);
	cout << list; //порверка переопределенного оператора вывода
	list.reverse();
	cout << list;

	List<int> list2(10);
}


