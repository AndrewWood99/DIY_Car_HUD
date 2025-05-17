#include <LiquidCrystal.h>
#include <SharpIR.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // initialize the interface pins
SharpIR sharp(A1, 25, 93, 1080);
//Initialize Sharp Distance Sensor
boolean dooropen = false;
int ForceSensorPin = A0; //analog pins
//DistnaceSensorPn = A1 //pin slected in Sharp initialization
int PhotoHub1 = A2;
int PhotoHub2 = A3;
int PhotoHub3 = A4;
int ForceSensorReading; //varibales for distance sensor
int distance;
int spot = 1; //variables for speedometer funtion
int hub1;
int hub2;
int hub3;
int speedometer = 0;
int tens; //variables for numtofat function
int ones;
/////////////////////////////////////////////////////////////////////////////////////
/////////////
//////////////////////////////////////////CUSTOM CHARACTER
BANK///////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////
//setup from http://forum.arduino.cc/index.php?topic=8882.0
//User digimike
byte LT[8] = //Start Fat Numbers custom characters
{
  B00111,
  B01111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte UB[8] =
{
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
byte RT[8] =
{
  B11100,
  B11110,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte LL[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B01111,
  B00111
};
byte LB[8] =
{
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111
};
byte LR[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11110,
  B11100
};
byte MB[8] =
{
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111
};
byte block[8] =
{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte P[8] =
{
  B01111,
  B10001,
  B10001,
  B01111,
  B00001,
  B00001,
  B00001,
  B00001
  //End Fat Numbers custom characters
  //Start backwards letter custom characters
};
byte E[8] =
{
  B11111,
  B00001,
  B00001,
  B00001,
  B01111,
  B00001,
  B00001,
  B11111
};
byte N[8] =
{
  B10001,
  B10001,
  B10011,
  B10101,
  B11001,
  B10001,
  B10001,
  B10001
};
byte D[8] =
{
  B00111,
  B01001,
  B10001,
  B10001,
  B10001,
  B10001,
  B01001,
  B00111
};
byte R[8] =
{
  B01111,
  B10001,
  B10001,
  B10001,
  B01111,
  B00101,
  B01001,
  B10001
};
byte O[8] =
{
  B01110,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B01110
};
//End backwards letters custom characters
/////////////////////////////////////////////////////////////////////////////////////
/////////////
//////////////////////////////FAT NUMBERS BUILDS AND DOOR OPEN
BUILD//////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////
//setup from http://forum.arduino.cc/index.php?topic=8882.0
//User digimike
void custom0(int topleft)
{ // uses segments to build the number 0
  lcd.setCursor(topleft, 0); // set cursor to column 0, line 0 (first row)       -symetrical
  lcd.write((byte)0);  // call each segment to create
  lcd.write(1);  // top half of the number
  lcd.write(2);
  lcd.setCursor(topleft, 1); // set cursor to colum 0, line 1 (second row)
  lcd.write(3);  // call each segment to create
  lcd.write(4);  // bottom half of the number
  lcd.write(5);
}
void custom1(int topleft)
{
  lcd.setCursor(1 + topleft, 0); //reversed
  lcd.write((byte)0);
  lcd.write(1);
  lcd.setCursor(topleft, 1);
  lcd.write(4);
  lcd.write(7);
  lcd.write(4);
}
void custom2(int topleft)
{
  lcd.setCursor(topleft, 0);
  lcd.write((byte)0);
  lcd.write(6);
  lcd.write(6);
  lcd.setCursor(topleft, 1); //reversed
  lcd.write(4);
  lcd.write(4);
  lcd.write(5);
}
void custom3(int topleft)
{
  lcd.setCursor(topleft, 0); //reversed
  lcd.write((byte)0);
  lcd.write(6);
  lcd.write(6);
  lcd.setCursor(topleft, 1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(4);
}
void custom4(int topleft)
{
  lcd.setCursor(topleft, 0); //reversed
  lcd.write(7);
  lcd.write(4);
  lcd.write(5);
  lcd.setCursor(topleft, 1);
  lcd.write(7);
}
void custom5(int topleft)
{
  lcd.setCursor(topleft, 0); //reversed
  lcd.write(6);
  lcd.write(6);
  lcd.write(5);
  lcd.setCursor(topleft, 1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(4);
}
void custom6(int topleft)
{
  lcd.setCursor(topleft, 0); //reversed
  lcd.write(6);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(topleft, 1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
}
void custom7(int topleft)
{
  lcd.setCursor(topleft, 0); //reversed
  lcd.write((byte)0);
  lcd.write(1);
  lcd.write(1);
  lcd.setCursor(topleft, 1);
  lcd.write(7);
}
void custom8(int topleft)
{
  lcd.setCursor(topleft, 0); //symetrical
  lcd.write((byte)0);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(topleft, 1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
}
void custom9(int topleft)
{
  lcd.setCursor(topleft, 0); //reversed
  lcd.write((byte)0);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(topleft, 1);
  lcd.write(7);
}
void customDOOR() //Build for mirrored text for door status
{
  lcd.setCursor(2, 0);
  lcd.write(4);
  lcd.write(5);
  lcd.write(5);
  lcd.write(3);
  lcd.setCursor(2, 1);
  lcd.write(2);
  lcd.write(1);
  lcd.write((byte)0);
  lcd.write(5);
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////
////////////////////////////////////////////MAIN
CODE/////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////
void setup()
{
  Serial.begin(9600);
  lcd.clear(); //clear LCD to start program
  lcd.begin(16, 2);  // sets the LCD's rows and colums:
  pinMode (A1, INPUT); //set distance senor pin to recieve distance reading
  ForceSensorReading = analogRead(ForceSensorPin);  //read the door sensor first
  if (ForceSensorReading > 400)
    soon as the program starts
  {
    dooropen = false;
  }
  else
  {
    dooropen = true;
  }
}
void loop()
{
  //Assign custom characters to FAT NUMBERS
  lcd.createChar(0, LT);
  //determine if door is open as
  lcd.createChar(1, UB);
  lcd.createChar(2, RT);
  lcd.createChar(3, LL);
  lcd.createChar(4, LB);
  lcd.createChar(5, LR);
  lcd.createChar(6, MB);
  lcd.createChar(7, block);
  while (dooropen == false)
  {
    Serial.print(analogRead(A2));
    Serial.print("   ");
    //delay(10);
    Serial.print(analogRead(A3));
    Serial.print("   ");
    //delay(10);
    Serial.print(analogRead(A4));
    Serial.print("   ");
    //delay(10);
    Speedometer();
    Serial.println(spot);
    lcd.clear();
    if (speedometer < 10)
    {
      distance = sharp.distance();              //read distance sensor
      distance = 0.629 * distance + 7.208;      //convert raw distnace value to cm
      numtofat(distance - 11);                  //display distance on LCD with 11 cm
      buffer
      lcd.setCursor(7, 1);                      //add M for meters and decimal point
      lcd.write(".");
      lcd.setCursor(0, 1);
      lcd.write("M");
      delay(100);
      //delay and clear for smooth number changing
    }
    else
    {
      numtofat(speedometer);
      delay(100);
    }
    ForceSensorReading = analogRead(ForceSensorPin); //read door
    if (ForceSensorReading < 500) //determine if door is open
    {
      delay(50); //delay to prevent button bouncing
      dooropen = true;
    }
  }
  lcd.clear(); //clear lcd from speed and distance to prepare for door status message
  //Assign custom characters to backwards door open message
  lcd.createChar(0, P);
  lcd.createChar(1, E);
  lcd.createChar(2, N);
  lcd.createChar(3, D);
  lcd.createChar(4, R);
  lcd.createChar(5, O);
  customDOOR();         //Message DOOR is OPEN
  while (dooropen == true)
  {
    ForceSensorReading = analogRead(ForceSensorPin); //read door
    if (ForceSensorReading > 500) //check if door is closed
    {
      delay(200); //delay to prevent button bouncing
      dooropen = false;
    }
  }
  lcd.clear(); //clear lcd from door status message to prepare for speed and distance
  spot = 1;
}
/////////////////////////////////////////////////////////////////////////////////////
/////////////
////////////////////////////////////////////FUNCTIONS////////////////////////////////
/////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////
void clearnumber()
{ // clears the area the custom number is displayed in
  lcd.setCursor(0, 0);
  lcd.print("   ");
  lcd.setCursor(0, 1);
  lcd.print("   ");
}
void numtofat(int number) //number is number to make into fat text
{
  tens = number / 10;             //assign tens digit
  ones = number - (tens * 10);    //assign ones digit
  if (tens == 0)
  {
    custom0(4);
  }
  else if (tens == 1)
  {
    custom1(4);
  }
  else if (tens == 2)
  {
    custom2(4);
  }
  else if (tens == 3)
  {
    custom3(4);
  }
  else if (tens == 4)
  {
    custom4(4);
  }
  else if (tens == 5)
  {
    custom5(4);
  }
  else if (tens == 6)
  {
    custom6(4);
  }
  else if (tens == 7)
  {
    custom7(4);
  }
  else if (tens == 8)
  {
    custom8(4);
  }
  else if (tens == 9)
  {
    custom9(4);
  }
  if (ones == 0)
  {
    custom0(1);
  }
  else if (ones == 1)
  {
    custom1(1);
  }
  else if (ones == 2)
  {
    custom2(1);
  }
  else if (ones == 3)
  {
    custom3(1);
  }
  else if (ones == 4)
  {
    custom4(1);
  }
  else if (ones == 5)
  {
    custom5(1);
  }
  else if (ones == 6)
  {
    custom6(1);
  }
  else if (ones == 7)
  {
    custom7(1);
  }
  else if (ones == 8)
  {
    custom8(1);
  }
  else if (ones == 9)
  {
    custom9(1);
  }
}
void Speedometer()
{
  hub1 = analogRead(PhotoHub1);
  hub2 = analogRead(PhotoHub2);
  hub3 = analogRead(PhotoHub3);
  if (spot % 3 == 1)
  {
    if (hub2 < 875)
    {
      spot++;
      delay(100);
    }
    if (hub3 < 880)
    {
      spot--;
      delay(100);
    }
  }
  if (spot % 3 == 2)
  {
    if (hub3 < 880)
    {
      spot++;
      delay(100);
    }
    if (hub1 < 900)
    {
      spot--;
      delay(100);
    }
  }
  if (spot % 3 == 0)
  {
    if (hub1 < 900)
    {
    }
    spot++;
    delay(100);
    if (hub2 < 875)
    {
      spot--;
      delay(100);
    }
  }
  speedometer = 2 + (spot * 3);
}
