//Heart CKT LED Lightshow on ATTiny84

//Note these LED values will need to be
//  changed according to LED Mapping program
#define led1 10
#define led2 9
#define led3 8
#define led4 7
#define led5 6
#define led6 5
#define led7 4
#define led8 3
#define led9 2
#define led10 1

int led[] = { 
              led1, led2, led3, led4, led5,
              led6, led7, led8, led9, led10
            };

//Number of LEDs
int leds = 10;

//Delay variable
unsigned int t = 150;

void setup() {
  //Configuring all LED's to be OUTPUT
  for ( int i = 0 ; i < leds ; i++ ) {
    pinMode(led[i], OUTPUT);
    //digitalWrite(led[i], LOW);
  }
}

//Lightshow sequence
void loop() {

  //All on, forward
  for ( int i = 0 ; i < leds ; i++ ) {
    digitalWrite(led[i], HIGH);
    delay(t);
  }
  //All off, forward
  for ( int i = 0 ; i < leds ; i++ ) {
    digitalWrite(led[i], LOW);
    delay(t);
  }


  //All on, backward
  for ( int i = leds ; i >= 0 ; i-- ) {
    digitalWrite(led[i], HIGH);
    delay(t);
  }
  //All off, backward
  for ( int i = leds ; i >= 0 ; i-- ) {
    digitalWrite(led[i], LOW);
    delay(t);
  }


  //Every even on, backward
  for ( int i = leds ; i >= 0 ; i -= 2 ) {
    digitalWrite(led[i], HIGH);
    delay(t);
  }
  //Every odd on, CCW
  for ( int i = leds - 1 ; i >= 0 ; i -= 2 ) {
    digitalWrite(led[i], HIGH);
    delay(t);
  }
  //First half, off, CW
  for ( int i = 0 ; i <= 5 ; i++ ) {
    digitalWrite(led[i], LOW);
    delay(t);
  }
    //2nd half, off, CCW
  for ( int i = 6 ; i < leds ; i++ ) {
    digitalWrite(led[i], LOW);
    delay(t);
  }

  //First half, on, CCW
  for ( int i = 5 ; i >= 0 ; i-- ) {
    digitalWrite(led[i], HIGH);
    delay(t);
  }
    //2nd half, on, backward
  for ( int i = 6 ; i <= leds ; i++ ) {
    digitalWrite(led[i], HIGH);
    delay(t);
  }

  //First half, off, CW
  for ( int i = 0 ; i <= 5 ; i++ ) {
    digitalWrite(led[i], LOW);
    delay(t);
  }
    //2nd half, on, CCW
  for ( int i = leds ; i >= 6 ; i-- ) {
    digitalWrite(led[i], LOW);
    delay(t);
  }

}
