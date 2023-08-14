/* 
일지
  JULY 11 2023
    HC06 모듈 (블루투스) 통신 확인

  AUGUST 2 2023
    Digital Write맵 작성
    코드 설명 작성

  AUGUST ## 2023
*/


/* 
아두이노 핀 맵
  Tx : 1
  Rx : 0

  TRRS : 3

  COL0 : 4 (A6)
  COL1 : 5
  COL2 : 6 (A7)
  COL3 : 7
  COL4 : 8 (A8)
  COL5 : 9 (A9)

  ROW0 : 10 (A10)
  ROW1 : 16
  ROW2 : 14
  ROW3 : 15
  ROW4 : 18 (A0)
  ROW5 : 19 (A1)

*/

//define//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  #define C0 4
  #define C1 5
  #define C2 6
  #define C3 7
  #define C4 8
  #define C5 9
  #define R0 10
  #define R1 16
  #define R2 14
  #define R3 15
  #define R4 18
  #define R5 19
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//라이브러리//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  #include <SoftwareSerial.h>        // 통신 라이브러리
  #include <Keyboard.h>              // 키보드 라이브러리
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

SoftwareSerial BTSerial (1,0);       // 블루투스 객체 선언 (Tx, Rx)


void setup() {
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  Serial1.begin(9600);               // 시리얼 모니터 시작 (통신속도)
  BTSerial.begin(9600);              // 블루투스 통신 시작 (통신속도)
  Keyboard.begin();                  // 키보드 시작 (통신속도)
//pinMode(C0~C5)//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  pinMode(C0,OUTPUT);                //     `(96)      //    KEY_TAB    // KEY_CAPS_ROCK // KEY_LEFT_SHIFT //    KEY_ESC    //               //
  pinMode(C1,OUTPUT);                //       1        //       Q       //       A       //       Z        // KEY_LEFT_CTRL //               //
  pinMode(C2,OUTPUT);                //       2        //       W       //       S       //       X        // KEY_LEFT_GUI  //               //
  pinMode(C3,OUTPUT);                //       3        //       E       //       D       //       C        // KEY_LEFT_ALT  //               // 
  pinMode(C4,OUTPUT);                //       4        //       R       //       F       //       V        //  KEY_DELETE   // KEY_BACKSPACE //
  pinMode(C5,OUTPUT);                //       5        //       T       //       G       //       B        //   SPACE(32)   //   KEY_RETURN  //
//pinMode(R0~R5)//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  pinMode(R0,INPUT_PULLUP);          //     `(96)      //       1       //       2       //       3        //       4       //       5       //
  pinMode(R1,INPUT_PULLUP);          //    KEY_TAB     //       Q       //       W       //       E        //       R       //       T       //
  pinMode(R2,INPUT_PULLUP);          // KEY_CAPS_ROCK  //       A       //       S       //       D        //       F       //       G       //
  pinMode(R3,INPUT_PULLUP);          // KEY_LEFT_SHIFT //       Z       //       X       //       C        //       V       //       B       //
  pinMode(R4,INPUT_PULLUP);          //    KEY_ESC     // KEY_LEFT_CTRL //  KEY_LEFT_GUI //  KEY_LEFT_ALT  //  KEY_DELETE   //   SPACE(32)   //
  pinMode(R5,INPUT_PULLUP);          // KEY_BACKSPACE  //  KEY_RETURN   //               //                //               //               //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void loop() {
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  digitalWrite(R0, LOW); // `(96)     1     2     3     4     5
    // `
      if (digitalRead(C0)) Keyboard.release(96);               // 만약 C0 에서 디지털 입력이 감지된다면, Keyboard.release(96)을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press(96);                                 // C0 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press(96)을 실행 [LOW (0)인 경우 키를 눌러줌]
    // 1
      if (digitalRead(C1)) Keyboard.release('1');              // 만약 C1 에서 디지털 입력이 감지된다면, Keyboard.release('1')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press('1');                                // C1 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('1')을 실행 [LOW (0)인 경우 키를 눌러줌]
    // 2
      if (digitalRead(C2)) Keyboard.release('2');              // 만약 C2 에서 디지털 입력이 감지된다면, Keyboard.release('2')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press('2');                                // C2 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('2')을 실행 [LOW (0)인 경우 키를 눌러줌]
    // 3
      if (digitalRead(C3)) Keyboard.release('3');              // 만약 C3 에서 디지털 입력이 감지된다면, Keyboard.release('3')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press('3');                                // C3 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('3')을 실행 [LOW (0)인 경우 키를 눌러줌]
    // 4
      if (digitalRead(C4)) Keyboard.release('4');              // 만약 C4 에서 디지털 입력이 감지된다면, Keyboard.release('4')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press('4');                                // C4 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('4')을 실행 [LOW (0)인 경우 키를 눌러줌]
    // 5
      if (digitalRead(C5)) Keyboard.release('5');              // 만약 C5 에서 디지털 입력이 감지된다면, Keyboard.release('5')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press('5');                                // C5 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('5')을 실행 [LOW (0)인 경우 키를 눌러줌]
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  digitalWrite(R1, LOW); // KEY_TAB     Q     W     E     R     T
    // TAB
      if (digitalRead(C0)) Keyboard.release(KEY_TAB);          // 만약 C0 에서 디지털 입력이 감지된다면, Keyboard.release(KEY_TAB)을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press(KEY_TAB);                            // C0 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press(KEY_TAB)을 실행 [LOW (0)인 경우 키를 눌러줌]
    // Q
      if (digitalRead(C1)) Keyboard.release('q');              // 만약 C1 에서 디지털 입력이 감지된다면, Keyboard.release('q')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press('q');                                // C1 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('q')을 실행 [LOW (0)인 경우 키를 눌러줌]
    // W
      if (digitalRead(C2)) Keyboard.release('w');              // 만약 C2 에서 디지털 입력이 감지된다면, Keyboard.release('w')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press('w');                                // C2 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('w')을 실행 [LOW (0)인 경우 키를 눌러줌]
    // E
      if (digitalRead(C3)) Keyboard.release('e');              // 만약 C3 에서 디지털 입력이 감지된다면, Keyboard.release('e')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press('e');                                // C3 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('e')을 실행 [LOW (0)인 경우 키를 눌러줌]
    // R
      if (digitalRead(C4)) Keyboard.release('r');              // 만약 C4 에서 디지털 입력이 감지된다면, Keyboard.release('r')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press('r');                                // C4 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('r')을 실행 [LOW (0)인 경우 키를 눌러줌]
    // T
      if (digitalRead(C5)) Keyboard.release('t');              // 만약 C5 에서 디지털 입력이 감지된다면, Keyboard.release('t')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press('t');                                // C5 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('t')을 실행 [LOW (0)인 경우 키를 눌러줌]
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
  digitalWrite(R2, LOW); // KEY_CAPS_LOCK     A     S     D     F     G
    // KEY_CAPS_LOCK
      if (digitalRead(C0)) Keyboard.release(KEY_CAPS_LOCK);    // 만약 C0 에서 디지털 입력이 감지된다면, Keyboard.release(KEY_CAPS_LOCK)을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press(KEY_CAPS_LOCK);                      // C0 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press(KEY_CAPS_LOCK)을 실행 [LOW (0)인 경우 키를 눌러줌]
    // A
      if (digitalRead(C1)) Keyboard.release('a');              // 만약 C1 에서 디지털 입력이 감지된다면, Keyboard.release('a')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press('a');                                // C1 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('a')을 실행 [LOW (0)인 경우 키를 눌러줌]
    // S
      if (digitalRead(C2)) Keyboard.release('s');              // 만약 C2 에서 디지털 입력이 감지된다면, Keyboard.release('s')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press('s');                                // C2 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('s')을 실행 [LOW (0)인 경우 키를 눌러줌]
    // D
      if (digitalRead(C3)) Keyboard.release('d');              // 만약 C3 에서 디지털 입력이 감지된다면, Keyboard.release('d')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press('d');                                // C3 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('d')을 실행 [LOW (0)인 경우 키를 눌러줌]
    // F
      if (digitalRead(C4)) Keyboard.release('f');              // 만약 C4 에서 디지털 입력이 감지된다면, Keyboard.release('f')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press('f');                                // C4 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('f')을 실행 [LOW (0)인 경우 키를 눌러줌]
    // G
      if (digitalRead(C5)) Keyboard.release('g');              // 만약 C5 에서 디지털 입력이 감지된다면, Keyboard.release('g')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press('g');                                // C5 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('g')을 실행 [LOW (0)인 경우 키를 눌러줌]
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  digitalWrite(R3, LOW); // KEY_LEFT_SHIFT     Z     X     C     V     B
    // KEY_LEFT_SHIFT
      if (digitalRead(C0)) Keyboard.release(KEY_LEFT_SHIFT);   // 만약 C0 에서 디지털 입력이 감지된다면, Keyboard.release(KEY_LEFT_SHIFT)을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press(KEY_LEFT_SHIFT);                     // C0 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press(KEY_LEFT_SHIFT)을 실행 [LOW (0)인 경우 키를 눌러줌]
    // Z
      if (digitalRead(C1)) Keyboard.release('z');              // 만약 C1 에서 디지털 입력이 감지된다면, Keyboard.release('z')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press('z');                                // C1 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('z')을 실행 [LOW (0)인 경우 키를 눌러줌]
    // X
      if (digitalRead(C2)) Keyboard.release('x');              // 만약 C2 에서 디지털 입력이 감지된다면, Keyboard.release('x')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press('x');                                // C2 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('x')을 실행 [LOW (0)인 경우 키를 눌러줌]
    // C
      if (digitalRead(C3)) Keyboard.release('c');              // 만약 C3 에서 디지털 입력이 감지된다면, Keyboard.release('c')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press('c');                                // C3 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('c')을 실행 [LOW (0)인 경우 키를 눌러줌]
    // V
      if (digitalRead(C4)) Keyboard.release('v');              // 만약 C4 에서 디지털 입력이 감지된다면, Keyboard.release('v')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press('v');                                // C4 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('v')을 실행 [LOW (0)인 경우 키를 눌러줌]
    // B
      if (digitalRead(C5)) Keyboard.release('b');              // 만약 C5 에서 디지털 입력이 감지된다면, Keyboard.release('b')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press('b');                                // C5 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('b')을 실행 [LOW (0)인 경우 키를 눌러줌]
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  digitalWrite(R4, LOW); // KEY_ESC     KEY_LEFT_CTRL     KEY_LEFT_GUI     KEY_LEFT_ALT     KEY_DELETE     SPACE(32)
    // KEY_ESC
      if (digitalRead(C0)) Keyboard.release(KEY_ESC);          // 만약 C0 에서 디지털 입력이 감지된다면, Keyboard.release(KEY_ESC)을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press(KEY_ESC);                            // C0 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press(KEY_ESC)을 실행 [LOW (0)인 경우 키를 눌러줌]
    // KEY_LEFT_CTRL
      if (digitalRead(C1)) Keyboard.release(KEY_LEFT_CTRL);    // 만약 C1 에서 디지털 입력이 감지된다면, Keyboard.release('KEY_LEFT_CTRL')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press(KEY_LEFT_CTRL);                      // C1 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('KEY_LEFT_CTRL')을 실행 [LOW (0)인 경우 키를 눌러줌]
    // KEY_LEFT_GUI
      if (digitalRead(C2)) Keyboard.release(KEY_LEFT_GUI);     // 만약 C2 에서 디지털 입력이 감지된다면, Keyboard.release('KEY_LEFT_GUI')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press(KEY_LEFT_GUI);                       // C2 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('KEY_LEFT_GUI')을 실행 [LOW (0)인 경우 키를 눌러줌]
    // KEY_LEFT_ALT
      if (digitalRead(C3)) Keyboard.release(KEY_LEFT_ALT);     // 만약 C3 에서 디지털 입력이 감지된다면, Keyboard.release('KEY_LEFT_ALT')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press(KEY_LEFT_ALT);                       // C3 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('KEY_LEFT_ALT')을 실행 [LOW (0)인 경우 키를 눌러줌]
    // KEY_DELETE
      if (digitalRead(C4)) Keyboard.release(KEY_DELETE);       // 만약 C4 에서 디지털 입력이 감지된다면, Keyboard.release('KEY_DELETE')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press(KEY_DELETE);                         // C4 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('KEY_DELETE')을 실행 [LOW (0)인 경우 키를 눌러줌]
    // SPACE(32)
      if (digitalRead(C5)) Keyboard.release('32');             // 만약 C5 에서 디지털 입력이 감지된다면, Keyboard.release('32')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press('32');                               // C5 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('32')을 실행 [LOW (0)인 경우 키를 눌러줌]
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  digitalWrite(R5, LOW); // KEY_BACKSPACE     KEY_RETURN
    // KEY_BACKSPACE
      if (digitalRead(C0)) Keyboard.release(KEY_BACKSPACE);    // 만약 C0 에서 디지털 입력이 감지된다면, Keyboard.release(KEY_BACKSPACE)을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press(KEY_BACKSPACE);                      // C0 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press(KEY_BACKSPACE)을 실행 [LOW (0)인 경우 키를 눌러줌]
    // KEY_RETURN 
      if (digitalRead(C1)) Keyboard.release(KEY_RETURN);       // 만약 C1 에서 디지털 입력이 감지된다면, Keyboard.release('KEY_RETURN')을 실행 [HIGH (1)인 경우 키를 놓아줌]
      else Keyboard.press(KEY_RETURN);                         // C1 에서 디지털 입력이 감지되지 않은 경우에는 Keyboard.press('KEY_RETURN')을 실행 [LOW (0)인 경우 키를 눌러줌]
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}



/*
  if(BTSerial.available()){         // 블루투스 통신이 사용되면
    Serial1.write(BTSerial.read()); // 시리얼 모니터에 입력된 데이터를 블루투스 통신이 읽어옴
  }
  if(Serial1.available()){          // 시리얼 모니터 통신이 사용되면
    BTSerial.write(Serial1.read()); // 블루투스에 입력된 데이터를 시리얼 모니터가 읽어옴
  }

*/