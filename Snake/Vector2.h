#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
private:
	int m_xPos;
	int m_yPos;

public:
	Vector2();
	Vector2( const int x, const int y );

	//-------------------------------------------------------
	//	Function	:   getX
	//	Purpose		:   Returns X value of the Vector2
	//	Parameters  :   none
	//	Returns		:   int
	//-------------------------------------------------------
	int getX() const;

	//-------------------------------------------------------
	//	Function	:   setX
	//	Purpose		:   Sets X value of the Vector2
	//	Parameters  :   int x
	//	Returns		:   void
	//-------------------------------------------------------
	void setX( int x );

	//-------------------------------------------------------
	//	Function	:   getY
	//	Purpose		:   Returns Y value of the Vector2
	//	Parameters  :   none
	//	Returns		:   int
	//-------------------------------------------------------
	int getY() const;

	//-------------------------------------------------------
	//	Function	:   setY
	//	Purpose		:   Sets Y value of the Vector2
	//	Parameters  :   int y
	//	Returns		:   void
	//-------------------------------------------------------
	void setY( int y );

	//-------------------------------------------------------
	//	Function	:   set
	//	Purpose		:   Sets x and y by copying Vector2 from paramater
	//	Parameters  :   Vector2 positionToSet
	//	Returns		:   void
	//-------------------------------------------------------
	void set( Vector2 positionToSet );

	//-------------------------------------------------------
	//	Function	:   setByInt
	//	Purpose		:   Sets x and y by copying ints from paramater,
	//					Useful for setting values without an existing Vector2
	//	Parameters  :   int x, int y
	//	Returns		:   void
	//-------------------------------------------------------
	void setByInt( int x, int y );

	//Operator overloads
	Vector2 operator+( const Vector2& other )
	{
		Vector2 rtnVal;
		rtnVal.m_xPos = m_xPos + other.m_xPos;
		rtnVal.m_yPos = m_yPos + other.m_yPos;
		return rtnVal;
	}

	Vector2 operator-( const Vector2& other )
	{
		Vector2 rtnVal;
		rtnVal.m_xPos = m_xPos - other.m_xPos;
		rtnVal.m_yPos = m_yPos - other.m_yPos;
		return rtnVal;
	}

	//Vector2 operator*( const float scale )
	//{
	//	Vector2 rtnVal;
	//	rtnVal.m_xPos = m_xPos * scale;
	//	rtnVal.m_yPos = m_yPos * scale;
	//	return rtnVal;
	//}

	//Vector2 operator/( const float divisor )
	//{
	//	Vector2 rtnVal;
	//	rtnVal.m_xPos = m_xPos / divisor;
	//	rtnVal.m_yPos = m_yPos / divisor;
	//	return rtnVal;
	//}

	bool operator==( const Vector2& other )
	{
		return ( m_xPos == other.m_xPos && m_yPos == other.m_yPos );
	}
};

#endif // End of '#ifndef VECTOR2_H'
