#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QScrollArea>
#include <QPushButton>
#include <QLineEdit>
#include<qpalette.h>
#include "Graph.h"
#include"File.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);

private slots:
    void on_addNodeButton_clicked();
    
    void on_addEdgeButton_clicked();
    
    void on_displayGraphButton_clicked();
    void on_displayGraphButton1_clicked();


    void on_removeNodeButton_clicked();
    void on_removeEdgeButton_clicked();
    void on_addDirectedEdgeButton_clicked();
    void on_shortestPathButton_clicked();

    void on_exitButton_clicked();
    void on_saveButton_clicked();

    void on_getMSTButton_clicked();
    void on_getMSTButton1_clicked();





private:
    QPalette backgroundPalette;
    QLabel* displayLabel;
    QPushButton* addNodeButton;
    QLineEdit* nodeNameLineEdit;
    QPushButton* addEdgeButton;
    QLineEdit* edgeDetailsLineEdit;

    QPushButton* displayGraphButton;
    QPushButton* displayGraphButton1;


    QPushButton* getMSTButton;
    QPushButton* getMSTButton1;


    QPushButton* removeNodeButton;
    QLineEdit* removeNodeLineEdit;
    QPushButton* addDirectedEdgeButton;

    QLineEdit* fromNodeLineEdit;
    QLineEdit* toNodeLineEdit;
    QLineEdit* edgeNameLineEdit;
    QLineEdit* distanceLineEdit;

    QLineEdit* fromNodeLineEdit1;
    QLineEdit* toNodeLineEdit1;
    QLineEdit* edgeNameLineEdit1;
    QLineEdit* distanceLineEdit1;

    QLineEdit* fromNodeLineEdit2;
    QLineEdit* toNodeLineEdit2;
    QLineEdit* edgeNameLineEdit2;

    QPushButton* removeEdgeButton;
    QLineEdit* removeEdgeDetailsLineEdit;
    QPushButton* shortestPathButton;
    QLineEdit* sourceNodeLineEdit;
    QLineEdit* destinationNodeLineEdit;
    QPushButton* exitButton;

    QPushButton* saveButton;

    Graph* graph;
};

#endif // MAINWINDOW_H
