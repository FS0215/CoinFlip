#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include <playscene.h>
class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);

    PlayScene* pScene = NULL;

signals:
    // 选择返回的信号函数
    void chooseSceneBack();

};

#endif // CHOOSELEVELSCENE_H
