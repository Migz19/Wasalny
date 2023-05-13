#include "mainwindow.h"
#include <iostream>
#include <QString>
#include"GraphException.h"
#include<exception>
#include <QMessageBox>
#include<qapplication>
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    //backgroundPalette.setColor(QPalette::Window, QColor(255, 0, 100));  // Change the color to your desired color
    //setAutoFillBackground(true);
    //setPalette(backgroundPalette);

    //setStyleSheet("MainWindow { background-image: url(back.jpg);background-repeat: no-repeat; background-position: center; background-size: cover; }");

    
    resize(1300, 800);
    // Set up the UI
    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setGeometry(50, 450, 1000, 300);
    scrollArea->setWidgetResizable(true);

    // Set up the display label
    displayLabel = new QLabel(scrollArea);
    displayLabel->setGeometry(0, 0, 1000, 500);
    displayLabel->setAlignment(Qt::AlignTop);
    displayLabel->setWordWrap(true);

    // Set up the font size of displayLabel
    QFont font = displayLabel->font();
    font.setPointSize(14);
    displayLabel->setFont(font);

    // Set the displayLabel as the widget for the scroll area
    scrollArea->setWidget(displayLabel);


    // Increase the font size of displayLabel
    QFont font1 = displayLabel->font();
    font1.setPointSize(14);  // Set the desired font size
    displayLabel->setFont(font1);


    addNodeButton = new QPushButton("Add City", this);
    addNodeButton->setGeometry(150, 90, 100, 30);

    nodeNameLineEdit = new QLineEdit(this);
    nodeNameLineEdit->setGeometry(250, 90, 170, 30);
    nodeNameLineEdit->setPlaceholderText("City name");
     

    removeNodeButton = new QPushButton("Remove City", this);
    removeNodeButton->setGeometry(500,90, 130, 30);

    removeNodeLineEdit = new QLineEdit(this);
    removeNodeLineEdit->setGeometry(650, 90, 140, 30);
    removeNodeLineEdit->setPlaceholderText("City name");
     

    addEdgeButton = new QPushButton("Add two ways Road", this);
    addEdgeButton->setGeometry(150, 150, 150, 30);

    fromNodeLineEdit1 = new QLineEdit(this);
    fromNodeLineEdit1->setGeometry(300, 150, 150, 30);
    fromNodeLineEdit1->setPlaceholderText("From");

    toNodeLineEdit1 = new QLineEdit(this);
    toNodeLineEdit1->setGeometry(460, 150, 150, 30);
    toNodeLineEdit1->setPlaceholderText("To");

    edgeNameLineEdit1 = new QLineEdit(this);
    edgeNameLineEdit1->setGeometry(620, 150, 150, 30);
    edgeNameLineEdit1->setPlaceholderText("Road name");

    distanceLineEdit1 = new QLineEdit(this);
    distanceLineEdit1->setGeometry(780, 150, 150, 30);
    distanceLineEdit1->setPlaceholderText("distance");

    displayGraphButton = new QPushButton("Display (BFS)", this);
    displayGraphButton->setGeometry(150, 390, 130, 30);

    displayGraphButton1 = new QPushButton("Display (DFS)", this);
    displayGraphButton1->setGeometry(300, 390, 130, 30);

    getMSTButton = new QPushButton("MST(prim)", this);
    getMSTButton->setGeometry(600, 390, 130, 30);

    getMSTButton1 = new QPushButton("MST(kruskal)", this);
    getMSTButton1->setGeometry(450, 390, 130, 30);

    removeEdgeButton = new QPushButton("Remove Road", this);
    removeEdgeButton->setGeometry(150, 250, 150, 30);

    fromNodeLineEdit2 = new QLineEdit(this);
    fromNodeLineEdit2->setGeometry(300, 250, 150, 30);
    fromNodeLineEdit2->setPlaceholderText("From");


    toNodeLineEdit2 = new QLineEdit(this);
    toNodeLineEdit2->setGeometry(460, 250, 150, 30);
    toNodeLineEdit2->setPlaceholderText("To");


    edgeNameLineEdit2 = new QLineEdit(this);
    edgeNameLineEdit2->setGeometry(620, 250, 150, 30);
    edgeNameLineEdit2->setPlaceholderText("Road name");


    addDirectedEdgeButton = new QPushButton("Add One way road", this);
    addDirectedEdgeButton->setGeometry(150, 200, 150, 30);

    fromNodeLineEdit = new QLineEdit(this);
    fromNodeLineEdit->setGeometry(300, 200, 150, 30);
    fromNodeLineEdit->setPlaceholderText("From");

    toNodeLineEdit = new QLineEdit(this);
    toNodeLineEdit->setGeometry(460, 200, 150, 30);
    toNodeLineEdit->setPlaceholderText("To");

    edgeNameLineEdit = new QLineEdit(this);
    edgeNameLineEdit->setGeometry(620, 200, 150, 30);
    edgeNameLineEdit->setPlaceholderText("Road name");

    distanceLineEdit = new QLineEdit(this);
    distanceLineEdit->setGeometry(780, 200, 150, 30);
    distanceLineEdit->setPlaceholderText("Distance");

    shortestPathButton = new QPushButton("Shortest Path", this);
    shortestPathButton->setGeometry(150, 300, 150, 30);

    sourceNodeLineEdit = new QLineEdit(this);
    sourceNodeLineEdit->setGeometry(300, 300, 150, 30);
    sourceNodeLineEdit->setPlaceholderText("From");

    destinationNodeLineEdit = new QLineEdit(this);
    destinationNodeLineEdit->setGeometry(460, 300, 150, 30);
    destinationNodeLineEdit->setPlaceholderText("To");

    exitButton = new QPushButton("Exit", this);
    exitButton->setGeometry(850, 390, 100, 30);

    saveButton = new QPushButton("Save", this);
    saveButton->setGeometry(1000, 390, 100, 30);

    // Create the graph instance
    graph = Graph::getInstance();

    // Connect signals and slots
    connect(addNodeButton, &QPushButton::clicked, this, &MainWindow::on_addNodeButton_clicked);
    connect(addEdgeButton, &QPushButton::clicked, this, &MainWindow::on_addEdgeButton_clicked);
    connect(displayGraphButton, &QPushButton::clicked, this, &MainWindow::on_displayGraphButton_clicked);
    connect(displayGraphButton1, &QPushButton::clicked, this, &MainWindow::on_displayGraphButton1_clicked);


    connect(removeNodeButton, &QPushButton::clicked, this, &MainWindow::on_removeNodeButton_clicked);
    connect(addDirectedEdgeButton, &QPushButton::clicked, this, &MainWindow::on_addDirectedEdgeButton_clicked);
    connect(exitButton, &QPushButton::clicked, this, &MainWindow::on_exitButton_clicked);
    connect(removeEdgeButton, &QPushButton::clicked, this, &MainWindow::on_removeEdgeButton_clicked);
    connect(shortestPathButton, &QPushButton::clicked, this, &MainWindow::on_shortestPathButton_clicked);

    connect(saveButton, &QPushButton::clicked, this, &MainWindow::on_saveButton_clicked);

    connect(getMSTButton, &QPushButton::clicked, this, &MainWindow::on_getMSTButton_clicked);
    connect(getMSTButton1, &QPushButton::clicked, this, &MainWindow::on_getMSTButton1_clicked);


}

