
all: vader testmemleak

clean:
	rm *.o vader testmemleak

vader: vader.o BigNum.o
	g++ -o vader vader.o BigNum.o

vader.o: vader.cpp BigNum.h
	g++ -c vader.cpp

vaderec: vaderec.o BigNum.o
	g++ -o vaderec vaderec.o BigNum.o

vaderec.o: vaderec.cpp BigNum.h
	g++ -c vaderec.cpp

testmemleak: testmemleak.o BigNum.o
	g++ -o testmemleak testmemleak.o BigNum.o

testmemleak.o: testmemleak.cpp BigNum.h
	g++ -c testmemleak.cpp

BigNum.o: BigNum.h BigNum.cpp
	g++ -c BigNum.cpp
