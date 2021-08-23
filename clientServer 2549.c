
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
const float DEG2RAD = 3.14159 / 180;
int flag = 0, count = 0, count1 = 0, dt = 0, dd = 0, dx = 0, da = 0, db = 0, dat1 = 0, dat2 = 0,frontflag=0,front1flag=0;
int upflag=0,downflag=0;
int upc3flag=0,upc4flag=0,downc3flag=0,downc4flag=0;
int dataoneflag=0,datatwoflag=0;
float pos1 = 110.0, pos2 = 300.0;
char *ptr1, *ptr2, *ptr3, *ptr4, *ptr5, *ptr6, *ptr7, *ptr8, *ptr9;
int len1, len2, len3, len4, len5, len6, len7,i;
float x1=107.0,x2=300.0;
void one();
float angle, p1 = 107.0, p2 = 300.0, p3 = 175.0, p4 = 200.0, p5 = 175.0, p6 = 200.0, p7 = 100.0, p8 = 115.0, p9 = 185.0, p10 = 99.0, p11 = 210.0, p12 = 280.0;
float p13 = 300.0, p14 = 262.0, p15 = 300.0, p16 = 114.0, p17 = 216.0, p18 = 99.0;
/*the variables used here are the x and y coordinates.
where p1,p3,p5,p7,p9,p11,p13,p15,p17 are x coordinates.
and p2,p4,p6,p8,p10,p12,p14,p16,p18 are y coordinates.
*/
void download();
void response();
void downloading();
void upload();



/*void myReshape(int w, int h)
{
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-1.0, 1.0, -1.0, 1.0, -10.0, 10.0);
glMatrixMode(GL_MODELVIEW);
}*/

void draw(float radius)            //used to create a circle shape like figure.
{
	float delta_theta = 0.001;
	glBegin(GL_POLYGON); // OR GL_LINE_LOOP


	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	for (angle = 0; angle < 2 * 3.1415; angle += delta_theta)
		glVertex3f(radius*cos(angle), radius*sin(angle), 0);

	glEnd();

}



void Init()  // used to initialize the display .
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
	glMatrixMode(GL_MODELVIEW);
	glOrtho(-1.0, 1.0, -1.0, 1.0, -10.0, 10.0);

}

