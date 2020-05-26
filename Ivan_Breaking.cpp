#include "TXLib.h"
#include "OreshkovLib.h"

void draw_dus();
void some_scene();

void draw_dust();
void some_scen2();
void draw_avto();
void draw_cloud(int x,int y, double scale, COLORREF color);

void some_text();

int main()
{
    some_scene();
    some_scen2();
    some_text();
    return 0;
}

void some_scene()
{
    int x,y,z;

    txCreateWindow(1200,800);
    x=-100;
    y=250;
    z=0;
    while (x<1500)
    {
        txClear();
        draw_dus();
        draw_sun((x-250)*0.3, y, 0,  0, 6, 1.0, RGB (255,204,51));
        draw_avtohouse(x, 450, 1, 1.0, RGB(255,255,204));
        draw_svet(500, 490, 1.1, z, RGB(102,102,102));
        y-=1;
        x+=10;
        if (x%300==0)
        {
            if (z==0)
            {
                z+=1;
            }
            else
            {
                z-=1;
            }
        }
        txSleep(18);
        txSetFillColor(TX_WHITE);
    }
}



void draw_dus()
{
    txSetFillColor(RGB (136,160,191));
    txSetColor(TX_BLACK,1);
    txClear();
    txSetFillColor(RGB (79,33,10));
    txRectangle(1300,500,-100,900);
}

void some_scen2()
{
    int x,y,z;
    x=-100;
    z=-100;
    while (x<400)
    {
        txClear();
        draw_dust();
        draw_avtohouse(x, 420, 1, 1.5, RGB(255,255,204));
        y-=1;
        x+=10;
        txSleep(18);
    }
    draw_cloud(180,400, 5,RGB(51,51,51));
    txSleep(800);
    while (x<1500)
    {
        txClear();
        draw_dust();
        draw_avto();
        draw_walter(x, 600, z,  0, -z, -10,   1.2, RGB(204,153,102));
        x+=4;
        z+=10;
        if(z==100)
        {
            z=-100;
        }
        txSleep(18);
        txSetFillColor(TX_WHITE);
    }
}

void draw_dust()
{
    txSetFillColor(RGB (136,160,191));
    txSetColor(TX_BLACK,1);
    txClear();

    txSetFillColor(RGB (92,61,42));
    POINT l[9] = {{0, 80}, {640, 120}, {720, 160},
    {1110, 120}, {1201, 180},
    {1200, 100}, {1200, 180}, {1600,470}, {0, 470}};
    txPolygon (l, 9);

    txSetFillColor(RGB (138,102,74));
    txRectangle(0,470,1600,800);

    txSetFillColor(RGB (79,33,10));
    POINT a[6] = {{1060, 800}, {1080, 700}, {1120, 680}, {1120, 600},
    {1200, 520}, {1200, 800}};
    txPolygon (a, 6);

    POINT q[7] = {{0,0}, {220, 0}, {640, 60}, {680, 140},
    {720, 160}, {640, 120}, {0, 80}};
    txPolygon (q, 7);

    txSetFillColor(RGB (38,30,22));
    POINT r[8] = {{720, 170}, {730, 130}, {960, 110}, {1110, 120},
    {1200, 100}, {1200, 180}, {1140, 210}, {860, 160}};
    txPolygon (r, 8);

    txSetFillColor(RGB(94,102,34));
    POINT e[7] = {{570, 500}, {570, 530}, {640, 540}, {690, 510},
    {650, 450}, {640, 480}, {610, 480}};
    txPolygon (e, 7);
}

void draw_avto()
{
    txSetFillColor(RGB (255,255,204));
    POINT i[18] = {{440, 540}, {360, 550}, {240, 540}, {240, 380},
    {280, 200}, {140, 160}, {160, 140}, {460, 240}, {470, 230},
    {550, 260}, {560, 280}, {640, 320}, {640, 420}, {650, 450},
    {650, 520}, {480, 530}, {480, 480}, {460, 480}};
    txPolygon (i, 18);

    txSetFillColor(RGB (70,62,44));
    POINT w[4] = {{290, 270}, {400, 290}, {390, 375}, {280, 360}};
    txPolygon (w, 4);
    POINT t[4] = {{540, 330}, {565, 340}, {555, 380}, {530, 370}};
    txPolygon (t, 4);

    txSetFillColor(RGB (44,39,38));
    POINT n[6] = {{240, 540}, {240, 380},{280, 200}, {140, 160},
    {100, 320}, {100, 460}};
    txPolygon (n, 6);

    txSetFillColor(RGB (3,4,15));
    POINT k[4] = {{130, 300}, {150, 210}, {250, 240}, {220, 330}};
    txPolygon (k, 4);

    txSetFillColor(RGB (128,105,66));
    POINT y[4] = {{570, 340}, {610, 350}, {585, 510}, {540, 510}};
    txPolygon (y, 4);

    txSetFillColor(RGB (1,1,3));
    POINT j[12] = {{650, 520}, {480, 530}, {480, 480}, {460, 480},
    {440, 540}, {360, 550}, {240, 540}, {100, 420}, {60,410}, {0,430},
    {0,620}, {120,660}};
    txPolygon (j, 12);

    txSetFillColor(RGB(76,65,66));
    POINT f[8] = {{470, 490}, {476, 510}, {478, 525}, {476, 540},
    {460, 558}, {455, 550}, {450, 530}, {455, 510}};
    txPolygon (f, 8);

    txSetFillColor(RGB(94,102,34));
    POINT e[7] = {{570, 500}, {570, 530}, {640, 540}, {690, 510},
    {650, 450}, {640, 480}, {610, 480}};
    txPolygon (e, 7);
}

void draw_cloud(int x,int y, double scale, COLORREF color)
{
    txSetColor(color);
    txSetFillColor(color);
    txCircle(x,y,70*scale);
    txCircle(x+90*scale,y,75*scale);
    txCircle(x+155*scale,y,40*scale);
}


void some_text()
{
    int x;
    x=3;

    txPlaySound("BreakingBad.wav", SND_ASYNC);
    while(x>1)
    {
        txSetFillColor(TX_WHITE);
        txSetFillColor(RGB(19,36,2));
        txClear();
        txSetColor  (RGB(227,255,233),3);
        txSetFillColor(RGB(52,124,74));
        txRectangle (430,410,630,610);
        txSelectFont("Arial Black", 190);
        txDrawText  (430, 420, 630, 620, "Ba");
        txRectangle (230,410,430,210);
        txSelectFont("Arial Black", 190);
        txDrawText  (230,420,430,220, "Br");
        x=-1;
        txSleep(1500);
    }

    txSetColor(RGB(249,255,243));
    txSelectFont("Comic Sans MS", 200);
    txDrawText  (400, 220, 910, 420, "eaking");
    txDrawText  (385, 440, 985, 600, "d");
    x+=10;
    txSleep(700);
    txSetFillColor(RGB(19,36,2));
    txClear();
    txSelectFont("Comic Sans MS", 50);
    txDrawText  (200, 200, 910, 420, "Created by");
    txDrawText  (240, 380, 985, 430, "Иван Оrешков");
}
