unsigned int tick,sec=0,minute=0, ms=0, button=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8,INPUT);
  TCCR1A = 0x00; TCCR1B = 0x04;
  TCNT1H = 0x00; TCNT1L = 0x00;
  Serial.print(minute);
  Serial.print(":");
  Serial.print(sec);
  Serial.print(":");
  Serial.println(ms);
}

void start(){
  tick=TCNT1%625;
  if ( tick == 0){
     ms++;
     if ( ms == 100){
        TCNT1 = 0;
        ms = 0;
        sec++;
        if (sec == 60 ){
          sec = 0;
          minute++;  
        }
     }
     Serial.print(minute);
     Serial.print(":");
     Serial.print(sec);
     Serial.print(":");
     Serial.println(ms);
  } 
}

void stop_s(){
  TCNT1 = 0;
  TCCR1B = 0;
  Serial.print("0");
  Serial.print(":");
  Serial.print(sec);
  Serial.print(":");
  Serial.println(ms);
}
void loop() {
  //start();
  //Serial.println(digitalRead(8));
  //button = digitalRead(8);
  //delay(1000);
  button = 1;
  if (minute == 1){
    button =0;  
  }
  if (button == 0){
    stop_s();  
  }else
  {
    start();
  }
  
}
