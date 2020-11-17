//제작: HRP (Hanium ROLAB Project)

#include "Servo_test.h"

// 초기 모터 각도 설정
void setup()
{
  Serial.begin(9600);
  for(int i=3; i<9; i++){   
  servo[i].attach(i);
  servo[i].write(angle[i]);
  Serial.print(i);
  Serial.print("번 모터 초깃값 설정: ");
  Serial.println(angle[i]);
  delay(1500);
  }
  menu();
}

/*
1번 테스트
2번 모션제어
3번 현재 정보출력


*/

void loop()
{
 
  if(Serial.available()){
    String inString = Serial.readStringUntil('\n');
    if(inString=="1")
    test();
    else if(inString=="2")
    motion();
    else if(inString=="?")
    inform();
    menu();
  }
}

//menu 문자열 출력 함수
void menu(){   
  Serial.println("번호를 입력하세요:\n 1. Test \n 2. Motion \n ?. Inform");
  }
