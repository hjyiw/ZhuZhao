#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


class ZZConfigWidget;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    bool InitWidget();
private:
    QWidget* m_pMainWidget{Q_NULLPTR};
    QWidget* m_pLeftTopWidget{Q_NULLPTR};
    QWidget* m_pLeftBottomWidget{Q_NULLPTR};
    QWidget* m_pRightWidget{Q_NULLPTR};

    ZZConfigWidget* m_pConfigWidget{Q_NULLPTR};
};
#endif // MAINWINDOW_H
