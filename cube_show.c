#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <Python.h>
#define W 0//white
#define Y 1//yellow
#define R 2//red
#define O 3//orange
#define B 4//blue
#define G 5//green
#define K 6
#define T 1.0/6
#define F 1.0/3

static double distance = 2.0, pitch = -45.0, yaw = 45.0;
//char* formula;
GLint mouse_button = -1;
GLint mouse_x = 0, mouse_y = 0;
int i,j;
int counter=0;
int len_formula;
int mili_second=0;
static float gDrawRotateAngle=0;

static const GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
static const GLfloat light_ambient[] = {0.4, 0.4, 0.4, 1.0};
static const GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};

static const GLfloat mat_default_color[] = { 1.0, 1.0, 1.0, 1.0 };
static const GLfloat mat_default_specular[] = { 1.0, 1.0, 1.0, 1.0 };
static const GLfloat mat_default_shininess[] = { 100.0 };
static const GLfloat mat_default_emission[] = {0.0, 0.0, 0.0, 0.0};

/*
char corner_permu[8]={'a','b','c','d','e','f','g','h'};
int  corner_ori[8]  ={0,0,0,0,0,0,0,0};
int  edge_permu[12] ={1,2,3,4,5,6,7,8,9,10,11,12};
int  edge_ori[12]   ={0,0,0,0,0,0,0,0,0,0 ,0 ,0 };
*/
/*
char corner_permu[8]={'a','h','d','g','c','e','b','f'};
int corner_ori[8]={0,-1,1,-1,-1,0,0,-1};
int edge_permu[12]={9,7,8,12,3,5,2,1,11,10,6,4};
int edge_ori[12]={1,1,1,0,1,1,0,1,0,1,1,0};
*/

char corner_permu[8]={'b','c','d','a','e','f','g','h'};
int corner_ori[8]={-1,0,1,0,0,0,0,0};
int edge_permu[12]={5,6,2,3,1,7,8,4,10,11,12,9};
int edge_ori[12]={1,0,1,1,1,0,1,1,0,0,0,0};
/*
char corner_permu[8]={'f','e','b','d','c','g','h','a'};
int corner_ori[8]={0,-1,-1,1,0,0,0,1};
int edge_permu[12]={7,4,1,6,3,8,2,5,10,11,12,9};
int edge_ori[12]={0,1,0,1,0,1,1,0,0,0,0,0};
*/
int buf_int;
char buf_char;
void makecube(int u,int d,int f,int b,int r,int l);

void rotate(char rotation);
int search_char(char *array,char want);
int search(int *array,int want);

int search(int array[], int want){
  int i;
  int size= sizeof(array)/sizeof(array[0]);
  for(i=0;i<12;i++){
    if(array[i]==want)

      break;
    
  }
  return i;
}

int search_char(char *array,char want){
  int i;
  int size=sizeof(array)/sizeof(array[0]);
  for(i=0;i<size;i++){
    if(array[i]==want)
      break;
  }
  return i;
}
void change_edge_permu(int one,int two,int three,int four){
 
  int edge_at_one,edge_at_two,edge_at_three,edge_at_four;
  edge_at_one=search(edge_permu,one);
  edge_at_two=search(edge_permu,two);
  edge_at_three=search(edge_permu,three);
  edge_at_four=search(edge_permu,four);
  edge_permu[edge_at_one]=two;
  edge_permu[edge_at_two]=three;
  edge_permu[edge_at_three]=four;
  edge_permu[edge_at_four]=one;
 
}

