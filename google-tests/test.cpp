#include "pch.h"
#include "Circle.h"



TEST(TestCase, CheckName) {
	data a;
	a.setVardas("ignas");
	EXPECT_EQ(a.getVardas(), "ignas");
	EXPECT_TRUE(true);
}


TEST(TestCase, CheckAvg) {
	data pi;
	data du;
	pi.setRez(2);
	pi.setMediana(3);
	du.setRez(4);
	du.setMediana(5);
	data trys = pi+du;
	EXPECT_EQ(trys.getRez(), 6);
	EXPECT_TRUE(true);
}