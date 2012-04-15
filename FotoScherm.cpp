/*
 * 	Fotoscherm.cpp
 *  Gemaakt door Robbert van der Hulst, S1063848
 *
 */

#include "FotoScherm.hpp"

FotoScherm::FotoScherm()
{

	//het optiescherm
			this->optieScherm = new OptieScherm( this );

	//Bepaal grootte van het scherm
	MAExtent screenSize = maGetScrSize();
	int screenWidth = EXTENT_X( screenSize );
	int screenHeight = EXTENT_Y( screenSize );

	//standaard font en grafisch uiterlijk (uit de resource file res.lst)
	Font* font = new MAUI::Font(RES_FONT);
	WidgetSkin* skin = new WidgetSkin( RES_SELECTED, RES_UNSELECTED, 16, 32, 16, 32, false, false );

	//maak een label die andere widgets straks bevat, en een achtergrondkleur heeft
	achtergrondLabel = new Label(0,0,0,0,NULL);

	//Dit geeft het scherm de kleur zwart.
		achtergrondLabel->setBackgroundColor(0x000000);

	//maak een plaatje (laden uit de resource file res.lst) en voeg label als parent toe
	image = new Image(screenWidth/2-60,screenHeight/2-60, 120, 160, achtergrondLabel, false, false, RES_IMAGE);

	// maak tekst bij het plaatje met een label
	imageTekst = new Label( screenWidth/2 - 40, 250, 80, 30, achtergrondLabel, "", 0, font);
	imageTekst->setSkin(skin);
	imageTekst->setPaddingLeft(1);
	imageTekst->setPaddingTop(1);

	//dit scherm als standaard, met achtergrondlabel als basis widget
	this->setMain(achtergrondLabel);


}

FotoScherm::~FotoScherm()
{

}


//show() override de show() van de super klasse (Screen), omdat we bij showen eerst opties willen ophalen
void FotoScherm::show()
{
	//roep de show() van de superklasse (Screen) aan
	this->Screen::show();

	//haal informatie achtergrondkleur op van optiescherm
	this->achtergrondLabel->setBackgroundColor( this->optieScherm->getAchtergrondOptie() );

	//haal informatie imagetekst op van optiescherm
	imageTekst->setCaption(this->optieScherm->getImagetekst());

	//haal informatie over afmetingen afbeeldingen
	this->image->setWidth(this->optieScherm->getImageSize());
	this->image->setHeight(this->optieScherm->getImageSize());
}


//afvangen invoer
void FotoScherm::keyPressEvent(int keyCode, int nativeCode)
{
	//bij indrukken van de MAK_FIRE toets, laat optiescherm zien

	if (keyCode == MAK_FIRE)
	{
		optieScherm->show();
	}
}


void FotoScherm::pointerPressEvent(MAPoint2d point)
{
	//bij touch op scherm, laat optiescherm zien.
	optieScherm->show();
}
