#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <math.h>
#include <ctime>
#include <cstdlib>

#include <iostream>
#define PI 3.1416

GLfloat car_speed = -110.0;
GLfloat car_speed2 = -150.0;
GLfloat car_speed3 = -250.0;

GLfloat cloud_speed1 = 500.0;
GLfloat cloud_speed2 = 400.0;
GLfloat cloud_speed3 = 50.0;
GLfloat cloud_speed4 = 900.0;
GLfloat cloud_speed5 = 700.0;
GLfloat cloud_speed6 = 200.0;

GLfloat sun_speed=10.0;
GLfloat moon_speed=350.0;
GLfloat spin=0.0;

GLfloat color1=0.05,color2=0.05,color3=0.15;
GLfloat suncolor1=1,suncolor2=0,suncolor3=0;


void circle(GLdouble rad) {
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);

    for(int  i = 0; i <=50; i++) {
        glVertex2f(rad * cos(theta), rad * sin(theta));
        theta += delTheta;
    }

    glEnd();
}

void Sky() {
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(color1,color2,color3);
    glVertex2f(0, 0);
    glVertex2f(1000, 0);
    glVertex2f(1000, 500);
    glVertex2f(0,500);
    glEnd();
    glPopMatrix();
}

void cloud()
{
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glTranslatef(40,10,0);
    circle(20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(60,10,0);
    circle(25);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50,20,0);
    circle(20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50,0,0);
    circle(20);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(20,10,0);
    circle(20);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(30,20,0);
    circle(20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30,0,0);
    circle(20);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0,10,0);
    circle(25);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(10,20,0);
    circle(20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,0,0);
    circle(20);
    glPopMatrix();
}

void clouds()
{
    glPushMatrix();
    glTranslatef(cloud_speed1,250,0);
    cloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloud_speed2,290,0);
    cloud();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(cloud_speed3,220,0);
    cloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloud_speed4,400,0);
    cloud();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(cloud_speed5,350,0);
    cloud();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(cloud_speed6,380,0);
    cloud();
    glPopMatrix();
}


void update2()
{

    cloud_speed1-=0.03;

    cloud_speed2-=0.05;

    cloud_speed3-=0.02;

    cloud_speed4-=0.04;

    cloud_speed5-=0.03;

    cloud_speed6-=0.04;


    if (cloud_speed1 < -100) {
        cloud_speed1 = 1020;
    }

    if (cloud_speed2 < -100) {
        cloud_speed2 = 1020;
    }

    if (cloud_speed3 < -100) {
        cloud_speed3 = 1020;
    }

    if (cloud_speed4 < -100) {
        cloud_speed4 = 1020;
    }

    if (cloud_speed5 < -100) {
        cloud_speed5 = 1020;
    }

    if (cloud_speed6 < -100) {
        cloud_speed6 = 1020;
    }

    glutPostRedisplay();

}

void rain()
{
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    GLfloat x= 10.00;
    GLfloat y = 10.00;
    for(int i=0;i<=500;i+=10)
    {
        y=i;
        x=0;
        for(int j=0;j<=1000;j+=20)
        {
            x=j;
            glVertex2f(x,y);
            glVertex2f(x+5.0,y+5.0);
        }
    }
    glEnd();


}

void rains()
{
    glPushMatrix();
    rain();
    glPopMatrix();
}


void sun()
{
    glColor3f(suncolor1,suncolor2,suncolor3);
    glPushMatrix();
    glTranslatef(500,sun_speed,0);
    circle(40);
    glPopMatrix();
}

void Moon() {
    glColor3f(.7882,.7529,.7333);
    glPushMatrix();
    glTranslatef(500,moon_speed, 0);
    circle(30);
    glPopMatrix();
}

void update3()
{

    sun_speed+=0.02;


    if (sun_speed > 560) {
        sun_speed = 0;
    }

    if(sun_speed>60)
    {
        color1=0;
        color2=206;
        color3=209;

        moon_speed=0;
    }

    if(sun_speed>530)
    {
        color1=0.05;
        color2=0.05;
        color3=0.15;

        moon_speed=350;
    }

    if(sun_speed>200)
    {
        suncolor1=255;
        suncolor2=255;
        suncolor3=0;
    }

    if(sun_speed>550)
    {
        suncolor1=1;
        suncolor2=0;
        suncolor3=0;
    }


    glutPostRedisplay();

}

