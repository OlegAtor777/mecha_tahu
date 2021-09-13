#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

int mode1 = 5;
int led = 6;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
  }
  if ((irrecv.decode(&results)) && (results.value == 0xFF30CF) ) {
    mode1 = 1;
    irrecv.resume();
  }
  if ((irrecv.decode(&results)) && (results.value == 0xFF9867) ) {
    mode1 = 2;
    analogWrite(led, 127);
    irrecv.resume();
  }
  if ((irrecv.decode(&results)) && (results.value == 0xFFB04F) ) {
    mode1 = 3;
    analogWrite(led, 255);
    irrecv.resume();
  }
  if ((irrecv.decode(&results)) && (results.value == 0xFF6897) ) {
    analogWrite(led, 0);
    irrecv.resume();
  }

  while (mode1 == 1) {
    irrecv.resume();
    for (int i = 0; i <= 254; i++) {
      analogWrite (led, i);
      delay(5);
    }
    delay(100);
    for (int i = 254; i >= 0; i--) {
      analogWrite (led, i);
      delay (5);
    }
    if ((irrecv.decode(&results)) && (results.value == 0xFF9867) ) {
      mode1 = 2;
      analogWrite(led, 127);
      irrecv.resume();
      break;
    }
    if ((irrecv.decode(&results)) && (results.value == 0xFFB04F) ) {
      mode1 = 3;
      analogWrite(led, 255);
      irrecv.resume();
      break;
    }
    if ((irrecv.decode(&results)) && (results.value == 0xFF6897) ) {
      mode1 = 0;
      analogWrite(led, 0);
      irrecv.resume();
      break;
    }
  }
  /*if (mode1 == 2){
    analogWrite(led, 127);
    }
    if (mode1 == 3){
    analogWrite(led, 254);
    }*/
}
