#include "Tile.h"
#include "std_lib_facilities.h"

// For å sette labelfarge i henhold til hvor mange miner som er rundt
 map<int, Color> minesToColor{ { 1, Color::blue },
{ 2, Color::red },
{ 3,Color::dark_green },
{ 4, Color::dark_magenta },
{ 5, Color::dark_blue },
{ 6, Color::dark_cyan },
{ 7, Color::dark_red },
{ 8, Color::dark_yellow } };

// For å sette Tilelabel i henhold til state
 map<Cell, string> cellToSymbol{ { Cell::closed, "" },
{ Cell::open, "" },
{ Cell::flagged, "@<" } };

void Tile::open()
{
	if (state == Cell::closed) {
		if (isMine) {
			//set label til rød x
			set_label("x");
			set_label_color(Color::red);
		}
		 
		static_cast<Fl_Button*>(pw)->set();//Setter en button som trykket på, tilsvarer åpnet rute
		state = Cell::open;
		
	}
	
}

void Tile::flag()
{
	if (state != Cell::open) {
		if (state == Cell::flagged) {
			state = Cell::closed;
			//TODO: bruke map
			set_label(cellToSymbol[state]);
		}
		else {
			state = Cell::flagged;
			//TODO: bruke map
			set_label(cellToSymbol[state]);
			set_label_color(Color::blue);
		}
	}
}

void Tile::setAdjMines(int adjMines) {
	if (adjMines != 0) {
		set_label(to_string(adjMines));
	}
	set_label_color(minesToColor[adjMines]);
	switch (adjMines) {
	case 1:
		set_label_color(Color::blue);
		break;

	case 2:
		set_label_color(Color::red);
		break;

	case 3:
		set_label_color(Color::dark_green);
		break;

	case 4:
		set_label_color(Color::dark_magenta);
		break;

	case 5:
		set_label_color(Color::dark_blue);
		break;

	case 6:
		set_label_color(Color::dark_cyan);
		break;

	case 7:
		set_label_color(Color::dark_red);
		break;

	case 8:
		set_label_color(Color::dark_yellow);
		break;
	}
}