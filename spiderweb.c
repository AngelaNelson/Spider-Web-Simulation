#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#define pi 3.142857
void display1();
void background();
float uu = 0;
float ll = 0;
float angle=0.0;
float s=0.2;
int fillFlag=3;
void renderbitmap(float x,float y,void *font,char *string)
{
	char *c;
	glRasterPos2f(x,y);
	for(c=string;*c!='\0';c++)
	{
		glutBitmapCharacter(font,*c);
	}
}
void introscreen()
{
	glColor3f(1.0,1.0,1.0);
	char buf[100]={0};
	sprintf(buf,"------KEYS TO MOVE:R->Right,L->Left,U->Upward,D->Down,C->clockwise,A->Anti-clockwise------");
	renderbitmap(90,20,GLUT_BITMAP_HELVETICA_12,buf);


}


void line(GLint x,GLint y,GLint x1,GLint y1)
{
	
	if(fillFlag==1)
	{
	glColor3f(0.7, 0.8, 1.0);
	}
	else if(fillFlag==2)
	{
	glColor3f(0.0, 0.0, 0.3);	
	}
	else
	{
	glColor3f(0.5, 0.2, 0.1);
	}
	glPointSize(1.0);
	glBegin(GL_LINES);;
	glVertex2i(x,y);
	glVertex2i(x1,y1);
	glEnd();
}
void draw_hex(GLint x1,GLint y1,GLint x2,GLint y2,GLint x3,GLint
y3,GLint x4,GLint y4,GLint x5,GLint y5,GLint x6,GLint y6,GLint
x7,GLint y7,GLint x8,GLint y8)
{

	glPointSize(1.0);
	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x1,y1);
	glVertex2i(x2,y2);
	glVertex2i(x3,y3);
	glVertex2i(x4,y4);
	glVertex2i(x5,y5);
	glVertex2i(x6,y6);
	glVertex2i(x7,y7);
	glVertex2i(x8,y8);
	glEnd();
	
}
void draw_quad(GLint x1,GLint y1,GLint x2,GLint y2,GLint x3,GLint
y3,GLint x4,GLint y4)
{

	glPointSize(1.0);
	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x1,y1);
	glVertex2i(x2,y2);
	glVertex2i(x3,y3);
	glVertex2i(x4,y4);
	glEnd();
	
}

void web()
{
	GLint 	x1=800,y11=1500,x2=1300,y2=1300,x3=1500,y3=800,x4=1300,y4=300,x5=800,y5=100,x6=300,y6=300,x7=100,y7=800,x8=300,y8=1300;
	int i;
	
	glColor3f(0.329412,0.329412,0.329412);//set web's  color here.
	line(x1,y11,x5,y5);
	line(x2,y2,x6,y6);
	line(x3,y3,x7,y7);
	line(x4,y4,x8,y8);

	for(i=0;i<4;i++)
	{
	
		draw_hex(x1,y11,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6,x7,y7,x8,y8);
		y11-=100;
		x2-=100;
		y2-=100;
		x3-=100;
		x4-=100;
		y4+=100;
		y5+=100;
		x6+=100;
		y6+=100;
		x7+=100;
		x8+=100;
		y8-=100;
	}
	for(i=0;i<3;i++)
	{
		draw_quad(x1,y11,x3,y3,x5,y5,x7,y7);
		y11-=100;
		x3-=100;
		y5+=100;
		x7+=100;

	}

}
void leg(float a, float b)

{
	if(fillFlag==1)
	{
	glColor3f(0.9, 0.5, 0.0);
	}
	else if(fillFlag==2)
	{
	glColor3f(0.2, 0.4, 0.1);	
	}
	else
	{
	glColor3f(0.3, 0.0, 0.5);
	}
	
  		glBegin(GL_LINES);
  		glVertex2f(a,b);
  		glVertex2f(a+150,b+100);
  	glEnd();
	glBegin(GL_LINES);
  		glVertex2f(a+150,b+100);
  		glVertex2f(a+300,b-200);
  	glEnd();
 

}
void leg2(float a, float b,int nn)
{	
	if(fillFlag==1)
	{
	glColor3f(0.9, 0.5, 0.0);
	}
	else if(fillFlag==2)
	{
	glColor3f(0.2, 0.4, 0.1);	
	}
	else
	{
	glColor3f(0.3, 0.0, 0.5);
	}
	
  		glBegin(GL_LINES);
  		glVertex2f(a,b);
  		glVertex2f(a-150,b+100);
  		glEnd();
  	if(nn!=3)
  	{
		glBegin(GL_LINES);
  		glVertex2f(a-150,b+100);
  		glVertex2f(a-300,b-200);
  		glEnd();
	}
}

