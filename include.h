#pragma once

#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <random>

#define GRID_SIZE 3
#define TILE_SIZE 200
#define KEY_UP 2490368
#define KEY_DOWN 2621440
#define KEY_LEFT 2424832
#define KEY_RIGHT 2555904

struct Tile
{
    cv::Mat image;      // 存储图像块
    cv::Point position; // 图像块在网格中的位置
    bool isEmpty;       // 是否为空白块
};

struct DirectionsAllowed
{
    bool isUpAllowed;
    bool isDownAllowed;
    bool isLeftAllowed;
    bool isRightAllowed;
};

// ImageProcess.cpp
cv::Mat ResizeImage(cv::Mat image, int width, int height);
std::vector<Tile> SpliteImage(cv::Mat image);
std::vector<Tile> ShuffleTiles(std::vector<Tile> &tiles);
void DrawTiles(cv::Mat &canvas, const std::vector<Tile> &tiles);

// MathProcess.cpp
int PointToInt(cv::Point point);
std::vector<int> PointsToints(std::vector<Tile> &tiles);
int Calculateinversions(std::vector<int> numbers);

// InputProcess.cpp
int GetEmptyIndex(std::vector<Tile> tiles);
bool IsKeyLegit(std::vector<Tile> tiles, int key);