#define R1 22
#define G1 23
#define B1 24

#define R2 26
#define G2 27
#define B2 28

#define R3 30
#define G3 31
#define B3 32

#define R4 34
#define G4 35
#define B4 36

#define R5 38
#define G5 39
#define B5 40

#define R6 42
#define G6 43
#define B6 44

#define sw1 7
#define sw2 4

#define t1 1000
#define t2 3000
#define t3 5000

int state = 0;
int val = 0;
int o_val = 0;

int state2 = 0;
int val2 = 0;
int o_val2 = 0;

int n1 = random(1, 7) * 4 + 18;
int n2 ;
int n3 ;
int n4 ;


// the setup function runs once when you press reset or power the board
void setup() {
 
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(R1, OUTPUT);
  pinMode(G1, OUTPUT);
  pinMode(B1, OUTPUT);

  pinMode(R2, OUTPUT);
  pinMode(G2, OUTPUT);
  pinMode(B2, OUTPUT);

  pinMode(R3, OUTPUT);
  pinMode(G3, OUTPUT);
  pinMode(B3, OUTPUT);

  pinMode(R4, OUTPUT);
  pinMode(G4, OUTPUT);
  pinMode(B4, OUTPUT);

  pinMode(R5, OUTPUT);
  pinMode(G5, OUTPUT);
  pinMode(B5, OUTPUT);

  pinMode(R6, OUTPUT);
  pinMode(G6, OUTPUT);
  pinMode(B6, OUTPUT);
  
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);

  number();

}

void number() {
  while(1) {
    n1 = random(1, 7) * 4 + 18;
    n2 = random(1, 7) * 4 + 18;
    n3 = random(1, 7) * 4 + 18;
    n4 = random(1, 7) * 4 + 18;
    if ( n1!=n2 && n1!=n3 && n1!=n4 && n2!=n3 && n2!=n4 && n3!=n4 ) {
      break;
     }
  }
}

// the loop function runs over and over again forever
void loop() {

 val2 = digitalRead(sw2);

  if ((val2==LOW) && (o_val2==HIGH)) {
    state2++;
    if (state2 == 4) {
      state2=0;
    }
    delay(10);
  }
  
  o_val2 = val2;
  
  if (state2 == 1) {
    setRed(R1);
    delay(500);
    Off(R1, G1, B6);
    setRed(R2);
    delay(500);
    Off(R2, G2, B6);
    setRed(R3);
    delay(500);
    Off(R3, G3, B6);
    setRed(R4);
    delay(500);
    Off(R4, G4, B6);
    setRed(R5);
    delay(500);
    Off(R5, G5, B6);
    setRed(R6);
    delay(500);
    Off(R6, G6, B6);
  }

  else if (state2 == 2) {
    setGreen(R1);
    delay(500);
    Off(R1, G1, B1);
    setGreen(R2);
    delay(500);
    Off(R2, G2, B2);
    setGreen(R3);
    delay(500);
    Off(R3, G3, B3);
    setGreen(R4);
    delay(500);
    Off(R4, G4, B4);
    setGreen(R5);
    delay(500);
    Off(R5, G5, B5);
    setGreen(R6);
    delay(500);
    Off(R6, G6, B6);
  }

  else if( state2 == 3) {
    setBlue(R1);
    delay(500);
    Off(R1, G1, B1);
    setBlue(R2);
    delay(500);
    Off(R2, G2, B2);
    setBlue(R3);
    delay(500);
    Off(R3, G3, B3);
    setBlue(R4);
    delay(500);
    Off(R4, G4, B4);
    setBlue(R5);
    delay(500);
    Off(R5, G5, B5);
    setBlue(R6);
    delay(500);
    Off(R6, G6, B6);
  }

  else {
    Off(R1, G1, B1);
    Off(R2, G2, B2);
    Off(R3, G3, B3);
    Off(R4, G4, B4);
    Off(R5, G5, B5);
    Off(R6, G6, B6);
    

  val = digitalRead(sw1);

  if ((val==LOW) && (o_val==HIGH)) {
    state++;
    if (state == 4) {
      state=0;
    }
    delay(10);
  }
  
  o_val = val;

  if(state == 1) {
   setRed(n1);
   setRed(n2);
   delay(1000);
   setGreen(n1);
   setGreen(n2);
   delay(1000);
   setBlue(n1);
   setBlue(n2);
   delay(1000);

  }

  else if(state == 2) {
    setRed(n1);
    setRed(n2);
    setRed(n3);
    setRed(n4);
    delay(1000);
    setGreen(n1);
    setGreen(n2);
    setGreen(n3);
    setGreen(n4);
    delay(1000);
    setBlue(n1);
    setBlue(n2);
    setBlue(n3);
    setBlue(n4);
    delay(1000);

  }

  else if(state == 3) {
    setRed(R1);
    setRed(R2);
    setRed(R3);
    setRed(R4);
    setRed(R5);
    setRed(R6);
    delay(1000);
    setGreen(R1);
    setGreen(R2);
    setGreen(R3);
    setGreen(R4);
    setGreen(R5);
    setGreen(R6);
    delay(1000);
    setBlue(R1);
    setBlue(R2);
    setBlue(R3);
    setBlue(R4);
    setBlue(R5);
    setBlue(R6);
    delay(1000);

  }

  else {
    Off(R1, G1, B1);
    delay(800);
    Off(R2, G2, B2);
    delay(800);
    Off(R3, G3, B3);
    delay(800);
    Off(R4, G4, B4);
    delay(800);
    Off(R5, G5, B5);
    delay(800);
    Off(R6, G6, B6);
  }


  }
  

}


void Off(int R, int G, int B) {
  digitalWrite(R,LOW);
  digitalWrite(G,LOW);
  digitalWrite(B,LOW);
}

void setRed(int R)
{
  int G = R+1;
  int B = R+2;
  digitalWrite(R,HIGH);  
  digitalWrite(G,LOW);
  digitalWrite(B,LOW);
}
void setGreen(int R)
{int G = R+1;
  int B = R+2;
  digitalWrite(R,LOW);
  digitalWrite(G,HIGH);    
  digitalWrite(B,LOW);
}
void setBlue(int R)
{
  int G = R+1;
  int B = R+2;
  digitalWrite(R,LOW);
  digitalWrite(G,LOW);
  digitalWrite(B,HIGH);
}
