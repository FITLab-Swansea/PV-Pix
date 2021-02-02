//TiltTile 2x2 TX Demo

#include <Servo.h> 
 
Servo myservo1;  // Create servo object to control a servo a maximum of eight servo objects can be created 
Servo myservo2;  
Servo myservo3;
Servo myservo4;

int tile1_open_closed = 0; //'HIGH' open; 'LOW' closed
int tile2_open_closed = 0;
int tile3_open_closed = 0;
int tile4_open_closed = 0;

volatile int tile1_touched = 0;     //Has tile been touched?
volatile int tile2_touched = 0;
volatile int tile3_touched = 0;
volatile int tile4_touched = 0;

 
void setup() 
{ 
  pinMode(P8_1, OUTPUT); // XBee enable (LOW)
  pinMode(P3_4, OUTPUT); // UART RX
  pinMode(P3_3, OUTPUT); // UART TX

  pinMode(P2_2, OUTPUT); //Enable Servos

  pinMode(P2_6, INPUT_PULLUP); //Touch pins
  pinMode(P2_3, INPUT_PULLUP);
  pinMode(P1_6, INPUT_PULLUP);
  pinMode(P2_7, INPUT_PULLUP); 

  //Attach interrupt
  attachInterrupt(digitalPinToInterrupt (P2_6), tilt_tile1, RISING);
  attachInterrupt(digitalPinToInterrupt (P2_3), tilt_tile2, RISING);
  attachInterrupt(digitalPinToInterrupt (P1_6), tilt_tile3, RISING);
  attachInterrupt(digitalPinToInterrupt (P2_7), tilt_tile4, RISING);  

  Serial.begin(9600);       //Debug
  Serial1.begin(9600);

  myservo1.attach(P2_5);
  myservo2.attach(P2_4); 
  myservo3.attach(P1_5);
  myservo4.attach(P1_4);

    Serial.print("Setup ");
            
} 
 
void loop() 
{ 
 
 Serial.println("loop");

  if(tile1_touched == '1'){                  /******** Tile 1 ********/
    digitalWrite(P2_2, HIGH);             //Enable Servos          
      if(tile1_open_closed == '0'){           //Toggle tile position. LOW = closed
        tile1_open_closed = '1';
        myservo1.write(90);                  //Move tile to open position
        digitalWrite(P2_7, LOW);               //Enable XBee
        Serial1.print('1');                   //Transmit ASCII '1'
        //Serial1.print('5');                   //Transmit ASCII '5' for open
        digitalWrite(P2_7, HIGH);              //Disable XBee
      }else{                                  //HIGH = open
        tile1_open_closed = '0';
        myservo1.write(0);                  //Move tile to open position
        digitalWrite(P2_7,LOW);               //Enable XBee
        Serial1.print('2');                   //Transmit ASCII '1'
        //Serial1.print('6');                   //Transmit ASCII '6' for closed
        digitalWrite(P2_7,HIGH);              //Disable XBee
      }
    
  }else if(tile2_touched == '1'){            /******** Tile 2 ********/ 
    digitalWrite(P2_2, HIGH);             //Enable Servos                                       
      if(tile2_open_closed == '0'){          
        tile2_open_closed = '1';
        myservo2.write(90);                  //Move tile to open position
        digitalWrite(P2_7,LOW);               //Enable XBee
        Serial1.print('3');                   //Transmit ASCII '2'
        //Serial1.print('5');                   //Transmit ASCII '5' for open
        digitalWrite(P2_7,HIGH);              //Disable XBee
      }else{                            
        tile2_open_closed = '0';
        myservo2.write(0);                  //Move tile to open position
        digitalWrite(P2_7,LOW);               //Enable XBee
        Serial1.print('4');                   //Transmit ASCII '2'
        //Serial1.print('6');                   //Transmit ASCII '6' for closed
        digitalWrite(P2_7,HIGH);              //Disable XBee 
      }
    
  }else if(tile3_touched == '1'){            /******** Tile 3 ********/  
    digitalWrite(P2_2, HIGH);             //Enable Servos                                       
      if(tile3_open_closed == '0'){          
        tile3_open_closed = '1';
        myservo3.write(90);                  //Move tile to open position
        digitalWrite(P2_7,LOW);               //Enable XBee
        Serial1.print('5');                   //Transmit ASCII '3'
        //Serial1.print('5');                   //Transmit ASCII '5' for open
        digitalWrite(P2_7,HIGH);              //Disable XBee
      }else{                                
        tile3_open_closed = '0'; 
        myservo3.write(0);                  //Move tile to open position
        digitalWrite(P2_7,LOW);               //Enable XBee
        Serial1.print('6');                   //Transmit ASCII '3'
        //Serial1.print('6');                   //Transmit ASCII '6' for closed
        digitalWrite(P2_7,HIGH);              //Disable XBee 
      }
      
  }else if(tile4_touched == '1'){            /******** Tile 4 ********/ 
    digitalWrite(P2_2, HIGH);             //Enable Servos                               
      if(tile4_open_closed == '0'){          
         tile4_open_closed = '1';
         myservo4.write(90);                  //Move tile to open position
         digitalWrite(P2_7,LOW);               //Enable XBee
         Serial1.print('7');                   //Transmit ASCII '4'
         //Serial1.print('5');                   //Transmit ASCII '5' for open
         digitalWrite(P2_7,HIGH);              //Disable XBee
      }else{                                
         tile4_open_closed = '0'; 
         myservo4.write(0);                  //Move tile to open position
         digitalWrite(P2_7,LOW);               //Enable XBee
         Serial1.print('8');                   //Transmit ASCII '4'
         //Serial1.print('6');                   //Transmit ASCII '6' for closed
         digitalWrite(P2_7,HIGH);              //Disable XBee 
  
      }
      
  }else{
     //Do nothing
  }
  

  delay(1500); 
  digitalWrite(P2_2, LOW);              //Disable Servos  
  tile1_touched = '0';         //Reset all tiles to untouched
  tile2_touched = '0';
  tile3_touched = '0';
  tile4_touched = '0';
  
  suspend();                   //MCU to low power mode

  
}

/*********** Interrupt Service Routines ***********/

void tilt_tile1(){
  tile1_touched = '1';
  wakeup(); 
}

void tilt_tile2(){
  tile2_touched = '1';
  wakeup();
}

void tilt_tile3(){
  tile3_touched = '1';
  wakeup();
}

void tilt_tile4(){      //tilt_tile4
  tile4_touched = '1';
  wakeup();
}
