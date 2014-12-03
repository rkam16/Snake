#include <MeggyJrSimple.h>
int xplayer=3; //Cordinates of player dot
int yplayer=4;
int direction=0; //Posible values are 0,90,180,270
int xapple=random(8);
int yapple=random(8);
int marker=3;

void setup() {  // run once, when the sketch starts
  MeggyJrSimpleSetup();
  Serial.begin(9600);
}
 
/* Draw PLayer
   Display Slate
   Check Buttons
   Update Direction if a button is pressed
   Update Player based on direction
   Correct for Wrap
*/ 

void loop () 
{
  Serial.print("x is");
  Serial.print(xplayer);
  Serial.print("y is");
  Serial.print(yplayer);
  Serial.println();
  

 DrawPx(xplayer,yplayer,Red);
 DrawPx(xapple,yapple,Green);
 DisplaySlate();
 delay(100);
 ClearSlate();
 CheckButtonsDown();
 if (Button_Right) direction=90;
 if (Button_Left) direction=270;
 if (Button_Down) direction=180;
 if (Button_Up) direction=0;
 if (direction==0) yplayer++; 
 if (direction==90) xplayer++;
 if (direction==180) yplayer--;
 if (direction==270) xplayer--;
 if(xplayer>7) xplayer=0;
 if(yplayer>7) yplayer=0;
 if(xplayer<0) xplayer=7;
 if(yplayer<0) yplayer=7;
 {if (xapple==xplayer){
   if(yapple==yplayer){
     xapple=random(8);
     yapple=random(8);
   }
  } 
 }
 
 struct Point {
   int x;
   int y;
 };
 Point p1={3,4};
 Point p2={4,4};
 Point p3={5,4};
 Point snakeArray[64] = {p1,p2,p3};
 
}

void loop();

void drawSnake()
{
  for (int i=0; i<marker; i++)
  {
    DrawPx(snakeArray[i].x,snakeArray[i].y,Red);
  }
}
 
