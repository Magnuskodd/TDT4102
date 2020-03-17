#include "MinesweeperWindow.h"

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	Fl::background(200, 200, 200);
	constexpr int width = 16;
	constexpr int height = 17;
	constexpr int mines = 50;

	Point startPoint{ 200,300 };
	MinesweeperWindow mw{ startPoint, width, height, mines, "Minesweeper" };
	return gui_main();

}