void line()     //this function is to design the system(monitor and CPU)
{



	glColor3f(0.22, 0.22, 0.22);
	glBegin(GL_POLYGON);
	glVertex2i(30, 60);
	glVertex2i(80, 60);
	glVertex2i(80, 115);
	glVertex2i(30, 115);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(32.0, 64.0);
	glVertex2f(78.0, 64.0);
	glVertex2f(78.0, 112.0);
	glVertex2f(32.0, 112.0);
	glEnd();

	glColor3f(0.22, 0.22, 0.22);
	glBegin(GL_POLYGON);
	glVertex2f(30.0, 44.0);
	glVertex2f(80.1, 44.0);
	glVertex2f(80.1, 60.0);
	glVertex2f(30.0, 60.0);
	glEnd();



	glColor3f(0.22, 0.22, 0.22);
	glBegin(GL_POLYGON);
	glVertex2f(51.0, 34.0);
	glVertex2f(51.0, 44.0);
	glVertex2f(59.0, 44.0);
	glVertex2f(59.0, 34.0);
	glVertex2f(64.0, 34.0);
	glVertex2f(64.0, 32.0);
	glVertex2f(46.0, 32.0);
	glVertex2f(46.0, 34.0);

	glVertex2f(51.0, 34.0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(29.9, 44);
	glVertex2f(29.99, 115.2);
	glVertex2f(80.1, 44);
	glVertex2f(80.1, 115.2);
	glVertex2f(29.9, 115.2);
	glVertex2f(80.1, 115.29);
	glEnd();

	glColor3f(0.22, 0.22, 0.22);
	glBegin(GL_POLYGON);
	glVertex2f(90.0, 32.0);
	glVertex2f(110.0, 32.0);
	glVertex2f(110.0, 115.0);
	glVertex2f(90.0, 115.0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(92.0, 103.0);
	glVertex2f(108.0, 103.0);
	glVertex2f(108.0, 112.0);
	glVertex2f(92.0, 112.0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(95.0, 89.0);
	glVertex2f(103.0, 89.0);
	glVertex2f(103.0, 98.0);
	glVertex2f(95.0, 98.0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(105.0, 95.0);
	glVertex2f(108.0, 95.0);
	glVertex2f(108.0, 98.0);
	glVertex2f(105.0, 98.0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(105.0, 89.0);
	glVertex2f(108.0, 89.0);
	glVertex2f(108.0, 92.0);
	glVertex2f(105.0, 92.0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glPointSize(3.5);
	glBegin(GL_POINTS);
	glVertex2f(93.0, 96.0);
	glVertex2f(93.0, 91.0);
	glEnd();
	
/*  glColor3f(1.0, 1.0, 1.0);
	glPointSize(0.5);
	glBegin(GL_POINTS);
	glVertex2f(73.0, 66.0);
	glVertex2f(73.0, 61.0);
	glEnd();
	*/
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(0.5);
	glBegin(GL_POINTS);
	glVertex2f(106.0, 96.5);
	glVertex2f(107.0, 96.5);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glPointSize(0.5);
	glBegin(GL_POINTS);
	glVertex2f(106.0, 90.5);
	glVertex2f(107.0, 90.5);
	glEnd();

	glColor3f(2.0, 0.2, 0.2);
	glBegin(GL_LINES);
	glVertex2f(92.0, 80.0);
	glVertex2f(108.0, 80.0);
	glEnd();

	glColor3f(2.0, 0.2, 0.2);
	glBegin(GL_LINES);
	glVertex2f(92.0, 75.0);
	glVertex2f(108.0, 75.0);
	glEnd();

	glColor3f(2.0, 0.2, 0.2);
	glBegin(GL_LINES);
	glVertex2f(92.0, 70.0);
	glVertex2f(108.0, 70.0);
	glEnd();
	/*glColor3f(0.0, 0.0, 0.0);
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glVertex2f(35.0, 22.0);
	glEnd();
	*/
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(97.5, 65.0);
	glVertex2f(102.5, 65.0);
	glVertex2f(102.5, 41.0);
	glVertex2f(97.5, 41.0);
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glVertex2f(100.0, 58.0);
	//glVertex2f(80.0, 18.0);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glVertex2f(100.0, 48.0);
	glEnd();
	//glutSwapBuffers();
	//glTranslatef(0.0, 225.0, 0.0);

	/*	glColor3f(2.0, 0.2, 0.2);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(31.0, 50.0);
	glVertex2f(79.0, 50.0);
	glEnd();
	*/


}
void server() // this function is to design the central server.
{
	glColor3f(0.22, 0.22, 0.22);
	glBegin(GL_POLYGON);
	glVertex2f(175.0, 100.0);
	glVertex2f(225.0, 100.0);
	glVertex2f(225.0, 280.0);
	glVertex2f(175.0, 280.0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(177.2, 104.0);
	glVertex2f(222.8, 104.0);
	glVertex2f(222.8, 276.0);
	glVertex2f(177.2, 276.0);
	glEnd();

	glColor3f(2.55, 2.55, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(177.2, 139.0);
	glVertex2f(222.8, 139.0);
	glVertex2f(222.8, 141.0);
	glVertex2f(177.2, 141.0);
	glEnd();

	glColor3f(2.55, 2.55, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(207.0, 233.0);
	glVertex2f(222.8, 233.0);
	glVertex2f(222.8, 240.0);
	glVertex2f(207.0, 240.0);
	glEnd();

	glColor3f(2.55, 2.55, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(207.0, 220.0);
	glVertex2f(222.8, 220.0);
	glVertex2f(222.8, 227.0);
	glVertex2f(207.0, 227.0);
	glEnd();

	glColor3f(2.55, 2.55, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(207.0, 207.0);
	glVertex2f(222.8, 207.0);
	glVertex2f(222.8, 214.0);
	glVertex2f(207.0, 214.0);
	glEnd();

	glColor3f(0.0, 0.0, 1.0);
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glVertex2f(186.0, 260.0);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glVertex2f(186.0, 252.0);
	glEnd();

	/*glColor3f(0.20, 0.20, 0.20);
	glBegin(GL_POLYGON);
	glVertex2f(178.7, 106.0);
	glVertex2f(221.3, 106.0);
	glVertex2f(221.3, 274.0);
	glVertex2f(178.7, 274.0);
	glEnd();
	*/

}
void upload4() // used to display the bitmap characters.
{
	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	ptr8 = " D A T A - 2  U P L O A D E D ";

	len7 = strlen(ptr8);
	glColor3f(0.60, 0.60, 0.60);
	glRasterPos3f(138.0, 156.0, 0.0);
	int i;
	for (i = 0; i<len7; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr8[i]);

	glPopMatrix();
	glutPostRedisplay();



	glFlush();
}
void uploading4()// used to display the bitmap characters.
{
	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	ptr8 = " U P L O A D I N G  D A T A - 2 ...";

	len7 = strlen(ptr8);
	//glColor3f(0.60, 0.60, 0.60);
	glRasterPos3f(138.0, 156.0, 0.0);
	int i;
	for (i = 0; i<len7; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr8[i]);

	glPopMatrix();
	glutPostRedisplay();



	glFlush();
}
void download4()// used to display the bitmap characters.
{

	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	ptr6 = "D A T A - 1   D O W N L O A D E D";

	len6 = strlen(ptr6);
	glColor3f(0.60, 0.60, 0.60);
	glRasterPos3f(120.0, 53.0, 0.0);
	int i;
	for (i = 0; i < len6; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr6[i]);

	glPopMatrix();
	glutPostRedisplay();



	glFlush();
}
void downloading4()// used to display the bitmap characters.
{

	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	ptr6 = "D O W N L O A D I N G   D A T A - 1 ...";

	len6 = strlen(ptr6);
	//glColor3f(0.60, 0.60, 0.60);
	glRasterPos3f(120.0, 53.0, 0.0);
	int i;
	for (i = 0; i < len6; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr6[i]);

	glPopMatrix();
	glutPostRedisplay();



	glFlush();
}


void download3()// used to display the bitmap characters.
{


	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	ptr6 = "D A T A - 2    D O W N L O A D E D";

	len6 = strlen(ptr6);
	//glColor3f(0.60, 0.60, 0.60);
	glRasterPos3f(120.0, 318.0, 0.0);
	int i;
	for (i = 0; i < len6; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr6[i]);

	glPopMatrix();
	glutPostRedisplay();



	glFlush();

}
void downloading3()// used to display the bitmap characters.
{
	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	ptr6 = "D O W N L O A D I N G   D A T A - 2 ...";

	len6 = strlen(ptr6);
	//glColor3f(0.60, 0.60, 0.60);
	glRasterPos3f(120.0, 318.0, 0.0);
	int i;
	for (i = 0; i<len6; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr6[i]);

	glPopMatrix();
	glutPostRedisplay();



	glFlush();
}


void upload3()// used to display the bitmap characters.
{
	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	ptr8 = " D A T A - 1   U P L O A D E D ";

	len7 = strlen(ptr8);
	glColor3f(0.60, 0.60, 0.60);
	glRasterPos3f(140.0, 213.0, 0.0);
	int i;
	for (i = 0; i<len7; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr8[i]);

	glPopMatrix();
	glutPostRedisplay();



	glFlush();
}

void uploading3()// used to display the bitmap characters.
{
	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	ptr6 = "U P L O A D I N G   D A T A - 1 ...";

	len6 = strlen(ptr6);
	//glColor3f(0.60, 0.60, 0.60);
	glRasterPos3f(140.0, 213.0, 0.0);
	int i;
	for (i = 0; i<len6; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr6[i]);

	glPopMatrix();
	glutPostRedisplay();



	glFlush();
}

void fourfourU()//uploading function for the client 4
{
	
	upflag=0;
	downflag=0;
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload();
	glPopMatrix();
	
	
	upc3flag=0;
	downc3flag=0;
	
	upc4flag=0;
	downc4flag=0;
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload1();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload1();
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload2();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload2();
	glPopMatrix();
	glPushMatrix();
			glColor3f(0.0,0.0,0.0);
			datatwostatus();
			glPopMatrix();
			
			
			glPushMatrix();
			glColor3f(0.0,0.0,0.0);
			dataonestatus();
			glPopMatrix();
	if (p15 == 300.0 && p16 >= 114.0 && p16 < 145.0)
	{
		p16 = p16 + 0.08;

		glutPostRedisplay();
	}
	else
	{
		if (p15 <= 300.0 && p15>225.7)
		{
			p15 = p15 - 0.08;
			glutPostRedisplay();
		}
	}
	if (p15 > 227.5)
	{

		glPushMatrix();
		glColor3f(0.6, 0.6, 0.6);
		uploading4();
		glPopMatrix();

	}
	else
	{
		glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);
		uploading4();
		glPopMatrix();
		upload4();
		upc4flag=1;
				if(upc4flag==1 )
				{
					glPushMatrix();
					glColor3f(0.0,0.0,0.0);
					alreadyupload2();
					glPopMatrix();
					glPushMatrix();
					glColor3f(0.6,0.6,0.6);
					alreadyupload2();
					glPopMatrix();
				}

		//alreadydownload2();
	}
//datatwoflag=1;


}

void dataonestatus()
{
			glPushMatrix();
			glTranslatef(100.0, 0.0, 0.0);
			ptr1 = " U P L O A D    D A T A  1    F R O M    C L I E N T 3    I N T O   S E R V E R ...";
			
		
			len2 = strlen(ptr1);
		
			//glColor3f(0.6, 0.6, 0.6);
			glRasterPos3f(50, 340.0, 0.0);
			for (i = 0; i<len2; i++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr1[i]);
			glPopMatrix();
			glutPostRedisplay();
			glFlush();
	
}
void datatwostatus()
{
			glPushMatrix();
			glTranslatef(100.0, 0.0, 0.0);
			ptr1 = " U P L O A D    D A T A 2    F R O M    C L I E N T 4    I N T O   S E R V E R ....";
			
		
			len2 = strlen(ptr1);
		
			//glColor3f(0.6, 0.6, 0.6);
			glRasterPos3f(50, 340.0, 0.0);
			for (i = 0; i<len2; i++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr1[i]);
			glPopMatrix();
			glutPostRedisplay();
			glFlush();
	
}
void fourfourD() //download function for client 4.
{
	
	upflag=0;
	downflag=0;
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload();
	glPopMatrix();
	
	
	upc3flag=0;
	downc3flag=0;
	
	upc4flag=0;
	downc4flag=0;
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload1();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload1();
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload2();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload2();
	glPopMatrix();
	glPushMatrix();
			glColor3f(0.0,0.0,0.0);
			datatwostatus();
			glPopMatrix();
			
			
			glPushMatrix();
			glColor3f(0.0,0.0,0.0);
			dataonestatus();
			glPopMatrix();
	if (p17 == 216.0 && p18 <= 99.0 && p18 > 70.0)
	{
		p18 = p18 - 0.08;

		glutPostRedisplay();
	}
	else
	{
		if (p17 >= 216.0 && p17<289.0)
		{
			p17 = p17 + 0.08;
			glutPostRedisplay();
		}
	}

	if (p17 < 287.0)
	{
		glPushMatrix();
		glColor3f(0.6, 0.6, 0.6);
		downloading4();
		glPopMatrix();

	}
	else
	{
		glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);
		downloading4();
		glPopMatrix();
		download4();
		downc4flag=1;
				if(downc4flag==1 )
				{
					glPushMatrix();
					glColor3f(0.0,0.0,0.0);
					alreadydownload2();
					glPopMatrix();
					glPushMatrix();
					glColor3f(0.6,0.6,0.6);
					alreadydownload2();
					glPopMatrix();
				}

	}
//	if(dataoneflag!=1)
//	{
//		glPushMatrix();
//		glColor3f(0.6,0.6,0.6);
//		dataonestatus();
//		glPopMatrix();
//	}

}
void alreadydownload1()
{
			glPushMatrix();
			glTranslatef(100.0, 0.0, 0.0);
			ptr1 = " D A T A  2   I S   D O W N L O A D E D   F R O M   S E R V E R   I N T O   C L I E N T 3";
			
		
			len2 = strlen(ptr1);
		
			//glColor3f(0.6, 0.6, 0.6);
			glRasterPos3f(50, 340.0, 0.0);
			for (i = 0; i<len2; i++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr1[i]);
			glPopMatrix();
			glutPostRedisplay();
			glFlush();
	
}
void alreadyupload1()
{
			glPushMatrix();
			glTranslatef(100.0, 0.0, 0.0);
			ptr1 = " D A T A  1   I S   U P L O A D E D   F R O M   C L I E N T - 3   I N T O   S E R V E R";
			
		
			len2 = strlen(ptr1);
		
			//glColor3f(0.6, 0.6, 0.6);
			glRasterPos3f(50, 340.0, 0.0);
			for (i = 0; i<len2; i++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr1[i]);
			glPopMatrix();
			glutPostRedisplay();
			glFlush();
	
}


void alreadydownload2()
{
			glPushMatrix();
			glTranslatef(100.0, 0.0, 0.0);
			ptr1 = " D A T A  1  I S   D O W N L O A D E D   F R O M   S E R V E R   I N T O  C L I E N T - 4";
			
		
			len2 = strlen(ptr1);
		
			//glColor3f(0.6, 0.6, 0.6);
			glRasterPos3f(50, 340.0, 0.0);
			for (i = 0; i<len2; i++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr1[i]);
			glPopMatrix();
			glutPostRedisplay();
			glFlush();
	
}
void alreadyupload2()
{
			glPushMatrix();
			glTranslatef(100.0, 0.0, 0.0);
			ptr1 = " D A T A  2  I S   U P L O A D E D   F R O M   C L I E N T - 4   I N T O   S E R V E R";
			
		
			len2 = strlen(ptr1);
		
			//glColor3f(0.6, 0.6, 0.6);
			glRasterPos3f(50, 340.0, 0.0);
			for (i = 0; i<len2; i++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr1[i]);
			glPopMatrix();
			glutPostRedisplay();
			glFlush();
	
}
void threethreeU() //upload fuction for client 3.
{
	
	upflag=0;
	downflag=0;
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload();
	glPopMatrix();
	
	
	upc3flag=0;
	downc3flag=0;
	
	upc4flag=0;
	downc4flag=0;
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload1();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload1();
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload2();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload2();
	glPopMatrix();
	glPushMatrix();
			glColor3f(0.0,0.0,0.0);
			datatwostatus();
			glPopMatrix();
			
			
			glPushMatrix();
			glColor3f(0.0,0.0,0.0);
			dataonestatus();
			glPopMatrix();
	if (p13 == 300.0 && p14 <= 262.0 && p14 > 225.0)
	{
		p14 = p14 - 0.08;

		glutPostRedisplay();
	}
	else
	{
		if (p13 <= 300.0 && p13>226.0)
		{
			p13 = p13 - 0.08;
			glutPostRedisplay();
		}
	}

	if (p13 > 229.0)
	{

		glPushMatrix();
		glColor3f(0.6, 0.6, 0.6);
		uploading3();
		glPopMatrix();

	}
	else
	{
		glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);
		uploading3();
		glPopMatrix();
		upload3();
		
			upc3flag=1;
				if(upc3flag==1 )
				{
					glPushMatrix();
					glColor3f(0.0,0.0,0.0);
					alreadydownload1();
					glPopMatrix();
					glPushMatrix();
					glColor3f(0.6,0.6,0.6);
					alreadyupload1();
					glPopMatrix();
				}

	}
//	dataoneflag=1;

}
 
void threethreeD()//download function for client 3.
{
	
	upflag=0;
	downflag=0;
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload();
	glPopMatrix();
	
	
	upc3flag=0;
	downc3flag=0;
	
	upc4flag=0;
	downc4flag=0;
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload1();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload1();
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload2();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload2();
	glPopMatrix();
	glPushMatrix();
			glColor3f(0.0,0.0,0.0);
			datatwostatus();
			glPopMatrix();
			
			
			glPushMatrix();
			glColor3f(0.0,0.0,0.0);
			dataonestatus();
			glPopMatrix();
	if (p11 == 210.0 && p12 >= 280.0 && p12 < 310.0)
	{
		p12 = p12 + 0.08;

		glutPostRedisplay();
	}
	else
	{
		if (p11 >= 210.0 && p11<289.2)
		{
			p11 = p11 + 0.08;
			glutPostRedisplay();
		}
	}
	if (p11 < 286.0)
	{

		glPushMatrix();
		glColor3f(0.6, 0.6, 0.6);
		downloading3();
		glPopMatrix();

	}
	else
	{
		glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);
		downloading3();
		glPopMatrix();
		glPushMatrix();
		glColor3f(0.6, 0.6, 0.6);
		download3();
		glPopMatrix();
		downc3flag=1;
				if(downc3flag==1 )
				{
					glPushMatrix();
					glColor3f(0.0,0.0,0.0);
					alreadydownload1();
					glPopMatrix();
					glPushMatrix();
					glColor3f(0.6,0.6,0.6);
					alreadydownload1();
					glPopMatrix();
				}

	}
//	if(datatwoflag!=1)
//	{
//		glPushMatrix();
//		glColor3f(0.6,0.6,0.6);
//		datatwostatus();
//		glPopMatrix();
//	}
}





void download2()// used to display the bitmap characters.
{
	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	ptr6 = "D O W N L O A D E D ";

	len6 = strlen(ptr6);
	//glColor3f(0.60, 0.60, 0.60);
	glRasterPos3f(30.0, 55.0, 0.0);
	for (i = 0; i<len6; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr6[i]);

	glPopMatrix();
	glutPostRedisplay();



	glFlush();
}

void downloading2()// used to display the bitmap characters.
{
	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	ptr6 = "D O W N L O A D I N G ...";

	len6 = strlen(ptr6);
	//glColor3f(0.60, 0.60, 0.60);
	glRasterPos3f(30.0, 55.0, 0.0);
	for (i = 0; i<len6; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr6[i]);

	glPopMatrix();
	glutPostRedisplay();



	glFlush();
}



void twotwoD()//download function for client 2.
{
	
	upflag=0;
	downflag=0;
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload();
	glPopMatrix();
	
	upc3flag=0;
	downc3flag=0;
	
	upc4flag=0;
	downc4flag=0;
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload1();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload1();
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload2();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload2();
	glPopMatrix();
	
			glPushMatrix();
			glColor3f(0.0,0.0,0.0);
			datatwostatus();
			glPopMatrix();
			
			
			glPushMatrix();
			glColor3f(0.0,0.0,0.0);
			dataonestatus();
			glPopMatrix();
	if (p9 == 185.0 && p10 <= 99.0 && p10 > 68.0)
	{
		p10 = p10 - 0.08;

		glutPostRedisplay();
	}
	else
	{
		if (p9 <= 185.0 && p9 > 111.2)
		{
			p9 = p9 - 0.08;
			glutPostRedisplay();
		}
	}

	if (p9 > 112.0)
	{
		glPushMatrix();
		glColor3f(0.6, 0.6, 0.6);
		downloading2();
		glPopMatrix();

	}
	else
	{
		glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);
		downloading2();
		glPopMatrix();
		glPushMatrix();
		glColor3f(0.6, 0.6, 0.6);
		download2();
		glPopMatrix();
		glEnd();
	}

}




void upload2()// used to display the bitmap characters.
{
	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	ptr6 = "U P L O A D E D ";

	len6 = strlen(ptr6);
	//glColor3f(0.60, 0.60, 0.60);
	glRasterPos3f(27.0, 155.0, 0.0);
	for (i = 0; i<len6; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr6[i]);

	glPopMatrix();
	glutPostRedisplay();



	glFlush();
}

void uploading2()// used to display the bitmap characters.
{
	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	ptr6 = "U P L O A D I N G ...";

	len6 = strlen(ptr6);
	//glColor3f(0.60, 0.60, 0.60);
	glRasterPos3f(27.0, 155.0, 0.0);
	int i;
	for (i = 0; i<len6; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr6[i]);

	glPopMatrix();
	glutPostRedisplay();



	glFlush();
}



void twotwoU()//upload function for client 2.
{
	
	upflag=0;
	downflag=0;
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload();
	glPopMatrix();
	
	
	upc3flag=0;
	downc3flag=0;
	
	upc4flag=0;
	downc4flag=0;
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload1();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload1();
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload2();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload2();
	glPopMatrix();
	glPushMatrix();
			glColor3f(0.0,0.0,0.0);
			datatwostatus();
			glPopMatrix();
			
			
			glPushMatrix();
			glColor3f(0.0,0.0,0.0);
			dataonestatus();
			glPopMatrix();
	if (p7 == 100.0 && p8 >= 115.0 && p8 < 145.0)
	{
		p8 = p8 + 0.08;
		glutPostRedisplay();
	}
	else
	{
		if (p8 >= 145.0 && p7<174.0)
		{
			p7 = p7 + 0.08;
			glutPostRedisplay();
		}
	}

	if (p7 < 172.0)
	{
		glPushMatrix();
		glColor3f(0.6, 0.6, 0.6);
		uploading2();
		glPopMatrix();

	}
	else
	{
		glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);
		uploading2();
		glPopMatrix();
		glPushMatrix();
		glColor3f(0.6, 0.6, 0.6);
		upload2();
		glPopMatrix();
		glEnd();
	}



}






void oneoneD()//download function for client 1.
{
	
	upc3flag=0;
	downc3flag=0;
	
	upc4flag=0;
	downc4flag=0;
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload1();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload1();
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload2();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload2();
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	datatwostatus();
	glPopMatrix();
	
	
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	dataonestatus();
	glPopMatrix();
	if (flag == 1)
	{
		if (p5 <= 175.0 && p6 == 200.0 && p5 > 100.0)
		{
			p5 = p5 - 0.08;

			glutPostRedisplay();
		}
		else
		{
			if (p5 <= 100.0 && p6<250.0)
			{
				p6 = p6 + 0.08;
				glutPostRedisplay();
			}
		}



		glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);
		response();
		glPopMatrix();

		if (p6 < 248.0)
		{
			glPushMatrix();
			glColor3f(0.6, 0.6, 0.6);
			downloading();
			glPopMatrix();

		}
		else
		{
			glPushMatrix();
			glColor3f(0.0, 0.0, 0.0);
			downloading();
			glPopMatrix();
			glPushMatrix();
			glColor3f(0.6, 0.6, 0.6);
			download();
			glPopMatrix();
			glEnd();
				downflag=1;
			if(downflag==1)
		{
			glPushMatrix();
			glColor3f(0.0,0.0,0.0);
			alreadyupload();
			glPopMatrix();
			glPushMatrix();
			glColor3f(0.6,0.6,0.6);
			alreadydownload();
			glPopMatrix();
		
		}
		}


	}
	if(p5>=175)
	{
		glPushMatrix();
		glColor3f(0.6,0.6,0.6);
		handshakepending();
		glPopMatrix();
	}
}
void downloading()// used to display the bitmap characters.
{
	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	ptr5 = "D O W N L O A D I N G ... ";

	len5 = strlen(ptr5);
	//glColor3f(0.60, 0.60, 0.60);
	glRasterPos3f(25.0, 190.0, 0.0);
	int i;
	for (i = 0; i<len5; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr5[i]);

	glPopMatrix();
	glutPostRedisplay();



	glFlush();
}


void download()// used to display the bitmap characters.
{
	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	ptr6 = "D O W N L O A D E D ";

	len6 = strlen(ptr6);
	//glColor3f(0.60, 0.60, 0.60);
	glRasterPos3f(25.0, 190.0, 0.0);
	for (i = 0; i<len6; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr6[i]);

	glPopMatrix();
	glutPostRedisplay();



	glFlush();
}


void request()// used to display the bitmap characters.
{
	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	ptr3 = " C L I E N T   R E Q U E S T.....  S I N = 1 ";

	len1 = strlen(ptr3);

	//glColor3f(0.60, 0.60, 0.60);
	glRasterPos3f(25.0, 315.0, 0.0);
	for (i = 0; i<len1; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr3[i]);

	glPopMatrix();
	glutPostRedisplay();
	glFlush();
}


void requestfinal()
{
	
	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	ptr3 = " H A N D S H A K E      D O N E !!!!!! ";

	len1 = strlen(ptr3);

	//glColor3f(0.60, 0.60, 0.60);
	glRasterPos3f(25.0, 315.0, 0.0);
	for (i = 0; i<len1; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr3[i]);

	glPopMatrix();
	glutPostRedisplay();
	glFlush();
}
void response()// used to display the bitmap characters.
{
	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	ptr4 = " S E R V E R   S E N D I N G...... A C K = 1 ";

	len2 = strlen(ptr4);

	//glColor3f(0.60, 0.60, 0.60);
	//glRasterPos3f(15.0, 190.0, 0.0);
	glRasterPos3f(2.0, 180.0, 0.0);
	for (i = 0; i<len2; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr4[i]);

	glPopMatrix();
	glutPostRedisplay();



	glFlush();

}




void handshake1V()//handshake process function
{
	if (p3 <= 175.0 && p4 == 200.0 && p3 > 100.0)
	{
		p3 = p3 - 0.08;

		glPushMatrix();
		glPointSize(2.0);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POINTS);
		glVertex2f(p3, p4);
		glEnd();
		glPopMatrix();
		glutPostRedisplay();
	}
	else
	{
		if (p3 <= 100.0 && p4<252.0)
		{
			p4 = p4 + 0.08;

			glPushMatrix();
			glColor3f(1.0, 1.0, 1.0);
			glPointSize(2.0);
			glBegin(GL_POINTS);
			glVertex2f(p3, p4);
			glEnd();
			glPopMatrix();
			glutPostRedisplay();
		}
	}
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.6);
	response();
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	handshakepending();
	glPopMatrix();
	if(p4>=252.0)
	{
		glPushMatrix();
		glColor3f(0.0,0.0,0.0);
		request();
		glPopMatrix();
		handshakecomplete();
	}
	glutPostRedisplay();
	//	glutSwapBuffers();
	glFlush();
}
void handshakecomplete()
{
	if (x1 >= 107.0 && x2 == 300.0 && x1 < 200.0)
	{
		x1 = x1 + 0.08;

		glPushMatrix();
		glPointSize(2.0);
		glColor3f(1.0, 0.5, 0.5);
		glBegin(GL_POINTS);
		glVertex2f(x1, x2);
		glEnd();
		glPopMatrix();
		glutPostRedisplay();
	}
	else
	{
		if (x1 >= 200.0 && x2>278.0)
		{
			x2 = x2 - 0.08;

			glPushMatrix();
			glColor3f(1.0, 0.0, 0.5);
			glPointSize(2.0);
			glBegin(GL_POINTS);
			glVertex2f(x1, x2);
			glEnd();
			glPopMatrix();
			glutPostRedisplay();
		}
	}
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.6);
	requestfinal();
	glPopMatrix();


//
//	if (p1 >= 200.0 & p2 <= 278.0)
//	{
//		handshake1V();
//	}
	flag = 1;

	//	glutSwapBuffers();
	glFlush();
	
}

void handshake1H()//handshake process function
{

	if (p1 >= 107.0 && p2 == 300.0 && p1 < 200.0)
	{
		p1 = p1 + 0.08;

		glPushMatrix();
		glPointSize(2.0);
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_POINTS);
		glVertex2f(p1, p2);
		glEnd();
		glPopMatrix();
		glutPostRedisplay();
	}
	else
	{
		if (p1 >= 200.0 && p2>278.0)
		{
			p2 = p2 - 0.08;

			glPushMatrix();
			glColor3f(1.0, 1.0, 1.0);
			glPointSize(2.0);
			glBegin(GL_POINTS);
			glVertex2f(p1, p2);
			glEnd();
			glPopMatrix();
			glutPostRedisplay();
		}
	}
	glPushMatrix();
	glColor3f(0.6, 0.6, 0.6);
	request();
	glPopMatrix();



	if (p1 >= 200.0 & p2 <= 278.0)
	{
		handshake1V();
	}

	//	glutSwapBuffers();
	glFlush();
}







