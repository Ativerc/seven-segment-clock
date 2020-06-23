/*
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

void double_display(int);

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
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);  
}

void loop() {
    for (int num = 30; num >= 0; num--){
        double_display(num);
    }
}

void double_display(int number) {
    int first_dig = 0;
    int second_dig = 0;
    if (number > 9){
        first_dig = number / 10;
        second_dig = number % 10;
    }
    else if (1 < number < 9)
    {
        first_dig = 0;
        second_dig = number % 10;
    }
    else if (number == 0){
        first_dig = 0;
        second_dig = 0;
    }
    int pin = 2;
    for (int j=0; j<7; j++){
        digitalWrite(10, LOW);
        digitalWrite(pin, num_array[first_dig][j]);
        pin++;
    }
    delay(500);
    digitalWrite(10, HIGH);
    pin = 2;
    for (int j=0; j<7; j++){
        digitalWrite(9, LOW);
        digitalWrite(pin, num_array[second_dig][j]);
        pin++;
    }
    delay(500);
    digitalWrite(9,HIGH);

}

