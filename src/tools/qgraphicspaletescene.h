#ifndef QGRAPHICSPALETESCENE_H
#define QGRAPHICSPALETESCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include "../core.h"

class QGraphicsPaleteScene : public QGraphicsScene
{
	Q_OBJECT
public:

	explicit QGraphicsPaleteScene(QObject *parent = nullptr);


signals:

public slots:
	void onLayerChange();
	void onChipsetChange();
protected:

	void updateSelectionRect();

	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

	void cancelSelection();

	bool m_cancel;
	bool m_pressed;
	QGraphicsPixmapItem* m_tiles;
	QGraphicsRectItem* m_selectionItem;
	QPixmap m_lowerTiles;
	QPixmap m_upperTiles;
	QRectF last_selection;
	QPointF m_initial;
	QPointF m_current;

};

#endif // QGRAPHICSPALETESCENE_H
