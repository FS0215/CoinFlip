#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QString>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);
    // normalImg 代表正常显示的图片
    // pressImg  代表按下后显示的图片，默认为空
    MyPushButton(QString normalImg, QString pressImg = "");

    void zoom1();
    void zoom2();

    QString normalImgPath;      // 默认显示图片路径
    QString pressedImgPath;     // 按下后显示图片路径

    // 鼠标按下事件
    void mousePressEvent(QMouseEvent *e);
    // 鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *e);
signals:

};

#endif // MYPUSHBUTTON_H
