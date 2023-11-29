//
// Created by user on 28.11.2023.
//

#ifndef HOTEL_MAINTABWINDOW_H
#define HOTEL_MAINTABWINDOW_H

#include <QDialog>
#include <QTabWidget>
#include <QDialogButtonBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainTabWindow; }
QT_END_NAMESPACE

class MainTabWindow : public QDialog {
Q_OBJECT

public:
    explicit MainTabWindow(QWidget *parent = nullptr);

    ~MainTabWindow() override;

private:
    QTabWidget *tabWidget;
    Ui::MainTabWindow *ui;
};


#endif //HOTEL_MAINTABWINDOW_H
