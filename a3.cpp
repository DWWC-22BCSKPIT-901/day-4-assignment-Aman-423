#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void floodFillUtil(vector<vector<int>>& img, int x, int y, int prevClr, int newClr) {
    // Base cases
    if (x < 0 || x >= img.size() || y < 0 || y >= img[0].size()) {
        return;
    }
    if (img[x][y] != prevClr || img[x][y] == newClr) {
        return;
    }

    // Replace the color
    img[x][y] = newClr;

    // Recur for 4 adjacent pixels
    floodFillUtil(img, x + 1, y, prevClr, newClr);
    floodFillUtil(img, x - 1, y, prevClr, newClr);
    floodFillUtil(img, x, y + 1, prevClr, newClr);
    floodFillUtil(img, x, y - 1, prevClr, newClr);
}

void floodFill(vector<vector<int>>& img, int x, int y, int newClr) {
    int prevClr = img[x][y];
    floodFillUtil(img, x, y, prevClr, newClr);
}

int main() {
    vector<vector<int>> img = {
        {1, 1, 1, 1},
        {1, 1, 0, 0},
        {1, 0, 1, 1}
    };
    int x = 1, y = 1, newClr = 2;

    floodFill(img, x, y, newClr);

    cout << "Updated image:\n";
    for (const auto& row : img) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << "\n";
    }

    return 0;
}