#include "widget.h"
#include <QMouseEvent>
#include <cmath>

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

void Widget::mousePressEvent(QMouseEvent *e)
{

    mousePressPosition = QVector2D(e->pos());
}

void Widget::mouseReleaseEvent(QMouseEvent *e)
{
    xAxisRotation += (180 * ((GLfloat)e->y() - (GLfloat)mousePressPosition.y())) / 600;
    yAxisRotation += (180 * ((GLfloat)e->x() - (GLfloat)mousePressPosition.x())) / 600;
    mousePressPosition = QVector2D(e->pos());
    update();

}

void Widget::initializeGL()
{
    initializeOpenGLFunctions();
    //glMatrixMode(GL_PROJECTION);
    //glEnable(GL_DEPTH_TEST);
}

void Widget::resizeGL(int w, int h)
{
    //glViewport(0,0,w,h);
}

void Widget::paintGL()
{
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    glRotatef(yAxisRotation, 0.0, 1.0, 0.0);
//    glRotatef(xAxisRotation, 1.0, 0.0, 0.0);

    QVector3D vertex[] = {

    {QVector3D(-0.5f, -0.5f,  0.5f)},
    {QVector3D( 0.5f, -0.5f,  0.5f)},
    {QVector3D(-0.5f,  0.5f,  0.5f)},// v2
    {QVector3D( 0.5f,  0.5f,  0.5f)},// v3

    // Vertex data for face 1
    {QVector3D( 0.5f, -0.5f,  0.5f)},// v4
    {QVector3D( 0.5f, -0.5f, -0.5f)},// v5
    {QVector3D( 0.5f,  0.5f,  0.5f)},// v6
    {QVector3D( 0.5f,  0.5f, -0.5f)},// v7

    // Vertex data for face 2
    {QVector3D( 0.5f, -0.5f, -0.5f)},// v8
    {QVector3D(-0.5f, -0.5f, -0.5f)},// v9
    {QVector3D( 0.5f,  0.5f, -0.5f)},// v10
    {QVector3D(-0.5f,  0.5f, -0.5f)},// v11

    // Vertex data for face 3
    {QVector3D(-0.5f, -0.5f, -0.5f)}, // v12
    {QVector3D(-0.5f, -0.5f,  0.5f)},  // v13
    {QVector3D(-0.5f,  0.5f, -0.5f)},// v14
    {QVector3D(-0.5f,  0.5f,  0.5f)},// v15

    // Vertex data for face 4
    {QVector3D(-0.5f, -0.5f, -0.5f)},// v16
    {QVector3D( 0.5f, -0.5f, -0.5f)}, // v17
    {QVector3D(-0.5f, -0.5f,  0.5f)},// v18
    {QVector3D( 0.5f, -0.5f,  0.5f)},// v19

    // Vertex data for face 5
    {QVector3D(-0.5f,  0.5f,  0.5f)},// v20
    {QVector3D( 0.5f,  0.5f,  0.5f)},// v21
    {QVector3D(-0.5f,  0.5f, -0.5f)}, // v22
    {QVector3D( 0.5f,  0.5f, -0.5f)},// v23
    };

    arrayBuf = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    arrayBuf.setUsagePattern(QOpenGLBuffer::StaticDraw);
    Q_ASSERT(arrayBuf.create());
    Q_ASSERT(arrayBuf.bind());

    arrayBuf.allocate(vertex, 24 * sizeof(vertex));
    arrayBuf.write(0, vertex, sizeof(vertex));

    /*
    shaderProg.addShaderFromSourceFile(QOpenGLShader::Vertex, "/home/vishnyakov/work/new_test_opengl/vshader.vsh");
    shaderProg.addShaderFromSourceFile(QOpenGLShader::Fragment, "/home/vishnyakov/work/new_test_opengl/fshader.fsh");
    Q_ASSERT(shaderProg.link());
    Q_ASSERT(shaderProg.bind());
    */

    int vPosition = 0;
    glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(vPosition);

    glClear(GL_COLOR_BUFFER_BIT);

    glClearColor(0.25, 0.45, 0.65, 1.0);

    glDrawArrays(GL_QUADS, 0, 24);
    glFlush();
    //rquad-=0.15f;
}

Widget::~Widget()
{
}

