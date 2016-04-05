/* BigNum.cpp 
	This is the implementation cpp for the BigNum Class.
James Moore
CPSC 230A
First created September 22, 2014
Final edit October 25,2014
Davies

*/
#include <sstream>
#include "BigNum.h"
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

//basic constructor
BigNum::BigNum(){
	digits = new int[1];
	numDigits= 1;
	*digits = 0;		
	isPositive = true;
}

// int constructor
BigNum::BigNum(int b){
	// must handle  0
	if(b == 0){
		numDigits =1;
		digits = new int[1];
		digits[0] = 0;
		isPositive = true;
		return;
	}// endif

	int temp[50]; // statically allocated arry size
	if(b>=0){
		isPositive = true;
	} // end if
	else{
		isPositive= false;
		b = -b;
	}

	int spot = 0; // this will be used when putting digits in the array
	while(b > 0){
		temp[spot++] = b % 10;
		b /=10;
	}
	digits = new int[spot];
	for(int p=0; p < spot; ++p){
		digits[p] = temp[p];
	}
	numDigits = spot;

}// end int constructor

// char string constructor
BigNum::BigNum(const char string[]){
	if(string[0] == '+'){
		isPositive = true;
		string++;
	} // end if
	else if(string[0] == '-'){
		isPositive = false;
		string++;
	}
	else{
		isPositive = true;
	}
	// phewwwww that takes care of the ispositive variable. if it is negutive make it false.
	// if it is postitive make it true. otherwise make it true.
	
	// find the length them allocate memory for it
	numDigits = strlen(string);
	// make the new array
	digits = new int[numDigits];
	// put the numbers in the array
	for(int j = 0; j < numDigits; ++j){
		digits[numDigits-j-1] = string[j] - '0';
	} // end for
} // this now ends the char constructor


//Destructor
BigNum::~BigNum(){
	delete [] digits;
}

BigNum & BigNum::operator=(const BigNum &anotherBigNum){
	if(this == &anotherBigNum){
		return *this;
	}	
	delete [] digits;
	numDigits = anotherBigNum.numDigits;
	digits = new int[numDigits];
	isPositive = anotherBigNum.isPositive;
	for( int i = 0;i < numDigits; ++i){
		digits[i]=anotherBigNum.digits[i];
	}
	return *this;
}

//copy constructor
BigNum::BigNum(const BigNum &anotherBigNum){
	digits=NULL;
	*this=anotherBigNum;
}

//return true if tis BigNum is equal to the argument passed
bool BigNum::isEqualTo(const BigNum &anotherBigNum) const{
	if(numDigits != anotherBigNum.numDigits){
		return false;
	}
	if(isPositive != anotherBigNum.isPositive){
		return false;
	}
	
	for(int i=0; i<numDigits; ++i){
		if(digits[i] != anotherBigNum.digits[i]){
			return false;
		}
	}
	return true;
}// end isEqualTo

// Return true if this BigNum is less than the argument passed
bool BigNum::isLessThan(const BigNum &anotherBigNum) const{
	return (!(*this == anotherBigNum)) && (!(*this > anotherBigNum));

}// end member function
   
// Return true if this BigNum is greater than the argument passed.
bool BigNum::isGreaterThan(const BigNum &anotherBigNum) const{
	if(isPositive && !anotherBigNum.isPositive){
		return true;
	}
	if(!isPositive && anotherBigNum.isPositive){
		return false;
	}	
	
	if(!isPositive && !anotherBigNum.isPositive){
		BigNum newCopy1 = *this;
		BigNum newCopy2 = anotherBigNum;
		newCopy1.isPositive = true;
		newCopy2.isPositive = true;
		return !(newCopy1 >= newCopy2);
	} // end if
	// now check the digits length
	if(numDigits > anotherBigNum.numDigits){
		return true;
	}
	if(numDigits < anotherBigNum.numDigits){
		return false;
	}
	// check each digit 	
	for(int i = numDigits; i >= 0; --i){
		if(digits[i] > anotherBigNum.digits[i]){
			return true;
		} // end if
		if(digits[i] < anotherBigNum.digits[i]){
			return false;
		}
	}// end for
	return false;
}

