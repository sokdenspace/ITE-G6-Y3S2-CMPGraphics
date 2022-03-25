#include <GL/freeglut.h>
#include <string>

#define _USE_MATH_DEFINES
#include <math.h>

// Hide the console
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

const float M_PI_F = (float)M_PI;
const float g_fieldWidth = 4 * M_PI_F;
const float g_fieldHeight = 4;
const float g_halfFieldWidth = g_fieldWidth / 2;
const float g_halfFieldHeight = g_fieldHeight / 2;
const float g_onePercentOfHalfWidth = (float)g_halfFieldWidth / 100;
const float g_onePercentOfHalfHeight = (float)g_halfFieldHeight / 100;

void drawText(float x, float y, std::string text, float r, float g, float b)
{
    glColor3f(r, g, b);
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char*)text.c_str());
}

void drawLine(
    float x0, float y0, float x1, float y1,
    float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_LINES);
    {
        glVertex2f(x0, y0);
        glVertex2f(x1, y1);
    }
    glEnd();
}

void drawSin(float r, float g, float b)
{
    const float step = (float)M_PI / 10;

    float xPrev = -2 * (float)M_PI;

    for (size_t i = 0; i < 40; i++)
    {
        float x0 = xPrev;
        float y0 = sin(x0);

        float x1 = x0 + step;
        float y1 = sin(x1);
        xPrev = x1;

        drawLine(x0, y0, x1, y1, r, g, b);
    }
}

void drawCoordinates(float r, float g, float b)
{
    float halfOfLengthOfLine = 4;

    // 1
    drawText(-14 * g_onePercentOfHalfWidth, g_halfFieldHeight / 2, "1", r, g, b);
    drawLine(
        -halfOfLengthOfLine * g_onePercentOfHalfWidth,
        g_halfFieldHeight / 2,
        halfOfLengthOfLine * g_onePercentOfHalfWidth,
        g_halfFieldHeight / 2, r, g, b);

    // -1
    drawText(-18 * g_onePercentOfHalfWidth, -g_halfFieldHeight / 2, "-1", r, g, b);
    drawLine(
        -halfOfLengthOfLine * g_onePercentOfHalfWidth,
        -g_halfFieldHeight / 2, 2 * g_onePercentOfHalfWidth,
        -g_halfFieldHeight / 2, r, g, b);

    // Pi
    drawText(
        M_PI_F - 5 * g_onePercentOfHalfWidth,
        7 * g_onePercentOfHalfHeight, "Pi", r, g, b);
    drawLine(
        M_PI_F, -halfOfLengthOfLine * g_onePercentOfHalfHeight,
        M_PI_F, halfOfLengthOfLine * g_onePercentOfHalfHeight,
        r, g, b);

    // -Pi
    drawText(
        -M_PI_F - 7 * g_onePercentOfHalfWidth,
        7 * g_onePercentOfHalfHeight, "-Pi", r, g, b);
    drawLine(
        -M_PI_F, -halfOfLengthOfLine * g_onePercentOfHalfHeight,
        -M_PI_F, halfOfLengthOfLine * g_onePercentOfHalfHeight,
        r, g, b);
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawText(
        g_halfFieldWidth - 80 * g_onePercentOfHalfWidth,
        g_halfFieldHeight - 20 * g_onePercentOfHalfHeight,
        "y = Sin(x)", 1, 1, 1);

    // X
    drawLine(-g_halfFieldWidth, 0, g_halfFieldWidth, 0, 1, 0, 0);
    drawText(
        g_halfFieldWidth - 10 * g_onePercentOfHalfWidth,
        -10 * g_onePercentOfHalfHeight, "X", 1, 0, 0);

    // Y
    drawLine(0, -g_halfFieldHeight, 0, g_halfFieldHeight, 0, 1, 0);
    drawText(
        -10 * g_onePercentOfHalfWidth,
        g_halfFieldHeight - 15 * g_onePercentOfHalfHeight, "Y", 0, 1, 0);

    drawCoordinates(1, 1, 1);

    drawSin(0.5, 0.5, 1);

    glutSwapBuffers();
}

void setup2DGraphics(double width, double height)
{
    double halfWidth = width / 2;
    double halfHeight = height / 2;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-halfWidth, halfWidth, -halfHeight, halfHeight, 100, -100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(256, 256);
    glutCreateWindow("Sin");
    setup2DGraphics(g_fieldWidth, g_fieldHeight);
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}