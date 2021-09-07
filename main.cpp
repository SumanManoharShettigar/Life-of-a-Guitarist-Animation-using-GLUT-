/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include<iostream>
#include<mmsystem.h>
#include<unistd.h>



using namespace std;
static int slices = 16;
static int stacks = 16;
float xhq=1920;
float xhqb=960;
float yhq=1080;
float yhqb=540;
float sx,sy,x,y;
int disp=762;
float ta=1;
float tb=1;
float gy=40;
float gg=1;
float ta_max=-330;
float storydelay=-300;
void* currentFont;
int wi=0;
int time=0;
float lightangle=0;
//audience global variables
float cl1[72],cl2[72],cl3[72];
bool readyforchange;
float moveaudience=0;
int sym =-1;



void displayguitar(float tx, float ty, float SX, float SY, float rx, float ct, float st );
void dispKidGuitar(float tx, float ty, float sx, float sy);
void kidband(float tx,float ty,float sx,float sy);
void setFont(void* font)
{
    currentFont = font;
}

//[drawString
/**
 * Draw a character string.
 *
 * @param x        The x position
 * @param y        The y position
 * @param z        The z position
 * @param string   The character string
 */
void drawString(float x, float y, float z, char *string)
{
    glRasterPos3f(x, y, z);

    for (char* c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(currentFont, *c);  // Updates the position
    }
}

void displaystory( char *string)
{
    char *c= string;
    glColor3f(0.0, 0.0, 0.0);

    drawString( -900,-460,0,c);

}

void DrawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_POLYGON);

    for (int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
    glFlush();
}

/* GLUT callback Handlers */
void glVertex2f(float x1, float x2, char nam[])
{
    float x12, y12;
    x12=x1;
    y12=x2;

    if(!strcmp(nam,"hq"))
    {
        x12=(x12-xhqb);
        y12=-(y12-yhqb);

    }

    //cout<<" ( "<<x12<<" , "<<x12<<" ) \n";
    glVertex2f(x12,y12);
}

void displaystorybox()
{

    float SX=1,SY=1,tx=0,ty=0;

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(25*SX+tx,1025*SY + ty,"hq");
    glVertex2f(25*SX+tx,955*SY + ty,"hq");
    glVertex2f(1885*SX+tx,955*SY + ty,"hq");
    glVertex2f(1885*SX+tx,1025*SY + ty,"hq");
    glVertex2f(25*SX+tx,1025*SY + ty,"hq");
    glEnd();


    glColor3f(1,1,1);
    glBegin(GL_POLYGON);

    glVertex2f(30*SX+tx,1020*SY + ty,"hq");
    glVertex2f(30*SX+tx,960*SY + ty,"hq");
    glVertex2f(1880*SX+tx,960*SY + ty,"hq");
    glVertex2f(1880*SX+tx,1020*SY + ty,"hq");
    glVertex2f(30*SX+tx,1020*SY + ty,"hq");

    glEnd();
}

void displaynames()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glColor3f(0.0, 0.0, 1.0);
    glColor3f(0.91,0.68,0.18);
    drawString(-150, 500, 0.0, "NMAM  INSTITUTE   OF  TECHNOLOGY");

    glColor3f(0.0, 1.0, 0.5);
    drawString(-300,460, 0.0, "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");

    glColor3f(1.0, 0.5, 0.0);
    drawString( -100, 400, 0.0,"A MINI PROJECT ON");

    glColor3f(1.0, 0.0, 0.0);
    drawString(-80, 360, 0.0,"Life of a Guitarist");


    glColor3f(0.0, 1.0, 0.2);
    drawString(-170, 200, 0.0, "Steve Aston   (4NM18CS188) ");
    drawString(-200, 160, 0.0, "Suman Manohar Shettigar  (4NM18CS193) ");

    glColor3f(0.96,0.84,0.04);
    drawString(-100, 0,0.0,"SUBMITTED TO :");
    glColor3f(0.11,0.93,0.73);
    drawString(-100, -40,0.0,"Mr.Pradeep Kanchan ");
    drawString(-100, -80,0.0,"Assistant Professor Grade III ");
    drawString(-100,-120,0.0,"Department of CSE");
    glFlush();


}



void juniorschool()
{
    glColor3f(.7,0.7,0.7);
    glRectf(-960,-540,960,540);
    float tx, ty, sx, sy;
    sx=1;
    sy=1;
    tx=0;
    ty=0;
    glColor3f(0.91,0.19,0.19);
    ty=+200;
    DrawCircle(tx+-378,ty+494,300,30);
    DrawCircle(tx+-135,ty+491,300,30);
    DrawCircle(tx+108,ty+497,300,30);
    DrawCircle(tx+346,ty+494,300,30);
    DrawCircle(tx+559,ty+499,300,30);
    DrawCircle(tx+-556,ty+495,300,30);
    ty=0;
    glBegin(GL_QUADS);

    glColor3f(0.84,0.13,0.13);
    glVertex2f(817*sx+tx,169*sy + ty);
    glVertex2f(849*sx+tx,125*sy + ty);
    glVertex2f(959*sx+tx,128*sy + ty);
    glVertex2f(958*sx+tx,191*sy + ty);
    glVertex2f(855*sx+tx,131*sy + ty);
    glVertex2f(799*sx+tx,-232*sy + ty);
    glVertex2f(959*sx+tx,-224*sy + ty);
    glVertex2f(959*sx+tx,127*sy + ty);
    glColor3f(0.84,0.13,0.14);
    glVertex2f(-960*sx+tx,129*sy + ty);
    glVertex2f(-848*sx+tx,127*sy + ty);
    glVertex2f(-793*sx+tx,196*sy + ty);
    glVertex2f(-960*sx+tx,202*sy + ty);
    glVertex2f(-960*sx+tx,126*sy + ty);
    glVertex2f(-847*sx+tx,124*sy + ty);
    glVertex2f(-805*sx+tx,-221*sy + ty);
    glVertex2f(-955*sx+tx,-224*sy + ty);
    glColor3f(0.93,0.71,0.11);
    glVertex2f(-960*sx+tx,145*sy + ty);
    glVertex2f(-844*sx+tx,136*sy + ty);
    glVertex2f(-847*sx+tx,118*sy + ty);
    glVertex2f(-960*sx+tx,112*sy + ty);
    glColor3f(0.95,0.21,0.22);
    glVertex2f(-960*sx+tx,112*sy + ty);
    glVertex2f(-904*sx+tx,106*sy + ty);
    glVertex2f(-868*sx+tx,-224*sy + ty);
    glVertex2f(-960*sx+tx,-221*sy + ty);
    glVertex2f(-903*sx+tx,103*sy + ty);
    glVertex2f(-847*sx+tx,114*sy + ty);
    glVertex2f(-792*sx+tx,-221*sy + ty);
    glVertex2f(-853*sx+tx,-218*sy + ty);
    glColor3f(0.95,0.21,0.22);
    glVertex2f(578*sx+tx,540*sy + ty);
    glVertex2f(847*sx+tx,140*sy + ty);
    glVertex2f(959*sx+tx,150*sy + ty);
    glVertex2f(sx*960+tx,540*sy+ty);
    glColor3f(0.96,0.77,0.14);
    glVertex2f(847*sx+tx,137*sy + ty);
    glVertex2f(959*sx+tx,145*sy + ty);
    glVertex2f(959*sx+tx,108*sy + ty);
    glVertex2f(850*sx+tx,119*sy + ty);
    glColor3f(0.95,0.21,0.22);
    glVertex2f(959*sx+tx,104*sy + ty);
    glVertex2f(924*sx+tx,101*sy + ty);
    glVertex2f(904*sx+tx,-225*sy + ty);
    glVertex2f(959*sx+tx,-220*sy + ty);
    glVertex2f(852*sx+tx,112*sy + ty);
    glVertex2f(910*sx+tx,105*sy + ty);
    glVertex2f(874*sx+tx,-227*sy + ty);
    glVertex2f(795*sx+tx,-230*sy + ty);
    glColor3f(0.58,0.38,0.18);
    glVertex2f(1*sx+tx,782*sy + ty,"hq");
    glVertex2f(1*sx+tx,765*sy + ty,"hq");
    glVertex2f(1919*sx+tx,760*sy + ty,"hq");
    glVertex2f(1919*sx+tx,782*sy + ty,"hq");
    glColor3f(0.85,0.57,0.33);
    glVertex2f(0*sx+tx,779*sy + ty,"hq");
    glVertex2f(1919*sx+tx,780*sy + ty,"hq");
    glVertex2f(1919*sx+tx,925*sy + ty,"hq");
    glVertex2f(0*sx+tx,924*sy + ty,"hq");
    glColor3f(0.67,0.49,0.34);
    glVertex2f(0*sx+tx,922*sy + ty,"hq");
    glVertex2f(1919*sx+tx,922*sy + ty,"hq");
    glVertex2f(1919*sx+tx,1202*sy + ty,"hq");
    glVertex2f(0*sx+tx,1203*sy + ty,"hq");
    glColor3f(0.41,0.37,0.34);
    glVertex2f(43*sx+tx,753*sy + ty,"hq");
    glVertex2f(208*sx+tx,747*sy + ty,"hq");
    glVertex2f(211*sx+tx,954*sy + ty,"hq");
    glVertex2f(43*sx+tx,955*sy + ty,"hq");
    glColor3f(0.22,0.20,0.20);
    glVertex2f(74*sx+tx,774*sy + ty,"hq");
    glVertex2f(79*sx+tx,830*sy + ty,"hq");
    glVertex2f(182*sx+tx,825*sy + ty,"hq");
    glVertex2f(179*sx+tx,774*sy + ty,"hq");
    glVertex2f(69*sx+tx,861*sy + ty,"hq");
    glVertex2f(183*sx+tx,862*sy + ty,"hq");
    glVertex2f(182*sx+tx,924*sy + ty,"hq");
    glVertex2f(67*sx+tx,931*sy + ty,"hq");
    glColor3f(0.41,0.41,0.41);
    glVertex2f(-847*sx+tx,-255*sy + ty);
    glVertex2f(-848*sx+tx,-269*sy + ty);
    glVertex2f(-827*sx+tx,-271*sy + ty);
    glVertex2f(-825*sx+tx,-256*sy + ty);
    glVertex2f(-850*sx+tx,-350*sy + ty);
    glVertex2f(-853*sx+tx,-363*sy + ty);
    glVertex2f(-823*sx+tx,-364*sy + ty);
    glVertex2f(-821*sx+tx,-345*sy + ty);
    tx=tx+1650;
    glColor3f(0.41,0.37,0.34);
    glVertex2f(43*sx+tx,753*sy + ty,"hq");
    glVertex2f(208*sx+tx,747*sy + ty,"hq");
    glVertex2f(211*sx+tx,954*sy + ty,"hq");
    glVertex2f(43*sx+tx,955*sy + ty,"hq");
    glColor3f(0.22,0.20,0.20);
    glVertex2f(74*sx+tx,774*sy + ty,"hq");
    glVertex2f(79*sx+tx,830*sy + ty,"hq");
    glVertex2f(182*sx+tx,825*sy + ty,"hq");
    glVertex2f(179*sx+tx,774*sy + ty,"hq");
    glVertex2f(69*sx+tx,861*sy + ty,"hq");
    glVertex2f(183*sx+tx,862*sy + ty,"hq");
    glVertex2f(182*sx+tx,924*sy + ty,"hq");
    glVertex2f(67*sx+tx,931*sy + ty,"hq");
    glColor3f(0.41,0.41,0.41);
    glVertex2f(-847*sx+tx,-255*sy + ty);
    glVertex2f(-848*sx+tx,-269*sy + ty);
    glVertex2f(-827*sx+tx,-271*sy + ty);
    glVertex2f(-825*sx+tx,-256*sy + ty);
    glVertex2f(-850*sx+tx,-350*sy + ty);
    glVertex2f(-853*sx+tx,-363*sy + ty);
    glVertex2f(-823*sx+tx,-364*sy + ty);
    glVertex2f(-821*sx+tx,-345*sy + ty);
    glColor3f(0.95,0.21,0.22);
    tx=ty=0;
    glVertex2f(-960*sx+tx,152*sy + ty);
    glVertex2f(-844*sx+tx,139*sy + ty);
    glVertex2f(-539*sx+tx,537*sy + ty);
    glVertex2f(-959*sx+tx,536*sy + ty);
    glEnd();
    glColor3f(0.24,0.23,0.23);
    DrawCircle(tx+-833,ty+-262,40,30);
    DrawCircle(tx+-833,ty+-354,40,30);
    tx=-30;
    DrawCircle(tx+846,ty+-262,40,30);
    DrawCircle(tx+841,ty+-354,40,30);
    glColor3f(0.34,0.33,0.32);
    tx=0;
    DrawCircle(tx+-837,ty+-257,20,30);
    DrawCircle(tx+-833,ty+-356,20,30);
    tx=-30;
    DrawCircle(tx+843,ty+-261,20,30);
    DrawCircle(tx+843,ty+-355,20,30);

//glBegin(GL_QUADS);
//
//glEnd();

//Text
    glColor3f(1.,1.,1.);
    glRasterPos3f(-120, 300, 1);

    char *string="Junior School";
    for (char* c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);  // Updates the position
    }

}
void displaygig()
{
    glColor3f(.9,0.9,0);
    glRectf(-960,-540,960,540);
    float tx=0,ty=0,sx=1,sy=1;
    glBegin(GL_QUADS);
    glColor3f(0.07,0.33,0.56);
    glVertex2f(-960*sx+tx,-310*sy + ty);
    glVertex2f(960*sx+tx,-310*sy + ty);
    glVertex2f(960*sx+tx,-540*sy + ty);
    glVertex2f(-960*sx+tx,-540*sy + ty);
    glColor3f(0.33,0.27,0.79);
    glVertex2f(-466*sx+tx,-341*sy + ty);
    glVertex2f(-396*sx+tx,-308*sy + ty);
    glVertex2f(362*sx+tx,-306*sy + ty);
    glVertex2f(451*sx+tx,-339*sy + ty);
    glVertex2f(-568*sx+tx,-425*sy + ty);
    glVertex2f(-452*sx+tx,-365*sy + ty);
    glVertex2f(402*sx+tx,-366*sy + ty);
    glVertex2f(550*sx+tx,-425*sy + ty);

    glColor3f(0.00,0.00,0.08);
    glVertex2f(-960*sx+tx,500*sy + ty);
    glVertex2f(-960*sx+tx,537*sy + ty);
    glVertex2f(960*sx+tx,540*sy+ty);
    glVertex2f(959*sx+tx,496*sy + ty);
    glVertex2f(-960*sx+tx,473*sy + ty);
    glVertex2f(959*sx+tx,470*sy + ty);
    glVertex2f(959*sx+tx,464*sy + ty);
    glVertex2f(-960*sx+tx,462*sy + ty);
    glEnd();
    glColor3f(0.69,0.78,1.00);

    DrawCircle(tx+-892,ty+458,15,15);
    DrawCircle(tx+-700,ty+461,15,15);
    DrawCircle(tx+-503,ty+458,15,15);
    DrawCircle(tx+-312,ty+459,15,15);
    DrawCircle(tx+-122,ty+459,15,15);
    DrawCircle(tx+75,ty+460,15,15);
    DrawCircle(tx+270,ty+458,15,15);
    DrawCircle(tx+457,ty+460,15,15);
    DrawCircle(tx+651,ty+459,15,15);
    DrawCircle(tx+850,ty+461,15,15);
    glBegin(GL_QUADS);

    glColor3f(0.32,0.96,1.00);
    glVertex2f(-960*sx+tx,-287*sy + ty);
    glVertex2f(959*sx+tx,-279*sy + ty);
    glVertex2f(959*sx+tx,-312*sy + ty);
    glVertex2f(-960*sx+tx,-314*sy + ty);
    glVertex2f(-472*sx+tx,-349*sy + ty);
    glVertex2f(453*sx+tx,-348*sy + ty);
    glVertex2f(442*sx+tx,-383*sy + ty);
    glVertex2f(-466*sx+tx,-383*sy + ty);
    glVertex2f(-568*sx+tx,-429*sy + ty);
    glVertex2f(551*sx+tx,-424*sy + ty);
    glVertex2f(543*sx+tx,-465*sy + ty);
    glVertex2f(-565*sx+tx,-463*sy + ty);
    ty-=50;
    glColor3f(0.33,0.29,0.57);
    glVertex2f(-906*sx+tx,68*sy + ty);
    glVertex2f(-825*sx+tx,66*sy + ty);
    glVertex2f(-819*sx+tx,-254*sy + ty);
    glVertex2f(-902*sx+tx,-255*sy + ty);
    glVertex2f(849*sx+tx,81*sy + ty);
    glVertex2f(933*sx+tx,83*sy + ty);
    glVertex2f(930*sx+tx,-240*sy + ty);
    glVertex2f(847*sx+tx,-241*sy + ty);
    glEnd();

//speaker heads

    glColor3f(0.05,0.04,0.30);
    DrawCircle(tx+-869,ty+22,30,30);
    DrawCircle(tx+-865,ty+-55,30,30);
    DrawCircle(tx+-862,ty+-128,30,30);
    DrawCircle(tx+-867,ty+-212,30,30);
    DrawCircle(tx+890,ty+36,30,30);
    DrawCircle(tx+890,ty+-43,30,30);
    DrawCircle(tx+892,ty+-122,30,30);
    DrawCircle(tx+891,ty+-196,30,30);

    DrawCircle(tx+-869,ty+22,30,30);
    DrawCircle(tx+-865,ty+-55,30,30);
    DrawCircle(tx+-862,ty+-128,30,30);
    DrawCircle(tx+-867,ty+-212,30,30);
    DrawCircle(tx+890,ty+36,30,30);
    DrawCircle(tx+890,ty+-43,30,30);
    DrawCircle(tx+892,ty+-122,30,30);
    DrawCircle(tx+891,ty+-196,30,30);
    glColor3f(0.67,0.78,0.96);
    DrawCircle(tx+-869,ty+22,15,15);
    DrawCircle(tx+-865,ty+-55,15,15);
    DrawCircle(tx+-862,ty+-128,15,15);
    DrawCircle(tx+-867,ty+-212,15,15);
    DrawCircle(tx+890,ty+36,15,15);
    DrawCircle(tx+890,ty+-43,15,15);
    DrawCircle(tx+892,ty+-122,15,15);
    DrawCircle(tx+891,ty+-196,15,15);


//Text
    glColor3f(.0,.0,.0);
    glRasterPos3f(-120, 300, 1);

    char *string="Small Gig";
    for (char* c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);  // Updates the position
    }
}


void dispcollege()
{
    glColor3f(.8,0.8,0.8);
    glRectf(-960,-540,960,540);
    float tx, ty, sx, sy;
    sx=1;
    sy=1;
    tx=0;
    ty=0;
    glBegin(GL_QUADS);
    glColor3f(0.84,0.13,0.13);
    glVertex2f(817*sx+tx,169*sy + ty);
    glVertex2f(849*sx+tx,125*sy + ty);
    glVertex2f(959*sx+tx,128*sy + ty);
    glVertex2f(958*sx+tx,191*sy + ty);
    glVertex2f(855*sx+tx,131*sy + ty);
    glVertex2f(799*sx+tx,-232*sy + ty);
    glVertex2f(959*sx+tx,-224*sy + ty);
    glVertex2f(959*sx+tx,127*sy + ty);
    glColor3f(0.84,0.13,0.14);
    glVertex2f(-960*sx+tx,129*sy + ty);
    glVertex2f(-848*sx+tx,127*sy + ty);
    glVertex2f(-793*sx+tx,196*sy + ty);
    glVertex2f(-960*sx+tx,202*sy + ty);
    glVertex2f(-960*sx+tx,126*sy + ty);
    glVertex2f(-847*sx+tx,124*sy + ty);
    glVertex2f(-805*sx+tx,-221*sy + ty);
    glVertex2f(-955*sx+tx,-224*sy + ty);
    glColor3f(0.93,0.71,0.11);
    glVertex2f(-960*sx+tx,145*sy + ty);
    glVertex2f(-844*sx+tx,136*sy + ty);
    glVertex2f(-847*sx+tx,118*sy + ty);
    glVertex2f(-960*sx+tx,112*sy + ty);
    glColor3f(0.95,0.21,0.22);
    glVertex2f(-960*sx+tx,112*sy + ty);
    glVertex2f(-904*sx+tx,106*sy + ty);
    glVertex2f(-868*sx+tx,-224*sy + ty);
    glVertex2f(-960*sx+tx,-221*sy + ty);
    glVertex2f(-903*sx+tx,103*sy + ty);
    glVertex2f(-847*sx+tx,114*sy + ty);
    glVertex2f(-792*sx+tx,-221*sy + ty);
    glVertex2f(-853*sx+tx,-218*sy + ty);
    glColor3f(0.95,0.21,0.22);
    glVertex2f(578*sx+tx,540*sy + ty);
    glVertex2f(847*sx+tx,140*sy + ty);
    glVertex2f(959*sx+tx,150*sy + ty);
    glVertex2f(sx*960+tx,540*sy+ty);
    glColor3f(0.96,0.77,0.14);
    glVertex2f(847*sx+tx,137*sy + ty);
    glVertex2f(959*sx+tx,145*sy + ty);
    glVertex2f(959*sx+tx,108*sy + ty);
    glVertex2f(850*sx+tx,119*sy + ty);
    glColor3f(0.95,0.21,0.22);
    glVertex2f(959*sx+tx,104*sy + ty);
    glVertex2f(924*sx+tx,101*sy + ty);
    glVertex2f(904*sx+tx,-225*sy + ty);
    glVertex2f(959*sx+tx,-220*sy + ty);
    glVertex2f(852*sx+tx,112*sy + ty);
    glVertex2f(910*sx+tx,105*sy + ty);
    glVertex2f(874*sx+tx,-227*sy + ty);
    glVertex2f(795*sx+tx,-230*sy + ty);
    glColor3f(0.58,0.38,0.18);
    glVertex2f(1*sx+tx,782*sy + ty,"hq");
    glVertex2f(1*sx+tx,765*sy + ty,"hq");
    glVertex2f(1919*sx+tx,760*sy + ty,"hq");
    glVertex2f(1919*sx+tx,782*sy + ty,"hq");
    glColor3f(0.85,0.57,0.33);
    glVertex2f(0*sx+tx,779*sy + ty,"hq");
    glVertex2f(1919*sx+tx,780*sy + ty,"hq");
    glVertex2f(1919*sx+tx,925*sy + ty,"hq");
    glVertex2f(0*sx+tx,924*sy + ty,"hq");
//floor
    glColor3f(0.40,0.20,0.00);
    glVertex2f(0*sx+tx,922*sy + ty,"hq");
    glVertex2f(1919*sx+tx,922*sy + ty,"hq");
    glVertex2f(1919*sx+tx,1202*sy + ty,"hq");
    glVertex2f(0*sx+tx,1203*sy + ty,"hq");
    glColor3f(0.41,0.37,0.34);
    glVertex2f(43*sx+tx,753*sy + ty,"hq");
    glVertex2f(208*sx+tx,747*sy + ty,"hq");
    glVertex2f(211*sx+tx,954*sy + ty,"hq");
    glVertex2f(43*sx+tx,955*sy + ty,"hq");
    glColor3f(0.22,0.20,0.20);
    glVertex2f(74*sx+tx,774*sy + ty,"hq");
    glVertex2f(79*sx+tx,830*sy + ty,"hq");
    glVertex2f(182*sx+tx,825*sy + ty,"hq");
    glVertex2f(179*sx+tx,774*sy + ty,"hq");
    glVertex2f(69*sx+tx,861*sy + ty,"hq");
    glVertex2f(183*sx+tx,862*sy + ty,"hq");
    glVertex2f(182*sx+tx,924*sy + ty,"hq");
    glVertex2f(67*sx+tx,931*sy + ty,"hq");
    glColor3f(0.41,0.41,0.41);
    glVertex2f(-847*sx+tx,-255*sy + ty);
    glVertex2f(-848*sx+tx,-269*sy + ty);
    glVertex2f(-827*sx+tx,-271*sy + ty);
    glVertex2f(-825*sx+tx,-256*sy + ty);
    glVertex2f(-850*sx+tx,-350*sy + ty);
    glVertex2f(-853*sx+tx,-363*sy + ty);
    glVertex2f(-823*sx+tx,-364*sy + ty);
    glVertex2f(-821*sx+tx,-345*sy + ty);
    tx=tx+1650;
    glColor3f(0.41,0.37,0.34);
    glVertex2f(43*sx+tx,753*sy + ty,"hq");
    glVertex2f(208*sx+tx,747*sy + ty,"hq");
    glVertex2f(211*sx+tx,954*sy + ty,"hq");
    glVertex2f(43*sx+tx,955*sy + ty,"hq");
    glColor3f(0.22,0.20,0.20);
    glVertex2f(74*sx+tx,774*sy + ty,"hq");
    glVertex2f(79*sx+tx,830*sy + ty,"hq");
    glVertex2f(182*sx+tx,825*sy + ty,"hq");
    glVertex2f(179*sx+tx,774*sy + ty,"hq");
    glVertex2f(69*sx+tx,861*sy + ty,"hq");
    glVertex2f(183*sx+tx,862*sy + ty,"hq");
    glVertex2f(182*sx+tx,924*sy + ty,"hq");
    glVertex2f(67*sx+tx,931*sy + ty,"hq");
    glColor3f(0.41,0.41,0.41);
    glVertex2f(-847*sx+tx,-255*sy + ty);
    glVertex2f(-848*sx+tx,-269*sy + ty);
    glVertex2f(-827*sx+tx,-271*sy + ty);
    glVertex2f(-825*sx+tx,-256*sy + ty);
    glVertex2f(-850*sx+tx,-350*sy + ty);
    glVertex2f(-853*sx+tx,-363*sy + ty);
    glVertex2f(-823*sx+tx,-364*sy + ty);
    glVertex2f(-821*sx+tx,-345*sy + ty);
    glColor3f(0.95,0.21,0.22);
    tx=ty=0;
    glVertex2f(-960*sx+tx,152*sy + ty);
    glVertex2f(-844*sx+tx,139*sy + ty);
    glVertex2f(-539*sx+tx,537*sy + ty);
    glVertex2f(-959*sx+tx,536*sy + ty);
    glEnd();

//Text
    glColor3f(.0,.0,.0);
    glRasterPos3f(-120, 300, 1);

    char *string="College";
    for (char* c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);  // Updates the position
    }

//int sym1;
//int sym2;
//sym2=sym1=1;
//sym2=-1;
//sym1=-1;
//int cp[4][2]={{sym1*1920,sym2*691},{sym1*1809,sym2*680},{sym1*1455,sym2*1076},{sym1*1920,sym2*1078}};
//int c[4],k,n=3;
//float x,y,u,blend;
//bezierCoefficients(n,c);
//
//glBegin(GL_POLYGON);
//
//	for(u=0;u<1.0;u+=0.01)
//	{x=0;y=0;
//		for(k=0;k<4;k++)
//		{
//			blend=c[k]*pow(u,k)*pow(1-u,n-k);
//			x+=cp[k][0]*blend;
//			y+=cp[k][1]*blend;
//		}
//
////        DrawCircle()
//		glVertex2f(x,y,"hq");
//
//	}
//	glEnd();




}





