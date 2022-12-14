#ifndef FRUIT_H
#define FRUIT_H

#include "Drawable.h"

class Fruit : public Drawable
{
private:
	Vector2 m_bounds;

public:
	Fruit();

	//-------------------------------------------------------
	//	Function	:	changePos
	//	Purpose		:	Changes the fruit position, used for when the Snake Head collides with the Fruit
	//	Parameters  :	none
	//	Returns		:	void
	//-------------------------------------------------------
	void changePos();
};

#endif // End of '#ifndef FRUIT_H'