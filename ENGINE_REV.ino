#include <Servo.h>
//#include <LED_LIGHTS_TOGGLE_CODE>

int KeyParkPin        = 26;
int KeyParkSend       = 27;
int KeyOnPin          = 28;
int KeyOnSend         = 29;          //DIGITAL PINS
int EnginePrimeSend   = 31;
int NeutralPin        = 32;
int NeutralSend           ;
int EngineStartPin    = 34;
int EngineStartSend       ;
int KeepAlivePin      = 35;
int KeepAliveSend;

int EngineRevPin      = 36;           //DIGITAL INPUT SIGNAL
int EngineRevSend     = 11;           //PWM SERVO PIN OUTPUT
Servo EngineRevServo      ;


void setup()
{
  EngineRevServo.attach(EngineRevSend);       //COMMANDING LINK OF SERVO TO PWM

  KeyParkPin, KeyParkSend           = 0;
  KeyOnPin, KeyOnSend               = 0;
  EnginePrimeSend                   = 0;      //SETTING VARIABLE TO ZERO
  NeutralPin, NeutralSend           = 0;
  EngineStartPin, EngineStartSend   = 0;
  EngineRevPin, EngineRevSend       = 0;

  pinMode(KeyParkPin, INPUT);
  pinMode(KeyParkSend, OUTPUT);
  pinMode(KeyOnPin, INPUT);
  pinMode(KeyOnSend, OUTPUT);
  pinMode(EnginePrimeSend, OUTPUT);           //DEFINEING INPUT AND OUTPUT
  pinMode(NeutralPin, INPUT);
  pinMode(EngineStartPin, INPUT);
  pinMode(KeepAlivePin, INPUT);
  pinMode(EngineRevPin, INPUT);
  pinMode(EngineRevPin, OUTPUT);
}

void loop()
{
  while (KeyParkPin == HIGH){digitalWrite(KeyParkSend, HIGH); break;}   //TURN ON THE DASHBOARD

  while (KeyOnPin == HIGH){digitalWrite(KeyOnSend, HIGH); LEDModeSetting == 1; delay(1500); digitalWrite(EnginePrimeSend, HIGH); delay(1500); LEDModeSetting = 3; break;}

  if (NeutralPin == HIGH){digitalWrite(NeutralSend, HIGH);} else (digitalWrite (NeutralSend, LOW));     //NEUTRAL SWITCH

  if (KeepAlivePin == LOW){digitalWrite(KeepAliveSend, LOW);} else (digitalWrite (KeepAliveSend, HIGH));    //KEEP ALIVE

  if (KeepAliveSend == LOW){while (EngineStartPin == HIGH){if (NeutralSend = HIGH)    //TURN ON ENGINE
        { digitalWrite(EngineStartSend, HIGH); LEDModeSetting = 2; delay(1500);
          digitalWrite(EngineStartSend, LOW); LEDModeSetting = 4; break;}}}

  while (EngineRevPin == HIGH){for (int i = 0; i <= 90; i = i + 30){EngineRevServo.write(i);delay(250);}break;}   //REVVING FUNCTION 1/4 THROTTLE
}