//Queen
float mouth=90;
int mouthc=0;
void displayBand(float tx,float ty,float sx,float sy)
{

    if(mouthc==0)
    {
        mouth+=0.5;
        if(mouth>=100)
            mouthc=1;
    }
    if(mouthc==1)
    {
        mouth-=0.5;
        if(mouth<=90)
            mouthc=0;
    }
    //Human singer

    glTranslatef(1*sx,-100*sy,0);
    glColor3f(1.0,0.90,0.70);
    DrawCircle(1*sx,110*sy,40*sy,100*sy);//head

    glBegin(GL_POLYGON);
    glColor3f(0.1,0.1,0.1);//hair
    glVertex2f(-40*sx,133*sy);
    glVertex2f(40*sx,133*sy);
    glVertex2f(40*sx,160*sy);
    glVertex2f(30*sx,150*sy);
    glVertex2f(20*sx,160*sy);
    glVertex2f(10*sx,155*sy);
    glVertex2f(1*sx,160*sy);
    glVertex2f(-10*sx,150*sy);
    glVertex2f(-20*sx,160*sy);
    glVertex2f(-30*sx,150*sy);
    glVertex2f(-40*sx,160*sy);
    glEnd();


    glColor3f(0.0,0.0,0.0);
    DrawCircle(17*sx,120*sy,5*sx,100);//eyes

    glColor3f(0.0,0.0,0.0);
    DrawCircle(-17*sx,120*sy,5*sy,100);

    glBegin(GL_POLYGON);
    //Smile
    glVertex2d(-15*sx,100*sy);
    glVertex2d(-1*sx,95*sy);

    glVertex2d(17*sx,100*sy);
    glVertex2d(1*sx,mouth*sy);
    glVertex2d(-15*sx,100*sy);
    glEnd();

    glColor3f(1.0,0.90,0.70);
    glRectd(-50*sx,75*sy,+50*sx,-75*sy);//body
    glRectd(-80*sx,-55*sy,-50*sx,75*sy);//left arm
    glRectd(50*sx,75*sy,80*sx,-55*sy);//right arm

    //TANK TOP
    glBegin(GL_POLYGON);
    glColor3f(1.,1.,1.);
    glVertex2f(-50*sx,30*sy);
    glVertex2f(-50*sx,-75*sy);
    glVertex2f(50*sx,-75*sy);
    glVertex2f(50*sx,30*sy);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.,1.,1.);
    glVertex2f(-20*sx,30*sy);
    glVertex2f(-30*sx,50*sy);
    glVertex2f(-30*sx,75*sy);
    glVertex2f(-40*sx,75*sy);
    glVertex2f(-40*sx,50*sy);
    glVertex2f(-50*sx,30*sy);
    glVertex2f(50*sx,30*sy);
    glVertex2f(40*sx,50*sy);
    glVertex2f(40*sx,75*sy);
    glVertex2f(30*sx,75*sy);
    glVertex2f(30*sx,50*sy);
    glVertex2f(20*sx,30*sy);


    glEnd();





    glColor3f(0.5,0.7,1.);
    glRectd(-50*sx,-75*sy,-10*sx,-250*sy);//left leg
    glRectd(50*sx,-75*sy,10*sx,-250*sy);//right leg
    glRectd(50*sx,-75*sy,-50*sx,-110*sy);

    //belt
    glColor3f(0.5,0.5,0.1);
    glRectd(50*sx,-75*sy,-50*sx,-55*sy);



    //right foot
    glColor3f(0.,0.,0.);
    glBegin(GL_TRIANGLES);
    glVertex2f(50*sx,-250*sy);
    glVertex2f(10*sx,-250*sy);
    glVertex2f(0*sx,-280*sy);



    //left foot
    glVertex2f(-50*sx,-250*sy);
    glVertex2f(-10*sx,-250*sy);
    glVertex2f(-60*sx,-280*sy);

    glEnd();

    //hand
    glTranslatef(-1*sx,+100*sy,0);
    //Hand Movement
    glPushMatrix();
    glTranslatef(65*sx,-145*sy,0);
    glColor3f(1.0,0.90,0.70);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_POLYGON);

    glVertex2f(-15*sx,30*sy);
    glVertex2f(15*sx,30*sy);
    glVertex2f(10*sx,-50*sy);
    glVertex2f(-10*sx,-50*sy);

    glEnd();
    glTranslatef(-65*sx,+145*sy,0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-65*sx,-145*sy,0);
    glColor3f(1.0,0.90,0.70);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_POLYGON);

    glVertex2f(-15*sx,30*sy);
    glVertex2f(15*sx,30*sy);
    glVertex2f(10*sx,-50*sy);
    glVertex2f(-10*sx,-50*sy);

    glEnd();
    glTranslatef(+65*sx,+145*sy,0);
    glPopMatrix();


    glTranslatef(+1*sx,-100*sy,0);

    //right hand

    glTranslatef(-1*sx,100*sy,0);
    //HUman End

    //Mic
    glTranslatef(1*sx,-100*sy,0);
    glColor3f(.6,.6,.6);
    glBegin(GL_POLYGON);
    glVertex2f(-24*sx,-290*sy);
    glVertex2f(-15*sx,-290*sy);
    glVertex2f(-15*sx,65*sy);
    glVertex2f(-24*sx,65*sy);
    glEnd();

    glBegin(GL_TRIANGLES);//mic
    glVertex2f(-0*sx,70*sy);
    glVertex2f(-10*sx,90*sy);
    glVertex2f(-60*sx,50*sy);
    DrawCircle(-5*sx,80*sy,10*sx,100);

    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-60*sx,-290*sy);
    glVertex2f(-60*sx,-305*sy);
    glVertex2f(26*sx,-305*sy);
    glVertex2f(26*sx,-290*sy);

    glEnd();
    glTranslatef(-1*sx,100*sy,0);




    //Human2

    glTranslatef(600*sx,25*sy,0);
    glColor3f(1.0,0.90,0.70);
    DrawCircle(1*sx,110*sy,40*sy,100*sy);//head
    glBegin(GL_POLYGON);
    glColor3f(0.1,0.1,0.1);//hair
    glVertex2f(-40*sx,133*sy);
    glVertex2f(40*sx,133*sy);
    glVertex2f(40*sx,160*sy);
    glVertex2f(30*sx,150*sy);
    glVertex2f(20*sx,160*sy);
    glVertex2f(10*sx,155*sy);
    glVertex2f(1*sx,160*sy);
    glVertex2f(-10*sx,150*sy);
    glVertex2f(-20*sx,160*sy);
    glVertex2f(-30*sx,150*sy);
    glVertex2f(-40*sx,160*sy);
    glEnd();


    glColor3f(0.0,0.0,0.0);
    DrawCircle(17*sx,120*sy,5*sx,100);//eyes

    glColor3f(0.0,0.0,0.0);
    DrawCircle(-17*sx,120*sy,5*sy,100);

    glBegin(GL_POLYGON);
    //Smile
    glVertex2d(-15*sx,100*sy);
    glVertex2d(-1*sx,95*sy);

    glVertex2d(17*sx,100*sy);
    glVertex2d(1*sx,90*sy);
    glVertex2d(-15*sx,100*sy);
    glEnd();

    glColor3f(1.0,0.90,0.70);
    glRectd(-50*sx,75*sy,+50*sx,-75*sy);//body
    glRectd(-80*sx,-55*sy,-50*sx,75*sy);//left arm
    glRectd(50*sx,75*sy,80*sx,-55*sy);//right arm

    glBegin(GL_POLYGON);
    glColor3f(1.,1.,1.);
    glVertex2f(-50*sx,30*sy);
    glVertex2f(-50*sx,-75*sy);
    glVertex2f(50*sx,-75*sy);
    glVertex2f(50*sx,30*sy);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.,1.,1.);
    glVertex2f(-20*sx,30*sy);
    glVertex2f(-30*sx,50*sy);
    glVertex2f(-30*sx,75*sy);
    glVertex2f(-40*sx,75*sy);
    glVertex2f(-40*sx,50*sy);
    glVertex2f(-50*sx,30*sy);
    glVertex2f(50*sx,30*sy);
    glVertex2f(40*sx,50*sy);
    glVertex2f(40*sx,75*sy);
    glVertex2f(30*sx,75*sy);
    glVertex2f(30*sx,50*sy);
    glVertex2f(20*sx,30*sy);


    glEnd();



    glColor3f(0.1,0.1,.1);
    glRectd(-50*sx,-75*sy,-10*sx,-250*sy);//left leg
    glRectd(50*sx,-75*sy,10*sx,-250*sy);//right leg
    glRectd(50*sx,-75*sy,-50*sx,-110*sy);

    //belt
    glColor3f(0.5,0.5,0.1);
    glRectd(50*sx,-75*sy,-50*sx,-55*sy);



    //right foot
    glColor3f(0.,0.,0.);
    glBegin(GL_TRIANGLES);
    glVertex2f(50*sx,-250*sy);
    glVertex2f(10*sx,-250*sy);
    glVertex2f(0*sx,-280*sy);



    //left foot
    glVertex2f(-50*sx,-250*sy);
    glVertex2f(-10*sx,-250*sy);
    glVertex2f(-60*sx,-280*sy);

    glEnd();

    //hand
    //hand
    glTranslatef(1*sx,+100*sy,0);
    //Hand Movement
    glPushMatrix();
    glTranslatef(65*sx,-145*sy,0);
    glColor3f(1.0,0.90,0.70);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_POLYGON);

    glVertex2f(-15*sx,30*sy);
    glVertex2f(15*sx,30*sy);
    glVertex2f(10*sx,-30*sy);
    glVertex2f(-10*sx,-30*sy);

    glEnd();
    glTranslatef(-65*sx,+145*sy,0);
    glPopMatrix();


    //GUITAR RIGHT

    glPushMatrix();
    glTranslatef(-30*sx,70*sy,0);

    glRotatef(290+lightangle/6,0,0,1);
    displayguitar(1,1,.6*sx,.6*sy,.5*sy,.5*sy,.5*sy);
    glTranslatef(30*sx,-70*sy,0);
    glPopMatrix();

    //left handing moving
    glPushMatrix();
    glTranslatef(-65*sx,-145*sy,0);
    glColor3f(1.0,0.90,0.70);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_POLYGON);

    glVertex2f(-15*sx,30*sy);
    glVertex2f(15*sx,30*sy);
    glVertex2f(10*sx,-50*sy);
    glVertex2f(-10*sx,-50*sy);

    glEnd();
    glTranslatef(+65*sx,+145*sy,0);
    glPopMatrix();


    glTranslatef(-1*sx,-100*sy,0);

    glTranslatef(-600*sx,-25*sy,0);
    //HUman End







    //Human3 drums

    glTranslatef(-400*sx,75*sy,0);
    glColor3f(1.0,0.90,0.70);
    DrawCircle(1*(sx-.20),110*(sy-.20),40*(sx-.20),100);//head

    glTranslatef(-1*sx,-30*sy,0);
    glBegin(GL_POLYGON);
    glColor3f(0.74,0.52,0.32);//hair
    glVertex2f(-30*sx,133*sy);
    glVertex2f(30*sx,133*sy);
    glVertex2f(40*sx,160*sy);
    glVertex2f(30*sx,150*sy);
    glVertex2f(20*sx,160*sy);
    glVertex2f(10*sx,155*sy);
    glVertex2f(1*sx,160*sy);
    glVertex2f(-10*sx,150*sy);
    glVertex2f(-20*sx,160*sy);
    glVertex2f(-30*sx,150*sy);
    glVertex2f(-30*sx,160*sy);
    glEnd();
    glTranslatef(1*sx,+30*sy,0);

    glColor3f(0.0,0.0,0.0);
    DrawCircle(17*(sx-.20),120*(sy-.20),5*(sx-.20),100);//eyes

    glColor3f(0.0,0.0,0.0);
    DrawCircle(-17*(sx-.20),120*(sy-.20),5*(sx-.20),100);

    glBegin(GL_POLYGON);
    //Smile
    glVertex2d(-15*(sx-.20),100*(sy-.20));
    glVertex2d(-1*(sx-.20),95*(sy-.20));

    glVertex2d(17*(sx-.20),100*(sy-.20));
    glVertex2d(1*(sx-.20),90*(sy-.20));
    glVertex2d(-15*(sx-.20),100*(sy-.20));
    glEnd();

    glColor3f(1.0,0.90,0.70);
    glRectd(-50*(sx-.20),75*(sy-.20),+50*(sx-.20),-75*(sy-.20));//body
    glRectd(-80*(sx-.20),-1*(sy-.20),-50*(sx-.20),75*(sy-.20));//left arm
    glRectd(50*(sx-.20),75*(sy-.20),80*(sx-.20),1*(sy-.20));//right arm

    glBegin(GL_POLYGON);
    glColor3f(1.,1.,1.);
    glVertex2f(-50*(sx-.20),30*(sy-.20));
    glVertex2f(-50*(sx-.20),-75*(sy-.20));
    glVertex2f(50*(sx-.20),-75*(sy-.20));
    glVertex2f(50*(sx-.20),30*(sy-.20));
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.,1.,1.);
    glVertex2f(-20*(sx-.20),30*(sy-.20));
    glVertex2f(-30*(sx-.20),50*(sy-.20));
    glVertex2f(-30*(sx-.20),75*(sy-.20));
    glVertex2f(-40*(sx-.20),75*(sy-.20));
    glVertex2f(-40*(sx-.20),50*(sy-.20));
    glVertex2f(-50*(sx-.20),30*(sy-.20));
    glVertex2f(50*(sx-.20),30*(sy-.20));
    glVertex2f(40*(sx-.20),50*(sy-.20));
    glVertex2f(40*(sx-.20),75*(sy-.20));
    glVertex2f(30*(sx-.20),75*(sy-.20));
    glVertex2f(30*(sx-.20),50*(sy-.20));
    glVertex2f(20*(sx-.20),30*(sy-.20));


    glEnd();



    glColor3f(0.1,0.1,.1);
    glRectd(-50*(sx-.20),-75*(sy-.20),-10*(sx-.20),-250*(sy-.20));//left leg
    glRectd(50*(sx-.20),-75*(sy-.20),10*(sx-.20),-250*(sy-.20));//right leg
    glRectd(50*(sx-.20),-75*(sy-.20),-50*(sx-.20),-110*(sy-.20));

    //belt
    glColor3f(0.5,0.5,0.1);
    glRectd(50*(sx-.20),-75*(sy-.20),-50*(sx-.20),-55*(sy-.20));



    //right foot
    glColor3f(0.,0.,0.);
    glBegin(GL_TRIANGLES);
    glVertex2f(50*(sx-.20),-250*(sy-.20));
    glVertex2f(10*(sx-.20),-250*(sy-.20));
    glVertex2f(0*(sx-.20),-280*(sy-.20));



    //left foot
    glVertex2f(-50*(sx-.20),-250*(sy-.20));
    glVertex2f(-10*(sx-.20),-250*(sy-.20));
    glVertex2f(-60*(sx-.20),-280*(sy-.20));

    glEnd();

    //hand
    glTranslatef(1*sx,+100*sy,0);
    //Hand Movement
    glPushMatrix();
    glTranslatef(65*(sx-.20),-145*(sy-.20),0);
    glColor3f(1.0,0.90,0.70);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_POLYGON);

    glVertex2f(-15*(sx-.20),30*(sy-.20));
    glVertex2f(15*(sx-.20),30*(sy-.20));
    glVertex2f(10*(sx-.20),-50*(sy-.20));
    glVertex2f(-10*(sx-.20),-50*(sy-.20));

    glEnd();
    glTranslatef(-65*(sx-.20),+145*(sy-.20),0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-65*(sx-.20),-145*(sy-.20),0);
    glColor3f(1.0,0.90,0.70);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_POLYGON);

    glVertex2f(-15*(sx-.20),30*(sy-.20));
    glVertex2f(15*(sx-.20),30*(sy-.20));
    glVertex2f(10*(sx-.20),-50*(sy-.20));
    glVertex2f(-10*(sx-.20),-50*(sy-.20));

    glEnd();
    glTranslatef(+65*(sx-.20),+145*(sy-.20),0);
    glPopMatrix();


    glTranslatef(-1*sx,-100*sy,0);
    glTranslatef(400*sx,-75*sy,0);
    //HUman End

    //drums
    glTranslatef(-400*sx,+75*sy,0);
    glColor3f(.4,.4,.4);
    DrawCircle(0*sx,-150*sy,100*sy,100);

    glBegin(GL_POLYGON);
    glVertex2f(-240*sx,-230*sy);
    glVertex2f(-240*sx,-250*sy);
    glVertex2f(240*sx,-250*sy);
    glVertex2f(240*sx,-230*sy);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(117*sx,-230*sy);
    glVertex2f(123*sx,-230*sy);
    glVertex2f(123*sx,-40*sy);
    glVertex2f(117*sx,-40*sy);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(60*sx,-11*sy);
    glVertex2f(150*sx,-11*sy);
    glVertex2f(160*sx,-50*sy);
    glVertex2f(70*sx,-50*sy);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(193*sx,-230*sy);
    glVertex2f(187*sx,-230*sy);
    glVertex2f(187*sx,10*sy);
    glVertex2f(193*sx,10*sy);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(190*sx,10*sy);
    glVertex2f(110*sx,20*sy);
    glVertex2f(190*sx,30*sy);
    glVertex2f(270*sx,20*sy);

    glEnd();


    //left
    glBegin(GL_POLYGON);
    glVertex2f(-117*sx,-230*sy);
    glVertex2f(-123*sx,-230*sy);
    glVertex2f(-123*sx,-40*sy);
    glVertex2f(-117*sx,-40*sy);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-193*sx,-230*sy);
    glVertex2f(-187*sx,-230*sy);
    glVertex2f(-187*sx,10*sy);
    glVertex2f(-193*sx,10*sy);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-60*sx,-11*sy);
    glVertex2f(-150*sx,-11*sy);
    glVertex2f(-160*sx,-50*sy);
    glVertex2f(-70*sx,-50*sy);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-190*sx,10*sy);
    glVertex2f(-110*sx,20*sy);
    glVertex2f(-190*sx,30*sy);
    glVertex2f(-270*sx,20*sy);

    glEnd();

    glTranslatef(400*sx,-75*sy,0);


    //Human4

    glTranslatef(-800*sx,-1*sy,0);
    glColor3f(1.0,0.90,0.70);
    DrawCircle(1*sx,110*sy,40*sy,100*sy);//head

    glBegin(GL_POLYGON);
    glColor3f(0.1,0.1,0.1);//hair
    glVertex2f(-40*sx,133*sy);
    glVertex2f(40*sx,133*sy);
    glVertex2f(40*sx,160*sy);
    glVertex2f(30*sx,150*sy);
    glVertex2f(20*sx,160*sy);
    glVertex2f(10*sx,155*sy);
    glVertex2f(1*sx,160*sy);
    glVertex2f(-10*sx,150*sy);
    glVertex2f(-20*sx,160*sy);
    glVertex2f(-30*sx,150*sy);
    glVertex2f(-40*sx,160*sy);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    DrawCircle(17*sx,120*sy,5*sx,100);//eyes

    glColor3f(0.0,0.0,0.0);
    DrawCircle(-17*sx,120*sy,5*sy,100);

    glBegin(GL_POLYGON);
    //Smile
    glVertex2d(-15*sx,100*sy);
    glVertex2d(-1*sx,95*sy);

    glVertex2d(17*sx,100*sy);
    glVertex2d(1*sx,90*sy);
    glVertex2d(-15*sx,100*sy);
    glEnd();

    glColor3f(1.0,0.90,0.70);
    glRectd(-50*sx,75*sy,+50*sx,-75*sy);//body
    glRectd(-80*sx,-55*sy,-50*sx,75*sy);//left arm
    glRectd(50*sx,75*sy,80*sx,-55*sy);//right arm

    glBegin(GL_POLYGON);
    glColor3f(1.,1.,1.);
    glVertex2f(-50*sx,30*sy);
    glVertex2f(-50*sx,-75*sy);
    glVertex2f(50*sx,-75*sy);
    glVertex2f(50*sx,30*sy);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.,1.,1.);
    glVertex2f(-20*sx,30*sy);
    glVertex2f(-30*sx,50*sy);
    glVertex2f(-30*sx,75*sy);
    glVertex2f(-40*sx,75*sy);
    glVertex2f(-40*sx,50*sy);
    glVertex2f(-50*sx,30*sy);
    glVertex2f(50*sx,30*sy);
    glVertex2f(40*sx,50*sy);
    glVertex2f(40*sx,75*sy);
    glVertex2f(30*sx,75*sy);
    glVertex2f(30*sx,50*sy);
    glVertex2f(20*sx,30*sy);


    glEnd();



    glColor3f(0.4,0.6,.8);
    glRectd(-50*sx,-75*sy,-10*sx,-250*sy);//left leg
    glRectd(50*sx,-75*sy,10*sx,-250*sy);//right leg
    glRectd(50*sx,-75*sy,-50*sx,-110*sy);

    //belt
    glColor3f(0.5,0.5,0.1);
    glRectd(50*sx,-75*sy,-50*sx,-55*sy);



    //right foot
    glColor3f(0.,0.,0.);
    glBegin(GL_TRIANGLES);
    glVertex2f(50*sx,-250*sy);
    glVertex2f(10*sx,-250*sy);
    glVertex2f(0*sx,-280*sy);



    //left foot
    glVertex2f(-50*sx,-250*sy);
    glVertex2f(-10*sx,-250*sy);
    glVertex2f(-60*sx,-280*sy);

    glEnd();

    //hand
//hand
    glTranslatef(1*sx,+100*sy,0);
    //Hand Movement
    glPushMatrix();
    glTranslatef(65*sx,-145*sy,0);
    glColor3f(1.0,0.90,0.70);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_POLYGON);

    glVertex2f(-15*sx,30*sy);
    glVertex2f(15*sx,30*sy);
    glVertex2f(10*sx,-20*sy);
    glVertex2f(-10*sx,-20*sy);

    glEnd();




    glTranslatef(-65*sx,+145*sy,0);
    glPopMatrix();

    //GUITAR RIGHT

    glPushMatrix();
    glTranslatef(-30*sx,80*sy,0);

    glRotatef(290+lightangle/6,0,0,1);
    displayguitar(1,1,.6*sx,.6*sy,.5*sx,.5*sx,.5*sx);
    glTranslatef(30*sx,-80*sy,0);
    glPopMatrix();
    //right hand
    glPushMatrix();
    glTranslatef(-65*sx,-145*sy,0);
    glColor3f(1.0,0.90,0.70);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_POLYGON);

    glVertex2f(-15*sx,30*sy);
    glVertex2f(15*sx,30*sy);
    glVertex2f(10*sx,-50*sy);
    glVertex2f(-10*sx,-50*sy);

    glEnd();
    glTranslatef(+65*sx,+145*sy,0);
    glPopMatrix();


    glTranslatef(-1*sx,-100*sy,0);
    glTranslatef(800*sx,+1*sy,0);
    //HUman End








}

