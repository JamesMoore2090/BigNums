
#ifndef BIGNUM_H
#define BIGNUM_H


#include<iostream>
using namespace std;

class BigNum {

public:

    // Note: You MAY NOT change anything in this public section of the
    // BigNum class. Doing so would mean my code wouldn't work with yours,
    // since we'd be using two different public interfaces!
    

    /**************/
    /**  PART I  **/
    /**************/

    // Default constructor. Invoked (for example) when a user does:
    //   BigNum b;
    // or
    //   BigNum *bPtr = new BigNum;
    BigNum();

    // Integer constructor. Invoked (for example) when a user does:
    //   BigNum b(5);
    // or
    //   BigNum b = 5;
    // or
    //   BigNum *bPtr = new BigNum(5);
    BigNum(int num);

    // Character string constructor. Invoked (for example) when a user does:
    //   BigNum b("1515681747170512879881759");
    // or
    //   BigNum b = "1515681747170512879881759";
    // or
    //   BigNum *bPtr = new BigNum("1515681747170512879881759");
    BigNum(const char string[]);

    // Destructor. Automatically invoked whenever a BigNum goes out of
    // existence.
    ~BigNum();

    // Assignment operator. Invoked when one BigNum is assigned to another:
    //   BigNum x, y;
    //   x = y;
    BigNum& operator=(const BigNum &anotherBigNum);

    // Copy constructor. Automatically invoked when a new BigNum is created
    // based on an existing BigNum (a by-value function call, for instance.)
    BigNum(const BigNum &anotherBigNum);


    // Return true if this BigNum is equal to the argument passed.
    bool isEqualTo(const BigNum &anotherBigNum) const;

    // Return true if this BigNum is less than the argument passed.
    bool isLessThan(const BigNum &anotherBigNum) const;
    // Return true if this BigNum is greater than the argument passed.
    bool isGreaterThan(const BigNum &anotherBigNum) const;

    
    // Return a new BigNum equal to this BigNum plus the argument passed.
    BigNum plus(const BigNum &addend) const;

    // Return a new BigNum equal to this BigNum minus the argument passed.
    BigNum minus(const BigNum &subtractand) const;


    // Print the value of this BigNum to the output stream passed.
    void print(ostream &os) const;



    /***************/
    /**  PART II  **/
    /***************/

    // Return a new BigNum equal to this BigNum plus the argument passed.
    BigNum operator+(const BigNum &addend) const;

    // Add the value of the argument to this BigNum (changing this BigNum's
    // value.)
    BigNum& operator+=(const BigNum &addend);

    // Return a new BigNum equal to this BigNum minus the argument passed.
    BigNum operator-(const BigNum &subtractand) const;

    // Subtract the value of the argument from this BigNum (changing this
    // BigNum's value.)
    BigNum& operator-=(const BigNum &subtractand);

    // Return true if this BigNum is greater than the argument passed.
    bool operator>(const BigNum &anotherBigNum) const;

    // Return true if this BigNum is greater than or equal to the argument
    // passed.
    bool operator>=(const BigNum &anotherBigNum) const;

    // Return true if this BigNum is less than the argument passed.
    bool operator<(const BigNum &anotherBigNum) const;

    // Return true if this BigNum is less than or equal to the argument passed.
    bool operator<=(const BigNum &anotherBigNum) const;

    // Return true if this BigNum is equal to the argument passed.
    bool operator==(const BigNum &anotherBigNum) const;

    // Return true if this BigNum is not equal to the argument passed.
    bool operator!=(const BigNum &anotherBigNum) const;

    // Print the value of the BigNum passed to the output stream passed.
    friend ostream& operator<<(ostream &os, const BigNum &bignum);

    // Read a BigNum in from an input stream. (Stephen is cordially
    // providing the code for this method for you; copy it from 
    // /home/stephen/cpsc230/assignment1/BigNumInputStreamReader.cpp.)
    friend istream& operator>>(istream &is, BigNum& bignum);


    /********************/
    /**  EXTRA CREDIT  **/
    /********************/

    // Return a new BigNum equal to this BigNum times the argument passed.
    BigNum times(const BigNum &multiplicand) const;

    // Return the factorial of this BigNum.
    BigNum factorial() const;

    // Return a new BigNum equal to this BigNum times the argument passed.
    BigNum operator*(const BigNum &multiplicand) const;

    // Multiply the value of the argument by this BigNum (changing this
    // BigNum's value.)
    BigNum& operator*=(const BigNum &multiplicand);



private:

    // Note 1: You MAY change anything below if you would like to implement
    // your BigNums in a different way. The design choices I'm expressing
    // below are merely a recommendation, and one that I know works out to
    // yield some of the simplest and most elegant code. That being said, it's
    // up to you.
    
    // Note 2: It may behoove you to add some private helper methods here.


    // A dynamic array of integers representing the string of decimal
    // digits in the number, stored "backwards" (ie., the "ones' place" is
    // in array index 0, the "tens' place" is in array index 1, the
    // "hundreds' place" is in array index 2, etc.)
    int *digits;

    // The number of decimal digits in this number.
    int numDigits;

    // True if and only if the number is non-negative.
    bool isPositive;

    // helper function for multiplication
    BigNum MultiplyDigits(int number) const;
    // helper function to shift the numbers
    BigNum shift(int spot) const;
};

#endif
