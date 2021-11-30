#ifndef WIDGET_H
#define WIDGET_H

#include <QBasicTimer>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <GL/gl.h>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>


class Widget : public QOpenGLWidget, protected QOpenGLFunctions
{
protected:
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    Q_OBJECT

public:
    using QOpenGLWidget::QOpenGLWidget;
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    GLfloat rquad;
    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;
    float xAxisRotation;
    float yAxisRotation;
    QOpenGLShaderProgram shaderProg;
    QVector2D mousePressPosition;
    QVector3D rotationAxis;
};
#endif // WIDGET_H