//Display BRian MAy
int c=10;
int cou=0;//to give delay
void displayBrian(float tx,float ty,float sx,float sy)
{
    float r,g,b;
    r=g=b=0;

    printf("%d ",c);
    switch(c)
    {
    case 10:
    {
        r=1.0;
        g=0.0;
        b=0.0;
        cou++;
        if(cou==10)
        {
            c=20;
            cou=0;
        }
        break;
    }

    case 20:
    {
        r=1.0;
        g=1.0;
        b=0.0;
        cou++;
        if(cou==10)
        {
            c=30;
            cou=0;
        }
        break;
    }

    case 30:
    {
        r=0.0;
        g=1.0;
        b=0.0;
        cou++;
        if(cou==10)
        {
            c=40;
            cou=0;
        }
        break;
    }

    case 40:
    {
        r=0.0;
        g=1.0;
        b=1.0;
        cou++;
        if(cou==10)
        {
            c=50;
            cou=0;
        }
        break;
    }

    case 50:
    {
        r=0.0;
        g=0.0;
        b=1.0;
        cou++;
        if(cou==10)
        {
            c=60;
            cou=0;
        }
        break;
    }

    case 60:
    {
        r=1.0;
        g=0.0;
        b=1.0;
        cou++;
        if(cou==10)
        {
            c=10;
            cou=0;
        }
        break;
    }


    }




    glColor3f(r/5,g/5,b/5);
    //stage floor

    glBegin(GL_POLYGON);
    glVertex2d(-960*sx,-540*sy);
    glVertex2d(960*sx,-540*sy);
    glColor3f(r/2,g/2,b/2);
    glVertex2d(960*sx,-100*sy);
    glVertex2d(-960*sx,-100*sy);
    glEnd();

    //

    //stage background
    glColor3f(r/2,g/2,b/2);

    glBegin(GL_POLYGON);
    glVertex2d(-960*sx,540*sy);
    glVertex2d(960*sx,540*sy);
    glColor3f(r/5,g/5,b/5);
    glVertex2d(960*sx,-100*sy);
    glVertex2d(-960*sx,-100*sy);
    glEnd();


    //Back Lights
    glPushMatrix();

    glRotatef(lightangle,0,0,1);
    glBegin(GL_TRIANGLES);
    glColor3f(r,g,b);
    glVertex2f(1*sx*5,-100*sy*5);
    glColor3f(r/4,g/4,b/4);
    glVertex2f(-120*sx*5,450*sy*2);
    glVertex2f(+120*sx*5,450*sy*2);
    glEnd();

    glPopMatrix();

    //Human2


    glColor3f(1.0,0.90,0.70);
    DrawCircle(1*sx,110*sy,40*sy,100*sy);//head

    glBegin(GL_POLYGON);
    glColor3f(0.1,0.1,0.1);//hair
    glVertex2f(-40*sx,133*sy);
    glVertex2f(40*sx,133*sy);
    glVertex2f(40*sx,160*sy);
    glVertex2f(30*sx,150*sy);
    glVertex2f(20*sx,160*sy);
    glVertex2f(10*sx,155*sy);
    glVertex2f(1*sx,160*sy);
    glVertex2f(-10*sx,150*sy);
    glVertex2f(-20*sx,160*sy);
    glVertex2f(-30*sx,150*sy);
    glVertex2f(-40*sx,160*sy);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    DrawCircle(17*sx,120*sy,5*sx,100);//eyes

    glColor3f(0.0,0.0,0.0);
    DrawCircle(-17*sx,120*sy,5*sy,100);

    glBegin(GL_POLYGON);
    //Smile
    glVertex2d(-15*sx,100*sy);
    glVertex2d(-1*sx,95*sy);

    glVertex2d(17*sx,100*sy);
    glVertex2d(1*sx,90*sy);
    glVertex2d(-15*sx,100*sy);
    glEnd();

    glColor3f(1.0,0.90,0.70);
    glRectd(-50*sx,75*sy,+50*sx,-75*sy);//body
    glRectd(-80*sx,-55*sy,-50*sx,75*sy);//left arm
    glRectd(50*sx,75*sy,80*sx,-55*sy);//right arm

    glBegin(GL_POLYGON);
    glColor3f(1.,1.,1.);
    glVertex2f(-50*sx,30*sy);
    glVertex2f(-50*sx,-75*sy);
    glVertex2f(50*sx,-75*sy);
    glVertex2f(50*sx,30*sy);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.,1.,1.);
    glVertex2f(-20*sx,30*sy);
    glVertex2f(-30*sx,50*sy);
    glVertex2f(-30*sx,75*sy);
    glVertex2f(-40*sx,75*sy);
    glVertex2f(-40*sx,50*sy);
    glVertex2f(-50*sx,30*sy);
    glVertex2f(50*sx,30*sy);
    glVertex2f(40*sx,50*sy);
    glVertex2f(40*sx,75*sy);
    glVertex2f(30*sx,75*sy);
    glVertex2f(30*sx,50*sy);
    glVertex2f(20*sx,30*sy);


    glEnd();



    glColor3f(0.1,0.1,.1);
    glRectd(-50*sx,-75*sy,-10*sx,-250*sy);//left leg
    glRectd(50*sx,-75*sy,10*sx,-250*sy);//right leg
    glRectd(50*sx,-75*sy,-50*sx,-110*sy);

    //belt
    glColor3f(0.5,0.5,0.1);
    glRectd(50*sx,-75*sy,-50*sx,-55*sy);



    //right foot
    glColor3f(0.,0.,0.);
    glBegin(GL_TRIANGLES);
    glVertex2f(50*sx,-250*sy);
    glVertex2f(10*sx,-250*sy);
    glVertex2f(0*sx,-280*sy);



    //left foot
    glVertex2f(-50*sx,-250*sy);
    glVertex2f(-10*sx,-250*sy);
    glVertex2f(-60*sx,-280*sy);

    glEnd();

    //hand
    //hand
    glTranslatef(1*sx,+100*sy,0);
    //Hand Movement
    glPushMatrix();
    glTranslatef(65*sx,-145*sy,0);
    glColor3f(1.0,0.90,0.70);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_POLYGON);

    glVertex2f(-15*sx,30*sy);
    glVertex2f(15*sx,30*sy);
    glVertex2f(10*sx,-30*sy);
    glVertex2f(-10*sx,-30*sy);

    glEnd();
    glTranslatef(-65*sx,+145*sy,0);
    glPopMatrix();


    //GUITAR RIGHT

    glPushMatrix();
    glTranslatef(-30*sx,70*sy,0);

    glRotatef(290+lightangle/6,0,0,1);
    displayguitar(1,1,.6*sx,.6*sy,.5*sy,.5*sy,.5*sy);
    glTranslatef(30*sx,-70*sy,0);
    glPopMatrix();

    //left handing moving
    glPushMatrix();
    glTranslatef(-65*sx,-145*sy,0);
    glColor3f(1.0,0.90,0.70);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_POLYGON);

    glVertex2f(-15*sx,30*sy);
    glVertex2f(15*sx,30*sy);
    glVertex2f(10*sx,-50*sy);
    glVertex2f(-10*sx,-50*sy);

    glEnd();
    glTranslatef(+65*sx,+145*sy,0);
    glPopMatrix();


    glTranslatef(-1*sx,-100*sy,0);


    //HUman End




}
void justlights(float tx,float ty,float sx,float sy)
{

    float r,g,b;
    r=g=b=0;

    printf("%d ",c);
    switch(c)
    {
    case 10:
    {
        r=1.0;
        g=0.0;
        b=0.0;
        cou++;
        if(cou==10)
        {
            c=20;
            cou=0;
        }
        break;
    }

    case 20:
    {
        r=1.0;
        g=1.0;
        b=0.0;
        cou++;
        if(cou==10)
        {
            c=30;
            cou=0;
        }
        break;
    }

    case 30:
    {
        r=0.0;
        g=1.0;
        b=0.0;
        cou++;
        if(cou==10)
        {
            c=40;
            cou=0;
        }
        break;
    }

    case 40:
    {
        r=0.0;
        g=1.0;
        b=1.0;
        cou++;
        if(cou==10)
        {
            c=50;
            cou=0;
        }
        break;
    }

    case 50:
    {
        r=0.0;
        g=0.0;
        b=1.0;
        cou++;
        if(cou==10)
        {
            c=60;
            cou=0;
        }
        break;
    }

    case 60:
    {
        r=1.0;
        g=0.0;
        b=1.0;
        cou++;
        if(cou==10)
        {
            c=10;
            cou=0;
        }
        break;
    }


    }

    //Back Lights
    glPushMatrix();
    glTranslatef(-800*sx+tx,1*sy+ty,0);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_TRIANGLES);
    glColor3f(r,g,b);
    glVertex2f(1*sx,-100*sy);
    glColor3f(r/4,g/4,b/4);
    glVertex2f(-120*sx,450*sy);
    glVertex2f(+120*sx,450*sy);
    glEnd();
    glTranslatef(800*sx-tx,1*sy-ty,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-400*sx+tx,1*sy+ty,0);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_TRIANGLES);
    glColor3f(r,g,b);
    glVertex2f(1*sx,-100*sy);
    glColor3f(r/4,g/4,b/4);
    glVertex2f(-120*sx,450*sy);
    glVertex2f(+120*sx,450*sy);
    glEnd();
    glTranslatef(+400*sx-tx,1*sy-ty,0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(1*sx+tx,1*sy+ty,0);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_TRIANGLES);
    glColor3f(r,g,b);
    glVertex2f(1*sx,-100*sy);
    glColor3f(r/4,g/4,b/4);
    glVertex2f(-120*sx,450*sy);
    glVertex2f(+120*sx,450*sy);
    glEnd();
    glTranslatef(1*sx-tx,1*sy-ty,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(400*sx+tx,1*sy+ty,0);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_TRIANGLES);
    glColor3f(r,g,b);
    glVertex2f(1*sx,-100*sy);
    glColor3f(r/4,g/4,b/4);
    glVertex2f(-120*sx,450*sy);
    glVertex2f(+120*sx,450*sy);
    glEnd();
    glTranslatef(-400*sx-tx,1*sy-ty,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(800*sx+tx,1*sy+ty,0);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_TRIANGLES);
    glColor3f(r,g,b);
    glVertex2f(1*sx,-100*sy);
    glColor3f(r/4,g/4,b/4);
    glVertex2f(-120*sx,450*sy);
    glVertex2f(+120*sx,450*sy);
    glEnd();
    glTranslatef(-800*sx-tx,1*sy-ty,0);
    glPopMatrix();




}

//Stage

void stage(float tx,float ty,float sx,float sy)
{

    float r,g,b;
    r=g=b=0;

    printf("%d ",c);
    switch(c)
    {
    case 10:
    {
        r=1.0;
        g=0.0;
        b=0.0;
        cou++;
        if(cou==10)
        {
            c=20;
            cou=0;
        }
        break;
    }

    case 20:
    {
        r=1.0;
        g=1.0;
        b=0.0;
        cou++;
        if(cou==10)
        {
            c=30;
            cou=0;
        }
        break;
    }

    case 30:
    {
        r=0.0;
        g=1.0;
        b=0.0;
        cou++;
        if(cou==10)
        {
            c=40;
            cou=0;
        }
        break;
    }

    case 40:
    {
        r=0.0;
        g=1.0;
        b=1.0;
        cou++;
        if(cou==10)
        {
            c=50;
            cou=0;
        }
        break;
    }

    case 50:
    {
        r=0.0;
        g=0.0;
        b=1.0;
        cou++;
        if(cou==10)
        {
            c=60;
            cou=0;
        }
        break;
    }

    case 60:
    {
        r=1.0;
        g=0.0;
        b=1.0;
        cou++;
        if(cou==10)
        {
            c=10;
            cou=0;
        }
        break;
    }


    }




    glColor3f(r/5,g/5,b/5);
    //stage floor

    glBegin(GL_POLYGON);
    glVertex2d(-960*sx,-540*sy);
    glVertex2d(960*sx,-540*sy);
    glColor3f(r/2,g/2,b/2);
    glVertex2d(960*sx,-100*sy);
    glVertex2d(-960*sx,-100*sy);
    glEnd();

    //

    //stage background
    glColor3f(r/2,g/2,b/2);

    glBegin(GL_POLYGON);
    glVertex2d(-960*sx,540*sy);
    glVertex2d(960*sx,540*sy);
    glColor3f(r/5,g/5,b/5);
    glVertex2d(960*sx,-100*sy);
    glVertex2d(-960*sx,-100*sy);
    glEnd();


    //Back Lights
    glPushMatrix();
    glTranslatef(-800*sx,1*sy,0);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_TRIANGLES);
    glColor3f(r,g,b);
    glVertex2f(1*sx,-100*sy);
    glColor3f(r/4,g/4,b/4);
    glVertex2f(-120*sx,450*sy);
    glVertex2f(+120*sx,450*sy);
    glEnd();
    glTranslatef(800*sx,1*sy,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-400*sx,1*sy,0);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_TRIANGLES);
    glColor3f(r,g,b);
    glVertex2f(1*sx,-100*sy);
    glColor3f(r/4,g/4,b/4);
    glVertex2f(-120*sx,450*sy);
    glVertex2f(+120*sx,450*sy);
    glEnd();
    glTranslatef(+400*sx,1*sy,0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(1*sx,1*sy,0);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_TRIANGLES);
    glColor3f(r,g,b);
    glVertex2f(1*sx,-100*sy);
    glColor3f(r/4,g/4,b/4);
    glVertex2f(-120*sx,450*sy);
    glVertex2f(+120*sx,450*sy);
    glEnd();
    glTranslatef(1*sx,1*sy,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(400*sx,1*sy,0);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_TRIANGLES);
    glColor3f(r,g,b);
    glVertex2f(1*sx,-100*sy);
    glColor3f(r/4,g/4,b/4);
    glVertex2f(-120*sx,450*sy);
    glVertex2f(+120*sx,450*sy);
    glEnd();
    glTranslatef(-400*sx,1*sy,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(800*sx,1*sy,0);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_TRIANGLES);
    glColor3f(r,g,b);
    glVertex2f(1*sx,-100*sy);
    glColor3f(r/4,g/4,b/4);
    glVertex2f(-120*sx,450*sy);
    glVertex2f(+120*sx,450*sy);
    glEnd();
    glTranslatef(-800*sx,1*sy,0);
    glPopMatrix();















}

















void displayhandg()
{

    Sleep(450);
    if(time==0)
    {
        PlaySound("D://Codeblock//thriller.wav",NULL,SND_LOOP|SND_ASYNC);
        time++;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.5,0.0,0.0,1.0);
    switch(time)
    {
    case 1:
    {
        glClearColor(0.5,0.0,0.0,1.0);
        time++;
        break;

    }
    case 2:
    {
        glClearColor(0.0,0.5,0.0,1.0);
        time++;
        break;

    }
    case 3:
    {
        glClearColor(0.0,0.0,0.5,1.0);
        time++;
        break;

    }
    case 4:
    {
        glClearColor(1.0,1.,0.,1.0);
        time++;
        break;

    }
    case 5:
    {
        glClearColor(0.2,0.4,0.6,1.0);
        time++;
        break;

    }
    case 6:
    {
        glClearColor(1.,0.,1.0,1.0);
        time++;
        break;
    }
    case 7:
    {
        glClearColor(1.,0.,0.3,0.0);
        time++;
        break;
    }
    case 8:
    {
        glClearColor(0.2,0.,0.0,1.0);
        time++;
        break;
    }
    case 9:
    {
        glClearColor(0.,0.,1.0,1.0);
        time++;
        break;
    }
    case 10:
    {
        glClearColor(1.,1.,0.0,1.0);
        disp=3;
        break;
    }
    }

    float SX=1,SY=1;
    float ty=0;
    float tx=0;
    //Human
    glColor3f(1.0,0.90,0.70);
    DrawCircle(-330,140,40,100);//head
    glBegin(GL_POLYGON);
    glColor3f(0.43,0.24,0.07);//hair
    glVertex2f(-370,160);
    glVertex2f(-290,160);
    glVertex2f(-290,190);
    glVertex2f(-300,180);
    glVertex2f(-310,190);
    glVertex2f(-320,180);
    glVertex2f(-330,190);
    glVertex2f(-340,180);
    glVertex2f(-350,190);
    glVertex2f(-360,180);
    glVertex2f(-370,190);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    DrawCircle(-313,150,5,100);//eyes

    glColor3f(0.0,0.0,0.0);
    DrawCircle(-347,150,5,100);

    glBegin(GL_POLYGON);
    //Smile
    glVertex2d(-345,125);
    glVertex2d(-330,115);

    glVertex2d(-317,125);
    glVertex2d(-330,120);
    glVertex2d(-345,125);
    glEnd();

    glColor3f(01.0,0.0,0.0);
    glRectd(-390,100,-270,-50);//body
    glRectd(-390,100,-415,-10);//left arm
    glRectd(-270,100,-245,-10);//right arm

    glColor3f(0.,0.,0.);
    glRectd(-375,-50,-345,-200);//left leg
    glRectd(-285,-50,-315,-200);//right leg
    glRectd(-375,-50,-285,-80);

    //innerCoat
    glRectd(-360,98,-300,-50);

    //right foot
    glBegin(GL_TRIANGLES);
    glVertex2f(-345,-200);
    glVertex2f(-375,-200);
    glVertex2f(-390,-230);



    //left foot
    glVertex2f(-285,-200);
    glVertex2f(-315,-200);
    glVertex2f(-330,-230);

    glEnd();

    //hand
    glBegin(GL_POLYGON);
    glVertex2f(-390,-10);
    glVertex2f(-390,-30);
    glVertex2f(-413,-10);

    glVertex2f(-413,-30);
    glEnd();
    //right hand
    glBegin(GL_POLYGON);
    glVertex2f(-270,-10);
    glVertex2f(-270,-30);
    glVertex2f(-247,-10);

    glVertex2f(-247,-30);
    glEnd();

    //HUman End


    //(6.09,5.80), (9.39,0.44), (5.96,2.38), (2.73,0.84)
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    SX=50;
    SY=60;
    tx=90;
    ty=-370;

    glVertex2f(2.73*SX+tx,0.84*SY+ty);
    glVertex2f(6.09*SX+tx,5.80*SY+ty);
//      glVertex2f(9.07*SX+tx,0.36*SY+ty);
    glVertex2f(5.83*SX+tx,2.25*SY+ty);
    glVertex2f(2.73*SX+tx,0.84*SY+ty);
    glEnd();

    glBegin(GL_POLYGON);
    SX=50;
    SY=60;
    tx=90;
    ty=-370;

//      glVertex2f(2.73*SX+tx,0.84*SY+ty);
    glVertex2f(6.09*SX+tx,5.80*SY+ty);
    glVertex2f(9.07*SX+tx,0.36*SY+ty);
    glVertex2f(5.83*SX+tx,2.25*SY+ty);
    glVertex2f(2.73*SX+tx,0.84*SY+ty);
    glEnd();


    glFlush();

    //(4.00,1.00), (5.00,1.00), (5.00,9.00), (4.00,9.00) NECK
    glColor3f(0.59,0.29,0.00);
    glBegin(GL_POLYGON);
    SX=30;
    SY=30;
    tx=260;
    ty=-130;
    glVertex2f(4.00*SX+tx,1.00*SY+ty);
    glVertex2f(5.00*SX+tx,1.00*SY+ty);
    glVertex2f(5.00*SX+tx,13.00*SY+ty);
    glVertex2f(4.00*SX+tx,13.00*SY+ty);
    glVertex2f(4.00*SX+tx,1.00*SY+ty);
    glEnd();
    glFlush();

    //(4.50,3.35), (7.42,6.74), (6.00,1.00), (5.00,1.00)
    glColor3f(1.0,0.0,0.00);
    glBegin(GL_POLYGON);
    SX=30;
    SY=30;
    int wi=0;
    tx=230;
    ty=180;
    glVertex2f(5.00*SX+tx,1.00*SY+ty);
    glVertex2f(4.50*SX+tx,3.35*SY+ty);
    glVertex2f(7.42*SX+tx,6.74*SY+ty);
    glVertex2f(6.00*SX+tx,1.00*SY+ty);
    glVertex2f(5.00*SX+tx,1.00*SY+ty);
    glEnd();
    glFlush();

    //rgb(0.76,0.76,0.76)
    //

    SX=30;
    SY=30;
    tx=230;
    ty=-120;

    float m=8;

    for( int i=0 ; i <14 ; i++)
    {

        if(i==4)
            m=5;
        else if(i==6)
            m=4;
        else if(i==8)
            m=3;
        else if(i==10)
            m=2;

        ty=ty+i*m;
        glColor3f(0.80,0.80,0.00);

        glBegin(GL_POLYGON);
        glVertex2f(6.00*SX+tx,1.00*SY+ty);
        glVertex2f(5.00*SX+tx,1.00*SY+ty);
        glVertex2f(5.00*SX+tx,0.85*SY+ty);
        glVertex2f(6.00*SX+tx,0.85*SY+ty);
        glVertex2f(6.00*SX+tx,1.00*SY+ty);
        glEnd();
        glFlush();
    }

    //rgb(0.80,0.80,0.00)
    glColor3f(0.76,0.76,0.76);
    tx=tx+145;
    ty=ty+110;

    for(int i =0 ; i< 6 ; i++)
    {

        DrawCircle(tx,ty,6,12);
        glFlush();
        tx=tx+12;
        ty=ty+13;
    }

    //rgb(1.00,1.00,0.30) KNOBS
    tx=450;
    ty=-200;
    glColor3f(1.00,1.00,0.30);
    DrawCircle(tx,ty,10,12);
    glFlush();
    tx=460;
    ty=-230;
    glColor3f(1.00,1.00,0.30);
    DrawCircle(tx,ty,10,12);
    glFlush();

    //pickups ( pickups and bridge have relative pos )
    SX=15;
    SY=10;
    tx=tx-135;
    ty=ty+80;
    glColor3f(0.61,0.61,0.65);
    glBegin(GL_POLYGON);
    glVertex2f(3.00*SX+tx,3.00*SY+ty);
    glVertex2f(6.00*SX+tx,3.00*SY+ty);
    glVertex2f(6.00*SX+tx,1.00*SY+ty);
    glVertex2f(3.00*SX+tx,1.00*SY+ty);
    glVertex2f(3.00*SX+tx,3.00*SY+ty);
    glEnd();
    glFlush();
    int j=0;
    for(j=1; j<7; j++)
    {
        glColor3f(0.30,0.30,0.32);
        DrawCircle(370+j*7,-130,2,10);
        glFlush();
    }


    ty=ty-40;
    glColor3f(0.61,0.61,0.65);
    glBegin(GL_POLYGON);
    glVertex2f(3.00*SX+tx,3.00*SY+ty);
    glVertex2f(6.00*SX+tx,3.00*SY+ty);
    glVertex2f(6.00*SX+tx,1.00*SY+ty);
    glVertex2f(3.00*SX+tx,1.00*SY+ty);
    glVertex2f(3.00*SX+tx,3.00*SY+ty);
    glEnd();
    glFlush();
    for(j=1; j<7; j++)
    {
        glColor3f(0.30,0.30,0.32);
        DrawCircle(370+j*7,-170,2,10);
        glFlush();
    }
    // BRIDGE
    ty=ty-20;
    glBegin(GL_POLYGON);
    glVertex2f(3.00*SX+tx,2.00*SY+ty);
    glVertex2f(6.00*SX+tx,2.00*SY+ty);
    glVertex2f(6.00*SX+tx,1.00*SY+ty);
    glVertex2f(3.00*SX+tx,1.00*SY+ty);
    glVertex2f(3.00*SX+tx,2.00*SY+ty);
    glEnd();
    glFlush();

    // STRINGS

    glColor3f(0.87,0.87,0.87);
    SX=30;
    SY=30;
    tx=232;
    ty=-180;
    for(j=1; j<7; j++)
    {

        glBegin(GL_LINES);
        glVertex2f(5.00*SX+tx,-1.00*SY+ty);
        glVertex2f(5.00*SX+tx,13.00*SY+ty);
        glEnd();
        glFlush();
        tx=tx+5;
    }

}



