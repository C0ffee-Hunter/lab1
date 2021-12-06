#include <iostream>
#include "List.h"

using namespace std;


int main()
{
	List list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.print();
	cout << list.get_size() << ": size" << endl;

	list.push_front(2384);
	list.remove(2);
	cout << "remove #2" << endl;
	list.print();
	list.clear();
	cout << "clear" << endl;
	list.print();

    return 0;
}