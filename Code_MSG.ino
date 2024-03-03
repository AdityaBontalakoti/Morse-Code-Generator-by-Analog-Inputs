int pot;
int led;
void setup() {
  Serial.println("Code by Aditya Bontalakoti and Animireddi Sandeep");
  
  pinMode(A1, INPUT);
  pinMode(5, OUTPUT); // led from the potentiometer is given to PWM pins only because of duty cycle.
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(12,INPUT); //THis pin is taken as input
  pinMode(3,OUTPUT);
  Serial.begin(9600); //Here baudrate is 9600

}


void loop() {
  //delay(3000);
  pot = analogRead(A1); //reading is stored of A1
  led = map(pot, 0, 1023, 0, 255); // Analog  to digital Convertor by mapping.

  analogWrite(5, led); //The analog data is fed to pin5
  //int g = pot/4;
  Serial.println(led);
  //Serial.println(g);
  Serial.println("Potentiometer is starting again");
  digitalWrite(9,HIGH); //9 pin is always high . Here it is fixed

  /*We used a XOR GATE , so that 0 XOR 1(FIXED) is 1 i.e DASH-- , 1 XOR 1(FIXED) is 0 i.e DOT*/
  // Here led value varies from 0 to 255 . 
  if(led<125){
    digitalWrite(8,LOW); 
  }
  else if(led>=125){
    digitalWrite(8,HIGH);
  }
  
  int condition = digitalRead(12);
  Serial.println("The Condition is" + condition);
  
  
  if(condition == 0){
    //Write the code for DASH
    digitalWrite(3,LOW);
    delay(50); //Given because to basically stop every other function before executing the below 2 statements
    digitalWrite(3,HIGH);
    delay(3000);
  }

  else if(condition == 1){
    //Write the code for DOT
    digitalWrite(3,LOW);
    delay(100);//Given because to basically stop every other function before executing the below 2 statements
    digitalWrite(3,HIGH);
    delay(1000);
    //END
    
  }
}