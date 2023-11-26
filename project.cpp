#include "iGraphics.h"

int mode = 0, i, n, check, lenu, lenp, x=50, dy = 25, ddx = 5, ddy = 5;
int ly = 450, rx = 200, ry = 450, ldx = 70, rdx = 90;
int dx = 250, uy = 355, py = 250, sy = 200, sdx = 80;
char str[25], stru[25], strp[25], buffu[25], buffp[25], sn1[3], sn2[3], sn3[3];
FILE *fpp, *fpi, *fpd;
char *db1 = "username.txt";
char *db2 = "password.txt";
char *db3 = "data.txt";
bool rh[5];
time_t ts;

long int j;
int sys, show, n1, n2, t1, t2, math, d[7];
char res[11][40] = {"pictures/nursery/math/0.bmp", "pictures/nursery/math/1.bmp", "pictures/nursery/math/2.bmp",
			"pictures/nursery/math/3.bmp", "pictures/nursery/math/4.bmp", "pictures/nursery/math/5.bmp",
			"pictures/nursery/math/6.bmp", "pictures/nursery/math/7.bmp", "pictures/nursery/math/8.bmp",
			"pictures/nursery/math/9.bmp", "pictures/nursery/math/10.bmp"};

char dig[10][40] = {"pictures/kg/math/0.bmp", "pictures/kg/math/1.bmp", "pictures/kg/math/2.bmp",
			"pictures/kg/math/3.bmp", "pictures/kg/math/4.bmp", "pictures/kg/math/5.bmp",
			"pictures/kg/math/6.bmp", "pictures/kg/math/7.bmp", "pictures/kg/math/8.bmp",
			"pictures/kg/math/9.bmp"};


