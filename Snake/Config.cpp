#include "Config.h"

namespace Config
{
    int calcPlayableSpace()
    {
        //Multiplying height by width to get total spaces
        int totalSpaces = k_mapHeight * k_mapWidth;

        //Adding height * 2 to width * 2 to get the border spaces, then minus 4 so the corners aren't counted twice
        int borderSpaces = ( ( k_mapHeight * 2 ) + ( k_mapWidth * 2 ) ) - 4;

        //Minus border spaces from total spaces to get the total amount of playable spaces
        //Then minus 1 to account for the snake head
        int remainingSpaces = ( totalSpaces - borderSpaces ) - 1;

        return remainingSpaces;
    }
}