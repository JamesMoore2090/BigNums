/*
 * "Perhaps I can find new ways to motivate them."   - Darth Vader
 *
 * Welcome to the Darth Vader BigNum tester program. 
 *
 * It awards a maximum 80 points, or 100 points if you did the extra credit. 
 * The other 20 points for the assignment will be awarded by having no memory
 * leaks as detected by the testmemleak program.
 *
 * Note: If you did the extra credit, search this file for the all-caps 
 * words "EXTRA CREDIT" and follow instructions. (The default file assumes
 * you did *not* do the extra credit, and hence will max out at 80 points.)
 *
 * - Stephen
 */

#include"BigNum.h"
#include<iostream>
#include<sstream>
#include<cstring>
#include<cstdlib>

using namespace std;

bool printsCorrectly(BigNum &b, string output, int testnum);
int testConstructors();
int testComparisons();
int testPlusMinus();
int testTimes();
int testFactorial();
int testDefaultConst(int testnum);
int testCharArrayConst(string number, int testnum);
int testIntConst(string number, int testnum);
bool correctlyGreaterThan(BigNum &a, BigNum &b, bool useOp, int testnum);
bool correctlyLessThan(BigNum &a, BigNum &b, bool useOp, int testnum);
bool correctlyEqualTo(BigNum &a, BigNum &b, bool useOp, int testnum);
bool correctlyAdds(BigNum &a, BigNum &b, BigNum &c, bool useOp, int testnum);
bool correctlySubtracts(BigNum &a, BigNum &b, BigNum &c, bool useOp, 
    int testnum);
bool correctlyMultiplies(BigNum &a, BigNum &b, BigNum &c, bool useOp, 
    int testnum);
bool correctlyComputesFactorial(BigNum &a, BigNum &b, int testnum);
bool correctTimesEquals(BigNum &num1, BigNum &num2, BigNum &product, 
    int testnum);
int testCopyConst(BigNum x, string y, int testnum);

main()
{
    int totalScore = 0;

	totalScore += testConstructors();
	totalScore += testComparisons();
	totalScore += testPlusMinus();
	totalScore += testTimes();
	totalScore += testFactorial();

	cout << "Your total score: " << totalScore << endl;
    cout << "(Maximum 80 pts unless extra credit is enabled; see vader.cpp for details.)"
       << endl;
}

int testConstructors() {
	int totalScore = 0;

	totalScore += testDefaultConst(1);
	totalScore += testIntConst("37",2);
	totalScore += testIntConst("-37",3);
	totalScore += testIntConst("9",4);
	totalScore += testIntConst("-9",5);
	totalScore += testIntConst("0",6);
	totalScore += testIntConst("1827374",7);
	totalScore += testIntConst("-1827374",8);
	totalScore += testCharArrayConst("37",9);
	totalScore += testCharArrayConst("-37",10);
	totalScore += testCharArrayConst("9",11);
	totalScore += testCharArrayConst("-9",12);
	totalScore += testCharArrayConst("0",13);
	totalScore += testCharArrayConst("1827374",14);
	totalScore += testCharArrayConst("-1827374",15);
	totalScore += testCharArrayConst("-18273168648172091823748172865812364817204702197401820356182365812348127857132874126859612098471927481278561829571892774",16);
	totalScore += testCharArrayConst("-754872089463986389718974896289569827149263598162893451289618927345891237581689234718927389561892375",17);
	totalScore += testCharArrayConst("-99999999999999999999999999999999999999999999999999991919191919191991919199999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999",18);

	BigNum x("123");
	BigNum y("12975892785860747823748162856127348912635871238971");
	totalScore += testCopyConst(x,"123",19);
	totalScore += testCopyConst(y,"12975892785860747823748162856127348912635871238971",20);
	return totalScore;
}

int testCopyConst(BigNum x, string y, int testnum) {
    cout << testnum << ": ";
cout.flush();
	if (printsCorrectly(x,y,testnum)) {
		cout << "Copy constructor correctly copies " << y << " (1pt)" << endl;
		return 1;
	}
	else {
		cout << "Copy constructor INCORRECTLY copies " << y << endl;
		return 0;
	}
}

