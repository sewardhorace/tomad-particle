

int first = 0;
int second = 0;
int third = 0;

int blue1 = D0;
int green1 = D1;
int red1 = D2;

int blue2 = D3;
int green2 = D4;
int red2 = D5;

int blue3 = A0;
int green3 = A1;
int red3 = A2;

void setup()
{

    pinMode(blue1, OUTPUT);
    pinMode(green1, OUTPUT);
    pinMode(red1, OUTPUT);

    pinMode(blue2, OUTPUT);
    pinMode(green2, OUTPUT);
    pinMode(red2, OUTPUT);

    pinMode(blue3, OUTPUT);
    pinMode(green3, OUTPUT);
    pinMode(red3, OUTPUT);

    Spark.function("blink",ledBlink);
    Spark.function("thinking", thinking);


    digitalWrite(red1,HIGH);
    digitalWrite(green1,HIGH);
    digitalWrite(blue1,HIGH);
    digitalWrite(red2,HIGH);
    digitalWrite(green2,HIGH);
    digitalWrite(blue2,HIGH);
    digitalWrite(red3,HIGH);
    digitalWrite(green3,HIGH);
    digitalWrite(blue3,HIGH);
}

void turnOn(String section){
    if (section=="first"){
      digitalWrite(red1,LOW);
    }
    else if (section=="second"){
      digitalWrite(red2,LOW);
    }
}
void turnOff(String section){
    if (section=="first"){
      digitalWrite(red1,HIGH);
    }
    else if (section=="second"){
      digitalWrite(red2,HIGH);
    }
}

void loop()
{
    if (first==1 || second==1 || third==1){
      delay(5000);
      if (first==1){
        turnOn("first");
      }
      if (second==1){
        turnOn("second");
      }
      delay(500);
      turnOff("first");
      turnOff("second");
      first = 0;
      second = 0;
      third = 0;
    }
}

int thinking(String command) {
    if (command=="first") {
      first = 1;
      return 1;
    }
    else if (command=="second") {
      second = 1;
      return 1;
    }
    else if (command=="third") {
      third = 1;
      return 1;
    }
    else {
      return -1;
    }
}



int ledBlink(String command) {

    if (command=="on") {
        digitalWrite(blue1,LOW);
        digitalWrite(green2,LOW);
        digitalWrite(blue3,LOW);
        return 1;
    }
    else if (command=="off") {
        digitalWrite(blue1,HIGH);
        digitalWrite(green2,HIGH);
        digitalWrite(blue3,HIGH);
        return 0;
    }
    else {
        return -1;
    }
}