void hill_big() {
    // Hill
    glBegin(GL_POLYGON);
    glColor3f(0.05, 0.35, 0.15);
    glVertex2i(70, 70);
    glVertex2i(200, 225);
    glVertex2i(330, 70);

    glEnd();

    // Hill_top
    glBegin(GL_POLYGON);
    glColor3f(.3, 0.0, 0.0);


    glVertex2i(200, 225);
    glVertex2i(230, 190);
    glVertex2i(220, 180);
    glVertex2i(200, 190);
    glVertex2i(190, 180);
    glVertex2i(170, 190);

    glEnd();
}

void hill_small() {
    // Hill_Small
    glBegin(GL_POLYGON);
    glColor3f(0.65, 0.5, 0.3198);
    glVertex2i(70, 70);
    glVertex2i(200, 225);
    glVertex2i(330, 70);

    glEnd();

    // Hill_Small_Snow
    glBegin(GL_POLYGON);
    glColor3f(.85, .724, .45);

    glVertex2i(200, 225);
    glVertex2i(230, 190);
    glVertex2i(220, 180);
    glVertex2i(200, 190);
    glVertex2i(190, 180);
    glVertex2i(170, 190);

    glEnd();
}

void Hill_Big_One() {
    glPushMatrix();
    glTranslatef(-70,0,0);
    hill_big();
    glPopMatrix();
}

void Hill_Small_One() {
    glPushMatrix();
    glTranslatef(100,-50,0);
    hill_small();
    glPopMatrix();
}

void Hill_Big_Two() {
    glPushMatrix();
    glTranslatef(550,0,0);
    hill_big();
    glPopMatrix();
}


void Car_Model(GLfloat c1,GLfloat c2,GLfloat c3)
{
    /* CAR */

    // CAR BODY
    glBegin(GL_POLYGON);
    glColor3f(c1, c2, c3);
    glVertex2i(15, 35);
    glVertex2i(0, 23);
    glVertex2i(0, 10);
    glVertex2i(80, 10);
    glVertex2i(80, 23);
    glVertex2i(60, 23);
    glVertex2i(50, 35);
    glEnd();

    // CAR WHEEL 1
    glColor3f(0.45, 0.0, 0.25);
    glPushMatrix();
    glTranslatef(13,12,0);
    circle(7);
    glPopMatrix();

    // CAR WHEEL 2
    glColor3f(0.45, 0.0, 0.25);
    glPushMatrix();
    glTranslatef(63,12,0);
    circle(7);
    glPopMatrix();
}

void roadStripe() {
    glBegin(GL_POLYGON);
    glColor3f(0.4,0.4,0.4);

    glVertex2i(0, 29);
    glVertex2i(0, 31);
    glVertex2i(20, 31);
    glVertex2i(20, 29);

    glEnd();
}

void field() {
    //border
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);

    glVertex2i(0, 50);
    glVertex2i(0, 70);
    glVertex2i(1000, 70);
    glVertex2i(1000, 50);

    glEnd();

    // ROAD
    glBegin(GL_POLYGON);
    glColor3f(0.10,0.11,0.11);

    glVertex2i(0, 0);
    glVertex2i(0, 60);
    glVertex2i(1000, 60);
    glVertex2i(1000, 0);

    glEnd();


    // ROAD STRIPES

    for (int i = 0; i <= 1000; i+=50) {
        glPushMatrix();
        glTranslatef(i,0,0);
        roadStripe();
        glPopMatrix();
    }


    // Car Model 1
    glPushMatrix();
    glTranslatef(car_speed,20,0);
    Car_Model(1.0,1.0,1.0);
    glPopMatrix();

    // Car Model 2
    glPushMatrix();
    glTranslatef(car_speed2,0,0);
    Car_Model(1.0,0.0,0.0);
    glPopMatrix();

    // Car Model 3
    glPushMatrix();
    glTranslatef(car_speed3,0,0);
    Car_Model(0.0,0.0,1.0);
    glPopMatrix();
}

void update1()
{

    car_speed += 0.12;
    car_speed2 += 0.10;
    car_speed3 += 0.08;


    if (car_speed > 1100) {
        car_speed = -110;
    }

    if (car_speed2 > 1100) {
        car_speed2 = -150;
    }

    if (car_speed3 > 1100) {
        car_speed3 = -250;
    }

    glutPostRedisplay();

}


