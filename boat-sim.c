#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SPEED 10.0

float i = 0, j = 0;
int z = 0, x = 0;
int red = 0;
int black = 0, green = 1;
void *font = GLUT_BITMAP_HELVETICA_18;

void drawstring(GLfloat x, GLfloat y, char *string) {
  char *c;
  glRasterPos2f(x, y);
  for (c = string; *c != '\0'; *c++) {
    glutBitmapCharacter(font, *c);
  }
}

void myinit() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 1100, 0, 700);
  glMatrixMode(GL_MODELVIEW);
  glClearColor(1, 1, 1, 1);
  glPointSize(1000);
}

void circle(float x1, float y1, float r) {
  float x, y, theta;
  int i;
  glBegin(GL_POLYGON);
  for (i = 0; i <= 360; i++) {
    theta = 3.142 * i / 180;
    x = x1 + r * cos(theta);
    y = y1 + r * sin(theta);
    glVertex2f(x, y);
  }

  glEnd();
}

void draw_object() {
  glBegin(GL_POLYGON);
  glColor3f(0.0, 0.0, 0.7764191540);
  glVertex2f(0, 0);
  glColor3f(0.0, 0.0, 0.01);
  glVertex2f(1100, 0);
  glColor3f(0.0, 0.0, 0.00121467104980);
  glVertex2f(1100, 700);
  glColor3f(0.0, 0.0, 0.17610);
  glVertex2f(0, 700);
  glColor3f(0.0, 0.0, 0.1287172600);
  glEnd();

  glColor3f(0.2, 0.1, 0);
  glBegin(GL_POLYGON);
  glVertex2f(0, 400);
  glVertex2f(250, 700);
  glVertex2f(500, 400);
  glEnd();

  glBegin(GL_POLYGON);
  glVertex2f(500, 400);
  glVertex2f(750, 700);
  glVertex2f(1000, 400);
  glEnd();

  // moon

  glColor3f(1.0, 1.0, 1.0);
  circle(100, 625, 40);

  // star1

  glColor3f(1.0, 1.0, 1.0);

  glBegin(GL_TRIANGLES);
  glVertex2f(575 + j, 653 + j);
  glVertex2f(570 + j, 645 + j);
  glVertex2f(580 + j, 645 + j);
  glVertex2f(575 + j, 642 + j);
  glVertex2f(570 + j, 650 + j);
  glVertex2f(580 + j, 650 + j);
  glEnd();

  // star2

  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_TRIANGLES);
  glVertex2f(970 + j, 643 + j);
  glVertex2f(970 + j, 635 + j);
  glVertex2f(980 + j, 633 + j);
  glVertex2f(975 + j, 632 + j);
  glVertex2f(970 + j, 640 + j);
  glVertex2f(980 + j, 640 + j);
  glEnd();

  // star4

  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_TRIANGLES);
  glVertex2f(375 + j, 598 + j);
  glVertex2f(370 + j, 590 + j);
  glVertex2f(380 + j, 590 + j);
  glVertex2f(375 + j, 587 + j);
  glVertex2f(370 + j, 595 + j);
  glVertex2f(380 + j, 595 + j);
  glEnd();

  // star7

  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_TRIANGLES);
  glVertex2f(500 + j, 543 + j);
  glVertex2f(495 + j, 535 + j);
  glVertex2f(505 + j, 535 + j);
  glVertex2f(500 + j, 532 + j);
  glVertex2f(495 + j, 540 + j);
  glVertex2f(505 + j, 540 + j);
  glEnd();

  // boat

  glBegin(GL_POLYGON);
  glColor3f(0.0, 0.0, 0.0);
  glVertex2f(25 + i, 100);
  glVertex2f(225 + i, 100);
  glVertex2f(175 + i, 25);
  glVertex2f(75 + i, 25);
  glEnd();
  // flag

  glColor3f(red, green, black);
  glBegin(GL_POLYGON);
  glVertex2f(60 + i, 100);
  glVertex2f(120 + i, 100);
  glVertex2f(60 + i, 200);
  glEnd();

  // sea shore

  glColor3f(0.20, 0.10, 0.0);
  glBegin(GL_POLYGON);
  glVertex2f(1100, 68);
  glVertex2f(1100, 0);
  glVertex2f(500, 0);
  glEnd();
}

