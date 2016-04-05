
/*
 * "I find your lack of faith disturbing."   - Darth Vader
 *
 * Welcome to the BigNum memory leak tester program.
 *
 * To test, run "top" in a different window. Then run this program. Look at
 * top and ensure that the memory usage doesn't get above 0.0% or so. Press
 * ENTER when prompted. Continue to monitor it. If the memory usage never gets
 * above 0.0% or so, congratulations, you have earned 20 points.
 *
 * Note: this file does not test multiplication or factorial. I got tired.
 *
 * - Stephen
 */

#include"BigNum.h"
#include<iostream>
#include<cstring>
using namespace std;

const long NUM = 5000000;

int foo(BigNum x) {
	BigNum z;
	x = z;
}

main()
{
	char dummy[80];
	cout << "instantiating:" << endl;
	for (long i=0; i<NUM; ++i) {
        if (i%10000 == 0) {
            cout << i << "..." << endl;
        }
		BigNum x("1234");
	}
    cout << "(Press ENTER.)" << endl;
	cin.get();
	cout << "adding:" << endl;
	for (long i=0; i<NUM; ++i) {
        if (i%10000 == 0) {
            cout << i << "..." << endl;
        }
		BigNum x("12341748172489759817289457192873891748917248971289");
		BigNum y("4567172847125871897489127387128937189274897189247198");
		BigNum z1 = x.plus(y);
	}
    cout << "(Press ENTER.)" << endl;
	cin.get();
	cout << "subtracting:" << endl;
	for (long i=0; i<NUM; ++i) {
        if (i%10000 == 0) {
            cout << i << "..." << endl;
        }
		BigNum x("12341748172489759817289457192873891748917248971289");
		BigNum y("4567172847125871897489127387128937189274897189247198");
		BigNum z1 = x.minus(y);
	}
    cout << "(Press ENTER.)" << endl;
	cin.get();
	cout << "copying:" << endl;
	for (long i=0; i<NUM; ++i) {
        if (i%10000 == 0) {
            cout << i << "..." << endl;
        }
		BigNum x("12341847556174718273801798571082561892738718568912797");
		foo(x);
	}
    cout << "(Press ENTER.)" << endl;
	cin.get();
}