void edge_ori_change(int edge_at,int ori){
  if(ori==1){
    if(edge_ori[edge_at]==1)
      edge_ori[edge_at]=0;
    else if(edge_ori[edge_at]==0)
      edge_ori[edge_at]=1;
  }

}
void change_edge_ori(int one,int two, int three, int four,int one_ori,int two_ori, int three_ori, int four_ori){
  int edge_at_one,edge_at_two,edge_at_three,edge_at_four;
  edge_at_one=search(edge_permu,one);
  edge_at_two=search(edge_permu,two);
  edge_at_three=search(edge_permu,three);
  edge_at_four=search(edge_permu,four);
  edge_ori_change(edge_at_one,one_ori);
  edge_ori_change(edge_at_two,two_ori);
  edge_ori_change(edge_at_three,three_ori);
  edge_ori_change(edge_at_four,four_ori);
}

void change_corner_permu(char one,char two,char three,char four){
  int corner_at_one,corner_at_two,corner_at_three,corner_at_four;
  corner_at_one=search_char(corner_permu,one);
  corner_at_two=search_char(corner_permu,two);
  corner_at_three=search_char(corner_permu,three);
  corner_at_four=search_char(corner_permu,four);
  corner_permu[corner_at_one]=two;
  corner_permu[corner_at_two]=three;
  corner_permu[corner_at_three]=four;
  corner_permu[corner_at_four]=one;

}
void corner_ori_change(int corner_at,int ori){
  corner_ori[corner_at]+=ori;
  if(corner_ori[corner_at]==2)
    corner_ori[corner_at]=-1;
  else if(corner_ori[corner_at]==-2)
    corner_ori[corner_at]=1;

}

void change_corner_ori(char one, char two, char three, char four, int one_ori, int two_ori, int three_ori, int four_ori){

  int corner_at_one,corner_at_two,corner_at_three,corner_at_four;

  corner_at_one=search_char(corner_permu,one);
  corner_at_two=search_char(corner_permu,two);
  corner_at_three=search_char(corner_permu,three);
  corner_at_four=search_char(corner_permu,four);
  corner_ori_change(corner_at_one,one_ori);
  corner_ori_change(corner_at_two,two_ori);
  corner_ori_change(corner_at_three,three_ori);
  corner_ori_change(corner_at_four,four_ori);

}

void rotate(char rotation){
  switch(rotation){

  case 'U':
    change_corner_ori('a','b','c','d',0,0,0,0);
    change_corner_permu('a','b','c','d');
    change_edge_ori(1,2,3,4,0,0,0,0);
    change_edge_permu(1,2,3,4);
    break;

  case 'D':
    change_corner_ori('e','h','g','f',0,0,0,0);
    change_corner_permu('e','h','g','f');
    change_edge_ori(9,12,11,10,0,0,0,0);
    change_edge_permu(9,12,11,10);
    
    break;

  case 'F':
    change_corner_ori('c','g','h','d',1,-1,1,-1);
    change_corner_permu('c','g','h','d');
    change_edge_ori(7,11,8,3,1,1,1,1);
    change_edge_permu(7,11,8,3);
    break;

  case 'B':
    change_corner_ori('a','e','f','b',1,-1,1,-1);
    change_corner_permu('a','e','f','b');
    change_edge_ori(1,5,9,6,1,1,1,1);
    change_edge_permu(1,5,9,6);

    break;

  case 'R':
    change_corner_ori('b','f','g','c',1,-1,1,-1);
    change_corner_permu('b','f','g','c');
    change_edge_ori(2,6,10,7,0,0,0,0);
    change_edge_permu(2,6,10,7);

    break;

  case 'L':
    change_corner_ori('a','d','h','e',-1,1,-1,1);
    change_corner_permu('a','d','h','e');
    change_edge_ori(4,8,12,5,0,0,0,0);
    change_edge_permu(4,8,12,5);
    
    break;
}
}
void init(void)
{
  glClearColor (0.0,0.0,0.05,1.0);
  glClearDepth(1.0);
  
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glShadeModel(GL_SMOOTH);
}

