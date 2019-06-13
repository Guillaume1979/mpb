
#include "mpblib.hpp"

#include "gtest/gtest.h"

#include <boost/date_time/gregorian/gregorian.hpp>
#include <memory>
#include <iostream>

TEST(MPBClass, MPBClass001)
{
	date_t testdate = date_t(2019, 6, 13);
	std::unique_ptr<mpbns::MPBClass> mpbc(new mpbns::MPBClass(testdate));
	std::cout << testdate << std::endl;
	ASSERT_TRUE(mpbc->get_date() == testdate);
}

TEST(MPBClass, MPBClass002)
{
	date_t testdate = date_t(2019, 6, 14);
	std::unique_ptr<mpbns::MPBClass> mpbc(new mpbns::MPBClass(testdate));
	std::cout << testdate << std::endl;
	ASSERT_TRUE(mpbc->get_date() == testdate);
}