void displayguitar(float tx, float ty, float SX, float SY, float rx, float ct, float st )
{

    glColor3f(0.6,0.0,0.6);
    glBegin(GL_POLYGON);
// PART : triangle 1
    glVertex2f(226.5*SX + tx,-319.6*SY + ty );
    glVertex2f(394.5*SX + tx,-22*SY + ty );
    glVertex2f(381.5*SX + tx,-235*SY + ty );
    glVertex2f(226.5*SX + tx,-319.6*SY + ty );
    glEnd();
    glBegin(GL_POLYGON);
// PART : triangle 2
    glVertex2f(394.5*SX + tx,-22*SY + ty );
    glVertex2f(543.5*SX + tx,-348.4*SY + ty );
    glVertex2f(381.5*SX + tx,-235*SY + ty );
    glVertex2f(226.5*SX + tx,-319.6*SY + ty );
    glEnd();
    glColor3f(0.59,0.29,0.00);
    glBegin(GL_POLYGON);
// PART : neck
    glVertex2f(380*SX + tx,-100*SY + ty );
    glVertex2f(410*SX + tx,-100*SY + ty );
    glVertex2f(410*SX + tx,260*SY + ty );
    glVertex2f(380*SX + tx,260*SY + ty );
    glVertex2f(380*SX + tx,-100*SY + ty );
    glEnd();
    glColor3f(0.6,0.0,0.6);
    glBegin(GL_POLYGON);
// PART : head
    glVertex2f(380*SX + tx,210*SY + ty );
    glVertex2f(365*SX + tx,280.5*SY + ty );
    glVertex2f(452.6*SX + tx,382.2*SY + ty );
    glVertex2f(410*SX + tx,210*SY + ty );
    glVertex2f(380*SX + tx,210*SY + ty );
    glEnd();
    glColor3f(0.80,0.80,0.00);
    glBegin(GL_POLYGON);
// PART : fret
    glVertex2f(410*SX + tx,-90*SY + ty );
    glVertex2f(380*SX + tx,-90*SY + ty );
    glVertex2f(380*SX + tx,-94.5*SY + ty );
    glVertex2f(410*SX + tx,-94.5*SY + ty );
    glVertex2f(410*SX + tx,-90*SY + ty );
    glEnd();
    glColor3f(0.80,0.80,0.00);
    glBegin(GL_POLYGON);
    glVertex2f(410*SX + tx,-82*SY + ty );
    glVertex2f(380*SX + tx,-82*SY + ty );
    glVertex2f(380*SX + tx,-86.5*SY + ty );
    glVertex2f(410*SX + tx,-86.5*SY + ty );
    glVertex2f(410*SX + tx,-82*SY + ty );
    glEnd();
    glColor3f(0.80,0.80,0.00);
    glBegin(GL_POLYGON);
    glVertex2f(410*SX + tx,-66*SY + ty );
    glVertex2f(380*SX + tx,-66*SY + ty );
    glVertex2f(380*SX + tx,-70.5*SY + ty );
    glVertex2f(410*SX + tx,-70.5*SY + ty );
    glVertex2f(410*SX + tx,-66*SY + ty );
    glEnd();
    glColor3f(0.80,0.80,0.00);
    glBegin(GL_POLYGON);
    glVertex2f(410*SX + tx,-42*SY + ty );
    glVertex2f(380*SX + tx,-42*SY + ty );
    glVertex2f(380*SX + tx,-46.5*SY + ty );
    glVertex2f(410*SX + tx,-46.5*SY + ty );
    glVertex2f(410*SX + tx,-42*SY + ty );
    glEnd();
    glColor3f(0.80,0.80,0.00);
    glBegin(GL_POLYGON);
    glVertex2f(410*SX + tx,-22*SY + ty );
    glVertex2f(380*SX + tx,-22*SY + ty );
    glVertex2f(380*SX + tx,-26.5*SY + ty );
    glVertex2f(410*SX + tx,-26.5*SY + ty );
    glVertex2f(410*SX + tx,-22*SY + ty );
    glEnd();
    glColor3f(0.80,0.80,0.00);
    glBegin(GL_POLYGON);
    glVertex2f(410*SX + tx,3*SY + ty );
    glVertex2f(380*SX + tx,3*SY + ty );
    glVertex2f(380*SX + tx,-1.5*SY + ty );
    glVertex2f(410*SX + tx,-1.5*SY + ty );
    glVertex2f(410*SX + tx,3*SY + ty );
    glEnd();
    glColor3f(0.80,0.80,0.00);
    glBegin(GL_POLYGON);
    glVertex2f(410*SX + tx,27*SY + ty );
    glVertex2f(380*SX + tx,27*SY + ty );
    glVertex2f(380*SX + tx,22.5*SY + ty );
    glVertex2f(410*SX + tx,22.5*SY + ty );
    glVertex2f(410*SX + tx,27*SY + ty );
    glEnd();
    glColor3f(0.80,0.80,0.00);
    glBegin(GL_POLYGON);
    glVertex2f(410*SX + tx,55*SY + ty );
    glVertex2f(380*SX + tx,55*SY + ty );
    glVertex2f(380*SX + tx,50.5*SY + ty );
    glVertex2f(410*SX + tx,50.5*SY + ty );
    glVertex2f(410*SX + tx,55*SY + ty );
    glEnd();
    glColor3f(0.80,0.80,0.00);
    glBegin(GL_POLYGON);
    glVertex2f(410*SX + tx,79*SY + ty );
    glVertex2f(380*SX + tx,79*SY + ty );
    glVertex2f(380*SX + tx,74.5*SY + ty );
    glVertex2f(410*SX + tx,74.5*SY + ty );
    glVertex2f(410*SX + tx,79*SY + ty );
    glEnd();
    glColor3f(0.80,0.80,0.00);
    glBegin(GL_POLYGON);
    glVertex2f(410*SX + tx,106*SY + ty );
    glVertex2f(380*SX + tx,106*SY + ty );
    glVertex2f(380*SX + tx,101.5*SY + ty );
    glVertex2f(410*SX + tx,101.5*SY + ty );
    glVertex2f(410*SX + tx,106*SY + ty );
    glEnd();
    glColor3f(0.80,0.80,0.00);
    glBegin(GL_POLYGON);
    glVertex2f(410*SX + tx,126*SY + ty );
    glVertex2f(380*SX + tx,126*SY + ty );
    glVertex2f(380*SX + tx,121.5*SY + ty );
    glVertex2f(410*SX + tx,121.5*SY + ty );
    glVertex2f(410*SX + tx,126*SY + ty );
    glEnd();
    glColor3f(0.80,0.80,0.00);
    glBegin(GL_POLYGON);
    glVertex2f(410*SX + tx,148*SY + ty );
    glVertex2f(380*SX + tx,148*SY + ty );
    glVertex2f(380*SX + tx,143.5*SY + ty );
    glVertex2f(410*SX + tx,143.5*SY + ty );
    glVertex2f(410*SX + tx,148*SY + ty );
    glEnd();
    glColor3f(0.80,0.80,0.00);
    glBegin(GL_POLYGON);
    glVertex2f(410*SX + tx,172*SY + ty );
    glVertex2f(380*SX + tx,172*SY + ty );
    glVertex2f(380*SX + tx,167.5*SY + ty );
    glVertex2f(410*SX + tx,167.5*SY + ty );
    glVertex2f(410*SX + tx,172*SY + ty );
    glEnd();
    glColor3f(0.80,0.80,0.00);
    glBegin(GL_POLYGON);
    glVertex2f(410*SX + tx,198*SY + ty );
    glVertex2f(380*SX + tx,198*SY + ty );
    glVertex2f(380*SX + tx,193.5*SY + ty );
    glVertex2f(410*SX + tx,193.5*SY + ty );
    glVertex2f(410*SX + tx,198*SY + ty );
    glEnd();
    glColor3f(0.80,0.80,0.00);
//PART : tuning head
    DrawCircle(375*SX + tx,278*SY +ty,6*rx,12);
    DrawCircle(387*SX + tx,291*SY +ty,6*rx,12);
    DrawCircle(399*SX + tx,304*SY +ty,6*rx,12);
    DrawCircle(411*SX + tx,317*SY +ty,6*rx,12);
    DrawCircle(423*SX + tx,330*SY +ty,6*rx,12);
    DrawCircle(435*SX + tx,343*SY +ty,6*rx,12);
    glColor3f(1.00,1.00,0.30);
//PART : knob 1
    DrawCircle(450*SX + tx,-200*SY +ty,10*rx,12);
//PART : knob 2
    DrawCircle(460*SX + tx,-230*SY +ty,10*rx,12);
    glColor3f(0.61,0.61,0.65);
    glBegin(GL_POLYGON);
// PART : pickup 1
    glVertex2f(370*SX + tx,-120*SY + ty );
    glVertex2f(415*SX + tx,-120*SY + ty );
    glVertex2f(415*SX + tx,-140*SY + ty );
    glVertex2f(370*SX + tx,-140*SY + ty );
    glVertex2f(370*SX + tx,-120*SY + ty );
    glEnd();
    glColor3f(0.30,0.30,0.32);
//PART :  pickup screws
    DrawCircle(377*SX + tx,-130*SY +ty,2*rx,10);
    DrawCircle(384*SX + tx,-130*SY +ty,2*rx,10);
    DrawCircle(391*SX + tx,-130*SY +ty,2*rx,10);
    DrawCircle(398*SX + tx,-130*SY +ty,2*rx,10);
    DrawCircle(405*SX + tx,-130*SY +ty,2*rx,10);
    DrawCircle(412*SX + tx,-130*SY +ty,2*rx,10);
    glColor3f(0.61,0.61,0.65);
    glBegin(GL_POLYGON);
// PART : pickup 2
    glVertex2f(370*SX + tx,-160*SY + ty );
    glVertex2f(415*SX + tx,-160*SY + ty );
    glVertex2f(415*SX + tx,-180*SY + ty );
    glVertex2f(370*SX + tx,-180*SY + ty );
    glVertex2f(370*SX + tx,-160*SY + ty );
    glEnd();
    glColor3f(0.30,0.30,0.32);
//PART : pickup screws 2
    DrawCircle(377*SX + tx,-170*SY +ty,2*rx,10);
    DrawCircle(384*SX + tx,-170*SY +ty,2*rx,10);
    DrawCircle(391*SX + tx,-170*SY +ty,2*rx,10);
    DrawCircle(398*SX + tx,-170*SY +ty,2*rx,10);
    DrawCircle(405*SX + tx,-170*SY +ty,2*rx,10);
    DrawCircle(412*SX + tx,-170*SY +ty,2*rx,10);
    glColor3f(0.61,0.21,0.25);
    glBegin(GL_POLYGON);
// PART : bridge
    glVertex2f(370*SX + tx,-190*SY + ty );
    glVertex2f(415*SX + tx,-190*SY + ty );
    glVertex2f(415*SX + tx,-200*SY + ty );
    glVertex2f(370*SX + tx,-200*SY + ty );
    glVertex2f(370*SX + tx,-190*SY + ty );
    glEnd();
    glColor3f(0.61,0.61,0.65);
    glBegin(GL_LINES);
// PART : strings
    glVertex2f(382*SX + tx,-210*SY + ty );
    glVertex2f(382*SX + tx,210*SY + ty );
    glEnd();
    glColor3f(0.61,0.61,0.65);
    glBegin(GL_LINES);
    glVertex2f(387*SX + tx,-210*SY + ty );
    glVertex2f(387*SX + tx,210*SY + ty );
    glEnd();
    glColor3f(0.61,0.61,0.65);
    glBegin(GL_LINES);
    glVertex2f(392*SX + tx,-210*SY + ty );
    glVertex2f(392*SX + tx,210*SY + ty );
    glEnd();
    glColor3f(0.61,0.61,0.65);
    glBegin(GL_LINES);
    glVertex2f(397*SX + tx,-210*SY + ty );
    glVertex2f(397*SX + tx,210*SY + ty );
    glEnd();
    glColor3f(0.61,0.61,0.65);
    glBegin(GL_LINES);
    glVertex2f(402*SX + tx,-210*SY + ty );
    glVertex2f(402*SX + tx,210*SY + ty );
    glEnd();
    glColor3f(0.61,0.61,0.65);
    glBegin(GL_LINES);
    glVertex2f(407*SX + tx,-210*SY + ty );
    glVertex2f(407*SX + tx,210*SY + ty );
    glEnd();

}
void displayhouse()
{

    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0,0.0,1.0);

    //Background Home Ground
    glColor3f(0.09,0.70,0.30);
    glBegin(GL_POLYGON);
    glVertex2d(-960,-540);
    glVertex2d(960,-540);
    glVertex2d(960,-100);
    glVertex2d(-960,-100);
    glEnd();

    //

    //Sky

    glColor3f(0.05,0.70,1.0);
    glBegin(GL_POLYGON);
    glVertex2d(-960,540);
    glVertex2d(960,540);
    glVertex2d(960,-100);
    glVertex2d(-960,-100);
    glEnd();




    //Chimney
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2d(170*sx+x,380*sy+y);
    glVertex2d(240*sx+x,380*sy+y);
    glVertex2d(240*sx+x,100*sy+y);
    glVertex2d(170*sx+x,100*sy+y);
    glEnd();



    //Home 428  501Cursor Position at 769  500
    glColor3f(0.60,00.30,0.10);
    glBegin(GL_POLYGON);
    glVertex2d(-320*sx+x,-320*sy+y);
    glVertex2d(320*sx+x,-320*sy+y);
    glVertex2d(320*sx+x,120*sy+y);
    glVertex2d(0*sx,450*sy+y);
    glVertex2d(-320*sx+x,120*sy+y);
    glEnd();


    //Windows
    //left
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-150*sx+x,-80*sy+y);
    glVertex2d(-270*sx+x,-80*sy+y);
    glVertex2d(-270*sx+x,60*sy+y);
    glVertex2d(-150*sx+x,60*sy+y);
    glEnd();
    //glass
    glColor3f(0.40,0.80,.80);
    glBegin(GL_POLYGON);
    glVertex2d(-165*sx+x,-65*sy+y);
    glVertex2d(-255*sx+x,-65*sy+y);
    glVertex2d(-255*sx+x,45*sy+y);
    glVertex2d(-165*sx+x,45*sy+y);
    glEnd();

    //right
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2d(150*sx+x,-80*sy+y);
    glVertex2d(270*sx+x,-80*sy+y);
    glVertex2d(270*sx+x,60*sy+y);
    glVertex2d(150*sx+x,60*sy+y);
    glEnd();
    //glass
    glColor3f(0.40,0.80,.80);
    glBegin(GL_POLYGON);
    glVertex2d(165*sx+x,-65*sy+y);
    glVertex2d(255*sx+x,-65*sy+y);
    glVertex2d(255*sx+x,45*sy+y);
    glVertex2d(165*sx+x,45*sy+y);
    glEnd();

    //Door
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-100*sx+x,-320*sy+y);
    glVertex2d(100*sx+x,-320*sy+y);
    glVertex2d(100*sx+x,-100*sy+y);
    glVertex2d(-100*sx+x,-100*sy+y);
    glEnd();

    glColor3f(0.90,0.80,0.40);
    glBegin(GL_POLYGON);
    glVertex2d(-80*sx+x,-320*sy+y);
    glVertex2d(80*sx+x,-320*sy+y);
    glVertex2d(80*sx+x,-120*sy+y);
    glVertex2d(-80*sx+x,-120*sy+y);
    glEnd();


    //Roof
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    //left
    glVertex2d(0*sx,450*sy+y);
    glVertex2d(0*sx,490*sy+y);
    glVertex2d(-350*sx+x,120*sy+y);
    glVertex2d(-350*sx+x,80*sy+y);
    //right
    glVertex2d(0*sx,450*sy+y);
    glVertex2d(0*sx,490*sy+y);
    glVertex2d(350*sy+x,120*sy+y);
    glVertex2d(350*sy+x,80*sy+y);
    glEnd();
//    glFlush();
//       glutSwapBuffers();

}

//Man and Father scene 2
float S_ANGLE=0;
void display_fatson(float tx,float ty,float sx,float sy)
{



    float lf=-400;
    float bf=450;
    //Father


    // Body

    //Hands
    glPushMatrix();
    glTranslatef(((bf+20)*sx+tx),((lf+440)*sy+ty),0);

    glColor3f(1.0,0.0,0.0);
    if(ta==ta_max)
    {
        glRotatef(-35,0,0,1);
        glColor3f(1.0,1.0,1.0);
        glBegin(GL_POLYGON); //CONCERT TICKET
        glVertex2f(-5,-220);
        glVertex2f(+10,-260);
        glVertex2f(+10,0);
        glVertex2f(-5,50);
        glEnd();
        glColor3f(1.0,0.0,0.0);
    }

    glRotatef(-S_ANGLE,0,0,1);
    glRectf((-15)*sx,(1)*sy,(15)*sx,(-50)*sy);
    glColor3f(1.0,0.90,0.70);
    glRectf((-15)*sx,(-50)*sy,(15)*sx,(-200)*sy);
    glTranslatef(-((bf+20)*sx+tx),(-(lf+440)*sy+ty),0);
    glPopMatrix();

    //Legs
    glColor3f(0.0,0.0,0.0);
    //1st Leg
    glPushMatrix();



    glTranslatef(((bf+20)*sx+tx), ((lf+250)*sy+ty),0);

    glRotatef(-S_ANGLE, 0, 0, 1);
    glRectf(-15*sx,1*sy,(15)*sx,(-250)*sy);

    glTranslatef(-((bf+20)*sx+tx), (-(lf+250)*sy+ty),0);


    glPopMatrix();

    //2nd Leg
    glPushMatrix();



    glTranslatef(((bf+20)*sx+tx), ((lf+250)*sy+ty),0);

    glRotatef(+S_ANGLE, 0, 0, 1);
    glRectf(-15*sx,1*sy,(15)*sx,(-250)*sy);

    glTranslatef(-((bf+20)*sx+tx), (-(lf+250)*sy+ty),0);


    glPopMatrix();


    //other hand
    glPushMatrix();
    glTranslatef(((bf+20)*sx+tx),((lf+440)*sy+ty),0);
    //body
    glColor3f(1.0,0.0,0.0);

    glRectf((-20)*sx,(1)*sy,(20)*sx,(-200)*sy);
    glColor3f(1.0,0.0,0.0);
    glRotatef(S_ANGLE,0,0,1);
    glRectf((-15)*sx,(1)*sy,(15)*sx,(-50)*sy);
    glColor3f(1.0,0.90,0.70);
    glRectf((-15)*sx,(-50)*sy,(15)*sx,(-200)*sy);

    glTranslatef(-((bf+20)*sx+tx),(-(lf+440)*sy+ty),0);
    glPopMatrix();

    //Head
    glPushMatrix();
    glTranslatef(((bf+20)*sx+tx),((lf+440)*sy+ty),0);
    glColor3f(1.0,0.90,0.70);
    DrawCircle(0,45,45,100);

    glBegin(GL_POLYGON);
    glColor3f(0.43,0.24,0.07);//hair
    glVertex2f(-40*sx,70*sy);
    glVertex2f(40*sx,70*sy);
    glVertex2f(40*sx,115*sy);
    glVertex2f(30*sx,105*sy);
    glVertex2f(20*sx,115*sy);
    glVertex2f(10*sx,105*sy);
    glVertex2f(1*sx,115*sy);
    glVertex2f(-10*sx,105*sy);
    glVertex2f(-20*sx,115*sy);
    glVertex2f(-30*sx,105*sy);
    glVertex2f(-40*sx,115*sy);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    DrawCircle(-32,45,7,100);//eyes
    glBegin(GL_POLYGON);
    glVertex2f(-33,15);
    glVertex2f(-25,15);
    glVertex2f(-15,25);
    glVertex2f(-25,15);
    glVertex2f(-33,15);
    glEnd();
    glTranslatef(-((bf+20)*sx+tx),-((lf+440)*sy+ty),0);
    glPopMatrix();












    //KID

    glPushMatrix();
    glTranslatef(-((bf+20)*sx+tx),((lf+250)*sy+ty),0);
    //body

    glColor3f(1.0,0.0,0.0);
    glRotatef(-S_ANGLE,0,0,1);
    glRectf((-15)*sx,(1)*sy,(15)*sx,(-50)*sy);
    glColor3f(1.0,0.90,0.70);
    glRectf((-15)*sx,(-50)*sy,(15)*sx,(-130)*sy);
    glTranslatef(((bf+20)*sx+tx),(-(lf+250)*sy+ty),0);
    glPopMatrix();





    glColor3f(0.0,0.0,0.0);
    //1st Leg
    glPushMatrix();



    glTranslatef(-((bf+20)*sx+tx), ((lf+150)*sy+ty),0);

    glRotatef(-S_ANGLE, 0, 0, 1);
    glRectf(-15*sx,1*sy,(15)*sx,(-70)*sy);
    glColor3f(1.0,0.90,0.70);
    glRectf(-15*sx,-70*sy,(15)*sx,(-150)*sy);
    glTranslatef(+((bf+20)*sx+tx), (-(lf+150)*sy+ty),0);


    glPopMatrix();






    //2nd Leg
    glPushMatrix();



    glTranslatef(-((bf+20)*sx+tx), ((lf+150)*sy+ty),0);

    glRotatef(S_ANGLE, 0, 0, 1);
    glColor3f(0.0,0.,0.0);
    glRectf(-15*sx,1*sy,(15)*sx,(-70)*sy);
    glColor3f(1.0,0.90,0.70);
    glRectf(-15*sx,-70*sy,(15)*sx,(-150)*sy);
    glTranslatef(+((bf+20)*sx+tx), (-(lf+150)*sy+ty),0);


    glPopMatrix();

    //head
    glPushMatrix();
    glTranslatef(-((bf+20)*sx+tx),((lf+250)*sy+ty),0);
    glColor3f(1.0,0.90,0.70);
    DrawCircle(0,35,35,100);
    glColor3f(0.0,0.0,0.0);
    DrawCircle(23,50,7,100);//eyes
    glBegin(GL_POLYGON);
    glVertex2f(33,20);
    glVertex2f(25,20);
    glVertex2f(20,30);
    glVertex2f(25,25);
    glVertex2f(33,25);
    glEnd();
    glTranslatef(((bf+20)*sx+tx),((lf+250)*sy+ty),0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-((bf+20)*sx+tx),((lf+250)*sy+ty),0);
    //body
    glColor3f(1.0,0.0,0.0);

    glRectf((-15)*sx,(1)*sy,(15)*sx,(-100)*sy);
    glColor3f(1.0,0.0,0.0);
    if(ta==ta_max)
        glRotatef(95,0,0,1);
    glRotatef(S_ANGLE,0,0,1);
    glRectf((-15)*sx,(1)*sy,(15)*sx,(-50)*sy);
    glColor3f(1.0,0.90,0.70);
    glRectf((-15)*sx,(-50)*sy,(15)*sx,(-130)*sy);
    glTranslatef(((bf+20)*sx+tx),(-(lf+250)*sy+ty),0);
    glPopMatrix();







}





void displayinterior( float tx, float ty, float SX, float SY )
{
    glColor3f(0.8,0.4,0);

    glBegin(GL_QUADS);
// wall
    glColor3f(0.45,0.79,0.91);
    glVertex2f(0*SX+tx,50*SY + ty,"hq");
    glVertex2f(1919*SX+tx,48*SY + ty,"hq");
    glVertex2f(1919*SX+tx,749*SY + ty,"hq");
    glVertex2f(1*SX+tx,749*SY + ty,"hq");
// floor
    glColor3f(0.53,0.60,0.63);
    glVertex2f(0*SX+tx,826*SY + ty,"hq");
    glVertex2f(1919*SX+tx,824*SY + ty,"hq");
    glVertex2f(1919*SX+tx,1002*SY + ty,"hq");
    glVertex2f(0*SX+tx,1003*SY + ty,"hq");
// table legs rear
    glColor3f(0.58,0.39,0.25);
    glVertex2f(245*SX+tx,652*SY + ty,"hq");
    glVertex2f(246*SX+tx,836*SY + ty,"hq");
    glVertex2f(261*SX+tx,836*SY + ty,"hq");
    glVertex2f(267*SX+tx,652*SY + ty,"hq");
    glVertex2f(607*SX+tx,650*SY + ty,"hq");
    glVertex2f(611*SX+tx,837*SY + ty,"hq");
    glVertex2f(624*SX+tx,838*SY + ty,"hq");
    glVertex2f(632*SX+tx,652*SY + ty,"hq");
    glEnd();
    glBegin(GL_QUADS);
//table legs front and lower wood
    glColor3f(0.71,0.45,0.31);
    glVertex2f(641*SX+tx,652*SY + ty,"hq");
    glVertex2f(645*SX+tx,836*SY + ty,"hq");
    glVertex2f(662*SX+tx,836*SY + ty,"hq");
    glVertex2f(666*SX+tx,652*SY + ty,"hq");
    glVertex2f(208*SX+tx,653*SY + ty,"hq");
    glVertex2f(213*SX+tx,839*SY + ty,"hq");
    glVertex2f(228*SX+tx,836*SY + ty,"hq");
    glVertex2f(232*SX+tx,652*SY + ty,"hq");
    glVertex2f(193*SX+tx,649*SY + ty,"hq");
    glVertex2f(682*SX+tx,651*SY + ty,"hq");
    glVertex2f(684*SX+tx,615*SY + ty,"hq");
    glVertex2f(196*SX+tx,615*SY + ty,"hq");
    glColor3f(0.75,0.49,0.33);
// table top
    glVertex2f(177*SX+tx,602*SY + ty,"hq");
    glVertex2f(175*SX+tx,615*SY + ty,"hq");
    glVertex2f(703*SX+tx,615*SY + ty,"hq");
    glVertex2f(703*SX+tx,597*SY + ty,"hq");
//bookshelf
    glColor3f(0.96,0.67,0.10);
    glVertex2f(1448*SX+tx,336*SY + ty,"hq");
    glVertex2f(1447*SX+tx,830*SY + ty,"hq");
    glVertex2f(1846*SX+tx,827*SY + ty,"hq");
    glVertex2f(1844*SX+tx,338*SY + ty,"hq");


// shelf1
    glColor3f(0.27,0.16,0.10);
    glVertex2f(1481*SX+tx,365*SY + ty,"hq");
    glVertex2f(1814*SX+tx,367*SY + ty,"hq");
    glVertex2f(1812*SX+tx,493*SY + ty,"hq");
    glVertex2f(1479*SX+tx,493*SY + ty,"hq");
// shelf2 and 3
    glVertex2f(1479*SX+tx,519*SY + ty,"hq");
    glVertex2f(1808*SX+tx,516*SY + ty,"hq");
    glVertex2f(1811*SX+tx,637*SY + ty,"hq");
    glVertex2f(1481*SX+tx,640*SY + ty,"hq");
    glVertex2f(1480*SX+tx,665*SY + ty,"hq");
    glVertex2f(1811*SX+tx,665*SY + ty,"hq");
    glVertex2f(1813*SX+tx,792*SY + ty,"hq");
    glVertex2f(1479*SX+tx,793*SY + ty,"hq");
// window
    glColor3f(1.00,1.00,1.00);
    glVertex2f(725*SX+tx,194*SY + ty,"hq");
    glVertex2f(1204*SX+tx,193*SY + ty,"hq");
    glVertex2f(1200*SX+tx,576*SY + ty,"hq");
    glVertex2f(723*SX+tx,576*SY + ty,"hq");
// window pane
    glColor3f(0.61,0.85,0.97);
    glVertex2f(754*SX+tx,216*SY + ty,"hq");
    glVertex2f(755*SX+tx,370*SY + ty,"hq");
    glVertex2f(949*SX+tx,373*SY + ty,"hq");
    glVertex2f(946*SX+tx,215*SY + ty,"hq");
    glVertex2f(981*SX+tx,215*SY + ty,"hq");
    glVertex2f(985*SX+tx,366*SY + ty,"hq");
    glVertex2f(1177*SX+tx,368*SY + ty,"hq");
    glVertex2f(1175*SX+tx,217*SY + ty,"hq");
    glVertex2f(754*SX+tx,402*SY + ty,"hq");
    glVertex2f(947*SX+tx,404*SY + ty,"hq");
    glVertex2f(946*SX+tx,550*SY + ty,"hq");
    glVertex2f(754*SX+tx,553*SY + ty,"hq");
    glVertex2f(980*SX+tx,402*SY + ty,"hq");
    glVertex2f(1174*SX+tx,401*SY + ty,"hq");
    glVertex2f(1175*SX+tx,556*SY + ty,"hq");
    glVertex2f(983*SX+tx,554*SY + ty,"hq");
// window shine
    glColor3f(0.75,0.90,1.00);
    glVertex2f(751*SX+tx,293*SY + ty,"hq");
    glVertex2f(751*SX+tx,344*SY + ty,"hq");
    glVertex2f(886*SX+tx,226*SY + ty,"hq");
    glVertex2f(824*SX+tx,225*SY + ty,"hq");
    SX=SX*0.2;
    SY=SY*0.2;
    tx=tx+200;
    ty=tx+225;
//tv set
    glColor3f(0.06,0.06,0.06);
    glVertex2f(69*SX+tx,5*SY + ty,"hq");
    glVertex2f(1764*SX+tx,4*SY + ty,"hq");
    glVertex2f(1764*SX+tx,860*SY + ty,"hq");
    glVertex2f(64*SX+tx,858*SY + ty,"hq");
    glColor3f(1,1,1);
    glVertex2f(91*SX+tx,22*SY + ty,"hq");
    glVertex2f(1750*SX+tx,20*SY + ty,"hq");
    glVertex2f(1743*SX+tx,841*SY + ty,"hq");
    glVertex2f(88*SX+tx,843*SY + ty,"hq");
    glColor3f(0.06,0.06,0.06);
    glVertex2f(605*SX+tx,859*SY + ty,"hq");
    glVertex2f(576*SX+tx,892*SY + ty,"hq");
    glVertex2f(1256*SX+tx,890*SY + ty,"hq");
    glVertex2f(1227*SX+tx,858*SY + ty,"hq");
    glEnd();

    SX=1;
    SY=1;
    tx=0;
    ty=0;

    glBegin(GL_POLYGON);
    glColor3f(0.91,0.18,0.18);
    glVertex2f(397*SX+tx,457*SY + ty,"hq");
    glVertex2f(346*SX+tx,509*SY + ty,"hq");
    glVertex2f(392*SX+tx,514*SY + ty,"hq");
    glVertex2f(350*SX+tx,563*SY + ty,"hq");
    glVertex2f(448*SX+tx,497*SY + ty,"hq");
    glVertex2f(401*SX+tx,494*SY + ty,"hq");
    glEnd();
//glBegin(GL_QUADS);
//glColor3f(0.90,0.40,0.27);
//glVertex2f(271*sx+tx ,141*sy + ty,"hq");
//glVertex2f(968*sx+tx ,59*sy + ty,"hq");
//glVertex2f(1652*sx+tx ,151*sy + ty,"hq");
//glVertex2f(263*sx+tx ,150*sy + ty,"hq");
//glEnd();
    glColor3f(0.27,0.27,0.27);

    glBegin(GL_POLYGON);
    glVertex2f(25*SX+tx,1025*SY + ty,"hq");
    glVertex2f(25*SX+tx,955*SY + ty,"hq");
    glVertex2f(1885*SX+tx,955*SY + ty,"hq");
    glVertex2f(1885*SX+tx,1025*SY + ty,"hq");
    glVertex2f(25*SX+tx,1025*SY + ty,"hq");
    glEnd();


    glColor3f(1,1,1);
    glBegin(GL_POLYGON);

    glVertex2f(30*SX+tx,1020*SY + ty,"hq");
    glVertex2f(30*SX+tx,960*SY + ty,"hq");
    glVertex2f(1880*SX+tx,960*SY + ty,"hq");
    glVertex2f(1880*SX+tx,1020*SY + ty,"hq");
    glVertex2f(30*SX+tx,1020*SY + ty,"hq");

    glEnd();

    display_fatson(ta,1,1,1);

}
void bezierCoefficients(int n, int *c)
{
    int k,i;
    for(k=0; k<=n; k++)
    {
        c[k]=1;
        for(i=n; i>=k+1; i--)
            c[k]*=i;
        for(i=n-k; i>=2; i--)
            c[k]/=i;

    }
}
float float_rand( float min, float max )
{
    float scale = rand() / (float) RAND_MAX; /* [0, 1.0] */
    return min + scale * ( max - min );      /* [min, max] */
}
void displayaudience(int a1, int a2, int b1,int b2, int c1,int c2, int d1,int d2,int hm,int i)
{

    int cp[4][2]= {{a1,a2},{b1,b2},{c1,c2},{d1,d2}};
    int c[4],k,n=3;
    float x,y,u,blend;
    bezierCoefficients(n,c);
    // generate random color for audience in timer

    glColor3f(cl1[i],cl2[i],cl3[i]);
    glLineWidth(1.0);
    glBegin(GL_POLYGON);

    for(u=0; u<1.0; u+=0.01)
    {
        x=0;
        y=0;
        for(k=0; k<4; k++)
        {
            blend=c[k]*pow(u,k)*pow(1-u,n-k);
            x+=cp[k][0]*blend;
            y+=cp[k][1]*blend;
        }

//        DrawCircle()
        glVertex2f(x,y,"hq");

    }
    glEnd();
    glColor3f(0.92,0.74,0.55);
    DrawCircle(a1-1000,-a2/2+hm,40,20);
}

