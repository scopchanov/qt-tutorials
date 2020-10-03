#include "MainWindow.h"
#include "PixmapBuilder.h"
#include <QBoxLayout>
#include <QGraphicsRectItem>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
	auto *l = new QVBoxLayout(this);
	auto *graphicsView = new QGraphicsView(this);
	auto *item = new QGraphicsRectItem(0, 0, 100, 60);

	item->setPos(70, 90);
	item->setBrush(Qt::red);
	item->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

	graphicsView->setScene(new QGraphicsScene(this));
	graphicsView->setSceneRect(0, 0, 800, 800);
	graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	graphicsView->scene()->addItem(item);

	// Static square grid
//	graphicsView->setBackgroundBrush(QPixmap(":/pix/images/grid_square.png"));

	// Static crossed grid
//	graphicsView->setBackgroundBrush(QPixmap(":/pix/images/grid_cross.png"));

	// Static fancy grid
//	graphicsView->setBackgroundBrush(QPixmap(":/pix/images/grid_fancy.png"));

	// Dynamic square grid
//	graphicsView->setBackgroundBrush(PixmapBuilder::drawPattern(
//										 PixmapBuilder::PT_Cross, 40,
//										 "#009000"));

	// Dynamic crossed grid
//	graphicsView->setBackgroundBrush(PixmapBuilder::drawPattern(
//										 PixmapBuilder::PT_Square, 100,
//										 "#C000C0"));

	// Dynamic fancy grid
	graphicsView->setBackgroundBrush(PixmapBuilder::drawPattern(
										 PixmapBuilder::PT_Fancy, 20,
										 "#F0F000"));

	l->addWidget(graphicsView);

	resize(400, 400);
}
