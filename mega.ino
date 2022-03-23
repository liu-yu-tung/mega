#define RL1 14
#define RL2 15
#define RL3 16
#define RL4 17
#define RL5 18

int PWMA=34;
int AIN2=35;
int AIN1=36;
int STBY=37;
int BIN1=38;
int BIN2=39;
int PWMB=40;
void MotorWriting(double vL, double vR);
void MotorCheck();
void setup() {
    Serial.begin(9600);
    
    pinMode(RL1, INPUT);
    pinMode(RL2, INPUT);
    pinMode(RL3, INPUT);
    pinMode(RL4, INPUT);
    pinMode(RL5, INPUT);
    
    pinMode(PWMA, OUTPUT);
    pinMode(PWMB, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(STBY, OUTPUT);     // stand by 
    pinMode(LED_BUILTIN, OUTPUT);
    
}

void loop() {
        MotorCheck();
        //MotorWriting(255, -255);
        //delay(450);
        //digitalWrite(STBY, LOW);
        delay(2000);
    
   }
void MotorWriting(double vL, double vR) {
    digitalWrite(STBY, HIGH);
    if(vR >= 0) {
        digitalWrite(AIN1, HIGH);
        digitalWrite(AIN2, LOW);
        analogWrite(PWMA, vR);
       } 
    else {
        digitalWrite(AIN2, HIGH);
        digitalWrite(AIN1, LOW);
        analogWrite(PWMA, -vR);
    }
    if (vL >= 0) {
        digitalWrite(BIN2, HIGH);
        digitalWrite(BIN1, LOW);
        analogWrite(PWMB, vL);
        }    
    else {
        digitalWrite(BIN2, LOW);
        digitalWrite(BIN1, HIGH);
        analogWrite(PWMB, -vL);
    }
}
void MotorCheck() {
    MotorWriting(255, 255);
    delay(2000);
    MotorWriting(-255, -255);
    delay(2000);
    MotorWriting(-255, 255);
    delay(2000);
    MotorWriting(255, -255);
    delay(2000);
    MotorWriting(0, 0);
}