void displaycrowd(float TX,float TY,float SX, float SY)
{
    int hm=180;
    float ty=180,tx=0;
    for(int j=0; j<3; j++)
    {
        if(j==1)
            hm=140;
        if(j==2)
            hm=90;
        for( int i =0 ; i<24; i++)
        {
            tx=i+moveaudience;
            if(j==1)
                tx=i-moveaudience;
            displayaudience(1920-tx*80,1080-ty,1920-tx*80,980-ty,1840-tx*80,980-ty,1840-tx*80,1080-ty,hm,i*(j+1));
        }
        ty=ty-80;
    }
}
void displaystage(float TX,float TY,float SX,float SY)
{

// 	cout<<" DISPLAY STAGE \n";
    glColor3f(0.33,0.37,0.50);
    glLineWidth(5.0);
    float sx=1, sy=1, tx=0, ty=0 ;
    sx=sy=0.8;
    glPushMatrix();
    glTranslatef(-1*SX,50*SY,0);
    for(int i=0; i<900; i=i+100)
    {

        ty=-i*sx+200;
        glBegin(GL_LINE_LOOP);
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,718*sy*SY + ty,"hq");
        glEnd();
    }
    for(int i=0; i<2000; i=i+100)
    {
        tx=i*sx;
        glBegin(GL_LINE_LOOP);
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,718*sy*SY + ty,"hq");
        glEnd();
    }
    for(int i=0; i<900; i=i+100)
    {

        ty=-i*sx+200;
        glBegin(GL_LINE_LOOP);
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,718*sy*SY + ty,"hq");
        glEnd();
    }
    glTranslatef(1*SX,-50*SY,0);
    glPopMatrix();

    //Band
    glPushMatrix();
    glTranslatef(20*sx*SX,160*sy*SY,0);
    stage(1,1,.745,0.6);
    displayBand(1,1,.745,.6);
    glTranslatef(-20*sx*SX,-160*sy*SY,0);
    glPopMatrix();



    ty=+70;
    tx=+20;
    sy=1;
    sx=1;
    glBegin(GL_QUADS);
    glColor3f(0.93,0.57,0.53);
    glVertex2f(252*sx*SX+tx,625*sy*SY + ty,"hq");
    glVertex2f(355*sx*SX+tx,597*sy*SY + ty,"hq");
    glVertex2f(551*sx*SX+tx,601*sy*SY + ty,"hq");
    glVertex2f(426*sx*SX+tx,641*sy*SY + ty,"hq");
    glVertex2f(424*sx*SX+tx,667*sy*SY + ty,"hq");
    glVertex2f(561*sx*SX+tx,613*sy*SY + ty,"hq");
    glVertex2f(1357*sx*SX+tx,613*sy*SY + ty,"hq");
    glVertex2f(1508*sx*SX+tx,666*sy*SY + ty,"hq");
    glVertex2f(1373*sx*SX+tx,598*sy*SY + ty,"hq");
    glVertex2f(1554*sx*SX+tx,598*sy*SY + ty,"hq");
    glVertex2f(1670*sx*SX+tx,625*sy*SY + ty,"hq");
    glVertex2f(1493*sx*SX+tx,641*sy*SY + ty,"hq");
    glColor3f(0.58,0.24,0.45);
    glVertex2f(238*sx*SX+tx,625*sy*SY + ty,"hq");
    glVertex2f(244*sx*SX+tx,795*sy*SY + ty,"hq");
    glVertex2f(420*sx*SX+tx,829*sy*SY + ty,"hq");
    glVertex2f(425*sx*SX+tx,644*sy*SY + ty,"hq");
    glColor3f(0.71,0.34,0.55);
    glVertex2f(414*sx*SX+tx,647*sy*SY + ty,"hq");
    glVertex2f(549*sx*SX+tx,601*sy*SY + ty,"hq");
    glVertex2f(558*sx*SX+tx,612*sy*SY + ty,"hq");
    glVertex2f(418*sx*SX+tx,662*sy*SY + ty,"hq");
    glVertex2f(1358*sx*SX+tx,611*sy*SY + ty,"hq");
    glVertex2f(1366*sx*SX+tx,601*sy*SY + ty,"hq");
    glVertex2f(1493*sx*SX+tx,642*sy*SY + ty,"hq");
    glVertex2f(1487*sx*SX+tx,659*sy*SY + ty,"hq");
    glColor3f(0.58,0.22,0.45);
    glVertex2f(1495*sx*SX+tx,647*sy*SY + ty,"hq");
    glVertex2f(1492*sx*SX+tx,822*sy*SY + ty,"hq");
    glVertex2f(1652*sx*SX+tx,792*sy*SY + ty,"hq");
    glVertex2f(1674*sx*SX+tx,628*sy*SY + ty,"hq");
    glColor3f(0.88,0.40,0.51);
    glVertex2f(419*sx*SX+tx,678*sy*SY + ty,"hq");
    glVertex2f(424*sx*SX+tx,844*sy*SY + ty,"hq");
    glVertex2f(1514*sx*SX+tx,838*sy*SY + ty,"hq");
    glVertex2f(1508*sx*SX+tx,679*sy*SY + ty,"hq");

    ty=0;
//speakers1
    sx=sy=0.37;
    ty=ty+500;
    tx=tx-210;
    glColor3f(0.10,0.10,0.10);
    glVertex2f(1068*sx*SX+tx,191*sy*SY + ty,"hq");
    glVertex2f(1207*sx*SX+tx,130*sy*SY + ty,"hq");
    glVertex2f(1081*sx*SX+tx,740*sy*SY + ty,"hq");
    glVertex2f(1013*sx*SX+tx,805*sy*SY + ty,"hq");
    glColor3f(0.30,0.30,0.30);
    glVertex2f(1065*sx*SX+tx,189*sy*SY + ty,"hq");
    glVertex2f(1209*sx*SX+tx,127*sy*SY + ty,"hq");
    glVertex2f(825*sx*SX+tx,170*sy*SY + ty,"hq");
    glVertex2f(714*sx*SX+tx,213*sy*SY + ty,"hq");
    glColor3f(0.20,0.20,0.20);
    glVertex2f(716*sx*SX+tx,213*sy*SY + ty,"hq");
    glVertex2f(1066*sx*SX+tx,193*sy*SY + ty,"hq");
    glVertex2f(1011*sx*SX+tx,805*sy*SY + ty,"hq");
    glVertex2f(817*sx*SX+tx,770*sy*SY + ty,"hq");


    glEnd();
    tx=tx-80;
    ty=ty+170;
    int placespeakersx,placespeakersy;
    placespeakersx=-550*SX;
    placespeakersy=-750*SY;
    glColor3f(0.30,0.30,0.30);
    DrawCircle(tx+placespeakersx,ty+placespeakersy,100*sx*SY,20);
    glColor3f(0.50,0.50,0.50);
    DrawCircle(tx+placespeakersx,ty+placespeakersy,10*sx*SY,20);
    tx=tx+20;
    ty=ty-250;
    placespeakersy=-620*SY;
    placespeakersx=-570*SX;
    glColor3f(0.30,0.30,0.30);
    DrawCircle(tx+placespeakersx,ty+placespeakersy,80*sx*SY,20);
    glColor3f(0.50,0.50,0.50);
    DrawCircle(tx+placespeakersx,ty+placespeakersy,10*sx*SY,20);
//speakers2
    sx=sy=0.37;
    ty+=80;
    tx=tx+1680;
    glBegin(GL_QUADS);
    glColor3f(0.10,0.10,0.10);
    glVertex2f(712*sx*SX+tx,183*sy*SY + ty,"hq");
    glVertex2f(853*sx*SX+tx,245*sy*SY + ty,"hq");
    glVertex2f(916*sx*SX+tx,816*sy*SY + ty,"hq");
    glVertex2f(844*sx*SX+tx,754*sy*SY + ty,"hq");
    glColor3f(0.30,0.30,0.30);
    glVertex2f(714*sx*SX+tx,180*sy*SY + ty,"hq");
    glVertex2f(856*sx*SX+tx,243*sy*SY + ty,"hq");
    glVertex2f(1211*sx*SX+tx,261*sy*SY + ty,"hq");
    glVertex2f(1102*sx*SX+tx,221*sy*SY + ty,"hq");
    glColor3f(0.20,0.20,0.20);
    glVertex2f(859*sx*SX+tx,243*sy*SY + ty,"hq");
    glVertex2f(1207*sx*SX+tx,264*sy*SY + ty,"hq");
    glVertex2f(1110*sx*SX+tx,781*sy*SY + ty,"hq");
    glVertex2f(916*sx*SX+tx,816*sy*SY + ty,"hq");

    glEnd();
    ty-=310;
    placespeakersx=-580*SX;
    placespeakersy=-290*SY;
    glColor3f(0.30,0.30,0.30);
    DrawCircle(tx+placespeakersx,ty+placespeakersy,100*sx*SX,20);
    glColor3f(0.50,0.50,0.50);
    DrawCircle(tx+placespeakersx,ty+placespeakersy,10*sx*SX,20);
    tx=tx+20;
    ty=ty-250;
    placespeakersy=-135*SY;
    placespeakersx=-600*SX;
    glColor3f(0.30,0.30,0.30);
    DrawCircle(tx+placespeakersx,ty+placespeakersy,80*sx*SX,20);
    glColor3f(0.50,0.50,0.50);
    DrawCircle(tx+placespeakersx,ty+placespeakersy,10*sx*SX,20);

    sx=sy=1;




}


void displaystage1(float TX,float TY,float SX,float SY)
{

// 	cout<<" DISPLAY STAGE \n";
    glColor3f(0.33,0.37,0.50);
    glLineWidth(5.0);
    float sx=1, sy=1, tx=0, ty=0 ;
    sx=sy=0.8;
    glPushMatrix();
    glTranslatef(-1*SX,50*SY,0);
    for(int i=0; i<900; i=i+100)
    {

        ty=-i*sx+200;
        glBegin(GL_LINE_LOOP);
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,718*sy*SY + ty,"hq");
        glEnd();
    }
    for(int i=0; i<2000; i=i+100)
    {
        tx=i*sx;
        glBegin(GL_LINE_LOOP);
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,718*sy*SY + ty,"hq");
        glEnd();
    }
    for(int i=0; i<900; i=i+100)
    {

        ty=-i*sx+200;
        glBegin(GL_LINE_LOOP);
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,718*sy*SY + ty,"hq");
        glEnd();
    }
    glTranslatef(1*SX,-50*SY,0);
    glPopMatrix();




    //Band
    glPushMatrix();
    glTranslatef(20*sx*SX,160*sy*SY,0);
    stage(1,1,.745,0.6);
    kidband(1,1,.745,0.6);
    glTranslatef(-20*sx*SX,-160*sy*SY,0);
    glPopMatrix();


    glPushMatrix();
    glRotatef(90,0,0,1);
    justlights(200,800,0.35,0.35);

    glPopMatrix();

    glPushMatrix();
    glRotatef(270,0,0,1);
    justlights(-200,820,0.35,0.35);
    glPopMatrix();

    glPushMatrix();
    glRotatef(180,0,0,1);
    justlights(-400,-530,0.4,0.2);
    justlights(400,-530,0.4,0.2);
    glPopMatrix();



    ty=+70;
    tx=+20;
    sy=1;
    sx=1;
    glBegin(GL_QUADS);
    glColor3f(0.93,0.57,0.53);
    glVertex2f(252*sx*SX+tx,625*sy*SY + ty,"hq");
    glVertex2f(355*sx*SX+tx,597*sy*SY + ty,"hq");
    glVertex2f(551*sx*SX+tx,601*sy*SY + ty,"hq");
    glVertex2f(426*sx*SX+tx,641*sy*SY + ty,"hq");
    glVertex2f(424*sx*SX+tx,667*sy*SY + ty,"hq");
    glVertex2f(561*sx*SX+tx,613*sy*SY + ty,"hq");
    glVertex2f(1357*sx*SX+tx,613*sy*SY + ty,"hq");
    glVertex2f(1508*sx*SX+tx,666*sy*SY + ty,"hq");
    glVertex2f(1373*sx*SX+tx,598*sy*SY + ty,"hq");
    glVertex2f(1554*sx*SX+tx,598*sy*SY + ty,"hq");
    glVertex2f(1670*sx*SX+tx,625*sy*SY + ty,"hq");
    glVertex2f(1493*sx*SX+tx,641*sy*SY + ty,"hq");
    glColor3f(0.58,0.24,0.45);
    glVertex2f(238*sx*SX+tx,625*sy*SY + ty,"hq");
    glVertex2f(244*sx*SX+tx,795*sy*SY + ty,"hq");
    glVertex2f(420*sx*SX+tx,829*sy*SY + ty,"hq");
    glVertex2f(425*sx*SX+tx,644*sy*SY + ty,"hq");
    glColor3f(0.71,0.34,0.55);
    glVertex2f(414*sx*SX+tx,647*sy*SY + ty,"hq");
    glVertex2f(549*sx*SX+tx,601*sy*SY + ty,"hq");
    glVertex2f(558*sx*SX+tx,612*sy*SY + ty,"hq");
    glVertex2f(418*sx*SX+tx,662*sy*SY + ty,"hq");
    glVertex2f(1358*sx*SX+tx,611*sy*SY + ty,"hq");
    glVertex2f(1366*sx*SX+tx,601*sy*SY + ty,"hq");
    glVertex2f(1493*sx*SX+tx,642*sy*SY + ty,"hq");
    glVertex2f(1487*sx*SX+tx,659*sy*SY + ty,"hq");
    glColor3f(0.58,0.22,0.45);
    glVertex2f(1495*sx*SX+tx,647*sy*SY + ty,"hq");
    glVertex2f(1492*sx*SX+tx,822*sy*SY + ty,"hq");
    glVertex2f(1652*sx*SX+tx,792*sy*SY + ty,"hq");
    glVertex2f(1674*sx*SX+tx,628*sy*SY + ty,"hq");
    glColor3f(0.88,0.40,0.51);
    glVertex2f(419*sx*SX+tx,678*sy*SY + ty,"hq");
    glVertex2f(424*sx*SX+tx,844*sy*SY + ty,"hq");
    glVertex2f(1514*sx*SX+tx,838*sy*SY + ty,"hq");
    glVertex2f(1508*sx*SX+tx,679*sy*SY + ty,"hq");

    ty=0;
//speakers1
    sx=sy=0.37;
    ty=ty+500;
    tx=tx-210;
    glColor3f(0.10,0.10,0.10);
    glVertex2f(1068*sx*SX+tx,191*sy*SY + ty,"hq");
    glVertex2f(1207*sx*SX+tx,130*sy*SY + ty,"hq");
    glVertex2f(1081*sx*SX+tx,740*sy*SY + ty,"hq");
    glVertex2f(1013*sx*SX+tx,805*sy*SY + ty,"hq");
    glColor3f(0.30,0.30,0.30);
    glVertex2f(1065*sx*SX+tx,189*sy*SY + ty,"hq");
    glVertex2f(1209*sx*SX+tx,127*sy*SY + ty,"hq");
    glVertex2f(825*sx*SX+tx,170*sy*SY + ty,"hq");
    glVertex2f(714*sx*SX+tx,213*sy*SY + ty,"hq");
    glColor3f(0.20,0.20,0.20);
    glVertex2f(716*sx*SX+tx,213*sy*SY + ty,"hq");
    glVertex2f(1066*sx*SX+tx,193*sy*SY + ty,"hq");
    glVertex2f(1011*sx*SX+tx,805*sy*SY + ty,"hq");
    glVertex2f(817*sx*SX+tx,770*sy*SY + ty,"hq");


    glEnd();
    tx=tx-80;
    ty=ty+170;
    int placespeakersx,placespeakersy;
    placespeakersx=-550*SX;
    placespeakersy=-750*SY;
    glColor3f(0.30,0.30,0.30);
    DrawCircle(tx+placespeakersx,ty+placespeakersy,100*sx*SY,20);
    glColor3f(0.50,0.50,0.50);
    DrawCircle(tx+placespeakersx,ty+placespeakersy,10*sx*SY,20);
    tx=tx+20;
    ty=ty-250;
    placespeakersy=-620*SY;
    placespeakersx=-570*SX;
    glColor3f(0.30,0.30,0.30);
    DrawCircle(tx+placespeakersx,ty+placespeakersy,80*sx*SY,20);
    glColor3f(0.50,0.50,0.50);
    DrawCircle(tx+placespeakersx,ty+placespeakersy,10*sx*SY,20);
//speakers2
    sx=sy=0.37;
    ty+=80;
    tx=tx+1680;
    glBegin(GL_QUADS);
    glColor3f(0.10,0.10,0.10);
    glVertex2f(712*sx*SX+tx,183*sy*SY + ty,"hq");
    glVertex2f(853*sx*SX+tx,245*sy*SY + ty,"hq");
    glVertex2f(916*sx*SX+tx,816*sy*SY + ty,"hq");
    glVertex2f(844*sx*SX+tx,754*sy*SY + ty,"hq");
    glColor3f(0.30,0.30,0.30);
    glVertex2f(714*sx*SX+tx,180*sy*SY + ty,"hq");
    glVertex2f(856*sx*SX+tx,243*sy*SY + ty,"hq");
    glVertex2f(1211*sx*SX+tx,261*sy*SY + ty,"hq");
    glVertex2f(1102*sx*SX+tx,221*sy*SY + ty,"hq");
    glColor3f(0.20,0.20,0.20);
    glVertex2f(859*sx*SX+tx,243*sy*SY + ty,"hq");
    glVertex2f(1207*sx*SX+tx,264*sy*SY + ty,"hq");
    glVertex2f(1110*sx*SX+tx,781*sy*SY + ty,"hq");
    glVertex2f(916*sx*SX+tx,816*sy*SY + ty,"hq");

    glEnd();
    ty-=310;
    placespeakersx=-580*SX;
    placespeakersy=-290*SY;
    glColor3f(0.30,0.30,0.30);
    DrawCircle(tx+placespeakersx,ty+placespeakersy,100*sx*SX,20);
    glColor3f(0.50,0.50,0.50);
    DrawCircle(tx+placespeakersx,ty+placespeakersy,10*sx*SX,20);
    tx=tx+20;
    ty=ty-250;
    placespeakersy=-135*SY;
    placespeakersx=-600*SX;
    glColor3f(0.30,0.30,0.30);
    DrawCircle(tx+placespeakersx,ty+placespeakersy,80*sx*SX,20);
    glColor3f(0.50,0.50,0.50);
    DrawCircle(tx+placespeakersx,ty+placespeakersy,10*sx*SX,20);

    sx=sy=1;



}








int time1=0;
void dispconcert()

{
    if(time1==0)
    {
        PlaySound("D://Codeblock//queen.wav",NULL,SND_LOOP|SND_ASYNC);
        time1++;
    }

    //Background Home Ground
    glColor3f(0.09,0.70,0.30);
    glBegin(GL_POLYGON);
    glVertex2d(-960,-540);
    glVertex2d(960,-540);
    glVertex2d(960,-100);
    glVertex2d(-960,-100);
    glEnd();

    //

    //Sky

    glColor3f(0.05,0.7,1.0);
    glBegin(GL_POLYGON);
    glVertex2d(-960,540);
    glVertex2d(960,540);
    glVertex2d(960,-100);
    glVertex2d(-960,-100);
    glEnd();
    displaystage(1,1,1,1);
    displaycrowd(1,1,1,1);



}
int time2=0;
void dispconcert1()

{
    if(time2==1)
    {
        PlaySound("D://Codeblock//queen.wav",NULL,SND_LOOP|SND_ASYNC);
        time1++;
    }

    //Background Home Ground
    glColor3f(0.05,0.40,0.05);
    glBegin(GL_POLYGON);
    glVertex2d(-960,-540);
    glVertex2d(960,-540);
    glVertex2d(960,-100);
    glVertex2d(-960,-100);
    glEnd();

    //

    //Sky

    glColor3f(0.01,0.01,.09);
    glBegin(GL_POLYGON);
    glVertex2d(-960,540);
    glVertex2d(960,540);
    glVertex2d(960,-100);
    glVertex2d(-960,-100);
    glEnd();
    displaystage1(1,1,1,1);
    displaycrowd(1,1,1,1);




}








void afterconcert( float tx, float ty, float SX, float SY )
{
    glColor3f(0.8,0.4,0);

    glBegin(GL_QUADS);
// wall
    glColor3f(0.45,0.79,0.91);
    glVertex2f(0*SX+tx,50*SY + ty,"hq");
    glVertex2f(1919*SX+tx,48*SY + ty,"hq");
    glVertex2f(1919*SX+tx,749*SY + ty,"hq");
    glVertex2f(1*SX+tx,749*SY + ty,"hq");
// floor
    glColor3f(0.53,0.60,0.63);
    glVertex2f(0*SX+tx,826*SY + ty,"hq");
    glVertex2f(1919*SX+tx,824*SY + ty,"hq");
    glVertex2f(1919*SX+tx,1002*SY + ty,"hq");
    glVertex2f(0*SX+tx,1003*SY + ty,"hq");
// table legs rear
    glColor3f(0.58,0.39,0.25);
    glVertex2f(245*SX+tx,652*SY + ty,"hq");
    glVertex2f(246*SX+tx,836*SY + ty,"hq");
    glVertex2f(261*SX+tx,836*SY + ty,"hq");
    glVertex2f(267*SX+tx,652*SY + ty,"hq");
    glVertex2f(607*SX+tx,650*SY + ty,"hq");
    glVertex2f(611*SX+tx,837*SY + ty,"hq");
    glVertex2f(624*SX+tx,838*SY + ty,"hq");
    glVertex2f(632*SX+tx,652*SY + ty,"hq");
    glEnd();
    glBegin(GL_QUADS);
//table legs front and lower wood
    glColor3f(0.71,0.45,0.31);
    glVertex2f(641*SX+tx,652*SY + ty,"hq");
    glVertex2f(645*SX+tx,836*SY + ty,"hq");
    glVertex2f(662*SX+tx,836*SY + ty,"hq");
    glVertex2f(666*SX+tx,652*SY + ty,"hq");
    glVertex2f(208*SX+tx,653*SY + ty,"hq");
    glVertex2f(213*SX+tx,839*SY + ty,"hq");
    glVertex2f(228*SX+tx,836*SY + ty,"hq");
    glVertex2f(232*SX+tx,652*SY + ty,"hq");
    glVertex2f(193*SX+tx,649*SY + ty,"hq");
    glVertex2f(682*SX+tx,651*SY + ty,"hq");
    glVertex2f(684*SX+tx,615*SY + ty,"hq");
    glVertex2f(196*SX+tx,615*SY + ty,"hq");
    glColor3f(0.75,0.49,0.33);
// table top
    glVertex2f(177*SX+tx,602*SY + ty,"hq");
    glVertex2f(175*SX+tx,615*SY + ty,"hq");
    glVertex2f(703*SX+tx,615*SY + ty,"hq");
    glVertex2f(703*SX+tx,597*SY + ty,"hq");
//bookshelf
    glColor3f(0.96,0.67,0.10);
    glVertex2f(1448*SX+tx,336*SY + ty,"hq");
    glVertex2f(1447*SX+tx,830*SY + ty,"hq");
    glVertex2f(1846*SX+tx,827*SY + ty,"hq");
    glVertex2f(1844*SX+tx,338*SY + ty,"hq");


// shelf1
    glColor3f(0.27,0.16,0.10);
    glVertex2f(1481*SX+tx,365*SY + ty,"hq");
    glVertex2f(1814*SX+tx,367*SY + ty,"hq");
    glVertex2f(1812*SX+tx,493*SY + ty,"hq");
    glVertex2f(1479*SX+tx,493*SY + ty,"hq");
// shelf2 and 3
    glVertex2f(1479*SX+tx,519*SY + ty,"hq");
    glVertex2f(1808*SX+tx,516*SY + ty,"hq");
    glVertex2f(1811*SX+tx,637*SY + ty,"hq");
    glVertex2f(1481*SX+tx,640*SY + ty,"hq");
    glVertex2f(1480*SX+tx,665*SY + ty,"hq");
    glVertex2f(1811*SX+tx,665*SY + ty,"hq");
    glVertex2f(1813*SX+tx,792*SY + ty,"hq");
    glVertex2f(1479*SX+tx,793*SY + ty,"hq");
// window
    glColor3f(1.00,1.00,1.00);
    glVertex2f(725*SX+tx,194*SY + ty,"hq");
    glVertex2f(1204*SX+tx,193*SY + ty,"hq");
    glVertex2f(1200*SX+tx,576*SY + ty,"hq");
    glVertex2f(723*SX+tx,576*SY + ty,"hq");
// window pane
    glColor3f(0.61,0.85,0.97);
    glVertex2f(754*SX+tx,216*SY + ty,"hq");
    glVertex2f(755*SX+tx,370*SY + ty,"hq");
    glVertex2f(949*SX+tx,373*SY + ty,"hq");
    glVertex2f(946*SX+tx,215*SY + ty,"hq");
    glVertex2f(981*SX+tx,215*SY + ty,"hq");
    glVertex2f(985*SX+tx,366*SY + ty,"hq");
    glVertex2f(1177*SX+tx,368*SY + ty,"hq");
    glVertex2f(1175*SX+tx,217*SY + ty,"hq");
    glVertex2f(754*SX+tx,402*SY + ty,"hq");
    glVertex2f(947*SX+tx,404*SY + ty,"hq");
    glVertex2f(946*SX+tx,550*SY + ty,"hq");
    glVertex2f(754*SX+tx,553*SY + ty,"hq");
    glVertex2f(980*SX+tx,402*SY + ty,"hq");
    glVertex2f(1174*SX+tx,401*SY + ty,"hq");
    glVertex2f(1175*SX+tx,556*SY + ty,"hq");
    glVertex2f(983*SX+tx,554*SY + ty,"hq");
// window shine
    glColor3f(0.75,0.90,1.00);
    glVertex2f(751*SX+tx,293*SY + ty,"hq");
    glVertex2f(751*SX+tx,344*SY + ty,"hq");
    glVertex2f(886*SX+tx,226*SY + ty,"hq");
    glVertex2f(824*SX+tx,225*SY + ty,"hq");
    SX=SX*0.2;
    SY=SY*0.2;
    tx=tx+200;
    ty=tx+225;
//tv set
    glColor3f(0.06,0.06,0.06);
    glVertex2f(69*SX+tx,5*SY + ty,"hq");
    glVertex2f(1764*SX+tx,4*SY + ty,"hq");
    glVertex2f(1764*SX+tx,860*SY + ty,"hq");
    glVertex2f(64*SX+tx,858*SY + ty,"hq");
    glColor3f(1,1,1);
    glVertex2f(91*SX+tx,22*SY + ty,"hq");
    glVertex2f(1750*SX+tx,20*SY + ty,"hq");
    glVertex2f(1743*SX+tx,841*SY + ty,"hq");
    glVertex2f(88*SX+tx,843*SY + ty,"hq");
    glColor3f(0.06,0.06,0.06);
    glVertex2f(605*SX+tx,859*SY + ty,"hq");
    glVertex2f(576*SX+tx,892*SY + ty,"hq");
    glVertex2f(1256*SX+tx,890*SY + ty,"hq");
    glVertex2f(1227*SX+tx,858*SY + ty,"hq");
    glEnd();

    SX=1;
    SY=1;
    tx=0;
    ty=0;

    glBegin(GL_POLYGON);
    glColor3f(0.91,0.18,0.18);
    glVertex2f(397*SX+tx,457*SY + ty,"hq");
    glVertex2f(346*SX+tx,509*SY + ty,"hq");
    glVertex2f(392*SX+tx,514*SY + ty,"hq");
    glVertex2f(350*SX+tx,563*SY + ty,"hq");
    glVertex2f(448*SX+tx,497*SY + ty,"hq");
    glVertex2f(401*SX+tx,494*SY + ty,"hq");
    glEnd();
//glBegin(GL_QUADS);
//glColor3f(0.90,0.40,0.27);
//glVertex2f(271*sx+tx ,141*sy + ty,"hq");
//glVertex2f(968*sx+tx ,59*sy + ty,"hq");
//glVertex2f(1652*sx+tx ,151*sy + ty,"hq");
//glVertex2f(263*sx+tx ,150*sy + ty,"hq");
//glEnd();
    glColor3f(0.27,0.27,0.27);

    glBegin(GL_POLYGON);
    glVertex2f(25*SX+tx,1025*SY + ty,"hq");
    glVertex2f(25*SX+tx,955*SY + ty,"hq");
    glVertex2f(1885*SX+tx,955*SY + ty,"hq");
    glVertex2f(1885*SX+tx,1025*SY + ty,"hq");
    glVertex2f(25*SX+tx,1025*SY + ty,"hq");
    glEnd();


    glColor3f(1,1,1);
    glBegin(GL_POLYGON);

    glVertex2f(30*SX+tx,1020*SY + ty,"hq");
    glVertex2f(30*SX+tx,960*SY + ty,"hq");
    glVertex2f(1880*SX+tx,960*SY + ty,"hq");
    glVertex2f(1880*SX+tx,1020*SY + ty,"hq");
    glVertex2f(30*SX+tx,1020*SY + ty,"hq");

    glEnd();
    if(ta>ta_max)
    {
        gy=gy-0.0000005;
        gg=gg-0.001;
    }
    displayguitar(-100,-145,.45*SX,.45*SY,.45*SY,.45*SY,.45*SY);
    dispKidGuitar(ta,1-gy,1.05*gg,1.05*gg);
}