int testComparisons() {

	int totalScore = 0;
	BigNum zero(0);
	BigNum smallPos(3);
	BigNum smallNeg(-7);
	BigNum medPos(11512);
	BigNum medNeg(-128498);
	BigNum largePos("87458175081682784571285609127481728568912748");
	BigNum largeNeg("-81927095706675719241290659619646134264716784617865");
	BigNum close1("78750102635816286712837462158732");
	BigNum close2("78750102635816286712837462158733");
	BigNum close3("-78750102635816286712837462158732");
	BigNum close4("-78750102635816286712837462158733");

	if (correctlyLessThan(zero,smallPos,true,21)) totalScore++;
	if (correctlyLessThan(smallNeg,smallPos,true,22)) totalScore++;
	if (correctlyLessThan(smallPos,medPos,true,23)) totalScore++;
	if (correctlyLessThan(medPos,largePos,true,24)) totalScore++;
	if (correctlyLessThan(smallNeg,zero,true,25)) totalScore++;
	if (correctlyLessThan(close1,close2,true,26)) totalScore++;
	if (correctlyLessThan(close4,close3,true,27)) totalScore++;
	if (correctlyGreaterThan(smallPos,zero,true,28)) totalScore++;
	if (correctlyGreaterThan(medPos,smallPos,true,29)) totalScore++;
	if (correctlyGreaterThan(largePos,medPos,true,30)) totalScore++;
	if (correctlyGreaterThan(zero,smallNeg,true,31)) totalScore++;
	if (correctlyGreaterThan(close2,close1,true,32)) totalScore++;
	if (correctlyGreaterThan(close3,close4,true,33)) totalScore++;
	if (correctlyEqualTo(zero,zero,true,34)) totalScore++;
	if (correctlyEqualTo(close3,close3,true,35)) totalScore++;
	if (correctlyEqualTo(largePos,largePos,true,36)) totalScore++;
	if (correctlyEqualTo(largeNeg,largeNeg,true,37)) totalScore++;
	if (correctlyEqualTo(medPos,medPos,true,38)) totalScore++;

	if (correctlyLessThan(zero,smallPos,false,39)) totalScore++;
	if (correctlyLessThan(smallNeg,smallPos,false,40)) totalScore++;
	if (correctlyLessThan(smallPos,medPos,false,41)) totalScore++;
	if (correctlyLessThan(medPos,largePos,false,42)) totalScore++;
	if (correctlyLessThan(close1,close2,false,43)) totalScore++;
	if (correctlyLessThan(close4,close3,false,44)) totalScore++;
	if (correctlyGreaterThan(smallPos,zero,false,45)) totalScore++;
	if (correctlyGreaterThan(smallPos,smallNeg,false,46)) totalScore++;
	if (correctlyGreaterThan(medPos,smallPos,false,47)) totalScore++;
	if (correctlyGreaterThan(largePos,medPos,false,48)) totalScore++;
	if (correctlyGreaterThan(close2,close1,false,49)) totalScore++;
	if (correctlyGreaterThan(close3,close4,false,50)) totalScore++;
	if (correctlyEqualTo(zero,zero,false,51)) totalScore++;
	if (correctlyEqualTo(close3,close3,false,52)) totalScore++;
	if (correctlyEqualTo(largeNeg,largeNeg,false,53)) totalScore++;
	if (correctlyEqualTo(medPos,medPos,false,54)) totalScore++;

	if (medPos >= medPos) {
		cout << "55: " << medPos << " correctly >= " << medPos << " (1pt)" << endl;
		totalScore++;
	}
	else {
		cout << "55: " << medPos << " INCORRECTLY NOT >= " << medPos << endl;
	}

	if (zero >= zero) {
		cout << "56: " << zero << " correctly >= " << zero << " (1pt)" << endl;
		totalScore++;
	}
	else {
		cout << "56: " << zero << " INCORRECTLY NOT >= " << zero << endl;
	}

	if (largeNeg <= largeNeg) {
		cout << "57: " << largeNeg << " correctly <= " << largeNeg << " (1pt)" << endl;
		totalScore++;
	}
	else {
		cout << "57: " << largeNeg << " INCORRECTLY NOT <= " << largeNeg << endl;
	}

	if (smallNeg <= smallNeg) {
		cout << "58: " << smallNeg << " correctly <= " << smallNeg << " (1pt)" << endl;
		totalScore++;
	}
	else {
		cout << "58: " << smallNeg << " INCORRECTLY NOT <= " << smallNeg << endl;
	}

	if (zero != medPos) {
		cout << "59: " << zero << " correctly != " << medPos << " (1pt)" << endl;
		totalScore++;
	}
	else {
		cout << "59: " << zero << " INCORRECTLY NOT != " << medPos << endl;
	}

	if (smallNeg != smallPos) {
		cout << "60: " << smallNeg << " correctly != " << smallPos << " (1pt)" << endl;
		totalScore++;
	}
	else {
		cout << "60: " << smallNeg << " INCORRECTLY NOT != " << smallPos << endl;
	}

	return totalScore;

}

