#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int x = 500;

int y = 250;

LPTSTR out;

POINT curpos;

RECT res;

int num;

HWND desk = GetDesktopWindow();

int xoff;

int yoff;

int main()
{

	HWND conhandle = GetForegroundWindow();

	GetWindowRect(desk, &res);

	MoveWindow(conhandle, x, y, 300, 400, TRUE);

	while (true) {

		conhandle = GetForegroundWindow();

		GetCursorPos(&curpos);

		xoff = curpos.x - x;

		yoff = curpos.y - y;

		if (xoff < 450 && xoff > 300 && yoff > 0 && yoff < 550) {
			//is in the right rectangle
			x = curpos.x - 450;

		}

		if (xoff < 0 && xoff > -150 && yoff > 0 && yoff < 550) {
			//is in the left rectangle
			x = curpos.x + 150;

		}

		if (yoff > 400 && yoff < 550 && xoff > 0 && xoff < 300) {
			// is in the bottom rectangle
			y = curpos.y - 550;

		}

		if (yoff < 0 && yoff > -150 && xoff > 0 && xoff < 300) {
			// is in the top rectangle
			y = curpos.y + 150;

		}

		MoveWindow(conhandle, x, y, 300, 400, FALSE);

		cout << curpos.x << " ";

		cout << curpos.y << endl;

	}

	return 0;
}