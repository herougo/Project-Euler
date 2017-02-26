#include <iostream>
#include <string>

using namespace std;

unsigned short to16BitUnsigned(int n) {
	cerr << "    short: " << n << endl;
	return (unsigned short) n;
}


void printBinary(unsigned int n) {
	for (int i = 31; i >= 0; i--) {
		/*if ((1 << i) && n) {
			cerr << 1;
		} else {cerr << 0;}*/
		cerr << ((n >> i) & 1);
	}
	cerr << endl;
}

void yo (int n) {
	printBinary(to16BitUnsigned(n));
}

int main() {

	/*
	0 -> 0
	1 -> 01
	-1 -> 111...1111
	0xffff -> 0111...111
	-0x10000 -> 100..000
	*/
yo(-1);
yo(0);
yo(1);
yo(0xffff);
yo(-0x10000);
int n;
cin >> n; 
}