#include <iostream>
#include <cmath>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

/*
#include <windows.h>
#include <mmsystem.h>
*/


using namespace std;

// Movement
float _moveA  = 0.0f;   // boat-1 (left -> right)
float _moveB  = 0.0f;   // boat-2 (right -> left)
float _moveC  = 0.0f;   // clouds (left -> right)
float _moveShip =0.0f;
float _angle1 = 0.0f;   // windmill bla des
float speed   = 0.08f;  // base speed for movement


bool showScene5 = false;
bool showscene4 = false;
bool showScene3 = false;
bool showscene2 = false;
bool showscene1=  false;
bool showScene0 = true;

//  declarations
void drawscene0();
void drawScene1();
void drawScene2();
void drawScene3();
void drawScene4();
void drawScene5();
void display();
void update(int);
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);


void renderBitmapString(float x, float y, float z, void *font, const char *string) {
    glRasterPos3f(x, y, z); // Set the position of the text
    for (int i = 0; string[i] != '\0'; i++) {
        glutBitmapCharacter(font, string[i]); // Render each character
    }
}


/////////////////////////Introduction////////////////////////////////////////////////////////////////

void drawScene0() {
    glClear(GL_COLOR_BUFFER_BIT);

    // backgrnd
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.894f, 0.769f);   // Beige
    glVertex2f(-12.0f, 14.0f);
    glVertex2f(38.0f, 14.0f);
    glVertex2f(38.0f, -19.0f);
    glVertex2f(-12.0f, -19.0f);
    glEnd();

    // Top headings (blue)
    glColor3f(0.0f, 0.0f, 1.0f);
    renderBitmapString(5.5f, 10.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "American International University-Bangladesh");
    renderBitmapString(7.0f, 9.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Faculty of Science & Technology");
    renderBitmapString(9.0f, 8.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Department of CSE");

    // Course
    glColor3f(0.353f, 0.180f, 0.047f);   // Dark Chocolate color
    //course heading
    renderBitmapString(6.0f, 6.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Course: CSE-1118: Computer Graphics");

    // Group/section (red)
    glColor3f(1.0f, 0.0f, 0.0f);  // Red color for the group and section info
    renderBitmapString(7.8f, 5.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Section : L, Group : 05");
    renderBitmapString(6.5f, 3.8f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Submitted to: NOBORANJAN DEY");

 // Set table text color to black
glColor3f(0.0f, 0.0f, 0.0f);

// Set table text color to black
glColor3f(0.0f, 0.0f, 0.0f); // Black

// Table headers
renderBitmapString(-3.0f, 1.6f, 0.0f, GLUT_BITMAP_HELVETICA_18, "SL");
renderBitmapString(10.0f, 1.6f, 0.0f, GLUT_BITMAP_HELVETICA_18, "NAME");
renderBitmapString(24.0f, 1.6f, 0.0f, GLUT_BITMAP_HELVETICA_18, "ID");

// Wider table horizontal lines
glBegin(GL_LINES);
glVertex2f(-5.5f, 1.1f);
glVertex2f(30.0f, 1.1f);

glVertex2f(-5.5f, -4.4f);
glVertex2f(30.0f, -4.4f);
glEnd();

// Table rows
renderBitmapString(-3.0f, 0.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "01");
renderBitmapString(8.0f, 0.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "MD MUSTAKIM ALI");
renderBitmapString(22.0f, 0.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "22-48377-3");

renderBitmapString(-3.0f, -1.6f, 0.0f, GLUT_BITMAP_HELVETICA_18, "02");
renderBitmapString(7.7f, -1.6f, 0.0f, GLUT_BITMAP_HELVETICA_18, "FAHIM CHOWDHURY");
renderBitmapString(22.0f, -1.6f, 0.0f, GLUT_BITMAP_HELVETICA_18, "22-48390-3");

renderBitmapString(-3.0f, -3.2f, 0.0f, GLUT_BITMAP_HELVETICA_18, "03");
renderBitmapString(7.7f, -3.2f, 0.0f, GLUT_BITMAP_HELVETICA_18, "SK JARIF UDDIN OMI ");
renderBitmapString(22.0f, -3.2f, 0.0f, GLUT_BITMAP_HELVETICA_18, "22-49017-3");

glutSwapBuffers();
}




 ////////////////////////////////////SCENE 1( Village Day)) /////////////////////////////////////////////////


void drawScene1() {

     glClear(GL_COLOR_BUFFER_BIT);

    // sky (day)
    glBegin(GL_POLYGON);
    glColor3ub(135,206,250);
    glVertex2f(38.0f,3.0f);
    glVertex2f(38.0f,14.0f);
    glVertex2f(-12.0f,14.0f);
    glVertex2f(-12.0f,3.0f);
    glEnd();

  // sun
    glPushMatrix();
    glColor3ub(255,255,0);
    glTranslatef(30.0, 7.0, 0);
    glutSolidSphere(1.0, 64, 64);
    glPopMatrix();

    // cloud 1
    glPushMatrix();
    glTranslatef(_moveC,0.0f,0.0f);

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(1.0, 6.0, 0);
    glutSolidSphere(0.7, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(1.0, 7.0, 0);
    glutSolidSphere(0.7, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(2.0, 7.0, 0);
    glutSolidSphere(0.7, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(2.0, 6.0, 0);
    glutSolidSphere(0.7, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(0.0, 6.5, 0);
    glutSolidSphere(0.7, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(3.0, 6.5, 0);
    glutSolidSphere(0.7, 32, 32);
    glPopMatrix();

    glPopMatrix();

    // cloud 2
    glPushMatrix();
    glTranslatef(_moveC,0.0f,0.0f);

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(15.0, 9.0, 0);
    glutSolidSphere(0.8, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(15.0, 8.0, 0);
    glutSolidSphere(0.8, 32, 32);
    glPopMatrix();

    glPushMatrix();
     glColor3ub(255,255,255);
     glTranslatef(16.0, 8.0, 0);
     glutSolidSphere(0.8, 32, 32);
     glPopMatrix();

    glPushMatrix();
     glColor3ub(255,255,255);
     glTranslatef(16.0, 9.0, 0);
     glutSolidSphere(0.8, 32, 32);
     glPopMatrix();

    glPushMatrix();
     glColor3ub(255,255,255);
     glTranslatef(14.0, 8.5, 0);
     glutSolidSphere(0.8, 32, 32);
     glPopMatrix();

    glPushMatrix();
     glColor3ub(255,255,255);
     glTranslatef(17.0, 8.5, 0);
     glutSolidSphere(0.8, 32, 32);
     glPopMatrix();

    glPopMatrix();

    // cloud 3
   glPushMatrix();
   glTranslatef(_moveC, 0.0f, 0.0f);

   glPushMatrix();
   glColor3ub(255, 255, 255);
   glTranslatef(22.0f, 8.0f, 0.0f);
  glutSolidSphere(0.75, 32, 32);
   glPopMatrix();

glPushMatrix();
glColor3ub(255, 255, 255);
glTranslatef(22.0f, 7.0f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(255, 255, 255);
glTranslatef(23.0f, 8.0f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(255, 255, 255);
glTranslatef(23.0f, 7.0f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(255, 255, 255);
glTranslatef(24.0f, 7.5f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(255, 255, 255);
glTranslatef(21.0f, 7.5f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPopMatrix();


    // sea
    glBegin(GL_POLYGON);
    glColor3ub(65,105,225);
    glVertex2f(38.0f,-19.0f);
    glVertex2f(38.0f,3.0f);
    glVertex2f(-12.0f,3.0f);
    glVertex2f(-12.0f,-19.0f);
    glEnd();

    // left soil
glBegin(GL_POLYGON);
glColor3ub(0,128,0);
glVertex2f(4.0f, 0.0f);
glVertex2f(6.0f, 1.0f);
glVertex2f(3.0f, 3.0f);
glVertex2f(-12.0f, 3.0f);
glVertex2f(-12.0f, 0.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,128,0);
glVertex2f(5.0f, -3.0f);
glVertex2f(7.0f, -1.5f);
glVertex2f(4.0f, 0.0f);
glVertex2f(-12.0f, 0.0f);
glVertex2f(-12.0f, -3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,128,0);
glVertex2f(6.0f, -4.5f);
glVertex2f(8.0f, -4.0f);
glVertex2f(5.0f, -3.0f);
glVertex2f(-12.0f, -3.0f);
glVertex2f(-12.0f, -4.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,128,0);
glVertex2f(2.0f, -9.0f);
glVertex2f(9.5f, -7.0f);
glVertex2f(6.0f, -4.5f);
glVertex2f(-12.0f, -4.5f);
glVertex2f(-12.0f, -9.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,128,0);
glVertex2f(2.0f, -11.5f);
glVertex2f(5.0f, -10.0f);
glVertex2f(2.0f, -9.0f);
glVertex2f(-12.0f, -9.0f);
glVertex2f(-12.0f, -11.5f);
glEnd();

// left soil partition or border
glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(6.0f, 0.5f);
glVertex2f(6.0f, 1.0f);
glVertex2f(4.0f, 0.0f);
glVertex2f(4.5f, -0.25f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(7.0f, -2.0f);
glVertex2f(7.0f, -1.5f);
glVertex2f(5.0f, -3.0f);
glVertex2f(5.5f, -3.15f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(8.0f, -4.4f);
glVertex2f(8.0f, -4.0f);
glVertex2f(6.0f, -4.5f);
glVertex2f(6.3f, -4.8f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(9.5f, -7.5f);
glVertex2f(9.5f, -7.0f);
glVertex2f(2.0f, -9.0f);
glVertex2f(3.0f, -9.3f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(5.0f, -10.5f);
glVertex2f(5.0f, -10.0f);
glVertex2f(2.0f, -11.5f);
glVertex2f(2.0f, -12.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(2.0f, -12.0f);
glVertex2f(2.0f, -11.5f);
glVertex2f(-12.0f, -11.5f);
glVertex2f(-12.0f, -12.0f);
glEnd();

// right soil
glBegin(GL_POLYGON);
glColor3ub(0,128,0);
glVertex2f(13.0f, 3.0f);
glVertex2f(16.0f, 1.0f);
glVertex2f(38.0f, 1.0f);
glVertex2f(38.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,128,0);
glVertex2f(16.0f, 1.0f);
glVertex2f(14.0f, 0.0f);
glVertex2f(17.0f,-1.5f);
glVertex2f(38.0f,-1.5f);
glVertex2f(38.0f, 1.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,128,0);
glVertex2f(17.0f,-1.5f);
glVertex2f(15.0f,-3.0f);
glVertex2f(18.0f,-4.0f);
glVertex2f(38.0f,-4.0f);
glVertex2f(38.0f,-1.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,128,0);
glVertex2f(18.0f,-4.0f);
glVertex2f(16.0f,-4.5f);
glVertex2f(21.0f,-7.0f);
glVertex2f(38.0f,-7.0f);
glVertex2f(38.0f,-4.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,128,0);
glVertex2f(21.0f,-7.0f);
glVertex2f(19.0f,-8.0f);
glVertex2f(22.0f,-9.0f);
glVertex2f(38.0f,-9.0f);
glVertex2f(38.0f,-7.0f);
glEnd();

// right soil parrtition or border

glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(12.5f, 3.0f);
glVertex2f(15.6f, 0.8f);
glVertex2f(16.0f, 1.0f);
glVertex2f(13.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(14.0f,-0.5f);
glVertex2f(16.4f,-1.9f);
glVertex2f(17.0f,-1.5f);
glVertex2f(14.0f, 0.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(15.0f,-3.5f);
glVertex2f(17.0f,-4.2f);
glVertex2f(18.0f,-4.0f);
glVertex2f(15.0f,-3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(16.0f,-5.0f);
glVertex2f(20.5f,-7.2f);
glVertex2f(21.0f,-7.0f);
glVertex2f(16.0f,-4.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(19.0f,-8.5f);
glVertex2f(22.0f,-9.5f);
glVertex2f(22.0f,-9.0f);
glVertex2f(19.0f,-8.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(38.0f,-9.0f);
glVertex2f(22.0f,-9.0f);
glVertex2f(22.0f,-9.5f);
glVertex2f(38.0f,-9.5f);
glEnd();


// house (left)

// Main body
glBegin(GL_POLYGON);
glColor3ub(178,34,34);
glVertex2f(-10.2f,-3.5f);
glVertex2f(-4.2f,-3.5f);
glVertex2f(-4.2f, 3.0f);
glVertex2f(-10.2f, 3.0f);
glEnd();

// Roof
glBegin(GL_TRIANGLES);
glColor3ub(105,105,105);
glVertex2f(-10.4f,3.0f);
glVertex2f(-4.0f,3.0f);
glVertex2f(-7.2f,4.5f);
glEnd();

// Roof top bar
glBegin(GL_POLYGON);
glColor3ub(80,80,80);
glVertex2f(-10.4f,3.0f);
glVertex2f(-4.0f,3.0f);
glVertex2f(-4.0f,2.7f);
glVertex2f(-10.4f,2.7f);
glEnd();

// Door
glBegin(GL_POLYGON);
glColor3ub(90,60,40);
glVertex2f(-7.7f,-3.5f);
glVertex2f(-6.7f,-3.5f);
glVertex2f(-6.7f,-1.0f);
glVertex2f(-7.7f,-1.0f);
glEnd();

// Windows (bottom row, left)
glBegin(GL_POLYGON);
glColor3ub(135,206,235);
glVertex2f(-9.9f,-2.5f);
glVertex2f(-8.9f,-2.5f);
glVertex2f(-8.9f,-0.5f);
glVertex2f(-9.9f,-0.5f);
glEnd();

// Windows (bottom row, right)
glBegin(GL_POLYGON);
glColor3ub(135,206,235);
glVertex2f(-5.5f,-2.5f);
glVertex2f(-4.5f,-2.5f);
glVertex2f(-4.5f,-0.5f);
glVertex2f(-5.5f,-0.5f);
glEnd();

// Windows (top row, left)
glBegin(GL_POLYGON);
glColor3ub(135,206,235);
glVertex2f(-9.9f,0.0f);
glVertex2f(-8.9f,0.0f);
glVertex2f(-8.9f,2.0f);
glVertex2f(-9.9f,2.0f);
glEnd();

// Windows (top row, right)
glBegin(GL_POLYGON);
glColor3ub(135,206,235);
glVertex2f(-5.5f,0.0f);
glVertex2f(-4.5f,0.0f);
glVertex2f(-4.5f,2.0f);
glVertex2f(-5.5f,2.0f);
glEnd();

// Center window (top middle, aligned over door)
glBegin(GL_POLYGON);
glColor3ub(135,206,235);
glVertex2f(-7.7f,0.0f);
glVertex2f(-6.7f,0.0f);
glVertex2f(-6.7f,2.0f);
glVertex2f(-7.7f,2.0f);
glEnd();

// Window borders (left trim)
glBegin(GL_POLYGON);
glColor3ub(50,50,50);
glVertex2f(-10.0f,-2.6f);
glVertex2f(-8.8f,-2.6f);
glVertex2f(-8.8f,-0.4f);
glVertex2f(-10.0f,-0.4f);
glEnd();

// Window borders (right trim)
glBegin(GL_POLYGON);
glColor3ub(50,50,50);
glVertex2f(-5.6f,-2.6f);
glVertex2f(-4.4f,-2.6f);
glVertex2f(-4.4f,-0.4f);
glVertex2f(-5.6f,-0.4f);
glEnd();

// Porch (right extension)
glBegin(GL_POLYGON);
glColor3ub(178,34,34);
glVertex2f(-4.2f,-3.5f);
glVertex2f(-1.7f,-3.5f);
glVertex2f(-1.7f,1.0f);
glVertex2f(-4.2f,1.0f);
glEnd();

// Porch roof
glBegin(GL_POLYGON);
glColor3ub(100,100,100);
glVertex2f(-4.2f,1.0f);
glVertex2f(-1.7f,1.0f);
glVertex2f(-1.7f,1.3f);
glVertex2f(-4.2f,1.3f);
glEnd();


// DARK HOUSE 2

// Main body
glBegin(GL_POLYGON);
glColor3ub(120,120,120);
glVertex2f(-2.2f,-3.5f);
glVertex2f(4.3f,-3.5f);
glVertex2f(4.3f,0.5f);
glVertex2f(-2.2f,0.5f);
glEnd();

// Roof
glBegin(GL_TRIANGLES);
glColor3ub(60,40,40);
glVertex2f(-2.2f,0.5f);
glVertex2f(4.3f,0.5f);
glVertex2f(1.05f,4.0f);
glEnd();

// Roof outline
glBegin(GL_LINE_LOOP);
glColor3ub(20,20,20);
glVertex2f(-2.2f,0.5f);
glVertex2f(4.3f,0.5f);
glVertex2f(1.05f,4.0f);
glEnd();

// Door
glBegin(GL_POLYGON);
glColor3ub(80,50,30);
glVertex2f(0.55f,-3.5f);
glVertex2f(1.55f,-3.5f);
glVertex2f(1.55f,-0.5f);
glVertex2f(0.55f,-0.5f);
glEnd();

// Left window
glBegin(GL_POLYGON);
glColor3ub(90,110,130);
glVertex2f(-1.25f,-2.5f);
glVertex2f(-0.25f,-2.5f);
glVertex2f(-0.25f,-0.5f);
glVertex2f(-1.25f,-0.5f);
glEnd();

// Right window
glBegin(GL_POLYGON);
glColor3ub(90,110,130);
glVertex2f(2.35f,-2.5f);
glVertex2f(3.35f,-2.5f);
glVertex2f(3.35f,-0.5f);
glVertex2f(2.35f,-0.5f);
glEnd();

// Window frames
glBegin(GL_POLYGON);
glColor3ub(30,30,30);
glVertex2f(-0.78f,-2.5f);
glVertex2f(-0.72f,-2.5f);
glVertex2f(-0.72f,-0.5f);
glVertex2f(-0.78f,-0.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(30,30,30);
glVertex2f(2.82f,-2.5f);
glVertex2f(2.88f,-2.5f);
glVertex2f(2.88f,-0.5f);
glVertex2f(2.82f,-0.5f);
glEnd();

// Small attic window
glBegin(GL_POLYGON);
glColor3ub(70,90,110);
glVertex2f(0.70f,1.3f);
glVertex2f(1.40f,1.3f);
glVertex2f(1.40f,2.0f);
glVertex2f(0.70f,2.0f);
glEnd();


// tree (left trunk/branches)
glBegin(GL_POLYGON);
glColor3ub(139,69,19);
glVertex2f(-9.5f, 1.0f);
glVertex2f(-9.0f, 1.5f);
glVertex2f(-9.5f, 2.5f);
glVertex2f(-10.0f, 2.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(139,69,19);
glVertex2f(-9.0f, 1.5f);
glVertex2f(-8.5f, 1.0f);
glVertex2f(-8.0f, 2.0f);
glVertex2f(-8.0f, 2.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(139,69,19);
glVertex2f(-9.5f, 1.0f);
glVertex2f(-9.5f,-3.5f);
glVertex2f(-9.0f,-4.0f);
glVertex2f(-8.5f,-3.5f);
glVertex2f(-8.5f, 1.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(139,69,19);
glVertex2f(-8.5f,-3.0f);
glVertex2f(-9.5f,-3.0f);
glVertex2f(-10.5f,-3.5f);
glVertex2f(-7.5f,-3.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(139,69,19);
glVertex2f(-10.0f,-0.5f);
glVertex2f(-9.5f,-1.0f);
glVertex2f(-9.5f,-0.6f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(139,69,19);
glVertex2f(-9.5f, 1.0f);
glVertex2f(-9.0f, 1.5f);
glVertex2f(-8.5f, 1.0f);
glEnd();


// hillview (12 hills)
glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(-12.0f, 3.0f);
glVertex2f(-11.5f, 4.5f);
glVertex2f(-7.5f, 4.5f);
glVertex2f(-7.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(-11.5f, 4.5f);
glVertex2f(-11.0f, 5.5f);
glVertex2f(-8.0f, 5.5f);
glVertex2f(-7.5f, 4.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(-11.0f, 5.5f);
glVertex2f(-10.5f, 6.0f);
glVertex2f(-8.5f, 6.0f);
glVertex2f(-8.0f, 5.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(-10.5f, 6.0f);
glVertex2f(-10.3f, 6.2f);
glVertex2f(-8.7f, 6.2f);
glVertex2f(-8.5f, 6.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(-10.3f, 6.2f);
glVertex2f(-10.2f, 6.3f);
glVertex2f(-8.8f, 6.3f);
glVertex2f(-8.7f, 6.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(-7.0f, 3.0f);
glVertex2f(-6.5f, 4.0f);
glVertex2f(-4.5f, 4.0f);
glVertex2f(-4.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(-6.5f, 4.0f);
glVertex2f(-6.0f, 4.5f);
glVertex2f(-5.0f, 4.5f);
glVertex2f(-4.5f, 4.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(-4.0f, 3.0f);
glVertex2f(-3.5f, 4.5f);
glVertex2f(-1.5f, 4.5f);
glVertex2f(-1.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(-3.5f, 4.5f);
glVertex2f(-3.0f, 5.0f);
glVertex2f(-2.0f, 5.0f);
glVertex2f(-1.5f, 4.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(-1.0f, 3.0f);
glVertex2f(-0.5f, 6.0f);
glVertex2f(4.5f, 6.0f);
glVertex2f(5.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(-0.5f, 6.0f);
glVertex2f(0.0f, 7.0f);
glVertex2f(4.0f, 7.0f);
glVertex2f(4.5f, 6.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(0.0f, 7.0f);
glVertex2f(1.0f, 8.0f);
glVertex2f(3.0f, 8.0f);
glVertex2f(4.0f, 7.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,100,0);
glVertex2f(1.0f, 8.0f);
glVertex2f(3.0f, 8.0f);
glVertex2f(2.0f, 8.3f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(5.0f, 3.0f);
glVertex2f(5.5f, 4.0f);
glVertex2f(6.5f, 4.0f);
glVertex2f(7.0f, 3.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,100,0);
glVertex2f(5.5f, 4.0f);
glVertex2f(6.5f, 4.0f);
glVertex2f(6.0f, 4.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(7.0f, 3.0f);
glVertex2f(8.0f, 5.0f);
glVertex2f(13.0f, 5.0f);
glVertex2f(14.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(8.0f, 5.0f);
glVertex2f(9.0f, 6.0f);
glVertex2f(12.0f, 6.0f);
glVertex2f(13.0f, 5.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,100,0);
glVertex2f(9.0f, 6.0f);
glVertex2f(12.0f, 6.0f);
glVertex2f(10.5f, 6.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(14.0f, 3.0f);
glVertex2f(15.0f, 5.0f);
glVertex2f(20.0f, 5.0f);
glVertex2f(21.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(15.0f, 5.0f);
glVertex2f(16.0f, 6.0f);
glVertex2f(19.0f, 6.0f);
glVertex2f(20.0f, 5.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,100,0);
glVertex2f(16.0f, 6.0f);
glVertex2f(19.0f, 6.0f);
glVertex2f(17.5f, 6.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(21.0f, 3.0f);
glVertex2f(22.0f, 5.0f);
glVertex2f(24.0f, 5.0f);
glVertex2f(25.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(22.0f, 5.0f);
glVertex2f(22.5f, 5.5f);
glVertex2f(23.5f, 5.5f);
glVertex2f(24.0f, 5.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(25.0f, 3.0f);
glVertex2f(25.5f, 4.5f);
glVertex2f(28.5f, 4.5f);
glVertex2f(29.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(25.5f, 4.5f);
glVertex2f(26.0f, 5.0f);
glVertex2f(28.0f, 5.0f);
glVertex2f(28.5f, 4.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(29.0f, 3.0f);
glVertex2f(29.5f, 4.0f);
glVertex2f(30.5f, 4.0f);
glVertex2f(31.0f, 3.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,100,0);
glVertex2f(29.5f, 4.0f);
glVertex2f(30.0f, 4.5f);
glVertex2f(30.5f, 4.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(31.0f, 3.0f);
glVertex2f(31.5f, 4.5f);
glVertex2f(32.5f, 4.5f);
glVertex2f(33.0f, 3.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,100,0);
glVertex2f(31.5f, 4.5f);
glVertex2f(32.5f, 4.5f);
glVertex2f(32.0f, 5.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(33.0f, 3.0f);
glVertex2f(33.5f, 4.5f);
glVertex2f(37.5f, 4.5f);
glVertex2f(38.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(33.5f, 4.5f);
glVertex2f(34.0f, 5.0f);
glVertex2f(37.0f, 5.0f);
glVertex2f(37.5f, 4.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,100,0);
glVertex2f(34.0f, 5.0f);
glVertex2f(37.0f, 5.0f);
glVertex2f(35.5f, 5.5f);
glEnd();


    // tree canopy (top)
glPushMatrix();
glColor3ub(50,205,50);
glTranslatef(-10.5f, 2.5f, 0.0f);
glutSolidSphere(1.0, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(50,205,50);
glTranslatef(-9.5f, 3.0f, 0.0f);
glutSolidSphere(1.0, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(50,205,50);
glTranslatef(-7.5f, 1.5f, 0.0f);
glutSolidSphere(1.0, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(50,205,50);
glTranslatef(-7.5f, 2.5f, 0.0f);
glutSolidSphere(1.0, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(50,205,50);
glTranslatef(-8.5f, 3.5f, 0.0f);
glutSolidSphere(1.0, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(50,205,50);
glTranslatef(-10.0f, 4.0f, 0.0f);
glutSolidSphere(1.0, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(50,205,50);
glTranslatef(-8.0f, 4.0f, 0.0f);
glutSolidSphere(1.0, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(50,205,50);
glTranslatef(-9.0f, 5.0f, 0.0f);
glutSolidSphere(1.0, 32, 32);
glPopMatrix();


// boat-1 (moving ledt to Right)
glPushMatrix();
glTranslatef(_moveA, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(139,69,19);
glVertex2f( 1.0f, -14.0f);
glVertex2f( 1.5f, -13.0f);
glVertex2f(-2.0f, -13.0f);
glVertex2f(-3.0f, -14.0f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f( 2.0f, -14.5f);
glVertex2f( 2.0f, -14.0f);
glVertex2f(-3.0f, -14.0f);
glVertex2f(-3.0f, -14.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,0,0);
glVertex2f(-3.0f, -14.5f);
glVertex2f(-3.0f, -14.0f);
glVertex2f(-4.5f, -13.7f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,0,0);
glVertex2f( 2.0f, -14.5f);
glVertex2f( 3.5f, -13.7f);
glVertex2f( 2.0f, -14.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,0,0);
glVertex2f( 2.0f, -14.0f);
glVertex2f( 1.5f, -13.0f);
glVertex2f( 1.0f, -14.0f);
glEnd();

glPopMatrix();

// boat-2 (moving Right to Lft)
glPushMatrix();
glTranslatef(_moveB, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(139,69,19);
glVertex2f(22.0f, -17.5f);
glVertex2f(21.0f, -16.5f);
glVertex2f(17.5f, -16.5f);
glVertex2f(18.0f, -17.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f(22.0f, -18.0f);
glVertex2f(22.0f, -17.5f);
glVertex2f(17.0f, -17.5f);
glVertex2f(17.0f, -18.0f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(139,69,19);
glVertex2f(19.8f, -14.5f);
glVertex2f(19.8f, -14.0f);
glVertex2f(19.7f, -14.0f);
glVertex2f(19.7f, -14.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,0,0);
glVertex2f(17.0f, -18.0f);
glVertex2f(17.0f, -17.5f);
glVertex2f(15.5f, -17.2f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,0,0);
glVertex2f(22.0f, -17.5f);
glVertex2f(22.0f, -18.0f);
glVertex2f(23.5f, -17.2f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,0,0);
glVertex2f(17.0f, -17.5f);
glVertex2f(18.0f, -17.5f);
glVertex2f(17.5f, -16.5f);
glEnd();


// Mast hook
glBegin(GL_QUADS);
glColor3ub(139,69,19);
glVertex2f(19.75f, -16.5f);
glVertex2f(19.85f, -16.5f);
glVertex2f(19.85f, -14.2f);
glVertex2f(19.75f, -14.2f);
glEnd();


// Sail
glBegin(GL_TRIANGLES);
glColor3ub(255,99,71);
glVertex2f(19.82f, -14.3f); // top near mast
glVertex2f(19.82f, -16.2f); // bottom near mast
glVertex2f(18.60f, -15.25f); // tip to the left
glEnd();

glPopMatrix();


   // boat-3 (no movement)
glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(8.0f,  -2.5f);
glVertex2f(10.5f, -2.5f);
glVertex2f(10.5f, -2.2f);
glVertex2f(8.0f,  -2.2f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,0,0);
glVertex2f(8.0f,  -2.2f);
glVertex2f(7.0f,  -2.0f);
glVertex2f(8.0f,  -2.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,0,0);
glVertex2f(11.5f, -2.0f);
glVertex2f(10.5f, -2.2f);
glVertex2f(10.5f, -2.5f);
glEnd();



    // First WINDMILL (left)

// tower
glBegin(GL_POLYGON);
glColor3ub(192,192,192);
glVertex2f(25.0f, 2.0f);
glVertex2f(24.75f,-5.0f);
glVertex2f(27.25f,-5.0f);
glVertex2f(27.0f, 2.0f);
glVertex2f(26.5f, 3.0f);
glVertex2f(25.5f, 3.0f);
glEnd();

    // hub + blades
    glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(26.0f, 3.0f, 0.0f);
    glutSolidSphere(0.5, 32, 32);
    glRotatef(_angle1, 0.0f, 0.0f, 1.0f);

glBegin(GL_QUADS);
glColor3ub(255,255,0);
glVertex2f(0.0f, 0.0f);
glVertex2f(5.0f, 0.0f);
glVertex2f(5.0f, 0.25f);
glVertex2f(0.0f, 0.25f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(255,255,0);
glVertex2f(0.0f, 0.0f);
glVertex2f(0.0f, 5.0f);
glVertex2f(-0.25f, 5.0f);
glVertex2f(-0.25f, 0.0f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(255,255,0);
glVertex2f(0.0f, -0.25f);
glVertex2f(0.0f, 0.0f);
glVertex2f(-5.0f, 0.0f);
glVertex2f(-5.0f, -0.25f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(255,255,0);
glVertex2f(0.25f, 0.0f);
glVertex2f(0.0f, 0.0f);
glVertex2f(0.0f, -5.0f);
glVertex2f(0.25f, -5.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(128,0,0);
glVertex2f(0.25f, 0.0f);
glVertex2f(5.0f, -2.5f);
glVertex2f(5.0f, 0.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(128,0,0);
glVertex2f(0.0f, 0.025f);
glVertex2f(2.5f, 5.0f);
glVertex2f(0.0f, 5.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(128,0,0);
glVertex2f(-0.25f, 0.0f);
glVertex2f(-5.0f, 2.5f);
glVertex2f(-5.0f, 0.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(128,0,0);
glVertex2f(0.0f, -0.025f);
glVertex2f(-2.5f, -5.0f);
glVertex2f(0.0f, -5.0f);
glEnd();

glPopMatrix();



    // Second WINDMILL

// windmill tower
glBegin(GL_POLYGON);
glColor3ub(192,192,192);
glVertex2f(31.0f,2.0f);
glVertex2f(30.75f,-6.0f);
glVertex2f(33.25f,-6.0f);
glVertex2f(33.0f,2.0f);
glVertex2f(32.5f,3.0f);
glVertex2f(31.5f,3.0f);
glEnd();

    // hub + blades
    glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(32.0f,3.0f,0.0f);
    glutSolidSphere(0.5,32,32);
    glRotatef(_angle1, 0.0f, 0.0f, 1.0f);

  glBegin(GL_QUADS);
glColor3ub(255,255,0);
glVertex2f(0.0f, 0.0f);
glVertex2f(5.0f, 0.0f);
glVertex2f(5.0f, 0.25f);
glVertex2f(0.0f, 0.25f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(255,255,0);
glVertex2f(0.0f, 0.0f);
glVertex2f(0.0f, 5.0f);
glVertex2f(-0.25f, 5.0f);
glVertex2f(-0.25f, 0.0f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(255,255,0);
glVertex2f(0.0f, -0.25f);
glVertex2f(0.0f, 0.0f);
glVertex2f(-5.0f, 0.0f);
glVertex2f(-5.0f, -0.25f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(255,255,0);
glVertex2f(0.25f, 0.0f);
glVertex2f(0.0f, 0.0f);
glVertex2f(0.0f, -5.0f);
glVertex2f(0.25f, -5.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(128,0,0);
glVertex2f(0.25f, 0.0f);
glVertex2f(5.0f, -2.5f);
glVertex2f(5.0f, 0.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(128,0,0);
glVertex2f(0.0f, 0.025f);
glVertex2f(2.5f, 5.0f);
glVertex2f(0.0f, 5.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(128,0,0);
glVertex2f(-0.25f, 0.0f);
glVertex2f(-5.0f, 2.5f);
glVertex2f(-5.0f, 0.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(128,0,0);
glVertex2f(0.0f, -0.025f);
glVertex2f(-2.5f, -5.0f);
glVertex2f(0.0f, -5.0f);
glEnd();

glPopMatrix();

    glutSwapBuffers();
}







 /////////////////////////////////SCENE 2 ///////////////////////////////////////////////////////////////


    void drawScene2() {

   glClear(GL_COLOR_BUFFER_BIT);


    // sky (night)
    glBegin(GL_POLYGON);
    glColor3ub(0,0,0);//balck
    glVertex2f(38.0f,3.0f);
    glVertex2f(38.0f,14.0f);
    glVertex2f(-12.0f,14.0f);
    glVertex2f(-12.0f,3.0f);
    glEnd();

// stars
glPointSize(2.0f);
glColor3ub(255,255,255);
glBegin(GL_POINTS);
glVertex2f( 1.0f,  4.0f);
glVertex2f( 2.0f,  7.5f);
glVertex2f( 4.0f,  5.0f);
glVertex2f(-2.0f,  8.0f);
glVertex2f(30.0f,  5.0f);
glVertex2f(-1.0f,  9.0f);
glVertex2f(35.0f,  7.0f);
glVertex2f(-3.0f,  7.0f);
glVertex2f(-7.0f,  5.0f);
glVertex2f(10.0f,  7.5f);
glVertex2f(12.0f,  8.5f);
glVertex2f(-11.0f, 6.0f);
glVertex2f(37.0f,  7.5f);
glVertex2f(-10.0f, 4.5f);
glVertex2f(13.0f,  7.0f);
glVertex2f(14.0f,  7.5f);
glVertex2f(18.0f, 10.0f);
glEnd();


    // moon
glPushMatrix();
glColor3ub(217,217,217);
glTranslatef(-8.0, 10.0, 0);
glutSolidSphere(1, 48, 48);
glPopMatrix();

glPushMatrix();
glColor3ub(0,0,0);
glTranslatef(-8.0, 10.25, 0);
glutSolidSphere(1, 48, 48);
glPopMatrix();


// clouds (gray)

// Cloud 1
glPushMatrix();
glTranslatef(_moveC, 0.0f, 0.0f);

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(1.0f, 6.0f, 0.0f);
glutSolidSphere(0.7, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(1.0f, 7.0f, 0.0f);
glutSolidSphere(0.7, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(2.0f, 7.0f, 0.0f);
glutSolidSphere(0.7, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(2.0f, 6.0f, 0.0f);
glutSolidSphere(0.7, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(0.0f, 6.5f, 0.0f);
glutSolidSphere(0.7, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(3.0f, 6.5f, 0.0f);
glutSolidSphere(0.7, 32, 32);
glPopMatrix();

glPopMatrix();


// Cloud 2
glPushMatrix();
glTranslatef(_moveC, 0.0f, 0.0f);

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(15.0f, 9.0f, 0.0f);
glutSolidSphere(0.8, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(15.0f, 8.0f, 0.0f);
glutSolidSphere(0.8, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(16.0f, 8.0f, 0.0f);
glutSolidSphere(0.8, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(16.0f, 9.0f, 0.0f);
glutSolidSphere(0.8, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(14.0f, 8.5f, 0.0f);
glutSolidSphere(0.8, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(17.0f, 8.5f, 0.0f);
glutSolidSphere(0.8, 32, 32);
glPopMatrix();

glPopMatrix();


// Cloud 3
glPushMatrix();
glTranslatef(_moveC, 0.0f, 0.0f);

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(22.0f, 8.0f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(22.0f, 7.0f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(23.0f, 8.0f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(23.0f, 7.0f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(24.0f, 7.5f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(21.0f, 7.5f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPopMatrix();


    // sea
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 80);
    glVertex2f(38.0f,-19.0f);
    glVertex2f(38.0f,3.0f);
    glVertex2f(-12.0f,3.0f);
    glVertex2f(-12.0f,-19.0f);
    glEnd();



  // LEFT SOIL
glBegin(GL_POLYGON);
glColor3ub(0,128,0);
glVertex2f(4.0f, 0.0f);
glVertex2f(6.0f, 1.0f);
glVertex2f(3.0f, 3.0f);
glVertex2f(-12.0f, 3.0f);
glVertex2f(-12.0f, 0.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,128,0);
glVertex2f(5.0f, -3.0f);
glVertex2f(7.0f, -1.5f);
glVertex2f(4.0f, 0.0f);
glVertex2f(-12.0f, 0.0f);
glVertex2f(-12.0f, -3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,128,0);
glVertex2f(6.0f, -4.5f);
glVertex2f(8.0f, -4.0f);
glVertex2f(5.0f, -3.0f);
glVertex2f(-12.0f, -3.0f);
glVertex2f(-12.0f, -4.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,128,0);
glVertex2f(2.0f, -9.0f);
glVertex2f(9.5f, -7.0f);
glVertex2f(6.0f, -4.5f);
glVertex2f(-12.0f, -4.5f);
glVertex2f(-12.0f, -9.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,128,0);
glVertex2f(2.0f, -11.5f);
glVertex2f(5.0f, -10.0f);
glVertex2f(2.0f, -9.0f);
glVertex2f(-12.0f, -9.0f);
glVertex2f(-12.0f, -11.5f);
glEnd();

//Soil BORDERS
glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(6.0f, 0.5f);
glVertex2f(6.0f, 1.0f);
glVertex2f(4.0f, 0.0f);
glVertex2f(4.5f, -0.25f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(7.0f, -2.0f);
glVertex2f(7.0f, -1.5f);
glVertex2f(5.0f, -3.0f);
glVertex2f(5.5f, -3.15f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(8.0f, -4.4f);
glVertex2f(8.0f, -4.0f);
glVertex2f(6.0f, -4.5f);
glVertex2f(6.3f, -4.8f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(9.5f, -7.5f);
glVertex2f(9.5f, -7.0f);
glVertex2f(2.0f, -9.0f);
glVertex2f(3.0f, -9.3f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(5.0f, -10.5f);
glVertex2f(5.0f, -10.0f);
glVertex2f(2.0f, -11.5f);
glVertex2f(2.0f, -12.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(2.0f, -12.0f);
glVertex2f(2.0f, -11.5f);
glVertex2f(-12.0f, -11.5f);
glVertex2f(-12.0f, -12.0f);
glEnd();



// Right soil
glBegin(GL_POLYGON);
glColor3ub(0,128,0);
glVertex2f(13.0f, 3.0f);
glVertex2f(16.0f, 1.0f);
glVertex2f(38.0f, 1.0f);
glVertex2f(38.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,128,0);
glVertex2f(16.0f, 1.0f);
glVertex2f(14.0f, 0.0f);
glVertex2f(17.0f,-1.5f);
glVertex2f(38.0f,-1.5f);
glVertex2f(38.0f, 1.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,128,0);
glVertex2f(17.0f,-1.5f);
glVertex2f(15.0f,-3.0f);
glVertex2f(18.0f,-4.0f);
glVertex2f(38.0f,-4.0f);
glVertex2f(38.0f,-1.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,128,0);
glVertex2f(18.0f,-4.0f);
glVertex2f(16.0f,-4.5f);
glVertex2f(21.0f,-7.0f);
glVertex2f(38.0f,-7.0f);
glVertex2f(38.0f,-4.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,128,0);
glVertex2f(21.0f,-7.0f);
glVertex2f(19.0f,-8.0f);
glVertex2f(22.0f,-9.0f);
glVertex2f(38.0f,-9.0f);
glVertex2f(38.0f,-7.0f);
glEnd();

// right soil borders
glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(12.5f, 3.0f);
glVertex2f(15.6f, 0.8f);
glVertex2f(16.0f, 1.0f);
glVertex2f(13.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(14.0f,-0.5f);
glVertex2f(16.4f,-1.9f);
glVertex2f(17.0f,-1.5f);
glVertex2f(14.0f, 0.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(15.0f,-3.5f);
glVertex2f(17.0f,-4.2f);
glVertex2f(18.0f,-4.0f);
glVertex2f(15.0f,-3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(16.0f,-5.0f);
glVertex2f(20.5f,-7.2f);
glVertex2f(21.0f,-7.0f);
glVertex2f(16.0f,-4.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(19.0f,-8.5f);
glVertex2f(22.0f,-9.5f);
glVertex2f(22.0f,-9.0f);
glVertex2f(19.0f,-8.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(38.0f,-9.0f);
glVertex2f(22.0f,-9.0f);
glVertex2f(22.0f,-9.5f);
glVertex2f(38.0f,-9.5f);
glEnd();



    // house (left)

// Main body
glBegin(GL_POLYGON);
glColor3ub(178,34,34);
glVertex2f(-10.2f,-3.5f);
glVertex2f(-4.2f,-3.5f);
glVertex2f(-4.2f, 3.0f);
glVertex2f(-10.2f, 3.0f);
glEnd();

// Roof
glBegin(GL_TRIANGLES);
glColor3ub(105,105,105);
glVertex2f(-10.4f,3.0f);
glVertex2f(-4.0f,3.0f);
glVertex2f(-7.2f,4.5f);
glEnd();

// Roof top bar
glBegin(GL_POLYGON);
glColor3ub(80,80,80);
glVertex2f(-10.4f,3.0f);
glVertex2f(-4.0f,3.0f);
glVertex2f(-4.0f,2.7f);
glVertex2f(-10.4f,2.7f);
glEnd();

// Door
glBegin(GL_POLYGON);
glColor3ub(90,60,40);
glVertex2f(-7.7f,-3.5f);
glVertex2f(-6.7f,-3.5f);
glVertex2f(-6.7f,-1.0f);
glVertex2f(-7.7f,-1.0f);
glEnd();

// Windows (bottom row, left)
glBegin(GL_POLYGON);
glColor3ub(135,206,235);
glVertex2f(-9.9f,-2.5f);
glVertex2f(-8.9f,-2.5f);
glVertex2f(-8.9f,-0.5f);
glVertex2f(-9.9f,-0.5f);
glEnd();

// Windows (bottom row, right)
glBegin(GL_POLYGON);
glColor3ub(135,206,235);
glVertex2f(-5.5f,-2.5f);
glVertex2f(-4.5f,-2.5f);
glVertex2f(-4.5f,-0.5f);
glVertex2f(-5.5f,-0.5f);
glEnd();

// Windows (top row, left)
glBegin(GL_POLYGON);
glColor3ub(135,206,235);
glVertex2f(-9.9f,0.0f);
glVertex2f(-8.9f,0.0f);
glVertex2f(-8.9f,2.0f);
glVertex2f(-9.9f,2.0f);
glEnd();

// Windows (top row, right)
glBegin(GL_POLYGON);
glColor3ub(135,206,235);
glVertex2f(-5.5f,0.0f);
glVertex2f(-4.5f,0.0f);
glVertex2f(-4.5f,2.0f);
glVertex2f(-5.5f,2.0f);
glEnd();

// Center window (top middle, aligned over door)
glBegin(GL_POLYGON);
glColor3ub(135,206,235);
glVertex2f(-7.7f,0.0f);
glVertex2f(-6.7f,0.0f);
glVertex2f(-6.7f,2.0f);
glVertex2f(-7.7f,2.0f);
glEnd();

// Window borders (left trim)
glBegin(GL_POLYGON);
glColor3ub(50,50,50);
glVertex2f(-10.0f,-2.6f);
glVertex2f(-8.8f,-2.6f);
glVertex2f(-8.8f,-0.4f);
glVertex2f(-10.0f,-0.4f);
glEnd();

// Window border
glBegin(GL_POLYGON);
glColor3ub(50,50,50);
glVertex2f(-5.6f,-2.6f);
glVertex2f(-4.4f,-2.6f);
glVertex2f(-4.4f,-0.4f);
glVertex2f(-5.6f,-0.4f);
glEnd();

// Porch
glBegin(GL_POLYGON);
glColor3ub(178,34,34);
glVertex2f(-4.2f,-3.5f);
glVertex2f(-1.7f,-3.5f);
glVertex2f(-1.7f,1.0f);
glVertex2f(-4.2f,1.0f);
glEnd();

// Porch roof
glBegin(GL_POLYGON);
glColor3ub(100,100,100);
glVertex2f(-4.2f,1.0f);
glVertex2f(-1.7f,1.0f);
glVertex2f(-1.7f,1.3f);
glVertex2f(-4.2f,1.3f);
glEnd();


// DARK HOUSE 2

// Main body
glBegin(GL_POLYGON);
glColor3ub(120,120,120);
glVertex2f(-2.2f,-3.5f);
glVertex2f(4.3f,-3.5f);
glVertex2f(4.3f,0.5f);
glVertex2f(-2.2f,0.5f);
glEnd();

// Roof
glBegin(GL_TRIANGLES);
glColor3ub(60,40,40);
glVertex2f(-2.2f,0.5f);
glVertex2f(4.3f,0.5f);
glVertex2f(1.05f,4.0f);
glEnd();

// Roof outline
glBegin(GL_LINE_LOOP);
glColor3ub(20,20,20);
glVertex2f(-2.2f,0.5f);
glVertex2f(4.3f,0.5f);
glVertex2f(1.05f,4.0f);
glEnd();

// Door
glBegin(GL_POLYGON);
glColor3ub(80,50,30);
glVertex2f(0.55f,-3.5f);
glVertex2f(1.55f,-3.5f);
glVertex2f(1.55f,-0.5f);
glVertex2f(0.55f,-0.5f);
glEnd();

// Left window
glBegin(GL_POLYGON);
glColor3ub(90,110,130);
glVertex2f(-1.25f,-2.5f);
glVertex2f(-0.25f,-2.5f);
glVertex2f(-0.25f,-0.5f);
glVertex2f(-1.25f,-0.5f);
glEnd();

// Right window
glBegin(GL_POLYGON);
glColor3ub(90,110,130);
glVertex2f(2.35f,-2.5f);
glVertex2f(3.35f,-2.5f);
glVertex2f(3.35f,-0.5f);
glVertex2f(2.35f,-0.5f);
glEnd();

// Window frames
glBegin(GL_POLYGON);
glColor3ub(30,30,30);
glVertex2f(-0.78f,-2.5f);
glVertex2f(-0.72f,-2.5f);
glVertex2f(-0.72f,-0.5f);
glVertex2f(-0.78f,-0.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(30,30,30);
glVertex2f(2.82f,-2.5f);
glVertex2f(2.88f,-2.5f);
glVertex2f(2.88f,-0.5f);
glVertex2f(2.82f,-0.5f);
glEnd();

// Small window
glBegin(GL_POLYGON);
glColor3ub(70,90,110);
glVertex2f(0.70f,1.3f);
glVertex2f(1.40f,1.3f);
glVertex2f(1.40f,2.0f);
glVertex2f(0.70f,2.0f);
glEnd();

// tree
glBegin(GL_POLYGON);
glColor3ub(139,69,19);
glVertex2f(-9.5f, 1.0f);
glVertex2f(-9.0f, 1.5f);
glVertex2f(-9.5f, 2.5f);
glVertex2f(-10.0f, 2.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(139,69,19);
glVertex2f(-9.0f, 1.5f);
glVertex2f(-8.5f, 1.0f);
glVertex2f(-8.0f, 2.0f);
glVertex2f(-8.0f, 2.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(139,69,19);
glVertex2f(-9.5f, 1.0f);
glVertex2f(-9.5f,-3.5f);
glVertex2f(-9.0f,-4.0f);
glVertex2f(-8.5f,-3.5f);
glVertex2f(-8.5f, 1.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(139,69,19);
glVertex2f(-8.5f,-3.0f);
glVertex2f(-9.5f,-3.0f);
glVertex2f(-10.5f,-3.5f);
glVertex2f(-7.5f,-3.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(139,69,19);
glVertex2f(-10.0f,-0.5f);
glVertex2f(-9.5f,-1.0f);
glVertex2f(-9.5f,-0.6f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(139,69,19);
glVertex2f(-9.5f, 1.0f);
glVertex2f(-9.0f, 1.5f);
glVertex2f(-8.5f, 1.0f);
glEnd();


// hills (same as day)
glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(-12.0f, 3.0f);
glVertex2f(-11.5f, 4.5f);
glVertex2f(-7.5f, 4.5f);
glVertex2f(-7.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(-11.5f, 4.5f);
glVertex2f(-11.0f, 5.5f);
glVertex2f(-8.0f, 5.5f);
glVertex2f(-7.5f, 4.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(-11.0f, 5.5f);
glVertex2f(-10.5f, 6.0f);
glVertex2f(-8.5f, 6.0f);
glVertex2f(-8.0f, 5.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(-10.5f, 6.0f);
glVertex2f(-10.3f, 6.2f);
glVertex2f(-8.7f, 6.2f);
glVertex2f(-8.5f, 6.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(-10.3f, 6.2f);
glVertex2f(-10.2f, 6.3f);
glVertex2f(-8.8f, 6.3f);
glVertex2f(-8.7f, 6.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(-7.0f, 3.0f);
glVertex2f(-6.5f, 4.0f);
glVertex2f(-4.5f, 4.0f);
glVertex2f(-4.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(-6.5f, 4.0f);
glVertex2f(-6.0f, 4.5f);
glVertex2f(-5.0f, 4.5f);
glVertex2f(-4.5f, 4.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(-4.0f, 3.0f);
glVertex2f(-3.5f, 4.5f);
glVertex2f(-1.5f, 4.5f);
glVertex2f(-1.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(-3.5f, 4.5f);
glVertex2f(-3.0f, 5.0f);
glVertex2f(-2.0f, 5.0f);
glVertex2f(-1.5f, 4.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(-1.0f, 3.0f);
glVertex2f(-0.5f, 6.0f);
glVertex2f(4.5f, 6.0f);
glVertex2f(5.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(-0.5f, 6.0f);
glVertex2f(0.0f, 7.0f);
glVertex2f(4.0f, 7.0f);
glVertex2f(4.5f, 6.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(0.0f, 7.0f);
glVertex2f(1.0f, 8.0f);
glVertex2f(3.0f, 8.0f);
glVertex2f(4.0f, 7.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,100,0);
glVertex2f(1.0f, 8.0f);
glVertex2f(3.0f, 8.0f);
glVertex2f(2.0f, 8.3f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(5.0f, 3.0f);
glVertex2f(5.5f, 4.0f);
glVertex2f(6.5f, 4.0f);
glVertex2f(7.0f, 3.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,100,0);
glVertex2f(5.5f, 4.0f);
glVertex2f(6.5f, 4.0f);
glVertex2f(6.0f, 4.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(7.0f, 3.0f);
glVertex2f(8.0f, 5.0f);
glVertex2f(13.0f, 5.0f);
glVertex2f(14.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(8.0f, 5.0f);
glVertex2f(9.0f, 6.0f);
glVertex2f(12.0f, 6.0f);
glVertex2f(13.0f, 5.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,100,0);
glVertex2f(9.0f, 6.0f);
glVertex2f(12.0f, 6.0f);
glVertex2f(10.5f, 6.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(14.0f, 3.0f);
glVertex2f(15.0f, 5.0f);
glVertex2f(20.0f, 5.0f);
glVertex2f(21.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(15.0f, 5.0f);
glVertex2f(16.0f, 6.0f);
glVertex2f(19.0f, 6.0f);
glVertex2f(20.0f, 5.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,100,0);
glVertex2f(16.0f, 6.0f);
glVertex2f(19.0f, 6.0f);
glVertex2f(17.5f, 6.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(21.0f, 3.0f);
glVertex2f(22.0f, 5.0f);
glVertex2f(24.0f, 5.0f);
glVertex2f(25.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(22.0f, 5.0f);
glVertex2f(22.5f, 5.5f);
glVertex2f(23.5f, 5.5f);
glVertex2f(24.0f, 5.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(25.0f, 3.0f);
glVertex2f(25.5f, 4.5f);
glVertex2f(28.5f, 4.5f);
glVertex2f(29.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(25.5f, 4.5f);
glVertex2f(26.0f, 5.0f);
glVertex2f(28.0f, 5.0f);
glVertex2f(28.5f, 4.5f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(29.0f, 3.0f);
glVertex2f(29.5f, 4.0f);
glVertex2f(30.5f, 4.0f);
glVertex2f(31.0f, 3.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,100,0);
glVertex2f(29.5f, 4.0f);
glVertex2f(30.0f, 4.5f);
glVertex2f(30.5f, 4.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(31.0f, 3.0f);
glVertex2f(31.5f, 4.5f);
glVertex2f(32.5f, 4.5f);
glVertex2f(33.0f, 3.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,100,0);
glVertex2f(31.5f, 4.5f);
glVertex2f(32.5f, 4.5f);
glVertex2f(32.0f, 5.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(33.0f, 3.0f);
glVertex2f(33.5f, 4.5f);
glVertex2f(37.5f, 4.5f);
glVertex2f(38.0f, 3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(0,100,0);
glVertex2f(33.5f, 4.5f);
glVertex2f(34.0f, 5.0f);
glVertex2f(37.0f, 5.0f);
glVertex2f(37.5f, 4.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,100,0);
glVertex2f(34.0f, 5.0f);
glVertex2f(37.0f, 5.0f);
glVertex2f(35.5f, 5.5f);
glEnd();


// tree canopy (green)
glPushMatrix();
glColor3ub(50,205,50);
glTranslatef(-10.5f, 2.5f, 0.0f);
glutSolidSphere(1.0, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(50,205,50);
glTranslatef(-9.5f, 3.0f, 0.0f);
glutSolidSphere(1.0, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(50,205,50);
glTranslatef(-7.5f, 1.5f, 0.0f);
glutSolidSphere(1.0, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(50,205,50);
glTranslatef(-7.5f, 2.5f, 0.0f);
glutSolidSphere(1.0, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(50,205,50);
glTranslatef(-8.5f, 3.5f, 0.0f);
glutSolidSphere(1.0, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(50,205,50);
glTranslatef(-10.0f, 4.0f, 0.0f);
glutSolidSphere(1.0, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(50,205,50);
glTranslatef(-8.0f, 4.0f, 0.0f);
glutSolidSphere(1.0, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(50,205,50);
glTranslatef(-9.0f, 5.0f, 0.0f);
glutSolidSphere(1.0, 32, 32);
glPopMatrix();



// boat-1 (moving left to right)
glPushMatrix();
glTranslatef(_moveA, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(139,69,19);
glVertex2f( 1.0f, -14.0f);
glVertex2f( 1.5f, -13.0f);
glVertex2f(-2.0f, -13.0f);
glVertex2f(-3.0f, -14.0f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f( 2.0f, -14.5f);
glVertex2f( 2.0f, -14.0f);
glVertex2f(-3.0f, -14.0f);
glVertex2f(-3.0f, -14.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,0,0);
glVertex2f(-3.0f, -14.5f);
glVertex2f(-3.0f, -14.0f);
glVertex2f(-4.5f, -13.7f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,0,0);
glVertex2f( 2.0f, -14.5f);
glVertex2f( 3.5f, -13.7f);
glVertex2f( 2.0f, -14.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,0,0);
glVertex2f( 2.0f, -14.0f);
glVertex2f( 1.5f, -13.0f);
glVertex2f( 1.0f, -14.0f);
glEnd();

glPopMatrix();

// boat-2 (moving R to L)
glPushMatrix();
glTranslatef(_moveB, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(139,69,19);
glVertex2f(22.0f, -17.5f);
glVertex2f(21.0f, -16.5f);
glVertex2f(17.5f, -16.5f);
glVertex2f(18.0f, -17.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f(22.0f, -18.0f);
glVertex2f(22.0f, -17.5f);
glVertex2f(17.0f, -17.5f);
glVertex2f(17.0f, -18.0f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(139,69,19);
glVertex2f(19.8f, -14.5f);
glVertex2f(19.8f, -14.0f);
glVertex2f(19.7f, -14.0f);
glVertex2f(19.7f, -14.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,0,0);
glVertex2f(17.0f, -18.0f);
glVertex2f(17.0f, -17.5f);
glVertex2f(15.5f, -17.2f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,0,0);
glVertex2f(22.0f, -17.5f);
glVertex2f(22.0f, -18.0f);
glVertex2f(23.5f, -17.2f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,0,0);
glVertex2f(17.0f, -17.5f);
glVertex2f(18.0f, -17.5f);
glVertex2f(17.5f, -16.5f);
glEnd();

// Mast sail hook
glBegin(GL_QUADS);
glColor3ub(139,69,19);
glVertex2f(19.75f, -16.5f);
glVertex2f(19.85f, -16.5f);
glVertex2f(19.85f, -14.2f);
glVertex2f(19.75f, -14.2f);
glEnd();

// Sail
glBegin(GL_TRIANGLES);
glColor3ub(255,99,71);
glVertex2f(19.82f, -14.3f);
glVertex2f(19.82f, -16.2f);
glVertex2f(18.60f, -15.25f);
glEnd();

glPopMatrix();


   // boat-3
glBegin(GL_POLYGON);
glColor3ub(0,0,0);
glVertex2f(8.0f,  -2.5f);
glVertex2f(10.5f, -2.5f);
glVertex2f(10.5f, -2.2f);
glVertex2f(8.0f,  -2.2f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,0,0);
glVertex2f(8.0f,  -2.2f);
glVertex2f(7.0f,  -2.0f);
glVertex2f(8.0f,  -2.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,0,0);
glVertex2f(11.5f, -2.0f);
glVertex2f(10.5f, -2.2f);
glVertex2f(10.5f, -2.5f);
glEnd();


    // First WINDMILL (left)

// tower
glBegin(GL_POLYGON);
glColor3ub(192,192,192);
glVertex2f(25.0f, 2.0f);
glVertex2f(24.75f,-5.0f);
glVertex2f(27.25f,-5.0f);
glVertex2f(27.0f, 2.0f);
glVertex2f(26.5f, 3.0f);
glVertex2f(25.5f, 3.0f);
glEnd();

    // hub + blades
    glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(26.0f, 3.0f, 0.0f);
    glutSolidSphere(0.5, 32, 32);
    glRotatef(_angle1, 0.0f, 0.0f, 1.0f);

glBegin(GL_QUADS);
glColor3ub(255,255,0);
glVertex2f(0.0f, 0.0f);
glVertex2f(5.0f, 0.0f);
glVertex2f(5.0f, 0.25f);
glVertex2f(0.0f, 0.25f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(255,255,0);
glVertex2f(0.0f, 0.0f);
glVertex2f(0.0f, 5.0f);
glVertex2f(-0.25f, 5.0f);
glVertex2f(-0.25f, 0.0f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(255,255,0);
glVertex2f(0.0f, -0.25f);
glVertex2f(0.0f, 0.0f);
glVertex2f(-5.0f, 0.0f);
glVertex2f(-5.0f, -0.25f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(255,255,0);
glVertex2f(0.25f, 0.0f);
glVertex2f(0.0f, 0.0f);
glVertex2f(0.0f, -5.0f);
glVertex2f(0.25f, -5.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(128,0,0);
glVertex2f(0.25f, 0.0f);
glVertex2f(5.0f, -2.5f);
glVertex2f(5.0f, 0.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(128,0,0);
glVertex2f(0.0f, 0.025f);
glVertex2f(2.5f, 5.0f);
glVertex2f(0.0f, 5.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(128,0,0);
glVertex2f(-0.25f, 0.0f);
glVertex2f(-5.0f, 2.5f);
glVertex2f(-5.0f, 0.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(128,0,0);
glVertex2f(0.0f, -0.025f);
glVertex2f(-2.5f, -5.0f);
glVertex2f(0.0f, -5.0f);
glEnd();

glPopMatrix();



    // Second WINDMILL

// windmill tower
glBegin(GL_POLYGON);
glColor3ub(192,192,192);
glVertex2f(31.0f,2.0f);
glVertex2f(30.75f,-6.0f);
glVertex2f(33.25f,-6.0f);
glVertex2f(33.0f,2.0f);
glVertex2f(32.5f,3.0f);
glVertex2f(31.5f,3.0f);
glEnd();

    // hub + blades
    glPushMatrix();
    glColor3ub(0,0,0);
    glTranslatef(32.0f,3.0f,0.0f);
    glutSolidSphere(0.5,32,32);
    glRotatef(_angle1, 0.0f, 0.0f, 1.0f);

  glBegin(GL_QUADS);
glColor3ub(255,255,0);
glVertex2f(0.0f, 0.0f);
glVertex2f(5.0f, 0.0f);
glVertex2f(5.0f, 0.25f);
glVertex2f(0.0f, 0.25f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(255,255,0);
glVertex2f(0.0f, 0.0f);
glVertex2f(0.0f, 5.0f);
glVertex2f(-0.25f, 5.0f);
glVertex2f(-0.25f, 0.0f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(255,255,0);
glVertex2f(0.0f, -0.25f);
glVertex2f(0.0f, 0.0f);
glVertex2f(-5.0f, 0.0f);
glVertex2f(-5.0f, -0.25f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(255,255,0);
glVertex2f(0.25f, 0.0f);
glVertex2f(0.0f, 0.0f);
glVertex2f(0.0f, -5.0f);
glVertex2f(0.25f, -5.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(128,0,0);
glVertex2f(0.25f, 0.0f);
glVertex2f(5.0f, -2.5f);
glVertex2f(5.0f, 0.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(128,0,0);
glVertex2f(0.0f, 0.025f);
glVertex2f(2.5f, 5.0f);
glVertex2f(0.0f, 5.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(128,0,0);
glVertex2f(-0.25f, 0.0f);
glVertex2f(-5.0f, 2.5f);
glVertex2f(-5.0f, 0.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(128,0,0);
glVertex2f(0.0f, -0.025f);
glVertex2f(-2.5f, -5.0f);
glVertex2f(0.0f, -5.0f);
glEnd();

glPopMatrix();

    glutSwapBuffers();
}








///////////////////////////////Scene 3 Ship scene/////////////////////////////////////

void drawScene3() {
     glClear(GL_COLOR_BUFFER_BIT);


    // ---------- SKY ----------
    glBegin(GL_QUADS);
        glColor3f(0.76f,0.90f,0.99f);
        glVertex2f(-12.0f,14.0f);
        glVertex2f( 38.0f,14.0f);

        glColor3f(0.68f,0.86f,0.97f);
        glVertex2f( 38.0f, 3.2f);
        glVertex2f(-12.0f, 3.2f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.91f,0.96f,0.99f);
        glVertex2f(-12.0f,3.2f);
        glVertex2f( 38.0f,3.2f);

        glColor3f(0.88f,0.94f,0.98f);
        glVertex2f( 38.0f,2.5f);
        glVertex2f(-12.0f,2.5f);
    glEnd();


      // sun
    glPushMatrix();
    glColor3ub(255,255,0);
    glTranslatef(9.0, 11.0, 0);
    glutSolidSphere(1.0, 64, 64);
    glPopMatrix();

    // cloud 1
    glPushMatrix();
    glTranslatef(_moveC,0.0f,0.0f);

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(1.0, 6.0, 0);
    glutSolidSphere(0.7, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(1.0, 7.0, 0);
    glutSolidSphere(0.7, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(2.0, 7.0, 0);
    glutSolidSphere(0.7, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(2.0, 6.0, 0);
    glutSolidSphere(0.7, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(0.0, 6.5, 0);
    glutSolidSphere(0.7, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(3.0, 6.5, 0);
    glutSolidSphere(0.7, 32, 32);
    glPopMatrix();

    glPopMatrix();

    // cloud 2
    glPushMatrix();
    glTranslatef(_moveC,0.0f,0.0f);

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(15.0, 9.0, 0);
    glutSolidSphere(0.8, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(15.0, 8.0, 0);
    glutSolidSphere(0.8, 32, 32);
    glPopMatrix();

    glPushMatrix();
     glColor3ub(255,255,255);
     glTranslatef(16.0, 8.0, 0);
     glutSolidSphere(0.8, 32, 32);
     glPopMatrix();

    glPushMatrix();
     glColor3ub(255,255,255);
     glTranslatef(16.0, 9.0, 0);
     glutSolidSphere(0.8, 32, 32);
     glPopMatrix();

    glPushMatrix();
     glColor3ub(255,255,255);
     glTranslatef(14.0, 8.5, 0);
     glutSolidSphere(0.8, 32, 32);
     glPopMatrix();

    glPushMatrix();
     glColor3ub(255,255,255);
     glTranslatef(17.0, 8.5, 0);
     glutSolidSphere(0.8, 32, 32);
     glPopMatrix();

    glPopMatrix();

    // cloud 3
   glPushMatrix();
   glTranslatef(_moveC, 0.0f, 0.0f);

   glPushMatrix();
   glColor3ub(255, 255, 255);
   glTranslatef(22.0f, 8.0f, 0.0f);
  glutSolidSphere(0.75, 32, 32);
   glPopMatrix();

glPushMatrix();
glColor3ub(255, 255, 255);
glTranslatef(22.0f, 7.0f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(255, 255, 255);
glTranslatef(23.0f, 8.0f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(255, 255, 255);
glTranslatef(23.0f, 7.0f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(255, 255, 255);
glTranslatef(24.0f, 7.5f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(255, 255, 255);
glTranslatef(21.0f, 7.5f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPopMatrix();




//  ONE GREEN MOUNTAIN
glBegin(GL_POLYGON);
    glColor3f(0.16f, 0.43f, 0.28f);
    glVertex2f(-2.5f, 3.2f);

    glColor3f(0.20f, 0.50f, 0.33f);
    glVertex2f(0.0f, 4.1f);

    glColor3f(0.25f, 0.58f, 0.37f);
    glVertex2f(2.7f, 5.2f);

    glColor3f(0.30f, 0.65f, 0.41f);
    glVertex2f(5.5f, 6.0f);

    glColor3f(0.36f, 0.72f, 0.46f);
    glVertex2f(8.3f, 6.7f);

    glColor3f(0.40f, 0.76f, 0.49f);
    glVertex2f(11.1f, 7.1f);

    glColor3f(0.34f, 0.70f, 0.46f);
    glVertex2f(13.8f, 6.6f);

    glColor3f(0.28f, 0.61f, 0.41f);
    glVertex2f(16.5f, 5.8f);

    glColor3f(0.22f, 0.53f, 0.36f);
    glVertex2f(19.0f, 4.8f);

    glColor3f(0.18f, 0.45f, 0.31f);
    glVertex2f(21.6f, 3.9f);

    glColor3f(0.16f, 0.43f, 0.28f);
    glVertex2f(24.4f, 3.2f);
    glVertex2f(20.0f, 3.2f);
    glVertex2f(15.0f, 3.2f);
    glVertex2f(10.0f, 3.2f);
    glVertex2f(5.0f, 3.2f);
    glVertex2f(0.0f, 3.2f);
glEnd();


glBegin(GL_POLYGON); // sun highlight
    glColor3f(0.45f, 0.80f, 0.52f);
    glVertex2f(10.8f, 6.9f);

    glColor3f(0.45f, 0.80f, 0.52f);
    glVertex2f(12.4f, 6.5f);

    glColor3f(0.40f, 0.76f, 0.49f);
    glVertex2f(14.2f, 6.0f);

    glColor3f(0.35f, 0.70f, 0.46f);
    glVertex2f(16.1f, 5.4f);

    glColor3f(0.30f, 0.62f, 0.41f);
    glVertex2f(18.1f, 4.7f);

    glColor3f(0.26f, 0.56f, 0.38f);
    glVertex2f(19.8f, 4.0f);

    glColor3f(0.24f, 0.52f, 0.35f);
    glVertex2f(18.0f, 3.5f);

    glColor3f(0.30f, 0.62f, 0.41f);
    glVertex2f(15.2f, 4.2f);

    glColor3f(0.36f, 0.72f, 0.46f);
    glVertex2f(12.6f, 5.2f);

    glColor3f(0.40f, 0.76f, 0.49f);
    glVertex2f(10.8f, 6.1f);

glEnd();


glBegin(GL_POLYGON); //lower part of the hill
    glColor3f(0.12f, 0.35f, 0.23f);
    glVertex2f(-2.5f, 3.2f);
    glVertex2f(24.4f, 3.2f);
    glVertex2f(23.0f, 3.5f);
    glVertex2f(19.0f, 3.7f);
    glVertex2f(14.0f, 3.9f);
    glVertex2f(10.0f, 3.9f);
    glVertex2f(6.0f, 3.8f);
    glVertex2f(2.0f, 3.6f);
    glVertex2f(-1.0f, 3.4f);
glEnd();


   // ---------- SEA ----------
glBegin(GL_QUADS);
    glColor3f(0.18f, 0.73f, 0.71f);
    glVertex2f(-12.0f, 3.2f);
    glVertex2f(38.0f, 3.2f);

    glColor3f(0.10f, 0.61f, 0.60f);
    glVertex2f(38.0f, -19.0f);
    glVertex2f(-12.0f, -19.0f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(0.16f, 0.70f, 0.69f);
    glVertex2f(-12.0f, 3.2f);
    glVertex2f(38.0f, 3.2f);

    glColor3f(0.14f, 0.67f, 0.66f);
    glVertex2f(38.0f, 2.0f);
    glVertex2f(-12.0f, 2.0f);
glEnd();



// SEA WAVES
glLineWidth(2.0f);
glColor3f(0.72f, 0.92f, 0.92f);

glBegin(GL_LINE_STRIP);
    glVertex2f(20.8f, 0.70f);
    glVertex2f(21.6f, 0.75f);
    glVertex2f(22.5f, 0.69f);
    glVertex2f(23.3f, 0.77f);
    glVertex2f(24.1f, 0.71f);
glEnd();

glBegin(GL_LINE_STRIP);
    glVertex2f(12.2f, 0.10f);
    glVertex2f(13.3f, 0.14f);
    glVertex2f(14.3f, 0.08f);
    glVertex2f(15.3f, 0.16f);
    glVertex2f(16.2f, 0.09f);
glEnd();

glBegin(GL_LINE_STRIP);
    glVertex2f(4.0f, -1.9f);
    glVertex2f(5.5f, -1.8f);
    glVertex2f(7.0f, -2.0f);
    glVertex2f(8.5f, -1.8f);
    glVertex2f(10.0f, -2.0f);
glEnd();



//  BOAT left
glBegin(GL_POLYGON);
    glColor3ub(18, 26, 28);
    glVertex2f(-6.50f, -1.18f);
    glVertex2f(-3.90f, -1.07f);
    glVertex2f(-2.70f, -0.97f);
    glVertex2f(-2.58f, -0.88f);
    glVertex2f(-3.70f, -0.86f);
    glVertex2f(-4.80f, -0.89f);
    glVertex2f(-6.50f, -0.98f);
glEnd();

// Beige color upper side of boat
glBegin(GL_QUADS);
    glColor3ub(196, 176, 134);
    glVertex2f(-6.42f, -1.00f);
    glVertex2f(-2.66f, -0.90f);
    glVertex2f(-2.66f, -0.86f);
    glVertex2f(-6.42f, -0.96f);
glEnd();

// Waterline
glColor3ub(240, 240, 240);
glBegin(GL_POLYGON);
    glVertex2f(-4.20f, -0.96f);
    glVertex2f(-4.15f, -0.95f);
    glVertex2f(-4.10f, -0.96f);
    glVertex2f(-4.08f, -1.00f);
    glVertex2f(-4.10f, -1.04f);
    glVertex2f(-4.15f, -1.05f);
    glVertex2f(-4.20f, -1.04f);
    glVertex2f(-4.22f, -1.00f);
glEnd();

// Mast
glBegin(GL_QUADS);
    glColor3ub(206, 180, 140);
    glVertex2f(-4.12f, -0.90f);
    glVertex2f(-4.06f, -0.90f);
    glVertex2f(-4.06f, 1.82f);
    glVertex2f(-4.12f, 1.82f);
glEnd();

// sail Backstay
glBegin(GL_LINES);
    glColor3ub(150, 150, 150);
    glVertex2f(-4.09f, 1.82f);
    glVertex2f(-4.95f, -0.88f);
    //sail forstay
    glVertex2f(-4.09f, 1.82f);
    glVertex2f(-2.60f, -0.70f);
glEnd();

//sail Boom
glBegin(GL_QUADS);
    glColor3ub(206, 180, 140);
    glVertex2f(-4.12f, -0.78f);
    glVertex2f(-2.58f, -0.70f);
    glVertex2f(-2.58f, -0.76f);
    glVertex2f(-4.12f, -0.84f);
glEnd();

// Main sail
glBegin(GL_POLYGON);
    glColor3ub(138, 28, 28);
    glVertex2f(-4.09f, 1.82f);
    glColor3ub(160, 38, 38);
    glVertex2f(-3.82f, 1.18f);
    glColor3ub(168, 48, 48);
    glVertex2f(-3.55f, 0.72f);
    glColor3ub(174, 56, 56);
    glVertex2f(-3.28f, 0.32f);
    glColor3ub(168, 48, 48);
    glVertex2f(-3.04f, 0.00f);
    glColor3ub(158, 36, 36);
    glVertex2f(-2.82f, -0.28f);
    glColor3ub(150, 32, 32);
    glVertex2f(-2.58f, -0.70f);
    glColor3ub(150, 35, 35);
    glVertex2f(-3.60f, -0.76f);
    glColor3ub(148, 34, 34);
    glVertex2f(-4.12f, -0.78f);
glEnd();

glBegin(GL_LINES);
    glColor3ub(220, 190, 190);
    glVertex2f(-4.10f, 1.10f);
    glVertex2f(-3.02f, -0.70f);
    glVertex2f(-4.10f, 0.30f);
    glVertex2f(-3.25f, -0.70f);
glEnd();


glBegin(GL_POLYGON);
    glColor3ub(155, 36, 36);
    glVertex2f(-4.12f, -0.78f);
    glColor3ub(168, 48, 48);
    glVertex2f(-3.40f, 0.94f);
    glColor3ub(140, 28, 28);
    glVertex2f(-2.58f, -0.70f);
glEnd();

// Tiny  flag
glBegin(GL_TRIANGLES);
    glColor3ub(192, 40, 40);
    glVertex2f(-4.09f, 1.86f);
    glVertex2f(-3.94f, 1.78f);
    glVertex2f(-4.09f, 1.72f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3ub(192, 40, 40);
    glVertex2f(-6.45f, -1.02f);
    glVertex2f(-6.24f, -1.06f);
    glVertex2f(-6.45f, -1.12f);
glEnd();
glLineWidth(2.0f);
glColor3ub(205, 230, 230);
glBegin(GL_LINE_STRIP);
    glVertex2f(-4.9f, -1.22f);
    glVertex2f(-4.3f, -1.28f);
    glVertex2f(-3.7f, -1.22f);
glEnd();



//  BOAT B –right

// Hull
glBegin(GL_POLYGON);
    glColor3ub(18, 26, 28);
    glVertex2f(28.10f, -2.20f);
    glVertex2f(30.60f, -2.10f);
    glVertex2f(31.70f, -2.00f);
    glVertex2f(31.82f, -1.90f);
    glVertex2f(30.60f, -1.88f);
    glVertex2f(29.30f, -1.92f);
    glVertex2f(28.10f, -2.02f);
glEnd();

// Coaming
glBegin(GL_QUADS);
    glColor3ub(196, 176, 134);
    glVertex2f(28.18f, -2.02f);
    glVertex2f(31.74f, -1.94f);
    glVertex2f(31.74f, -1.90f);
    glVertex2f(28.18f, -1.98f);
glEnd();

// Mast
glBegin(GL_QUADS);
    glColor3ub(206, 180, 140);
    glVertex2f(29.62f, -1.96f);
    glVertex2f(29.68f, -1.96f);
    glVertex2f(29.68f, 0.58f);
    glVertex2f(29.62f, 0.58f);
glEnd();

// Stays
glBegin(GL_LINES);
    glColor3ub(150, 150, 150);
    glVertex2f(29.65f, 0.58f);
    glVertex2f(28.95f, -1.94f);
    glVertex2f(29.65f, 0.58f);
    glVertex2f(31.30f, -1.76f);
glEnd();

// Boom
glBegin(GL_QUADS);
    glColor3ub(206, 180, 140);
    glVertex2f(29.62f, -1.82f);
    glVertex2f(31.32f, -1.74f);
    glVertex2f(31.32f, -1.80f);
    glVertex2f(29.62f, -1.88f);
glEnd();

// Main sail (curved)
glBegin(GL_POLYGON);
    glColor3ub(138, 28, 28);
    glVertex2f(29.65f, 0.58f);
    glColor3ub(160, 38, 38);
    glVertex2f(29.88f, 0.06f);
    glColor3ub(168, 48, 48);
    glVertex2f(30.15f, -0.36f);
    glColor3ub(174, 56, 56);
    glVertex2f(30.42f, -0.70f);
    glColor3ub(162, 40, 40);
    glVertex2f(30.90f, -1.18f);
    glColor3ub(150, 32, 32);
    glVertex2f(31.32f, -1.76f);
    glColor3ub(150, 35, 35);
    glVertex2f(30.20f, -1.82f);
    glColor3ub(148, 34, 34);
    glVertex2f(29.62f, -1.86f);
glEnd();

glBegin(GL_POLYGON);
    glColor3ub(155, 36, 36);
    glVertex2f(29.62f, -1.86f);
    glColor3ub(168, 48, 48);
    glVertex2f(30.32f, -0.48f);
    glColor3ub(140, 28, 28);
    glVertex2f(31.32f, -1.76f);
glEnd();





  // MAIN FERRY SHIP

// Lower hull
glBegin(GL_POLYGON);
    glColor3ub(18, 34, 56);
    glVertex2f(2.6f, 0.40f);
    glVertex2f(8.0f, 0.75f);
    glVertex2f(14.6f, 1.05f);
    glVertex2f(20.8f, 1.30f);
    glVertex2f(23.9f, 1.45f);
    glVertex2f(25.1f, 1.80f);
    glVertex2f(26.0f, 1.40f);
    glVertex2f(25.4f, 0.95f);
    glVertex2f(22.6f, 0.92f);
    glVertex2f(17.0f, 0.78f);
    glVertex2f(10.3f, 0.50f);
    glVertex2f(4.2f, 0.32f);
glEnd();

// Red stripe
glBegin(GL_QUADS);
    glColor3ub(168, 25, 44);
    glVertex2f(3.8f, 0.48f);
    glVertex2f(24.9f, 1.30f);
    glVertex2f(24.9f, 1.44f);
    glVertex2f(2.6f, 0.52f);
glEnd();

// Waterline
glBegin(GL_QUADS);
    glColor3ub(25, 25, 25);
    glVertex2f(2.6f, 0.58f);
    glVertex2f(25.5f, 1.48f);
    glVertex2f(25.5f, 1.54f);
    glVertex2f(2.6f, 0.64f);
glEnd();

// Main hull (white)
glBegin(GL_POLYGON);
    glColor3ub(252, 252, 252);
    glVertex2f(3.0f, 0.62f);
    glVertex2f(9.0f, 0.90f);
    glVertex2f(15.5f, 1.18f);
    glVertex2f(21.2f, 1.38f);
    glVertex2f(24.0f, 1.55f);
    glVertex2f(25.4f, 2.20f);
    glVertex2f(25.1f, 2.85f);
    glVertex2f(22.8f, 2.85f);
    glVertex2f(18.9f, 2.74f);
    glVertex2f(14.0f, 2.62f);
    glVertex2f(9.0f, 2.51f);
    glVertex2f(5.0f, 2.40f);
    glVertex2f(3.2f, 2.26f);
    glVertex2f(2.9f, 1.98f);
glEnd();

// Window band + mullions
glBegin(GL_QUADS);
    glColor3ub(30, 46, 68);
    glVertex2f(3.6f, 2.24f);
    glVertex2f(24.0f, 2.34f);
    glColor3ub(52, 78, 108);
    glVertex2f(24.0f, 2.96f);
    glVertex2f(3.6f, 2.86f);
glEnd();

glLineWidth(2.0f);
glColor3ub(210, 220, 230);
glBegin(GL_LINES);
    glVertex2f(4.2f, 2.28f);
    glVertex2f(4.2f, 2.92f);
    glVertex2f(5.5f, 2.28f);
    glVertex2f(5.5f, 2.92f);
    glVertex2f(6.8f, 2.28f);
    glVertex2f(6.8f, 2.92f);
    glVertex2f(8.1f, 2.28f);
    glVertex2f(8.1f, 2.92f);
    glVertex2f(9.4f, 2.28f);
    glVertex2f(9.4f, 2.92f);
    glVertex2f(10.7f, 2.28f);
    glVertex2f(10.7f, 2.92f);
    glVertex2f(12.0f, 2.28f);
    glVertex2f(12.0f, 2.92f);
    glVertex2f(13.3f, 2.28f);
    glVertex2f(13.3f, 2.92f);
    glVertex2f(14.6f, 2.28f);
    glVertex2f(14.6f, 2.92f);
    glVertex2f(15.9f, 2.28f);
    glVertex2f(15.9f, 2.92f);
    glVertex2f(17.2f, 2.28f);
    glVertex2f(17.2f, 2.92f);
    glVertex2f(18.5f, 2.28f);
    glVertex2f(18.5f, 2.92f);
    glVertex2f(19.8f, 2.28f);
    glVertex2f(19.8f, 2.92f);
    glVertex2f(21.1f, 2.28f);
    glVertex2f(21.1f, 2.92f);
    glVertex2f(22.4f, 2.28f);
    glVertex2f(22.4f, 2.92f);
    glVertex2f(23.7f, 2.28f);
    glVertex2f(23.7f, 2.92f);
glEnd();

glLineWidth(1.0f);
glColor3ub(182, 202, 222);
glBegin(GL_LINES);
    glVertex2f(3.8f, 2.90f);
    glVertex2f(23.8f, 3.00f);
glEnd();

// Upper deck + bridge
glBegin(GL_POLYGON);
    glColor3ub(252, 252, 252);
    glVertex2f(4.2f, 2.92f);
    glVertex2f(18.8f, 3.00f);
    glVertex2f(20.0f, 4.08f);
    glVertex2f(16.9f, 4.08f);
    glVertex2f(14.5f, 3.88f);
    glVertex2f(11.1f, 3.72f);
    glVertex2f(7.0f, 3.54f);
    glVertex2f(4.2f, 3.34f);
glEnd();

glBegin(GL_POLYGON);
    glColor3ub(26, 38, 52);
    glVertex2f(15.2f, 3.58f);
    glVertex2f(19.0f, 3.86f);
    glVertex2f(19.2f, 3.20f);
    glVertex2f(16.0f, 3.20f);
    glVertex2f(15.2f, 3.54f);
glEnd();

// lines
glLineWidth(2.0f);
glColor3ub(210, 220, 230);
glBegin(GL_LINES);
    glVertex2f(16.15f, 3.14f);
    glVertex2f(16.15f, 3.72f);
    glVertex2f(17.15f, 3.14f);
    glVertex2f(17.15f, 3.78f);
    glVertex2f(18.10f, 3.14f);
    glVertex2f(18.10f, 3.70f);
glEnd();

glLineWidth(1.0f);
glColor3ub(185, 205, 225);
glBegin(GL_LINES);
    glVertex2f(15.3f, 3.56f);
    glVertex2f(19.0f, 3.68f);
glEnd();


// Funnel
glBegin(GL_QUADS);
    glColor3ub(40, 44, 52);
    glVertex2f(11.9f, 3.70f);
    glVertex2f(12.6f, 3.70f);
    glVertex2f(12.6f, 4.70f);
    glVertex2f(11.9f, 4.70f);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(210, 40, 40);
    glVertex2f(11.9f, 4.52f);
    glVertex2f(12.6f, 4.52f);
    glVertex2f(12.6f, 4.66f);
    glVertex2f(11.9f, 4.66f);
glEnd();

// Railings
glLineWidth(2.0f);
glColor3ub(70, 70, 70);
glBegin(GL_LINES);
    glVertex2f(4.3f, 3.47f);
    glVertex2f(19.1f, 3.57f);
glEnd();

glBegin(GL_LINES);
    glVertex2f(3.5f, 2.26f);
    glVertex2f(24.2f, 2.42f);
glEnd();

// Door
glBegin(GL_QUADS);
    glColor3ub(200, 150, 185);
    glVertex2f(5.05f, 2.18f);
    glVertex2f(5.55f, 2.18f);
    glVertex2f(5.55f, 2.96f);
    glVertex2f(5.05f, 2.96f);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(70, 90, 115);
    glVertex2f(5.13f, 2.26f);
    glVertex2f(5.47f, 2.26f);
    glVertex2f(5.47f, 2.88f);
    glVertex2f(5.13f, 2.88f);
glEnd();


// Fenders
glBegin(GL_QUADS);
    glColor3ub(30, 30, 30);
    glVertex2f(4.00f, 1.22f);
    glVertex2f(4.42f, 1.22f);
    glVertex2f(4.42f, 1.54f);
    glVertex2f(4.10f, 1.54f);
    glVertex2f(6.30f, 1.22f);
    glVertex2f(6.62f, 1.22f);
    glVertex2f(6.62f, 1.54f);
    glVertex2f(6.30f, 1.54f);
    glVertex2f(8.50f, 1.22f);
    glVertex2f(8.82f, 1.22f);
    glVertex2f(8.82f, 1.54f);
    glVertex2f(8.50f, 1.54f);
    glVertex2f(10.70f, 1.22f);
    glVertex2f(11.02f, 1.22f);
    glVertex2f(11.02f, 1.54f);
    glVertex2f(10.70f, 1.54f);
    glVertex2f(12.90f, 1.22f);
    glVertex2f(13.22f, 1.22f);
    glVertex2f(13.22f, 1.54f);
    glVertex2f(12.90f, 1.54f);
    glVertex2f(15.10f, 1.22f);
    glVertex2f(15.42f, 1.22f);
    glVertex2f(15.42f, 1.54f);
    glVertex2f(15.10f, 1.54f);
    glVertex2f(17.30f, 1.42f);
    glVertex2f(17.62f, 1.42f);
    glVertex2f(17.62f, 1.74f);
    glVertex2f(17.30f, 1.74f);
glEnd();


glBegin(GL_QUADS);
    glColor3ub(235, 235, 235);
    glVertex2f(4.17f, 1.29f);
    glVertex2f(4.35f, 1.29f);
    glVertex2f(4.35f, 1.47f);
    glVertex2f(4.17f, 1.47f);
    glVertex2f(6.37f, 1.29f);
    glVertex2f(6.55f, 1.29f);
    glVertex2f(6.55f, 1.47f);
    glVertex2f(6.37f, 1.47f);
    glVertex2f(8.57f, 1.29f);
    glVertex2f(8.75f, 1.29f);
    glVertex2f(8.75f, 1.47f);
    glVertex2f(8.57f, 1.47f);
    glVertex2f(10.77f, 1.29f);
    glVertex2f(10.95f, 1.29f);
    glVertex2f(10.95f, 1.47f);
    glVertex2f(10.77f, 1.47f);
    glVertex2f(12.97f, 1.29f);
    glVertex2f(13.15f, 1.29f);
    glVertex2f(13.15f, 1.47f);
    glVertex2f(12.97f, 1.47f);
    glVertex2f(15.17f, 1.29f);
    glVertex2f(15.35f, 1.29f);
    glVertex2f(15.35f, 1.47f);
    glVertex2f(15.17f, 1.47f);
    glVertex2f(17.37f, 1.69f);
    glVertex2f(17.55f, 1.69f);
    glVertex2f(17.55f, 1.87f);
    glVertex2f(17.37f, 1.87f);

glEnd();



//birds Near the Mast

glLineWidth(2.0f);
glColor3ub(35, 40, 45);

// First bird near the mast
glBegin(GL_LINE_STRIP);
    glVertex2f(11.0f, 7.20f);
    glVertex2f(11.5f, 7.50f);
    glVertex2f(12.0f, 7.65f);
glEnd();

glBegin(GL_LINE_STRIP);
    glVertex2f(12.0f, 7.65f);
    glVertex2f(12.5f, 7.50f);
    glVertex2f(13.0f, 7.20f);
glEnd();

glBegin(GL_TRIANGLES);
    glVertex2f(11.95f, 7.55f);
    glVertex2f(12.05f, 7.55f);
    glVertex2f(12.00f, 7.40f);
glEnd();


// Birds Near the ship

glBegin(GL_LINE_STRIP);
    glVertex2f(21.7f, 7.00f);
    glVertex2f(22.3f, 7.35f);
    glVertex2f(22.8f, 7.50f);
glEnd();

glBegin(GL_LINE_STRIP);
    glVertex2f(22.8f, 7.50f);
    glVertex2f(23.3f, 7.35f);
    glVertex2f(23.9f, 7.00f);
glEnd();

glBegin(GL_TRIANGLES);
    glVertex2f(22.72f, 7.42f);
    glVertex2f(22.88f, 7.42f);
    glVertex2f(22.80f, 7.28f);
glEnd();


// Mid-Air Small Birds

glLineWidth(1.5f);
glColor3ub(60, 75, 90);

// First small bird
glBegin(GL_LINE_STRIP);
    glVertex2f(15.7f, 8.05f);
    glVertex2f(16.2f, 8.30f);
    glVertex2f(16.6f, 8.40f);
glEnd();

glBegin(GL_LINE_STRIP);
    glVertex2f(16.6f, 8.40f);
    glVertex2f(17.0f, 8.30f);
    glVertex2f(17.5f, 8.05f);
glEnd();

// Second small bird
glBegin(GL_LINES);
    glColor3ub(100, 120, 140);
    glVertex2f(18.8f, 8.55f);
    glVertex2f(19.1f, 8.70f);
glEnd();

glBegin(GL_LINES);
    glVertex2f(19.1f, 8.70f);
    glVertex2f(19.4f, 8.55f);
glEnd();

// Third small bird
glBegin(GL_LINES);
    glColor3ub(120, 140, 160);
    glVertex2f(21.0f, 8.90f);
    glVertex2f(21.3f, 9.00f);
glEnd();

glBegin(GL_LINES);
    glVertex2f(21.3f, 9.00f);
    glVertex2f(21.6f, 8.90f);
glEnd();



// boat-1 (moving ledt to Right)
glPushMatrix();
glTranslatef(_moveA, 0.0f, 0.0f);

glBegin(GL_QUADS);
glColor3ub(139,69,19);
glVertex2f( 1.0f, -14.0f);
glVertex2f( 1.5f, -13.0f);
glVertex2f(-2.0f, -13.0f);
glVertex2f(-3.0f, -14.0f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f( 2.0f, -14.5f);
glVertex2f( 2.0f, -14.0f);
glVertex2f(-3.0f, -14.0f);
glVertex2f(-3.0f, -14.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,0,0);
glVertex2f(-3.0f, -14.5f);
glVertex2f(-3.0f, -14.0f);
glVertex2f(-4.5f, -13.7f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,0,0);
glVertex2f( 2.0f, -14.5f);
glVertex2f( 3.5f, -13.7f);
glVertex2f( 2.0f, -14.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,0,0);
glVertex2f( 2.0f, -14.0f);
glVertex2f( 1.5f, -13.0f);
glVertex2f( 1.0f, -14.0f);
glEnd();

glPopMatrix();



    glutSwapBuffers();
}









/////////////////////////////SCENE 4 Beach DAY/////////////////////////////////

void drawScene4() {

 glClear(GL_COLOR_BUFFER_BIT);

//sky
glBegin(GL_QUADS);
glColor3ub(135, 206, 235); // blue color
glVertex2f(-12.0f, 14.0f);
glVertex2f(38.0f, 14.0f);   // topright of the sky
glVertex2f(38.0f, 3.0f);    // bottom right of the sky
glVertex2f(-12.0f, 3.0f);   // bottomleft of the sky
glEnd();

//SUN
glPushMatrix();
glColor3ub(250, 140, 0);  // dark Orange
glTranslatef(5.0, 10.0, 0);
glutSolidSphere(1.0, 64, 64);
glPopMatrix();

 // cloud 1
    glPushMatrix();
    glTranslatef(_moveC,0.0f,0.0f);

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(1.0, 6.0, 0);
    glutSolidSphere(0.7, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(1.0, 7.0, 0);
    glutSolidSphere(0.7, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(2.0, 7.0, 0);
    glutSolidSphere(0.7, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(2.0, 6.0, 0);
    glutSolidSphere(0.7, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(0.0, 6.5, 0);
    glutSolidSphere(0.7, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(3.0, 6.5, 0);
    glutSolidSphere(0.7, 32, 32);
    glPopMatrix();

    glPopMatrix();

    // cloud 2
    glPushMatrix();
    glTranslatef(_moveC,0.0f,0.0f);

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(15.0, 9.0, 0);
    glutSolidSphere(0.8, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,255,255);
    glTranslatef(15.0, 8.0, 0);
    glutSolidSphere(0.8, 32, 32);
    glPopMatrix();

    glPushMatrix();
     glColor3ub(255,255,255);
     glTranslatef(16.0, 8.0, 0);
     glutSolidSphere(0.8, 32, 32);
     glPopMatrix();

    glPushMatrix();
     glColor3ub(255,255,255);
     glTranslatef(16.0, 9.0, 0);
     glutSolidSphere(0.8, 32, 32);
     glPopMatrix();

    glPushMatrix();
     glColor3ub(255,255,255);
     glTranslatef(14.0, 8.5, 0);
     glutSolidSphere(0.8, 32, 32);
     glPopMatrix();

    glPushMatrix();
     glColor3ub(255,255,255);
     glTranslatef(17.0, 8.5, 0);
     glutSolidSphere(0.8, 32, 32);
     glPopMatrix();

    glPopMatrix();

    // cloud 3
   glPushMatrix();
   glTranslatef(_moveC, 0.0f, 0.0f);

   glPushMatrix();
   glColor3ub(255, 255, 255);
   glTranslatef(22.0f, 8.0f, 0.0f);
  glutSolidSphere(0.75, 32, 32);
   glPopMatrix();

glPushMatrix();
glColor3ub(255, 255, 255);
glTranslatef(22.0f, 7.0f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(255, 255, 255);
glTranslatef(23.0f, 8.0f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(255, 255, 255);
glTranslatef(23.0f, 7.0f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(255, 255, 255);
glTranslatef(24.0f, 7.5f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(255, 255, 255);
glTranslatef(21.0f, 7.5f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPopMatrix();


// SEA
glBegin(GL_QUADS);
glColor3ub(70,110,245);
glVertex2f(-12.0f,-19.0f);
glVertex2f(38.0f,-19.0f);
glVertex2f(38.0f,3.0f);
glVertex2f(-12.0f,3.0f);
glEnd();

//Thin wave band
glBegin(GL_QUADS);
glColor3ub(90,130,255);
glVertex2f(-12.0f,-2.20f);
glVertex2f(38.0f,-2.20f);
glVertex2f(38.0f,-2.00f);
glVertex2f(-12.0f,-2.00f);
glEnd();

// THIN WAVE BAND
glBegin(GL_QUADS);
glColor3ub(90,130,255);
glVertex2f(-12.0f,0.25f);
glVertex2f(38.0f,0.25f);
glVertex2f(38.0f,0.35f);
glVertex2f(-12.0f,0.35f);
glEnd();


// BEACH

glBegin(GL_POLYGON);
glColor3ub(250,225,180);
  glVertex2f(-12.0f,-21.0f);
  glVertex2f(38.0f,-21.0f);
  glVertex2f(38.0f,-4.60f);
  glVertex2f(36.0f,-4.30f);
  glVertex2f(33.0f,-4.50f);
  glVertex2f(30.0f,-4.10f);
  glVertex2f(27.0f,-4.40f);
  glVertex2f(24.0f,-4.05f);
  glVertex2f(20.0f,-4.40f);
  glVertex2f(16.0f,-4.10f);
  glVertex2f(12.0f,-4.40f);
  glVertex2f( 8.0f,-4.05f);
  glVertex2f( 4.0f,-4.30f);
  glVertex2f( 0.0f,-3.95f);
  glVertex2f(-4.0f,-4.30f);
  glVertex2f(-8.0f,-4.05f);
  glVertex2f(-10.0f,-4.30f);
  glVertex2f(-12.0f,-4.00f);
glEnd();

//MOUNTAINS

glBegin(GL_TRIANGLES);
glColor3ub(0,90,0);
glVertex2f(11.0f,3.0f);
glVertex2f(16.5f,8.0f);
glVertex2f(22.0f,3.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,110,0);
glVertex2f(14.0f,3.0f);
glVertex2f(18.0f,6.5f);
glVertex2f(21.0f,3.0f);
glEnd();

// MOUNTAIN 2

glBegin(GL_TRIANGLES);
glColor3ub(0, 90, 0);
glVertex2f(20.0f, 3.0f);
glVertex2f(30.0f, 8.0f);
glVertex2f(40.0f, 3.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0, 110, 0);
glVertex2f(24.0f, 4.0f);
glVertex2f(32.0f, 7.0f);
glVertex2f(38.0f, 4.0f);
glEnd();




// ISLAND HOUSE

glBegin(GL_POLYGON);
glColor3ub(0,140,0);
glVertex2f(18.0f,3.0f);
glVertex2f(19.5f,3.6f);
glVertex2f(21.0f,3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(40,40,90);
glVertex2f(19.0f,3.0f);
glVertex2f(19.0f,3.7f);
glVertex2f(19.8f,3.7f);
glVertex2f(19.8f,3.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(25,25,60);
glVertex2f(18.95f,3.7f);
glVertex2f(19.85f,3.7f);
glVertex2f(19.4f,4.15f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(160,32,240);
glVertex2f(19.10f,3.25f);
glVertex2f(19.25f,3.25f);
glVertex2f(19.25f,3.45f);
glVertex2f(19.10f,3.45f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0,200,120);
glVertex2f(19.55f,3.25f);
glVertex2f(19.70f,3.25f);
glVertex2f(19.70f,3.45f);
glVertex2f(19.55f,3.45f);
glEnd();



// SHIP
glPushMatrix();
glTranslatef(_moveShip, 0.0f, 0.0f);


glBegin(GL_POLYGON);
glColor3ub(15,20,60);
glVertex2f(21.0f, 2.5f);
glVertex2f(27.0f, 2.5f);
glVertex2f(25.8f, 1.5f);
glVertex2f(22.2f, 1.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(235,235,235);
glVertex2f(22.0f, 2.5f);
glVertex2f(27.0f, 2.5f);
glVertex2f(26.2f, 3.1f);
glVertex2f(22.8f, 3.1f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(250,210,0);
glVertex2f(23.3f, 3.1f);
glVertex2f(23.6f, 3.1f);
glVertex2f(23.6f, 3.4f);
glVertex2f(23.3f, 3.4f);
glVertex2f(24.0f, 3.1f);
glVertex2f(24.3f, 3.1f);
glVertex2f(24.3f, 3.4f);
glVertex2f(24.0f, 3.4f);
glVertex2f(24.8f, 3.1f);
glVertex2f(25.1f, 3.1f);
glVertex2f(25.1f, 3.4f);
glVertex2f(24.8f, 3.4f);
glEnd();

glPopMatrix();



//LIFEGUARD TOWER

// Legs
glBegin(GL_QUADS);
glColor3ub(139,69,19); // Brown color
glVertex2f(30.0f, -8.0f);
glVertex2f(30.8f, -8.0f);
glVertex2f(30.8f, -5.0f);
glVertex2f(30.0f, -5.0f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(139,69,19); // Right leg
glVertex2f(32.0f, -8.0f);
glVertex2f(32.8f, -8.0f);
glVertex2f(32.8f, -5.0f);
glVertex2f(32.0f, -5.0f);
glEnd();

// Platform
glBegin(GL_QUADS);
glColor3ub(139,69,19);
glVertex2f(30.0f, -5.0f);
glVertex2f(32.8f, -5.0f);
glVertex2f(32.8f, -2.0f);
glVertex2f(30.0f, -2.0f);
glEnd();

// Roof
glBegin(GL_TRIANGLES);
glColor3ub(35,35,40);
glVertex2f(29.5f, -2.0f);
glVertex2f(33.3f, -2.0f);
glVertex2f(31.4f, 3.0f);
glEnd();

// Rungs
glBegin(GL_QUADS);
glColor3ub(139,69,19);
glVertex2f(30.8f, -6.7f);
glVertex2f(32.0f, -6.7f);
glVertex2f(32.0f, -6.5f);
 glVertex2f(30.8f, -6.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(139,69,19); // Second rung
glVertex2f(30.8f, -5.7f);
 glVertex2f(32.0f, -5.7f);
glVertex2f(32.0f, -5.5f);
glVertex2f(30.8f, -5.5f);
glEnd();



//pine tree
   // PINE TREE 1
glBegin(GL_QUADS);
glColor3ub(120,70,30);
glVertex2f(36.8f,-10.0f);
glVertex2f(37.3f,-10.0f);
glVertex2f(37.3f,-7.0f);
glVertex2f(36.8f,-7.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,170,80);
glVertex2f(36.0f,-6.0f);
glVertex2f(38.1f,-6.0f);
glVertex2f(37.05f,-3.8f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,190,90);
glVertex2f(36.2f,-4.5f);
glVertex2f(37.9f,-4.5f);
glVertex2f(37.05f,-2.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,210,100);
glVertex2f(36.4f,-3.2f);
glVertex2f(37.7f,-3.2f);
glVertex2f(37.05f,-1.7f);
glEnd();


//PINE TREE 2
glBegin(GL_QUADS);
glColor3ub(120,70,30);
glVertex2f(33.8f,-9.0f);
glVertex2f(34.3f,-9.0f);
glVertex2f(34.3f,-6.0f);
glVertex2f(33.8f,-6.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,170,80);
glVertex2f(33.0f,-6.0f);
glVertex2f(35.1f,-6.0f);
glVertex2f(34.05f,-3.8f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,190,90);
glVertex2f(33.2f,-4.5f);
glVertex2f(34.9f,-4.5f);
glVertex2f(34.05f,-2.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,210,100);
glVertex2f(33.4f,-3.2f);
glVertex2f(34.7f,-3.2f);
glVertex2f(34.05f,-1.7f);
glEnd();


//PINE TREE 3
glBegin(GL_QUADS);
glColor3ub(120,70,30);
glVertex2f(36.8f,-12.0f);
glVertex2f(37.3f,-12.0f);
glVertex2f(37.3f,-9.0f);
glVertex2f(36.8f,-9.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,170,80);
glVertex2f(36.0f,-9.0f);
glVertex2f(38.1f,-9.0f);
glVertex2f(37.05f,-6.8f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,190,90);
glVertex2f(36.2f,-7.5f);
glVertex2f(37.9f,-7.5f);
glVertex2f(37.05f,-5.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,210,100);
glVertex2f(36.4f,-6.2f);
glVertex2f(37.7f,-6.2f);
glVertex2f(37.05f,-4.7f);
glEnd();


//PINE TREE 4 (middle, right side of Pine Tree 3
glBegin(GL_QUADS);
glColor3ub(120,70,30);
glVertex2f(34.8f,-12.0f);
glVertex2f(35.3f,-12.0f);
glVertex2f(35.3f,-9.0f);
glVertex2f(34.8f,-9.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,170,80);
glVertex2f(34.0f,-9.0f);
glVertex2f(36.1f,-9.0f);
glVertex2f(35.05f,-6.8f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,190,90);
glVertex2f(34.2f,-7.5f);
glVertex2f(35.9f,-7.5f);
glVertex2f(35.05f,-5.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,210,100);
glVertex2f(34.4f,-6.2f);
glVertex2f(35.7f,-6.2f);
glVertex2f(35.05f,-4.7f);
glEnd();


//PINE TREE 5 (down)
glBegin(GL_QUADS);
glColor3ub(120,70,30);
glVertex2f(33.8f,-16.0f);
glVertex2f(34.3f,-16.0f);
glVertex2f(34.3f,-13.0f);
glVertex2f(33.8f,-13.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,170,80);
glVertex2f(33.0f,-13.0f);
glVertex2f(35.1f,-13.0f);
glVertex2f(34.05f,-10.8f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,190,90);
glVertex2f(33.2f,-11.5f);
glVertex2f(34.9f,-11.5f);
glVertex2f(34.05f,-9.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,210,100);
glVertex2f(33.4f,-10.2f);
glVertex2f(34.7f,-10.2f);
glVertex2f(34.05f,-8.7f);
glEnd();


//PINE TREE 6 (down)
glBegin(GL_QUADS);
glColor3ub(120,70,30);
glVertex2f(36.8f,-16.0f);
glVertex2f(37.3f,-16.0f);
glVertex2f(37.3f,-13.0f);
glVertex2f(36.8f,-13.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,170,80);
glVertex2f(36.0f,-13.0f);
glVertex2f(38.1f,-13.0f);
glVertex2f(37.05f,-10.8f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,190,90);
glVertex2f(36.2f,-11.5f);
glVertex2f(37.9f,-11.5f);
glVertex2f(37.05f,-9.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,210,100);
glVertex2f(36.4f,-10.2f);
glVertex2f(37.7f,-10.2f);
glVertex2f(37.05f,-8.7f);
glEnd();


//  PINE TREE 7(further down)
// Trunk of the pine tree
glBegin(GL_QUADS);
glColor3ub(120,70,30);
glVertex2f(36.8f,-18.0f);
glVertex2f(37.3f,-18.0f);
glVertex2f(37.3f,-15.0f);
glVertex2f(36.8f,-15.0f);
glEnd();

// First layer of pine tree
glBegin(GL_TRIANGLES);
glColor3ub(0,170,80);
glVertex2f(36.0f,-15.0f);
glVertex2f(38.1f,-15.0f);
glVertex2f(37.05f,-12.8f);
glEnd();

// Second laye
glBegin(GL_TRIANGLES);
glColor3ub(0,190,90);
glVertex2f(36.2f,-13.5f);
glVertex2f(37.9f,-13.5f);
glVertex2f(37.05f,-11.5f);
glEnd();

// Third layer
glBegin(GL_TRIANGLES);
glColor3ub(0,210,100);
glVertex2f(36.4f,-12.2f);
glVertex2f(37.7f,-12.2f);
glVertex2f(37.05f,-10.7f);
glEnd();



  //  UMBRELLA (RED) + TWO SEATS
// Pole
glBegin(GL_QUADS);
glColor3ub(205,170,120);
glVertex2f(3.40f,-8.50f);
glVertex2f(3.60f,-8.50f);
glVertex2f(3.60f,-4.00f);
glVertex2f(3.40f,-4.00f);
glEnd();

// Canopy (red)
glBegin(GL_POLYGON);
glColor3ub(220,40,40);
glVertex2f(0.90f,-4.00f);
glVertex2f(1.06f,-3.11f);
glVertex2f(1.51f,-2.33f);
glVertex2f(2.20f,-1.75f);
glVertex2f(3.05f,-1.44f);
glVertex2f(3.95f,-1.44f);
glVertex2f(4.80f,-1.75f);
glVertex2f(5.49f,-2.33f);
glVertex2f(5.94f,-3.11f);
glVertex2f(6.10f,-4.00f);
glEnd();

// Rim (darker red)
glBegin(GL_QUADS);
glColor3ub(160,20,20);
glVertex2f(0.90f,-4.00f);
glVertex2f(6.10f,-4.00f);
glVertex2f(6.10f,-4.10f);
glVertex2f(0.90f,-4.10f);
glEnd();

// Hub
glBegin(GL_QUADS);
glColor3ub(230,200,150);
glVertex2f(3.34f,-4.06f);
glVertex2f(3.66f,-4.06f);
glVertex2f(3.58f,-3.80f);
glVertex2f(3.42f,-3.80f);
glEnd();

// Left chair
glBegin(GL_QUADS);
glColor3ub(190,150,100); // seat
glVertex2f(2.00f,-7.90f);
glVertex2f(3.20f,-7.90f);
glVertex2f(3.20f,-8.35f);
glVertex2f(2.00f,-8.35f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(190,150,100); // back
glVertex2f(3.20f,-7.90f);
glVertex2f(2.85f,-6.90f);
glVertex2f(1.65f,-6.90f);
glVertex2f(2.00f,-7.90f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(150,120,80);  // legs
glVertex2f(2.15f,-9.10f);
glVertex2f(2.30f,-9.10f);
glVertex2f(2.30f,-8.35f);
glVertex2f(2.15f,-8.35f);

glVertex2f(2.90f,-9.10f);
glVertex2f(3.05f,-9.10f);
glVertex2f(3.05f,-8.35f);
glVertex2f(2.90f,-8.35f);
glEnd();

// Right chair
glBegin(GL_QUADS);
glColor3ub(190,150,100); // seat
glVertex2f(3.80f,-7.90f);
glVertex2f(5.00f,-7.90f);
glVertex2f(5.00f,-8.35f);
glVertex2f(3.80f,-8.35f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(190,150,100); // back
glVertex2f(3.80f,-7.90f);
glVertex2f(4.10f,-6.90f);
glVertex2f(5.30f,-6.90f);
glVertex2f(5.00f,-7.90f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(150,120,80);  // legs
glVertex2f(3.95f,-9.10f);
glVertex2f(4.10f,-9.10f);
glVertex2f(4.10f,-8.35f);
glVertex2f(3.95f,-8.35f);

glVertex2f(4.85f,-9.10f);
glVertex2f(5.00f,-9.10f);
glVertex2f(5.00f,-8.35f);
glVertex2f(4.85f,-8.35f);
glEnd();

// BLUE UMBRELLA + TWO CHAIRS (LEFT)

// Pole
glBegin(GL_QUADS);
glColor3ub(205,170,120);
glVertex2f(-6.60f,-8.50f);
glVertex2f(-6.40f,-8.50f);
glVertex2f(-6.40f,-4.00f);
glVertex2f(-6.60f,-4.00f);
glEnd();

// Canopy (blue)
glBegin(GL_POLYGON);
glColor3ub(30,144,255);
glVertex2f(-9.10f,-4.00f);
glVertex2f(-8.94f,-3.11f);
glVertex2f(-8.49f,-2.33f);
glVertex2f(-7.80f,-1.75f);
glVertex2f(-6.95f,-1.44f);
glVertex2f(-6.05f,-1.44f);
glVertex2f(-5.20f,-1.75f);
glVertex2f(-4.51f,-2.33f);
glVertex2f(-4.06f,-3.11f);
glVertex2f(-3.90f,-4.00f);
glEnd();

// Rim (darker blue)
glBegin(GL_QUADS);
glColor3ub(20,80,160);
glVertex2f(-9.10f,-4.00f);
glVertex2f(-3.90f,-4.00f);
glVertex2f(-3.90f,-4.10f);
glVertex2f(-9.10f,-4.10f);
glEnd();

// Hub
glBegin(GL_QUADS);
glColor3ub(230,200,150);
glVertex2f(-6.66f,-4.06f);
glVertex2f(-6.34f,-4.06f);
glVertex2f(-6.42f,-3.80f);
glVertex2f(-6.58f,-3.80f);
glEnd();

// Left chair
glBegin(GL_QUADS);
glColor3ub(190,150,100); // seat
glVertex2f(-8.00f,-7.90f);
glVertex2f(-6.80f,-7.90f);
glVertex2f(-6.80f,-8.35f);
glVertex2f(-8.00f,-8.35f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(190,150,100); // back
glVertex2f(-6.80f,-7.90f);
glVertex2f(-7.15f,-6.90f);
glVertex2f(-8.35f,-6.90f);
glVertex2f(-8.00f,-7.90f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(150,120,80);  // legs
glVertex2f(-7.85f,-9.10f);
glVertex2f(-7.70f,-9.10f);
glVertex2f(-7.70f,-8.35f);
glVertex2f(-7.85f,-8.35f);

glVertex2f(-7.10f,-9.10f);
glVertex2f(-6.95f,-9.10f);
glVertex2f(-6.95f,-8.35f);
glVertex2f(-7.10f,-8.35f);
glEnd();

// Right chair
glBegin(GL_QUADS);
glColor3ub(190,150,100); // seat
glVertex2f(-6.20f,-7.90f);
glVertex2f(-5.00f,-7.90f);
glVertex2f(-5.00f,-8.35f);
glVertex2f(-6.20f,-8.35f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(190,150,100); // back
glVertex2f(-6.20f,-7.90f);
glVertex2f(-5.90f,-6.90f);
glVertex2f(-4.70f,-6.90f);
glVertex2f(-5.00f,-7.90f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(150,120,80);  // legs
glVertex2f(-6.05f,-9.10f);
glVertex2f(-5.90f,-9.10f);
glVertex2f(-5.90f,-8.35f);
glVertex2f(-6.05f,-8.35f);

glVertex2f(-5.15f,-9.10f);
glVertex2f(-5.00f,-9.10f);
glVertex2f(-5.00f,-8.35f);
glVertex2f(-5.15f,-8.35f);
glEnd();


// BLACK UMBRELLA + TWO CHAIRS RIGHT

// Pole
glBegin(GL_QUADS);
glColor3ub(205,170,120);
glVertex2f(15.40f,-8.50f);
glVertex2f(15.60f,-8.50f);
glVertex2f(15.60f,-4.00f);
glVertex2f(15.40f,-4.00f);
glEnd();

// Canopy (black)
glBegin(GL_POLYGON);
glColor3ub(25,25,25);
glVertex2f(12.90f,-4.00f);
glVertex2f(13.06f,-3.11f);
glVertex2f(13.51f,-2.33f);
glVertex2f(14.20f,-1.75f);
glVertex2f(15.05f,-1.44f);
glVertex2f(15.95f,-1.44f);
glVertex2f(16.80f,-1.75f);
glVertex2f(17.49f,-2.33f);
glVertex2f(17.94f,-3.11f);
glVertex2f(18.10f,-4.00f);
glEnd();

// Rim (darker)
glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f(12.90f,-4.00f);
glVertex2f(18.10f,-4.00f);
glVertex2f(18.10f,-4.10f);
glVertex2f(12.90f,-4.10f);
glEnd();

// Hub
glBegin(GL_QUADS);
glColor3ub(230,200,150);
glVertex2f(15.34f,-4.06f);
glVertex2f(15.66f,-4.06f);
glVertex2f(15.58f,-3.80f);
glVertex2f(15.42f,-3.80f);
glEnd();

// Left chair
glBegin(GL_QUADS);
glColor3ub(190,150,100); // seat
glVertex2f(14.00f,-7.90f);
glVertex2f(15.20f,-7.90f);
glVertex2f(15.20f,-8.35f);
glVertex2f(14.00f,-8.35f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(190,150,100); // back
glVertex2f(15.20f,-7.90f);
glVertex2f(14.85f,-6.90f);
glVertex2f(13.65f,-6.90f);
glVertex2f(14.00f,-7.90f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(150,120,80);  // legs
glVertex2f(14.15f,-9.10f);
glVertex2f(14.30f,-9.10f);
glVertex2f(14.30f,-8.35f);
glVertex2f(14.15f,-8.35f);

glVertex2f(14.90f,-9.10f);
glVertex2f(15.05f,-9.10f);
glVertex2f(15.05f,-8.35f);
glVertex2f(14.90f,-8.35f);
glEnd();

// Right chair
glBegin(GL_QUADS);
glColor3ub(190,150,100); // seat
glVertex2f(15.80f,-7.90f);
glVertex2f(17.00f,-7.90f);
glVertex2f(17.00f,-8.35f);
glVertex2f(15.80f,-8.35f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(190,150,100); // back
glVertex2f(15.80f,-7.90f);
glVertex2f(16.10f,-6.90f);
glVertex2f(17.30f,-6.90f);
glVertex2f(17.00f,-7.90f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(150,120,80);  // legs
glVertex2f(15.95f,-9.10f);
glVertex2f(16.10f,-9.10f);
glVertex2f(16.10f,-8.35f);
glVertex2f(15.95f,-8.35f);

glVertex2f(16.85f,-9.10f);
glVertex2f(17.00f,-9.10f);
glVertex2f(17.00f,-8.35f);
glVertex2f(16.85f,-8.35f);
glEnd();


    glutSwapBuffers();
}






 ///////////////////////////////SCENE 5 Beach day (Night) ////////////////////////////////////////////

void drawScene5(){

 glClear(GL_COLOR_BUFFER_BIT);

//sky
glBegin(GL_QUADS);
glColor3ub(0,0,0);  // black blue color
glVertex2f(-12.0f, 14.0f);  // Top-left of the sky
glVertex2f(38.0f, 14.0f);   // Top-right of the sky
glVertex2f(38.0f, 3.0f);    // Bottom-right of the sky
glVertex2f(-12.0f, 3.0f);   // Bottom-left  of the sky
glEnd();

// stars
glBegin(GL_POINTS);
glColor3ub(255,255,255);
glBegin(GL_POINTS);
glVertex2f( 1.0f,  4.0f);
glVertex2f( 2.0f,  7.5f);
glVertex2f( 4.0f,  5.0f);
glVertex2f(-2.0f,  8.0f);
glVertex2f(30.0f,  5.0f);
glVertex2f(-1.0f,  9.0f);
glVertex2f(35.0f,  7.0f);
glVertex2f(-3.0f,  7.0f);
glVertex2f(-7.0f,  5.0f);
glVertex2f(10.0f,  7.5f);
glVertex2f(12.0f,  8.5f);
glVertex2f(-11.0f, 6.0f);
glVertex2f(37.0f,  7.5f);
glVertex2f(-10.0f, 4.5f);
glVertex2f(13.0f,  7.0f);
glVertex2f(14.0f,  7.5f);
glVertex2f(18.0f, 10.0f);
glEnd();


    // moon
glPushMatrix();
glColor3ub(217,217,217);
glTranslatef(-8.0, 10.0, 0);
glutSolidSphere(1, 48, 48);
glPopMatrix();

glPushMatrix();
glColor3ub(0,0,0);
glTranslatef(-8.0, 10.25, 0);
glutSolidSphere(1, 48, 48);
glPopMatrix();



// clouds (gray)

// Cloud 1
glPushMatrix();
glTranslatef(_moveC, 0.0f, 0.0f);

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(1.0f, 6.0f, 0.0f);
glutSolidSphere(0.7, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(1.0f, 7.0f, 0.0f);
glutSolidSphere(0.7, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(2.0f, 7.0f, 0.0f);
glutSolidSphere(0.7, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(2.0f, 6.0f, 0.0f);
glutSolidSphere(0.7, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(0.0f, 6.5f, 0.0f);
glutSolidSphere(0.7, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(3.0f, 6.5f, 0.0f);
glutSolidSphere(0.7, 32, 32);
glPopMatrix();

glPopMatrix();


// Cloud 2
glPushMatrix();
glTranslatef(_moveC, 0.0f, 0.0f);

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(15.0f, 9.0f, 0.0f);
glutSolidSphere(0.8, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(15.0f, 8.0f, 0.0f);
glutSolidSphere(0.8, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(16.0f, 8.0f, 0.0f);
glutSolidSphere(0.8, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(16.0f, 9.0f, 0.0f);
glutSolidSphere(0.8, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(14.0f, 8.5f, 0.0f);
glutSolidSphere(0.8, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(17.0f, 8.5f, 0.0f);
glutSolidSphere(0.8, 32, 32);
glPopMatrix();

glPopMatrix();


// Cloud 3
glPushMatrix();
glTranslatef(_moveC, 0.0f, 0.0f);

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(22.0f, 8.0f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(22.0f, 7.0f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(23.0f, 8.0f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(23.0f, 7.0f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(24.0f, 7.5f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPushMatrix();
glColor3ub(105,105,105);
glTranslatef(21.0f, 7.5f, 0.0f);
glutSolidSphere(0.75, 32, 32);
glPopMatrix();

glPopMatrix();


//SEA
glBegin(GL_QUADS);
glColor3ub(25, 25, 112);  // Midnight Blue
glVertex2f(-12.0f,-19.0f);
glVertex2f(38.0f,-19.0f);
glVertex2f(38.0f,3.0f);
glVertex2f(-12.0f,3.0f);
glEnd();

// Thin wave band
glBegin(GL_QUADS);
glColor3ub(90,130,255);
glVertex2f(-12.0f,-2.20f);
glVertex2f(38.0f,-2.20f);
glVertex2f(38.0f,-2.00f);
glVertex2f(-12.0f,-2.00f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(90,130,255);
glVertex2f(-12.0f,0.25f);
glVertex2f(38.0f,0.25f);
glVertex2f(38.0f,0.35f);
glVertex2f(-12.0f,0.35f);
glEnd();


// BEACH

glBegin(GL_POLYGON);
glColor3ub(250,225,180);
  glVertex2f(-12.0f,-21.0f);
  glVertex2f(38.0f,-21.0f);
  glVertex2f(38.0f,-4.60f);
  glVertex2f(36.0f,-4.30f);
  glVertex2f(33.0f,-4.50f);
  glVertex2f(30.0f,-4.10f);
  glVertex2f(27.0f,-4.40f);
  glVertex2f(24.0f,-4.05f);
  glVertex2f(20.0f,-4.40f);
  glVertex2f(16.0f,-4.10f);
  glVertex2f(12.0f,-4.40f);
  glVertex2f( 8.0f,-4.05f);
  glVertex2f( 4.0f,-4.30f);
  glVertex2f( 0.0f,-3.95f);
  glVertex2f(-4.0f,-4.30f);
  glVertex2f(-8.0f,-4.05f);
  glVertex2f(-10.0f,-4.30f);
  glVertex2f(-12.0f,-4.00f);
glEnd();


//MOUNTAINS
//Mountain 1
glBegin(GL_TRIANGLES);
glColor3ub(0,90,0);
glVertex2f(11.0f,3.0f);
glVertex2f(16.5f,8.0f);
glVertex2f(22.0f,3.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,110,0);
glVertex2f(14.0f,3.0f);
glVertex2f(18.0f,6.5f);
glVertex2f(21.0f,3.0f);
glEnd();

// MOUNTAIN 2

glBegin(GL_TRIANGLES);
glColor3ub(0, 90, 0);
glVertex2f(20.0f, 3.0f);
glVertex2f(30.0f, 8.0f);
glVertex2f(40.0f, 3.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0, 110, 0);
glVertex2f(24.0f, 4.0f);
glVertex2f(32.0f, 7.0f);
glVertex2f(38.0f, 4.0f);
glEnd();



// ISLAND HOUSE

glBegin(GL_POLYGON);
glColor3ub(0,140,0);
glVertex2f(18.0f,3.0f);
glVertex2f(19.5f,3.6f);
glVertex2f(21.0f,3.0f);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(40,40,90);
glVertex2f(19.0f,3.0f);
glVertex2f(19.0f,3.7f);
glVertex2f(19.8f,3.7f);
glVertex2f(19.8f,3.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(25,25,60);
glVertex2f(18.95f,3.7f);
glVertex2f(19.85f,3.7f);
glVertex2f(19.4f,4.15f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(160,32,240);
glVertex2f(19.10f,3.25f);
glVertex2f(19.25f,3.25f);
glVertex2f(19.25f,3.45f);
glVertex2f(19.10f,3.45f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(0,200,120);
glVertex2f(19.55f,3.25f);
glVertex2f(19.70f,3.25f);
glVertex2f(19.70f,3.45f);
glVertex2f(19.55f,3.45f);
glEnd();

// SHIP
glPushMatrix();
glTranslatef(_moveShip, 0.0f, 0.0f);


glBegin(GL_POLYGON);
glColor3ub(15,20,60);
glVertex2f(21.0f, 2.5f);
glVertex2f(27.0f, 2.5f);
glVertex2f(25.8f, 1.5f);
glVertex2f(22.2f, 1.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(235,235,235);
glVertex2f(22.0f, 2.5f);
glVertex2f(27.0f, 2.5f);
glVertex2f(26.2f, 3.1f);
glVertex2f(22.8f, 3.1f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(250,210,0);
glVertex2f(23.3f, 3.1f);
glVertex2f(23.6f, 3.1f);
glVertex2f(23.6f, 3.4f);
glVertex2f(23.3f, 3.4f);
glVertex2f(24.0f, 3.1f);
glVertex2f(24.3f, 3.1f);
glVertex2f(24.3f, 3.4f);
glVertex2f(24.0f, 3.4f);
glVertex2f(24.8f, 3.1f);
glVertex2f(25.1f, 3.1f);
glVertex2f(25.1f, 3.4f);
glVertex2f(24.8f, 3.4f);
glEnd();

glPopMatrix();


//LIFEGUARD TOWER

// Legs
glBegin(GL_QUADS);
glColor3ub(139,69,19); // Brown color
glVertex2f(30.0f, -8.0f);
glVertex2f(30.8f, -8.0f);
glVertex2f(30.8f, -5.0f);
glVertex2f(30.0f, -5.0f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(139,69,19); // Right leg
glVertex2f(32.0f, -8.0f);
glVertex2f(32.8f, -8.0f);
glVertex2f(32.8f, -5.0f);
glVertex2f(32.0f, -5.0f);
glEnd();

// Platform
glBegin(GL_QUADS);
glColor3ub(139,69,19);
glVertex2f(30.0f, -5.0f);
glVertex2f(32.8f, -5.0f);
glVertex2f(32.8f, -2.0f);
glVertex2f(30.0f, -2.0f);
glEnd();

// Roof
glBegin(GL_TRIANGLES);
glColor3ub(35,35,40);
glVertex2f(29.5f, -2.0f);
glVertex2f(33.3f, -2.0f);
glVertex2f(31.4f, 3.0f);
glEnd();

// Rungs
glBegin(GL_QUADS);
glColor3ub(139,69,19);
glVertex2f(30.8f, -6.7f);
glVertex2f(32.0f, -6.7f);
glVertex2f(32.0f, -6.5f);
 glVertex2f(30.8f, -6.5f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(139,69,19); // Second rung
glVertex2f(30.8f, -5.7f);
 glVertex2f(32.0f, -5.7f);
glVertex2f(32.0f, -5.5f);
glVertex2f(30.8f, -5.5f);
glEnd();


   // PINE TREE 1
glBegin(GL_QUADS);
glColor3ub(120,70,30);
glVertex2f(36.8f,-10.0f);
glVertex2f(37.3f,-10.0f);
glVertex2f(37.3f,-7.0f);
glVertex2f(36.8f,-7.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,170,80);
glVertex2f(36.0f,-6.0f);
glVertex2f(38.1f,-6.0f);
glVertex2f(37.05f,-3.8f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,190,90);
glVertex2f(36.2f,-4.5f);
glVertex2f(37.9f,-4.5f);
glVertex2f(37.05f,-2.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,210,100);
glVertex2f(36.4f,-3.2f);
glVertex2f(37.7f,-3.2f);
glVertex2f(37.05f,-1.7f);
glEnd();


//PINE TREE 2
glBegin(GL_QUADS);
glColor3ub(120,70,30);
glVertex2f(33.8f,-9.0f);
glVertex2f(34.3f,-9.0f);
glVertex2f(34.3f,-6.0f);
glVertex2f(33.8f,-6.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,170,80);
glVertex2f(33.0f,-6.0f);
glVertex2f(35.1f,-6.0f);
glVertex2f(34.05f,-3.8f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,190,90);
glVertex2f(33.2f,-4.5f);
glVertex2f(34.9f,-4.5f);
glVertex2f(34.05f,-2.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,210,100);
glVertex2f(33.4f,-3.2f);
glVertex2f(34.7f,-3.2f);
glVertex2f(34.05f,-1.7f);
glEnd();


//PINE TREE 3
glBegin(GL_QUADS);
glColor3ub(120,70,30);
glVertex2f(36.8f,-12.0f);
glVertex2f(37.3f,-12.0f);
glVertex2f(37.3f,-9.0f);
glVertex2f(36.8f,-9.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,170,80);
glVertex2f(36.0f,-9.0f);
glVertex2f(38.1f,-9.0f);
glVertex2f(37.05f,-6.8f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,190,90);
glVertex2f(36.2f,-7.5f);
glVertex2f(37.9f,-7.5f);
glVertex2f(37.05f,-5.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,210,100);
glVertex2f(36.4f,-6.2f);
glVertex2f(37.7f,-6.2f);
glVertex2f(37.05f,-4.7f);
glEnd();


//PINE TREE 4 (middle, right side of Pine Tree 3
glBegin(GL_QUADS);
glColor3ub(120,70,30);
glVertex2f(34.8f,-12.0f);
glVertex2f(35.3f,-12.0f);
glVertex2f(35.3f,-9.0f);
glVertex2f(34.8f,-9.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,170,80);
glVertex2f(34.0f,-9.0f);
glVertex2f(36.1f,-9.0f);
glVertex2f(35.05f,-6.8f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,190,90);
glVertex2f(34.2f,-7.5f);
glVertex2f(35.9f,-7.5f);
glVertex2f(35.05f,-5.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,210,100);
glVertex2f(34.4f,-6.2f);
glVertex2f(35.7f,-6.2f);
glVertex2f(35.05f,-4.7f);
glEnd();


//PINE TREE 5 (down)
glBegin(GL_QUADS);
glColor3ub(120,70,30);
glVertex2f(33.8f,-16.0f);
glVertex2f(34.3f,-16.0f);
glVertex2f(34.3f,-13.0f);
glVertex2f(33.8f,-13.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,170,80);
glVertex2f(33.0f,-13.0f);
glVertex2f(35.1f,-13.0f);
glVertex2f(34.05f,-10.8f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,190,90);
glVertex2f(33.2f,-11.5f);
glVertex2f(34.9f,-11.5f);
glVertex2f(34.05f,-9.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,210,100);
glVertex2f(33.4f,-10.2f);
glVertex2f(34.7f,-10.2f);
glVertex2f(34.05f,-8.7f);
glEnd();


//PINE TREE 6 (down)
glBegin(GL_QUADS);
glColor3ub(120,70,30);
glVertex2f(36.8f,-16.0f);
glVertex2f(37.3f,-16.0f);
glVertex2f(37.3f,-13.0f);
glVertex2f(36.8f,-13.0f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,170,80);
glVertex2f(36.0f,-13.0f);
glVertex2f(38.1f,-13.0f);
glVertex2f(37.05f,-10.8f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,190,90);
glVertex2f(36.2f,-11.5f);
glVertex2f(37.9f,-11.5f);
glVertex2f(37.05f,-9.5f);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0,210,100);
glVertex2f(36.4f,-10.2f);
glVertex2f(37.7f,-10.2f);
glVertex2f(37.05f,-8.7f);
glEnd();


//  PINE TREE 7(further down)

// Trunk of the pine tree
glBegin(GL_QUADS);
glColor3ub(120,70,30);
glVertex2f(36.8f,-18.0f);
glVertex2f(37.3f,-18.0f);
glVertex2f(37.3f,-15.0f);
glVertex2f(36.8f,-15.0f);
glEnd();

// First layer of pine tree
glBegin(GL_TRIANGLES);
glColor3ub(0,170,80);
glVertex2f(36.0f,-15.0f);
glVertex2f(38.1f,-15.0f);
glVertex2f(37.05f,-12.8f);
glEnd();

// Second laye
glBegin(GL_TRIANGLES);
glColor3ub(0,190,90);
glVertex2f(36.2f,-13.5f);
glVertex2f(37.9f,-13.5f);
glVertex2f(37.05f,-11.5f);
glEnd();

// Third layer
glBegin(GL_TRIANGLES);
glColor3ub(0,210,100);
glVertex2f(36.4f,-12.2f);
glVertex2f(37.7f,-12.2f);
glVertex2f(37.05f,-10.7f);
glEnd();


  // SIMPLE UMBRELLA (RED) + TWO SEATS
// Pole
glBegin(GL_QUADS);
glColor3ub(205,170,120);
glVertex2f(3.40f,-8.50f);
glVertex2f(3.60f,-8.50f);
glVertex2f(3.60f,-4.00f);
glVertex2f(3.40f,-4.00f);
glEnd();

// Canopy (red)
glBegin(GL_POLYGON);
glColor3ub(220,40,40);
glVertex2f(0.90f,-4.00f);
glVertex2f(1.06f,-3.11f);
glVertex2f(1.51f,-2.33f);
glVertex2f(2.20f,-1.75f);
glVertex2f(3.05f,-1.44f);
glVertex2f(3.95f,-1.44f);
glVertex2f(4.80f,-1.75f);
glVertex2f(5.49f,-2.33f);
glVertex2f(5.94f,-3.11f);
glVertex2f(6.10f,-4.00f);
glEnd();

// Rim (darker red)
glBegin(GL_QUADS);
glColor3ub(160,20,20);
glVertex2f(0.90f,-4.00f);
glVertex2f(6.10f,-4.00f);
glVertex2f(6.10f,-4.10f);
glVertex2f(0.90f,-4.10f);
glEnd();

// Hub
glBegin(GL_QUADS);
glColor3ub(230,200,150);
glVertex2f(3.34f,-4.06f);
glVertex2f(3.66f,-4.06f);
glVertex2f(3.58f,-3.80f);
glVertex2f(3.42f,-3.80f);
glEnd();

// Left chair
glBegin(GL_QUADS);
glColor3ub(190,150,100); // seat
glVertex2f(2.00f,-7.90f);
glVertex2f(3.20f,-7.90f);
glVertex2f(3.20f,-8.35f);
glVertex2f(2.00f,-8.35f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(190,150,100); // back
glVertex2f(3.20f,-7.90f);
glVertex2f(2.85f,-6.90f);
glVertex2f(1.65f,-6.90f);
glVertex2f(2.00f,-7.90f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(150,120,80);  // legs
glVertex2f(2.15f,-9.10f);
glVertex2f(2.30f,-9.10f);
glVertex2f(2.30f,-8.35f);
glVertex2f(2.15f,-8.35f);

glVertex2f(2.90f,-9.10f);
glVertex2f(3.05f,-9.10f);
glVertex2f(3.05f,-8.35f);
glVertex2f(2.90f,-8.35f);
glEnd();

// Right chair
glBegin(GL_QUADS);
glColor3ub(190,150,100); // seat
glVertex2f(3.80f,-7.90f);
glVertex2f(5.00f,-7.90f);
glVertex2f(5.00f,-8.35f);
glVertex2f(3.80f,-8.35f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(190,150,100); // back
glVertex2f(3.80f,-7.90f);
glVertex2f(4.10f,-6.90f);
glVertex2f(5.30f,-6.90f);
glVertex2f(5.00f,-7.90f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(150,120,80);  // legs
glVertex2f(3.95f,-9.10f);
glVertex2f(4.10f,-9.10f);
glVertex2f(4.10f,-8.35f);
glVertex2f(3.95f,-8.35f);

glVertex2f(4.85f,-9.10f);
glVertex2f(5.00f,-9.10f);
glVertex2f(5.00f,-8.35f);
glVertex2f(4.85f,-8.35f);
glEnd();

// BLUE UMBRELLA + TWO CHAIRS (LEFT)

// Pole
glBegin(GL_QUADS);
glColor3ub(205,170,120);
glVertex2f(-6.60f,-8.50f);
glVertex2f(-6.40f,-8.50f);
glVertex2f(-6.40f,-4.00f);
glVertex2f(-6.60f,-4.00f);
glEnd();

// Canopy (blue)
glBegin(GL_POLYGON);
glColor3ub(30,144,255);
glVertex2f(-9.10f,-4.00f);
glVertex2f(-8.94f,-3.11f);
glVertex2f(-8.49f,-2.33f);
glVertex2f(-7.80f,-1.75f);
glVertex2f(-6.95f,-1.44f);
glVertex2f(-6.05f,-1.44f);
glVertex2f(-5.20f,-1.75f);
glVertex2f(-4.51f,-2.33f);
glVertex2f(-4.06f,-3.11f);
glVertex2f(-3.90f,-4.00f);
glEnd();

// Rim (darker blue)
glBegin(GL_QUADS);
glColor3ub(20,80,160);
glVertex2f(-9.10f,-4.00f);
glVertex2f(-3.90f,-4.00f);
glVertex2f(-3.90f,-4.10f);
glVertex2f(-9.10f,-4.10f);
glEnd();

// Hub
glBegin(GL_QUADS);
glColor3ub(230,200,150);
glVertex2f(-6.66f,-4.06f);
glVertex2f(-6.34f,-4.06f);
glVertex2f(-6.42f,-3.80f);
glVertex2f(-6.58f,-3.80f);
glEnd();

// Left chair
glBegin(GL_QUADS);
glColor3ub(190,150,100); // seat
glVertex2f(-8.00f,-7.90f);
glVertex2f(-6.80f,-7.90f);
glVertex2f(-6.80f,-8.35f);
glVertex2f(-8.00f,-8.35f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(190,150,100); // back
glVertex2f(-6.80f,-7.90f);
glVertex2f(-7.15f,-6.90f);
glVertex2f(-8.35f,-6.90f);
glVertex2f(-8.00f,-7.90f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(150,120,80);  // legs
glVertex2f(-7.85f,-9.10f);
glVertex2f(-7.70f,-9.10f);
glVertex2f(-7.70f,-8.35f);
glVertex2f(-7.85f,-8.35f);

glVertex2f(-7.10f,-9.10f);
glVertex2f(-6.95f,-9.10f);
glVertex2f(-6.95f,-8.35f);
glVertex2f(-7.10f,-8.35f);
glEnd();

// Right chair
glBegin(GL_QUADS);
glColor3ub(190,150,100); // seat
glVertex2f(-6.20f,-7.90f);
glVertex2f(-5.00f,-7.90f);
glVertex2f(-5.00f,-8.35f);
glVertex2f(-6.20f,-8.35f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(190,150,100); // back
glVertex2f(-6.20f,-7.90f);
glVertex2f(-5.90f,-6.90f);
glVertex2f(-4.70f,-6.90f);
glVertex2f(-5.00f,-7.90f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(150,120,80);  // legs
glVertex2f(-6.05f,-9.10f);
glVertex2f(-5.90f,-9.10f);
glVertex2f(-5.90f,-8.35f);
glVertex2f(-6.05f,-8.35f);

glVertex2f(-5.15f,-9.10f);
glVertex2f(-5.00f,-9.10f);
glVertex2f(-5.00f,-8.35f);
glVertex2f(-5.15f,-8.35f);
glEnd();


// BLACK UMBRELLA + TWO CHAIRS RIGHT

// Pole
glBegin(GL_QUADS);
glColor3ub(205,170,120);
glVertex2f(15.40f,-8.50f);
glVertex2f(15.60f,-8.50f);
glVertex2f(15.60f,-4.00f);
glVertex2f(15.40f,-4.00f);
glEnd();

// Canopy (black)
glBegin(GL_POLYGON);
glColor3ub(25,25,25);
glVertex2f(12.90f,-4.00f);
glVertex2f(13.06f,-3.11f);
glVertex2f(13.51f,-2.33f);
glVertex2f(14.20f,-1.75f);
glVertex2f(15.05f,-1.44f);
glVertex2f(15.95f,-1.44f);
glVertex2f(16.80f,-1.75f);
glVertex2f(17.49f,-2.33f);
glVertex2f(17.94f,-3.11f);
glVertex2f(18.10f,-4.00f);
glEnd();

// Rim (darker)
glBegin(GL_QUADS);
glColor3ub(0,0,0);
glVertex2f(12.90f,-4.00f);
glVertex2f(18.10f,-4.00f);
glVertex2f(18.10f,-4.10f);
glVertex2f(12.90f,-4.10f);
glEnd();

// Hub
glBegin(GL_QUADS);
glColor3ub(230,200,150);
glVertex2f(15.34f,-4.06f);
glVertex2f(15.66f,-4.06f);
glVertex2f(15.58f,-3.80f);
glVertex2f(15.42f,-3.80f);
glEnd();

// Left chair
glBegin(GL_QUADS);
glColor3ub(190,150,100); // seat
glVertex2f(14.00f,-7.90f);
glVertex2f(15.20f,-7.90f);
glVertex2f(15.20f,-8.35f);
glVertex2f(14.00f,-8.35f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(190,150,100); // back
glVertex2f(15.20f,-7.90f);
glVertex2f(14.85f,-6.90f);
glVertex2f(13.65f,-6.90f);
glVertex2f(14.00f,-7.90f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(150,120,80);  // legs
glVertex2f(14.15f,-9.10f);
glVertex2f(14.30f,-9.10f);
glVertex2f(14.30f,-8.35f);
glVertex2f(14.15f,-8.35f);

glVertex2f(14.90f,-9.10f);
glVertex2f(15.05f,-9.10f);
glVertex2f(15.05f,-8.35f);
glVertex2f(14.90f,-8.35f);
glEnd();

// Right chair
glBegin(GL_QUADS);
glColor3ub(190,150,100); // seat
glVertex2f(15.80f,-7.90f);
glVertex2f(17.00f,-7.90f);
glVertex2f(17.00f,-8.35f);
glVertex2f(15.80f,-8.35f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(190,150,100); // back
glVertex2f(15.80f,-7.90f);
glVertex2f(16.10f,-6.90f);
glVertex2f(17.30f,-6.90f);
glVertex2f(17.00f,-7.90f);
glEnd();

glBegin(GL_QUADS);
glColor3ub(150,120,80);  // legs
glVertex2f(15.95f,-9.10f);
glVertex2f(16.10f,-9.10f);
glVertex2f(16.10f,-8.35f);
glVertex2f(15.95f,-8.35f);

glVertex2f(16.85f,-9.10f);
glVertex2f(17.00f,-9.10f);
glVertex2f(17.00f,-8.35f);
glVertex2f(16.85f,-8.35f);
glEnd();


    glutSwapBuffers();
}




    void init() {

    glDisable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}




void display() {
    if (showScene0) {
        drawScene0();  // Show Scene 0 when the flag is true
    }
    else if (showscene4) {
        drawScene4();  // Show scene 4
    }
    else if (showScene3) {
        drawScene3();  // Show beach scene (Scene 3)
    }
    else if (showscene2) {
        drawScene2();  // Show night scene (Scene 2)
    }
    else if (showScene5) {
    drawScene5();
}

    else {
        drawScene1();  // Show day scene (Scene 1)
    }

}



void update(int) {

    _moveShip -= 0.01f;

    _moveA += speed * 0.12f;           // boat-1 Left to Right
    if (_moveA > 50.0f)  _moveA = -50.0f;

    _moveB -= speed * 0.10f;           // boat-2 Right to Left
    if (_moveB < -50.0f)  _moveB = 50.0f;

    _moveC += speed * 0.05f;           // clouds movement
    if (_moveC > 50.0f)  _moveC = -50.0f;

    _angle1 += 2.0f;                   // windmill rotation
    if (_angle1 >= 360.0f)  _angle1 -= 360.0f;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);

}

void reshape(int w, int h) {
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-12.0, 38.0, -19.0, 14.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int, int) {
    switch (key) {

        case '+':
            speed += 0.02f;
            break;

        case '-':
            speed = max(0.0f, speed - 0.02f);
            break;


        case '1':
            showScene5=false;
            showScene3 = false;
            showscene2 = false;
            showscene4 = false;
            showScene0 = false;
            break; // Day (Scene 1)


        case '2':
             showScene5=false;
            showScene3 = false;
            showscene2 = true;
            showscene4 = false;
            showScene0 = false;
            break; // Night (Scene 2)

        case '3':
             showScene5=false;
            showScene3 = true;
            showscene2 = false;
            showscene4 = false;
            showScene0 = false;
            break; // Sea(Scene 3)

        case '4':
             showScene5=false;
            showscene4 = true;
            showScene3 = false;
            showscene2 = false;
            showScene0 = false;
            break; // Scene 4 beach day

        case '0':
             showScene5=false;
            showScene0 = true;
            showScene3 = false;
            showscene2 = false;
            showscene4 = false;
            break; // Scene 0 Intro

            case '5':
    showScene0 = false;
    showScene3 = false;
    showscene2 = false;
    showscene4 = false;
    showScene5 = true;
    break; // Scene 5 beach night


            /*
                    case 13:  // Enter key
            if (showScene0) {
                PlaySound(TEXT("scene0.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
            }
            else if (showscene2) {
                PlaySound(TEXT("insect_chirping.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
            }
            else if (showScene3) {
                PlaySound(TEXT("scene3.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
            }
            else if (showscene4) {
                PlaySound(TEXT("scene4.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
            }
            else {
                // Default Scene 1
                PlaySound(TEXT("scene1.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
            }
            break;

        // Stop sound
        case 's': case 'S':
            PlaySound(NULL, NULL, 0);
            break;
    */

      case 27:
            exit(0);
            break;

    }
    glutPostRedisplay();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1500, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("A way to Saint-Martin Island");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);

    cout << "Keyboard Controls:\n\n Click '0'= Introduction \n Click '1'= Scenery:1 \n Click '2'= Scenery:2 \n Click '3' = Scenery:3\n Click '4' = Scenery:4 \n Click '5' = Scenery:5\n Click '+' = Increasing speed of boat \n Click '-' = Decreasing speed of boat \n Click 'ESC' = EXIT";
    glutMainLoop();
    return 0;

}

