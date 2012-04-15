/*
 * 	Main.cpp
 *  Gemaakt door Robbert van der Hulst, S1063848
 *
 */

#include <MAUtil/Moblet.h>
#include "FotoBewerker.hpp"

//main functie
extern "C" int MAMain()
{
	//start een Moblet app met de FotoBewerker klasse
	Moblet::run(new FotoBewerker());
	return 0;
}
