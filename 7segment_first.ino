/*
Code initially from allaboutcircuits
What this does:
This is making a 7 segment display count from 9 to 0 
with a 1 second delay in between each change,

Code is more complex than the first commit's code for 
just interfacing with the 7 segment display module and 
turning on/off all its segments one by one.

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

// make an array to save Sev Seg pin configuration of numbers

int num_array[10][7] = {  { 1,1,1,1,1,1,0 },    // 0
                          { 0,1,1,0,0,0,0 },    // 1
                          { 1,1,0,1,1,0,1 },    // 2
                          { 1,1,1,1,0,0,1 },    // 3
                          { 0,1,1,0,0,1,1 },    // 4
                          { 1,0,1,1,0,1,1 },    // 5
                          { 1,0,1,1,1,1,1 },    // 6
                          { 1,1,1,0,0,0,0 },    // 7
                          { 1,1,1,1,1,1,1 },    // 8
                          { 1,1,1,1,0,1,1 }};   // 9
//function header
void Num_Write(int);

void setup() 
{ 
  // set pin modes
  pinMode(2, OUTPUT);   
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() 
{
  // This function sends the actual number that has to be displayed to the End User,
  // to the Num_write function.
  for (int counter = 10; counter > 0; counter--) 
  {
    delay(1000);
    Num_Write(counter-1); 
  }
  delay(3000);
}

// This function receives the number to be displayed 
// It fetches the value for each segment (from the num array),
// for the number to be displayed.
// And sends the value to the corresponding pin of the 7 seg display.
void Num_Write(int number) 
{
  int pin= 2;
  for (int j=0; j < 7; j++) 
  {
    digitalWrite(pin, num_array[number][j]);
    pin++;
  }
}