void choose_color(int color){

  switch(color){
  case(W):  glColor3f(0.9f, 0.9f, 0.9f);break;     // white
  case(Y):  glColor3f(0.9f, 0.9f, 0.0f);break;     // Yellow
  case(R):  glColor3f(0.8f, 0.0f, 0.0f);break;     // Red
  case(O):  glColor3f(1.0f, 0.3f, 0.0f);break;     // Orange
  case(B):  glColor3f(0.0f, 0.0f, 0.5f);break;     // Blue
  case(G):  glColor3f(0.0f, 0.6f, 0.0f);break;     // Green
  default: glColor3f(0.0f, 0.0f, 0.0f);break;
  }
}

void make_center()
{
  glPushMatrix();
  glTranslatef( F, 0, 0);
  makecube(W,Y,R,O,B,G);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-F, 0, 0);
  makecube(W,Y,R,O,B,G);
  glPopMatrix();

  glPushMatrix();
  glTranslatef( 0, F, 0);
  makecube(W,Y,R,O,B,G);
  glPopMatrix();

  glPushMatrix();
  glTranslatef( 0,-F, 0);
  makecube(W,Y,R,O,B,G);
  glPopMatrix();

  glPushMatrix();
  glTranslatef( 0, 0, F);
  makecube(W,Y,R,O,B,G);
  glPopMatrix();

  glPushMatrix();
  glTranslatef( 0, 0,-F);
  makecube(W,Y,R,O,B,G);
  glPopMatrix();
}

void make_edge(int permu, int ori, int u, int b, int l, int f, int d, int r)
{
  glPushMatrix();
  switch(permu){
  case(1):
    glTranslatef( 0, F,-F);
    glRotatef(0,0,1,0);
    break;
  case(2):
    glTranslatef( F, F, 0);
    glRotatef(-90,0,1,0);
    break;
  case(3):
    glTranslatef( 0, F, F);
    glRotatef(-180,0,1,0);
    break;
  case(4):
    glTranslatef(-F, F, 0);
    glRotatef(-270,0,1,0);
    break;
  case(5):
    glTranslatef(-F, 0,-F);
    glRotatef( 90,0,1,0); 
    glRotatef(-90,0,0,1);
    break;
  case(6):
    glTranslatef( F, 0,-F);
    glRotatef(-90,0,1,0);
    glRotatef(90,0,0,1);
    break;
  case(7):
    glTranslatef( F, 0, F);
    glRotatef(-90,0,1,0);
    glRotatef(-90,0,0,1);
    break;
  case(8):
    glTranslatef(-F, 0, F);
    glRotatef(90,0,1,0);
    glRotatef(90,0,0,1);
    break;
  case(9):
    glTranslatef( 0,-F,-F);
    glRotatef(-180,0,0,1);
    glRotatef(0,0,1,0);
    break;
  case(10):
    glTranslatef( F,-F, 0);
    glRotatef(-180,0,0,1);
    glRotatef( 90,0,1,0);
    break;
  case(11):
    glTranslatef( 0,-F, F);
    glRotatef(-180,0,0,1);
    glRotatef(180,0,1,0);
    break;
  case(12):
    glTranslatef( -F,-F, 0);
    glRotatef(-180,0,0,1);
    glRotatef(270,0,1,0);
    break;
  default:
    break;
  }
  switch(ori){
  case(0):
    break;
  case(1):
    glRotatef(-180, 0,1,-1);
    break;
  default:
    break;
  }
  makecube(u,d,f,b,r,l);
  glPopMatrix();
}

