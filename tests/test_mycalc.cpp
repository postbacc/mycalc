
// gtest/gtest.h must be included here
#include <gtest/gtest.h>
#include "../code/mycalc.h"

#include <fstream>
#include <iostream>

class mycalcTest : public ::testing::Test {
protected:
	static void SetUpTestCase(){
	}

	// This function runs only once before any TEST_F function
	static void TearDownTestCase(){
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open())
		outgrade.clear();

		outgrade << total_grade;
		outgrade.close();
	}

	// This function runs after all TEST_F functions have been executed
	void add_points_to_grade(int points){
		if(!::testing::Test::HasFailure()){
			total_grade += points;
		}
	}

	// this function runs before every TEST_F function
	void SetUp() override {}

	// this function runs after ever TEST_F function
	void TearDown() override {}
	
	mycalc mycalcobj;
	static int total_grade;
};

int mycalcTest::total_grade = 0;

TEST_F(mycalcTest, SumFuncForPositiveResult){
	EXPECT_EQ(5,mycalcobj.sum(2,3));
	add_points_to_grade(10);
}

TEST_F(mycalcTest, SumFuncForNegativeResult){
	EXPECT_EQ(-1,mycalcobj.sum(-3,2));
	add_points_to_grade(5);
}

TEST_F(mycalcTest, SubFunc){
	EXPECT_EQ(1,mycalcobj.sub(3,2));
	add_points_to_grade(2);
}