//	function iDraw() is called again and again by the system.
void iDraw()
{
//	void iText(GLdouble x, GLdouble y, char *str, void* font=GLUT_BITMAP_8_BY_13)
//	Description: Displays a string on screen.
//	Parameters: x, y- coordinates of the first character of the string,
//				str- The string to show,
//				font- (Optional)Specifies the font type.
//	FONT values must be any one of the following-
//	{GLUT_BITMAP_HELVETICA_10, GLUT_BITMAP_8_BY_13, GLUT_BITMAP_TIMES_ROMAN_10,
//	 GLUT_BITMAP_HELVETICA_12, GLUT_BITMAP_9_BY_15, GLUT_BITMAP_TIMES_ROMAN_24,
//	 GLUT_BITMAP_HELVETICA_18}

    //place your drawing codes here

    iClear();

    if(mode <= 0)
    {
        iShowBMP(0, 0, "pictures/cover.bmp");
		iSetColor(150, 150, 150);
		iFilledRectangle(x, ly, ldx, dy);
		iFilledRectangle(rx, ry, rdx, dy);
        iSetColor(0,0,255);
        iRectangle(x, ly, ldx, dy);
        iText(x + ddx, ly + ddy, "Login", GLUT_BITMAP_TIMES_ROMAN_24);
        iRectangle(rx, ry, rdx, dy);
        iText(rx + ddx, ry + ddy, "Register", GLUT_BITMAP_TIMES_ROMAN_24);

        if(mode <= -1 && mode >= -5)
        {
            iText(x + 50, uy + 65, "Login:", GLUT_BITMAP_TIMES_ROMAN_24);
            iText(x, uy + 30,"Enter username:", GLUT_BITMAP_TIMES_ROMAN_24);
            iRectangle(x, uy, dx, dy);
            iText(x + ddx, uy + ddy, stru, GLUT_BITMAP_TIMES_ROMAN_24);
            iText(x, py + 30,"Enter password:", GLUT_BITMAP_TIMES_ROMAN_24);
            iRectangle(x, py, dx, dy);
            iText(x + ddx, py + ddy, str, GLUT_BITMAP_TIMES_ROMAN_24);
            iRectangle(x, sy, sdx, dy);
            iText(x + ddx, sy + ddy, "submit", GLUT_BITMAP_TIMES_ROMAN_24);

			if(mode == -2) {
				iSetColor(0,255,0);
				iRectangle(x, uy, dx, dy);
			}
			if(mode == -4) {
				iSetColor(0,255,0);
				iRectangle(x, py, dx, dy);
			}
        }

        if(mode == -5)
        {
            if(check == 0)
            {
                fpd = fopen(db3, "r");
                fscanf(fpd, "%[^\n]", buffu);
                n = atoi(buffu);
                fclose(fpd);

                fpi = fopen(db1, "r");
                for(i = 1; i <= n; i++)
                {
                    //fscanf(fpi, "%[^\n]", buffu);
					//fread(buffu, 20, 1, fpi);
                    fgets(buffu, 20, fpi);
                    buffu[strlen(buffu) - 1] = 0;
                    if(!strcmp(stru, buffu))
                    {
                        check = 1;
                        break;
                    }
                }
                if(i > n) check = -1;
                fclose(fpi);
            }

            if(check == 1)
            {
                fpp = fopen(db2, "r");
                for( ; i > 0; i--)
                {
					//fscanf(fpp, "%[^\n]", buffp);
                    fgets(buffp, 20, fpp);
                    buffp[strlen(buffp) - 1] = 0;
                }
                fclose(fpp);
                if(strcmp(strp, buffp))
                {
                    check = -2;
                }
            }

            if(check == -1)
            {
				iSetColor(255,0,0);
				if(strlen(stru) == 0) {
					iText(x, uy + 50, "Username can't be empty.");
					if(strlen(strp) == 0) iText(x, py + 50, "Password can't be empty.");
				}
                else iText(x, uy + 50, "Username not found. Retry or Register.");
            }

            else if(check == -2)
            {
				iSetColor(255,0,0);
				if(strlen(strp) == 0) iText(x, py + 50, "Password can't be empty. Retry.");
                else iText(x, py + 50, "Password doesn't match. Retry.");
            }

            else mode = 1;
        }

        if(mode <= -10)
        {
            iText(x + 50, uy + 65, "Register:", GLUT_BITMAP_TIMES_ROMAN_24);
            iText(x, uy + 30,"Enter username:", GLUT_BITMAP_TIMES_ROMAN_24);
            iRectangle(x, uy, dx, dy);
            iText(x + ddx, uy + ddy, stru, GLUT_BITMAP_TIMES_ROMAN_24);
            iText(x, py + 30,"Enter password:", GLUT_BITMAP_TIMES_ROMAN_24);
            iRectangle(x, py, dx, dy);
            iText(x + ddx, py + ddy, str, GLUT_BITMAP_TIMES_ROMAN_24);
            iRectangle(x, sy, sdx, dy);
            iText(x + ddx, sy + ddy, "submit", GLUT_BITMAP_TIMES_ROMAN_24);
			if(mode == -12) {
				iSetColor(0,255,0);
				iRectangle(x, uy, dx, dy);
			}
			if(mode == -14) {
				iSetColor(0,255,0);
				iRectangle(x, py, dx, dy);
			}
        }

        if(mode == -15)
        {
            if(check == 0)
            {
                fpd = fopen(db3, "r");
                fscanf(fpd, "%[^\n]", buffu);
                n = atoi(buffu);
                fclose(fpd);

                fpi = fopen(db1, "r");
                for(i = 1; i <= n; i++)
                {
					//fscanf(fpi, "%[^\n]", buffu);
                    //fread(buffu, 20, 1, fpi);
                    fgets(buffu, 20, fpi);
                    buffu[strlen(buffu) - 1] = 0;
                    if(!strcmp(stru, buffu) || !strlen(stru) || !strlen(strp))
                    {
                        check = -1;
                        break;
                    }
                }
                if(i > n) check = 1;
                fclose(fpi);
            }

            if(check == 1)
            {
                fpi = fopen(db1, "a");
                fprintf(fpi, "%s\n", stru);
                fclose(fpi);
                fpp = fopen(db2, "a");
                fprintf(fpp, "%s\n", strp);
                fclose(fpp);

                fpd = fopen(db3, "w");
                fprintf(fpd, "%d", n + 1);
                fclose(fpd);
            }

            if(check == -1)
            {
				iSetColor(255,0,0);
				if(!strlen(stru)) iText(x, uy + 50, "Username can't be empty.");
                else if(strlen(strp)) iText(x, uy + 50, "Username in use. Try another one.");
				if(!strlen(strp)) iText(x, py + 50, "Password can't be empty.");
            }

            else mode = 1;
        }
    }

    else
    {
        if(mode==1)
        {
            iClear();
            iShowBMP(0, 0, "pictures/playorkg.bmp");
			iShowBMP(0, 0, "pictures/play.bmp");
			iShowBMP(350, 0, "pictures/nur.bmp");
			iShowBMP(700, 0, "pictures/kg.bmp");

			iSetColor(200, 200, 200);
			iFilledRectangle(950, 580, 90, 30);
			iSetColor(0, 0, 0);
			iText(955, 588, "Log out", GLUT_BITMAP_TIMES_ROMAN_24);
			iSetColor(200, 200, 200);
			iFilledRectangle(800, 580, 130, 30);
			iSetColor(0, 0, 0);
			iText(805, 588, "instructions", GLUT_BITMAP_TIMES_ROMAN_24);
        }
		else if(mode == 50)
        {
            iClear();
            iShowBMP(0, 0, "pictures/ins.bmp");
        }

        else if(mode == 100)
        {
            iClear();
            iShowBMP(0, 0, "pictures/play/play.bmp");
        }

        else if(mode == 200)
        {
            iClear();
            iShowBMP(0, 0, "pictures/nursery/nur.bmp");
        }
        else if(mode == 300)
        {
            iClear();
            iShowBMP(0, 0, "pictures/kg/kg.bmp");
        }

        else if(mode >= 1000 && mode < 2000)
        {

            if(mode == 1000)
            {
                iClear();
		iShowBMP(  0, 312, "pictures/play/color.bmp");
		iShowBMP(525, 312, "pictures/play/shape.bmp");
		iShowBMP(  0,   0, "pictures/play/digit.bmp");
		iShowBMP(525,   0, "pictures/play/alphabet.bmp");
            }
            else if(mode == 1101)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/color/white.bmp");
            }
            else if(mode == 1102)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/color/black.bmp");
            }
            else if(mode == 1103)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/color/red.bmp");
            }
            else if(mode == 1104)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/color/green.bmp");
            }
            else if(mode == 1105)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/color/blue.bmp");
            }
            else if(mode == 1106)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/color/yellow.bmp");
            }
			else if(mode == 1107)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/color/orange.bmp");
            }
			else if(mode == 1108)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/color/pink.bmp");
            }
			else if(mode == 1109)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/color/purple.bmp");
            }
			else if(mode == 1110)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/color/rainbow.bmp");
            }

            else if(mode == 1201)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/shape/circle.bmp");
            }
            else if(mode == 1202)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/shape/oval.bmp");
            }
            else if(mode == 1203)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/shape/triangle.bmp");
            }
            else if(mode == 1204)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/shape/rectangle.bmp");
            }
            else if(mode == 1205)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/shape/square.bmp");
            }
            else if(mode == 1206)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/shape/diamond.bmp");
            }
            else if(mode == 1207)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/shape/star.bmp");
            }
            else if(mode == 1208)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/shape/heart.bmp");
            }
            else if(mode == 1200)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/shape/all.bmp");
            }

            else if(mode == 1301)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/digit/1.bmp");
            }
            else if(mode == 1302)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/digit/2.bmp");
            }
            else if(mode == 1303)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/digit/3.bmp");
            }
            else if(mode == 1304)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/digit/4.bmp");
            }
            else if(mode == 1305)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/digit/5.bmp");
            }
            else if(mode == 1306)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/digit/6.bmp");
            }
            else if(mode == 1307)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/digit/7.bmp");
            }
            else if(mode == 1308)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/digit/8.bmp");
            }
            else if(mode == 1309)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/digit/9.bmp");
            }
            else if(mode == 1300)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/digit/0.bmp");
            }
            else if(mode == 1401)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/a.bmp");
            }
            else if(mode == 1402)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/b.bmp");
            }
            else if(mode == 1403)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/c.bmp");
            }
            else if(mode == 1404)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/d.bmp");
            }
            else if(mode == 1405)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/e.bmp");
            }
            else if(mode == 1406)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/f.bmp");
            }
            else if(mode == 1407)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/g.bmp");
            }
            else if(mode == 1408)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/h.bmp");
            }
            else if(mode == 1409)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/i.bmp");
            }
            else if(mode == 1410)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/j.bmp");
            }
            else if(mode == 1411)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/k.bmp");
            }
            else if(mode == 1412)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/l.bmp");
            }
            else if(mode == 1413)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/m.bmp");
            }
            else if(mode == 1414)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/n.bmp");
            }
            else if(mode == 1415)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/o.bmp");
            }
            else if(mode == 1416)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/p.bmp");
            }
            else if(mode == 1417)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/q.bmp");
            }
            else if(mode == 1418)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/r.bmp");
            }
            else if(mode == 1419)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/s.bmp");
            }
            else if(mode == 1420)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/t.bmp");
            }
            else if(mode == 1421)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/u.bmp");
            }
            else if(mode == 1422)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/v.bmp");
            }
            else if(mode == 1423)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/w.bmp");
            }
            else if(mode == 1424)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/x.bmp");
            }
            else if(mode == 1425)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/y.bmp");
            }
            else if(mode == 1426)
            {
                iClear();
                iShowBMP(0, 0, "pictures/play/alpha/z.bmp");
            }
        }

        else if(mode >= 2000 && mode < 3000)
        {
			if(mode == 2000)
            {
                iClear();
				iShowBMP(  0, 312, "pictures/nursery/counting.bmp");
				iShowBMP(525, 312, "pictures/nursery/words.bmp");
				iShowBMP(  0,   0, "pictures/nursery/math.bmp");
				iShowBMP(525,   0, "pictures/nursery/rhyme.bmp");
            }
            else if(mode == 2100)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/count/0.bmp");
			}
			else if(mode == 2101)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/count/1.bmp");
			}
			else if(mode == 2102)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/count/2.bmp");
			}
			else if(mode == 2103)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/count/3.bmp");
			}
			else if(mode == 2104)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/count/4.bmp");
			}
			else if(mode == 2105)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/count/5.bmp");
			}
			else if(mode == 2106)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/count/6.bmp");
			}
			else if(mode == 2107)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/count/7.bmp");
			}
			else if(mode == 2108)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/count/8.bmp");
			}
			else if(mode == 2109)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/count/9.bmp");
			}
			else if(mode == 2110)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/count/10.bmp");
			}

			else if(mode == 2301)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/a.bmp");
			}
			else if(mode == 2302)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/b.bmp");
			}
			else if(mode == 2303)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/c.bmp");
			}
			else if(mode == 2304)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/d.bmp");
			}
			else if(mode == 2305)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/e.bmp");
			}
			else if(mode == 2306)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/f.bmp");
			}
			else if(mode == 2307)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/g.bmp");
			}
			else if(mode == 2308)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/h.bmp");
			}
			else if(mode == 2309)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/i.bmp");
			}
			else if(mode == 2310)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/j.bmp");
			}
			else if(mode == 2311)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/k.bmp");
			}
			else if(mode == 2312)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/l.bmp");
			}
			else if(mode == 2313)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/m.bmp");
			}
			else if(mode == 2314)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/n.bmp");
			}
			else if(mode == 2315)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/o.bmp");
			}
			else if(mode == 2316)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/p.bmp");
			}
			else if(mode == 2317)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/q.bmp");
			}
			else if(mode == 2318)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/r.bmp");
			}
			else if(mode == 2319)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/s.bmp");
			}
			else if(mode == 2320)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/t.bmp");
			}
			else if(mode == 2321)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/u.bmp");
			}
			else if(mode == 2322)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/v.bmp");
			}
			else if(mode == 2323)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/w.bmp");
			}
			else if(mode == 2324)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/x.bmp");
			}
			else if(mode == 2325)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/y.bmp");
			}
			else if(mode == 2326)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/word/z.bmp");
			}

			else if(mode == 2499) {
				iClear();
				iShowBMP(  0, 0, "pictures/nursery/math/plus_big.bmp");
				iShowBMP(525, 0, "pictures/nursery/math/minus_big.bmp");
			}

			else if(mode == 2400)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/math/mathback.bmp");
				iShowBMP(150, 300, res[n1]);
				iShowBMP(450, 300, res[n2]);
				iShowBMP(600, 300, "pictures/nursery/math/equal.bmp");
				if(sys == 0) iShowBMP(300, 300, "pictures/nursery/math/plus.bmp");
				else if(sys == 1) iShowBMP(300, 300, "pictures/nursery/math/minus.bmp");
				if(sys == 0 && show == 1 && n1 + n2 < 11) iShowBMP(750, 300, res[n1 + n2]);
				else if(sys == 1 && show == 1 && n1 - n2 >= 0) iShowBMP(750, 300, res[n1 - n2]);
			}
			else if(mode == 2410)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/math/mathback.bmp");
				iShowBMP(150, 400, res[n1]);
				//iShowBMP(450, 300, res[n2]);
				if(sys == 0) for(i = 0; i < 11 - n2; i++) {
					iShowBMP(50 + (i % 6) * 160, 240 - (i / 6) * 160, res[i]);
				}
				else if(sys == 1) for(i = n2; i < 11; i++) {
					iShowBMP(50 + (i % 6) * 160, 240 - (i / 6) * 160, res[i]);
				}
			}
			else if(mode == 2420)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/math/mathback.bmp");
				//iShowBMP(150, 300, res[n1]);
				iShowBMP(450, 400, res[n2]);
				if(sys == 0) for(i = 0; i < 11 - n1; i++) {
					iShowBMP(50 + (i % 6) * 160, 240 - (i / 6) * 160, res[i]);
				}
				else if(sys == 1) for(i = 0; i <= n1; i++) {
					iShowBMP(50 + (i % 6) * 160, 240 - (i / 6) * 160, res[i]);
				}
			}

			else if(mode == 2500)
			{
				iClear();
				iShowBMP(  0, 312, "pictures/nursery/rhymes/rh1.bmp");
				iShowBMP(525, 312, "pictures/nursery/rhymes/rh2.bmp");
				iShowBMP(  0,   0, "pictures/nursery/rhymes/rh3.bmp");
				iShowBMP(525,   0, "pictures/nursery/rhymes/rh4.bmp");
			}

			else if(mode == 2510)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh1/0.bmp");
				rh[1] = true;
				
				if(time(NULL) - ts == 2) {
					mode = 2511;
					if(rh[1]) {
						PlaySound("music/nursery/rhymes/rh1.wav", NULL, SND_ASYNC);
					}
				}
			}

			else if(mode == 2511)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh1/1.bmp");
				if(time(NULL) - ts == 8) mode = 2512;
			}
			else if(mode == 2512)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh1/2.bmp");
				if(time(NULL) - ts == 13) mode = 2513;
			}
			else if(mode == 2513)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh1/3.bmp");
				if(time(NULL) - ts == 19) mode = 2514;
			}
			else if(mode == 2514)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh1/4.bmp");
				if(time(NULL) - ts == 24) {
					rh[1] = false;
					mode = 2500;
				}
			}

			else if(mode == 2530)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh2/0.bmp");
				
				if(time(NULL) - ts == 2) {
					rh[2] = true;
					mode = 2531;
					if(rh[2]) {
						PlaySound("music/nursery/rhymes/rh2.wav", NULL, SND_ASYNC);
					}
				}
			}
			else if(mode == 2531)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh2/1.bmp");
				if(time(NULL) - ts == 4) mode = 2532;	
			}
			else if(mode == 2532)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh2/2.bmp");
				if(time(NULL) - ts == 5) mode = 2533;
			}
			else if(mode == 2533)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh2/3.bmp");
				if(time(NULL) - ts == 7) mode = 2534;
			}
			else if(mode == 2534)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh2/4.bmp");
				if(time(NULL) - ts == 8) mode = 2535;
			}
			else if(mode == 2535)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh2/5.bmp");
				if(time(NULL) - ts == 10) mode = 2536;
			}
			else if(mode == 2536)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh2/6.bmp");
				if(time(NULL) - ts == 12) mode = 2537;
			}
			else if(mode == 2537)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh2/7.bmp");
				if(time(NULL) - ts == 13) mode = 2538;
			}
			else if(mode == 2538)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh2/8.bmp");
				if(time(NULL) - ts == 15) mode = 2539;
			}
			else if(mode == 2539)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh2/9.bmp");
				if(time(NULL) - ts == 16) {
					rh[2] = false;
					mode = 2500;
				}
			}

			else if(mode == 2550)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh3/0.bmp");

				if(time(NULL) - ts == 2) {
					rh[3] = true;
					mode = 2551;
					if(rh[3]) {
						PlaySound("music/nursery/rhymes/rh3.wav", NULL, SND_ASYNC);
					}
				}
			}
			else if(mode == 2551)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh3/1.bmp");
				if(time(NULL) - ts == 4) mode = 2552;
			}
			else if(mode == 2552)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh3/2.bmp");
				if(time(NULL) - ts == 7) mode = 2553;
			}
			else if(mode == 2553)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh3/3.bmp");
				if(time(NULL) - ts == 9) mode = 2554;
			}
			else if(mode == 2554)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh3/4.bmp");
				if(time(NULL) - ts == 11) mode = 2555;
			}
			else if(mode == 2555)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh3/5.bmp");
				if(time(NULL) - ts == 13) mode = 2556;
			}
			else if(mode == 2556)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh3/6.bmp");
				if(time(NULL) - ts == 16) mode = 2557;
			}
			else if(mode == 2557)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh3/7.bmp");
				if(time(NULL) - ts == 18) mode = 2558;
			}
			else if(mode == 2558)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh3/8.bmp");
				if(time(NULL) - ts == 21) mode = 2559;
			}
			else if(mode == 2559)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh3/9.bmp");
				if(time(NULL) - ts == 22) {
					rh[3] = false;
					mode = 2500;
				}
			}

			else if(mode == 2570)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh4/0.bmp");
				if(time(NULL) - ts == 2) {
					rh[4] = true;
					mode = 2571;
					if(rh[4]) {
						PlaySound("music/nursery/rhymes/rh4.wav", NULL, SND_ASYNC);
					}
				}
			}
			else if(mode == 2571)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh4/1.bmp");
				if(time(NULL) - ts == 8) mode = 2572;
			}
			else if(mode == 2572)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh4/2.bmp");
				if(time(NULL) - ts == 15) mode = 2573;
			}
			else if(mode == 2573)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh4/3.bmp");
				if(time(NULL) - ts == 22) mode = 2574;
			}
			else if(mode == 2574)
			{
				iClear();
				iShowBMP(0, 0, "pictures/nursery/rhymes/rh4/4.bmp");
				if(time(NULL) - ts == 29) {
					rh[4] = false;
					mode = 2500;
				}
			}
        }

        else if(mode >= 3000 && mode < 4000)
        {
			if(mode == 3000)
            {
                iClear();
				iShowBMP(  0, 0, "pictures/kg/number.bmp");
				iShowBMP(0, 312, "pictures/kg/body.bmp");
				iShowBMP(525,   0, "pictures/kg/math/math.bmp");
				//iShowBMP(525,   0, "pictures/kg/others.bmp");
            }

			else if(mode == 3101) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/you/face.bmp");
			}
			else if(mode == 3102) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/you/eyes.bmp");
			}
			else if(mode == 3103) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/you/ear.bmp");
			}
			else if(mode == 3104) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/you/nose.bmp");
			}
			else if(mode == 3105) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/you/hand.bmp");
			}
			else if(mode == 3106) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/you/leg.bmp");
			}
			else if(mode == 3107) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/you/knee.bmp");
			}
			else if(mode == 3108) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/you/throat.bmp");
			}
			else if(mode == 3109) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/you/wrist.bmp");
			}

			else if(mode == 3299) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/numbers/number.bmp");
				iShowBMP(525, 0, "pictures/kg/multichart/multichart.bmp");
			}

			else if(mode == 3201) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/numbers/1to10.bmp");
			}
			else if(mode == 3202) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/numbers/11to20.bmp");
			}
			else if(mode == 3203) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/numbers/21to30.bmp");
			}
			else if(mode == 3204) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/numbers/31to40.bmp");
			}
			else if(mode == 3205) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/numbers/41to50.bmp");
			}
			else if(mode == 3206) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/numbers/51to60.bmp");
			}
			else if(mode == 3207) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/numbers/61to70.bmp");
			}
			else if(mode == 3208) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/numbers/71to80.bmp");
			}
			else if(mode == 3209) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/numbers/81to90.bmp");
			}
			else if(mode == 3210) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/numbers/91to100.bmp");
			}

			else if(mode == 3301) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/multichart/tt1.bmp");
			}
			else if(mode == 3302) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/multichart/tt2.bmp");
			}
			else if(mode == 3303) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/multichart/tt3.bmp");
			}
			else if(mode == 3304) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/multichart/tt4.bmp");
			}
			else if(mode == 3305) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/multichart/tt5.bmp");
			}
			else if(mode == 3306) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/multichart/tt6.bmp");
			}
			else if(mode == 3307) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/multichart/tt7.bmp");
			}
			else if(mode == 3308) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/multichart/tt8.bmp");
			}
			else if(mode == 3309) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/multichart/tt9.bmp");
			}
			else if(mode == 3310) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/multichart/tt10.bmp");
			}
			else if(mode == 3311) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/multichart/tt11.bmp");
			}
			else if(mode == 3312) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/multichart/tt12.bmp");
			}

			else if(mode == 3400) {
				iClear();
				iShowBMP(  0, 312, "pictures/kg/math/plus_big.bmp");
				iShowBMP(525, 312, "pictures/kg/math/minus_big.bmp");
				iShowBMP(  0,   0, "pictures/kg/math/multi_big.bmp");
				iShowBMP(525,   0, "pictures/kg/math/div_big.bmp");
			}

			else if(mode == 3410) {
				iClear();
				iShowBMP(0, 0, "pictures/nursery/math/mathback.bmp");
				iShowBMP(300, 224, "pictures/kg/math/plus.bmp");
				iSetColor(0, 0, 0);
				iFilledRectangle(300, 205, 600, 14);
				iShowBMP(500, 424, dig[d[1]]);
				iShowBMP(700, 424, dig[d[0]]);
				iShowBMP(500, 224, dig[d[3]]);
				iShowBMP(700, 224, dig[d[2]]);
				iShowBMP(700, 0, dig[(d[0] + d[2]) % 10]);
				t1 = (d[0] + d[2]) / 10;
				iShowBMP(500, 0, dig[(d[1] + d[3] + t1) % 10]);
				t2 = (d[1] + d[3] + t1) / 10;
				if(t2) iShowBMP(300, 0, dig[t2]);
			}

			else if(mode == 3411) {
				iClear();
				iShowBMP(0, 0, "pictures/nursery/math/mathback.bmp");
				for(i = 0; i < 10; i++) {
					iShowBMP(5 + (i % 5) * 210, 350 - (i / 5) * 250, dig[i]);
				}
			}

			else if(mode == 3420) {
				iClear();
				iShowBMP(0, 0, "pictures/nursery/math/mathback.bmp");
				iShowBMP(300, 224, "pictures/kg/math/minus.bmp");
				iSetColor(0, 0, 0);
				iFilledRectangle(300, 205, 600, 14);
				iShowBMP(500, 424, dig[d[1]]);
				iShowBMP(700, 424, dig[d[0]]);
				iShowBMP(500, 224, dig[d[3]]);
				iShowBMP(700, 224, dig[d[2]]);
				iShowBMP(700, 0, dig[(d[0] + 10 - d[2]) % 10]);
				
				if(d[0] >= d[2]) iShowBMP(500, 0, dig[d[1] - d[3]]);
				else if(d[0] < d[2]) iShowBMP(500, 0, dig[d[1] - d[3] - 1]);
			}
			else if(mode == 3421) {
				iClear();
				iShowBMP(0, 0, "pictures/nursery/math/mathback.bmp");
				for(i = 0; i < 10; i++) {
					if(d[1] * 10 + i >= d[3] * 10 + d[2]) {
						iShowBMP(5 + (i % 5) * 210, 350 - (i / 5) * 250, dig[i]);
					}
				}
			}
			else if(mode == 3422) {
				iClear();
				iShowBMP(0, 0, "pictures/nursery/math/mathback.bmp");
				for(i = 0; i < 10; i++) {
					if(i * 10 + d[0] >= d[3] * 10 + d[2]) {
						iShowBMP(5 + (i % 5) * 210, 350 - (i / 5) * 250, dig[i]);
					}
				}
			}
			else if(mode == 3423) {
				iClear();
				iShowBMP(0, 0, "pictures/nursery/math/mathback.bmp");
				for(i = 0; i < 10; i++) {
					if(d[1] * 10 + d[0] >= d[3] * 10 + i) {
						iShowBMP(5 + (i % 5) * 210, 350 - (i / 5) * 250, dig[i]);
					}
				}
			}
			else if(mode == 3424) {
				iClear();
				iShowBMP(0, 0, "pictures/nursery/math/mathback.bmp");
				for(i = 0; i < 10; i++) {
					if(d[1] * 10 + d[0] >= i * 10 + d[2]) {
						iShowBMP(5 + (i % 5) * 210, 350 - (i / 5) * 250, dig[i]);
					}
				}
			}

			else if(mode == 3430) {
				iClear();
				iShowBMP(0, 0, "pictures/nursery/math/mathback.bmp");
				iShowBMP(500, 224, "pictures/kg/math/multi.bmp");
				iSetColor(0, 0, 0);
				iFilledRectangle(300, 205, 600, 14);
				iShowBMP(700, 424, dig[d[0]]);
				iShowBMP(500, 424, dig[d[1]]);
				iShowBMP(700, 224, dig[d[2]]);
				iShowBMP(700, 0, dig[(d[0] * d[2]) % 10]);
				t1 = (d[1] * d[2]) + (d[0] * d[2]) / 10;
				iShowBMP(500, 0, dig[t1 % 10]);
				t2 = t1 / 10;
				if(t2) iShowBMP(300, 0, dig[t2]);
			}
			else if(mode == 3431) {
				iClear();
				iShowBMP(0, 0, "pictures/nursery/math/mathback.bmp");
				for(i = 0; i < 10; i++) {
					iShowBMP(5 + (i % 5) * 210, 350 - (i / 5) * 250, dig[i]);
				}
			}

			else if(mode == 3440) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/math/divback.bmp");
				//iShowBMP(500, 224, "pictures/kg/math/div.bmp");
				iSetColor(0, 0, 0);
				t1 = (d[1] * 10 + d[0]) / d[5];
				t2 = (d[1] * 10 + d[0]) - (d[5] * t1);

				iFilledRectangle(225, 205, 400,   5);
				iFilledRectangle(210, 224,   5, 400);
				iFilledRectangle(635, 224,   5, 400);
				iShowBMP(425, 424, dig[d[0]]);
				iShowBMP(225, 424, dig[d[1]]);
				iShowBMP(  0, 424, dig[d[5]]);
				if(t1 / 10) iShowBMP(650, 424, dig[t1 / 10]);
				if(t1 / 10) iShowBMP(850, 424, dig[t1 % 10]);
				else iShowBMP(650, 424, dig[t1 % 10]);
				iShowBMP(425, 215, dig[(d[5] * t1) % 10]);
				if((d[5] * t1) / 10) iShowBMP(225, 215, dig[(d[5] * t1) / 10]);
				iShowBMP(425,   0, dig[t2 % 10]);
			}
			else if(mode == 3441) {
				iClear();
				iShowBMP(0, 0, "pictures/nursery/math/mathback.bmp");
				for(i = 0; i < 10; i++) {
					iShowBMP(5 + (i % 5) * 210, 350 - (i / 5) * 250, dig[i]);
				}
			}
			else if(mode == 3442) {
				iClear();
				iShowBMP(0, 0, "pictures/nursery/math/mathback.bmp");
				for(i = 0; i < 10; i++) {
					iShowBMP(5 + (i % 5) * 210, 350 - (i / 5) * 250, dig[i]);
				}
			}
			else if(mode == 3443) {
				iClear();
				iShowBMP(0, 0, "pictures/nursery/math/mathback.bmp");
				for(i = 1; i < 10; i++) {
					iShowBMP(5 + (i % 5) * 210, 350 - (i / 5) * 250, dig[i]);
				}
			}

			else if(mode == 3500) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/misc/days.bmp");
				iShowBMP(525, 0, "pictures/kg/misc/months.bmp");
			}
			else if(mode == 3501) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/misc/daymon.bmp");
			}
			else if(mode == 3502) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/misc/num10.bmp");
			}
			else if(mode == 3503) {
				iClear();
				iShowBMP(0, 0, "pictures/kg/misc/num10.bmp");
			}
        }
    }
}