void make_corner(char permu, int ori,int u,int b, int l, int f, int d, int r)
{
  glPushMatrix();

  switch(permu){
  case('a'):
    glTranslatef(-F, F,-F);
    glRotatef(0,0,1,0);    
    break;
  case('b'):
    glTranslatef( F, F,-F);
    glRotatef(-90,0,1,0);
    break;
  case('c'):
    glTranslatef( F, F, F);
    glRotatef(-180,0,1,0);
    break;
  case('d'):
    glTranslatef(-F, F, F);
    glRotatef(-270,0,1,0);
    break;
  case('e'):
    glTranslatef(-F,-F,-F);
    glRotatef(-180,1,0,0);
    glRotatef(-270,0,1,0);
    break;
  case('f'):
    glTranslatef( F,-F,-F);
    glRotatef(-180,1,0,0);
    glRotatef(-180,0,1,0);

    break;
  case('g'):
    glTranslatef( F,-F, F);
    glRotatef(-180,1,0,0);
    glRotatef(-90,0,1,0);

    break;
  case('h'):
    glTranslatef(-F,-F, F);
    glRotatef(-180,1,0,0);
    glRotatef(-0,0,1,0);
   
    break;
  default:
    break;
  }
  switch(ori){
  case(0):
    break;
  case(1):
    glRotatef(-240,-1,1,-1);
    break;
  case(-1):
    glRotatef(-120,-1,1,-1);
    break;
  default:
    break;
  }
   
  makecube(u,d,f,b,r,l);
  glPopMatrix();
}
void makecube(int u, int d, int f, int b, int r, int l){
 
  glBegin(GL_QUADS);
  choose_color(u);
  glVertex3f(-T, T,-T);
  glVertex3f( T, T,-T);
  glVertex3f( T, T, T);
  glVertex3f(-T, T, T);
  
  choose_color(d);
  glVertex3f(-T,-T,-T);
  glVertex3f( T,-T,-T);
  glVertex3f( T,-T, T);
  glVertex3f(-T,-T, T);
    
  choose_color(f);
  glVertex3f(-T,-T, T);
  glVertex3f( T,-T, T);
  glVertex3f( T, T, T);
  glVertex3f(-T, T, T);
  
  choose_color(b);
  glVertex3f(-T,-T,-T);
  glVertex3f( T,-T,-T);
  glVertex3f( T, T,-T);
  glVertex3f(-T, T,-T);
  
  choose_color(r);
  glVertex3f( T,-T,-T);
  glVertex3f( T, T,-T);
  glVertex3f( T, T, T);
  glVertex3f( T,-T, T);
  
  choose_color(l);
  glVertex3f(-T,-T,-T);
  glVertex3f(-T, T,-T);
  glVertex3f(-T, T, T);
  glVertex3f(-T,-T, T);
  
  glEnd();

}




static void DrawCubeUpdate(float timeDelta)
{
  //  gDrawRotateAngle+=timeDelta*30.0f;
    gDrawRotateAngle+=timeDelta*0.0f;
  if(gDrawRotateAngle>360.0f) gDrawRotateAngle-=360.0f;
}

void display(void)
{  
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
  glMatrixMode(GL_MODELVIEW);    
 
  glLoadIdentity();   
    gluLookAt(0.0,0.0,distance,0.0,0.0,0.0,0.0,1.0,0.0);

  glRotatef(-pitch,1.0,0.0,0.0);
  glRotatef(-yaw,0.0,1.0,0.0);

  /////////////////////////////////////////////////////////









  //////////////////////////////////////////////////////
  glPushMatrix();
  {
    glRotatef(gDrawRotateAngle,0.0,1.0,0.0);
    glRotatef(gDrawRotateAngle,1.0,0.0,0.0);

    make_corner(corner_permu[0],corner_ori[0],W,O,G,K,K,K);
    make_corner(corner_permu[1],corner_ori[1],W,B,O,K,K,K);
    make_corner(corner_permu[2],corner_ori[2],W,R,B,K,K,K);
    make_corner(corner_permu[3],corner_ori[3],W,G,R,K,K,K);
    make_corner(corner_permu[4],corner_ori[4],Y,G,O,K,K,K);
    make_corner(corner_permu[5],corner_ori[5],Y,O,B,K,K,K);
    make_corner(corner_permu[6],corner_ori[6],Y,B,R,K,K,K);
    make_corner(corner_permu[7],corner_ori[7],Y,R,G,K,K,K);

    make_edge(edge_permu[0],edge_ori[0],W,O,K,K,K,K);
    make_edge(edge_permu[1],edge_ori[1],W,B,K,K,K,K);
    make_edge(edge_permu[2],edge_ori[2],W,R,K,K,K,K);
    make_edge(edge_permu[3],edge_ori[3],W,G,K,K,K,K);
    make_edge(edge_permu[4],edge_ori[4],O,G,K,K,K,K);
    make_edge(edge_permu[5],edge_ori[5],O,B,K,K,K,K);
    make_edge(edge_permu[6],edge_ori[6],R,B,K,K,K,K);
    make_edge(edge_permu[7],edge_ori[7],R,G,K,K,K,K);
    make_edge(edge_permu[8],edge_ori[8],Y,O,K,K,K,K);
    make_edge(edge_permu[9],edge_ori[9],Y,B,K,K,K,K);
    make_edge(edge_permu[10],edge_ori[10],Y,R,K,K,K,K);
    make_edge(edge_permu[11],edge_ori[11],Y,G,K,K,K,K);

    make_center();
    
  }
  glPopMatrix();

 
  glPopMatrix();
  glutSwapBuffers();
}

