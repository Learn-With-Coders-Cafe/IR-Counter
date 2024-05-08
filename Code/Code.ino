//=======================================================================
// www.youtube.com/c/TeachMeSomething  // Visit for more project Videos

//=======================================================================
#include <TM1637Display.h>
#define CLK 10
#define DIO 11

#define delaytime   10
int sensor =4;
int count=0;

TM1637Display display(CLK, DIO);

void setup()
{
 Serial.begin(115200);
 display.setBrightness(0x0f);  // Set full brightness
 display.clear();
}

void loop()
{
display.showNumberDec(count,true);
 if (digitalRead(sensor)==LOW)
  {
     count++;
     display.showNumberDec(count,true);
     Serial.println("Count Value:" + String(count));
     while (digitalRead(sensor)==LOW)  {}
  }
 
}
