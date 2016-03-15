// HW3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <cstdlib>
#include <string>
using std::string;
using std::cout;
using std::endl;
void exitWhenInvalidScreen(int input) {
	if (input <= 0 || input>1000) {
		std::cout << "invalid screen size" << std::endl;
		exit(0);
	}
}
class Screen {
private:
	int _width;
	int _height;
	string enter;
	string leave;
	static Screen* instance;
	Screen(int width, int height) {

		enter = "enter screen";
		leave = "leave screen";
		cout << enter << endl;
		exitWhenInvalidScreen(width);
		exitWhenInvalidScreen(height);
		_width = width;
		_height = height;
	};
public:
	
	static Screen* getInstance(int width = 640, int height = 480) {
		if (instance == 0) {
			instance = new Screen(width, height);
		}
		
			return instance;
		
	}


	~Screen() {
		cout << leave << endl;
	}
	static void deleteInstance() {
		Screen* p = instance;
		delete p;
		instance = NULL;
	}
	int getWidth() {
		return _width;
	};
	int getHeight() {
		return _height;
	};
	//int setWidth(int width) {
	//	exitWhenInvalidScreen(width);
	//	_width = width;
	//	return width;
	//};    //return width
	//int setHeight(int height) {
	//	exitWhenInvalidScreen(height);
	//	_height = height;
	//	return height;
	//};
};
Screen* Screen::instance = NULL;
int main() {
	  int width, height;
	  Screen *screen1, *screen2;
	
	  std::cin >> width >> height;
	
		  screen1 = Screen::getInstance(width, height);
	 screen2 = Screen::getInstance();
	  if (screen1 != screen2) {
		      std::cout << "two instances" << std::endl;
		
	}
	
		  std::cout << screen2->getWidth() << ' ' << screen2->getHeight() << std::endl;
	  screen2->deleteInstance();
	  screen1 = Screen::getInstance(2 * width, 2 * height);
	  std::cout << screen1->getWidth() << ' ' << screen1->getHeight() << std::endl;
	  screen1->deleteInstance();
	
	#ifdef DEBUG
	  std::cin.get();
	#endif
	  return 0;
	
}
