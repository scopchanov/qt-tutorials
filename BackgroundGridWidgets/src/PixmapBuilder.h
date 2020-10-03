#ifndef PIXMAPBUILDER_H
#define PIXMAPBUILDER_H

#include <QPixmap>

class QPainter;

class PixmapBuilder
{	
	explicit PixmapBuilder();
public:
	enum PixmapType : int {
		PT_Square = 0,
		PT_Cross,
		PT_Fancy
	};

	static QPixmap drawPattern(int type, int size, const QColor &color);

private:
	static void drawSquare(QPainter *painter, int width, const QColor &color);
	static void drawCross(QPainter *painter, int width, const QColor &color);
	static void drawFancy(QPainter *painter, int width, const QColor &color);
};

#endif // PIXMAPBUILDER_H