void upload()//this function displays bitmap characters.
{
	
	upc3flag=0;
	downc3flag=0;
	
	upc4flag=0;
	downc4flag=0;
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload1();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload1();
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload2();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload2();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	ptr1 = "U P L O A D ";
	ptr2 = "E D ";
	len1 = strlen(ptr1);
	len2 = strlen(ptr2);
	glColor3f(0.60, 0.60, 0.60);
	glRasterPos3f(40.0, 315.0, 0.0);
	int i;
	for (i = 0; i<len1; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr1[i]);
	for (i = 0; i < len2; i++){

		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr2[i]);
	}
	glPopMatrix();
	glutPostRedisplay();



	glFlush();

}

void uploading()//this function displays bitmap characters.
{
	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	ptr1 = "U P L O A D ";
	ptr2 = "I N G . . .";
	len1 = strlen(ptr1);
	len2 = strlen(ptr2);

	glRasterPos3f(40.0, 315.0, 0.0);
	for (i = 0; i<len1; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr1[i]);
	for (i = 0; i < len2; i++){

		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr2[i]);
	}
	glPopMatrix();
	glutPostRedisplay();


	glFlush();

}


void oneoneU()//upload function for client 1.
{
			glPushMatrix();
			glColor3f(0.0,0.0,0.0);
			requestfinal();
			glPopMatrix();
			glPushMatrix();
			glColor3f(0.0,0.0,0.0);
			datatwostatus();
			glPopMatrix();
			
			
			glPushMatrix();
			glColor3f(0.0,0.0,0.0);
			dataonestatus();
			glPopMatrix();
	if (flag == 1)
	{

		if (pos1 >= 110.0 && pos1 < 200.0)
		{
			pos1 = pos1 + 0.08;
			glutPostRedisplay();

		}
		else
		{
			if (pos2 <= 300.0 && pos2 > 282.0)
			{
				pos2 = pos2 - 0.08;
				glutPostRedisplay();
			}
		}

		glPushMatrix();
		glColor3f(0.0, 0.0, 0.0);
		request();
		glPopMatrix();


		if (pos2 > 282.0)
		{

			glPushMatrix();
			glColor3f(0.60, 0.6, 0.6);
			uploading();
			glPopMatrix();
		}
		else
		{
			glPushMatrix();
			glColor3f(0.0, 0.0, 0.0);
			uploading();
			glPopMatrix();
			upload();
			upflag=1;
				if(upflag==1 )
				{
					glPushMatrix();
					glColor3f(0.0,0.0,0.0);
					alreadydownload();
					glPopMatrix();
					glPushMatrix();
					glColor3f(0.6,0.6,0.6);
					alreadyupload();
					glPopMatrix();
				}
		}

	}
	if (p1<= 107.0)
	{
		
			glPushMatrix();
			glColor3f(0.60, 0.6, 0.6);
			handshakepending();
			glPopMatrix();
		
	}
}         
void handshakepending()
{
			glPushMatrix();
			glTranslatef(100.0, 0.0, 0.0);
			ptr1 = " T C P   H A N D S H A K E   H A S  T O   B E   D O N E   B E T W E E N   C L I E N T - 1   A N D   S E R V E R  ";
			
		
			len2 = strlen(ptr1);
		
			//glColor3f(0.6, 0.6, 0.6);
			glRasterPos3f(50, 340.0, 0.0);
			for (i = 0; i<len2; i++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr1[i]);
			glPopMatrix();
			glutPostRedisplay();
			glFlush();
	
}
void alreadyupload()
{
			glPushMatrix();
			glTranslatef(100.0, 0.0, 0.0);
			ptr1 = " D A T A    I S   U P L O A D E D    F R O M   C L I E N T - 1   I N T O   S E R V E R ";
			
		
			len2 = strlen(ptr1);
		
			//glColor3f(0.6, 0.6, 0.6);
			glRasterPos3f(50, 340.0, 0.0);
			for (i = 0; i<len2; i++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr1[i]);
			glPopMatrix();
			glutPostRedisplay();
			glFlush();
	
}
void alreadydownload()
{
			glPushMatrix();
			glTranslatef(100.0, 0.0, 0.0);
			ptr1 = " D A T A    I S   D O W N L O A D E D   F R O M   S E R V E R    I N T O   C L I E N T - 1  ";
			
		
			len2 = strlen(ptr1);
		
			//glColor3f(0.6, 0.6, 0.6);
			glRasterPos3f(50, 340.0, 0.0);
			for (i = 0; i<len2; i++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr1[i]);
			glPopMatrix();
			glutPostRedisplay();
			glFlush();
	
}
void notifyhandshake()
{
	        glPushMatrix();
			glTranslatef(100.0, 0.0, 0.0);
			ptr1 = " T C P   H A N D S H A K E   I S  A L R E A D Y   D O N E ";
			
		
			len2 = strlen(ptr1);
		
			//glColor3f(0.60, 0.60, 0.60);
			glRasterPos3f(50, 340.0, 0.0);
			for (i = 0; i<len2; i++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr1[i]);
			glPopMatrix();
			glutPostRedisplay();
			glFlush();
			
}
void notifyDone()
{
			glPushMatrix();
			glColor3f(0.0, 0.0, 0.0);
			notifyhandshake();
			glPopMatrix();
			
			glPushMatrix();
			glTranslatef(100.0, 0.0, 0.0);
			ptr1 = "                                                                                                   ";
			
		
			len2 = strlen(ptr1);
		
			glColor3f(0.60, 0.60, 0.60);
			glRasterPos3f(50, 340.0, 0.0);
			for (i = 0; i<len2; i++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr1[i]);
			glPopMatrix();
			glutPostRedisplay();
			glFlush();
}