bool correctlyLessThan(BigNum &a, BigNum &b, bool useOp, int testnum) {
    cout << testnum << ": ";
cout.flush();
	if ((useOp && a < b) || (!useOp && a.isLessThan(b))) {
		cout << a << " correctly" << (useOp ? " < " : " less than ") << b << " (1pt)" << endl;
		return true;
	}
	else {
		cout << a << " INCORRECTLY" << (useOp ? " not < " : " not less than ") << b << endl;
		return false;
	}
}

bool correctlyGreaterThan(BigNum &a, BigNum &b, bool useOp, int testnum) {
    cout << testnum << ": ";
cout.flush();
	if ((useOp && a > b) || (!useOp && a.isGreaterThan(b))) {
		cout << a << " correctly" << (useOp ? " > " : " greater than ") << b << " (1pt)" << endl;
		return true;
	}
	else {
		cout << a << " INCORRECTLY" << (useOp ? " not > " : " not greater than ") << b << endl;
		return false;
	}
}

bool correctlyEqualTo(BigNum &a, BigNum &b, bool useOp, int testnum) {
    cout << testnum << ": ";
cout.flush();
	if ((useOp && a == b) || (!useOp && a.isEqualTo(b))) {
		cout << a << " correctly" << (useOp ? " == " : " equal to ") << b << " (1pt)" << endl;
		return true;
	}
	else {
		cout << a << " INCORRECTLY" << (useOp ? " not == " : " not equal to ") << b << endl;
		return false;
	}
}

