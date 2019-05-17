#include <gtest/gtest.h>
#include "../code/mycalc.h"

class mycalcTest : public ::testing::Test {
protected:
	void SetUp() override {
	}
	//void TearDown() override {}
	
	mycalc mycalcobj;
};

TEST_F(mycalcTest, SumFuncForPositiveResult){
	EXPECT_EQ(5,mycalcobj.sum(2,3));
}

TEST_F(mycalcTest, SumFuncForNegativeResult){
	EXPECT_EQ(-1,mycalcobj.sum(-3,2));
}

TEST_F(mycalcTest, SubFunc){
	EXPECT_EQ(1,mycalcobj.sub(3,2));
}


