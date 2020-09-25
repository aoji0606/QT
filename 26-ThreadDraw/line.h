#ifndef LINE_H
#define LINE_H

#include <ctime>
#include <QObject>
#include <QPainter>
#include <QImage>
#include <QPen>
#include <QThread>

class Line : public QObject
{
	Q_OBJECT
public:
	explicit Line(QObject* parent = nullptr);

	void Run();
	void DrawLine();
	void SetStop(bool);

signals:
	void Update(QImage);

private:
	QPainter painter;
	QImage image;
	QPen pen;
	bool stop;
};

#endif // LINE_H
