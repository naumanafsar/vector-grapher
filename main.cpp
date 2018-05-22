#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Gl_Window.H>
#include <FL/gl.h>
#include <FL/Fl_Value_Slider.H>
#include <FL/glut.H>
#include <FL/Fl_Double_Window.H>
#include <GL/glu.h>

using namespace std;

#include <cmath>

class MyGlWindow : public Fl_Gl_Window {
  // int handle(int event);
  // void draw();
  void computeCurve();
public:
	float r,g,b;
	MyGlWindow(int x, int y, int w, int h) :
	  Fl_Gl_Window(x,y,w,h,"My GL Window")
	  {
		  r = g = 1;
		  b = 0;
	 }

   void draw() {	// the draw method must be private

     if(!valid()) {  //valid() is magic set after first draw() call.
       glEnable(GL_DEPTH_TEST);
       glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
       gluPerspective(40, 1, 10, 120);

       glMatrixMode(GL_MODELVIEW);
       glLoadIdentity();
       gluLookAt(0, 0, 50, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
       glScalef(.3,.3,.3);

       computeCurve();
     }
     glClearColor(0.0, 0.0, 0.0, 0.0);
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glCallList(1);

       glMatrixMode(GL_PROJECTION);	// set up coord system
       glLoadIdentity();			// reset it
       glOrtho(-1,1,-1,1,-1,1);	// set it to be -1 to 1 in each axis
       glMatrixMode(GL_MODELVIEW);	// back to normal mode
       glLoadIdentity();			// clear what anyone else did

       glClearColor(0,0,0,0);		// clear the window to black
       glClear(GL_COLOR_BUFFER_BIT);	// clear the window
        glBegin(GL_LINE_STRIP);
        glColor3f(1, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(20, 0, 0);
        glVertex3f(0, 0, 0);
        glColor3f(0, 1, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 20, 0);
        glVertex3f(0, 0, 0);
        glColor3f(0, 0, 1);
        glVertex3f(0, 0,  0);
        glVertex3f(0, 0, 20);
        glEnd();

        computeCurve();
   }

 };

 // int MyGlWindow::handle(int event) {
 // 	static int x ,y;
 // 	switch (event) {
 // 		case FL_PUSH:
 // 		make_current();
 // 		x = Fl::event_x();
 //     y = Fl::event_y();
 //     return 1;
 // 		  cout << "It is pushed..!";
 // 	}
 // 	redraw();
 // }

 void MyGlWindow::computeCurve() {

   gl_start();
   GLfloat ang, x, y, z = -50;
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();
   glRotatef(90,1,0,0);
   glColor3f(1,0,0);
   glBegin(GL_POINTS);
   for(ang = 0; ang < 10 * 3.14; ang += .1) {
   x = 70 *sin(ang);
   y = 70 *cos(ang);
   z += .75;
   glVertex3f(x,y,z);
   }
   glEnd();
   redraw();

 }



    // gl_start();
    // GLfloat ang, x, y, z = -50;
    // glClear(GL_COLOR_BUFFER_BIT);
    // glPushMatrix();
    // glRotatef(90,1,0,0);
    // glColor3f(1,0,0);
    // glBegin(GL_POINTS);
    // for(ang = 0; ang < 10 * 3.14; ang += .1) {
    // x = 70 *sin(ang);
    // y = 70 *cos(ang);
    // z += .75;
    // glVertex3f(x,y,z);
    // }
    // glEnd();
    // glPopMatrix();
    // glFlush();

		// glColor3f(r,g,b);			// draw in yellow
		// glRectf(-.5,-.5,.5,.5);		// draw a filled rectangle




void ButCall(Fl_Widget *w) {
  cout << "The Button was Clicked!" << endl;

};
int main(int argc, char **argv) {

  Fl_Window* wind = new Fl_Window(20,62,800,500,"Vector Grapher");

  wind->begin();


  // Fl_Window *window = new Fl_Window(800,600, "Vector Grapher");

  Fl_Tabs *tabs = new Fl_Tabs(0,0, 800, 500, "Vector Grapher");
  {
    Fl_Group *grp1 = new Fl_Group(10,22,790,570,"Generate Graph");
      {
        // Fl_Box *box = new Fl_Box(20,62,300,350,"OpenGL Window");
        MyGlWindow *gl = new MyGlWindow(20,62,300,350);
        Fl_Button *rotRight = new Fl_Button(420, 382, 95, 30, "Rotate Right");
        Fl_Button *rotLeft = new Fl_Button(325, 382, 92, 30, "Rotate Left");


        Fl_Input *xAxis = new Fl_Input(540, 62, 250, 40, "Enter X-axis: ");
        Fl_Input *yAxis = new Fl_Input(540, 105, 250, 40, "Enter Y-axis: ");
        Fl_Input *zAxis = new Fl_Input(540, 150, 250, 40, "Enter Z-axis: ");

        Fl_Button *genGraph = new Fl_Button(570, 192, 160, 30, "Generate Graph");
        genGraph->callback(ButCall);

        genGraph->type(FL_NORMAL_BUTTON);
        // button2->type(FL_NORMAL_BUTTON)
        cout << xAxis->value();
        yAxis->value();
        xAxis->value();
        // gl->show();

        // box->box(FL_UP_BOX);
        // box->labelfont(FL_BOLD+FL_ITALIC);
        // box->labelsize(14);
        // box->labeltype(FL_SHADOW_LABEL);

      }
      grp1->labelsize(14);
      grp1->end();

    Fl_Group *grp2 = new Fl_Group(22,20,790,570,"Instruction");
      {
        Fl_Text_Buffer *buff = new Fl_Text_Buffer();
       Fl_Text_Display *disp = new Fl_Text_Display(0, 20, 800, 450);
       disp->buffer(buff);
       buff->text("A couple of Intstructions!");
      }
      grp2->labelsize(14);
      grp2->end();

    Fl_Group *grp3 = new Fl_Group(22,20,790,570,"License");
      {
        Fl_Text_Buffer *buff = new Fl_Text_Buffer();
       Fl_Text_Display *disp = new Fl_Text_Display(0, 20, 800, 450);
       disp->buffer(buff);
       buff->text("MIT License \n \n       Copyright (c) 2018 Mehmood Munir , Ahmed Waheed and Nauman Afsar \n \nPermission is hereby granted, free of charge, to any person obtaining a copy\nof this software and associated documentation files (the \"Software\"), to dealin the Software without \n restriction, including without limitation the rights \nto use, copy, modify, merge, publish, distribute, sublicense, and/or sell \n copies of the Software, and to permit persons to whom the Software is \n furnished to do so, subject to the following conditions: \n \n       The above copyright notice and this permission notice shall be included in all\ncopies or substantial portions of the Software. \n \nTHE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR \nIMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, \nFITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE \n AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\nLIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.");
      }
      grp3->labelsize(14);
      grp3->end();

  }
  tabs->end();


  // window->end();
  // window->show(argc, argv);
  wind->end();

  wind->show();
  return Fl::run();
}