//	if (pos1==)





void one()//displays points as it increments.
{
	if (flag == 1){


		glPushMatrix();
		//glPointSize(4.0);
		glPointSize(6.0);
		glColor3f(0.20, 0.20, 2.0);
		glBegin(GL_POINTS);
		glVertex2f(pos1, pos2);
		glEnd();
		glPopMatrix();
		glFlush();

	}
}

void two()//displays points as it increments.
{
	if (flag == 1){




		glPushMatrix();
		//glPointSize(4.0);
		glPointSize(6.0);
		glColor3f(2.0, 0.20, 0.20);
		glBegin(GL_POINTS);
		glVertex2f(p5, p6);
		glEnd();
		glPopMatrix();
		glFlush();


	}
}

void three()//displays points as it increments.
{

	glPushMatrix();
	//glPointSize(4.0);
	glPointSize(6.0);
	glColor3f(0.20, 0.20, 2.0);
	glBegin(GL_POINTS);
	glVertex2f(p7, p8);
	glEnd();
	glPopMatrix();
	glFlush();

}
void four()//displays points as it increments.
{

	glPushMatrix();
	//glPointSize(4.0);
	glPointSize(6.0);
	glColor3f(2.0, 0.20, 0.20);
	glBegin(GL_POINTS);
	glVertex2f(p9, p10);
	glEnd();
	glPopMatrix();
	glFlush();

}

