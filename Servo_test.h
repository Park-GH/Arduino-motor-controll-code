//This source code can control servo motor for test.
//Usage: In Serial Communication, you input precondition
//precondition: "MotorNumber,angle"
//ex) "3,70" "4,80"
//postcondition: Motor controlled

//(3,집게),(4,손목),(5,전체손목회전),(6,어깨),(7,팔),(8,몸통)
//ex) 3,90 3번모터 90도
/*6,0 7,180
6,20 7,150
6,30 7,150
6,50 7,140
6,50 7,130
6,60 7,120
6번이 90도 세워짐 >>> 7번은 왔다갔다*/

#include <Servo.h>

#define m_speed 10

Servo servo[9];
int angle[9]={0, 0, 0, 30, 0, 0, 50, 130, 90};  //initial angle condition 0~180


void inform(){
  Serial.println("======Inform======");
  int num=3;
  for(num; num<=8; num++){
    Serial.print(num);
    Serial.print("번 모터: ");
    Serial.println(angle[num]);
 }
   Serial.println("==================");
} 







void motion(){
  Serial.println("======Motion======");
  Serial.println("?: Inform");
  Serial.println("/: Return menu");
  Serial.println("==================");
   while(1){
  if(Serial.available()){
    String inString = Serial.readStringUntil('\n');
    if(inString=="/")
  break;
    else if(inString=="S"){ //뻗음
    angle[6]=160;angle[7]=130;
    servo[6].write(angle[6]);
    servo[7].write(angle[7]);
    }
    else if(inString=="D"){ //내림
    angle[6]=50;angle[7]=150;
    delay(1000);
    angle[6]=50;angle[7]=130;
    servo[6].write(angle[6]);
    servo[7].write(angle[7]);
    }
    else if(inString=="U"){ //올림
    angle[6]=50;angle[7]=150;
    delay(1000);
    angle[6]=90;angle[7]=180;
    servo[6].write(angle[6]);
    servo[7].write(angle[7]);
    }
    else if(inString=="N"){ //벌림
    angle[3]=0;
    servo[3].write(angle[3]);
    }
    else if(inString=="B"){ //닫으
    angle[3]=60;
    servo[3].write(angle[3]);
    }
    else if(inString=="R"){
    angle[8]=0;
    servo[8].write(angle[8]);
    }
    else if(inString=="M"){
    angle[8]=90;
    servo[8].write(angle[8]);
    }
    else if(inString=="L"){
    angle[8]=180;
    servo[8].write(angle[8]);
    }
    else if(inString=="?")
    inform();
    else{
    Serial.println("Input Error");
    }
  } 
}
}










void test()
{
  Serial.println("======Test========");
  Serial.println("?: Inform");
  Serial.println("/: Return menu");
  Serial.println("==================");
while(1){
  if(Serial.available()){
    String inString = Serial.readStringUntil('\n');
    if(inString=="/")
	break;
    else if(inString[1]==','){
    int Motor = int(inString[0])-48;
    int index_length = inString.length(); 
    angle[Motor] = inString.substring(2, index_length).toInt();
    Serial.print(Motor);
    Serial.print(",");
    Serial.println(angle[Motor]);
    servo[Motor].write(angle[Motor]);
    delay(1000);
    }
    else if(inString=="?")
    inform();
    else{
    Serial.println("Input Error");
    }
  } 
}
}

void operation(int num, int ang)
{
  int temp;
  if(angle[num]<ang)
  for(angle[num]; angle[num]<=ang; angle[num]++){
     servo[num].write(angle[num]);
     delay(m_speed);
  }
  else
  for(angle[num]; angle[num]>=ang; angle[num]--){
     servo[num].write(angle[num]);
     delay(m_speed);  
  }
}
