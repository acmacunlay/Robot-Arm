
// SETTING UP THE VARIABLES

  #include <Servo.h>
  #include <SoftwareSerial.h>
  
  SoftwareSerial Bluetooth(0, 1); //Blutooth(Rx pin, Tx pin)
  
  //setup for shoulder Left-Right servo
  Servo servo01;
  int pin_servo01 = 3;
  int pos_servo01;        // pos_servoXX holds the current position of the servo in degrees
  int min_servo01 = 0;    // min_servoXX sets the minimum angle that a servo could reach in degrees
  int max_servo01 = 180;  // max_servoXX sets the maximum angle that a servo could reacj in degrees
  int norm_servo01 = 90;  // norm_servoXX is the "default" position of the servo after turning on and receiving a "reset position" command from the app
  
  //setup for shoulder Up-Down servo
  Servo servo02;
  int pin_servo02 = 5;
  int pos_servo02;
  int min_servo02 = 45;
  int max_servo02 = 135;
  int norm_servo02 = 135;
  
  //setup for elbow servo
  Servo servo03;
  int pin_servo03 = 6;
  int pos_servo03;
  int min_servo03 = 90;
  int max_servo03 = 180;
  int norm_servo03 = 180;
  
  //setup for wrist Left-Right servo
  Servo servo04;
  int pin_servo04 = 9;
  int pos_servo04;
  int min_servo04 = 10;
  int max_servo04 = 170;
  int norm_servo04 = 90;
  
  //setup for wrist Up-Down sevo
  Servo servo05;
  int pin_servo05 = 10;
  int pos_servo05;
  int min_servo05 = 80;
  int max_servo05 = 170;
  int norm_servo05 = 135;
  
  //setup for gripper servo
  Servo servo06;
  int pin_servo06 = 11;
  int pos_servo06;
  int min_servo06 = 15;
  int max_servo06 = 85;
  int norm_servo06 = 85;
  
  int delayInterval = 15;
  int delaySetup = 500;
  
  int dataIn, m;

//END OF SETTING UP THE VARIABLES

//INITIALIZE

  void setup() {
  
    Bluetooth.begin(9600); // Bluetooth and Arduino baud rate must match. Arduino baud rate should adjust to the BT baud rate and not the other way around.
    Bluetooth.setTimeout(5);
    Serial.begin(9600);
  
    servo01.attach(pin_servo01);
    servo01.write(norm_servo01);
    pos_servo01 = norm_servo01;
    
    servo02.attach(pin_servo02);
    servo02.write(norm_servo02);
    pos_servo02 = norm_servo02;
  
    servo03.attach(pin_servo03);
    servo03.write(norm_servo03);
    pos_servo03 = norm_servo03;
  
    servo04.attach(pin_servo04);
    servo04.write(norm_servo04);
    pos_servo04 = norm_servo04;
  
    servo05.attach(pin_servo05);
    servo05.write(norm_servo05);
    pos_servo05 = norm_servo05;
  
    servo06.attach(pin_servo06);
    servo06.write(norm_servo06);
    pos_servo06 = norm_servo06;
    
  }

// END OF INITIALIZE

