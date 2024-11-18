#include "include.h"

int PointToInt(cv::Point point)
{
    if (point.x == 0 && point.y == 0)
        return 1;
    else if (point.x == 1 && point.y == 0)
        return 2;
    else if (point.x == 2 && point.y == 0)
        return 3;
    else if (point.x == 0 && point.y == 1)
        return 4;
    else if (point.x == 1 && point.y == 1)
        return 5;
    else if (point.x == 2 && point.y == 1)
        return 6;
    else if (point.x == 0 && point.y == 2)
        return 7;
    else if (point.x == 1 && point.y == 2)
        return 8;
    else
    {
        std::cerr << "Error: PointToInt failed." << std::endl;
        return -1;
    }
}

std::vector<int> PointsToints(std::vector<Tile> &tiles)
{
    std::vector<int> result;
    for (int i = 0; i < tiles.size() - 1; i++)
    {
        result.push_back(PointToInt(tiles[i].position));
    }

    return result;
}

int Calculateinversions(std::vector<int> numbers)
{
    int result = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        int temp = 0;
        for (int j = i + 1; j < numbers.size(); j++)
        {
            if (numbers[j] < numbers[i])
            {
                temp++;
            }
            else
            {
                continue;
            }
        }
        result += temp;
    }

    return result;
}