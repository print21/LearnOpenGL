
#include <QMainWindow>

class QTabWidget;
class QtOpenGLWidget;

class MainWindow : public QMainWindow
{
	Q_OBJECT;
public:
	MainWindow();
	~MainWindow();

protected:
	void initWidgets();
	void initToolbars();

protected:
	QTabWidget * _centerWidget;
	QtOpenGLWidget * _viewer;
};