void dispKidGuitar(float tx, float ty, float sx, float sy)
{
    float lf=-400;
    float bf=450;

//KID

    glPushMatrix();
    glTranslatef(-((bf+20)*sx+tx),((lf+250)*sy+ty),0);
    //body

    glColor3f(1.0,0.0,0.0);
    glRotatef(-S_ANGLE,0,0,1);
    glRectf((-15)*sx,(1)*sy,(15)*sx,(-50)*sy);
    glColor3f(1.0,0.90,0.70);
    glRectf((-15)*sx,(-50)*sy,(15)*sx,(-130)*sy);
    glTranslatef(((bf+20)*sx+tx),(-(lf+250)*sy+ty),0);
    glPopMatrix();





    glColor3f(0.0,0.0,0.0);
    //1st Leg
    glPushMatrix();



    glTranslatef(-((bf+20)*sx+tx), ((lf+150)*sy+ty),0);

    glRotatef(-S_ANGLE, 0, 0, 1);
    glRectf(-15*sx,1*sy,(15)*sx,(-70)*sy);
    glColor3f(1.0,0.90,0.70);
    glRectf(-15*sx,-70*sy,(15)*sx,(-150)*sy);
    glTranslatef(+((bf+20)*sx+tx), (-(lf+150)*sy+ty),0);


    glPopMatrix();






    //2nd Leg
    glPushMatrix();



    glTranslatef(-((bf+20)*sx+tx), ((lf+150)*sy+ty),0);

    glRotatef(S_ANGLE, 0, 0, 1);
    glColor3f(0.0,0.,0.0);
    glRectf(-15*sx,1*sy,(15)*sx,(-70)*sy);
    glColor3f(1.0,0.90,0.70);
    glRectf(-15*sx,-70*sy,(15)*sx,(-150)*sy);
    glTranslatef(+((bf+20)*sx+tx), (-(lf+150)*sy+ty),0);


    glPopMatrix();

    //head
    glPushMatrix();
    glTranslatef(-((bf+20)*sx+tx),((lf+250)*sy+ty),0);
    glColor3f(1.0,0.90,0.70);
    DrawCircle(0,35,35,100);
    glColor3f(0.0,0.0,0.0);
    DrawCircle(23,50,7,100);//eyes
    glBegin(GL_POLYGON);
    glVertex2f(33,20);
    glVertex2f(25,20);
    glVertex2f(20,30);
    glVertex2f(25,25);
    glVertex2f(33,25);
    glEnd();
    glTranslatef(((bf+20)*sx+tx),((lf+250)*sy+ty),0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-((bf+20)*sx+tx),((lf+250)*sy+ty),0);
    //body
    glColor3f(1.0,0.0,0.0);

    glRectf((-15)*sx,(1)*sy,(15)*sx,(-100)*sy);
    glColor3f(1.0,0.0,0.0);

    glRotatef(S_ANGLE,0,0,1);
    glRectf((-15)*sx,(1)*sy,(15)*sx,(-50)*sy);
    glColor3f(1.0,0.90,0.70);
    glRectf((-15)*sx,(-50)*sy,(15)*sx,(-130)*sy);
    glTranslatef(((bf+20)*sx+tx),(-(lf+250)*sy+ty),0);
    glPopMatrix();

}


void growingupscene(float tx, float ty, float SX, float SY)
{

    glColor3f(0.8,0.4,0);

    glBegin(GL_QUADS);
// wall
    glColor3f(0.45,0.79,0.91);
    glVertex2f(0*SX+tx,50*SY + ty,"hq");
    glVertex2f(1919*SX+tx,48*SY + ty,"hq");
    glVertex2f(1919*SX+tx,749*SY + ty,"hq");
    glVertex2f(1*SX+tx,749*SY + ty,"hq");
// floor
    glColor3f(0.53,0.60,0.63);
    glVertex2f(0*SX+tx,826*SY + ty,"hq");
    glVertex2f(1919*SX+tx,824*SY + ty,"hq");
    glVertex2f(1919*SX+tx,1080*SY + ty,"hq");
    glVertex2f(0*SX+tx,1080*SY + ty,"hq");
// table legs rear
    glColor3f(0.58,0.39,0.25);
    glVertex2f(245*SX+tx,652*SY + ty,"hq");
    glVertex2f(246*SX+tx,836*SY + ty,"hq");
    glVertex2f(261*SX+tx,836*SY + ty,"hq");
    glVertex2f(267*SX+tx,652*SY + ty,"hq");
    glVertex2f(607*SX+tx,650*SY + ty,"hq");
    glVertex2f(611*SX+tx,837*SY + ty,"hq");
    glVertex2f(624*SX+tx,838*SY + ty,"hq");
    glVertex2f(632*SX+tx,652*SY + ty,"hq");
    glEnd();
    glBegin(GL_QUADS);
//table legs front and lower wood
    glColor3f(0.71,0.45,0.31);
    glVertex2f(641*SX+tx,652*SY + ty,"hq");
    glVertex2f(645*SX+tx,836*SY + ty,"hq");
    glVertex2f(662*SX+tx,836*SY + ty,"hq");
    glVertex2f(666*SX+tx,652*SY + ty,"hq");
    glVertex2f(208*SX+tx,653*SY + ty,"hq");
    glVertex2f(213*SX+tx,839*SY + ty,"hq");
    glVertex2f(228*SX+tx,836*SY + ty,"hq");
    glVertex2f(232*SX+tx,652*SY + ty,"hq");
    glVertex2f(193*SX+tx,649*SY + ty,"hq");
    glVertex2f(682*SX+tx,651*SY + ty,"hq");
    glVertex2f(684*SX+tx,615*SY + ty,"hq");
    glVertex2f(196*SX+tx,615*SY + ty,"hq");
    glColor3f(0.75,0.49,0.33);
// table top
    glVertex2f(177*SX+tx,602*SY + ty,"hq");
    glVertex2f(175*SX+tx,615*SY + ty,"hq");
    glVertex2f(703*SX+tx,615*SY + ty,"hq");
    glVertex2f(703*SX+tx,597*SY + ty,"hq");
//bookshelf
    glColor3f(0.96,0.67,0.10);
    glVertex2f(1448*SX+tx,336*SY + ty,"hq");
    glVertex2f(1447*SX+tx,830*SY + ty,"hq");
    glVertex2f(1846*SX+tx,827*SY + ty,"hq");
    glVertex2f(1844*SX+tx,338*SY + ty,"hq");


// shelf1
    glColor3f(0.27,0.16,0.10);
    glVertex2f(1481*SX+tx,365*SY + ty,"hq");
    glVertex2f(1814*SX+tx,367*SY + ty,"hq");
    glVertex2f(1812*SX+tx,493*SY + ty,"hq");
    glVertex2f(1479*SX+tx,493*SY + ty,"hq");
// shelf2 and 3
    glVertex2f(1479*SX+tx,519*SY + ty,"hq");
    glVertex2f(1808*SX+tx,516*SY + ty,"hq");
    glVertex2f(1811*SX+tx,637*SY + ty,"hq");
    glVertex2f(1481*SX+tx,640*SY + ty,"hq");
    glVertex2f(1480*SX+tx,665*SY + ty,"hq");
    glVertex2f(1811*SX+tx,665*SY + ty,"hq");
    glVertex2f(1813*SX+tx,792*SY + ty,"hq");
    glVertex2f(1479*SX+tx,793*SY + ty,"hq");
// window
    glColor3f(1.00,1.00,1.00);
    glVertex2f(725*SX+tx,194*SY + ty,"hq");
    glVertex2f(1204*SX+tx,193*SY + ty,"hq");
    glVertex2f(1200*SX+tx,576*SY + ty,"hq");
    glVertex2f(723*SX+tx,576*SY + ty,"hq");
// window pane
    glColor3f(0.61,0.85,0.97);
    glVertex2f(754*SX+tx,216*SY + ty,"hq");
    glVertex2f(755*SX+tx,370*SY + ty,"hq");
    glVertex2f(949*SX+tx,373*SY + ty,"hq");
    glVertex2f(946*SX+tx,215*SY + ty,"hq");
    glVertex2f(981*SX+tx,215*SY + ty,"hq");
    glVertex2f(985*SX+tx,366*SY + ty,"hq");
    glVertex2f(1177*SX+tx,368*SY + ty,"hq");
    glVertex2f(1175*SX+tx,217*SY + ty,"hq");
    glVertex2f(754*SX+tx,402*SY + ty,"hq");
    glVertex2f(947*SX+tx,404*SY + ty,"hq");
    glVertex2f(946*SX+tx,550*SY + ty,"hq");
    glVertex2f(754*SX+tx,553*SY + ty,"hq");
    glVertex2f(980*SX+tx,402*SY + ty,"hq");
    glVertex2f(1174*SX+tx,401*SY + ty,"hq");
    glVertex2f(1175*SX+tx,556*SY + ty,"hq");
    glVertex2f(983*SX+tx,554*SY + ty,"hq");
// window shine
    glColor3f(0.75,0.90,1.00);
    glVertex2f(751*SX+tx,293*SY + ty,"hq");
    glVertex2f(751*SX+tx,344*SY + ty,"hq");
    glVertex2f(886*SX+tx,226*SY + ty,"hq");
    glVertex2f(824*SX+tx,225*SY + ty,"hq");
    SX=SX*0.2;
    SY=SY*0.2;
    tx=tx+200;
    ty=tx+225;
//tv set

//glTranslatef(1*SX,-50*SY,0);
    glColor3f(0.06,0.06,0.06);
    glVertex2f(69*SX+tx,5*SY + ty,"hq");
    glVertex2f(1764*SX+tx,4*SY + ty,"hq");
    glVertex2f(1764*SX+tx,860*SY + ty,"hq");
    glVertex2f(64*SX+tx,858*SY + ty,"hq");
    glColor3f(1,1,1);
    glVertex2f(91*SX+tx,22*SY + ty,"hq");
    glVertex2f(1750*SX+tx,20*SY + ty,"hq");
    glVertex2f(1743*SX+tx,841*SY + ty,"hq");
    glVertex2f(88*SX+tx,843*SY + ty,"hq");
    glColor3f(0.06,0.06,0.06);
    glVertex2f(605*SX+tx,859*SY + ty,"hq");
    glVertex2f(576*SX+tx,892*SY + ty,"hq");
    glVertex2f(1256*SX+tx,890*SY + ty,"hq");
    glVertex2f(1227*SX+tx,858*SY + ty,"hq");
    glEnd();


    SX=1;
    SY=1;
    tx=0;
    ty=0;

    glBegin(GL_POLYGON);
    glColor3f(0.91,0.18,0.18);
    glVertex2f(397*SX+tx,457*SY + ty,"hq");
    glVertex2f(346*SX+tx,509*SY + ty,"hq");
    glVertex2f(392*SX+tx,514*SY + ty,"hq");
    glVertex2f(350*SX+tx,563*SY + ty,"hq");
    glVertex2f(448*SX+tx,497*SY + ty,"hq");
    glVertex2f(401*SX+tx,494*SY + ty,"hq");
    glEnd();
//glBegin(GL_QUADS);
//glColor3f(0.90,0.40,0.27);
//glVertex2f(271*sx+tx ,141*sy + ty,"hq");
//glVertex2f(968*sx+tx ,59*sy + ty,"hq");
//glVertex2f(1652*sx+tx ,151*sy + ty,"hq");
//glVertex2f(263*sx+tx ,150*sy + ty,"hq");
//glEnd();
    glColor3f(0.27,0.27,0.27);

    glBegin(GL_POLYGON);
    glVertex2f(25*SX+tx,1025*SY + ty,"hq");
    glVertex2f(25*SX+tx,955*SY + ty,"hq");
    glVertex2f(1885*SX+tx,955*SY + ty,"hq");
    glVertex2f(1885*SX+tx,1025*SY + ty,"hq");
    glVertex2f(25*SX+tx,1025*SY + ty,"hq");
    glEnd();


    glColor3f(1,1,1);
    glBegin(GL_POLYGON);

    glVertex2f(30*SX+tx,1020*SY + ty,"hq");
    glVertex2f(30*SX+tx,960*SY + ty,"hq");
    glVertex2f(1880*SX+tx,960*SY + ty,"hq");
    glVertex2f(1880*SX+tx,1020*SY + ty,"hq");
    glVertex2f(30*SX+tx,1020*SY + ty,"hq");

    glEnd();



}

void kidplayingguitar(float tx, float ty, float sx, float sy)
{

    glPushMatrix();

    glTranslatef(1*sx+tx,-200*sy+ty,0);

    glColor3f(1.0,0.90,0.70);
    DrawCircle(1*sx,110*sy,40*sy,100*sy);//head
    glBegin(GL_POLYGON);
    glColor3f(0.43,0.24,0.07);//hair
    glVertex2f(-40*sx,133*sy);
    glVertex2f(40*sx,133*sy);
    glVertex2f(40*sx,160*sy);
    glVertex2f(30*sx,150*sy);
    glVertex2f(20*sx,160*sy);
    glVertex2f(10*sx,155*sy);
    glVertex2f(1*sx,160*sy);
    glVertex2f(-10*sx,150*sy);
    glVertex2f(-20*sx,160*sy);
    glVertex2f(-30*sx,150*sy);
    glVertex2f(-40*sx,160*sy);
    glEnd();




    glColor3f(0.0,0.0,0.0);
    DrawCircle(17*sx,120*sy,5*sx,100);//eyes

    glColor3f(0.0,0.0,0.0);
    DrawCircle(-17*sx,120*sy,5*sy,100);

    glBegin(GL_POLYGON);
    //Smile
    glVertex2d(-15*sx,100*sy);
    glVertex2d(-1*sx,95*sy);

    glVertex2d(17*sx,100*sy);
    glVertex2d(1*sx,mouth*sy);
    glVertex2d(-15*sx,100*sy);
    glEnd();

    glColor3f(0.7,0.00,0.00);
    glRectd(-50*sx,75*sy,+50*sx,-75*sy);//body
    glRectd(-80*sx,-55*sy,-50*sx,75*sy);//left arm
    glRectd(50*sx,75*sy,80*sx,-55*sy);//right arm

    glColor3f(1.0,0.90,0.70);
    glRectd(-80*sx,-55*sy,-50*sx,25*sy);//left arm
    glRectd(50*sx,25*sy,80*sx,-55*sy);//right arm





    glColor3f(0.,0.,0.);
    glRectd(-50*sx,-75*sy,-10*sx,-200*sy);//left leg
    glRectd(50*sx,-75*sy,10*sx,-200*sy);//right leg
    glRectd(50*sx,-75*sy,-50*sx,-110*sy);

    //belt
    glColor3f(0.5,0.5,0.1);
    glRectd(50*sx,-75*sy,-50*sx,-55*sy);



    //right foot
    glColor3f(0.,0.,0.);
    glBegin(GL_TRIANGLES);
    glVertex2f(50*sx,-200*sy);
    glVertex2f(10*sx,-200*sy);
    glVertex2f(0*sx,-230*sy);



    //left foot
    glVertex2f(-50*sx,-200*sy);
    glVertex2f(-10*sx,-200*sy);
    glVertex2f(-60*sx,-230*sy);

    glEnd();


    glTranslatef(-1*sx-tx,+200*sy-ty,0);
    //Hand Movement
    glPushMatrix();
    glTranslatef(65*sx+tx,-245*sy+ty,0);
    glColor3f(1.0,0.90,0.70);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_POLYGON);

    glVertex2f(-15*sx,30*sy);
    glVertex2f(15*sx,30*sy);
    glVertex2f(10*sx,-20*sy);
    glVertex2f(-10*sx,-20*sy);

    glEnd();
    glTranslatef(-65*sx-tx,+245*sy-ty,0);
    glPopMatrix();

    glTranslatef(+1*sx+tx,-200*sy+ty,0);

    //GUITAR RIGHT

    glPushMatrix();
    glTranslatef(-30*sx,100*sy,0);

    glRotatef(290+lightangle/6,0,0,1);
    displayguitar(-60,30,.6*sx,.6*sy,.5*sy,.5*sy,.5*sy);
    glTranslatef(30*sx,-70*sy,0);
    glPopMatrix();



    //right hand

    glTranslatef(-1*sx-tx,200*sy-ty,0);


    glPushMatrix();
    glTranslatef(-65*sx+tx,-245*sy+ty,0);
    glColor3f(1.0,0.90,0.70);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_POLYGON);

    glVertex2f(-15*sx,35*sy);
    glVertex2f(15*sx,35*sy);
    glVertex2f(10*sx,-50*sy);
    glVertex2f(-10*sx,-50*sy);

    glEnd();
    glTranslatef(+65*sx-tx,+245*sy-ty,0);
    glPopMatrix();



    //HUman End
    glPopMatrix();




}

void highschool(float tx,float ty,float sx,float sy)
{

    glColor3f(.5,0,0);
    glRectf(-960,-540,960,540);

    glBegin(GL_QUADS);

// floor
    glColor3f(0.1,0.1,0.1);
    glVertex2f(0*sx+tx,826*sy + ty,"hq");
    glVertex2f(1919*sx+tx,824*sy + ty,"hq");
    glColor3f(0.4,0.4,0.4);
    glVertex2f(1919*sx+tx,1080*sy + ty,"hq");
    glVertex2f(0*sx+tx,1080*sy + ty,"hq");

    glEnd();

//curtains
    glColor3f(.9,.9,.0);
    glBegin(GL_POLYGON);
    glVertex2f(-600,540);
    glVertex2f(-600,300);

    for(int i=0; i<59; i++)
        glVertex2f(-600+i*0.5,300-9.16*i);
    int j=1;

    for(int i=1; i<=12; i++)
    {
        if(j==0)
        {
            glVertex2f(-570-32.8*i,-241+25);
            j=1;
        }
        if(j==1)
        {
            glVertex2f(-570-32.8*i,-241);
            j=0;
        }
    }


    glVertex2f(-960,-241);
    glColor3f(.6,.6,.0);
    glVertex2f(-960,540);
    glEnd();

//cur2
    glBegin(GL_POLYGON);
    glColor3f(.8,.8,.0);
    glVertex2f(+600,540);
    glVertex2f(+600,300);
    for(int i=0; i<59; i++)
        glVertex2f(+600-i*0.5,300-9.16*i);
    j=1;
    for(int i=1; i<=12; i++)
    {
        if(j==0)
        {
            glVertex2f(+570+32.8*i,-241+25);
            j=1;
        }
        if(j==1)
        {
            glVertex2f(+570+32.8*i,-241);
            j=0;
        }
    }


    glVertex2f(+960,-241);
    glColor3f(.55,.55,.0);
    glVertex2f(+960,540);
    glEnd();

//Text
    glColor3f(1.,1.,1.);
    glRasterPos3f(-120, 300, 1);

    char *string="High School";
    for (char* c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);  // Updates the position
    }

}


float cou1=100;
int change=0;
float up=100;
void crack(float tx,float ty,float sx,float sy)
{
    if(change==0)
    {
        glColor3f(1,1,1);
        glPushMatrix();
        glTranslatef(-1*sx+tx,-200*sy+ty,0);
        glRectf(-5*sx,(0+up)*sy,5*sx,(100+up)*sy);
        glTranslatef(1*sx+tx,+200*sy-ty,0);
        glPopMatrix();
        cou1=cou1+2;
        up=up+2;
        if(cou1==200)
            change=1;
        printf("%d",up);

    }
    if(change==1)
    {
        glColor3f(1,0,0);

        glPushMatrix();
        glTranslatef(-1*sx+tx,1*sy+ty,0);
        glRotatef(0,0,0,1);
        glRectf(-5*sx,0+(up-200)*sy,5*sx,100+(up-200)*sy);
        glTranslatef(1*sx+tx,-1*sy-ty,0);
        glPopMatrix();

        glColor3f(1,1,0);
        glPushMatrix();
        glTranslatef(-1*sx+tx,1*sy+ty,0);
        glRotatef(30,0,0,1);
        glRectf(-5*sx,0+(up-200)*sy,5*sx,100+(up-200)*sy);
        glTranslatef(1*sx+tx,-1*sy-ty,0);
        glPopMatrix();

        glColor3f(0,1,0);
        glPushMatrix();
        glTranslatef(-1*sx+tx,1*sy+ty,0);
        glRotatef(60,0,0,1);
        glRectf(-5*sx,0+(up-200)*sy,5*sx,100+(up-200)*sy);
        glTranslatef(1*sx+tx,-1*sy-ty,0);
        glPopMatrix();

        glColor3f(0,1,1);
        glPushMatrix();
        glTranslatef(-1*sx+tx,1*sy+ty,0);
        glRotatef(90,0,0,1);
        glRectf(-5*sx,0+(up-200)*sy,5*sx,100+(up-200)*sy);
        glTranslatef(1*sx+tx,-1*sy-ty,0);
        glPopMatrix();

        glColor3f(1,0.,1);
        glPushMatrix();
        glTranslatef(-1*sx+tx,1*sy+ty,0);
        glRotatef(120,0,0,1);
        glRectf(-5*sx,0+(up-200)*sy,5*sx,100+(up-200)*sy);
        glTranslatef(1*sx+tx,-1*sy-ty,0);
        glPopMatrix();

        glColor3f(1,0,0.);
        glPushMatrix();
        glTranslatef(-1*sx+tx,1*sy+ty,0);
        glRotatef(150,0,0,1);
        glRectf(-5*sx,0+(up-200)*sy,5*sx,100+(up-200)*sy);
        glTranslatef(1*sx+tx,-1*sy-ty,0);
        glPopMatrix();

        glColor3f(1,1,0);
        glPushMatrix();
        glTranslatef(-1*sx+tx,1*sy+ty,0);
        glRotatef(180,0,0,1);
        glRectf(-5*sx,0+(up-200)*sy,5*sx,100+(up-200)*sy);
        glTranslatef(1*sx+tx,-1*sy-ty,0);
        glPopMatrix();

        glColor3f(0,1,0);
        glPushMatrix();
        glTranslatef(-1*sx+tx,1*sy+ty,0);
        glRotatef(210,0,0,1);
        glRectf(-5*sx,0+(up-200)*sy,5*sx,100+(up-200)*sy);
        glTranslatef(1*sx+tx,-1*sy-ty,0);
        glPopMatrix();

        glColor3f(0,1,1);
        glPushMatrix();
        glTranslatef(-1*sx+tx,1*sy+ty,0);
        glRotatef(240,0,0,1);
        glRectf(-5*sx,0+(up-200)*sy,5*sx,100+(up-200)*sy);
        glTranslatef(1*sx+tx,-1*sy-ty,0);
        glPopMatrix();

        glColor3f(0,0,1);
        glPushMatrix();
        glTranslatef(-1*sx+tx,1*sy+ty,0);
        glRotatef(270,0,0,1);
        glRectf(-5*sx,0+(up-200)*sy,5*sx,100+(up-200)*sy);
        glTranslatef(1*sx+tx,-1*sy-ty,0);
        glPopMatrix();

        glColor3f(1,0,1.0);
        glPushMatrix();
        glTranslatef(-1*sx+tx,1*sy+ty,0);
        glRotatef(300,0,0,1);
        glRectf(-5*sx,0+(up-200)*sy,5*sx,100+(up-200)*sy);
        glTranslatef(1*sx+tx,-1*sy-ty,0);
        glPopMatrix();

        glColor3f(1,1,0);
        glPushMatrix();
        glTranslatef(-1*sx+tx,1*sy+ty,0);
        glRotatef(330,0,0,1);
        glRectf(-5*sx,0+(up-200)*sy,5*sx,100+(up-200)*sy);
        glTranslatef(1*sx+tx,-1*sy-ty,0);
        glPopMatrix();







        cou1=cou1-1;
        up=up+.5;
        if(cou1==100)
        {
            change=0;
            up=100;
            cou1=100;
        }

        printf("%d",up);
    }

}

