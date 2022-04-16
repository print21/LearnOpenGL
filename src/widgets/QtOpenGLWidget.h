
#include <QOpenGLWidget>

class QtOpenGLWidget : public QOpenGLWidget
{
	Q_OBJECT;
public:
	explicit QtOpenGLWidget(QWidget * parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
	~QtOpenGLWidget();

protected:
	virtual void initializeGL() override;
	virtual void resizeGL(int w, int h) override;
	virtual void paintGL() override;
};

