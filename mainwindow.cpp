#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): ui(new Ui::MainWindow)
{
    connect(&l_to_rButton,SIGNAL(clicked()),this,SLOT(L_to_REvent()));
    connect(&r_to_lButton,SIGNAL(clicked()),this,SLOT(R_to_LEvent()));
    connect(&sortButton,SIGNAL(clicked()),this,SLOT(Sort_Event()));
    leftListModel.setItem(0, new QStandardItem("1"));
    leftListModel.setItem(1, new QStandardItem("2"));
    leftListModel.setItem(2, new QStandardItem("3"));
    leftListModel.setItem(3, new QStandardItem("5"));
    leftListModel.setItem(4, new QStandardItem("4"));
    rightListModel.setItem(0, new QStandardItem("7"));
    rightListModel.setItem(1, new QStandardItem("6"));
    rightListModel.setItem(2, new QStandardItem("5"));
    rightListModel.setItem(3, new QStandardItem("4"));
    leftView.setModel(&leftListModel);
    rightView.setModel(&rightListModel);
    l_to_rButton.setText(">>");
    r_to_lButton.setText("<<");
    sortButton.setText("Sort");
    buttonGroup.addWidget(&l_to_rButton);
    buttonGroup.addWidget(&sortButton);
    buttonGroup.addWidget(&r_to_lButton);
    mainLayout.addWidget(&leftView);
    mainLayout.addLayout(&buttonGroup);
    mainLayout.addWidget(&rightView);
    setLayout(&mainLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Sort_Event()
{
    leftListModel.sort(0);
    rightListModel.sort(0,Qt::DescendingOrder);

}
void MainWindow::L_to_REvent()
{
    qint32 ind;
    ind=leftView.currentIndex().row();
    if(ind<0)
        ind=0;
   if(leftListModel.rowCount()>ind){
    rightListModel.setItem(rightListModel.rowCount(),new QStandardItem(leftListModel.item(ind)->text()));
    leftListModel.removeRow(ind);}
}
void MainWindow::R_to_LEvent(){
    qint32 ind;
    ind=rightView.currentIndex().row();
    if(ind<0)
        ind=0;
    if(rightListModel.rowCount()>ind){
    leftListModel.setItem(leftListModel.rowCount(),new QStandardItem(rightListModel.item(ind)->text()));
    rightListModel.removeRow(ind);}
}
