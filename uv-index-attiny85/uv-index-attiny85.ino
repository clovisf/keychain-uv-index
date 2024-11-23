#define guvas12d A3
#define LED 0

int guvaanalog;
int blink;
int onesecond;
int counter;
long oldtime;
long sensorreadingtiming;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  guvaanalog= analogRead(guvas12d);

  if(millis() - sensorreadingtiming > 50){
    sensorreadingtiming= millis();
    if(guvaanalog < 40){
      blink= 0;
    }else if(guvaanalog < 60){
      blink= 1;
    }else if(guvaanalog < 80){
      blink= 2;
    }else if(guvaanalog < 100){
      blink= 3;
    }else if(guvaanalog < 120){
      blink= 4;
    }else if(guvaanalog < 140){
      blink= 5;
    }else if(guvaanalog < 160){
      blink= 6;
    }else if(guvaanalog < 175){
      blink= 7;
    }else if(guvaanalog < 195){
      blink= 8;
    }else if(guvaanalog < 218){
      blink= 9;
    }else if(guvaanalog  < 235){
      blink= 10;
    }else{
      blink= 11;
    }
  }
  

  if(millis() - oldtime > 100){
    oldtime= millis();
    counter++;
    if(counter < (blink*2)){
      digitalWrite(LED, !digitalRead(LED));
    }else{
      onesecond++;
      if(onesecond < 10){

      }else{
        counter= 0;
        onesecond= 0;
      }
    }
  }
  
}
