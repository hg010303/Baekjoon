#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

char map[1023][2045];
void drawStar(int n, int x, int y, bool dir) {
    // 시작점
    map[x][y] = '*';
    // 마지막 단계라면 return
    if (n == 1) return;

    // 삼각형의 높이
    int height = (1 << n) - 1;
    int left = y, right = y;
    for (int i = 1; i < height; i++) {
        if (dir) x--; // UP
        else x++; // DOWN

        left--; right++;
        map[x][left] = '*'; map[x][right] = '*';
    }

    //  마지막 단계에서는 left와 right 사이에 '*'로 채움
    for (int j = left + 1; j < right; j++) {
        map[x][j] = '*';
    }

    // 안쪽 삼각형의 시작점 x 좌표 계산
    if (dir) x++;
    else x--;

    drawStar(n - 1, x, y, !dir);
}

int main(void) {
    int n;
    cin >> n;

    // 모든 영역을 공백으로 초기화
    int height = (1 << n) - 1;
    int width = 2 * height - 1;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j] = ' ';
        }
    }

    bool dir = false; // DOWN
    if (n % 2 == 0) dir = true; // UP

    int x = 0;
    if (dir) x = (1 << n) - 2;
    int y = (1 << n) - 2;

    drawStar(n, x, y, dir);

    // 출력할 때, 바깥쪽 삼각형의 오른쪽 공백은 출력하지 않도록 설정.
    if (dir) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                printf("%c", map[i][j]);
            }
            width--;
            cout << "\n";
        }
    }
    else {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j <= y; j++) {
                printf("%c", map[i][j]);
            }
            y++;
            cout << "\n";
        }
    }

    return 0;
}