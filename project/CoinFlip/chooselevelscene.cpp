#include "chooselevelscene.h"
#include <QMenuBar>
#include <QAction>
#include <QPainter>
#include <mypushbutton.h>
#include <QTimer>
#include <QLabel>
#include <playscene.h>
#include <QSound>

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    // 设置窗口固定大小
    this->setFixedSize(420,680);
    // 设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    // 设置标题
    this->setWindowTitle("选择关卡");

    // 创建菜单栏
    QMenuBar * bar = this->menuBar();
    this->setMenuBar(bar);
    // 创建开始菜单
    QMenu * startMenu = bar->addMenu("开始");
    // 创建按钮菜单栏
    QAction * quitAction = startMenu->addAction("退出");
    // 退出游戏
    connect(quitAction, &QAction::triggered, [=](){this->close();});

    // 选择关卡按钮音效
    QSound * chooseSound = new QSound(":/res/TapButtonSound.wav",this);
    QSound * backSound = new QSound(":/res/BackButtonSound.wav",this);
    // 返回按钮
    MyPushButton * closeBtn = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    closeBtn->setParent(this);

    closeBtn->move(this->width() - closeBtn->width(),this->height() - closeBtn->height());

    connect(closeBtn, &MyPushButton::clicked, [=](){
        QTimer::singleShot(500,this,[=](){
            backSound->play();
            this->hide();
            // 触发自定义信号，关闭自身，该信号写到signals下作声明
            emit this->chooseSceneBack();
        });
    });

    // 创建关卡按钮
    for(int i = 0; i < 20;i++) {
        MyPushButton * menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(70 + (i % 4) * 70, 180 + (i / 4) * 70);

        connect(menuBtn, &MyPushButton::clicked,[=](){
            if(pScene == NULL)  // 游戏场景最好不用复用，直接移除掉创建新的场景
            {
                chooseSound->play();
                this->hide();
                pScene = new PlayScene(i + 1);  // 将选择的关卡号，传递给PlayerScene
                pScene->show();

                // PlayScene的返回按钮监听，删除该scene并且将指针指向空
                connect(pScene, &PlayScene::chooseSceneBack, [=](){
                    this->show();
                    delete pScene;
                    pScene = NULL;
                });

            }
        });

        // 按钮上显示的文字
        QLabel * label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i + 1));
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);       // 设置剧中
        label->move(70 + (i % 4) * 70, 180 + (i / 4) * 70);
        label->setAttribute(Qt::WA_TransparentForMouseEvents, true);    // 鼠标事件穿透
    }

}

void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    // 加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap( (this->width() - pix.width()) * 0.5, 30, pix.width(),pix.height(),pix);
}
