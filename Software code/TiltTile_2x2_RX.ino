//TiltTile 2x2 RX Demo

/*Continually watches for characters from 2x2 TX demo*/


#include <Servo.h> 
 
Servo myservo1;  // create servo object to control a servo a maximum of eight servo objects can be created 
Servo myservo2;  
Servo myservo3;
Servo myservo4;

int byte_one;
int byte_two;
//char next_byte;
 
void setup() 
{ 
  pinMode(P2_7, OUTPUT); // XBee enable (LOW)
  pinMode(P3_4, OUTPUT); // UART RX
  pinMode(P3_3, OUTPUT); // UART TX

  digitalWrite(P2_2, LOW); //Permanently enabled XBee


  Serial.begin(9600);  //for debugging
  Serial1.begin(9600);

  pinMode(P2_5, OUTPUT); 
  pinMode(P2_4, OUTPUT);
  pinMode(P1_5, OUTPUT);
  pinMode(P2_0, OUTPUT);
  
  myservo1.attach(P2_5);
  myservo2.attach(P2_4); 
  myservo3.attach(P1_5);
  myservo4.attach(P2_0);
} 


 
void loop() 
{ 
  /*Continually poll for new characters*/

  if (Serial1.available() > 0){               //Character available 
      byte_one = Serial1.read();
      //byte_two = Serial1.read();
      Serial.print(byte_one);
      //Serial.print(byte_two);


    if (byte_one == '1'){                      
        Serial.println("Servo1 Open"); 
        myservo1.write(90);                
        delay(1500);
    }else if (byte_one == '2'){
      Serial.println("Servo1 Closed");
        myservo1.write(0);                    
        delay(1500);
    }else if(byte_one == '3'){   
        Serial.println("Servo2 Open");      
        myservo2.write(90);   
        delay(1500);                 
    }else if (byte_one == '4'){          
        myservo2.write(0);  
        Serial.println("Servo2 Closed");
        delay(1500);                              
    }else if (byte_one == '5'){                
        Serial.println("Servo3 Open");          
        myservo3.write(90);
        delay(1500);                              
     }else if (byte_one == '6'){            
        Serial.println("Servo3 Closed");
        myservo3.write(0);  
        delay(1500);                 
     }else if (byte_one == '7'){           
        Serial.println("Servo4 Open");          
        myservo4.write(90);  
        delay(1500);                             
     }else if (byte_one == '8'){          
        Serial.println("Servo4 Closed");  
        myservo4.write(0);   
        delay(1500);                              
     }else{
      //Do nothing
     }
  }
}
