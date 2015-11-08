#include <stdio.h>
#include <ctype.h>
#include "cv.h"
#include "highgui.h"
#define WINDOW_STEP 3

int bytes_per_pixel(const IplImage* image);
void process(IplImage *source);
//void keyboard(unsigned char key,int x,int y);
int main(int argc, char** argv) {
  CvCapture* capture = 0;
  IplImage* image = 0;
  IplImage* result = 0;
  const char* windowName = "mirror 1";

  int win_step;
  int template_width, template_height;
  CvPoint2D32f previous_point;
  int p1x, p1y, p2x, p2y;
  CvFont font;
  int i, j;
  char buffer[256];





  cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX, 1.0, 1.0, 0.0, 1, 0);
  template_width = 32;
  template_height = 32;
  win_step = WINDOW_STEP;

  
  if (argc == 1 || (argc == 2 && strlen(argv[1]) == 1 && isdigit(argv[1][0]))) {
    capture = cvCreateCameraCapture(argc == 2 ? argv[1][0] - '0' : 0);
  } else if (argc == 2) 
    capture = cvCreateFileCapture(argv[1]);
  

  if (!capture) {
    fprintf(stderr, "ERROR: capture is NULL \n");
    return -1;
  }
  cvNamedWindow(windowName, CV_WINDOW_AUTOSIZE);
  image = cvQueryFrame(capture);
  
  if (!image) {
    fprintf(stderr, "Could not query frame...\n");
    return -1;
  }
  
  //  result = cvCloneImage(image);
  while (1) {
    image = cvQueryFrame(capture);
    if (!image) {
      fprintf(stderr, "Could not query frame...\n");
      break;
    }
    
    // process(image, result);




   for (j = 0; j < 3; j++) {
      for (i = 0; i < 3; i++) {
        previous_point.x = template_width / 2 + 8 * win_step
            + i * (8 * 2 * 3 + 32) + 180;
        previous_point.y = template_height / 2 + 8 * win_step
            + j * (8 * 2 * 3 + 32) + 130;
        p1x = (int) previous_point.x - template_width / 2 - 8 * win_step;
        p1y = (int) previous_point.y - template_height / 2 - 8 * win_step;
        p2x = (int) previous_point.x + template_width / 2 - 1 + 8 * win_step;
        p2y = (int) previous_point.y + template_height / 2 - 1 + 8 * win_step;
	cvRectangle(image, cvPoint(p1x, p1y), cvPoint(p2x, p2y),
		    CV_RGB(0, 0, 255), 1, // thickness, -1=filled
		    8, // line_type, 8=8-connected
		    0);
	//	printf("(%d,%d),(%d,%d)¥n",p1x,p1y,p2x,p2y);
      }
   }
   sprintf(buffer,"%s","RBRBRB");

    cvPutText(image, buffer, cvPoint(20,30), &font, CV_RGB(0,0,0));




    cvShowImage(windowName, image);

    if (cvWaitKey(10) == 27) {
      break;
      
    }
    else if (cvWaitKey(10) == 'c'){
      result = cvQueryFrame(capture);      
      process(result);
      printf("captured2\n");
      cvNamedWindow("capture", CV_WINDOW_AUTOSIZE);
      cvShowImage("capture",result);
    }
  }
  cvReleaseImage(&result);
  cvReleaseCapture(&capture);
  cvDestroyWindow("capture");

  cvReleaseImage(&image);
  cvReleaseCapture(&capture);
  cvDestroyWindow(windowName);

  return 0;
}

int bytes_per_pixel(const IplImage* image) {
  return (((image->depth & 255) / 8) * (image->nChannels));
}

