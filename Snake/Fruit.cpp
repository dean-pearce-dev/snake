#include "Config.h"
#include "Fruit.h"

Fruit::Fruit()
	: Drawable	()
	, m_bounds	( Config::k_mapWidth, Config::k_mapHeight )
{
	//Setting fruit char
	setChar( 'f' );

	//Setting initial position by randomisation
	setPosByInt( Math::randomiseNum( 1, m_bounds.getX() - 1 ), Math::randomiseNum( 1, m_bounds.getY() - 1 ) );
};

void Fruit::changePos()
{
	//Derenders the fruit, then changes position by randomisation, then renders the fruit
	derender();
	setPosByInt( Math::randomiseNum( 1, m_bounds.getX() - 1 ), Math::randomiseNum( 1, m_bounds.getY() - 1 ) );
	render();
}