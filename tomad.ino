
#define GLOWTIME 5000

int blue1 = D0;
int green1 = D1;
int red1 = D2;

int blue2 = D3;
int green2 = D4;
int red2 = D5;

int blue3 = A0;
int green3 = A1;
int red3 = A2;

int pins[] = {
  red1, green1, blue1,
  red2, green2, blue2,
  red3, green3, blue3
};

/*struct Section{
  int *pins[];
};
Section first = {{red1}};
Section second = {{green2, blue2}};
Section third = {{red3, blue3}};*/

int first[] = {red1, green1};
int second[] = {green2, blue2};
int third[] = {red3, blue3};

void setup()
{
  for (int i = 0; i < sizeof(pins) / sizeof(int); i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i],HIGH);
  }
  Spark.function("activate", activate);
}

void loop(){
}

void turnOn(int section[], int size){
  for (int i = 0; i < size; i++) {
    digitalWrite(section[i],LOW);
  }
  delay(GLOWTIME);
  for (int i = 0; i < size; i++) {
    digitalWrite(section[i],HIGH);
  }
}

int activate(String command) {
    if (command=="first") {
      turnOn(first, 2);
      return 1;
    }
    else if (command=="second") {
      turnOn(second, 2);
      return 2;
    }
    else if (command=="third") {
      turnOn(third, 2);
      return 3;
    }
    else {
      return -1;
    }
}
