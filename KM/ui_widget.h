/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Sat Sep 28 17:22:22 2024
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *qt;
    QPushButton *pushButton;
    QWidget *page_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(320, 240);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 320, 240));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        qt = new QPushButton(page);
        qt->setObjectName(QString::fromUtf8("qt"));
        qt->setGeometry(QRect(90, 90, 120, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Liberation Serif"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        qt->setFont(font);
        qt->setStyleSheet(QString::fromUtf8("\n"
"border-radius:8px;background-color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 160, 97, 29));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Liberation Serif"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        qt->setText(QApplication::translate("Widget", "qt", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Widget", "service2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