void idle() {
  glClearColor(1, 1, 1, 1);
  if (i >= 830 && i <= 1130)
    i += SPEED / 200;

  if (i > 1630)
    i = 0.0;

  if (j > 700)
    j = 0.0;

  glutPostRedisplay();
}

void mymouse(int btn, int state, int x, int y) {
  if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    glutIdleFunc(idle);
  if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)

    glutIdleFunc(NULL);
}

void keyboard(unsigned char key, int x, int y) {
  if (key == 'q')
    ;

  glutIdleFunc(NULL);
}

void myreshape(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (w > h)
    gluOrtho2D(0, 1100 * (w / h), 0, 700);
  else
    gluOrtho2D(0, 1100, 0, 700 * (h / w));

  glMatrixMode(GL_MODELVIEW);
  glutPostRedisplay();
}

void display1() {
  glClear(GL_COLOR_BUFFER_BIT);
  draw_object();

  if (z < 1100) {
    i += SPEED / 20;
    z++;
  }

  if (x < 700)
    j += SPEED / 0.02;

  glutSwapBuffers();
  glFlush();
}

int sub_menu;

void color_menu(int id) {

  switch (id) {
  case 2:
    red = 1;
    green = 0;
    black = 0;
    break;

  case 3:
    red = 0;
    green = 0;
    black = 0;
    break;

  case 4:
    red = 0;
    green = 1;
    black = 0;
  }

  glutPostRedisplay();
}

void top_menu(int id) {

  switch (id) {

  case 1:
    exit(0);
    break;

  default:
    color_menu(id);
    break;
  }
}

// void title() {
//
//   glLineWidth(3.0);
//   glColor3f(1.0, 1.0, 1.0);
//   glBegin(GL_LINE_LOOP);
//   glVertex2f(10, 10);
//   glVertex2f(10, 490);
//   glVertex2f(490, 490);
//   glVertex2f(490, 10);
//   glEnd();
//
//   glColor3f(1.0, 1.0, 0.0);
//   drawstring(80, 440, "Dayanand sagar academy of technology and management");
//   glColor3f(1.0, 1.0, 0.0);
//   drawstring(60, 400, "Under the guidance of prof. Raghu MT");
//   glColor3f(1.0, 1.0, 0.0);
//   drawstring(100, 360, "Computer Graphics & Visualization");
//   glColor3f(1.0, 1.0, 1.0);
//   drawstring(120, 320, "Topic:Boat simulation ");
//   glColor3f(1.0, 1.0, 1.0);
//   drawstring(100, 280, "Submitted by");
//   glColor3f(1.0, 1.0, 0.0);
//   drawstring(100, 260, "Nithin-1DT14CS057");
//   glColor3f(1.0, 1.0, 0.0);
//   drawstring(100, 240, "Nikhil-1DT14CS053");
//   glColor3f(1.0, 1.0, 0.0);
//   drawstring(100, 220, "VI CSE A");
//   glColor3f(1.0, 1.0, 1.0);
//   drawstring(60, 100, "Right click on Window for options");
//   glFlush();
// }

void myInit1() {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glColor3f(0.0f, 0.0f, 0.0f);
  glPointSize(5.0);
  gluOrtho2D(0.0, 500.0, 0.0, 500.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
}

// void display2(void) {
//   glClear(GL_COLOR_BUFFER_BIT);
//   title();
// }

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(1100, 700);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("moving boat");
  myinit();
  glutDisplayFunc(display1);
  glutMouseFunc(mymouse);
  glutKeyboardFunc(keyboard);
  sub_menu = glutCreateMenu(color_menu);
  glutAddMenuEntry("red", 2);
  glutAddMenuEntry("black", 3);
  glutAddMenuEntry("green", 4);
  glutCreateMenu(top_menu);
  glutAddMenuEntry("quit", 1);
  glutAddSubMenu("color", sub_menu);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
  // glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  // glutInitWindowPosition(600, 0);
  // glutInitWindowSize(500, 500);
  // glutCreateWindow("Front Sheet");
  // glutDisplayFunc(display2);
  myInit1();
  glutMainLoop();
  return 0;
}