void reshape(int w,int h)
{
  glViewport (0,0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0,(GLfloat)w/(GLfloat)h,1.0,20.0);
}

void keyboard (unsigned char key, int x, int y)
{
  switch (key){
  case 27:
    exit(0);
    break;
  case 'f':

    counter=0;
    /*    //    printf("%c",formula[counter]);
    rotate(formula[counter]);

    //      if(counter<len_formula){
    	if(formula[counter+1]!='2'||'3'){
	  rotate(formula[counter]);
	}
	else if(formula[counter+1]=='2'){
	  rotate(formula[counter]);
	  rotate(formula[counter]);
	}
	else if(formula[counter+1]=='3'){
	  rotate(formula[counter]);
	  rotate(formula[counter]);
	  rotate(formula[counter]);
	}
    	//   }
	*/
    break;
  }
}


void mouse(int button, int state, int x, int y)
{
  mouse_button=button;
  mouse_x=x,mouse_y=y;

  if(state==GLUT_UP){
    mouse_button=-1;
  }
  glutPostRedisplay();
}


void motion(int x,int y)
{
  switch(mouse_button){
  case GLUT_LEFT_BUTTON:
    if(x==mouse_x&y==mouse_y)
      return;

    yaw-=(GLfloat)(x-mouse_x)/10.0;
    pitch-=(GLfloat)(y-mouse_y)/10.0;

    break;
  case GLUT_RIGHT_BUTTON:
    if(y==mouse_y)
      return;
    if(y<mouse_y)
      distance+=(GLfloat) (mouse_y-y)/50.0;
    else
      distance-=(GLfloat) (y-mouse_y)/50.0;

    if (distance<1.0) distance=1.0;
    if (distance>10.0) distance=10.0;
    break;
  }
  mouse_x=x;
  mouse_y=y;

  glutPostRedisplay();
}

void idle()
{
  static int ms_prev;
  int ms;
  float s_elapsed;
  ms=glutGet(GLUT_ELAPSED_TIME);
  s_elapsed=(float)(ms-ms_prev)*0.001;
  if(s_elapsed<0.01f) return;



  mili_second+=(ms-ms_prev);


  ms_prev=ms;
  //  DrawCubeUpdate(s_elapsed);
  





  //////////////////////////////////////
  /*


  if(mili_second>1000)
    {
      if(counter<len_formula-1){
	if(formula[counter+1]!='2'||'3'){
	  rotate(formula[counter]);
	}
	else if(formula[counter+1]=='2'){
	  rotate(formula[counter]);
	  rotate(formula[counter]);
	}
	else if(formula[counter+1]=='3'){
	  rotate(formula[counter]);
	  rotate(formula[counter]);
	  rotate(formula[counter]);
	}
      }
      mili_second=0;
    }

  */
  //////////////////////////////////////















  glutPostRedisplay();
}


