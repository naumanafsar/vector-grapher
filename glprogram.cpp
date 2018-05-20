#include<GL/gl.h>
#include<GL/glut.h>
#include<iostream>
#include<fstream>
#include"function.cpp"




void renderer(void){
 GLfloat ang, x, y, z = -50;

	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(90,1,0,0);
	glColor3f(1,0,0);
	glBegin(GL_POINTS);
	point a;
	point b;
	point c;
	point p;
	p.generate(a,b,c,"sin(t)","cos(t)","t^1");
	p.makingPointsFile(a,b,c,-1000,50);
	fstream infile;
	infile.open("file.txt",ios::in);
	while(!infile.eof()) {
		long double x;
		long double y;
		long double z;
		infile>>x;
		infile>>y;
		infile>>z;
		//cout<<x<<endl;
		glVertex3f(x,y,z);
	}
	glEnd();
	glPopMatrix();
	glFlush();
}
void changeSize(GLsizei w, GLsizei h) {
	GLfloat sideRange = 200;

	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-sideRange, sideRange, -sideRange, sideRange, sideRange, -sideRange);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void initialSetup(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}


int main (int argc, const char * argv[])
{
	glutInit(&argc, (char **)argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("First Program");
	glutDisplayFunc(renderer);
	glutReshapeFunc(changeSize);
	initialSetup();
	glutMainLoop();
	return 0;
}