int gx=200;
void tvconcert(float tx,float ty,float SX,float SY)
{

    glColor3f(0.8,0.4,0);

    glBegin(GL_QUADS);
// wall
    glColor3f(0.45,0.79,0.91);
    glVertex2f(0*SX+tx,50*SY + ty,"hq");
    glVertex2f(1919*SX+tx,48*SY + ty,"hq");
    glVertex2f(1919*SX+tx,749*SY + ty,"hq");
    glVertex2f(1*SX+tx,749*SY + ty,"hq");
// floor
    glColor3f(0.53,0.60,0.63);
    glVertex2f(0*SX+tx,826*SY + ty,"hq");
    glVertex2f(1919*SX+tx,824*SY + ty,"hq");
    glVertex2f(1919*SX+tx,1002*SY + ty,"hq");
    glVertex2f(0*SX+tx,1003*SY + ty,"hq");
// table legs rear
    glColor3f(0.58,0.39,0.25);
    glVertex2f(245*SX+tx,652*SY + ty,"hq");
    glVertex2f(246*SX+tx,836*SY + ty,"hq");
    glVertex2f(261*SX+tx,836*SY + ty,"hq");
    glVertex2f(267*SX+tx,652*SY + ty,"hq");
    glVertex2f(607*SX+tx,650*SY + ty,"hq");
    glVertex2f(611*SX+tx,837*SY + ty,"hq");
    glVertex2f(624*SX+tx,838*SY + ty,"hq");
    glVertex2f(632*SX+tx,652*SY + ty,"hq");
    glEnd();
    glBegin(GL_QUADS);
//table legs front and lower wood
    glColor3f(0.71,0.45,0.31);
    glVertex2f(641*SX+tx,652*SY + ty,"hq");
    glVertex2f(645*SX+tx,836*SY + ty,"hq");
    glVertex2f(662*SX+tx,836*SY + ty,"hq");
    glVertex2f(666*SX+tx,652*SY + ty,"hq");
    glVertex2f(208*SX+tx,653*SY + ty,"hq");
    glVertex2f(213*SX+tx,839*SY + ty,"hq");
    glVertex2f(228*SX+tx,836*SY + ty,"hq");
    glVertex2f(232*SX+tx,652*SY + ty,"hq");
    glVertex2f(193*SX+tx,649*SY + ty,"hq");
    glVertex2f(682*SX+tx,651*SY + ty,"hq");
    glVertex2f(684*SX+tx,615*SY + ty,"hq");
    glVertex2f(196*SX+tx,615*SY + ty,"hq");
    glColor3f(0.75,0.49,0.33);
// table top
    glVertex2f(177*SX+tx,602*SY + ty,"hq");
    glVertex2f(175*SX+tx,615*SY + ty,"hq");
    glVertex2f(703*SX+tx,615*SY + ty,"hq");
    glVertex2f(703*SX+tx,597*SY + ty,"hq");
//bookshelf
    glColor3f(0.96,0.67,0.10);
    glVertex2f(1448*SX+tx,336*SY + ty,"hq");
    glVertex2f(1447*SX+tx,830*SY + ty,"hq");
    glVertex2f(1846*SX+tx,827*SY + ty,"hq");
    glVertex2f(1844*SX+tx,338*SY + ty,"hq");


// shelf1
    glColor3f(0.27,0.16,0.10);
    glVertex2f(1481*SX+tx,365*SY + ty,"hq");
    glVertex2f(1814*SX+tx,367*SY + ty,"hq");
    glVertex2f(1812*SX+tx,493*SY + ty,"hq");
    glVertex2f(1479*SX+tx,493*SY + ty,"hq");
// shelf2 and 3
    glVertex2f(1479*SX+tx,519*SY + ty,"hq");
    glVertex2f(1808*SX+tx,516*SY + ty,"hq");
    glVertex2f(1811*SX+tx,637*SY + ty,"hq");
    glVertex2f(1481*SX+tx,640*SY + ty,"hq");
    glVertex2f(1480*SX+tx,665*SY + ty,"hq");
    glVertex2f(1811*SX+tx,665*SY + ty,"hq");
    glVertex2f(1813*SX+tx,792*SY + ty,"hq");
    glVertex2f(1479*SX+tx,793*SY + ty,"hq");
// window
    glColor3f(1.00,1.00,1.00);
    glVertex2f(725*SX+tx,194*SY + ty,"hq");
    glVertex2f(1204*SX+tx,193*SY + ty,"hq");
    glVertex2f(1200*SX+tx,576*SY + ty,"hq");
    glVertex2f(723*SX+tx,576*SY + ty,"hq");
// window pane
    glColor3f(0.61,0.85,0.97);
    glVertex2f(754*SX+tx,216*SY + ty,"hq");
    glVertex2f(755*SX+tx,370*SY + ty,"hq");
    glVertex2f(949*SX+tx,373*SY + ty,"hq");
    glVertex2f(946*SX+tx,215*SY + ty,"hq");
    glVertex2f(981*SX+tx,215*SY + ty,"hq");
    glVertex2f(985*SX+tx,366*SY + ty,"hq");
    glVertex2f(1177*SX+tx,368*SY + ty,"hq");
    glVertex2f(1175*SX+tx,217*SY + ty,"hq");
    glVertex2f(754*SX+tx,402*SY + ty,"hq");
    glVertex2f(947*SX+tx,404*SY + ty,"hq");
    glVertex2f(946*SX+tx,550*SY + ty,"hq");
    glVertex2f(754*SX+tx,553*SY + ty,"hq");
    glVertex2f(980*SX+tx,402*SY + ty,"hq");
    glVertex2f(1174*SX+tx,401*SY + ty,"hq");
    glVertex2f(1175*SX+tx,556*SY + ty,"hq");
    glVertex2f(983*SX+tx,554*SY + ty,"hq");
// window shine
    glColor3f(0.75,0.90,1.00);
    glVertex2f(751*SX+tx,293*SY + ty,"hq");
    glVertex2f(751*SX+tx,344*SY + ty,"hq");
    glVertex2f(886*SX+tx,226*SY + ty,"hq");
    glVertex2f(824*SX+tx,225*SY + ty,"hq");
    SX=SX*0.2;
    SY=SY*0.2;
    tx=tx+200;
    ty=tx+225;
//tv set
    glColor3f(0.06,0.06,0.06);
    glVertex2f(69*SX+tx,5*SY + ty,"hq");
    glVertex2f(1764*SX+tx,4*SY + ty,"hq");
    glVertex2f(1764*SX+tx,860*SY + ty,"hq");
    glVertex2f(64*SX+tx,858*SY + ty,"hq");
    glColor3f(1,1,1);
    glVertex2f(91*SX+tx,22*SY + ty,"hq");
    glVertex2f(1750*SX+tx,20*SY + ty,"hq");
    glVertex2f(1743*SX+tx,841*SY + ty,"hq");
    glVertex2f(88*SX+tx,843*SY + ty,"hq");
    glColor3f(0.06,0.06,0.06);
    glVertex2f(605*SX+tx,859*SY + ty,"hq");
    glVertex2f(576*SX+tx,892*SY + ty,"hq");
    glVertex2f(1256*SX+tx,890*SY + ty,"hq");
    glVertex2f(1227*SX+tx,858*SY + ty,"hq");
    glEnd();

    SX=1;
    SY=1;
    tx=0;
    ty=0;

    glBegin(GL_POLYGON);
    glColor3f(0.91,0.18,0.18);
    glVertex2f(397*SX+tx,457*SY + ty,"hq");
    glVertex2f(346*SX+tx,509*SY + ty,"hq");
    glVertex2f(392*SX+tx,514*SY + ty,"hq");
    glVertex2f(350*SX+tx,563*SY + ty,"hq");
    glVertex2f(448*SX+tx,497*SY + ty,"hq");
    glVertex2f(401*SX+tx,494*SY + ty,"hq");
    glEnd();
//glBegin(GL_QUADS);
//glColor3f(0.90,0.40,0.27);
//glVertex2f(271*sx+tx ,141*sy + ty,"hq");
//glVertex2f(968*sx+tx ,59*sy + ty,"hq");
//glVertex2f(1652*sx+tx ,151*sy + ty,"hq");
//glVertex2f(263*sx+tx ,150*sy + ty,"hq");
//glEnd();
    glColor3f(0.27,0.27,0.27);

    glBegin(GL_POLYGON);
    glVertex2f(25*SX+tx,1025*SY + ty,"hq");
    glVertex2f(25*SX+tx,955*SY + ty,"hq");
    glVertex2f(1885*SX+tx,955*SY + ty,"hq");
    glVertex2f(1885*SX+tx,1025*SY + ty,"hq");
    glVertex2f(25*SX+tx,1025*SY + ty,"hq");
    glEnd();


    glColor3f(1,1,1);
    glBegin(GL_POLYGON);

    glVertex2f(30*SX+tx,1020*SY + ty,"hq");
    glVertex2f(30*SX+tx,960*SY + ty,"hq");
    glVertex2f(1880*SX+tx,960*SY + ty,"hq");
    glVertex2f(1880*SX+tx,1020*SY + ty,"hq");
    glVertex2f(30*SX+tx,1020*SY + ty,"hq");

    glEnd();

//Band
    glPushMatrix();
    glTranslatef(-575*SX,28*SY,0);
    stage(1,1,.17,0.15);
    displayBand(1,1,.17,.15);
    glTranslatef(575*SX,-28*SY,0);
    glPopMatrix();


    if(ta>ta_max)
    {
        gy=gy-.1;
        gg=gg-0.00001;
        gx=gx+1.2;
    }
    displayguitar(-100,-145,.45*SX,.45*SY,.45*SY,.45*SY,.45*SY);
    glPushMatrix();
    glScalef(-1,1,1);
    dispKidGuitar(ta-gx,-50-gy,1.3*gg,1.3*gg);

    glScalef(1,1,1);
    glPopMatrix();
}


//FirstLook

void firstlook(float tx,float ty,float sx,float sy)
{
    float r,g,b;
    r=g=b=0;

    printf("%d ",c);
    switch(c)
    {
    case 10:
    {
        r=1.0;
        g=0.0;
        b=0.0;
        cou++;
        if(cou==10)
        {
            c=20;
            cou=0;
        }
        break;
    }

    case 20:
    {
        r=1.0;
        g=1.0;
        b=0.0;
        cou++;
        if(cou==10)
        {
            c=30;
            cou=0;
        }
        break;
    }

    case 30:
    {
        r=0.0;
        g=1.0;
        b=0.0;
        cou++;
        if(cou==10)
        {
            c=40;
            cou=0;
        }
        break;
    }

    case 40:
    {
        r=0.0;
        g=1.0;
        b=1.0;
        cou++;
        if(cou==10)
        {
            c=50;
            cou=0;
        }
        break;
    }

    case 50:
    {
        r=0.0;
        g=0.0;
        b=1.0;
        cou++;
        if(cou==10)
        {
            c=60;
            cou=0;
        }
        break;
    }

    case 60:
    {
        r=1.0;
        g=0.0;
        b=1.0;
        cou++;
        if(cou==10)
        {
            c=10;
            cou=0;
        }
        break;
    }


    }




    glColor3f(r/5,g/5,b/5);
    //stage floor

    glBegin(GL_POLYGON);
    glVertex2d(-960*sx,-540*sy);
    glVertex2d(960*sx,-540*sy);
    glColor3f(r/2,g/2,b/2);
    glVertex2d(960*sx,-100*sy);
    glVertex2d(-960*sx,-100*sy);
    glEnd();

    //

    //stage background
    glColor3f(r/2,g/2,b/2);

    glBegin(GL_POLYGON);
    glVertex2d(-960*sx,540*sy);
    glVertex2d(960*sx,540*sy);
    glColor3f(r/5,g/5,b/5);
    glVertex2d(960*sx,-100*sy);
    glVertex2d(-960*sx,-100*sy);
    glEnd();


    //Back Lights
    glPushMatrix();

    glRotatef(lightangle,0,0,1);
    glBegin(GL_TRIANGLES);
    glColor3f(r,g,b);
    glVertex2f(1*sx*5,-100*sy*5);
    glColor3f(r/4,g/4,b/4);
    glVertex2f(-120*sx*5,450*sy*2);
    glVertex2f(+120*sx*5,450*sy*2);
    glEnd();

    glPopMatrix();

    //Human2


    glColor3f(1.0,0.90,0.70);
    DrawCircle(1*sx,110*sy,40*sy,100*sy);//head

    glBegin(GL_POLYGON);
    glColor3f(0.43,0.24,0.07);//hair
    glVertex2f(-40*sx,133*sy);
    glVertex2f(40*sx,133*sy);
    glVertex2f(40*sx,160*sy);
    glVertex2f(30*sx,150*sy);
    glVertex2f(20*sx,160*sy);
    glVertex2f(10*sx,155*sy);
    glVertex2f(1*sx,160*sy);
    glVertex2f(-10*sx,150*sy);
    glVertex2f(-20*sx,160*sy);
    glVertex2f(-30*sx,150*sy);
    glVertex2f(-40*sx,160*sy);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    DrawCircle(17*sx,120*sy,5*sx,100);//eyes

    glColor3f(0.0,0.0,0.0);
    DrawCircle(-17*sx,120*sy,5*sy,100);

    glBegin(GL_POLYGON);
    //Smile
    glVertex2d(-15*sx,100*sy);
    glVertex2d(-1*sx,95*sy);

    glVertex2d(17*sx,100*sy);
    glVertex2d(1*sx,90*sy);
    glVertex2d(-15*sx,100*sy);
    glEnd();

    glColor3f(1.0,0.00,0.00);
    glRectd(-50*sx,75*sy,+50*sx,-75*sy);//body
    glRectd(-80*sx,-55*sy,-50*sx,75*sy);//left arm
    glRectd(50*sx,75*sy,80*sx,-55*sy);//right arm

    glColor3f(.0,0.00,0.00);
    glRectd(-20*sx,70*sy,+20*sx,-75*sy);//body

    glColor3f(0.,0.,0.);
    glRectd(-50*sx,-75*sy,-10*sx,-250*sy);//left leg
    glRectd(50*sx,-75*sy,10*sx,-250*sy);//right leg
    glRectd(50*sx,-75*sy,-50*sx,-110*sy);





    //right foot
    glColor3f(0.,0.,0.);
    glBegin(GL_TRIANGLES);
    glVertex2f(50*sx,-250*sy);
    glVertex2f(10*sx,-250*sy);
    glVertex2f(0*sx,-280*sy);



    //left foot
    glVertex2f(-50*sx,-250*sy);
    glVertex2f(-10*sx,-250*sy);
    glVertex2f(-60*sx,-280*sy);

    glEnd();

    //hand
    //hand
    glTranslatef(1*sx,+100*sy,0);
    //Hand Movement
    glPushMatrix();
    glTranslatef(65*sx,-145*sy,0);
    glColor3f(1.0,0.0,0.0);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_POLYGON);

    glVertex2f(-15*sx,30*sy);
    glVertex2f(15*sx,30*sy);
    glVertex2f(10*sx,-10*sy);
    glVertex2f(-10*sx,-10*sy);


    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);

    glVertex2f(10*sx,-10*sy);
    glVertex2f(10*sx,-30*sy);
    glVertex2f(1*sx,-20*sy);

    glVertex2f(-10*sx,-30*sy);
    glVertex2f(-10*sx,-10*sy);


    glEnd();
    glTranslatef(-65*sx,+145*sy,0);
    glPopMatrix();


    //GUITAR RIGHT

    glPushMatrix();
    glTranslatef(-30*sx,70*sy,0);

    glRotatef(290+lightangle/6,0,0,1);
    displayguitar(1,1,.6*sx,.6*sy,.5*sy,.5*sy,.5*sy);
    glTranslatef(30*sx,-70*sy,0);
    glPopMatrix();

    //left handing moving
    glPushMatrix();
    glTranslatef(-65*sx,-145*sy,0);
    glColor3f(1.0,0.0,0.0);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_POLYGON);

    glVertex2f(-15*sx,30*sy);
    glVertex2f(15*sx,30*sy);
    glVertex2f(10*sx,-35*sy);
    glVertex2f(-10*sx,-35*sy);

    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);

    glVertex2f(10*sx,-30*sy);
    glVertex2f(10*sx,-45*sy);
    glVertex2f(1*sx,-35*sy);

    glVertex2f(-10*sx,-45*sy);
    glVertex2f(-10*sx,-30*sy);


    glEnd();
    glTranslatef(+65*sx,+145*sy,0);
    glPopMatrix();


    glTranslatef(-1*sx,-100*sy,0);


    //HUman End




}


//KID's BAND
void kidband(float tx,float ty,float sx,float sy)
{

    if(mouthc==0)
    {
        mouth+=0.5;
        if(mouth>=100)
            mouthc=1;
    }
    if(mouthc==1)
    {
        mouth-=0.5;
        if(mouth<=90)
            mouthc=0;
    }
    //Human singer

    glTranslatef(1*sx,-100*sy,0);
    glColor3f(1.0,0.90,0.70);
    DrawCircle(1*sx,110*sy,40*sy,100*sy);//head

    glBegin(GL_POLYGON);
    glColor3f(0.74,0.52,0.32);//hair
    glVertex2f(-40*sx,133*sy);
    glVertex2f(40*sx,133*sy);
    glVertex2f(40*sx,160*sy);
    glVertex2f(30*sx,150*sy);
    glVertex2f(20*sx,160*sy);
    glVertex2f(10*sx,155*sy);
    glVertex2f(1*sx,160*sy);
    glVertex2f(-10*sx,150*sy);
    glVertex2f(-20*sx,160*sy);
    glVertex2f(-30*sx,150*sy);
    glVertex2f(-40*sx,160*sy);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    DrawCircle(17*sx,120*sy,5*sx,100);//eyes

    glColor3f(0.0,0.0,0.0);
    DrawCircle(-17*sx,120*sy,5*sy,100);

    glBegin(GL_POLYGON);
    //Smile
    glVertex2d(-15*sx,100*sy);
    glVertex2d(-1*sx,95*sy);

    glVertex2d(17*sx,100*sy);
    glVertex2d(1*sx,mouth*sy);
    glVertex2d(-15*sx,100*sy);
    glEnd();

    glColor3f(1.0,1.0,0.);
    glRectd(-50*sx,75*sy,+50*sx,-75*sy);//body
    glRectd(-80*sx,-55*sy,-50*sx,75*sy);//left arm
    glRectd(50*sx,75*sy,80*sx,-55*sy);//right arm

    glColor3f(0.,0.,0.);
    glRectd(-20*sx,70*sy,+20*sx,-75*sy);//body




    glColor3f(0.,0.,0.);
    glRectd(-50*sx,-75*sy,-10*sx,-250*sy);//left leg
    glRectd(50*sx,-75*sy,10*sx,-250*sy);//right leg
    glRectd(50*sx,-75*sy,-50*sx,-110*sy);





    //right foot
    glColor3f(0.,0.,0.);
    glBegin(GL_TRIANGLES);
    glVertex2f(50*sx,-250*sy);
    glVertex2f(10*sx,-250*sy);
    glVertex2f(0*sx,-280*sy);



    //left foot
    glVertex2f(-50*sx,-250*sy);
    glVertex2f(-10*sx,-250*sy);
    glVertex2f(-60*sx,-280*sy);

    glEnd();

    //hand
    glTranslatef(-1*sx,+100*sy,0);
    //Hand Movement
    glPushMatrix();
    glTranslatef(65*sx,-145*sy,0);
    glColor3f(1.0,0.90,0.70);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_POLYGON);

    glVertex2f(-15*sx,30*sy);
    glVertex2f(15*sx,30*sy);
    glVertex2f(10*sx,-50*sy);
    glVertex2f(-10*sx,-50*sy);

    glEnd();
    glTranslatef(-65*sx,+145*sy,0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-65*sx,-145*sy,0);
    glColor3f(1.0,0.90,0.70);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_POLYGON);

    glVertex2f(-15*sx,30*sy);
    glVertex2f(15*sx,30*sy);
    glVertex2f(10*sx,-50*sy);
    glVertex2f(-10*sx,-50*sy);

    glEnd();
    glTranslatef(+65*sx,+145*sy,0);
    glPopMatrix();


    glTranslatef(+1*sx,-100*sy,0);

    //right hand

    glTranslatef(-1*sx,100*sy,0);
    //HUman End

    //Mic
    glTranslatef(1*sx,-100*sy,0);
    glColor3f(.6,.6,.6);
    glBegin(GL_POLYGON);
    glVertex2f(-24*sx,-290*sy);
    glVertex2f(-15*sx,-290*sy);
    glVertex2f(-15*sx,65*sy);
    glVertex2f(-24*sx,65*sy);
    glEnd();

    glBegin(GL_TRIANGLES);//mic
    glVertex2f(-0*sx,70*sy);
    glVertex2f(-10*sx,90*sy);
    glVertex2f(-60*sx,50*sy);
    DrawCircle(-5*sx,80*sy,10*sx,100);

    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-60*sx,-290*sy);
    glVertex2f(-60*sx,-305*sy);
    glVertex2f(26*sx,-305*sy);
    glVertex2f(26*sx,-290*sy);

    glEnd();
    glTranslatef(-1*sx,100*sy,0);




    //Human2
    glTranslatef(600*sx,25*sy,0);
    glColor3f(1.0,0.90,0.70);
    DrawCircle(1*sx,110*sy,40*sy,100*sy);//head

    glBegin(GL_POLYGON);
    glColor3f(0.43,0.24,0.07);//hair
    glVertex2f(-40*sx,133*sy);
    glVertex2f(40*sx,133*sy);
    glVertex2f(40*sx,160*sy);
    glVertex2f(30*sx,150*sy);
    glVertex2f(20*sx,160*sy);
    glVertex2f(10*sx,155*sy);
    glVertex2f(1*sx,160*sy);
    glVertex2f(-10*sx,150*sy);
    glVertex2f(-20*sx,160*sy);
    glVertex2f(-30*sx,150*sy);
    glVertex2f(-40*sx,160*sy);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    DrawCircle(17*sx,120*sy,5*sx,100);//eyes

    glColor3f(0.0,0.0,0.0);
    DrawCircle(-17*sx,120*sy,5*sy,100);

    glBegin(GL_POLYGON);
    //Smile
    glVertex2d(-15*sx,100*sy);
    glVertex2d(-1*sx,95*sy);

    glVertex2d(17*sx,100*sy);
    glVertex2d(1*sx,90*sy);
    glVertex2d(-15*sx,100*sy);
    glEnd();

    glColor3f(1.0,0.00,0.00);
    glRectd(-50*sx,75*sy,+50*sx,-75*sy);//body
    glRectd(-80*sx,-55*sy,-50*sx,75*sy);//left arm
    glRectd(50*sx,75*sy,80*sx,-55*sy);//right arm

    glColor3f(.0,0.00,0.00);
    glRectd(-20*sx,70*sy,+20*sx,-75*sy);//body

    glColor3f(0.,0.,0.);
    glRectd(-50*sx,-75*sy,-10*sx,-250*sy);//left leg
    glRectd(50*sx,-75*sy,10*sx,-250*sy);//right leg
    glRectd(50*sx,-75*sy,-50*sx,-110*sy);





    //right foot
    glColor3f(0.,0.,0.);
    glBegin(GL_TRIANGLES);
    glVertex2f(50*sx,-250*sy);
    glVertex2f(10*sx,-250*sy);
    glVertex2f(0*sx,-280*sy);



    //left foot
    glVertex2f(-50*sx,-250*sy);
    glVertex2f(-10*sx,-250*sy);
    glVertex2f(-60*sx,-280*sy);

    glEnd();

    //hand
    //hand
    glTranslatef(1*sx,+100*sy,0);
    //Hand Movement
    glPushMatrix();
    glTranslatef(65*sx,-145*sy,0);
    glColor3f(1.0,0.0,0.0);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_POLYGON);

    glVertex2f(-15*sx,30*sy);
    glVertex2f(15*sx,30*sy);
    glVertex2f(10*sx,-10*sy);
    glVertex2f(-10*sx,-10*sy);


    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);

    glVertex2f(10*sx,-10*sy);
    glVertex2f(10*sx,-30*sy);
    glVertex2f(1*sx,-20*sy);

    glVertex2f(-10*sx,-30*sy);
    glVertex2f(-10*sx,-10*sy);


    glEnd();
    glTranslatef(-65*sx,+145*sy,0);
    glPopMatrix();


    //GUITAR RIGHT

    glPushMatrix();
    glTranslatef(-30*sx,70*sy,0);

    glRotatef(290+lightangle/6,0,0,1);
    displayguitar(1,1,.6*sx,.6*sy,.5*sy,.5*sy,.5*sy);
    glTranslatef(30*sx,-70*sy,0);
    glPopMatrix();

    //left handing moving
    glPushMatrix();
    glTranslatef(-65*sx,-145*sy,0);
    glColor3f(1.0,0.0,0.0);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_POLYGON);

    glVertex2f(-15*sx,30*sy);
    glVertex2f(15*sx,30*sy);
    glVertex2f(10*sx,-30*sy);
    glVertex2f(-10*sx,-30*sy);

    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);

    glVertex2f(10*sx,-30*sy);
    glVertex2f(10*sx,-45*sy);
    glVertex2f(1*sx,-35*sy);

    glVertex2f(-10*sx,-45*sy);
    glVertex2f(-10*sx,-30*sy);


    glEnd();
    glTranslatef(+65*sx,+145*sy,0);
    glPopMatrix();


    glTranslatef(-1*sx,-100*sy,0);

    glTranslatef(-600*sx,-25*sy,0);

    //HUman End







    //Human3 drums

    glTranslatef(-400*sx,75*sy,0);
    glColor3f(1.0,0.90,0.70);
    DrawCircle(1*(sx-.20),110*(sy-.20),40*(sx-.20),100);//head
    glTranslatef(-1*sx,-30*sy,0);
    glBegin(GL_POLYGON);
    glColor3f(0.8,0.6,0.4);//hair
    glVertex2f(-30*sx,133*sy);
    glVertex2f(30*sx,133*sy);
    glVertex2f(40*sx,160*sy);
    glVertex2f(30*sx,150*sy);
    glVertex2f(20*sx,160*sy);
    glVertex2f(10*sx,155*sy);
    glVertex2f(1*sx,160*sy);
    glVertex2f(-10*sx,150*sy);
    glVertex2f(-20*sx,160*sy);
    glVertex2f(-30*sx,150*sy);
    glVertex2f(-30*sx,160*sy);
    glEnd();
    glTranslatef(1*sx,+30*sy,0);
    glColor3f(0.0,0.0,0.0);
    DrawCircle(17*(sx-.20),120*(sy-.20),5*(sx-.20),100);//eyes

    glColor3f(0.0,0.0,0.0);
    DrawCircle(-17*(sx-.20),120*(sy-.20),5*(sx-.20),100);

    glBegin(GL_POLYGON);
    //Smile
    glVertex2d(-15*(sx-.20),100*(sy-.20));
    glVertex2d(-1*(sx-.20),95*(sy-.20));

    glVertex2d(17*(sx-.20),100*(sy-.20));
    glVertex2d(1*(sx-.20),90*(sy-.20));
    glVertex2d(-15*(sx-.20),100*(sy-.20));
    glEnd();

    glColor3f(.0,0.00,1.00);
    glRectd(-50*(sx-.20),75*(sy-.20),+50*(sx-.20),-75*(sy-.20));//body
    glRectd(-80*(sx-.20),-1*(sy-.20),-50*(sx-.20),75*(sy-.20));//left arm
    glRectd(50*(sx-.20),75*(sy-.20),80*(sx-.20),1*(sy-.20));//right arm


    glColor3f(.0,0.00,.00);
    glRectd(-20*(sx-.20),70*(sy-.20),+20*(sx-.20),-75*(sy-.20));//body

    glColor3f(0.,0.,0.);
    glRectd(-50*(sx-.20),-75*(sy-.20),-10*(sx-.20),-250*(sy-.20));//left leg
    glRectd(50*(sx-.20),-75*(sy-.20),10*(sx-.20),-250*(sy-.20));//right leg
    glRectd(50*(sx-.20),-75*(sy-.20),-50*(sx-.20),-110*(sy-.20));

    //belt
    glColor3f(0.5,0.5,0.1);
    glRectd(50*(sx-.20),-75*(sy-.20),-50*(sx-.20),-55*(sy-.20));



    //right foot
    glColor3f(0.,0.,0.);
    glBegin(GL_TRIANGLES);
    glVertex2f(50*(sx-.20),-250*(sy-.20));
    glVertex2f(10*(sx-.20),-250*(sy-.20));
    glVertex2f(0*(sx-.20),-280*(sy-.20));



    //left foot
    glVertex2f(-50*(sx-.20),-250*(sy-.20));
    glVertex2f(-10*(sx-.20),-250*(sy-.20));
    glVertex2f(-60*(sx-.20),-280*(sy-.20));

    glEnd();

    //hand
    glTranslatef(1*sx,+100*sy,0);
    //Hand Movement
    glPushMatrix();
    glTranslatef(65*(sx-.20),-145*(sy-.20),0);
    glColor3f(1.0,0.90,0.70);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_POLYGON);

    glVertex2f(-15*(sx-.20),30*(sy-.20));
    glVertex2f(15*(sx-.20),30*(sy-.20));
    glVertex2f(10*(sx-.20),-50*(sy-.20));
    glVertex2f(-10*(sx-.20),-50*(sy-.20));

    glEnd();
    glTranslatef(-65*(sx-.20),+145*(sy-.20),0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-65*(sx-.20),-145*(sy-.20),0);
    glColor3f(1.0,0.90,0.70);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_POLYGON);

    glVertex2f(-15*(sx-.20),30*(sy-.20));
    glVertex2f(15*(sx-.20),30*(sy-.20));
    glVertex2f(10*(sx-.20),-50*(sy-.20));
    glVertex2f(-10*(sx-.20),-50*(sy-.20));

    glEnd();
    glTranslatef(+65*(sx-.20),+145*(sy-.20),0);
    glPopMatrix();


    glTranslatef(-1*sx,-100*sy,0);
    glTranslatef(400*sx,-75*sy,0);
    //HUman End

    //drums
    glTranslatef(-400*sx,+75*sy,0);
    glColor3f(.4,.4,.4);
    DrawCircle(0*sx,-150*sy,100*sy,100);

    glBegin(GL_POLYGON);
    glVertex2f(-240*sx,-230*sy);
    glVertex2f(-240*sx,-250*sy);
    glVertex2f(240*sx,-250*sy);
    glVertex2f(240*sx,-230*sy);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(117*sx,-230*sy);
    glVertex2f(123*sx,-230*sy);
    glVertex2f(123*sx,-40*sy);
    glVertex2f(117*sx,-40*sy);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(60*sx,-11*sy);
    glVertex2f(150*sx,-11*sy);
    glVertex2f(160*sx,-50*sy);
    glVertex2f(70*sx,-50*sy);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(193*sx,-230*sy);
    glVertex2f(187*sx,-230*sy);
    glVertex2f(187*sx,10*sy);
    glVertex2f(193*sx,10*sy);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(190*sx,10*sy);
    glVertex2f(110*sx,20*sy);
    glVertex2f(190*sx,30*sy);
    glVertex2f(270*sx,20*sy);

    glEnd();


    //left
    glBegin(GL_POLYGON);
    glVertex2f(-117*sx,-230*sy);
    glVertex2f(-123*sx,-230*sy);
    glVertex2f(-123*sx,-40*sy);
    glVertex2f(-117*sx,-40*sy);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-193*sx,-230*sy);
    glVertex2f(-187*sx,-230*sy);
    glVertex2f(-187*sx,10*sy);
    glVertex2f(-193*sx,10*sy);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-60*sx,-11*sy);
    glVertex2f(-150*sx,-11*sy);
    glVertex2f(-160*sx,-50*sy);
    glVertex2f(-70*sx,-50*sy);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-190*sx,10*sy);
    glVertex2f(-110*sx,20*sy);
    glVertex2f(-190*sx,30*sy);
    glVertex2f(-270*sx,20*sy);

    glEnd();

    glTranslatef(400*sx,-75*sy,0);


    //Human4

    glTranslatef(-800*sx,-1*sy,0);
    glColor3f(1.0,0.90,0.70);
    DrawCircle(1*sx,110*sy,40*sy,100*sy);//head


    glBegin(GL_POLYGON);
    glColor3f(0.9,0.4,0.5);//hair
    glVertex2f(-40*sx,133*sy);
    glVertex2f(40*sx,133*sy);
    glVertex2f(40*sx,160*sy);
    glVertex2f(30*sx,150*sy);
    glVertex2f(20*sx,160*sy);
    glVertex2f(10*sx,155*sy);
    glVertex2f(1*sx,160*sy);
    glVertex2f(-10*sx,150*sy);
    glVertex2f(-20*sx,160*sy);
    glVertex2f(-30*sx,150*sy);
    glVertex2f(-40*sx,160*sy);
    glEnd();


    glColor3f(0.0,0.0,0.0);
    DrawCircle(17*sx,120*sy,5*sx,100);//eyes

    glColor3f(0.0,0.0,0.0);
    DrawCircle(-17*sx,120*sy,5*sy,100);

    glBegin(GL_POLYGON);
    //Smile
    glVertex2d(-15*sx,100*sy);
    glVertex2d(-1*sx,95*sy);

    glVertex2d(17*sx,100*sy);
    glVertex2d(1*sx,90*sy);
    glVertex2d(-15*sx,100*sy);
    glEnd();

    glColor3f(.0,1.00,0.00);
    glRectd(-50*sx,75*sy,+50*sx,-75*sy);//body
    glRectd(-80*sx,-55*sy,-50*sx,75*sy);//left arm
    glRectd(50*sx,75*sy,80*sx,-55*sy);//right arm

    glColor3f(.0,0.00,0.00);
    glRectd(-20*sx,70*sy,+20*sx,-75*sy);//body

    glColor3f(0.,0.,0.);
    glRectd(-50*sx,-75*sy,-10*sx,-250*sy);//left leg
    glRectd(50*sx,-75*sy,10*sx,-250*sy);//right leg
    glRectd(50*sx,-75*sy,-50*sx,-110*sy);





    //right foot
    glColor3f(0.,0.,0.);
    glBegin(GL_TRIANGLES);
    glVertex2f(50*sx,-250*sy);
    glVertex2f(10*sx,-250*sy);
    glVertex2f(0*sx,-280*sy);



    //left foot
    glVertex2f(-50*sx,-250*sy);
    glVertex2f(-10*sx,-250*sy);
    glVertex2f(-60*sx,-280*sy);

    glEnd();

    //hand
    //hand
    glTranslatef(1*sx,+100*sy,0);
    //Hand Movement
    glPushMatrix();
    glTranslatef(65*sx,-145*sy,0);
    glColor3f(.0,1.0,0.0);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_POLYGON);

    glVertex2f(-15*sx,30*sy);
    glVertex2f(15*sx,30*sy);
    glVertex2f(10*sx,-10*sy);
    glVertex2f(-10*sx,-10*sy);


    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);

    glVertex2f(10*sx,-10*sy);
    glVertex2f(10*sx,-30*sy);
    glVertex2f(1*sx,-20*sy);

    glVertex2f(-10*sx,-30*sy);
    glVertex2f(-10*sx,-10*sy);


    glEnd();
    glTranslatef(-65*sx,+145*sy,0);
    glPopMatrix();


    //GUITAR RIGHT

    glPushMatrix();
    glTranslatef(-30*sx,70*sy,0);

    glRotatef(290+lightangle/6,0,0,1);
    displayguitar(1,1,.6*sx,.6*sy,.5*sy,.5*sy,.5*sy);
    glTranslatef(30*sx,-70*sy,0);
    glPopMatrix();

    //left handing moving
    glPushMatrix();
    glTranslatef(-65*sx,-145*sy,0);
    glColor3f(.0,1.0,0.0);
    glRotatef(lightangle,0,0,1);
    glBegin(GL_POLYGON);

    glVertex2f(-15*sx,30*sy);
    glVertex2f(15*sx,30*sy);
    glVertex2f(10*sx,-30*sy);
    glVertex2f(-10*sx,-30*sy);

    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);

    glVertex2f(10*sx,-30*sy);
    glVertex2f(10*sx,-45*sy);
    glVertex2f(1*sx,-35*sy);

    glVertex2f(-10*sx,-45*sy);
    glVertex2f(-10*sx,-30*sy);


    glEnd();
    glTranslatef(+65*sx,+145*sy,0);
    glPopMatrix();


    glTranslatef(-1*sx,-100*sy,0);
    glTranslatef(800*sx,+1*sy,0);
    //HUman End








}