//	function iMouseMove() is called when the user presses and drags the mouse.
//	(mx, my) is the position where the mouse pointer is.
void iMouseMove(int mx, int my)
{
    //place your codes here

}


//	function iMouse() is called when the user presses/releases the mouse.
//	(mx, my) is the position where the mouse pointer is.
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(mode <= 0)
        {
            if(mx >= x && mx <= (x + ldx) && my >= ly && my <= (ly + dy) && mode <= 0)
            {
                mode = -1;
            }

            else if(mx >= rx && mx <= (rx + rdx) && my >= ry && my <= (ry + dy) && mode <= 0)
            {
                mode = -10;
            }

            else if(mx >= x && mx <= (x + dx) && my >= uy && my <= (uy + dy) && mode <= -1 && mode >= -5)
            {
                mode = -2;
            }
            else if(mx >= x && mx <= (x + dx) && my >= py && my <= (py + dy) && mode <= -1 && mode >= -5)
            {
                mode = -4;
            }
            else if(mx >= x && mx <= (x + sdx) && my >= sy && my <= (sy + dy) && mode < 0 && mode > -10)
            {
                mode = -5;
                check = 0;
            }

            else if(mx >= x && mx <= (x + dx) && my >= uy && my <= (uy + dy) && mode <= -10)
            {
                mode = -12;
            }
            else if(mx >= x && mx <= (x + dx) && my >= py && my <= (py + dy) && mode <= -10)
            {
                mode = -14;
            }
            else if(mx >= x && mx <= (x + sdx) && my >= sy && my <= (sy + dy) && mode < -10)
            {
                mode = -15;
                check = 0;
            }
        }

        else
        {
			if(mx >= 950 && mx <= 1040 && my >= 580 && my <= 610 && mode == 1)
            {
                mode = 0;
            }
			else if(mx >= 800 && mx <= 930 && my >= 580 && my <= 610 && mode == 1)
            {
                mode = 50;
            }
			else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 50)
            {
                mode = 1;
            }
            else if(mx >= 0 && mx <= 350 && my >= 0 && my <= 480 && mode == 1)
            {
                mode = 100;
            }
            else if(mx >= 350 && mx <= 700 && my >= 0 && my <= 480 && mode == 1)
            {
                mode = 200;
            }
            else if(mx >= 700 && mx <= 1050 && my >= 0 && my <= 480 && mode == 1)
            {
                mode = 300;
            }
            else if(mode == 100 || mode >= 1000 && mode < 2000)
            {
                if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 100)
                {
                    mode = 1000;
                }
				
				else if(mx >= 0 && mx <= 525 && my >= 312 && my <= 624 && mode == 1000)
                {
                    mode = 1101;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1101)
                {
                    mode = 1102;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1102)
                {
                    mode = 1103;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1103)
                {
                    mode = 1104;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1104)
                {
                    mode = 1105;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1105)
                {
                    mode = 1106;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1106)
                {
                    mode = 1107;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1107)
                {
                    mode = 1108;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1108)
                {
                    mode = 1109;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1109)
                {
                    mode = 1110;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1110)
                {
                    mode = 1000;
                }

				else if(mx >= 525 && mx <= 1050 && my >= 312 && my <= 624 && mode == 1000)
                {
                    mode = 1201;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1201)
                {
                    mode = 1202;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1202)
                {
                    mode = 1203;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1203)
                {
                    mode = 1204;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1204)
                {
                    mode = 1205;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1205)
                {
                    mode = 1206;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1206)
                {
                    mode = 1207;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1207)
                {
                    mode = 1208;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1208)
                {
                    mode = 1200;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1200)
                {
                    mode = 1000;
                }

				else if(mx >= 0 && mx <= 525 && my >= 0 && my <= 312 && mode == 1000)
                {
                    mode = 1301;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1301)
                {
                    mode = 1302;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1302)
                {
                    mode = 1303;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1303)
                {
                    mode = 1304;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1304)
                {
                    mode = 1305;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1305)
                {
                    mode = 1306;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1306)
                {
                    mode = 1307;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1307)
                {
                    mode = 1308;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1308)
                {
                    mode = 1309;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1309)
                {
                    mode = 1300;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1300)
                {
                    mode = 1000;
                }

				else if(mx >= 525 && mx <= 1050 && my >= 0 && my <= 312 && mode == 1000)
                {
                    mode = 1401;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1401)
                {
                    mode = 1402;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1402)
                {
                    mode = 1403;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1403)
                {
                    mode = 1404;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1404)
                {
                    mode = 1405;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1405)
                {
                    mode = 1406;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1406)
                {
                    mode = 1407;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1407)
                {
                    mode = 1408;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1408)
                {
                    mode = 1409;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1409)
                {
                    mode = 1410;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1410)
                {
                    mode = 1411;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1411)
                {
                    mode = 1412;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1412)
                {
                    mode = 1413;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1413)
                {
                    mode = 1414;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1414)
                {
                    mode = 1415;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1415)
                {
                    mode = 1416;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1416)
                {
                    mode = 1417;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1417)
                {
                    mode = 1418;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1418)
                {
                    mode = 1419;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1419)
                {
                    mode = 1420;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1420)
                {
                    mode = 1421;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1421)
                {
                    mode = 1422;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1422)
                {
                    mode = 1423;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1423)
                {
                    mode = 1424;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1424)
                {
                    mode = 1425;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1425)
                {
                    mode = 1426;
                }
                else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 1426)
                {
                    mode = 1000;
                }
            }

            else if(mode == 200 || mode >= 2000 && mode < 3000)
            {
				if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 200)
                {
                    mode = 2000;
                }

				else if(mx >= 0 && mx <= 525 && my >= 312 && my <= 624 && mode == 2000)
                {
                    mode = 2100;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2100)
                {
                    mode = 2101;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2101)
                {
                    mode = 2102;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2102)
                {
                    mode = 2103;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2103)
                {
                    mode = 2104;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2104)
                {
                    mode = 2105;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2105)
                {
                    mode = 2106;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2106)
                {
                    mode = 2107;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2107)
                {
                    mode = 2108;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2108)
                {
                    mode = 2109;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2109)
                {
                    mode = 2110;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2110)
                {
                    mode = 2000;
                }

				else if(mx >= 525 && mx <= 1050 && my >= 312 && my <= 624 && mode == 2000)
                {
                    mode = 2301;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2301)
                {
                    mode = 2302;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2302)
                {
                    mode = 2303;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2303)
                {
                    mode = 2304;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2304)
                {
                    mode = 2305;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2305)
                {
                    mode = 2306;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2306)
                {
                    mode = 2307;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2307)
                {
                    mode = 2308;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2308)
                {
                    mode = 2309;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2309)
                {
                    mode = 2310;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2310)
                {
                    mode = 2311;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2311)
                {
                    mode = 2312;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2312)
                {
                    mode = 2313;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2313)
                {
                    mode = 2314;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2314)
                {
                    mode = 2315;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2315)
                {
                    mode = 2316;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2316)
                {
                    mode = 2317;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2317)
                {
                    mode = 2318;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2318)
                {
                    mode = 2319;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2319)
                {
                    mode = 2320;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2320)
                {
                    mode = 2321;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2321)
                {
                    mode = 2322;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2322)
                {
                    mode = 2323;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2323)
                {
                    mode = 2324;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2324)
                {
                    mode = 2325;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2325)
                {
                    mode = 2326;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 2326)
                {
                    mode = 2000;
                }

				else if(mx >= 0 && mx <= 525 && my >= 0 && my <= 312 && mode == 2000)
                {
                    mode = 2499;
                }
				else if(mode == 2499) {
						 if(mx >=   0 && mx <=  525 && my >= 0 && my <= 624) sys = n1 = n2 = 0;
					else if(mx >= 525 && mx <= 1050 && my >= 0 && my <= 624) sys = 1, n1 = n2 = 0;
					mode = 2400;
					show = 0;
				}
				else if(mx >= 150 && mx <= 300 && my >=300 && my <=450 && mode == 2400)
                {
                    mode = 2410;
                }
				else if(mode == 2410) {
						 if(mx >=  50 && mx <= 200 && my >= 240 && my <= 390) n1 = 0;
					else if(mx >= 210 && mx <= 360 && my >= 240 && my <= 390) n1 = 1;
					else if(mx >= 370 && mx <= 520 && my >= 240 && my <= 390) n1 = 2;
					else if(mx >= 530 && mx <= 690 && my >= 240 && my <= 390) n1 = 3;
					else if(mx >= 700 && mx <= 850 && my >= 240 && my <= 390) n1 = 4;
					else if(mx >= 860 && mx <=1010 && my >= 240 && my <= 390) n1 = 5;
					else if(mx >=  50 && mx <= 200 && my >=  80 && my <= 230) n1 = 6;
					else if(mx >= 210 && mx <= 360 && my >=  80 && my <= 230) n1 = 7;
					else if(mx >= 370 && mx <= 520 && my >=  80 && my <= 230) n1 = 8;
					else if(mx >= 530 && mx <= 690 && my >=  80 && my <= 230) n1 = 9;
					else if(mx >= 700 && mx <= 850 && my >=  80 && my <= 230) n1 =10;
					mode = 2400;
					show = 0;
				}
				else if(mx >= 450 && mx <= 600 && my >=300 && my <=450 && mode == 2400)
                {
                    mode = 2420;
                }
				else if(mode == 2420) {
						 if(mx >=  50 && mx <= 200 && my >= 240 && my <= 390) n2 = 0;
					else if(mx >= 210 && mx <= 360 && my >= 240 && my <= 390) n2 = 1;
					else if(mx >= 370 && mx <= 520 && my >= 240 && my <= 390) n2 = 2;
					else if(mx >= 530 && mx <= 690 && my >= 240 && my <= 390) n2 = 3;
					else if(mx >= 700 && mx <= 850 && my >= 240 && my <= 390) n2 = 4;
					else if(mx >= 860 && mx <=1010 && my >= 240 && my <= 390) n2 = 5;
					else if(mx >=  50 && mx <= 200 && my >=  80 && my <= 230) n2 = 6;
					else if(mx >= 210 && mx <= 360 && my >=  80 && my <= 230) n2 = 7;
					else if(mx >= 370 && mx <= 520 && my >=  80 && my <= 230) n2 = 8;
					else if(mx >= 530 && mx <= 690 && my >=  80 && my <= 230) n2 = 9;
					else if(mx >= 700 && mx <= 850 && my >=  80 && my <= 230) n2 =10;
					mode = 2400;
					show = 0;
				}
				else if(mx >= 600 && mx <= 750 && my >=300 && my <=450 && mode == 2400)
                {
                    show = 1;
                }

				else if(mx >= 525 && mx <= 1050 && my >= 0 && my <= 312 && mode == 2000)
                {
                    mode = 2500;
					rh[0] = true;
					if(rh[0]) PlaySound("music/nursery/rhymes/rh0.wav", NULL, SND_ASYNC);

                }
				else if(mx >= 0 && mx <= 525 && my >= 312 && my <= 624 && mode == 2500)
                {
					rh[0] = false;
                    mode = 2510;
					ts = time(NULL);
                }
				else if(mx >= 525 && mx <= 1050 && my >= 312 && my <= 624 && mode == 2500)
                {
					rh[0] = false;
                    mode = 2530;
					ts = time(NULL);
                }
				else if(mx >= 0 && mx <= 525 && my >= 0 && my <= 312 && mode == 2500)
                {
					rh[0] = false;
                    mode = 2550;
					ts = time(NULL);
                }
				else if(mx >= 525 && mx <= 1050 && my >= 0 && my <= 312 && mode == 2500)
                {
					rh[0] = false;
                    mode = 2570;
					ts = time(NULL);
                }
            }

            else if(mode == 300 || mode >=3000 && mode < 4000)
            {
				if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 300)
                {
                    mode = 3000;
                }

				else if(mx >= 0 && mx <= 525 && my >= 312 && my <= 624 && mode == 3000)
                {
					mode = 3101;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 3101)
                {
                    mode = 3102;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 3102)
                {
                    mode = 3103;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 3103)
                {
                    mode = 3104;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 3104)
                {
                    mode = 3105;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 3105)
                {
                    mode = 3106;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 3106)
                {
                    mode = 3107;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 3107)
                {
                    mode = 3108;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 3108)
                {
                    mode = 3109;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 3109)
                {
                    mode = 3000;
                }

				else if(mx >= 525 && mx <= 1050 && my >= 312 && my <= 624 && mode == 3000)
                {
                    mode = 3400;
                }
				else if(mx >= 0 && mx <= 525 && my >= 0 && my <= 624 && mode == 3299)
                {
                    mode = 3201;
                }
				else if(mx >= 0 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3201)
                {
                    mode = 3202;
                }
				else if(mx >= 0 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3202)
                {
                    mode = 3203;
                }
				else if(mx >= 0 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3203)
                {
                    mode = 3204;
                }
				else if(mx >= 0 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3204)
                {
                    mode = 3205;
                }
				else if(mx >= 0 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3205)
                {
                    mode = 3206;
                }
				else if(mx >= 0 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3206)
                {
                    mode = 3207;
                }
				else if(mx >= 0 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3207)
                {
                    mode = 3208;
                }
				else if(mx >= 0 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3208)
                {
                    mode = 3209;
                }
				else if(mx >= 0 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3209)
                {
                    mode = 3210;
                }
				else if(mx >= 0 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3210)
                {
                    mode = 3000;
                }
				else if(mx >= 525 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3299)
                {
                    mode = 3301;
                }
				else if(mx >= 0 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3301)
                {
                    mode = 3302;
                }
				else if(mx >= 0 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3302)
                {
                    mode = 3303;
                }
				else if(mx >= 0 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3303)
                {
                    mode = 3304;
                }
				else if(mx >= 0 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3304)
                {
                    mode = 3305;
                }
				else if(mx >= 0 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3305)
                {
                    mode = 3306;
                }
				else if(mx >= 0 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3306)
                {
                    mode = 3307;
                }
				else if(mx >= 0 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3307)
                {
                    mode = 3308;
                }
				else if(mx >= 0 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3308)
                {
                    mode = 3309;
                }
				else if(mx >= 0 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3309)
                {
                    mode = 3310;
                }
				else if(mx >= 0 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3310)
                {
                    mode = 3311;
                }
				else if(mx >= 0 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3311)
                {
                    mode = 3312;
                }
				else if(mx >= 0 && mx <= 1050 && my >= 0 && my <= 624 && mode == 3312)
                {
                    mode = 3000;
                }

				else if(mx >= 0 && mx <= 525 && my >= 0 && my <= 312 && mode == 3000)
                {
                    mode = 3299;
                }

				else if(mx >= 0 && mx <= 525 && my >= 312 && my <= 624 && mode == 3400)
                {
                    mode = 3410;
                }
				else if(mode == 3410)
                {
						 if(mx >= 700 && mx <= 900 && my >= 424 && my <= 624) math = 0, mode = 3411;
					else if(mx >= 500 && mx <= 700 && my >= 424 && my <= 624) math = 1, mode = 3411;
					else if(mx >= 700 && mx <= 900 && my >= 224 && my <= 424) math = 2, mode = 3411;
					else if(mx >= 500 && mx <= 700 && my >= 224 && my <= 424) math = 3, mode = 3411;
                }
				else if(mode == 3411)
                {
						 if(mx >=   5 && mx <= 205 && my >= 350 && my <= 550) d[math] = 0;
					else if(mx >= 215 && mx <= 415 && my >= 350 && my <= 550) d[math] = 1;
					else if(mx >= 425 && mx <= 625 && my >= 350 && my <= 550) d[math] = 2;
					else if(mx >= 635 && mx <= 835 && my >= 350 && my <= 550) d[math] = 3;
					else if(mx >= 845 && mx <=1045 && my >= 350 && my <= 550) d[math] = 4;
					else if(mx >=   5 && mx <= 205 && my >= 100 && my <= 300) d[math] = 5;
					else if(mx >= 215 && mx <= 415 && my >= 100 && my <= 300) d[math] = 6;
					else if(mx >= 425 && mx <= 625 && my >= 100 && my <= 300) d[math] = 7;
					else if(mx >= 635 && mx <= 835 && my >= 100 && my <= 300) d[math] = 8;
					else if(mx >= 845 && mx <=1045 && my >= 100 && my <= 300) d[math] = 9;
                    mode = 3410;
                }

				else if(mx >= 525 && mx <= 1050 && my >= 312 && my <= 624 && mode == 3400)
                {
                    mode = 3420;
                }
				else if(mode == 3420)
                {
						 if(mx >= 700 && mx <= 900 && my >= 424 && my <= 624) math = 0, mode = 3421;
					else if(mx >= 500 && mx <= 700 && my >= 424 && my <= 624) math = 1, mode = 3422;
					else if(mx >= 700 && mx <= 900 && my >= 224 && my <= 424) math = 2, mode = 3423;
					else if(mx >= 500 && mx <= 700 && my >= 224 && my <= 424) math = 3, mode = 3424;
                }
				else if(mode == 3421)
                {
						 if(mx >=   5 && mx <= 205 && my >= 350 && my <= 550) d[math] = 0;
					else if(mx >= 215 && mx <= 415 && my >= 350 && my <= 550) d[math] = 1;
					else if(mx >= 425 && mx <= 625 && my >= 350 && my <= 550) d[math] = 2;
					else if(mx >= 635 && mx <= 835 && my >= 350 && my <= 550) d[math] = 3;
					else if(mx >= 845 && mx <=1045 && my >= 350 && my <= 550) d[math] = 4;
					else if(mx >=   5 && mx <= 205 && my >= 100 && my <= 300) d[math] = 5;
					else if(mx >= 215 && mx <= 415 && my >= 100 && my <= 300) d[math] = 6;
					else if(mx >= 425 && mx <= 625 && my >= 100 && my <= 300) d[math] = 7;
					else if(mx >= 635 && mx <= 835 && my >= 100 && my <= 300) d[math] = 8;
					else if(mx >= 845 && mx <=1045 && my >= 100 && my <= 300) d[math] = 9;
                    mode = 3420;
                }
				else if(mode == 3422)
                {
						 if(mx >=   5 && mx <= 205 && my >= 350 && my <= 550) d[math] = 0;
					else if(mx >= 215 && mx <= 415 && my >= 350 && my <= 550) d[math] = 1;
					else if(mx >= 425 && mx <= 625 && my >= 350 && my <= 550) d[math] = 2;
					else if(mx >= 635 && mx <= 835 && my >= 350 && my <= 550) d[math] = 3;
					else if(mx >= 845 && mx <=1045 && my >= 350 && my <= 550) d[math] = 4;
					else if(mx >=   5 && mx <= 205 && my >= 100 && my <= 300) d[math] = 5;
					else if(mx >= 215 && mx <= 415 && my >= 100 && my <= 300) d[math] = 6;
					else if(mx >= 425 && mx <= 625 && my >= 100 && my <= 300) d[math] = 7;
					else if(mx >= 635 && mx <= 835 && my >= 100 && my <= 300) d[math] = 8;
					else if(mx >= 845 && mx <=1045 && my >= 100 && my <= 300) d[math] = 9;
                    mode = 3420;
                }
				else if(mode == 3423)
                {
						 if(mx >=   5 && mx <= 205 && my >= 350 && my <= 550) d[math] = 0;
					else if(mx >= 215 && mx <= 415 && my >= 350 && my <= 550) d[math] = 1;
					else if(mx >= 425 && mx <= 625 && my >= 350 && my <= 550) d[math] = 2;
					else if(mx >= 635 && mx <= 835 && my >= 350 && my <= 550) d[math] = 3;
					else if(mx >= 845 && mx <=1045 && my >= 350 && my <= 550) d[math] = 4;
					else if(mx >=   5 && mx <= 205 && my >= 100 && my <= 300) d[math] = 5;
					else if(mx >= 215 && mx <= 415 && my >= 100 && my <= 300) d[math] = 6;
					else if(mx >= 425 && mx <= 625 && my >= 100 && my <= 300) d[math] = 7;
					else if(mx >= 635 && mx <= 835 && my >= 100 && my <= 300) d[math] = 8;
					else if(mx >= 845 && mx <=1045 && my >= 100 && my <= 300) d[math] = 9;
                    mode = 3420;
                }
				else if(mode == 3424)
                {
						 if(mx >=   5 && mx <= 205 && my >= 350 && my <= 550) d[math] = 0;
					else if(mx >= 215 && mx <= 415 && my >= 350 && my <= 550) d[math] = 1;
					else if(mx >= 425 && mx <= 625 && my >= 350 && my <= 550) d[math] = 2;
					else if(mx >= 635 && mx <= 835 && my >= 350 && my <= 550) d[math] = 3;
					else if(mx >= 845 && mx <=1045 && my >= 350 && my <= 550) d[math] = 4;
					else if(mx >=   5 && mx <= 205 && my >= 100 && my <= 300) d[math] = 5;
					else if(mx >= 215 && mx <= 415 && my >= 100 && my <= 300) d[math] = 6;
					else if(mx >= 425 && mx <= 625 && my >= 100 && my <= 300) d[math] = 7;
					else if(mx >= 635 && mx <= 835 && my >= 100 && my <= 300) d[math] = 8;
					else if(mx >= 845 && mx <=1045 && my >= 100 && my <= 300) d[math] = 9;
                    mode = 3420;
                }

				else if(mx >= 0 && mx <= 525 && my >= 0 && my <= 312 && mode == 3400)
                {
                    mode = 3430;
                }
				else if(mode == 3430)
                {
						 if(mx >= 700 && mx <= 900 && my >= 424 && my <= 624) math = 0, mode = 3431;
					else if(mx >= 500 && mx <= 700 && my >= 424 && my <= 624) math = 1, mode = 3431;
					else if(mx >= 700 && mx <= 900 && my >= 224 && my <= 424) math = 2, mode = 3431;
                }
				else if(mode == 3431)
                {
						 if(mx >=   5 && mx <= 205 && my >= 350 && my <= 550) d[math] = 0;
					else if(mx >= 215 && mx <= 415 && my >= 350 && my <= 550) d[math] = 1;
					else if(mx >= 425 && mx <= 625 && my >= 350 && my <= 550) d[math] = 2;
					else if(mx >= 635 && mx <= 835 && my >= 350 && my <= 550) d[math] = 3;
					else if(mx >= 845 && mx <=1045 && my >= 350 && my <= 550) d[math] = 4;
					else if(mx >=   5 && mx <= 205 && my >= 100 && my <= 300) d[math] = 5;
					else if(mx >= 215 && mx <= 415 && my >= 100 && my <= 300) d[math] = 6;
					else if(mx >= 425 && mx <= 625 && my >= 100 && my <= 300) d[math] = 7;
					else if(mx >= 635 && mx <= 835 && my >= 100 && my <= 300) d[math] = 8;
					else if(mx >= 845 && mx <=1045 && my >= 100 && my <= 300) d[math] = 9;
                    mode = 3430;
                }

				else if(mx >= 525 && mx <= 1050 && my >= 0 && my <= 312 && mode == 3400)
                {
                    mode = 3440;
                }
				else if(mode == 3440)
                {
						 if(mx >= 425 && mx <= 625 && my >= 424 && my <= 624) math = 0, mode = 3441;
					else if(mx >= 225 && mx <= 425 && my >= 424 && my <= 624) math = 1, mode = 3442;
					else if(mx >=   0 && mx <= 200 && my >= 424 && my <= 624) math = 5, mode = 3443;
                }
				else if(mode == 3441)
                {
						 if(mx >=   5 && mx <= 205 && my >= 350 && my <= 550) d[math] = 0;
					else if(mx >= 215 && mx <= 415 && my >= 350 && my <= 550) d[math] = 1;
					else if(mx >= 425 && mx <= 625 && my >= 350 && my <= 550) d[math] = 2;
					else if(mx >= 635 && mx <= 835 && my >= 350 && my <= 550) d[math] = 3;
					else if(mx >= 845 && mx <=1045 && my >= 350 && my <= 550) d[math] = 4;
					else if(mx >=   5 && mx <= 205 && my >= 100 && my <= 300) d[math] = 5;
					else if(mx >= 215 && mx <= 415 && my >= 100 && my <= 300) d[math] = 6;
					else if(mx >= 425 && mx <= 625 && my >= 100 && my <= 300) d[math] = 7;
					else if(mx >= 635 && mx <= 835 && my >= 100 && my <= 300) d[math] = 8;
					else if(mx >= 845 && mx <=1045 && my >= 100 && my <= 300) d[math] = 9;
                    mode = 3440;
                }
				else if(mode == 3442)
                {
						 if(mx >=   5 && mx <= 205 && my >= 350 && my <= 550) d[math] = 0;
					else if(mx >= 215 && mx <= 415 && my >= 350 && my <= 550) d[math] = 1;
					else if(mx >= 425 && mx <= 625 && my >= 350 && my <= 550) d[math] = 2;
					else if(mx >= 635 && mx <= 835 && my >= 350 && my <= 550) d[math] = 3;
					else if(mx >= 845 && mx <=1045 && my >= 350 && my <= 550) d[math] = 4;
					else if(mx >=   5 && mx <= 205 && my >= 100 && my <= 300) d[math] = 5;
					else if(mx >= 215 && mx <= 415 && my >= 100 && my <= 300) d[math] = 6;
					else if(mx >= 425 && mx <= 625 && my >= 100 && my <= 300) d[math] = 7;
					else if(mx >= 635 && mx <= 835 && my >= 100 && my <= 300) d[math] = 8;
					else if(mx >= 845 && mx <=1045 && my >= 100 && my <= 300) d[math] = 9;
                    mode = 3440;
                }
				else if(mode == 3443)
                {
						 if(mx >=   5 && mx <= 205 && my >= 350 && my <= 550) d[math] = 0;
					else if(mx >= 215 && mx <= 415 && my >= 350 && my <= 550) d[math] = 1;
					else if(mx >= 425 && mx <= 625 && my >= 350 && my <= 550) d[math] = 2;
					else if(mx >= 635 && mx <= 835 && my >= 350 && my <= 550) d[math] = 3;
					else if(mx >= 845 && mx <=1045 && my >= 350 && my <= 550) d[math] = 4;
					else if(mx >=   5 && mx <= 205 && my >= 100 && my <= 300) d[math] = 5;
					else if(mx >= 215 && mx <= 415 && my >= 100 && my <= 300) d[math] = 6;
					else if(mx >= 425 && mx <= 625 && my >= 100 && my <= 300) d[math] = 7;
					else if(mx >= 635 && mx <= 835 && my >= 100 && my <= 300) d[math] = 8;
					else if(mx >= 845 && mx <=1045 && my >= 100 && my <= 300) d[math] = 9;
                    mode = 3440;
                }

				else if(mx >= 525 && mx <= 1050 && my >= 0 && my <= 312 && mode == 3000)
                {
                    mode = 3400;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 3500)
                {
                    mode = 3501;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 3501)
                {
                    mode = 3502;
                }
				else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 3502)
                {
                    mode = 3503;
                }
				/*else if(mx >=0 && mx <=1050 && my >=0 && my <=624 && mode == 3503)
                {
                    mode = 3504;
                }*/
            }
        }
    }
}


