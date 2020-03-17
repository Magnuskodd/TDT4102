#include "MinesweeperWindow.h"
#include "utilites.h"

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, const string& title) :
	Graph_lib::Window(xy, width * cellSize, height*cellSize, title), width(width), height(height), mines(mines),
	lossText{ Point{width*cellSize / 2 - cellSize * 2, height*cellSize / 2}, "You Lost!" }, 
	winText{ Point{ width*cellSize / 2 - cellSize * 2, height*cellSize / 2 }, "You Won!" }
	//Initialiser medlemsvariabler, bruker også konstruktøren til Windowsklassen
{
	// Legg til alle tiles på vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			int y = i * cellSize,
				x = j * cellSize;
			tiles.push_back(new Tile{ Point{ x, y }, cellSize, cb_click });
			attach(tiles.back());
		}
	}
	
	//Legg til miner på tilfeldige posisjoner
	for (int i = 0; i < (mines); i++) {

		int randIndex = getRand(0, width*height);
		if (!tiles[randIndex].isMine) {
			tiles[randIndex].isMine = true;
		}
		else {
			i--;
		}
	}

	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}


vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

int MinesweeperWindow::countMines(vector<Point> points) const {
	int mineCount = 0;
	for (auto xy : points) {
		int xTile = xy.x / cellSize;
		int yTile = xy.y / cellSize;
		if (tiles[yTile*height + xTile].isMine) {
			mineCount++;
		}
	}
	
	return mineCount;
}

void MinesweeperWindow::openTile(Point xy) {
	int xTile = xy.x / cellSize;
	int yTile = xy.y / cellSize;
	
	if (tiles[yTile*height + xTile].state == Cell::closed && !tiles[yTile*height + xTile].isMine) {
		vector<Point> points = adjacentPoints(xy);
		int mineCount = countMines(points);
		tiles[yTile*height + xTile].setAdjMines(mineCount);

		tiles[yTile*height + xTile].open();

		if (mineCount == 0) {
			for (auto tile : points) {
				openTile(tile);
			}
		}
		checkWin();
	}
	else if (tiles[yTile*height + xTile].isMine) {
		lostGame();
	}
}

void MinesweeperWindow::flagTile(Point xy) {
	int xTile = xy.x / cellSize;
	int yTile = xy.y / cellSize;
	tiles[yTile*height + xTile].flag();
}

void MinesweeperWindow::lostGame() {
	lossText.set_color(Color::dark_green);
	lossText.set_font_size(50);
	attach(lossText);

	for (auto tile : tiles) {
		if (tile->isMine) { tile->open(); }
	}
}

void MinesweeperWindow::checkWin() {
	bool win = true;

	for (auto tile : tiles) {
		if (tile->state == Cell::closed && !tile->isMine) {
			win = false;
		}
	}

	if (win) {
		winText.set_color(Color::dark_green);
		winText.set_font_size(50);
		attach(winText);

		for (auto tile : tiles) {
			if (tile->isMine) { tile->set_label("@<"); }
		}
	}
}

//Kaller opentile ved venstreklikk og flagTile ved høyreklikk
void MinesweeperWindow::cb_click(Address, Address pw)
{
	Point xy{ Fl::event_x(),Fl::event_y() };
	MouseButton mb = static_cast<MouseButton>(Fl::event_button());
	auto& win = reference_to<MinesweeperWindow>(pw);

	if (!win.inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		win.openTile(xy);
		break;
	case MouseButton::right:
		win.flagTile(xy);
		break;
	}
	win.flush();
}