// Return a new BigNum equal to this BigNum plus the argument passed.
BigNum BigNum::plus(const BigNum &addend) const{
	// if the signs are different then subtract
	if(isPositive && !addend.isPositive){
		BigNum addendAbsVal = addend;
		addendAbsVal.isPositive = true;
		return *this - addendAbsVal;
	}// end if 
	if(!isPositive && addend.isPositive){
		BigNum absVal1 = *this;
		BigNum absVal2 =addend;
		absVal1.isPositive = true;
		absVal2.isPositive = true;
		return absVal2 - absVal1;
	}// end if
	BigNum answer;
	answer.isPositive = isPositive;
	// figure which has more digits and then make a new array +1 
	// just incase you have to carry
	int newNumSize;
	if(numDigits > addend.numDigits){
		newNumSize = numDigits +1;
	}
	else {	
		newNumSize = addend.numDigits +1;
	}
	delete [] answer.digits;
	answer.digits = new int[newNumSize];
	// now we have the right size array. we can start  the MATH...!!!
	
	int carry=0;
	for(int i=0; i < newNumSize; ++i){
		int x = numDigits > i ? digits[i] : 0;
		int y = addend.numDigits > i ? addend.digits[i] : 0;
		int sum = x + y + carry;
		answer.digits[i] = sum % 10;
		carry = sum/10;
	}

	if(answer.digits[newNumSize - 1] == 0){
		answer.numDigits = newNumSize -1;
	}
	else{
		answer.numDigits = newNumSize;
	}
	
	return answer;

} // end plus function

// Return a new BigNum equal to this BigNum minus the argument passed.
BigNum BigNum::minus(const BigNum &subtractand) const{
	// lets look at the signs just like the adding
	
	// positive number - negitive number
	if(isPositive && !subtractand.isPositive){
		BigNum subtractandAbsVal = subtractand;
		subtractandAbsVal.isPositive = true;
		return *this + subtractandAbsVal;
	}// end if
	
	// negitive number - positive number
	if(!isPositive && subtractand.isPositive){
		BigNum absVal = *this;
		absVal.isPositive = true;
		absVal += subtractand;
		absVal.isPositive = false;
		return absVal;
	}// end if
	
	// negitive number - negative number
	if(!isPositive){
		BigNum answer = subtractand;
		answer.isPositive = true;
		return answer + *this;
	}// end if

	//subtract the lesser from the greater
	if(*this < subtractand){
		BigNum answer = subtractand;
		answer -= *this;
		answer.isPositive = !answer.isPositive;
		return answer;
	}
	BigNum answer;
	delete [] answer.digits;
	answer.digits = new int[numDigits];
	// now it is time to do math... BLAH
	int barrow = 0;
	for(int i=0; i< numDigits; ++i){
		int x = i >= numDigits ? 0 : digits[i];
		int y = i >= subtractand.numDigits ? 0 :subtractand.digits[i];
		x -= barrow;
	
		if(x>=y){
			answer.digits[i] = x-y;
			barrow = 0;
		}// end if
		else{
			answer.digits[i] = x-y+10;
			barrow = 1;
		}// end else

	}// end for
	// remove the leading zeroos off
	int newNumDigits = numDigits;
	int  i = numDigits -1;
	while(i > 0 && answer.digits[i] == 0){
		i--;
		newNumDigits--;
	}// end while

	answer.numDigits = newNumDigits;
	return answer;	
	
}// end minus

// Print the value of this BigNum to the output stream passed.
void BigNum::print(ostream &os) const{
	if(!isPositive){
		os << "-";
	}
	for(int a = numDigits-1; a >=0; --a){
		os << (int) digits[a];
	}
}





/* Hello there, folks; this input stream reader operator is kind of a pain
 * in the butt, so I'm just going to give you the code for it. Copy and
 * paste this code into your own BigNum.cpp file. */

//  Read a BigNum in from an input stream.
istream& operator>>(istream &is, BigNum& bignum) {

    //  Make sure the next character in the stream is a valid start to
    //  a BigNum; otherwise, throw an exception.
    char next = is.peek();
    while (isspace(next)) {
      is.get();
      next = is.peek();
    }
    if (!isdigit(next) && next != '+' && next != '-') {
        throw "No BigNum to read!!";
    }

    //  Read the sign character, if there is one.
    bignum.isPositive = true;
    if (next == '-') {
        is.get();
        bignum.isPositive = false;
    }
    if (next == '+') {
        is.get();
    }

    //  Read all consecutive digits into an array called "backwardsDigits,"
    //  resizing this array if necessary to accommodate all the input.
    //  (The array is called "backwards" because I'm storing the digits
    //  of the BigNum with the least significant digit in digits[0],
    //  and of course as we read the input from left to right, the most
    //  significant digit of backwardsDigits will instead be [0].)
    int capacity = 10;
    int *backwardsDigits = new int[capacity];
    int numDigits = 0;
    while (isdigit(is.peek())) {
        if (numDigits >= capacity) {
            //  Oops, our backwardsDigits array isn't big enough
            //  to handle all the digits in the BigNum the user
            //  typed in.  Double our capacity, and copy the
            //  existing digits into the new array.
            capacity *= 2;
            int *temp = new int[capacity];
            for (int i=0; i<(capacity/2); ++i) {
                temp[i] = backwardsDigits[i];
            }
            delete [] backwardsDigits;
            backwardsDigits = temp;
        }
        backwardsDigits[numDigits] = is.get() - '0';
        numDigits++;
    }

    //  Now all the digits that will represent this new BigNum are in the
    //  backwardsDigits array, stored in reverse order from how we want
    //  them stored in our BigNum.  Delete the old BigNum memory, and
    //  copy the digits into it.
    delete [] bignum.digits;
    bignum.digits = new int[numDigits];
    for (int i=0; i<numDigits; ++i) {
        bignum.digits[i] = backwardsDigits[numDigits-i-1];
    }
    bignum.numDigits = numDigits;

    //  Cool.  Now we have a new BigNum.  Delete this temporary memory we
    //  used, and return.
    delete [] backwardsDigits;
    return is;
}

