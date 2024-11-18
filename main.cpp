#include "include.h"

bool ifWon(std::vector<Tile> tiles)
{
    if (tiles[0].position == cv::Point(0, 0) &&
        tiles[1].position == cv::Point(1, 0) &&
        tiles[2].position == cv::Point(2, 0) &&
        tiles[3].position == cv::Point(0, 1) &&
        tiles[4].position == cv::Point(1, 1) &&
        tiles[5].position == cv::Point(2, 1) &&
        tiles[6].position == cv::Point(0, 2) &&
        tiles[7].position == cv::Point(1, 2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Won()
{
    std::cout << "You win!" << std::endl;
    cv::Mat winImage = cv::imread("pic/win.jpg");
    cv::imshow("Number Slider Puzzle", winImage);
    cv::waitKey(0);
}

int main(int argc, char *argv[])
{
    cv::Mat startImage = cv::imread("pic/start.jpg");
    cv::imshow("Number Slider Puzzle", startImage);
    cv::waitKey(0);

    cv::Mat originalImage = cv::imread("pic/numbers.jpg");
    if (originalImage.empty())
    {
        std::cerr << "Could not open or find the image!" << std::endl;
        return -1;
    }

    cv::Mat resizedImage = ResizeImage(originalImage, TILE_SIZE * GRID_SIZE, TILE_SIZE * GRID_SIZE);
    std::vector<Tile> tiles = SpliteImage(resizedImage);
    tiles.back().isEmpty = true;
    tiles = ShuffleTiles(tiles);

    cv::Mat canvas(GRID_SIZE * TILE_SIZE, GRID_SIZE * TILE_SIZE, originalImage.type());
    canvas.setTo(cv::Scalar::all(0));
    DrawTiles(canvas, tiles);

    cv::imshow("Number Slider Puzzle", canvas);

    for (;;)
    {
        int key = cv::waitKeyEx(0);
        if (IsKeyLegit(tiles, key))
        {
            int emptyBlock = GetEmptyIndex(tiles);
            if (key == KEY_UP)
            {
                std::swap(tiles[emptyBlock], tiles[emptyBlock + 3]);
                canvas.setTo(cv::Scalar::all(0));
                DrawTiles(canvas, tiles);
                cv::imshow("Number Slider Puzzle", canvas);
                if (ifWon(tiles))
                {
                    Won();
                    break;
                }
            }
            else if (key == KEY_DOWN)
            {
                std::swap(tiles[emptyBlock], tiles[emptyBlock - 3]);
                canvas.setTo(cv::Scalar::all(0));
                DrawTiles(canvas, tiles);
                cv::imshow("Number Slider Puzzle", canvas);
                if (ifWon(tiles))
                {
                    Won();
                    break;
                }
            }
            else if (key == KEY_LEFT)
            {
                std::swap(tiles[emptyBlock], tiles[emptyBlock + 1]);
                canvas.setTo(cv::Scalar::all(0));
                DrawTiles(canvas, tiles);
                cv::imshow("Number Slider Puzzle", canvas);
                if (ifWon(tiles))
                {
                    Won();
                    break;
                }
            }
            else if (key == KEY_RIGHT)
            {
                std::swap(tiles[emptyBlock], tiles[emptyBlock - 1]);
                canvas.setTo(cv::Scalar::all(0));
                DrawTiles(canvas, tiles);
                cv::imshow("Number Slider Puzzle", canvas);
                if (ifWon(tiles))
                {
                    Won();
                    break;
                }
            }
        }
        else
        {
            continue;
        }
    }
}