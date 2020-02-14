#pragma once

// Include Graph_lib library files that holds declarations needed for Window,
// and Shape derivatives.
#include "Graph.h"
#include "GUI.h"

// This part is only relevant for non-Windows users in 2019.
// Windows users has Graph_lib::Arc, Mac don't.
#ifndef WIN32
#include "Graph_lib.h"
#endif

using namespace Graph_lib;

// An abstract class. Concrete classes derived from this base class
// has to implement the member function attach_to().
class Emoji
{
public:
	// Disable copying. Disable slicing, etc.
	Emoji(const Emoji&) = delete;
	Emoji& operator=(const Emoji&) = delete;

	// Deleting the copy constructor also deletes the default constructor.
	// Emoji needs a default constructor.
	Emoji() {}

	// The pure virtual function that has to be overriden for a deriving class
	// to be instantiable. Every class deriving from Emoji is supposed to
	// attach all its Shapes to a window. This makes the class abstract.
	virtual void attach_to(Graph_lib::Window&) = 0;

	// Relevant because Vector_ref can own Emojis and automatically cleans up.
	// Subject will be visited later in the course.
	virtual ~Emoji() {}
};

// A yellow, empty face.
// An abstract class.
class Face : public Emoji
{
private:
	Circle faceMask;


public:
	Face(const Face&) = delete;
	Face& operator=(const Face&) = delete;
	virtual ~Face() {};

	Face(Point c, int r);
	virtual void attach_to(Graph_lib::Window& win) override;
};


// A yellow, empty, drawable face with eyes.
class EmptyFace : public Face {
private:
	Circle leftEye;
	Circle rightEye;

public:
	EmptyFace(Point c, int r);
	void attach_to(Graph_lib::Window& win) override;
};

//A smiley!
class SmileyFace : public EmptyFace {
private:
	Arc mouth;

public:
	SmileyFace(Point c, int r);
	void attach_to(Graph_lib::Window& win) override;
};

//A sad emoji
class SadFace : public EmptyFace {
private:
	Arc mouth;

public:
	SadFace(Point c, int r);
	void attach_to(Graph_lib::Window& win) override;
};

//A N G E R Y 
class AngryFace : public EmptyFace {
private:
	Line lFrown;
	Line rFrown;
	Arc mouth;
	int x1;
	int y1;
	int x2;
	int y2;


public:
	AngryFace(Point c, int r);
	void attach_to(Graph_lib::Window& win) override;
};

//Winking Emoji
class WinkingFace : public Face {
private:
	Arc mouth;
	Circle leftEye;
	Arc wink;

public:
	WinkingFace(Point c, int r);

	void attach_to(Graph_lib::Window& win) override;

};

//Suprised emoji, :O
class SurprisedFace : public EmptyFace {
private:
	Ellipse mouth;

public:
	SurprisedFace(Point c, int r);

	void attach_to(Graph_lib::Window& win) override;

};

void printEmoji(Vector_ref<Emoji>& emojis, Graph_lib::Window& win);