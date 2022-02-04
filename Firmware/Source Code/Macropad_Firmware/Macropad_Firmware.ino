#include <Keypad.h>
#include <Encoder.h>

//Start-Up LED Counter
int x = 0;

//Setting Key Row Variables
const int r1 = 1;
const int r2 = 2;
const int r3 = 3;
const int r4 = 4;
const int r5 = 5;


//Setting Key Column Variables
const int c1 = 6;
const int c2 = 7;
const int c3 = 8;


//Setting Rotary Encoder Variables
const int rot1A = 12;
const int rot1B = 11;
const int rot2A = 14;
const int rot2B = 15;
const int rot3A = 16;
const int rot3B = 17;
const int rot4A = 18;
const int rot4B = 19;
const int rot5A = 21;
const int rot5B = 20;


//Setting 3-Way Switch Variables
const int sw1 = 9; //Up
const int sw2 = 10; //Down


//Setting LED Variables
const int led1 = 22; //Up
const int led2 = 23; //Down


//Setting Encoder Classes
Encoder enc1(rot4A, rot4B); //Small 1
Encoder enc2(rot2A, rot2B); //Small 2
Encoder enc3(rot3A, rot3B); //Small 3
Encoder enc4(rot5A, rot5B); //Small 4
Encoder enc5(rot1A, rot1B); //Big Wheel

//Encoder Past
int past1 = 0;
int past2 = 0;
int past3 = 0;
int past4 = 0;
int past5 = 0;

/*
Code I copied and modified from the keypad library because I tried to code it myself but it was so 
inefficient that the serial bus was overwhelmed and I was loosing cycles. I'm so sorry I have failed you senpai
*/
const byte ROWS = 3; 
const byte COLS = 5; 
char hexaKeys[ROWS][COLS] = {
  {'D', 'F', 'H', 'J', 'M'},
  {'C', 'E', 'G', 'I', 'L'},
  {'B', 'A', 'M', 'N', 'K'}
};
byte rowPins[ROWS] = {c1, c2, c3}; 
byte colPins[COLS] = {r1, r2, r3, r4, r5}; 
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 


void setup() {
  //Starts Serial Debug Response
  Serial.begin(9600);

  //Sets LED and 3-Way pinmodes
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  //Activating 3-Way PULLUP resistors
  digitalWrite(sw1, HIGH);
  digitalWrite(sw2, HIGH);

  //LED Starup Animation
  while (x != 4){
    digitalWrite(led1, HIGH);
    delay(100);
    digitalWrite(led2, HIGH);
    delay(100);
    digitalWrite(led1, LOW);
    delay(100);
    digitalWrite(led2, LOW);
    delay(100);
    x = x + 1;
  }

  //Serial Starup Message
  Serial.println("----------------------------------");
  Serial.println("-----Macropad V1.3 Alpha 2022-----");
  Serial.println("----------By Jack Millen----------");
  Serial.println("----------------------------------");
}