void five()//displays points as it increments.
{
	glPushMatrix();
	//glPointSize(4.0);
	glPointSize(6.0);
	glColor3f(0.20, 0.20, 2.0);
	glBegin(GL_POINTS);
	glVertex2f(p13, p14);
	glEnd();
	glPopMatrix();
	glFlush();


}
void six()//displays points as it increments.
{
	glPushMatrix();
	//glPointSize(4.0);
	glPointSize(6.0);
	glColor3f(2.0, 0.20, 0.20);
	glBegin(GL_POINTS);
	glVertex2f(p11, p12);
	glEnd();
	glPopMatrix();
	glFlush();
}

void seven()//displays points as it increments.
{
	glPushMatrix();
	//glPointSize(4.0);
	glPointSize(6.0);
	glColor3f(0.2, 0.20, 2.0);
	glBegin(GL_POINTS);
	glVertex2f(p15, p16);
	glEnd();
	glPopMatrix();
	glFlush();
}

void eight()//displays points as it increments.
{
	glPushMatrix();
	//glPointSize(4.0);
	glPointSize(6.0);
	glColor3f(2.0, 0.20, 0.20);
	glBegin(GL_POINTS);
	glVertex2f(p17, p18);
	glEnd();
	glPopMatrix();
	glFlush();
}


