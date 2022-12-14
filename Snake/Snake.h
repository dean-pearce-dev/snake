#ifndef SNAKE_H
#define SNAKE_H

#include "SnakeHead.h"
#include "SnakeTail.h"

class Fruit;

class Snake
{
private:
	Vector2 m_bounds;

	SnakeHead m_head;
	SnakeTail m_tail;

	bool m_isAlive;

	Fruit* m_pFruit;
	int* m_pGameScore;

public:
	Snake();
	Snake( Fruit& fruit, int& gameScore );

	~Snake();

	//-------------------------------------------------------
	//	Function	:	update
	//	Purpose		:	Updates the Snake object which includes updating the Tail and Head objects, taking input,
	//					and detecting collision
	//	Parameters  :	none
	//	Returns		:	void
	//-------------------------------------------------------
	void update();

	//-------------------------------------------------------
	//	Function	:	render
	//	Purpose		:	Renders the Tail and Head objects which the Snake is composed of
	//	Parameters  :	none
	//	Returns		:	void
	//-------------------------------------------------------
	void render();

	//-------------------------------------------------------
	//	Function	:	derender
	//	Purpose		:	Derenders the Tail and Head objects to allow them to be rendered at their updated positions
	//	Parameters  :	none
	//	Returns		:	void
	//-------------------------------------------------------
	void derender();

	//-------------------------------------------------------
	//	Function	:	reset
	//	Purpose		:	Resets the snake for replaying the game without quitting
	//	Parameters  :	none
	//	Returns		:	void
	//-------------------------------------------------------
	void reset();

	//-------------------------------------------------------
	//	Function	:	isAlive
	//	Purpose		:	Returns the alive status of the snake so the game's fail state can be run when
	//					the snake is detected to be no longer alive
	//	Parameters  :	none
	//	Returns		:	bool
	//-------------------------------------------------------
	bool isAlive();

	//-------------------------------------------------------
	//	Function	:	setBounds
	//	Purpose		:	Sets the bounds that the SnakeHead is allowed to be within so that border collision
	//					can be detected 
	//	Parameters  :	const int& x, const int& y
	//	Returns		:	void
	//-------------------------------------------------------
	void setBounds( const int x, const int y );

	//-------------------------------------------------------
	//	Function	:	checkForCollision
	//	Purpose		:	Checks if the Head object has surpassed the map boundaries, or if it is colliding with a tail segment
	//	Parameters  :	none
	//	Returns		:	void
	//-------------------------------------------------------
	void checkForCollision();

	//-------------------------------------------------------
	//	Function	:	checkForFruit
	//	Purpose		:	Checks if the Head object is touching the fruit location so that the tail length and score can increase
	//					and the fruit can respawn at a new position
	//	Parameters  :	none
	//	Returns		:	void
	//-------------------------------------------------------
	void checkForFruit();

	//-------------------------------------------------------
	//	Function	:	initialCheckForFruit
	//	Purpose		:	Checks for fruit at the beginning of the game
	//	Parameters  :	none
	//	Returns		:	void
	//-------------------------------------------------------
	void initialCheckForFruit();

	//-------------------------------------------------------
	//	Function	:	getTailLength
	//	Purpose		:	Returns the length of the tail
	//	Parameters  :	none
	//	Returns		:	int&
	//-------------------------------------------------------
	int& getTailLength();

	//-------------------------------------------------------
	//	Function	:	getTailPosByIndex
	//	Purpose		:	Returns a Vector2 position of a tail segment by the specified index number
	//	Parameters  :	const int& indexOfTailSegment
	//	Returns		:	Vector2
	//-------------------------------------------------------
	Vector2 getTailPosByIndex( const int indexOfTailSegment );

	//-------------------------------------------------------
	//	Function	:	getHeadPos
	//	Purpose		:	Returns a reference to the snake head object
	//	Parameters  :	none
	//	Returns		:	SnakeHead&
	//-------------------------------------------------------
	SnakeHead& getHead();

	//-------------------------------------------------------
	//	Function	:	headCollisionCheck
	//	Purpose		:	Checks if the head is touching a tail segment
	//	Parameters  :	none
	//	Returns		:	bool
	//-------------------------------------------------------
	bool headCollisionCheck();
};

#endif // End of '#ifndef SNAKE_H'
