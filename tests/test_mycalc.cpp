#include <gtest/gtest.h>
#include <fstream>
#include <iostream>
#include "../code/mycalc.h"

class mycalcTest : public ::testing::Test {
protected:
	static void SetUpTestCase(){
	}
	static void TearDownTestCase(){
		std::ofstream outgrade("total_grade.txt");
		if(outgrade.is_open())
		outgrade.clear();

		outgrade << total_grade;
		outgrade.close();
	}

	void add_points_to_grade(int points){
		if(!::testing::Test::HasFailure()){
			total_grade += points;
		}
	}

	void SetUp() override {}

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