BigNum BigNum::times(const BigNum &multiplicand) const{
	//I need something to hold the product
	BigNum answer;
	//do the math!!!
	for(int P=0; P<multiplicand.numDigits; ++P){
		answer+= MultiplyDigits(multiplicand.digits[P]).shift(P);
	}// end for math done!!!!
	// What sign do I use???
	if(isPositive && multiplicand.isPositive || !isPositive && !multiplicand.isPositive){
		answer.isPositive = true;
	}// end if
	else{
		answer.isPositive = false;
	}
	return answer;


}// end times member function

BigNum BigNum::operator+(const BigNum &addend) const{
	BigNum added;
	added=this->plus(addend);
	return added;
}

BigNum & BigNum::operator+=(const BigNum &addend) {
	*this=*this+addend;
	return *this;
		
}

BigNum BigNum::operator-(const BigNum &subtractand) const{
	return this->minus(subtractand);
}

BigNum & BigNum::operator-=(const BigNum &subtractand) {
	*this=*this - subtractand;
	return *this;
}

bool BigNum::operator>(const BigNum &anotherBigNum) const{
	return this->isGreaterThan(anotherBigNum);
}

bool BigNum::operator>=(const BigNum &anotherBigNum) const{
	if(this->isGreaterThan(anotherBigNum) == true || this->isEqualTo(anotherBigNum) == true){
	return true;
	}
	else return false;
}

BigNum BigNum::operator *(const BigNum &multiplicand) const{
	return this->times(multiplicand);
}

BigNum& BigNum::operator*=(const BigNum &multiplicand){
	*this = *this * multiplicand;
	return *this;
}

bool BigNum::operator<(const BigNum &anotherBigNum) const{
	return this->isLessThan(anotherBigNum);
}


bool BigNum::operator<=(const BigNum &anotherBigNum) const{
	if(this->isLessThan(anotherBigNum) == true || this->isEqualTo(anotherBigNum) == true){
	return true;
	}
	else return false;
}

bool BigNum::operator==(const BigNum &anotherBigNum) const{
	return this->isEqualTo(anotherBigNum);
}

bool BigNum::operator!=(const BigNum &anotherBigNum) const{
	return !(*this == anotherBigNum);
}

ostream& operator<<(ostream &os, const BigNum &bignum){
	bignum.print(os);
	return os;
}

// this is a helper function for multiplication
BigNum BigNum::MultiplyDigits(int number) const{
	// need a place to store the product? Make one!
	BigNum multAnswer;
	// gonna need more memory so throw out the old get ready for the
	//NEW!!!!
	delete [] multAnswer.digits;
	
	//ooohhh no.... no memory... Lets create some!!!
	multAnswer.digits = new int[numDigits+1];
	for(int J=0; J <numDigits+1; ++J){
		multAnswer.digits[J] =0;
	}// end for
	// Time for more math.....
	int carry=0;
	for(int i=0; i < numDigits+1; ++i){
		int currDigit;
		// lets not run off the end of the array
		if(i<numDigits){
			currDigit = digits[i];
		}// end if
		else{
			currDigit =0;
		}
		int product = number * currDigit;
		multAnswer.digits[i] = (product + carry) % 10;
		carry =(product + carry)/10;
	}// end for

	if(multAnswer.digits[numDigits] == 0){
		multAnswer.numDigits = numDigits;
	}
	else{
		multAnswer.numDigits = numDigits +1;
	}	

	return multAnswer;
}// end MultiplyDigits Hellper function

//Helper function called shift
BigNum BigNum::shift(int spot) const{
	BigNum shiftAnswer;
	shiftAnswer.numDigits = numDigits + spot;
	delete [] shiftAnswer.digits;
	shiftAnswer.digits = new int[shiftAnswer.numDigits];
	for(int w=0; w<spot; ++w){
		shiftAnswer.digits[w] = 0;
	}// end for
	for(int t = spot; t <shiftAnswer.numDigits; ++t){
		shiftAnswer.digits[t] = digits[t-spot];
	}//end for
	return shiftAnswer;
}// end helper


