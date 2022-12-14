#ifndef CONFIG_H
#define CONFIG_H

namespace Config
{
    //Speed the game will run at by default
    const int k_defaultGameSpeed = 100;

    //Speed the game will increase by after score milestones
    const int k_gameSpeedIncrement = 10;

    //Score Milestone, game will speed up each time the score increases by this amount
    const int k_scoreMilestone = 5;

    //Maximum value the speed multiplier can reach
    //Needs to be set to safe value so that the game speed does not become too fast
    //k_gameSpeedIncrement * k_maxSpeedMultiplier will be the total that is subtracted from the game speed variable at max, this should not exceed k_defaultGameSpeed
    const int k_maxSpeedMultiplier = 5;

    //Console window size
    const int k_windowHeight = 560;
    const int k_windowWidth = 775;

    //Game map size
    const int k_mapHeight = 30;
    const int k_mapWidth = 90;

    //-------------------------------------------------------
    //	Function	:	calcPlayableSpace
    //	Purpose		:	Calculates the total available spaces inside the map border
    //	Parameters  :	none
    //	Returns		:	int
    //-------------------------------------------------------
    int calcPlayableSpace();
}

#endif // End of '#ifndef CONFIG_H'