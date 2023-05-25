#include <iostream>
#include <easyx.h>
#include <stdlib.h>
#include <conio.h>
#include<stdbool.h>
#include <graphics.h>
using namespace std;
#define Row 10
#define Col 10
#define SPACE 0
#define WALL 1
#define DEST 2
#define BOX 3
#define PLAYER 4
void Showmap(int map[Row][Col]);
void pushmap(int map[][Col]);
bool ispass(int map[][Col]);
void loadResource();
IMAGE imgs[6];

int main()
{
    initgraph(640, 640);
    loadResource();

    int map[3][Row][Col] =
    {
      {
       {0,0,0,0,0,0,0,0,0,0},
       {0,0,0,1,1,1,0,0,0,0},
       {0,0,0,1,2,1,0,0,0,0},
       {0,0,0,1,0,1,1,1,1,0},
       {0,1,1,1,3,3,0,2,1,0},
       {0,1,2,3,4,0,1,1,1,0},
       {0,1,1,1,1,3,1,0,0,0},
       {0,0,0,0,1,2,1,0,0,0},
       {0,0,0,0,1,1,1,0,0,0},
       {0,0,0,0,0,0,0,0,0,0},
      },
      {
       {0,0,0,0,1,1,1,0,0,0},
       {0,0,0,1,2,0,0,1,0,0},
       {0,0,1,0,0,3,0,0,1,0},
       {0,1,0,3,0,0,0,0,0,1},
       {1,2,0,0,4,0,0,2,1,0},
       {0,1,0,0,0,3,0,1,0,0},
       {0,0,1,0,3,0,1,0,0,0},
       {0,0,0,1,0,1,0,0,0,0},
       {0,0,0,1,2,1,0,0,0,0},
       {0,0,0,1,1,1,0,0,0,0},
      },
      {
       {0,0,0,0,0,0,0,0,0,0},
       {0,0,1,1,0,0,1,1,0,0},
       {0,1,2,0,1,1,0,2,1,0},
       {1,0,0,0,0,0,0,0,0,1},
       {1,0,3,0,0,4,3,0,0,1},
       {0,1,0,0,0,0,0,0,1,0},
       {0,0,1,0,0,3,0,1,0,0},
       {0,0,0,1,0,2,1,0,0,0},
       {0,0,0,0,1,1,0,0,0,0},
       {0,0,0,0,0,0,0,0,0,0},
      },
    };
    int level = 0;
    while (true) {
        Showmap(map[level]);
        if (ispass(map[level])) {
            level++;
            if (level >= 3) {
                cout << "恭喜你，通关了";
                break;
            }
            cout << "恭喜你，过关了!" << endl << "点击任意键，进入下一关" << endl;
        }

        pushmap(map[level]);
        system("cls");
    }
    return 0;
}
void Showmap(int map[][Col])
{
    for (int r = 0; r < Row; r++)
    {
        for (int c = 0; c < Col; c++) {
            switch (map[r][c])
            {
            case SPACE:
                cout << "  ";
                break;
            case WALL:
                cout << "■ ";
                break;
            case DEST:
                cout << "☆ ";
                break;
            case BOX:
                cout << "□ ";
                break;
            case PLAYER:
                cout << "♂ ";
                break;
            case DEST + BOX:
                cout << "★ ";
                break;
            case DEST + PLAYER:
                cout << "♂ ";
                break;
            default:
                break;
            }
        }
        cout << endl;
    }

}
void pushmap(int map[][Col])
{
    int r = -1;
    int c = -1;
    for (int i = 0; i < Row; i++) {
        for (int k = 0; k < Col; k++) {
            if (map[i][k] == PLAYER || map[i][k] == DEST + PLAYER) {
                r = i;
                c = k;
                goto doneloop;
            }
        }
    }
doneloop:

    switch (_getch())
    {
    case'W':
    case'w':
    case 72:
        if (map[r - 1][c] == SPACE || map[r - 1][c] == DEST) {
            map[r - 1][c] += PLAYER;
            map[r][c] -= PLAYER;
        }
        else if (map[r - 1][c] == BOX || map[r - 1][c] == BOX + DEST) {
            if (map[r - 2][c] == SPACE || map[r - 2][c] == DEST) {
                map[r - 2][c] += BOX;
                map[r - 1][c] -= BOX;
                map[r - 1][c] += PLAYER;
                map[r][c] -= PLAYER;
            }
        }break;
    case'S':
    case's':
    case 80:
        if (map[r + 1][c] == SPACE || map[r + 1][c] == DEST) {
            map[r + 1][c] += PLAYER;
            map[r][c] -= PLAYER;
        }
        else if (map[r + 1][c] == BOX || map[r + 1][c] == BOX + DEST) {
            if (map[r + 2][c] == SPACE || map[r + 2][c] == DEST) {
                map[r + 2][c] += BOX;
                map[r + 1][c] -= BOX;
                map[r + 1][c] += PLAYER;
                map[r][c] -= PLAYER;
            }
        } break;
    case'A':
    case'a':
    case 75:
        if (map[r][c - 1] == SPACE || map[r][c - 1] == DEST) {
            map[r][c - 1] += PLAYER;
            map[r][c] -= PLAYER;
        }
        else if (map[r][c - 1] == BOX || map[r][c - 1] == BOX + DEST) {
            if (map[r][c - 2] == SPACE || map[r][c - 2] == DEST) {
                map[r][c - 2] += BOX;
                map[r][c - 1] -= BOX;
                map[r][c - 1] += PLAYER;
                map[r][c] -= PLAYER;
            }
        }
        break;
    case'D':
    case'd':
    case 77:
        if (map[r][c + 1] == SPACE || map[r][c + 1] == DEST) {
            map[r][c + 1] += PLAYER;
            map[r][c] -= PLAYER;
        }
        else if (map[r][c + 1] == BOX || map[r][c + 1] == BOX + DEST) {
            if (map[r][c + 2] == SPACE || map[r][c + 2] == DEST) {
                map[r][c + 2] += BOX;
                map[r][c + 1] -= BOX;
                map[r][c + 1] += PLAYER;
                map[r][c] -= PLAYER;
            }
        }
        break;
    default:
        break;
    }
}
bool ispass(int map[][Col]) {
    for (int i = 0; i < Row; i++) {
        for (int k = 0; k < Col; k++) {
            if (map[i][k] == BOX) {
                return false;
            }
        }
    }
    return true;
}
void loadResource() {
    BeginBatchDraw();
    IMAGE img;
    loadimage(&img, _T("./image/0.jpg"));
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    HDC hdcSrc = GetImageHDC(&img);
    HDC hdcDst = CreateCompatibleDC(hdcSrc);
    HBITMAP hBitmap = CreateCompatibleBitmap(hdcSrc, screenWidth, screenHeight);
    SelectObject(hdcDst, hBitmap);
    StretchBlt(hdcDst, 0, 0, screenWidth, screenHeight, hdcSrc, 0, 0, img.getwidth(), img.getheight(), SRCCOPY);
    IMAGE imgScaled(screenWidth, screenHeight);
    BitBlt(GetImageHDC(&imgScaled), 0, 0, screenWidth, screenHeight, hdcDst, 0, 0, SRCCOPY);
    putimage(0, 0, &imgScaled);
    DeleteDC(hdcDst);
    DeleteObject(hBitmap);
    FlushBatchDraw();
    EndBatchDraw();
}





