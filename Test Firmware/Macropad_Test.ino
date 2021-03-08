/*
Macropad Test Firmware v0.8
*/
//Setting Row Pin Variables
const int r1 = 1;
const int r2 = 2;
const int r3 = 3;
const int r4 = 4;
const int r5 = 5;

//Setting Row Pin Variables
const int c1 = 6;
const int c2 = 7;
const int c3 = 8;

int A = 0;
int B = 0;
int C = 0;
int D = 0;
int E = 0;
int F = 0;
int G = 0;
int H = 0;
int I = 0;
int J = 0;
int K = 0;
int L = 0;
int M = 0;

void setup() {
  //Setting Serial Baud to 9600
  Serial.begin(9600);

  //Set pin modes
  pinMode(c1, INPUT);
  pinMode(c2, INPUT);
  pinMode(c3, INPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);
  pinMode(r5, OUTPUT);

  //Activating INPUT pull-up resistors by setting to HIGH. Setting OUTPUT to HIGH
  digitalWrite(c1, HIGH);
  digitalWrite(c2, HIGH);
  digitalWrite(c3, HIGH);
  digitalWrite(r1, HIGH);
  digitalWrite(r2, HIGH);
  digitalWrite(r3, HIGH);
  digitalWrite(r4, HIGH);
  digitalWrite(r5, HIGH);
}

void loop(){
  //Polling Row 1 for active switches
  digitalWrite(r1, LOW);
  if (digitalRead(c1) == 0) {A = 1;}
  if (digitalRead(c2) == 0) {B = 1;}
  if (digitalRead(c3) == 0) {C = 1;}
  digitalWrite(r1, HIGH);

  //Polling Row 2 for active switches
  digitalWrite(r2, LOW);
  if (digitalRead(c1) == 0) {D = 1;}
  if (digitalRead(c2) == 0) {E = 1;}
  if (digitalRead(c3) == 0) {F = 1;}
  digitalWrite(r2, HIGH);

  //Polling Row 3 for active switches
  digitalWrite(r3, LOW);
  if (digitalRead(c1) == 0) {G = 1;}
  if (digitalRead(c2) == 0) {H = 1;}
  digitalWrite(r3, HIGH);

   digitalWrite(r4, LOW);
  if (digitalRead(c1) == 0) {I = 1;}
  if (digitalRead(c2) == 0) {J = 1;}
  digitalWrite(r4, HIGH);

  digitalWrite(r5, LOW);
  if (digitalRead(c1) == 0) {K = 1;}
  if (digitalRead(c2) == 0) {L = 1;}
  if (digitalRead(c3) == 0) {M = 1;}
  digitalWrite(r5, HIGH);


  //Debug
  Serial.print(A);
  Serial.print(B);
  Serial.print(C);
  Serial.print(D);
  Serial.print(E);
  Serial.print(F);
  Serial.print(G);
  Serial.print(H);
  Serial.print(I);
  Serial.print(J);
  Serial.print(K);
  Serial.print(L);
  Serial.print(M);
  Serial.println();
  delay(100);

  int A = 0;
  int B = 0;
  int C = 0;
  int D = 0;
  int E = 0;
  int F = 0;
  int G = 0;
  int H = 0;
  int I = 0;
  int J = 0;
  int K = 0;
  int L = 0;
  int M = 0;
}
