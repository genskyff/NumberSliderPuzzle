#include "include.h"

std::vector<DirectionsAllowed> isDirectionsAllowed =
    {
        // up, down, left, right
        {true, false, true, false},
        {true, false, true, true},
        {true, false, false, true},
        {true, true, true, false},
        {true, true, true, true},
        {true, true, false, true},
        {false, true, true, false},
        {false, true, true, true},
        {false, true, false, true}};

int GetEmptyIndex(std::vector<Tile> tiles)
{
    for (int i = 0; i < tiles.size(); i++)
    {
        if (tiles[i].isEmpty == true)
        {
            return i;
        }
    }

    std::cout << "Error: No empty tile found" << std::endl;
    return -1;
}

bool IsKeyLegit(std::vector<Tile> tiles, int key)
{
    int index = GetEmptyIndex(tiles);
    if (key == KEY_UP)
    {
        return isDirectionsAllowed[index].isUpAllowed ? true : false;
    }
    else if (key == KEY_DOWN)
    {
        return isDirectionsAllowed[index].isDownAllowed ? true : false;
    }
    else if (key == KEY_LEFT)
    {
        return isDirectionsAllowed[index].isLeftAllowed ? true : false;
    }
    else if (key == KEY_RIGHT)
    {
        return isDirectionsAllowed[index].isRightAllowed ? true : false;
    }
    else if (key == -1)
    {
        exit(0);
    }
    else
    {
        return false;
    }
}