void MainWindow::on_addNodeButton_clicked()
{
    QString nodeName = nodeNameLineEdit->text();
    string node = nodeName.toStdString();
    try
    {
        graph->addNode(node);
        displayLabel->setText("City added: " + nodeName);
    }
    catch (const GraphException& ex)
    {
        string msg = "The city already exists";
        displayLabel->setText(QString::fromStdString(msg));

    }

    nodeNameLineEdit->clear();
}

void MainWindow::on_addEdgeButton_clicked()
{
    QString fromNode = fromNodeLineEdit1->text();
    QString toNode = toNodeLineEdit1->text();
    QString edgeName = edgeNameLineEdit1->text();
    QString distance = distanceLineEdit1->text();

    string from = fromNode.toStdString();
    string to = toNode.toStdString();
    string edge = edgeName.toStdString();
    int dist = distance.toInt();

    try
    {
        graph->addUnDirectedEdge(from, to, edge, dist);
        displayLabel->setText("Two ways road added: " + edgeName + " with distance" + distance + " km");
    }
    catch (const GraphException& ex)
    {
        string msg = "can't add road";
        displayLabel->setText(QString::fromStdString(msg));
    }
    fromNodeLineEdit1->clear();
    toNodeLineEdit1->clear();
    edgeNameLineEdit1->clear();
    distanceLineEdit1->clear();

    
}
void MainWindow::on_displayGraphButton_clicked()
{
    vector<std::string> graphData = graph->display(useBfs);
    string result;

    for (const auto& data : graphData)
    {
        result += data + "\n";
    }

    displayLabel->setText(QString::fromStdString(result));
}
void MainWindow::on_displayGraphButton1_clicked()
{
    vector<std::string> graphData = graph->display(useDfs);
    string result;


    for (const auto& data : graphData)
    {
        result += data + "\n";
    }

    displayLabel->setText(QString::fromStdString(result));
}
void MainWindow::on_removeNodeButton_clicked()
{
    QString nodeToRemove = removeNodeLineEdit->text().trimmed();
    removeNodeLineEdit->clear();

    try
    {
        graph->removeNode(nodeToRemove.toStdString());
        displayLabel->setText("City " +nodeToRemove+" removed successfully!");
    }
    catch (const GraphException& exception)
    {
        string msg="This city doesn't exist";
        displayLabel->setText(QString::fromStdString(msg));
    }
}

