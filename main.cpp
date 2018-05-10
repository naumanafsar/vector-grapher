#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Input.H>
#include <FL/gl.h>
#include <cmath>


int main(int argc, char **argv) {
  Fl_Window *window = new Fl_Window(800,600, "Vector Grapher");

  Fl_Tabs *tabs = new Fl_Tabs(0,0, 800, 600, "Vector Grapher");
  {
    Fl_Group *grp1 = new Fl_Group(10,22,790,570,"Generate Graph");
      {
        Fl_Box *box = new Fl_Box(20,62,300,350,"OpenGL Window");
        Fl_Button *button1 = new Fl_Button(325, 350, 80, 30, "Rotate X");
        Fl_Button *button2 = new Fl_Button(325, 382, 80, 30, "Rotate Y");


        Fl_Input *input1 = new Fl_Input(540, 62, 250, 40, "Enter X-axis: ");
        Fl_Input *input2 = new Fl_Input(540, 105, 250, 40, "Enter Y-axis: ");
        Fl_Input *input3 = new Fl_Input(540, 150, 250, 40, "Enter Z-axis: ");

        Fl_Button *button5 = new Fl_Button(570, 192, 160, 30, "Generate Graph");

        button5->type(FL_NORMAL_BUTTON);
        // button2->type(FL_NORMAL_BUTTON)
        input1->value();
        input2->value();
        input3->value();
      //   gl_start();
      //   GLfloat ang, x, y, z = -50;
      // 	glClear(GL_COLOR_BUFFER_BIT);
      // 	glPushMatrix();
      // 	glRotatef(90,1,0,0);
      // 	glColor3d(1,1,1);
      // 	// glutSwapBuffers();
      //   glBegin(GL_POINTS);
      //   for(ang = 0; ang < 10 * 3.14; ang += .1) {
    	// 		x = 70 *sin(ang);
    	// 		y = 70 *cos(ang);
    	// 		z += .75;
    	// 		glVertex3d(x,y,z);
      //
    	// 	}
    	// glEnd();
      //   gl_finish();
        box->box(FL_UP_BOX);
        box->labelfont(FL_BOLD+FL_ITALIC);
        box->labelsize(14);
        box->labeltype(FL_SHADOW_LABEL);

      }
      grp1->labelsize(14);
      grp1->end();

    Fl_Group *grp2 = new Fl_Group(22,20,790,570,"Instruction");
      {
        Fl_Text_Buffer *buff = new Fl_Text_Buffer();
       Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 640-40, 480-40);
       disp->buffer(buff);
       buff->text("A couple of Intstructions!");
      }
      grp2->labelsize(14);
      grp2->end();

    Fl_Group *grp3 = new Fl_Group(22,20,790,570,"License");
      {
        Fl_Text_Buffer *buff = new Fl_Text_Buffer();
       Fl_Text_Display *disp = new Fl_Text_Display(20, 20, 790, 570);
       disp->buffer(buff);
       buff->text("MIT License \n \n       Copyright (c) 2018 Mehmood Munir , Ahmed Waheed and Nauman Afsar \n \n       Permission is hereby granted, free of charge, to any person obtaining a copy  \n     of this software and associated documentation files (the \"Software\"), to dealin the Software without \n restriction, including without limitation the rights \n       to use, copy, modify, merge, publish, distribute, sublicense, and/or sell \n copies of the Software, and to permit persons to whom the Software is \n furnished to do so, subject to the following conditions: \n       The above copyright notice and this permission notice shall be included in all       \n copies or substantial portions of the Software. \n       THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR \n \n IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, \n       FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE \n AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER \n       LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, \n       OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE \n       SOFTWARE.");
      }
      grp3->labelsize(14);
      grp3->end();

  }
  tabs->end();


  window->end();
  window->show(argc, argv);
  return Fl::run();
}
