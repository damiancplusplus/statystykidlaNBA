#include "sort.hpp"
#include "menu.hpp"
#include "gtest/gtest.h"


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
player.nr=9;
    player.za1_celny =1;
    player.za1_niecelny=0;
    player.za1_p=0;
    player.za2_celny=1;
    player.za2_niecelny=0;
    player.za2_p=0;
    player.za3_celny=1;
    player.za3_niecelny=0;
    player.za3_p=0;
    player.zbiorka_atak=0;
    player.zbiorka_obrona=0;
    player.asysta=0;
    player.faul_atak=0;
    player.faul_obrona=0;
    player.strata=0;
    player.przechwyt=0;
    player.eval=0;
    player.punkty=0;
   
	
    EXPECT_EQ(6, player.licz_punkty());
	
}

int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