//	function iKeyboard() is called whenever the user hits a key in keyboard.
//	key- holds the ASCII value of the key pressed.
void iKeyboard(unsigned char key)
{
    if(mode == -2 || mode == -12)
    {
        //if backspace pressed, delete last character
        if(key == '\b' || lenu >= 13)
        {
            if(lenu>0)
            {
                lenu--;
                stru[lenu]=0;
            }
        }
        //if(key != '\b' && key != '\r' && key != '\t' && key != 32 && lenu < 18)
		else if(key > 32 && key < 127 && lenu < 12)
        {
            stru[lenu] = key;
            lenu++;
        }

		else if(lenu >= 12 || key == 27 || key == 32 || key == 127)
        {
            printf("\a");
        }
    }

    if(mode == -4 || mode == -14)
    {
        //if backspace pressed, delete last character
        if(key =='\b' || lenp >= 21)
        {
            if(lenp>0)
            {
                lenp--;
                strp[lenp] = 0;
                str[lenp] = 0;
            }
        }
        //if(key != '\b' && key != '\r' && key != '\t' && key != 32 && lenu < 18)
		else if(key > 32 && key < 127 && lenp < 20)
        {
            strp[lenp] = key;
            strcat(str, "*");
            lenp++;
        }
		else if(lenp >= 20 || key == 27 || key == 32 || key == 127)
        {
            printf("\a");
        }
    }
	if(mode == -2 || mode == -12 || mode == -4 || mode == -14) {
		if(mode == -2 && key == '\t') mode = -4;
		else if(mode == -12 && key == '\t') mode = -14;
		else if(mode == -4 && key == '\t') mode = -2;
		else if(mode == -14 && key == '\t') mode = -12;
	}
	if(mode < 0 && mode > -10 && key == '\r') mode = -5, check = 0;
	else if(mode < -10 && mode > -20 && key == '\r') mode = -15, check = 0;

	if(mode > 0 && key == '\b') {
		if(mode == 1000 || mode == 2000 || mode == 3000 || mode == 100 || mode == 200 || mode == 300) {
			mode = 1;
		}
		else if(mode == 50) {
			mode = 1;
		}
		else if(mode > 1000 && mode < 2000) {
			mode = 1000;
		}
		else if((mode > 2000 && mode < 2400) || mode == 2500 || mode == 2499) {
			mode = 2000;
		}
		else if(mode == 2400) {
			mode = 2499;
		}
		else if(mode == 2410 || mode == 2420) {
			mode = 2400;
		}
		else if((mode > 3100 && mode < 3110) || mode == 3400 || mode == 3299) {
			mode = 3000;
		}
		else if((mode > 3200 && mode < 3299) || (mode > 3300 && mode < 3399)) {
			mode = 3299;
		}
		else if(mode == 3410 || mode == 3420 || mode == 3430 || mode == 3440) {
			mode = 3400;
		}
		else if(mode > 3410 && mode < 3420) {
			mode = 3410;
		}
		else if(mode > 3420 && mode < 3430) {
			mode = 3420;
		}
		else if(mode > 3430 && mode < 3440) {
			mode = 3430;
		}
		else if(mode > 3440 && mode < 3450) {
			mode = 3440;
		}
	}


    //place your codes for other keys here
}


