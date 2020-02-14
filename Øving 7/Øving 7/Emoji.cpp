#include "Emoji.h"

/*
 * Implement your emojis in this file.
 **/



 // A yellow, empty face.
Face::Face(Point c, int r) : faceMask{ c, r } {
	faceMask.set_color(Color::black);
	faceMask.set_fill_color(Color::yellow);
}

void Face::attach_to(Graph_lib::Window& win)
{
	win.attach(faceMask);
}


// A yellow, empty, drawable face with eyes.
EmptyFace::EmptyFace(Point c, int r) : Face{c, r}, 
	leftEye{ Point{ c.x - r / 2, c.y - r / 8 }, r / 5 },
	rightEye{ Point { c.x + r / 2, c.y - r / 8 }, r / 5 }{

	leftEye.set_color(Color::black);
	leftEye.set_fill_color(Color::black);
	rightEye.set_color(Color::black);
	rightEye.set_fill_color(Color::black);

}

void EmptyFace::attach_to(Graph_lib::Window& win) {
	Face::attach_to(win);
	win.attach(leftEye);
	win.attach(rightEye);
}


//A smiley!
SmileyFace::SmileyFace(Point c, int r) : EmptyFace{ c,r }, mouth{ Point{c.x, c.y + r / 8}, r, r, 270-45.0, 270.0+45.0 }{
	mouth.set_color(Color::black);
	mouth.set_style(Line_style(Line_style::solid, 5));
}

void SmileyFace::attach_to(Graph_lib::Window& win) {
	EmptyFace::attach_to(win);
	win.attach(mouth);
}

//A sad face.
SadFace::SadFace(Point c, int r) : EmptyFace{ c,r }, mouth{ Point{c.x,c.y + r },r,r,90.0 - 45.0,90.0 + 45.0 }{
	mouth.set_color(Color::black);
	mouth.set_style(Line_style(Line_style::solid, 5));
}

void SadFace::attach_to(Graph_lib::Window& win) {
	EmptyFace::attach_to(win);
	win.attach(mouth);
}

//A N G E R Y: TODO: Får ikke Line til å vises.
AngryFace::AngryFace(Point c, int r) : EmptyFace{ c,r },
	mouth{ Point{c.x,c.y + r },r,r,90.0 - 45.0,90.0 + 45.0 },
	x1{ 3 * r / 5 }, y1{ 4 * r / 5 },
	x2{ r / 8 }, y2{ 2 * r / 3 },
	lFrown{ Point{c.x - x1, c.y - y1}, Point{c.x - x2, c.y - y2} },
	rFrown{ Point{c.x + x1, c.y - y1}, Point{c.x + x2, c.y - y2} }{
	
	mouth.set_color(Color::black);
	mouth.set_style(Line_style(Line_style::solid, 4));
	lFrown.set_color(Color::black);
	lFrown.set_style(Line_style(Line_style::solid, 4));
	rFrown.set_color(Color::black);
	rFrown.set_style(Line_style(Line_style::solid, 4));
}

void AngryFace::attach_to(Graph_lib::Window& win) {
	EmptyFace::attach_to(win);
	win.attach(mouth);
	win.attach(lFrown);
	win.attach(rFrown);
}

//Winking Emoji
WinkingFace::WinkingFace(Point c, int r) : Face{ c, r }, mouth{ Point{c.x, c.y + r / 8}, r, r, 270 - 45.0, 270.0 + 45.0 },
leftEye{ Point{ c.x - r / 2, c.y - r / 8 }, r / 5 }, wink{ Point{ c.x + r / 2, c.y - r / 12 }, r/2, r/2, 0.0, 180.0 }{
	mouth.set_color(Color::black);
	mouth.set_style(Line_style(Line_style::solid, 5));
	wink.set_color(Color::black);
	wink.set_style(Line_style(Line_style::solid, 5));
	leftEye.set_color(Color::black);
	leftEye.set_fill_color(Color::black);
}

void WinkingFace::attach_to(Graph_lib::Window& win) {
	Face::attach_to(win);
	win.attach(mouth);
	win.attach(wink);
	win.attach(leftEye);
}

//Surprised emoji, :O
SurprisedFace::SurprisedFace(Point c, int r) : EmptyFace{ c,r }, mouth{ Point{c.x, c.y + r / 2}, r/2, r / 4 }{
	mouth.set_color(Color::black);
	mouth.set_style(Line_style(Line_style::solid, 5));
}

void SurprisedFace::attach_to(Graph_lib::Window& win) {
	EmptyFace::attach_to(win);
	win.attach(mouth);
}

void printEmoji(Vector_ref<Emoji>& emojis, Graph_lib::Window& win) {
	for (auto emoji : emojis) {
		emoji->attach_to(win);
	}
}