void house() {
    // House_Roof
    glBegin(GL_POLYGON);
    glColor3f(.3, 0.0, 0.0);
    glVertex2i(285, 105);
    glVertex2i(295, 130);
    glVertex2i(365, 130);
    glVertex2i(380, 105);

     glEnd();

    // House_Fence
    glBegin(GL_POLYGON);
    glColor3f(.955, 1.0, 1.0);
    glVertex2i(290, 70);
    glVertex2i(290, 104);
    glVertex2i(375, 104);
    glVertex2i(375, 70);

    glEnd();

    // House_Fence_Shade
    glBegin(GL_POLYGON);
    glColor3f(1, 0.924, 0.930);
    glVertex2i(310, 70);
    glVertex2i(350, 104);
    glVertex2i(375, 104);
    glVertex2i(375, 70);

    glEnd();

    // House_Door
    glBegin(GL_POLYGON);
    glColor3f(.3, 0.0, 0.0);
    glVertex2i(320, 70);
    glVertex2i(320, 100);
    glVertex2i(345, 100);
    glVertex2i(345, 70);
    glEnd();

    // Window1
    glBegin(GL_POLYGON);
    glColor3f(1, 0.0, 0.0);
    glVertex2i(295, 75);
    glVertex2i(295, 90);
    glVertex2i(310, 90);
    glVertex2i(310, 75);

     glEnd();


     // Window2
    glBegin(GL_POLYGON);
    glColor3f(1, 0.0, 0.0);
    glVertex2i(355, 75);
    glVertex2i(355, 90);
    glVertex2i(370, 90);
    glVertex2i(370, 75);

    glEnd();


}


void house_one() {
    glPushMatrix();
    glTranslatef(0,0,0);
    house();
    glPopMatrix();
}

