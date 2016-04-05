/* This is the main file for the BigNum project. THe BigNum project is being designed to use a class called BigNum. The purpose of the is project is to create a program that will handle super large numbers. Larger than a typical int can handle.

Created by James Moore
start date 22, September 2014
Edited on: 
Final file completed: 
CPSC 230A
Davies

*/
#include "BigNum.h" // this the BigNum Class
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
cout << "This program will do cool stuff.... I hope!" << endl;
for(int i = 0; i<1000; i++){
	for(int b=0; b <1000; b++){
//BigNum test
int fourDig = 1234567890;
BigNum number(fourDig);
//BigNum b = -1;
//BigNum *bPtr = new BigNum(5);
cout << number << "This is number" << endl;
BigNum b("962");
BigNum moore("-48");
BigNum phone ("110");
/*
if(moore.isEqualTo(b) == true){
	cout << "they are equal to each other" << endl;
}
if(moore.isEqualTo(b) == false){
	cout << "they are not equal to each other" << endl;
}
if(moore.isGreaterThan(b) == true){
	cout << "they are greaterThan to each other" << endl;
}
if(moore.isGreaterThan(b) == false){
	cout << "they are not greaterThan to each other" << endl;
}
if(moore<b == true){
	cout << "they are lessThan to each other" << endl;
}
if(moore.isLessThan(b) == false){
	cout << "they are not lessThan to each other" << endl;
}
*/
BigNum me("1");
me = b+phone;
cout << "This is me " << me << endl;
cout << "This is moore " << moore << endl;
cout << "This is b " << b << endl;
}
}
}// end main
