#include <CustomStepper.h>
#include <AccelStepper.h>// Подключаем библиотеку управления шаговым двигателем. По умолчанию настроена на двигатель 28BYJ-48-5V
//CustomStepper stepper(8, 9, 10, 11);  // Указываем пины, к которым подключен драйвер шагового двигателя
#define HALFSTEP 8
AccelStepper stepper1(HALFSTEP, 8, 10, 9, 11);
int val;
int mot;
int i;
int led;
int IN;
int ROT;
void setup()
{
  stepper1.setMaxSpeed(2000.0);
  stepper1.setAcceleration(200.0);
  stepper1.setSpeed(2000);
  Serial.begin(9600);
  led = 6;
  pinMode(led, OUTPUT); // 13 пин – светодиод, объявляется как выход
  stepper1.setCurrentPosition(0);
  stepper1. moveTo(0);
  //stepper.setRPM(35);                 // Устанавливаем кол-во оборотов в минуту
  //stepper.setSPR(2048);       // Устанавливаем кол-во шагов на полный оборот. Максимальное значение 4075.7728395
}
void loop()
{

  // if (Serial.available()) // проверка поданных команд
  // {
  IN = Serial.read();
  if (IN == '1') {
    val = 1;
  }
  if (IN == '0') {
    val = 0;
  }
  if (IN == '3') {
    val = 3;
  }
  if (IN == '4') {
    val = 4;
  }
  if (IN == 'A') {
    val = 5;
  }



  if (val == 1) {
    i = 255;
    analogWrite(led, i); // при 1 включается светодиод
  }
  if (val == 0) {
    i = 0;
    analogWrite(led, 0); // при 0 выключается светодиод
  }
  if (val == 3) {
    val = -1;
    if (i < 255) {
      i += 15;
      analogWrite(led, i);
    }
  }
  if (val == 4) {
    val = -1;
    if (i > 0) {
      i -= 15;
      if (i < 0) {
        i = 0;
      }
      analogWrite(led, i);
    }
  }






  // }
  while (val == 5) {
   
    IN = Serial.read();
    
    

      if (IN == 'V') {
    mot = 1;
  }
  if (mot == 1) {
  
    stepper1.moveTo(-7500);
  
  }

  if (IN == 'E') {
    mot = 3;
  }
  if (mot == 3) {
  
    stepper1.moveTo(7500);
    }

  if (IN == 'M') {
    mot = 4;
  }
  if (mot == 4) {
  
    stepper1.moveTo(-2000);
  
  }

  if (IN == 'O') {
    mot = 5;
  }
  if (mot == 5) {
  
    stepper1.moveTo(2000);
  
  }

  if (IN == '9') {
    mot = 2;
  }
  if (mot == 2){
    stepper1.moveTo(0);
  }
    if (IN == '1') {
      val = 1;
      break;
    }
    if (IN == '0') {
      val = 0;
      break;
    }
    if (IN == '3') {
      val = 3;
      break;
    }
    if (IN == '4') {
      val = 4;
      break;
    }
     stepper1.run();
    for (i = 0; i <= 255; i++) {
      analogWrite(led, i);
      delay(5);
    }
    delay(100);
    for (i = 255; i >= 0; i--) {
      analogWrite(led, i);
      delay(5);
    }
    delay(100);
   
    stepper1.run();
  }



  if (IN == 'V') {
    mot = 1;
  }
  if (mot == 1) {
  
    stepper1.moveTo(-7500);
  
  }

  if (IN == 'E') {
    mot = 3;
  }
  if (mot == 3) {
  
    stepper1.moveTo(7500);
    }

  if (IN == 'M') {
    mot = 4;
  }
  if (mot == 4) {
  
    stepper1.moveTo(-2000);
  
  }

  if (IN == 'O') {
    mot = 5;
  }
  if (mot == 5) {
  
    stepper1.moveTo(2000);
  
  }

  if (IN == '9') {
    mot = 2;
  }
  if (mot == 2){
    stepper1.moveTo(0);
  }
  stepper1.run();
}
