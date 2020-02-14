#include "Simple_window.h"
#include "Graph.h"
#include "Emoji.h"

// Size of window and emoji radius
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main()
{
	using namespace Graph_lib;

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};

	/* TODO:
	 *  - initialize emojis
	 *  - connect emojis to window
	 **/

	/*SmileyFace test(Point{ win.x_max() / 2, win.y_max() / 2 }, emojiRadius);
	test.attach_to(win);

	SadFace sad(Point{ 50,50 }, emojiRadius);
	sad.attach_to(win);

	AngryFace anger(Point{ 150,150 }, emojiRadius);
	anger.attach_to(win);
	
	WinkingFace winkFace(Point{ 250,50 }, emojiRadius);
	winkFace.attach_to(win);

	SurprisedFace surprised(Point{ 350, 50 }, emojiRadius);
	surprised.attach_to(win);*/

	Vector_ref<Emoji> emojis;
	emojis.push_back(new SmileyFace{ Point{50,50}, emojiRadius });
	emojis.push_back(new SadFace{ Point {150,50}, emojiRadius });
	emojis.push_back(new AngryFace{ Point{250,50}, emojiRadius });
	emojis.push_back(new WinkingFace{ Point{350, 50}, emojiRadius });
	emojis.push_back(new SurprisedFace{ Point{450, 50}, emojiRadius });

	printEmoji(emojis, win);

	win.wait_for_button();

}