void MainWindow::on_addDirectedEdgeButton_clicked()
{
    QString fromNode = fromNodeLineEdit->text();
    QString toNode = toNodeLineEdit->text();
    QString edgeName = edgeNameLineEdit->text();
    QString distance = distanceLineEdit->text();

    string from = fromNode.toStdString();
    string to = toNode.toStdString();
    string edge = edgeName.toStdString();
    int dist = distance.toInt();

    try
    {
        graph->addDirectedEdge(from, to, edge, dist);
        displayLabel->setText("Directed edge added: " + edgeName + " (" + distance + " km)");
    }
    catch (const GraphException& ex)
    {
        string msg="can't add road";
        displayLabel->setText(QString::fromStdString(msg));
    }
    fromNodeLineEdit->clear();
    toNodeLineEdit->clear();
    edgeNameLineEdit->clear();
    distanceLineEdit->clear();
}

void MainWindow::on_removeEdgeButton_clicked()
{
    QString fromNode = fromNodeLineEdit2->text();
    QString toNode = toNodeLineEdit2->text();
    QString edgeName = edgeNameLineEdit2->text();

    string from = fromNode.toStdString();
    string to = toNode.toStdString();
    string edge = edgeName.toStdString();
  //  bool flag = 1;
    try
    {
        graph->removeEdge(fromNode.toStdString(), toNode.toStdString(), edgeName.toStdString());
        displayLabel->setText("Road removed successfully!");
    //    flag = 0;
    }
    catch (const GraphException& ex)
    {
        
        string msg = "Cannot remove the road. Either the city or the road itself doesn't exist.";
        displayLabel->setText(QString::fromStdString(msg));
      //  flag = 0;
    }
    
    //if(flag)
    fromNodeLineEdit2->clear();
    toNodeLineEdit2->clear();
    edgeNameLineEdit2->clear();


}

void MainWindow::on_exitButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exit", "Are you sure you want to exit?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        File file;
        file.save();

        QApplication::quit();
    }
}
void MainWindow::on_saveButton_clicked()
{
    File file;
    file.save();
    displayLabel->setText(QString::fromStdString("data saved"));

}
void MainWindow::on_getMSTButton_clicked()
{
    vector<std::string> graphData = graph->getMST(usePrim);
    string result;


    for (const auto& data : graphData)
    {
        result += data + "\n";
    }

    displayLabel->setText(QString::fromStdString(result));
}
void MainWindow::on_getMSTButton1_clicked()
{
    vector<std::string> graphData = graph->getMST(useKruskal);
    string result;


    for (const auto& data : graphData)
    {
        result += data + "\n";
    }

    displayLabel->setText(QString::fromStdString(result));
}
void MainWindow::on_shortestPathButton_clicked()
{
    QString sourceNode = sourceNodeLineEdit->text();
    QString destinationNode = destinationNodeLineEdit->text();

    string source = sourceNode.toStdString();
    string destination = destinationNode.toStdString();

    try
    {
        stack<std::pair<std::string, int>> shortestPath = graph->getShortestPath(source, destination);
        int totalDis=0;
        string result;
        while (!shortestPath.empty())
        {
            result +="->"+ shortestPath.top().first + " (" + std::to_string(shortestPath.top().second) + " km)";
            totalDis += shortestPath.top().second;
            shortestPath.pop();

        }
        result += "with total distance " +to_string(totalDis) + "km \n";

        displayLabel->setText(QString::fromStdString(result));
    }
    catch (const GraphException& ex)
    {
        string errorMsg = "Cannot find the shortest path between " + source + " and " + destination;
        displayLabel->setText(QString::fromStdString(errorMsg));
    }

    sourceNodeLineEdit->clear();
    destinationNodeLineEdit->clear();
}
