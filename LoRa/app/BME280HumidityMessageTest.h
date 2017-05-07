/*
 * BME280HumidityMessageTest.cpp
 *
 *  Created on: 14.12.2016
 *      Author: Adrian
 */

#include "gtest/gtest.h"

class BME280HumidityMessageTest : public ::testing::Test{
protected:
	virtual void SetUp(){

	}

	virtual void tearDown(){

	}

};

TEST(GetMessage,1){
	EXPECT_EQ(1,1);
}


