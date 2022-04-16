
#include <gl/glew.h>
#include "QtOpenGLWidget.h"

#include <gl/GLFunc.h>

#include <iostream>

QtOpenGLWidget::QtOpenGLWidget(QWidget * parent /*= nullptr*/, Qt::WindowFlags f /*= Qt::WindowFlags()*/)
	:QOpenGLWidget(parent, f)
{

}

QtOpenGLWidget::~QtOpenGLWidget()
{

}

void QtOpenGLWidget::initializeGL()
{
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		std::cerr << "Error: " << glewGetErrorString(err) << "\n";
	}
	else
	{
		std::cout << "OpenGL version: " << glGetString(GL_VERSION) << "\n";
		std::cout << "OpenGL renderer: " << glGetString(GL_RENDERER) << "\n";
		std::cout << "OpenGL vendor: " << glGetString(GL_VENDOR) << "\n";
		std::cout << "GLEW version: " << glewGetString(GLEW_VERSION) << "\n";
	}
}

void QtOpenGLWidget::resizeGL(int w, int h)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, w, h);
}

void QtOpenGLWidget::paintGL()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	drawTriangleDemo();
}
