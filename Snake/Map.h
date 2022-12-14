#ifndef MAP_H
#define MAP_H

class Map
{
private:
	int m_height;
	int m_width;

	const char m_borderChar;

public:
	Map();

	//-------------------------------------------------------
	//	Function	:	render
	//	Purpose		:	Draws the map border so the playspace is easily visible to the user
	//	Parameters  :	none
	//	Returns		:	void
	//-------------------------------------------------------
	void render();

	//-------------------------------------------------------
	//	Function	:	getHeight
	//	Purpose		:	Returns the Height boundary of the map
	//	Parameters  :	none
	//	Returns		:	int&
	//-------------------------------------------------------
	int getHeight();

	//-------------------------------------------------------
	//	Function	:	setHeight
	//	Purpose		:	Sets the Height boundary of the map via paramater
	//	Parameters  :	const int& height
	//	Returns		:	void
	//-------------------------------------------------------
	void setHeight( const int height );

	//-------------------------------------------------------
	//	Function	:	getWidth
	//	Purpose		:	Returns the width boundary of the map
	//	Parameters  :	none
	//	Returns		:	int&
	//-------------------------------------------------------
	int getWidth();

	//-------------------------------------------------------
	//	Function	:	setWidth
	//	Purpose		:	Sets the width boundary of the map via paramater
	//	Parameters  :	const int& width
	//	Returns		:	void
	//-------------------------------------------------------
	void setWidth( const int width );
};

#endif // End of '#ifndef MAP_H'
