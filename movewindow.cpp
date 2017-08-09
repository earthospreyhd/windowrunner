#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int x = 500;

int y = 250;

POINT curpos;

int num;

int xoff;

int yoff;

int lesseradd;

int greateradd;

int inc1;

int inc2;

int main()
{

	HWND conhandle = GetForegroundWindow();

	MoveWindow(conhandle, x, y, 300, 400, TRUE);

	int destx;

	int desty;

	double grad1;

	double grad2;

	int gradient;

	bool xislarger = FALSE;

	while (true) {

		conhandle = GetForegroundWindow();

		GetCursorPos(&curpos);

		xoff = curpos.x - x - 150;

		yoff = curpos.y - y - 200;

		if (xoff < 250 && xoff > -250 && yoff < 250 && yoff > -250) {

			destx = xoff;

			desty = yoff;

			if (abs(destx) > abs(desty)) {

				grad1 = destx;

				grad2 = desty;

				greateradd = x;

				lesseradd = y;

				inc1 = (abs(xoff) == xoff) ? -1 : 1;

				inc2 = (abs(yoff) == yoff) ? -1 : 1;

				xislarger = TRUE;

			}

			else {

				grad1 = desty;

				grad2 = destx;

				greateradd = y;

				lesseradd = x;

				inc1 = (abs(yoff) == yoff) ? -1 : 1;

				inc2 = (abs(xoff) == xoff) ? -1 : 1;
			}

			int greater = (int)grad1;

			int lesser = (int)grad2;

			gradient = (int)grad1 / grad2;

			for (int z = 0; z < 300; z++) {

				if (z % gradient == 0) {

					lesseradd = lesseradd + inc2;

				}

				greateradd = greateradd + inc1;

				if (xislarger) {

					MoveWindow(conhandle, greateradd, lesseradd, 300, 400, FALSE);

					cout << "x is " << greateradd << " y is " << lesseradd << endl;

					x = greateradd;

					y = lesseradd;

				}

				else {

					MoveWindow(conhandle, lesseradd, greateradd, 300, 400, FALSE);

					cout << "y is " << greateradd << " x is " << lesseradd << " " << abs(greater / lesser) << endl;

					y = greateradd;

					x = lesseradd;
				}

			}


		}
	}

	return 0;
}