// LOOP

  void loop() {

    if (Bluetooth.available() > 0) {
      dataIn = Bluetooth.read();

      // assigning value for every possible movement of each servo
      if (dataIn == 0)  { m = 0; }  //stop movement
      if (dataIn == 1)  { m = 1; }  //reset position
      if (dataIn == 2)  { m = 2; }  //servo01 +
      if (dataIn == 3)  { m = 3; }  //servo01 -
      if (dataIn == 4)  { m = 4; }  //servo02 +
      if (dataIn == 5)  { m = 5; }  //servo02 -
      if (dataIn == 6)  { m = 6; }  //servo03 +
      if (dataIn == 7)  { m = 7; }  //servo03 -
      if (dataIn == 8)  { m = 8; }  //servo04 +
      if (dataIn == 9)  { m = 9; }  //servo04 -
      if (dataIn == 10) { m = 10; } //servo05 +
      if (dataIn == 11) { m = 11; } //servo05 -
      if (dataIn == 12) { m = 12; } //servo06 +
      if (dataIn == 13) { m = 13; } //servo06 -
      
      //reset position
      while (m == 1) {
        if (Bluetooth.available() > 0) {
          m = Bluetooth.read();
        }
        servo01.write(norm_servo01);
        pos_servo01 = norm_servo01;
        servo02.write(norm_servo02);
        pos_servo02 = norm_servo02;
        servo03.write(norm_servo03);
        pos_servo03 = norm_servo03;
        servo04.write(norm_servo04);
        pos_servo04 = norm_servo04;
        servo05.write(norm_servo05);
        pos_servo05 = norm_servo05;
        servo06.write(norm_servo06);
        pos_servo06 = norm_servo06;
        
      }

      //servo01 +
      while (m == 2) {
        if (Bluetooth.available() > 0) {
          m = Bluetooth.read();
        }
        servo01.write(pos_servo01);
        if (pos_servo01 < max_servo01) {
          pos_servo01++;
        } if (pos_servo01 == max_servo01) {
          pos_servo01 = max_servo01;
        }
        delay(delayInterval);
      }

      //servo01 -
      while (m == 3) {
        if (Bluetooth.available() > 0) {
          m = Bluetooth.read();
        }
        servo01.write(pos_servo01);
        if (pos_servo01 > min_servo01) {
          pos_servo01--;
        } if (pos_servo01 == min_servo01) {
          pos_servo01 = min_servo01;
        }
        delay(delayInterval);
      }

      //servo02 +
      while (m == 4) {
        if (Bluetooth.available() > 0) {
          m = Bluetooth.read();
        }
        servo02.write(pos_servo02);
        if (pos_servo02 < max_servo02) {
          pos_servo02++;
        } if (pos_servo02 == max_servo02) {
          pos_servo02 = max_servo02;
        }
        delay(delayInterval);
      }

      //servo02 -
      while (m == 5) {
        if (Bluetooth.available() > 0) {
          m = Bluetooth.read();
        }
        servo02 .write(pos_servo02);
        if (pos_servo02 > min_servo02) {
          pos_servo02--;
        } if (pos_servo02 == min_servo02) {
          pos_servo02 = min_servo02;
        }
        delay(delayInterval);
      }

      //servo03 +
      while (m == 6) {
        if (Bluetooth.available() > 0) {
          m = Bluetooth.read();
        }
        servo03.write(pos_servo03);
        if (pos_servo03 < max_servo03) {
          pos_servo03++;
        } if (pos_servo03 == max_servo03) {
          pos_servo03 = max_servo03;
        }
        delay(delayInterval);
      }

      //servo03 -
      while (m == 7) {
        if (Bluetooth.available() > 0) {
          m = Bluetooth.read();
        }
        servo03.write(pos_servo03);
        if (pos_servo03 > min_servo03) {
          pos_servo03--;
        } if (pos_servo03 == min_servo03) {
          pos_servo03 = min_servo03;
        }
        delay(delayInterval);
      }

      //servo04 +
      while (m == 8) {
        if (Bluetooth.available() > 0) {
          m = Bluetooth.read();
        }
        servo04.write(pos_servo04);
        pos_servo04++;
        if (pos_servo04 < max_servo04) {
          pos_servo04++;
        } if (pos_servo04 == max_servo04) {
          pos_servo04 = max_servo04;
        }
        delay(delayInterval);
      }

      //servo04 -
      while (m == 9) {
        if (Bluetooth.available() > 0) {
          m = Bluetooth.read();
        }
        servo04.write(pos_servo04);
        if (pos_servo04 > min_servo04) {
          pos_servo04--;
        } if (pos_servo04 == min_servo04) {
          pos_servo04 = min_servo04;
        }
        delay(delayInterval);
      }

      //servo05 +
      while (m == 10) {
        if (Bluetooth.available() > 0) {
          m = Bluetooth.read();
        }
        servo05.write(pos_servo05);
        if (pos_servo05 < max_servo05) {
          pos_servo05++;
        } if (pos_servo05 == max_servo05) {
          pos_servo05 = max_servo05;
        }
        delay(delayInterval);
      }

      //servo05 -
      while (m == 11) {
        if (Bluetooth.available() > 0) {
          m = Bluetooth.read();
        }
        servo05.write(pos_servo05);
        if (pos_servo05 > min_servo05) {
          pos_servo05--;
        } if (pos_servo05 == min_servo05) {
          pos_servo05 = min_servo05;
        }
        delay(delayInterval);
      }

      //servo06 +
      while (m == 12) {
        if (Bluetooth.available() > 0) {
          m = Bluetooth.read();
        }
        servo06.write(pos_servo06);
        if (pos_servo06 < max_servo06) {
          pos_servo06++;
        } if (pos_servo06 == max_servo06) {
          pos_servo06 = max_servo06;
        }
        delay(delayInterval);
      }

      //servo06 -
      while (m == 13) {
        if (Bluetooth.available() > 0) {
          m = Bluetooth.read();
        }
        servo06.write(pos_servo06);
        if (pos_servo06 > min_servo06) {
          pos_servo06--;
        } if (pos_servo06 == min_servo06) {
          pos_servo06 = min_servo06;
        }
        delay(delayInterval);
      }
      
    }
    
  }

// END OF LOOP
