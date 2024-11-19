#include "include.h"

cv::Mat ResizeImage(cv::Mat image, int width, int height)
{
    cv::Mat resizedImage;
    cv::resize(image, resizedImage, cv::Size(width, height));
    return resizedImage;
}

std::vector<Tile> SpliteImage(cv::Mat image)
{
    std::vector<Tile> tiles;
    for (int x = 0; x < GRID_SIZE; x++)
    {
        for (int y = 0; y < GRID_SIZE; y++)
        {
            cv::Rect positions(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE);
            tiles.push_back({image(positions).clone(), cv::Point(x, y), false});
        }
    }

    return tiles;
}

std::vector<Tile> ShuffleTiles(std::vector<Tile> &tiles)
{
    std::vector<Tile> shuffledTiles = tiles;
    for (;;)
    {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(shuffledTiles.begin(), shuffledTiles.end() - 1, g); // 最后1个一开始不显示，所以不用打乱

        if (Calculateinversions(PointsToInts(shuffledTiles)) % 2 == 0)
        {
            // std::cout << "The inverse ordinal number is even, shuffled successfully!" << std::endl;
            return shuffledTiles; // 只返回逆序数为偶数的打乱结果
            break;
        }

        // std::cout << "The inverse ordinal number is not even, shuffling again..." << std::endl;
    }
}

void DrawTiles(cv::Mat &canvas, const std::vector<Tile> &tiles)
{
    int index = 0;
    for (int y = 0; y < GRID_SIZE; ++y)
    {
        for (int x = 0; x < GRID_SIZE; ++x)
        {
            if (!tiles[index].isEmpty)
            {
                cv::Rect roi(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE);
                tiles[index].image.copyTo(canvas(roi));
            }
            index++;
        }
    }
}