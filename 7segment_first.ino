/*
Code initially from allaboutcircuits
I just added some comments. 
Code is very easy to understand.

Pinout: Common Cathode 7 segment display 

10g 9f 8GND 7a 6b

1e  2d 3GND 4c 5dp

Wiring: 7 segment display module with Arduino Uno
| 7 segment | Arduino Uno |
|---|---|
|1e|D6|
|2d|D5|
|3,8|GND|
|4c|D4|
|5dp|-|
|6b|D3|
|7a|D2|
|9f|D7|
|10g|D8|
*/ 

void setup()
{ 
  // defining pins and their respective modes
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
}

void loop() 
{
  // loop to turn the LED segments ON. ONE by ONE.
  for(int i=2;i<9;i++)
  {
    digitalWrite(i,HIGH);
    delay(600);
  }

  // loop to turn the LED segments OFF. ONE by ONE.
  for(int i=2;i<9;i++)
  {
    digitalWrite(i,LOW);
    delay(600);
  }
  delay(1000);
}
