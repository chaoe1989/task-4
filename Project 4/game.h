#pragma once
#ifndef CGAME_H
#define CGAME_H

#include <windows.h>
#include <String>

#define ROW 4   //格子总行数
#define COLUMN 4    //格子总列数

class cGame
{
public:
	cGame();
	~cGame();
	void play();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void newLattice();
	bool canMove();
	void show();
	void buf_show();

private:
	int(*matrix)[COLUMN];	//存储格子信息
	int max;	//格子最大的数字的值
	bool gameWin;	//游戏是否取胜
	bool gameOver;	//游戏是否结束

};

#endif // CGAME_H