//	function iSpecialKeyboard() is called whenver user hits special keys like-
//	function keys, home, end, pg up, pg down, arraows etc. you have to use
//	appropriate constants to detect them. A list is:
//	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
//	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
//	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
//	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
void iSpecialKeyboard(unsigned char key)
{
    //place your codes for other keys here
	if(mode > 0 && key == GLUT_KEY_HOME) {
		rh[0] = true;
		if(rh[0]) PlaySound("music/nursery/rhymes/rh0.wav", NULL, SND_ASYNC);
		mode = 1;
	}
	else if(mode > 1000 && key == GLUT_KEY_LEFT) {
		if (mode == 1200) {
			mode = 1208;
		}
		else if((mode > 1101 && mode < 1111) || (mode > 1201 && mode < 1209) || (mode > 1300 && mode < 1310) || (mode > 1401 && mode < 1427) || (mode > 2100 && mode < 2110) || (mode > 2301 && mode < 2327) || (mode > 3101 && mode < 3110) || (mode > 3201 && mode < 3211) || (mode > 3301 && mode < 3313)) {
			mode--;
		}
	}
	else if(mode > 1000 && key == GLUT_KEY_RIGHT) {
		if(mode == 1208) {
			mode = 1200;
		}
		else if((mode > 1100 && mode < 1110) || (mode > 1200 && mode < 1208) || (mode >= 1300 && mode < 1309) || (mode > 1400 && mode < 1426) || (mode >= 2100 && mode < 2109) || (mode > 2300 && mode < 2326) || (mode > 3100 && mode < 3109) || (mode > 3200 && mode < 3210) || (mode > 3300 && mode < 3312)) {
			mode++;
		}
	}
}


int main()
{
    //place your own initialization codes here.

	rh[0] = rh[1] = rh[2] = rh[3] = rh[4] = false;

	d[5] = 1;

    	if(rh[0]) PlaySound("music/nursery/rhymes/rh0.wav", NULL, SND_ASYNC);
	if(rh[1]) PlaySound("music/nursery/rhymes/rh1.wav", NULL, SND_ASYNC);
	if(rh[2]) PlaySound("music/nursery/rhymes/rh2.wav", NULL, SND_ASYNC);
	if(rh[3]) PlaySound("music/nursery/rhymes/rh3.wav", NULL, SND_ASYNC);
	if(rh[4]) PlaySound("music/nursery/rhymes/rh4.wav", NULL, SND_ASYNC);

	iInitialize(1050, 624, "Learning Software");

    return 0;
}