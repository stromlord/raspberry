#include <iostream>
#include "strngbad.h"
using std::cout;

void callme1(StringBad&);
void callme2(StringBad);

int main() {
	using std::endl;
	{
		cout << "Starting an inner block.\n";
		StringBad headline1("Celery Stalks at Midnight");
		StringBad headline2("Lettuce prey");
		StringBad sports("Spinach Leaves Bowl for Dollars");
		cout << "headline1" << headline1 << endl;
		cout << "headline2" << headline2 << endl;
		cout << "sports" << sports << endl;
		callme1(headline1);
		cout << "headline1" << headline1 << endl;
		callme2(headline2);
		cout << "headline2" << headline2 << endl;
		cout << "Initialize one object to another:\n";
		StringBad sailor = sports;
		// StringBad sailor = StringBad(sports);
		cout << "sailor: " << sailor << endl;
		cout << "Assign one object to another:\n";
		StringBad knot;
		knot = headline1;
		cout << "knot: " << knot << endl;
		cout << "Exiting the block.\n";
	}
	cout << "End of main()\n";
}

void callme1(StringBad& rsb) {
	cout << "String passed by reference:";
	cout << "    \n" << rsb << "\"\n";
}

void callme2(StringBad sb) {
	cout << "String passed by value:";
	cout << "    \n" << sb << "\"\n";
}
