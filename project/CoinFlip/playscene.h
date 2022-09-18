#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QWidget>
#include <mycoin.h>
class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
//    explicit PlayScene(QWidget *parent = nullptr);
//    PlayScene();
    PlayScene(int levelNum);

    // 成员变量  记录关卡索引
    int levalIndex;

    int gameArray[4][4];    // 二维数组数据

    MyCoin* coinBtn[4][4];  // 金币数组按钮

    bool isWin = true;      // 是否胜利

    void paintEvent(QPaintEvent *);

signals:
    // 用于返回 选择观其场景 的信号函数
    void chooseSceneBack();
};

#endif // PLAYSCENE_H
