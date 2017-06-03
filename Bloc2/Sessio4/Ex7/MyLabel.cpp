#include "MyLabel.h"


MyLabel::MyLabel(QWidget* parent): QLabel(parent) {
	colorR = colorB = colorG = 0;
	posarBackground();
}


void MyLabel::posarBackground() {
	background = QString("background-color: rgb(%1,%2,%3)").arg(colorR).arg(colorG).arg(colorB);
	this->setStyleSheet(background);
}

void MyLabel::setColorR(int value) {
	colorR = value;
	posarBackground();
}
void MyLabel::setColorG(int value) {
	colorG = value;
	posarBackground();
}
void MyLabel::setColorB(int value) {
	colorB = value;
	posarBackground();
}