void process(IplImage *source) {
  uchar *pS, *pD;
  uchar *dataS, *dataD;
  int bpp;
  int step;
  CvSize size;
  int x, y;
  int R,G,B;
  int color_buf[3]={0,0,0};
  int size_of_win=6400;
  int ave_R,ave_G,ave_B;
  char cube[9];
  int i,j;
  bpp = bytes_per_pixel(source);




  
  cvGetRawData(source, &dataS, &step, &size);

  /*
  for (y = 0; y < size.height; y++) {
    pS = dataS + step * y;
    pD = dataD + step * y + bpp * size.width;
    for (x = 0; x < size.width; x++) {
      
      *pD = *pS;//R
      *(pD + 1) = *(pS + 1);//G
      *(pD + 2) = *(pS + 2);//B
      pS += bpp;
      pD -= bpp;
      

    }
  }
  */
 
  int cor_win_x[9]={180,260,340,180,260,340,180,260,340};
  int cor_win_y[9]={130,130,130,210,210,210,290,290,290};
  int Width=80;
  R=0;G=0;B=0; 

  for (i=0;i<9;i++){
    pS=dataS+ step*cor_win_y[i]+bpp*cor_win_x[i];

    int counter=0;  
    for (y=0;y<Width;y++){
      
      for(x=0;x<Width;x++){
	////////////write down process here;
	if(*pS>70||*(pS+1)>70||*(pS+2)>70){

	    R+=*pS;
	    G+=*(pS+1);
	    B+=*(pS+2);
	    counter++;

	}

	
	pS+=bpp;
      }
      pS+=step-bpp*Width;
    }
    R=R/counter;
    G=G/counter;
    B=B/counter;
  
    printf("%d,%d,%d¥n",R,G,B);
    R=0;G=0;B=0;
   }
  
}
/* for (y = 0; y < size.height; y++) {
    pD = dataD + step * y;
    for (x = 0; x < size.width; x++) {
      if(x>290&&x<310&&y>240&&y<260)
	{
      R+=*pD;
      G+=*(pD+1);
      B+=*(pD+2);
	}

      pD+=bpp;
      //      printf("%d,%d,%d¥n",R,G,B);
    }
  }
  
  R=R/(310-290)/(310-290);
  G=G/(310-290)/(310-290);
  B=B/(310-290)/(310-290);
  
  printf("%d,%d,%d¥n",R,G,B);
  
  }*/ /*        if(x>180&&x<420&&y>130&&y<370){
	  R=*pD;
	  G=*(pD+1);
	  B=*(pD+2);
	  
	}
	pD +=bpp;
	
	
	if(R>127||G>127||B>127){
	  color_buf[0]+=R;
	  color_buf[1]+=G;
	  color_buf[2]+=B;
	}
    }
  }
  ave_R=(int)color_buf[0]/size_of_win/9;
  ave_G=(int)color_buf[1]/size_of_win/9;
  ave_B=(int)color_buf[2]/size_of_win/9;
  printf("%d,%d,%d¥n",ave_R,ave_G,ave_B);
  color_buf[0]=0;
  color_buf[1]=0;
  color_buf[2]=0;
      */
    


//}


    
  //  printf("%d,%d,%d\n",ave_R,ave_G,ave_B);
  //  printf("%d,%d¥n",size.height,size.width);
  /* 
  for(i=0;i<9;i++){
    for (y=cor_win_y[i];y<cor_win_y[i]+Width;y++){
      for (y=cor_win_x[i];x<cor_win_x[i]+Width;x++){
      pD=dataD+step*y+bpp*x;
      }
    }
  }
  */
    /*
  R=*pD;
  G=*(pD+1);
  B=*(pD+2);
  
  if(R<127&&G<127&&B<127){}
  else{
    color_buf[0]+=R;
    color_buf[1]+=G;
    color_buf[2]+=B;
  }
  ave_R=(int)color_buf[0]/size_of_win;
  ave_G=(int)color_buf[1]/size_of_win;
  ave_B=(int)color_buf[2]/size_of_win;
  
  if(R>127&&G>127&&B>127) cube[i]='W';
  else if(R>=170&&G>=127&&B<127) cube[i]='Y';
  else if(R>=127&&G<127&&B<127) cube[i]='R';
  else if(R<170&&R>=80&&G>=127&&B<127) cube[i]='O';
  else if(R<127&&G<127&&B>=127) cube[i]='B';
  else if(R<80&&G>=127&&B<127) cube[i]='G';
    */


