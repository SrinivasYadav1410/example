#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QVariant>
#include <QProcess>
#include <QFile>



#define SECURECERTICATE       "/mnt/jffs2/verisgin.cer"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public:
    QVariant val ;

    
private slots:

    void on_qt_clicked();

    void on_pushButton_clicked();

public:
    int prepareDealerReqFile(QString,int i);
    int requestframing(QString,int i);


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
