#include <QLabel>


class MyLabel: public QLabel {

	Q_OBJECT

public:

	MyLabel(QWidget* parent = 0);

public slots:
	void setColorR(int value);
	void setColorG(int value);
	void setColorB(int value);

private:
	void posarBackground();

	int colorR, colorG, colorB;
	QString background;

};