int testPlusMinus() {

	int totalScore = 0;

	BigNum num1 = "12345678987654321";
	BigNum num2 = "999";
	BigNum num3 = "-999";
	BigNum num4 = "-11122233334444555556666677777778888888889999999999";
	BigNum num5 = "11122233334444555556666677777778888888889999999999";

	BigNum sum11 = "24691357975308642";
	BigNum sum12 = "12345678987655320";
	BigNum sum22 = "1998";
	BigNum sum13 = "12345678987653322";
	BigNum sum23 = "0";
	BigNum sum24 = "-11122233334444555556666677777778888888889999999000";
	BigNum sum34 = "-11122233334444555556666677777778888888890000000998";
	BigNum sum44 = "-22244466668889111113333355555557777777779999999998";

	BigNum diff11 = "0";
	BigNum diff12 = "12345678987653322";
	BigNum diff13 = "12345678987655320";
	BigNum diff44 = "0";
	BigNum diff23 = "1998";
	BigNum diff34 = "11122233334444555556666677777778888888889999999000";
	BigNum diff15 = "-11122233334444555556666677777778876543211012345678";

	if (correctlyAdds(num1, num1, sum11, false, 61)) totalScore++; 
	if (correctlyAdds(num1, num2, sum12, false, 62)) totalScore++; 
	if (correctlyAdds(num2, num2, sum22, false, 63)) totalScore++; 
	if (correctlyAdds(num1, num3, sum13, false, 64)) totalScore++; 
	if (correctlyAdds(num2, num3, sum23, false, 65)) totalScore++; 
	if (correctlyAdds(num2, num4, sum24, false, 66)) totalScore++; 
	if (correctlyAdds(num3, num4, sum34, false, 67)) totalScore++; 
	if (correctlyAdds(num4, num4, sum44, false, 68)) totalScore++; 

	if (correctlySubtracts(num1, num1, diff11, false, 69)) totalScore++; 
	if (correctlySubtracts(num1, num2, diff12, false, 70)) totalScore++; 
	if (correctlySubtracts(num1, num3, diff13, false, 71)) totalScore++; 
	if (correctlySubtracts(num4, num4, diff44, false, 72)) totalScore++; 
	if (correctlySubtracts(num2, num3, diff23, false, 73)) totalScore++; 
	if (correctlySubtracts(num3, num4, diff34, false, 74)) totalScore++; 
	if (correctlySubtracts(num1, num5, diff15, false, 75)) totalScore++; 

	if (correctlyAdds(num1, num1, sum11, true, 76)) totalScore++; 
	if (correctlyAdds(num1, num2, sum12, true, 77)) totalScore++; 
	if (correctlySubtracts(num1, num1, diff11, true, 78)) totalScore++; 

    cout << "79: ";
    cout.flush();
	num1 += num2;
	if (num1 == sum12) {
		cout << "+= correct (1pt)" << endl;
		totalScore++;
	}
	else {
		cout << "+= INCORRECT" << endl;
	}

    cout << "80: ";
    cout.flush();
	num3 -= num4;
	if (num3 == diff34) {
		cout << "-= correct (1pt)" << endl;
		totalScore++;
	}
	else {
		cout << "-= INCORRECT" << endl;
	}

	return totalScore;
}

int testFactorial() {

	int totalScore = 0;

	BigNum num1 = "1";
	BigNum num2 = "5";
	BigNum num3 = "11";
	BigNum num4 = "17";
	BigNum num5 = "999";

	BigNum factorial1 = "1";
	BigNum factorial2 = "120";
	BigNum factorial3 = "39916800";
	BigNum factorial4 = "355687428096000";
	BigNum factorial5 = "402387260077093773543702433923003985719374864210714632543799910429938512398629020592044208486969404800479988610197196058631666872994808558901323829669944590997424504087073759918823627727188732519779505950995276120874975462497043601418278094646496291056393887437886487337119181045825783647849977012476632889835955735432513185323958463075557409114262417474349347553428646576611667797396668820291207379143853719588249808126867838374559731746136085379534524221586593201928090878297308431392844403281231558611036976801357304216168747609675871348312025478589320767169132448426236131412508780208000261683151027341827977704784635868170164365024153691398281264810213092761244896359928705114964975419909342221566832572080821333186116811553615836546984046708975602900950537616475847728421889679646244945160765353408198901385442487984959953319101723355556602139450399736280750137837615307127761926849034352625200015888535147331611702103968175921510907788019393178114194545257223865541461062892187960223838971476088506276862967146674697562911234082439208160153780889893964518263243671616762179168909779911903754031274622289988005195444414282012187361745992642956581746628302955570299024324153181617210465832036786906117260158783520751516284225540265170483304226143974286933061690897968482590125458327168226458066526769958652682272807075781391858178889652208164348344825993266043367660176999612831860788386150279465955131156552036093988180612138558600301435694527224206344631797460594682573103790084024432438465657245014402821885252470935190620929023136493273497565513958720559654228749774011413346962715422845862377387538230483865688976461927383814900140767310446640259899490222221765904339901886018566526485061799702356193897017860040811889729918311021171229845901641921068884387121855646124960798722908519296819372388642614839657382291123125024186649353143970137428531926649875337218940694281434118520158014123344828015051399694290153483077644569099073152433278288269864602789864321139083506217095002597389863554277196742822248757586765752344220207573630569498825087968928162753848863396909959826280956121450994871701244516461260379029309120889086942028510640182154399457156805941872748998094254742173582401063677404595741785160829230135358081840096996372524230560855903700624271243416909004153690105933983835777939410970027753472000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

	if (correctlyComputesFactorial(num1, factorial1, 96)) totalScore++; 
	if (correctlyComputesFactorial(num2, factorial2, 97)) totalScore++; 
	if (correctlyComputesFactorial(num3, factorial3, 98)) totalScore++; 
	if (correctlyComputesFactorial(num4, factorial4, 99)) totalScore++; 
	if (correctlyComputesFactorial(num5, factorial5, 100)) totalScore++; 

    return totalScore;
}

