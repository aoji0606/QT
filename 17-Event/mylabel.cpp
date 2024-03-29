#include "mylabel.h"

MyLabel::MyLabel(QWidget* parent) : QLabel(parent)
{
	//自定义控件
	this->setMouseTracking(true);	//追踪鼠标
	this->setFont(QFont("Helvetica", 30, QFont::Normal));
	this->setAlignment(Qt::AlignCenter);
}

//鼠标按下
void MyLabel::mousePressEvent(QMouseEvent* ev)
{
	QPoint pos = ev->pos();
	QPoint global_pos = ev->globalPos();
	QString str = QString("Pos:(%1,%2)\nGlobalPos:(%3,%4)").
				  arg(pos.x()).arg(pos.y()).
				  arg(global_pos.x()).arg(global_pos.y());	//格式化输出字符串 类似sprintf

	switch (ev->button())
	{
		case Qt::LeftButton:
			str = "Press Left Button\n" + str;
			break;
		case Qt::RightButton:
			str = "Press Right Button\n" + str;
			break;
		case Qt::MidButton:
			str = "Press Mid Button\n" + str;
			break;
		default:
			break;
	}

	this->setStyleSheet("color:black;");
	this->setText(str);
}

//鼠标抬起
void MyLabel::mouseReleaseEvent(QMouseEvent* ev)
{
	QPoint pos = ev->pos();
	QPoint global_pos = ev->globalPos();
	QString str = QString("Pos:(%1,%2)\nGlobalPos:(%3,%4)").
				  arg(pos.x()).arg(pos.y()).
				  arg(global_pos.x()).arg(global_pos.y());

	switch (ev->button())
	{
		case Qt::LeftButton:
			str = "Release Left Button\n" + str;
			break;
		case Qt::RightButton:
			str = "Release Right Button\n" + str;
			break;
		case Qt::MidButton:
			str = "Release Mid Button\n" + str;
			break;
		default:
			break;
	}

	this->setStyleSheet("color:black;");
	this->setText(str);
}

//鼠标移动
void MyLabel::mouseMoveEvent(QMouseEvent* ev)
{
	QPoint pos = ev->pos();
	QPoint global_pos = ev->globalPos();
	QString str = QString("Event Intercept\nMove\nPos:(%1,%2)\nGlobalPos:(%3,%4)").
				  arg(pos.x()).arg(pos.y()).
				  arg(global_pos.x()).arg(global_pos.y());

	this->setText(str);
}

//鼠标离开
void MyLabel::leaveEvent(QEvent*)
{
	this->setStyleSheet("color:black;");
	this->setText(QString("Leave Event"));
}

//事件分发
bool MyLabel::event(QEvent* ev)
{
	//返回true 用户处理
	//返回false 父类处理

	if(ev->type() == QEvent::MouseMove)
	{
		//拦截QEvent::MouseMove
		this->setStyleSheet("color:blue;");
		QMouseEvent* e = static_cast<QMouseEvent*>(ev);
		MyLabel::mouseMoveEvent(e);

		return true;
	}
	else
	{
		//其他事件父类处理
		return QLabel::event(ev);
	}
}
