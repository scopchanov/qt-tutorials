#include "PixmapBuilder.h"
#include <QPainter>

PixmapBuilder::PixmapBuilder()
{

}

QPixmap PixmapBuilder::drawPattern(int type, int step, const QColor &color)
{
	QPixmap pixmap(step, step);
	QPainter painter;
	int pixmapWidth = pixmap.width() - 1;

	pixmap.fill(Qt::transparent);

	painter.begin(&pixmap);

	switch (type) {
	case PT_Square:
		drawSquare(&painter, pixmapWidth, color);
		break;
	case PT_Cross:
		drawCross(&painter, pixmapWidth, color);
		break;
	case PT_Fancy:
		drawFancy(&painter, pixmapWidth, color);
		break;
	}

	return pixmap;
}

void PixmapBuilder::drawSquare(QPainter *painter, int width, const QColor &color)
{
	painter->setPen(color);
	painter->drawLine(0, 0, width, 0);
	painter->drawLine(0, 0, 0, width);
}

void PixmapBuilder::drawCross(QPainter *painter, int width, const QColor &color)
{
	painter->setPen(color);
	painter->drawLine(0, 0, 2, 0);
	painter->drawLine(0, 0, 0, 2);
	painter->drawLine(0, width - 1, 0, width);
	painter->drawLine(width - 1, 0, width, 0);
}

void PixmapBuilder::drawFancy(QPainter *painter, int width, const QColor &color)
{
	int halfWidth = 0.5*width + 0.5;

	painter->setPen(color.lighter(106));
	painter->drawLine(0, halfWidth, width, halfWidth);
	painter->drawLine(halfWidth, 0, halfWidth, width);
	painter->setPen(color);
	painter->drawLine(0, 0, width, 0);
	painter->drawLine(0, 0, 0, width);
	painter->setPen(color.darker(118));
	painter->drawPoint(halfWidth, halfWidth);
	painter->setPen(color.darker(160));
	painter->drawPoint(0, 0);
}
