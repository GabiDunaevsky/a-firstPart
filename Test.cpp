#include "mat.hpp"
#include <iostream>
#include "doctest.h"
#include <string>
#include <algorithm>

using namespace std;
using namespace ariel;

string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n" // Example.
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));

	CHECK(nospaces(mat(13,5,'@','-')) == nospaces("@@@@@@@@@@@@@\n" // Regular matrix.
												   "@-----------@\n"
												   "@-@@@@@@@@@-@\n"
												   "@-----------@\n"
												   "@@@@@@@@@@@@@"));
	
	CHECK(nospaces(mat(33,19,'@','-')) == nospaces("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n" // Big Matrix.
													"@-------------------------------@\n"
													"@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@\n"
													"@-@---------------------------@-@\n"
													"@-@-@@@@@@@@@@@@@@@@@@@@@@@@@-@-@\n"
													"@-@-@-----------------------@-@-@\n"
													"@-@-@-@@@@@@@@@@@@@@@@@@@@@-@-@-@\n"
													"@-@-@-@-------------------@-@-@-@\n"
													"@-@-@-@-@@@@@@@@@@@@@@@@@-@-@-@-@\n"
													"@-@-@-@-@---------------@-@-@-@-@\n"
													"@-@-@-@-@@@@@@@@@@@@@@@@@-@-@-@-@\n"
													"@-@-@-@-------------------@-@-@-@\n"
													"@-@-@-@@@@@@@@@@@@@@@@@@@@@-@-@-@\n"
													"@-@-@-----------------------@-@-@\n"
													"@-@-@@@@@@@@@@@@@@@@@@@@@@@@@-@-@\n"
													"@-@---------------------------@-@\n"
													"@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@\n"
													"@-------------------------------@\n"
													"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"));
	
	CHECK(nospaces(mat(1,1,'%','$')) == nospaces("%")); // A good matrix of one sign.

	CHECK(nospaces(mat(1,9,'%','$')) == nospaces("%\n" // A good colum Matrix.
												  "%\n"
												  "%\n"
												  "%\n"
												  "%\n"
												  "%\n"
												  "%\n"
												  "%\n"
												  "%"));
	
	CHECK(nospaces(mat(9,1,'%','$')) == nospaces("%%%%%%%%%")); // A row Matrix.
	
	CHECK(nospaces(mat(9,3,'@','@')) == nospaces("@@@@@@@@@\n"
												   "@@@@@@@@@\n"
												   "@@@@@@@@@")); // Same sign Matrix.

	CHECK(nospaces(mat(3,3,'@','-')) == nospaces("@@@\n"
												   "@-@\n"
												   "@@@")); // square Matrix.

	

													
	/* Add more test here */
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%')); //Example.
	CHECK_THROWS(mat(35,-3,'@','-')); // When one number is negative but bouth are odd.
	CHECK_THROWS(mat(0,43,'@','-')); // When one number is equal to zero.
	CHECK_THROWS(mat(-2,43,'@','-'));// When one number is negative and the matrix is odd.
	CHECK_THROWS(mat(13,4,'@','-'));// When the matrix is not odd but two numbers are positive.
	CHECK_THROWS(mat(-13,-11,'@','-')); // When both are odd but negative.
	CHECK_THROWS(mat(0,0,'@','-')); // The zero matrix(not odd and nothing to print).
	CHECK_THROWS(mat(10,10,'@','^')); // When both are even.
	CHECK_THROWS(mat(-10,-10,'@','^')); // When both are negative and even.
	CHECK_THROWS(mat(10,10,'@','@')); // When both are even and same sign.
	// CHECK_THROWS(mat(9,3,'@','\n')); // When the char is not in the right range(Depents on the range , check for part b).
	// CHECK_THROWS(mat(9,3,'@','\t')); // When the char is not in the right range(Depents on the range , check for part b)..
	// CHECK_THROWS(mat(9,3,'@','\r')); // When the char is not in the right range(Depents on the range , check for part b).. 


    /* Add more test here */
}

TEST_CASE("Good input length") {
	CHECK(nospaces(mat(9,3,'@','@')).length() == 27);
	CHECK(nospaces(mat(5,5,'@','-')).length() == 25);
	CHECK(nospaces(mat(1,1,'@','-')).length() == 1);
	CHECK(nospaces(mat(1,9,'@','-')).length() == 9);
}
/* Add more test cases here */