void spider()
{	if(fillFlag==1)
	{
	glColor3f(0.9, 0.5, 0.0);
	}
	else if(fillFlag==2)
	{
	glColor3f(0.2, 0.4, 0.1);	
	}
	else
	{
	glColor3f(0.3, 0.0, 0.5);
	}
    	glPointSize(1.0);
    	glBegin(GL_TRIANGLE_FAN);
    	float x, y, i,h,k,j,p,q,temp=0.0;
    	float c,d,z;
    	int n=1;
    //ment in angle as
    // glVertex2i just draws a point on specified co-ordinate
    	for ( i = 0; i < 2*(pi); i += 0.01)
    	{

        	// let 200 is radius of circle and as,
        	// circle is defined as x=r*cos(i) and y=r*sin(i)
        	x = 200 * cos(i);
        	y = 200 * sin(i);
        	glVertex2i(x, y);
    	}
    	h=x;
    	k=y;

	for ( j= 0; j< (pi*2); j+= 0.01)
    	{
        
        	// circle is defined as x=r*cos(i) and y=r*sin(i)
        	p= 100* cos(j)+k;
        	q=100*sin(j)+h;
        	glVertex2i(p,q);
        
    	}

	temp=0;
	do
	{


 		for(z=temp;z<(n*(2.0/9.0)*(pi));z+=0.01)
 		{

		}

		temp=z;
		c=200*cos(z);
		d=200*sin(z);
		if(n==8||n==9||n==10)
		{
			leg(c,d);
		}
		if(n==6||n==4||n==5)
		{
			leg2(c,d,n);
		}
		n=n+1;
	}while(n<=10);

    glEnd();
}



/*void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0,0.0,1.0,1.0);
web();
glutDisplayFunc(display1);
glutPostRedisplay();
glutSwapBuffers();

}*/
void display1()
{
    
    
    glClear(GL_COLOR_BUFFER_BIT);
    introscreen();
    glFlush();
    glPushMatrix();
    glScalef(1,1,1);
    web();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(ll,uu,0);
    glScalef(s,s,0);
    glRotatef(angle,0,0,1);
    spider();
    glPopMatrix();
    background();
    glutSwapBuffers();
}


void keyboard(unsigned char key, int x1, int y1){

        if(key=='E')
        {
            exit(0);

        }
        else if(key=='U')
        {
            uu+=10;
            glutDisplayFunc(display1);
            glutPostRedisplay();

        }
        else if(key=='R')
        {
            ll+=10;
            glutDisplayFunc(display1);
            glutPostRedisplay();
        }
         else if(key=='L')
        {
            ll-=10;
            glutDisplayFunc(display1);
            glutPostRedisplay();
        }
       
        else if(key=='C')
        {
              angle-=0.9;
              glutDisplayFunc(display1);
              glutPostRedisplay();
        }
        else if(key=='A')
        {
              angle+=0.9;
              glutDisplayFunc(display1);
              glutPostRedisplay();
        }
        else if(key=='D')
        {
        	uu-=10;
		glutDisplayFunc(display1);
            	glutPostRedisplay();
	}
	 else if(key == 43)
        {
             s+=0.1;
	     glutDisplayFunc(display1);
             glutPostRedisplay();
        }
      
}
void fillMenu(int option)
{
if(option==1)
fillFlag=1;
else if (option==2)
fillFlag=2;
else
fillFlag=3;

}
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1500.0,0.0,1500.0);
}

void background()
{
if(fillFlag==1)
	{
	myinit();
	glClearColor(0.0, 0.1, 0.1,1.0);
	}
	else if(fillFlag==2)
	{
	myinit();
	glClearColor(1.0, 0.5, 0.0, 1.0);	
	}
	else
	{
	myinit();
	glClearColor(0.2, 1.0, 0.1, 1.0);
	}
}


void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1400,1400);
	glutInitWindowPosition(30.0,30.0);
	glutCreateWindow("Web");
	background();
	glutDisplayFunc(display1);
	glutCreateMenu(fillMenu);
	glutAddMenuEntry("PUMPKIN SPIDER",1);
	glutAddMenuEntry("GREEN ORBEWAVER",2);
	glutAddMenuEntry("PURPLE TREE TARANTULA",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}