int testTimes() {

	int totalScore = 0;

    BigNum num = "3";
    BigNum num0 = "-4";
    BigNum num1 = "5";
	BigNum num2 = "12345678987654321";
	BigNum num3 = "-999";
	BigNum num4 = "-11122233334444555556666677777778888888889999999999";
	BigNum num5 = "11122233334444555556666677777778888888889999999999";

    BigNum product = "9";
	BigNum product00 = "16";
	BigNum product01 = "-20";
	BigNum product11 = "25";
	BigNum product20 = "-49382715950617284";
	BigNum product12 = "61728394938271605";
	BigNum product13 = "-4995";
	BigNum product22 = "152415789666209420210333789971041";
	BigNum product23 = "-12333333308666666679";
	BigNum product33 = "998001";
	BigNum product14 = "-55611166672222777783333388888894444444449999999995";
	BigNum product44 = "123704074345829656818543728657062024719780296568007385434568149185182965409876542222222220000000001";

	if (correctlyMultiplies(num, num, product, false, 81)) totalScore++; 
	if (correctlyMultiplies(num0, num0, product00, false, 82)) totalScore++; 
	if (correctlyMultiplies(num0, num1, product01, false, 83)) totalScore++; 
	if (correctlyMultiplies(num1, num1, product11, false, 84)) totalScore++; 
	if (correctlyMultiplies(num2, num0, product20, false, 85)) totalScore++; 
	if (correctlyMultiplies(num1, num2, product12, false, 86)) totalScore++; 
	if (correctlyMultiplies(num1, num3, product13, false, 87)) totalScore++; 
	if (correctlyMultiplies(num2, num2, product22, false, 88)) totalScore++; 
	if (correctlyMultiplies(num2, num3, product23, false, 89)) totalScore++; 
	if (correctlyMultiplies(num3, num3, product33, false, 90)) totalScore++; 
	if (correctlyMultiplies(num1, num4, product14, false, 91)) totalScore++; 
	if (correctlyMultiplies(num4, num4, product44, false, 92)) totalScore++; 

	if (correctlyMultiplies(num1, num1, product11, true, 93)) totalScore++; 
	if (correctlyMultiplies(num2, num3, product23, true, 94)) totalScore++; 

    if (correctTimesEquals(num1,num2,product12, 95)) totalScore++;

	return totalScore;
}

bool correctlyMultiplies(BigNum &a, BigNum &b, BigNum &c, bool useOp,
    int testnum) {
    // EXTRA CREDIT: if you wrote times() and operator*, remove the 
    // "return false;" line, above, and uncomment the following code:
    cout << testnum << ": ";
    cout.flush();
	BigNum product;
	if (useOp) {
		product = a * b;
		if (product.isEqualTo(c)) {
			cout << a << " * " << b << " correctly " << product << " (1pt)" << endl;
			return true;
		}
		else {
			cout << a << " * " << b << " INCORRECTLY " << product << " instead of " << c << endl;
			return false;
		}
	}
	else {
		product = a.times(b);
		if (product.isEqualTo(c)) {
			cout << a << " times " << b << " correctly " << product << " (1pt)" << endl;
			return true;
		}
		else {
			cout << a << " times " << b << " INCORRECTLY " << product << " instead of " << c << endl;
			return false;
		}
	}
}

