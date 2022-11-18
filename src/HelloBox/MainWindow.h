

#include <QMainWindow>

class View3dGL;
class ModelControlWidget;
class TransformationInfoWidget;
class ViewControlWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT;
public:
    explicit MainWindow(QWidget * parent = nullptr);
    ~MainWindow();

protected:
    void initView();

protected:
    View3dGL * _view3d;
    ModelControlWidget * _modelControl;
    ViewControlWidget * _viewControl;
    TransformationInfoWidget * _infoView;
};