void loop() {

  
  //More sample code I copied and modified from the Keypad library
  char customKey = customKeypad.getKey();
  if (customKey){
    //Prints Mode when key is pressed
    if (digitalRead(sw1) == 0) {Serial.println("Mode: ▲");}
    else if (digitalRead(sw2) == 0) {Serial.println("Mode: ▼");}
    else {Serial.println("Mode: -");}
    
    //Prints what key has been pressed
    Serial.println(customKey);

    //Key actions
    if (digitalRead(sw1) == 0) {  // Switch UP
      if (customKey == 'A'){}
      if (customKey == 'B'){}
      if (customKey == 'C'){}
      if (customKey == 'D'){Keyboard.press(KEY_F21);Keyboard.release(KEY_F21);} //Open Arduino IDE
      if (customKey == 'E'){Keyboard.press(KEY_TAB);Keyboard.release(KEY_TAB);} //Indent
      if (customKey == 'F'){Keyboard.set_modifier(MODIFIERKEY_SHIFT);Keyboard.press(KEY_TAB);Keyboard.release(KEY_TAB);Keyboard.set_modifier(0);Keyboard.send_now();} //Reverse Indent
      if (customKey == 'G'){Keyboard.set_modifier(MODIFIERKEY_CTRL);Keyboard.press(KEY_R);Keyboard.release(KEY_R);Keyboard.set_modifier(0);Keyboard.send_now();} //Verify
      if (customKey == 'H'){Keyboard.set_modifier(MODIFIERKEY_CTRL);Keyboard.press(KEY_U);Keyboard.release(KEY_U);Keyboard.set_modifier(0);Keyboard.send_now();} //Upload
      if (customKey == 'I'){Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_SHIFT);Keyboard.press(KEY_M);Keyboard.release(KEY_M);Keyboard.set_modifier(0);Keyboard.send_now();} //Monitor
      if (customKey == 'J'){Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_SHIFT);Keyboard.press(KEY_L);Keyboard.release(KEY_L);Keyboard.set_modifier(0);Keyboard.send_now();} //Plotter
      if (customKey == 'K'){Keyboard.press(KEY_F22);Keyboard.release(KEY_F22);} //Serial Print
      if (customKey == 'L'){Keyboard.press(KEY_F23);Keyboard.release(KEY_F23);} //IF
      if (customKey == 'M'){Keyboard.press(KEY_F24);Keyboard.release(KEY_F24);} //While
      }
    else if (digitalRead(sw2) == 0) { // Switch DOWN
      
      }
    else { // Switch MID
      if (customKey == 'A'){Keyboard.press(KEY_F13);Keyboard.release(KEY_F13);}
      if (customKey == 'B'){Keyboard.press(KEY_F14);Keyboard.release(KEY_F14);}
      if (customKey == 'C'){Keyboard.press(KEY_F15);Keyboard.release(KEY_F15);}
      if (customKey == 'D'){Keyboard.press(KEY_F16);Keyboard.release(KEY_F16);}
      if (customKey == 'E'){Keyboard.press(KEY_F17);Keyboard.release(KEY_F17);}
      if (customKey == 'F'){Keyboard.press(KEY_F18);Keyboard.release(KEY_F18);}
      if (customKey == 'G'){Keyboard.press(KEY_F19);Keyboard.release(KEY_F19);}
      if (customKey == 'H'){Keyboard.press(KEY_F20);Keyboard.release(KEY_F20);}
      if (customKey == 'I'){Keyboard.press(KEY_MEDIA_PLAY_PAUSE);Keyboard.release(KEY_MEDIA_PLAY_PAUSE);}
      if (customKey == 'J'){Keyboard.set_modifier(MODIFIERKEY_CTRL);Keyboard.press(KEY_W);Keyboard.release(KEY_W);Keyboard.set_modifier(0);Keyboard.send_now();}
      if (customKey == 'K'){Keyboard.press(KEY_LEFT);Keyboard.release(KEY_LEFT);}
      if (customKey == 'L'){Keyboard.press(KEY_RIGHT);Keyboard.release(KEY_RIGHT);}
      if (customKey == 'M'){Keyboard.press(KEY_F);Keyboard.release(KEY_F);}
      }
    
  }
  //Setting LED depending on 3-Way position
  if (digitalRead(sw1) == 0) {digitalWrite(led1, HIGH);}
  if (digitalRead(sw1) != 0) {digitalWrite(led1, LOW);}
  if (digitalRead(sw2) == 0) {digitalWrite(led2, HIGH);}
  if (digitalRead(sw2) != 0) {digitalWrite(led2, LOW);}

  //Rotary Encoder Positive Actions
  if (enc1.read()/2> past1){Keyboard.press(KEY_MEDIA_VOLUME_INC);Keyboard.release(KEY_MEDIA_VOLUME_INC);}
  
  if (digitalRead(sw1) == 0){                  //UP
    
  }
  else if (digitalRead(sw2) == 0){             //DOWN
    
  }
  else{                                        //MIDDLE
    if (enc5.read()/2 > past5){Mouse.scroll(-2);}
    if (enc2.read()/2 < past2){Keyboard.press(KEY_LEFT);Keyboard.release(KEY_LEFT);}
  }
  
  //Rotary Encoder Negative Actions
  if (enc1.read()/2< past1){Keyboard.press(KEY_MEDIA_VOLUME_DEC);Keyboard.release(KEY_MEDIA_VOLUME_DEC);}
  
  if (digitalRead(sw1) == 0){                  //UP
    
  }
  else if (digitalRead(sw2) == 0){             //DOWN
    
  }
  else {                                       //MIDDLE
    if (enc5.read()/2 < past5){Mouse.scroll(2);}
    if (enc2.read()/2 > past2){Keyboard.press(KEY_RIGHT);Keyboard.release(KEY_RIGHT);}
  }

  //Setting past rotary encoder values
  past1 = enc1.read()/2;
  past2 = enc2.read()/2;
  past3 = enc3.read()/2;
  past4 = enc4.read()/2;
  past5 = enc5.read()/2;

  delay(50);
}