void house_two() {
    glPushMatrix();
    glTranslatef(450,0,0);
    house();
    glPopMatrix();
}
void Tree_Model_One() {
    glPushMatrix();
    glTranslatef(110,110,0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(110,100,0);
    circle(15);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2f(109, 70);
    glVertex2f(109, 90);
    glVertex2f(111, 90);
    glVertex2f(111, 70);

    glEnd();
}

void Tree_Model_Two() {
    glPushMatrix();
    glTranslatef(130,130,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(125,126,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(135,126,0);
    circle(5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130,125,0);
    circle(5);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2f(129, 110);
    glVertex2f(129, 124);
    glVertex2f(131, 124);
    glVertex2f(131, 110);

    glEnd();
}

void Tree_Model_Three() {
    glBegin(GL_POLYGON);

    glVertex2f(125, 123);
    glVertex2f(133, 145);
    glVertex2f(141, 123);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(0.38, 0.21, 0.26);
    glVertex2f(132, 110);
    glVertex2f(132, 124);
    glVertex2f(134, 124);
    glVertex2f(134, 110);

    glEnd();
}

void Tree_One() {
    glColor3f(0.0, 0.5, 0.1); // greenish
    glPushMatrix();
    glTranslatef(0,0,0);
    Tree_Model_One();
    glPopMatrix();
}

void Tree_Two() {
    glColor3f(1, 0.5, 0.0); // yellow
    glPushMatrix();
    glTranslatef(540,0,0);
    Tree_Model_One();
    glPopMatrix();
}

void Tree_Three() {
    glColor3f(0.0, 0.5, 0.1); // greenish
    glPushMatrix();
    glTranslatef(750,0,0);
    Tree_Model_One();
    glPopMatrix();
}

void Tree_Four() {
    glColor3f(0.13, 0.37, 0.31); // greenish
    glPushMatrix();
    glTranslatef(292,0,0);
    Tree_Model_One();
    glPopMatrix();
}

void Tree_Five() {
    glColor3f(1, 0.5, 0.0); // yellow
    glPushMatrix();
    glTranslatef(30,-40,0);
    Tree_Model_Two();
    glPopMatrix();
}

void Tree_Six() {
    glColor3f(0.13, 0.37, 0.31); // greenish
    glPushMatrix();
    glTranslatef(50,-40,0);
    Tree_Model_Two();
    glPopMatrix();
}

void Tree_Seven() {
    glColor3f(1, 0.5, 0.0); // yellow
    glPushMatrix();
    glTranslatef(322,-40,0);
    Tree_Model_Two();
    glPopMatrix();
}

void Tree_Eight() {
    glColor3f(0.13, 0.37, 0.31); // greenish
    glPushMatrix();
    glTranslatef(350,-40,0);
    Tree_Model_Two();
    glPopMatrix();
}

void Tree_Nine() {
    glColor3f(0.0, 0.5, 0.1); // greenish
    glPushMatrix();
    glTranslatef(780,-40,0);
    Tree_Model_Two();
    glPopMatrix();
}

void Tree_Ten() {
    glColor3f(1, 0.5, 0.0); // yellow
    glPushMatrix();
    glTranslatef(90,-40,0);
    Tree_Model_Three();
    glPopMatrix();
}

void Tree_Eleven() {
    glColor3f(0.13, 0.37, 0.31); // greenish
    glPushMatrix();
    glTranslatef(125,-40,0);
    Tree_Model_Three();
    glPopMatrix();
}

void Tree_Twelve() {
    glColor3f(0.0, 0.5, 0.1); // greenish
    glPushMatrix();
    glTranslatef(408,-40,0);
    Tree_Model_Three();
    glPopMatrix();
}


/* WINDMILL START */
void Windmill_Stand_Model() {
    glColor3f(0.738, 0.741, 0.736);
    glBegin(GL_POLYGON);
    glVertex2i(375, 100);
    glVertex2i(380, 240);
    glVertex2i(384, 240);
    glVertex2i(390, 100);
    glEnd();
}

void Windmill_Blade() {
    //Blade_One
    glPushMatrix();
    glRotatef(spin,0,0,1);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    //Blade_Two
    glPushMatrix();
    glRotatef(spin,0,0,1);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    //Blade_Three
    glPushMatrix();
    glRotatef(spin,0,0,1);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();
}

void Windmill() {
    // Windmill_Stand
    glColor3f(0.838, 0.841, 0.836);
    glPushMatrix();
    Windmill_Stand_Model();
    glPopMatrix();

    // Windmill_Motor
    glColor3f(0.911, 0.923, 0.936);
    glPushMatrix();
    glTranslatef(380,250,0);
    circle(10);
    glPopMatrix();

    // Windmill_Rotary_Blades
    glColor3f(0.911, 0.923, 0.936);
    glPushMatrix();
    glTranslatef(380,251,0);
    Windmill_Blade();
    glPopMatrix();
}

void Windmill_One() {
    glColor3f(0.911, 0.923, 0.936);
    glPushMatrix();
    glTranslatef(0,-40,0);
    Windmill();
    glPopMatrix();
}

void Windmill_Two() {
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(508,-70,0);
    Windmill();
    glPopMatrix();
}

void Windmill_Three() {
    glColor3f(0.11, 0.23, 0.36);
    glPushMatrix();
    glTranslatef(108,-90,0);
    Windmill();
    glPopMatrix();
}



void SpinWindmill() {
    spin += 0.2;
    glutPostRedisplay();
}
/* WINDMILL END */

void display1()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
    Sky();
    sun();
    Moon();
    update3();
    clouds();
    update2();
    Windmill_One();
    Windmill_Two();
    Windmill_Three();
    SpinWindmill();
    Hill_Big_One();
    Hill_Small_One();
    Hill_Big_Two();
    field();
    update1();
    house_one();
    house_two();
    Tree_One();
    Tree_Two();
    Tree_Three();
    Tree_Four();
    Tree_Five();
    Tree_Six();
    Tree_Seven();
    Tree_Eight();
    Tree_Nine();
    Tree_Ten();
    Tree_Eleven();
    Tree_Twelve();
    rains();
    glFlush();
}


void display2()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
    Sky();
    sun();
    Moon();
    update3();
    clouds();
    update2();
    Windmill_One();
    Windmill_Two();
    Windmill_Three();
    SpinWindmill();
    Hill_Big_One();
    Hill_Small_One();
    Hill_Big_Two();
    field();
    update1();
    house_one();
    house_two();
    Tree_One();
    Tree_Two();
    Tree_Three();
    Tree_Four();
    Tree_Five();
    Tree_Six();
    Tree_Seven();
    Tree_Eight();
    Tree_Nine();
    Tree_Ten();
    Tree_Eleven();
    Tree_Twelve();
    glFlush();
}

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

case 'r':
   glutDisplayFunc(display1);
    break;
case 's':
   glutDisplayFunc(display2);
    break;

    glutPostRedisplay();


	}
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1920, 1900);

    glutCreateWindow("Mountain Side Village");

    glutDisplayFunc(display2);

    //glutIdleFunc(display2);

    glutKeyboardFunc(handleKeypress);

    glutMainLoop();
}

