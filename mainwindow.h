#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void R_to_LEvent();
    void L_to_REvent();
    void Sort_Event();
private:
    Ui::MainWindow *ui;
    QStandardItemModel leftListModel,rightListModel;
    QListView leftView,rightView;
    QHBoxLayout mainLayout;
    QVBoxLayout buttonGroup;
    QPushButton l_to_rButton,r_to_lButton,sortButton;
};
#endif // MAINWINDOW_H
