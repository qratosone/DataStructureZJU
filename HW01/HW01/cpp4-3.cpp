#include "stdafx.h"
#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;
void exitWhenInvalidScreen(int input) {
	if (input <= 0 || input>1000) {
		std::cout << "invalid screen size" << std::endl;
		exit(0);
	}
}
int abs(int input) {
	if (input<0)
	{
		input = -input;
	}
	return input;
}
class Screen {
private:
	int _width;
	int _height;
public:
	Screen(int width, int height) {
		exitWhenInvalidScreen(width);
		exitWhenInvalidScreen(height);
		_width = width;
		_height = height;
		std::cout << "screen" << std::endl;
	};
	Screen() {
		std::cout << "screen" << std::endl;
	};
	int getWidth() {
		return _width;
	};
	int getHeight() {
		return _height;
	};
	int setWidth(int width) {
		exitWhenInvalidScreen(width);
		_width = width;
		return width;
	};    //return width
	int setHeight(int height) {
		exitWhenInvalidScreen(height);
		_height = height;
		return height;
	};
};
class MyRectangle {
private:
	Screen* screen_;
	int x1, y1, x2, y2;
public:
	MyRectangle(int x1, int y1, int x2, int y2, Screen* screen) {
		this->x1 = x1;
		this->x2 = x2;
		this->y1 = y1;
		this->y2 = y2;
		screen_ = screen;
	};
	MyRectangle() {
		this->x1 = 0;
		this->x2 = 0;
		this->y1 = 0;
		this->y2 = 0;
	};
	void setCoordinations(int x1, int y1, int x2, int y2) {
		this->x1 = x1;
		this->x2 = x2;
		this->y1 = y1;
		this->y2 = y2;
	}
	void setScreen(Screen &screen) {
		screen_ = &screen;
	}
	void Draw() {
		int width = screen_->getWidth();
		int height = screen_->getHeight();
		if (x1>0 && x1<width&&y1>0 && y1<height&&x2>0 && x2<width&&y2>0 && y2<height) {
			int recwidth = x2 - x1;
			//			recwidth = abs(recwidth);
			int recheight = y2 - y1;
			//			recheight = abs(recheight);
			//cout << x1 << " " << y1 << " " << recwidth << " " << recheight << endl;
			if (x1<x2&&y1>y2)
			{
				cout << x1 << " " << y1 << " " << recwidth << " " << recheight << endl;
			}
			else
			{
				cout << "invalid myrectangle" << endl;
			}
		}
		else {
			cout << "invalid myrectangle" << endl;
		}
	}


};
int main() {
	int width, height;
	cin >> width >> height;
	Screen  screen(width, height);

	int leftX, leftY, rightX, rightY;
	cin >> leftX >> leftY >> rightX >> rightY;
	MyRectangle myRectangle1(leftX, leftY, rightX, rightY, &screen);
	MyRectangle* myRectangles = new MyRectangle[2];

	myRectangles[1].setCoordinations(10, 300, 700, 500);
	myRectangles[1].setScreen(screen);

	myRectangle1.Draw();
	for (int i = 0; i < 2; i++) {
		myRectangles[i].setScreen(screen);
		(myRectangles + i)->Draw();
	}

	delete[] myRectangles;

#ifdef DEBUG
	std::cin.get();
#endif
	return 0;
}