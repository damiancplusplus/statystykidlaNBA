#include "sort.hpp"
#include <gtest/gtest.h>

// Test enum
TEST(FactorialTest, TestEnum) {
  EXPECT_EQ(1, Factorial(Blok));
  EXPECT_EQ(2, Factorial(za2));
  EXPECT_EQ(3, Factorial(za3));
}

TEST(FactorialTest, TestCountPoints)
{
	druzyna team;
	int points = 0;
	for(int i=0 ; i<10; ++i)
	{
		zawodnik player;
		player.punkty = 2;
		points +=2;
		
		team.zawodnicy.push_back(player);
	}
	
	EXPECT_EQ(points, team.licz_punkty_druzyny());
}

TEST(FactorialTest, TestCountPlayerPoints)
{
	zawodnik player;
	
	player.za1_celny +=1;
	player.za2_celny +=1;
	player.za3_celny +=1;
	
	EXPECT_EQ(6, player.licz_punkty());
	
}

int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
</gtest>