void display()//this function displays all the design and simulations.
{
	
	glPushMatrix();
	//glTranslatef(0.0, 0.0, 0.0);
	line();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 220.0, 0.0);
	line();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(260.0, 220.0, 0.0);
	line();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(260.0, 0.0, 0.0);
	line();
	glPopMatrix();


	glPushMatrix();
	server();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.22, 0.22, 0.22);
	glTranslatef(200.0, 140.0, 0.0);
	draw(7.0);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(200.0, 140.0, 0.0);
	draw(5.0);
	glPopMatrix();

	/*glPushMatrix();
	glColor3f(2.0, 0.2,0.2);
	glTranslatef(200.0, 140.0, 0.0);
	draw(3.0);
	glPopMatrix();
	*/

	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	char *ptr5 = "Client 2";
	int len5 = strlen(ptr5);
	glColor3f(0.3, 0.3, 0.3);
	glRasterPos3f(-53, 20, 0.0);
	for (i = 0; i<len5; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ptr5[i]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	char *ptr1 = "Client 1";
	int len1 = strlen(ptr1);
	glColor3f(0.3, 0.3, 0.3);
	glRasterPos3f(-53, 240, 0.0);
	for (i = 0; i<len1; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ptr1[i]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	char *ptr3 = "Client 3";
	int len3 = strlen(ptr3);
	glColor3f(0.3, 0.3, 0.3);
	glRasterPos3f(207, 240, 0.0);
	for (i = 0; i<len3; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ptr3[i]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	char *ptr4 = "Client 4";
	int len4 = strlen(ptr4);
	glColor3f(0.3, 0.3, 0.3);
	glRasterPos3f(207, 19, 0.0);
	for (i = 0; i<len4; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ptr4[i]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(100.0, 0.0, 0.0);
	char *ptr7 = "SERVER";
	int len7 = strlen(ptr4);
	glColor3f(0.3, 0.3, 0.3);
	glRasterPos3f(90, 85, 0.0);
	for (i = 0; i<len7; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ptr7[i]);

	glPopMatrix();


	glPushMatrix();

	one();

	glPopMatrix();

	glPushMatrix();

	two();

	glPopMatrix();

	glPushMatrix();
	if (count == 1)
	{
		three();
	}
	glPopMatrix();


	glPushMatrix();
	if (count1 == 1)
	{
		four();
	}
	glPopMatrix();

	glPushMatrix();
	if (dt == 1)
	{

		five();
	}
	glPopMatrix();


	glPushMatrix();
	if (dd == 1)
	{

		six();
	}
	glPopMatrix();

	glPushMatrix();
	if (da == 1)
	{

		seven();
	}
	glPopMatrix();

	glPushMatrix();
	if (db == 1)
	{

		eight();
	}
	glPopMatrix();


	glutSwapBuffers();
	glFlush();


}

void reshape(int w, int h)// this function is designed to reshape the display window if in case the display window is maximised or minimised.
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
	//glMatrixMode(GL_MODELVIEW);

}
void CS4(int b)//function for menu option 4
{
	
	
	if (b == 1)
	{
		
	glPushMatrix();
			glColor3f(0.0,0.0,0.0);
			datatwostatus();
			glPopMatrix();
			
			
			glPushMatrix();
			glColor3f(0.0,0.0,0.0);
			dataonestatus();
			glPopMatrix();
		da = 1;
		dat2 = 1;
		glutIdleFunc(fourfourU);
	}
	if (b == 2)
	{
		if (dat1 == 1)
		{

			db = 1;
			glutIdleFunc(fourfourD);
		}
		else
		{
			glPushMatrix();
			glColor3f(0.6,0.6,0.6);
			dataonestatus();
			glPopMatrix();
			
		}
	}
}


void CS3(int a)//function for menu option 3.
{
	upflag=0;
	downflag=0;
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload();
	glPopMatrix();
	
	
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload();
	glPopMatrix();
	
	if (a == 1)
	{
		dt = 1;
		dat1 = 1;
		
	glPushMatrix();
			glColor3f(0.0,0.0,0.0);
			datatwostatus();
			glPopMatrix();
			
			
			glPushMatrix();
			glColor3f(0.0,0.0,0.0);
			dataonestatus();
			glPopMatrix();
			glutIdleFunc(threethreeU);
	}
	if (a == 2)
	{
		if (dat2 == 1)
		{


			dd = 1;
			glutIdleFunc(threethreeD);
		}
		else
		{
			glPushMatrix();
			glColor3f(0.6,0.6,0.6);
			datatwostatus();
			glPopMatrix();
			
		}
	}
}


void CS2(int o)//function for menu option 2.
{
	
	upflag=0;
	downflag=0;
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload();
	glPopMatrix();
	
	
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload();
	glPopMatrix();
	if (o == 1)
	{


		count = 1;
		glutIdleFunc(twotwoU);
	}
	if (o == 2)
	{
		count1 = 1;
		glutIdleFunc(twotwoD);
	}

}



void CS1(int op)//function for menu option 1.
{
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadyupload();
	glPopMatrix();
	
	
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	alreadydownload();
	glPopMatrix();
	
			glPushMatrix();
			glColor3f(0.0,0.0,0.0);
		    glutIdleFunc(notifyhandshake);
		    glPopMatrix();
	if (op == 2)
	{
		glutIdleFunc(oneoneU);
		
	}
	if (op == 1)
	{
		if (flag == 0)
		{

			glutIdleFunc(handshake1H);
		}
		
		if (flag == 1)
		{
			glPushMatrix();
			glColor3f(0.6,0.6,0.6);
		    glutIdleFunc(notifyhandshake);
		    glPopMatrix();
		}
		//glutIdleFunc(handshake1V);

	}

	if (op == 3)
	{
		glutIdleFunc(oneoneD);
		
	}

}

void cs(int OP)//function for menu option 5.
{
	if (OP == 5)
	{
		exit(0);
	}
}


/*	void DT1(int op1)
{
}
void CS2(int opt)
{
}
void DT2(int op2)
{
}
*/

void frontscreen()
{
int i;
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 //glClearColor(1,1,1,0);
 glColor3f(0,0,1);
// drawstring(20.0,90.0,0.0,"NAME OF THE COLLEGE ");
 ptr6="              B  R  I  N  D  A  V  A  N     C  O  L  L  E  G  E   O  F   E  N  G  I  N  E  E  R  I  N  G  ";
 glRasterPos3f(100.0,340.0,0.0);
 len6=strlen(ptr6);
 for (i = 0; i<len6; i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr6[i]);

 glColor3f(0.7,0,1);
 ptr6="D E P A R T M E N T    O F    C O M P U T E R     S C I E N C E    A N D    E N G I N E E R I N G ";
 glRasterPos3f(100,320,0.0);
 len6=strlen(ptr6);
 for (i = 0; i<len6; i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr6[i]);
 glColor3f(1,0.5,0);
 ptr6="A   M I N I   P R O J E C T   O N  ";
 glRasterPos3f(160,280,0.0);
 len6=strlen(ptr6);
 for (i = 0; i<len6; i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr6[i]);
 //drawstring(21,82,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
 
 //drawstring(38,70,0.0,"A MINI PROJECT ON");
 //glColor3f(1,0,0);
 ptr6="  C L I E N T   S E R V E R    A R C H I T E C T U R E  ";
 glRasterPos3f(140,260,0.0);
 len6=strlen(ptr6);
 for (i = 0; i<len6; i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr6[i]);
 
 //drawstring(40,60,0.0,"PROJECT TITLE");
 //glColor3f(1,0.5,0);
 
 
 ptr6="U N D E R   T H E   G  U I D A N C E   O F                                                                                                   S U B M I T T E D    B Y:  ";
 glRasterPos3f(20,240,0.0);
 len6=strlen(ptr6);
 for (i = 0; i<len6; i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr6[i]);
 
 //drawstring(20,50,0.0,"BY:");
 //glColor3f(0.5,0,0.5);
 ptr6="                 PROF.   M E E N A T C H I   . R                                                                            N A M E  :  S  . K A L V I N   N A T H A N               U S N   :  1 B O 1 8 C S 0 7 9 ";
 glRasterPos3f(70,220,0.0);
 len6=strlen(ptr6);
 for (i = 0; i<len6; i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr6[i]);

 ptr6="                 PROF.   P A D M A V A T H I   H   G                                                                     N A M E  :  S H A R I F A   M                                 U S N   :  1 B O 1 8 C S 0 8 4 ";
 glRasterPos3f(70,200,0.0);
 len6=strlen(ptr6);
 for (i = 0; i<len6; i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr6[i]);

 ptr6="                                                                                                                                           N A M E  :  R  D I N E S H                                      U S N   :  1 B O 1 8 C S 0 7 1";
 glRasterPos3f(70,180,0.0);
 len6=strlen(ptr6);
 for (i = 0; i<len6; i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr6[i]);
//
// drawstring(10,40,0.0,"NAME FIRST           (USN)");
// drawstring(10,34,0.0,"NAME SECOND         (USN)");
// glColor3f(1,0.5,0);
//  ptr6=" P R E S S    x    T O     S T A R T   ";
// glRasterPos3f(70,140,0.0);
// len6=strlen(ptr6);
// for (i = 0; i<len6; i++)
	//glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ptr6[i]);
// drawstring(68,50,0.0,"GUIDES:");
// glColor3f(0.5,0.2,0.2);
// drawstring(63,40,0.0,"GUIDE NAME FIRST");
// drawstring(63,34,0.0,"GUIDE NAME SECOND");
// glColor3f(1,0.1,1);
 //drawstring(32,10,0.0,"PRESS ENTER TO START");
 glutSwapBuffers();
 
 glFlush();
 //frontflag=1;
}

void keys( unsigned char key, int x, int y )

{
// switch(key)
// {
// case 'x':if(frontflag==0) //Ascii of 'enter' key is 13
//    frontflag=1;
//  break;
//       }
	if(key=='x')
	{
		
		glutDisplayFunc(display);
	}
	glutPostRedisplay();
//    mydisplay();
}
//void mydisplay()
//{
// glClear(GL_COLOR_BUFFER_BIT);
// if(frontflag==0)
//   frontscreen ();
// if(frontflag==1)
//  {
//  	glutDisplayFunc(display);
//  	glutPostRedisplay();
//}
//}
void mytimer(int val)
{
	if(val==0)
		{
		glutDisplayFunc(display);
	}
	//glutIdleFunc(display);
	//front1flag=frontflag+1;
  	glutPostRedisplay();
}
void initRendering()

{

    glEnable(GL_DEPTH_TEST);

}

int main(int argc, char **argv)  //main function.
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1520, 790);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Client server architecture");
//lutCreateWindow(" Project ");
	Init();
//initRendering();
		glutDisplayFunc(frontscreen);
		glutTimerFunc(2000,mytimer,0);
			glutReshapeFunc(reshape);
	//sleep(5);
//	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//	
//	glutInitWindowSize(1520, 790);
//	glutInitWindowPosition(0, 0);
//	glutDisplayFunc(display);
//	
	//glutKeyboardFunc(keys);
	glutReshapeFunc(reshape);
	
	
	//glutDisplayFunc(display1);



	GLint id1 = glutCreateMenu(CS1);
	glutAddMenuEntry(" Handshake ", 1);
	glutAddMenuEntry(" Upload Data", 2);
	glutAddMenuEntry(" Download Data", 3);

	GLint id2 = glutCreateMenu(CS2);
	glutAddMenuEntry(" Upload Data", 1);
	glutAddMenuEntry(" Download Data ", 2);

	GLint id3 = glutCreateMenu(CS3);
	glutAddMenuEntry(" Upload Data 1", 1);
	glutAddMenuEntry(" Download Data 2", 2);

	GLint id4 = glutCreateMenu(CS4);
	glutAddMenuEntry(" Upload Data 2", 1);
	glutAddMenuEntry(" Download Data 1", 2);




	glutCreateMenu(cs);
	glutAddSubMenu("Client 1 - Server (TCP) ", id1);
	glutAddSubMenu("Client 2 - server (UDP) ", id2);
	glutAddSubMenu("Client 3 - Server ", id3);
	glutAddSubMenu("Client 4 - server ", id4);
	glutAddMenuEntry("Exit ", 5);
	//glutAddMenuEntry("Client 4 - server ",4);
	//	glutAttachMenu(GLUT_LEFT_BUTTON);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	//glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return(0);
}