/*



void get_cube_form(){
  PyObject* solver = PyImport_ImportModule("solver");
  if(solver) {
    
    
    PyObject* cube_form = PyObject_GetAttrString(solver, "cube_form");
    if(cube_form) {
      
      PyObject *r = PyObject_CallFunction(cube_form, NULL);
      if (PyString_Check(r)) {
	cube_str =PyString_AsString(r);
      }
      Py_XDECREF(r);
      Py_XDECREF(cube_form);
      
      

      

      
    }
  Py_XDECREF(solver);
  }
  


}




void get_solution(){
    PyObject* solver = PyImport_ImportModule("solver");
    if(solver) {
      PyObject* solution = PyObject_GetAttrString(solver, "solution");
      if(solution) {
	
	PyObject *d = PyObject_CallFunction(solution, NULL);
	if (PyString_Check(d)) {
	  formula =PyString_AsString(d);
	}
	Py_XDECREF(d);
	Py_XDECREF(solution);

      

      }	
    Py_XDECREF(solver);
    }



}
*/


int main(int argc, char** argv)
{
  int i;
  int count=0;
  int buf;
  char* cube_str;
  //  char* formula;
  char* cube_info;
  int len_cube;
  printf("oktogo");
  Py_Initialize();
  if (Py_IsInitialized()) {    
    PySys_SetArgv(argc, argv);


    PyObject* solver = PyImport_ImportModule("solver");
    if(solver) {
      PyObject* get_cube = PyObject_GetAttrString(solver, "send_cube");
      if(get_cube) {
	
	PyObject *d = PyObject_CallFunction(get_cube, NULL);
	if (PyString_Check(d)) {
	  cube_info =PyString_AsString(d);
	}
	Py_XDECREF(d);
	Py_XDECREF(get_cube);

      

      }	
    Py_XDECREF(solver);
    }
  
  Py_Finalize();
    }


        printf("%s\n",cube_info);
  


        len_cube=strlen(cube_info);
  
  
	printf("%d\n",len_cube);
      
  for(i=0;i<8;i++){
    corner_permu[i]=cube_info[i];
  }
  count+=8;
  for(i=0;i<8;i++){
    char moji=cube_info[i+count];
    switch(moji){
    case 't':
      buf=-1;
      break;
    case '0':
      buf=0;
      break;
    case '1':
      buf=1;
      break;
    }
    corner_ori[i]=buf;
  }
  count+=8;
  for(i=0;i<12;i++){
    switch(cube_info[i+count]){
    case('1'):
      buf=1;
      break;
    case('2'):
      buf=2;
      break;
    case('3'):
      buf=3;
      break;
    case('4'):
      buf=4;
      break;
    case('5'):
      buf=5;
      break;
    case('6'):
      buf=6;
      break;
    case('7'):
      buf=7;
      break;
    case('8'):
      buf=8;
      break;
    case('9'):
      buf=9;
      break;
    case('x'):
      buf=10;
      break;
    case('y'):
      buf=11;
      break;
    case('z'):
      buf=12;
      break;
    }
    edge_permu[i]=buf;
  }
  count+=12;
  for(i=0;i<12;i++){
    switch(cube_info[i+count]){
    case('0'):
      buf=0;
      break;
    case('1'):
      buf=1;
      break;
    }
    edge_ori[i]=buf;
  }
  count+=12;
  printf("%d\n",count);


  char *formula=malloc((len_cube-count)*sizeof(char));
  for(i=0;i<len_cube-count;i++){
    formula[i]=cube_info[i+count];
  }
  printf("%s",formula);




  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
  glutInitWindowSize(640,480);
  glutInitWindowPosition(50,50);
  glutCreateWindow("cube");

  init();
  //  rotate('U');
  //rotate('R');
  //rotate('D');
  //rotate('R');

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutIdleFunc(idle);
  glutMouseFunc(mouse);
  glutMotionFunc(motion);
  glutMainLoop();
  
  return 0;
}
