#pragma once
#include "GUI.h"

using namespace Graph_lib;

//De forskjellige tilstandene en Tile kan v�re i
enum class Cell { closed, open, flagged };

struct Tile : Button
{
public:

	Tile(Point pos, int size, Callback cb, bool isMine = false)
		:Button(pos, size, size, "", cb), isMine(isMine) {};

	void set_label(string s) { label = s; redraw(); }
	void set_label_color(Color c) { pw->labelcolor(c.as_int()); redraw(); }

	void open(); // �pner ruten
	void flag();// Flagger en rute
	void setAdjMines(int adjMines);

	Cell state = Cell::closed;
	bool isMine;
};