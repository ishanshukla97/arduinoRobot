/*
 * Bluetooth Controlled Robot
 * ***************************************************
 * ***************************************************
 * 
 * Description:
 * Bluetooth communication is established between android phone and HC-05
 * 
 * A seperate function "check_forward" is defined and called for recieving data from bluetooh instantaneously
 * as the key is pressed.
 */

//public declarations

//back
int backRight_pinA = 2;
int backRight_pinB = 3;
int backLeft_pinA = 4;
int backLeft_pinB = 5;

//front
int frontRight_pinA = 6;
int frontRight_pinB = 7;
int frontLeft_pinA = 8;
int frontLeft_pinB = 9;

 void setup() {
  Serial.begin(9600);
  //back
  pinMode(backRight_pinA , OUTPUT);
  pinMode(backRight_pinB , OUTPUT);
  pinMode(backLeft_pinA , OUTPUT);
  pinMode(backLeft_pinB , OUTPUT);

  //front
  pinMode(frontRight_pinA , OUTPUT);
  pinMode(frontRight_pinB , OUTPUT);
  pinMode(frontLeft_pinA , OUTPUT);
  pinMode(frontRight_pinB , OUTPUT);
}

void loop() {
  int byteRead;
  while(Serial.available()){
    byteRead = Serial.read();
    if(check_forward(&byteRead)){
      forward();
    }
    else if(byteRead == 2){
      backward();
    }
    else if(byteRead == 4){
       turn_left();
    }
    else if(byteRead == 6){
      turn_right();
    }
  }
}

//function to modify data recieved from bluetooth***********************************************************
bool check_forward(int* data){
  *data = *data -'0';
  if(*data == 8)
    return true;
  else
    return false;
}


//function to run front and back motors in forward direction************************************************
void forward(){
  //back(OK TESTED)
  digitalWrite(backRight_pinA , HIGH);
  digitalWrite(backRight_pinB , LOW);
  digitalWrite(backLeft_pinA , HIGH);
  digitalWrite(backLeft_pinB , LOW);

  //front(OK TESTED)
  digitalWrite(frontRight_pinA , HIGH);
  digitalWrite(frontRight_pinB , LOW);
  digitalWrite(frontLeft_pinA , HIGH);
  digitalWrite(frontLeft_pinB , LOW);
}//forward() Ends


//function to run front and back motors in backward direction************************************************
void backward(){
  //back(OK TESTED)
  digitalWrite(backRight_pinA , LOW);
  digitalWrite(backRight_pinB , HIGH);
  digitalWrite(backLeft_pinA , LOW);
  digitalWrite(backLeft_pinB , HIGH);

  //front(OK TESTED)
  digitalWrite(frontRight_pinA , LOW);
  digitalWrite(frontRight_pinB , HIGH);
  digitalWrite(frontLeft_pinA , LOW);
  digitalWrite(frontLeft_pinB , HIGH);
}//backward() Ends


//fuunction to turn robot in right direction*****************************************************************
void turn_right(){
  //right Wheels-in backward direction(OK TESTED)
  digitalWrite(backRight_pinA , LOW);
  digitalWrite(backRight_pinB , HIGH);
  digitalWrite(frontRight_pinA , LOW);
  digitalWrite(frontRight_pinB , HIGH);

  //left Wheels -forwward direction(OK TESTED)
  digitalWrite(backLeft_pinA , HIGH);
  digitalWrite(backLeft_pinB , LOW);
  digitalWrite(frontLeft_pinA , HIGH);
  digitalWrite(frontLeft_pinB , LOW);
}//turn_right()Ends


//function to turn robot in left direction**********************************************************************
void turn_left(){
  //right wheels-in forward direction
  digitalWrite(backRight_pinA , HIGH);
  digitalWrite(backRight_pinB , LOW);
  digitalWrite(frontRight_pinA , HIGH);
  digitalWrite(frontRight_pinB , LOW);

  //left wheels-in backward direction
  digitalWrite(backLeft_pinA , LOW);
  digitalWrite(backLeft_pinB , HIGH);
  digitalWrite(frontLeft_pinA , LOW);
  digitalWrite(frontLeft_pinB , HIGH);
}//turn_left() Ends

//function to hault all motors in case there is no signal from bluetooth

void hault(){
  digitalWrite(2 , LOW);
  digitalWrite(3 , LOW);
  digitalWrite(4 , LOW);
  digitalWrite(5 , LOW);

  //front(OK TESTED)
  digitalWrite(6 , LOW);
  digitalWrite(7 , LOW);
  digitalWrite(8 , LOW);
  digitalWrite(9 , LOW);
}

