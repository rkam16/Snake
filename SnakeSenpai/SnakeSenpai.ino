#include <MeggyJrSimple.h> // Required code

void setup()               // required code 
{
  MeggyJrSimpleSetup();  
  Serial.begin(9600); 
}

int direction = 0;        // possible values are 0,90,180,270
int xapple = random(8);
int yapple = random (8);
int marker = 1;
boolean alive = false;




struct Point
{
  int x;
  int y;
};

Point p1 = {3,4};
Point p2 = {4,4};
Point p3 = {5,4};
Point p4 = {6,4};
Point snakeArray[64] = {p1,p2,p3,p4};

/*
Draw Player - Call drawSnake()
Display Slate
Check buttons
Update direction if buttons are pressed
Update player based on direction
Correct for wrapping
 
*/
void getApple(void){
  Tone_Start(ToneC5, 50);
}

void drawSnake()
{
  DrawPx(snakeArray[0].x, snakeArray[0].y,Red);
  
  for(int i=1; i<marker; i++)
  {
    DrawPx(snakeArray[i].x,snakeArray[i].y,Red);
  }
}

void updateSnake()
{  
  for (int i = marker-1; i > 0; i--)           
  {
    snakeArray[i].x =  snakeArray[i-1].x;
    snakeArray[i].y =  snakeArray[i-1].y;
  }
}


void loop()
{
  drawSnake();
  DrawPx(xapple,yapple,Green);
  DisplaySlate();
  delay(125);
  ClearSlate();
  updateSnake();
  
  
  CheckButtonsPress();
 
  
  
  if (Button_Right)
  {
    direction = 90;
  }
  
  if (Button_Left)
  {
    direction = 270;
  }
  
  if (Button_Up)
  {
   direction = 0; 
  }
  
  if (Button_Down)
  {
    direction = 180;
  }
  if(direction==0)
    {
      snakeArray[0].y++;
    }
  if(direction==90)
    {
      snakeArray[0].x++;
    }
  if(direction==180)
    {
      snakeArray[0].y--;
    }
  if(direction==270)
    {
      snakeArray[0].x--;
    }
  if(snakeArray[0].x>7)
    {
      snakeArray[0].x=0;
    }
  if(snakeArray[0].y>7)
    {
      snakeArray[0].y=0;
    }
  if(snakeArray[0].x<0)
    {
      snakeArray[0].x=7;
    }
  if(snakeArray[0].y<0)
    {
      snakeArray[0].y=7;
    }
  
    
    if(xapple == snakeArray[0].x)
    {
      if(yapple == snakeArray[0].y)
      {
        xapple = random(8);
        yapple = random(8);
        marker++;
        getApple();
      }
    }
    
      for(int i=1; i<marker; i++)
      {
        if(snakeArray[0].x == snakeArray[i].x && snakeArray[0].y == snakeArray[i].y)
        {
          alive = true;
        }
      } 
      
    if(alive)
    {
      ClearSlate();                 

      
      Tone_Start(ToneF3, 1000);
      DisplaySlate();
      delay (1000);
      marker = 1;
      alive = false;
      
      
    }
}
