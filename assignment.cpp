#include <iostream>
#include <vector>
#include <utility>

void drawLineLow(int x0, int y0, int x1, int y1, std::vector<std::pair<int, int>>& lineCoordinates) {
    int deltaX = x1 - x0;
    int deltaY = y1 - y0;
    int stepY = 1;
    if (deltaY < 0) {
        stepY = -1;
        deltaY = -deltaY;
    }
    int decisionParam = 2 * deltaY - deltaX;
    int y = y0;

    for (int x = x0; x <= x1; x++) {
        lineCoordinates.push_back(std::make_pair(x, y));
        if (decisionParam > 0) {
            y += stepY;
            decisionParam -= 2 * deltaX;
        }
        decisionParam += 2 * deltaY;
    }
}

void drawLineHigh(int x0, int y0, int x1, int y1, std::vector<std::pair<int, int>>& lineCoordinates) {
    int deltaX = x1 - x0;
    int deltaY = y1 - y0;
    int stepX = 1;
    if (deltaX < 0) {
        stepX = -1;
        deltaX = -deltaX;
    }
    int decisionParam = 2 * deltaX - deltaY;
    int x = x0;

    for (int y = y0; y <= y1; y++) {
        lineCoordinates.push_back(std::make_pair(x, y));
        if (decisionParam > 0) {
            x += stepX;
            decisionParam -= 2 * deltaY;
        }
        decisionParam += 2 * deltaX;
    }
}

void drawLine(int x0, int y0, int x1, int y1, std::vector<std::pair<int, int>>& lineCoordinates) {
    if (std::abs(y1 - y0) < std::abs(x1 - x0)) {
        if (x0 > x1)
            drawLineLow(x1, y1, x0, y0, lineCoordinates);
        else
            drawLineLow(x0, y0, x1, y1, lineCoordinates);
    } else {
        if (y0 > y1)
            drawLineHigh(x1, y1, x0, y0, lineCoordinates);
        else
            drawLineHigh(x0, y0, x1, y1, lineCoordinates);
    }
}

void displayGrid(const std::vector<std::pair<int, int>>& lineCoordinates) {
    int maxX = 0;
    int maxY = 0;
    for (const auto& point : lineCoordinates) {
        maxX = std::max(maxX, point.first);
        maxY = std::max(maxY, point.second);
    }

    std::vector<std::vector<char>> grid(maxY + 1, std::vector<char>(maxX + 1, '.'));

    for (const auto& point : lineCoordinates) {
        grid[point.second][point.first] = '*';
    }

    for (int y = maxY; y >= 0; y--) {
        for (int x = 0; x <= maxX; x++) {
            std::cout << grid[y][x] << " ";
        }
        std::cout << std::endl;
    }
}

void displayCoordinates(const std::vector<std::pair<int, int>>& lineCoordinates) {
    std::cout << "Line Coordinates: ";
    for (const auto& point : lineCoordinates) {
        std::cout << "(" << point.first << ", " << point.second << ") ";
    }
    std::cout << std::endl;
}

int main() {
    // Case 1: 0 < m < 1
    std::cout << "Test Case 1: Line from (1,1) to (8,4)" << std::endl;
    std::vector<std::pair<int, int>> lineCoordinates1;
    drawLine(1, 1, 8, 4, lineCoordinates1);
    displayGrid(lineCoordinates1);
    displayCoordinates(lineCoordinates1);

    // Case 2: m > 1
    std::cout << "\nTest Case 2: Line from (1,1) to (4,8)" << std::endl;
    std::vector<std::pair<int, int>> lineCoordinates2;
    drawLine(1, 1, 4, 8, lineCoordinates2);
    displayGrid(lineCoordinates2);
    displayCoordinates(lineCoordinates2);

    return 0;
}
