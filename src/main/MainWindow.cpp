
#include "MainWindow.h"
#include <widgets/QtOpenGLWidget.h>


MainWindow::MainWindow()
	:QMainWindow()
{
	this->resize(1024, 768);
	initWidgets();
	initToolbars();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initWidgets()
{
	_centerWidget = new QTabWidget(this);
	this->setCentralWidget(_centerWidget);

	_viewer = new QtOpenGLWidget(_centerWidget);
	_centerWidget->addTab(_viewer, tr("3D View"));
}

void MainWindow::initToolbars()
{

}