bool correctTimesEquals(BigNum &num1, BigNum &num2, BigNum &product,
    int testnum) {
    // EXTRA CREDIT: if you wrote operator*=, remove the "return false;"
    // line, above, and uncomment the following code:
    cout << testnum << ": ";
    cout.flush();
	num1 *= num2;
	if (num1 == product) {
		cout << "*= correct (1pt)" << endl;
        return true;
	}
	else {
		cout << "*= INCORRECT" << endl;
        return false;
	}
}

bool correctlyComputesFactorial(BigNum &a, BigNum &b, int testnum) {
    return false;
    // EXTRA CREDIT: if you wrote factorial(), remove the "return false;",
    // above, and uncomment the following code:
/*
    cout << testnum << ": ";
    cout.flush();
	BigNum factorial;
    factorial = a.factorial();
    if (factorial.isEqualTo(b)) {
        cout << a << "! is correctly " << b << " (1pt)" << endl;
        return true;
    }
    else {
        cout << a << "! is INCORRECTLY " << factorial << " instead of " << b << endl;
        return false;
    }
*/
}

bool correctlyAdds(BigNum &a, BigNum &b, BigNum &c, bool useOp,
    int testnum) {
    cout << testnum << ": ";
    cout.flush();
	BigNum sum;
	if (useOp) {
		sum = a + b;
		if (sum.isEqualTo(c)) {
			cout << a << " + " << b << " correctly " << sum << " (1pt)" << endl;
			return true;
		}
		else {
			cout << a << " + " << b << " INCORRECTLY " << sum << " instead of " << c << endl;
			return false;
		}
	}
	else {
		sum = a.plus(b);
		if (sum.isEqualTo(c)) {
			cout << a << " plus " << b << " correctly " << sum << " (1pt)" << endl;
			return true;
		}
		else {
			cout << a << " plus " << b << " INCORRECTLY " << sum << " instead of " << c << endl;
			return false;
		}
	}
}

bool correctlySubtracts(BigNum &a, BigNum &b, BigNum &c, bool useOp,
    int testnum) {
	BigNum diff;
    cout << testnum << ": ";
    cout.flush();
	if (useOp) {
		diff = a - b;
		if (diff.isEqualTo(c)) {
			cout << a << " - " << b << " correctly " << diff << " (1pt)" << endl;
			return true;
		}
		else {
			cout << a << " - " << b << " INCORRECTLY " << diff << " instead of " << c << endl;
			return false;
		}
	}
	else {
		diff = a.minus(b);
		if (diff.isEqualTo(c)) {
			cout << a << " minus " << b << " correctly " << diff << " (1pt)" << endl;
			return true;
		}
		else {
			cout << a << " minus " << b << " INCORRECTLY " << diff << " instead of " << c << endl;
			return false;
		}
	}
}

bool printsCorrectly(BigNum &b, string output, int testnum) {

    cout << testnum << ": ";
    cout.flush();
	ostringstream buf(ios_base::out);
	b.print(buf);
	const char *contents = buf.str().c_str();
	if (strcmp(contents, output.c_str()) == 0) {
		cout << "correctly prints BigNum " << b << " (1pt)" << endl;
		return true;
	}
	cout << "INCORRECTLY prints " << contents << " for BigNum " << output << endl;
	return false;
}

int testIntConst(string output, int testnum) {
	int x = atoi(output.c_str());
	int score = 0;
	BigNum a(x);
	if (printsCorrectly(a,output,testnum)) {
		score++;
	}
	return score;
}

int testCharArrayConst(string output, int testnum) {
	int score = 0;
	BigNum a(output.c_str());
	if (printsCorrectly(a,output,testnum)) {
		score++;
	}
	return score;
}

int testDefaultConst(int testnum) {
	int score = 0;
	BigNum a;
	if (printsCorrectly(a,"0",testnum)) {
		score++;
	}
	return score;
}