void displayaudience(int a1, int a2, int b1,int b2, int c1,int c2, int d1,int d2,int hm,int i,float siz, float hmx)
{

    int cp[4][2]= {{a1,a2},{b1,b2},{c1,c2},{d1,d2}};
    int c[4],k,n=3;
    float x,y,u,blend;
    bezierCoefficients(n,c);
    // generate random color for audience in timer

    glColor3f(cl1[i],cl2[i],cl3[i]);
    glLineWidth(1.0);
    glBegin(GL_POLYGON);

    for(u=0; u<1.0; u+=0.01)
    {
        x=0;
        y=0;
        for(k=0; k<4; k++)
        {
            blend=c[k]*pow(u,k)*pow(1-u,n-k);
            x+=cp[k][0]*blend;
            y+=cp[k][1]*blend;
        }

//        DrawCircle()
        glVertex2f(x,y,"hq");

    }
    glEnd();
    glColor3f(0.92,0.74,0.55);
    DrawCircle(a1-1000+hmx,-a2/2+hm,40*siz,20);
}


//new crowd
void displaycrowd1(float txx, float ty, int hm, float sx,float hmx)
{
    float tx;
    for(int j=0; j<3; j++)
    {
        if(j==1)
            hm-=40;
        if(j==2)
            hm-=50;
        for( int i =0 ; i<24; i++)
        {
            tx=i+moveaudience;
            if(j==1)
                tx=i-moveaudience;
            displayaudience((1920-tx*80)*sx+txx,(1080-ty)*sx,(1920-tx*80)*sx+txx,(980-ty)*sx,(1840-tx*80)*sx+txx,(980-ty)*sx,(1840-tx*80)*sx+txx,(1080-ty)*sx,hm*sx,i*(j+1),sx,hmx);
        }
        ty=ty-80;
    }
}

//FAR VIEW
void farconcert()
{


    //Background Home Ground
    glColor3f(0.09,0.70,0.30);
    glBegin(GL_POLYGON);
    glVertex2d(-960,-540);
    glVertex2d(960,-540);
    glVertex2d(960,400);
    glVertex2d(-960,400);
    glEnd();

    //

    //Sky
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-960,540);
    glVertex2d(960,540);
    glVertex2d(960,-100);
    glVertex2d(-960,-100);
    glEnd();

//Background Home Ground
    glColor3f(0.09,0.70,0.30);
    glBegin(GL_POLYGON);
    glVertex2d(-960,-540);
    glVertex2d(960,-540);
    glColor3f(0.02,0.30,0.15);
    glVertex2d(960,50);
    glVertex2d(-960,50);
    glEnd();

    crack(-801,400,0.6,0.6);
    crack(-401,400,0.6,0.6);

    crack(-601,200,0.4,0.4);
    crack(0,400,0.9,0.9);
    crack(801,400,0.6,0.6);

    crack(401,400,0.6,0.6);
    crack(601,200,0.4,0.4);

    justlights(-600,0,.4,.4);
    justlights(600,0,.4,.4);


    float SX=0.3,SY=0.3;
//   cout<<" DISPLAY STAGE \n";
    glColor3f(0.33,0.37,0.50);
    glLineWidth(3.0);
    float sx=1, sy=1, tx=0, ty=0 ;





    sx=sy=0.8;
//    glPushMatrix();
//    glTranslatef(-1*SX,50*SY,0);
    tx+=700;
    for(int i=0; i<900; i=i+100)
    {

        ty=-i*sx*SX+200+150;

        glBegin(GL_LINE_LOOP);
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,718*sy*SY + ty,"hq");
        glEnd();
    }

    for(int i=0; i<2000; i=i+100)
    {
        tx=i*sx*SX+700;
        glBegin(GL_LINE_LOOP);
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,718*sy*SY + ty,"hq");
        glEnd();
    }
    for(int i=0; i<900; i=i+100)
    {

        ty=-i*sx*SX+200+150;
        glBegin(GL_LINE_LOOP);
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,718*sy*SY + ty,"hq");
        glVertex2f(320*sx*SX+tx,618*sy*SY + ty,"hq");
        glVertex2f(220*sx*SX+tx,718*sy*SY + ty,"hq");
        glEnd();
    }
//    glTranslatef(1*SX,-50*SY,0);
//    glPopMatrix();

    //Band
//    glPushMatrix();
//glTranslatef(20*sx*SX,160*sy*SY,0);
//stage(1,1,.745,0.6);
//glTranslatef(-20*sx*SX,-160*sy*SY,0);
//glPopMatrix();

    //Band
    glPushMatrix();
    glTranslatef(140*sx*SX,370*sy*SY,0);
    stage(1,1,.22,0.22);
    kidband(1,1,.22,0.22);
    glTranslatef(-140*sx*SX,-370*sy*SY,0);
    glPopMatrix();




// add  value to ty if  u need more stage space
    ty=+350;
    tx=+705;
    sy=1;
    sx=1;
    glBegin(GL_QUADS);
    glColor3f(0.93,0.57,0.53);
    glVertex2f(252*sx*SX+tx,625*sy*SY + ty,"hq");
    glVertex2f(355*sx*SX+tx,597*sy*SY + ty,"hq");
    glVertex2f(551*sx*SX+tx,601*sy*SY + ty,"hq");
    glVertex2f(426*sx*SX+tx,641*sy*SY + ty,"hq");
    glVertex2f(424*sx*SX+tx,667*sy*SY + ty,"hq");
    glVertex2f(561*sx*SX+tx,613*sy*SY + ty,"hq");
    glVertex2f(1357*sx*SX+tx,613*sy*SY + ty,"hq");
    glVertex2f(1508*sx*SX+tx,666*sy*SY + ty,"hq");
    glVertex2f(1373*sx*SX+tx,598*sy*SY + ty,"hq");
    glVertex2f(1554*sx*SX+tx,598*sy*SY + ty,"hq");
    glVertex2f(1670*sx*SX+tx,625*sy*SY + ty,"hq");
    glVertex2f(1493*sx*SX+tx,641*sy*SY + ty,"hq");
    glColor3f(0.58,0.24,0.45);
    glVertex2f(238*sx*SX+tx,625*sy*SY + ty,"hq");
    glVertex2f(244*sx*SX+tx,795*sy*SY + ty,"hq");
    glVertex2f(420*sx*SX+tx,829*sy*SY + ty,"hq");
    glVertex2f(425*sx*SX+tx,644*sy*SY + ty,"hq");
    glColor3f(0.71,0.34,0.55);
    glVertex2f(414*sx*SX+tx,647*sy*SY + ty,"hq");
    glVertex2f(549*sx*SX+tx,601*sy*SY + ty,"hq");
    glVertex2f(558*sx*SX+tx,612*sy*SY + ty,"hq");
    glVertex2f(418*sx*SX+tx,662*sy*SY + ty,"hq");
    glVertex2f(1358*sx*SX+tx,611*sy*SY + ty,"hq");
    glVertex2f(1366*sx*SX+tx,601*sy*SY + ty,"hq");
    glVertex2f(1493*sx*SX+tx,642*sy*SY + ty,"hq");
    glVertex2f(1487*sx*SX+tx,659*sy*SY + ty,"hq");
    glColor3f(0.58,0.22,0.45);
    glVertex2f(1495*sx*SX+tx,647*sy*SY + ty,"hq");
    glVertex2f(1492*sx*SX+tx,822*sy*SY + ty,"hq");
    glVertex2f(1652*sx*SX+tx,792*sy*SY + ty,"hq");
    glVertex2f(1674*sx*SX+tx,628*sy*SY + ty,"hq");
    glColor3f(0.88,0.40,0.51);
    glVertex2f(419*sx*SX+tx,678*sy*SY + ty,"hq");
    glVertex2f(424*sx*SX+tx,844*sy*SY + ty,"hq");
    glVertex2f(1514*sx*SX+tx,838*sy*SY + ty,"hq");
    glVertex2f(1508*sx*SX+tx,679*sy*SY + ty,"hq");


    ty=0;
//speakers1
    sx=sy=0.37;
    ty=430;
    tx=650;
    glColor3f(0.10,0.10,0.10);
    glVertex2f(1068*sx*SX+tx,191*sy*SY + ty,"hq");
    glVertex2f(1207*sx*SX+tx,130*sy*SY + ty,"hq");
    glVertex2f(1081*sx*SX+tx,740*sy*SY + ty,"hq");
    glVertex2f(1013*sx*SX+tx,805*sy*SY + ty,"hq");
    glColor3f(0.30,0.30,0.30);
    glVertex2f(1065*sx*SX+tx,189*sy*SY + ty,"hq");
    glVertex2f(1209*sx*SX+tx,127*sy*SY + ty,"hq");
    glVertex2f(825*sx*SX+tx,170*sy*SY + ty,"hq");
    glVertex2f(714*sx*SX+tx,213*sy*SY + ty,"hq");
    glColor3f(0.20,0.20,0.20);
    glVertex2f(716*sx*SX+tx,213*sy*SY + ty,"hq");
    glVertex2f(1066*sx*SX+tx,193*sy*SY + ty,"hq");
    glVertex2f(1011*sx*SX+tx,805*sy*SY + ty,"hq");
    glVertex2f(817*sx*SX+tx,770*sy*SY + ty,"hq");
//cout<<"x="<<817*sx*SX+tx<<"y="<<770*sy*SY + ty<<endl;


    glEnd();
//tx=740;
//ty=515;
//
//glColor3f(0.30,0.30,0.30);
//DrawCircle(tx,ty,100*sx*SY,20);
//glColor3f(0.50,0.50,0.50);
//DrawCircle(tx,ty,10*sx*SY,20);
//tx=tx+20;
//ty=ty-250;
//glColor3f(0.30,0.30,0.30);
//DrawCircle(tx,ty,80*sx*SY,20);
//glColor3f(0.50,0.50,0.50);
//DrawCircle(tx,ty,10*sx*SY,20);
////speakers2
//sx=sy=0.37;
//ty+=80;
    tx=tx+460;
    glBegin(GL_QUADS);
    glColor3f(0.10,0.10,0.10);
    glVertex2f(712*sx*SX+tx,183*sy*SY + ty,"hq");
    glVertex2f(853*sx*SX+tx,245*sy*SY + ty,"hq");
    glVertex2f(916*sx*SX+tx,816*sy*SY + ty,"hq");
    glVertex2f(844*sx*SX+tx,754*sy*SY + ty,"hq");
    glColor3f(0.30,0.30,0.30);
    glVertex2f(714*sx*SX+tx,180*sy*SY + ty,"hq");
    glVertex2f(856*sx*SX+tx,243*sy*SY + ty,"hq");
    glVertex2f(1211*sx*SX+tx,261*sy*SY + ty,"hq");
    glVertex2f(1102*sx*SX+tx,221*sy*SY + ty,"hq");
    glColor3f(0.20,0.20,0.20);
    glVertex2f(859*sx*SX+tx,243*sy*SY + ty,"hq");
    glVertex2f(1207*sx*SX+tx,264*sy*SY + ty,"hq");
    glVertex2f(1110*sx*SX+tx,781*sy*SY + ty,"hq");
    glVertex2f(916*sx*SX+tx,816*sy*SY + ty,"hq");

    glEnd();
//ty-=310;
//glColor3f(0.30,0.30,0.30);
//DrawCircle(tx,ty,100*sx*SX,20);
//glColor3f(0.50,0.50,0.50);
//DrawCircle(tx,ty,10*sx*SX,20);
//tx=tx+20;
//ty=ty-250;
//glColor3f(0.30,0.30,0.30);
//DrawCircle(tx,ty,80*sx*SX,20);
//glColor3f(0.50,0.50,0.50);
//DrawCircle(tx,ty,10*sx*SX,20);

//displaycrowd(0,180);
    displaycrowd1(-100,120,380,0.7,10);
    displaycrowd1(520,120,380,0.7,10);
    displaycrowd1(0,180,180,1,0);



    sx=sy=1;




}






void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,1.0);
    if( disp==1)
        displayguitar(1,1,1,1,1,1,1);
    if(disp==888)
        displayhandg();
    if(disp==7)
        displaynames();
    if(disp==3)
        displayhouse();
    if(disp==2)
        displayinterior(1,1,1,1);
    if(disp==555)
    {
        displayinterior(1,1,1,1);
        displaystory(" Once upon a time there was a kid named Freddie Jackson.");

    }
    if(disp==656)
    {
        displayinterior(1,1,1,1);
        displaystory(" His dad once got him tickets to a KUEENS CONCERT!!!!!!. ");
    }
    if(disp==757)
    {
        dispconcert();
        displaystorybox();
        displaystory(" Freddie and his father go to the Kueen's Concert. ");
    }
    if(disp==758)
    {
        dispconcert();
        displaystorybox();
        displaystory(" Freddie was astounded by the presence of the Kueen band. ");
    }

    if(disp==759)
    {
        stage(1,1,1,1);
        displayBand(1,1,1,1);
        displaystorybox();

        displaystory("The Kueen played their iconic song that day. ");
    }


    if(disp==760)
    {
        ta=0;
        displayBrian(1,1,1.5,1.5);
        displaystorybox();
        displaystory("Solo played by Brian Kay had ignited a new flame in Freddie's beating heart.");
    }
    if(disp==761)
    {
        displayBrian(1,1,1.5,1.5);
        displaystorybox();
        displaystory("It was a passion for a guitar!!");
    }

    if(disp==762)
    {
        afterconcert(1,1,1,1);
        displaystorybox();
        displaystory("Freddie bought a new Guitar .");

    }

    if(disp==763)
    {
        growingupscene(1,1,1.0,1.0);
        kidplayingguitar(1,-51,.7,.6);
        displaystorybox();
        displaystory("Freddie loved the guitar and rock & rolled with it day and night.");

    }
    if(disp==764)
    {
        juniorschool();

        kidplayingguitar(1,-50,.75,.73);
        displaystorybox();
        displaystory("As Freddie Grew, he competed in events and lost at first.");
    }

    if(disp==765)
    {

        highschool(1,1,1,1);
        kidplayingguitar(1,-40,.9,.9);
        displaystorybox();
        displaystory("But, Freddie's Love for guitar was priceless. He worked Day and Night learning the guitar.");




    }

    if(disp==766)
    {

        dispcollege();
        kidplayingguitar(1,0,1.1,1.15);
        displaystorybox();
        displaystory("Soon, Freddie mastered his instruments and won many awards.");




    }

    if(disp==767)
    {

        displaygig();
        kidplayingguitar(1,70,1.1,1.4);
        displaystorybox();
        displaystory("Freddie believed that Guitar was his life and tried to make a career out of it. ");




    }



    if(disp==768)
    {
        tvconcert(1,1,1,1);
        displaystorybox();
        displaystory("Freddie always wanted to perform in front of millions. That was his dream. ");


    }
    if(disp==769)
    {
        glColor3f(.0,0,0);
        glRectf(-960,-540,960,540);
        displaystorybox();
        displaystory("Freddie Worked extra hard!");

    }


    if(disp==770)
    {
        firstlook(1,100,3.3,3.3);


    }

    if(disp==771)
    {
        stage(1,1,1,1);
        kidband(1,1,1,1);
        displaystorybox();
        displaystory("Freddie is now a band member of Michael Jason's crew");


    }

    if(disp==772)
    {
        //With Crowd
        dispconcert1();
        displaystorybox();
        displaystory("Freddie was happy to be performing in among the greatest and front of his fans!!");




    }



    if(disp==773)
    {
        //LastScene
        farconcert();
        displaystorybox();
        displaystory("This is how Freddie fulfilled his dreams and rest is HISTORY! - This was the Life of Freddie Jackson.");

    }


    glFlush();
    glutSwapBuffers();

}
void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(1.0,0.0,0.0);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-xhqb,xhqb,-yhqb,yhqb);
    //gluOrtho2D(0,1920,1080,0);
    setFont(GLUT_BITMAP_HELVETICA_18);
    glutPostRedisplay();
}

/* Program entry point */
int go=0;
int go1=0;
int gobi=0;
int gobj=0;
float audmax=2;
int audgo;
int a=0;
int b=0;
// audience movement

void timer(int)
{
    //Stage Lights
    if(go1==0)
    {
        lightangle+=0.3;
        if(lightangle>=15.0)
        {
            go1=1;
        }
    }
    else if(go1==1)
    {
        lightangle-=0.3;
        if(lightangle<=-15.0)
            go1=0;
    }

    if(audgo==1)
    {
        moveaudience+=0.02;
        if(moveaudience>=audmax)
            audgo=2;
    }
    else if(audgo=2)
    {
        moveaudience-=0.02;
        if(moveaudience<=-audmax)
            audgo=1;
    }


    storydelay+=0.5;
    if(storydelay<-150)
        disp=7;
    if(storydelay==-150)
        disp=888;
    if(storydelay>-120&&storydelay<100)
    {

        sx+=0.02;
        sy+=0.02;
        disp=3;
    }
    if(storydelay==100)
        disp=2;
    if( storydelay==200)
    {
        gobi=1;
        disp=555;
    }
    if(storydelay==380)
    {
        disp=656;
    }
    if(storydelay==550)
    {
        disp=757;
    }

    if(storydelay==640)
    {
        disp=758;
    }

    if(storydelay==750)
    {
        disp=759;
    }



    if(storydelay==1200)
    {
        disp=760;
    }
    if(storydelay==1400)
    {
        disp=761;
        sx=0;
        sy=0;
    }

    if(storydelay==1600)
    {
        PlaySound("D://Codeblock//stay.wav",NULL,SND_LOOP|SND_ASYNC);


        disp=3;
        a=1;
    }
    if(a==1)
    {
        sx+=0.02;
        sy+=0.02;
    }


    if(storydelay==1700)
    {
        gobj=1;
        ta=0;
        disp=762;
    }
    if(storydelay==1900)
    {
        PlaySound("D://Codeblock//meg.wav",NULL,SND_LOOP|SND_ASYNC);
        disp=763;
    }
    if(storydelay==2170)
    {
        PlaySound("D://Codeblock//heaven.wav",NULL,SND_LOOP|SND_ASYNC);
        disp=764;

    }
    if(storydelay==2450)
    {
        PlaySound("D://Codeblock//november.wav",NULL,SND_LOOP|SND_ASYNC);
        disp=765;

    }



    if(storydelay==2650)
    {
        PlaySound("D://Codeblock//ozzy.wav",NULL,SND_LOOP|SND_ASYNC);
        disp=766;
    }
    if(storydelay==2850)
    {
        PlaySound("D://Codeblock//sweet.wav",NULL,SND_LOOP|SND_ASYNC);
        disp=767;
        a=0;
        sx=0;
        sy=0;
    }

    if(storydelay==3170)
    {
        PlaySound("D://Codeblock//some.wav",NULL,SND_LOOP|SND_ASYNC);

        disp=3;
        b=1;
    }

    if(b==1)
    {
        sx+=0.02;
        sy+=0.02;
    }

    if(storydelay==3270)
    {
        ta=0;
        disp=768;
    }

    if(storydelay==3570)
    {
        disp=769;
    }

    if(storydelay==3690)
    {
        PlaySound("D://Codeblock//tintro.wav",NULL,SND_LOOP|SND_ASYNC);
        disp=770;
    }

    if(storydelay==3820)
    {
        PlaySound("D://Codeblock//beat it.wav",NULL,SND_LOOP|SND_ASYNC);
        disp=771;
    }
    if(storydelay==4300)
    {
        disp=772;
    }
    if(storydelay==4770)
    {
        disp=773;
    }


    if(ta>ta_max&&gobi==1)
    {
        ta-=1;

        if(go==0)
        {
            S_ANGLE-=0.3;
            if(S_ANGLE<=-15)
                go=1;
        }
        else if(go==1)
        {
            S_ANGLE+=0.3;
            if(S_ANGLE>=15)
                go=0;
        }
    }

    if(ta<=ta_max)
    {
        S_ANGLE=0;


    }


    if(!((int)storydelay%60))
    {
        readyforchange=true;
        for(int i=0; i<72; i++)
        {

            cl1[i] = float_rand(0.0,1.0);
            cl2[i] = float_rand(0.0,1.0);
            cl3[i] = float_rand(0.0,1.0);
        }
    }

    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
}


int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(1920,1080);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Guitar Display");
    glutDisplayFunc(display);

    init();
    glutTimerFunc(0,timer,0);
    glutMainLoop();
    return 0;
}
// @todo
//1.Queens music
//2.Concert scene
//	a.People scene
//	b.Stage scene
