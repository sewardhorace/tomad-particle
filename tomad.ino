#define DELAY 5000
#define GLOWTIME 500

int blue1 = D0;
int green1 = D1;
int red1 = D2;

int blue2 = D3;
int green2 = D4;
int red2 = D5;

int blue3 = A0;
int green3 = A1;
int red3 = A2;

int *pins[] = {
  &red1, &green1, &blue1,
  &red2, &green2, &blue2,
  &red3, &green3, &blue2
};

struct Section{
  int isActivated;
  int *pins[3];
};
Section first = {0, {&red1, &green1, &blue1}};
Section second = {0, {&red2, &green2, &blue2}};
Section third = {0, {&red3, &green3, &blue3}};

void setup()
{
  for (int i = 0; i < sizeof(pins) / sizeof(int); i++) {
    pinMode(*pins[i], OUTPUT);
    digitalWrite(*pins[i],HIGH);
  }

  Spark.function("activate", activate);
}

void turnOn(struct Section& section){
  digitalWrite(*section.pins[0],LOW);
}
void turnOff(struct Section& section){
  digitalWrite(*section.pins[0],HIGH);
}

void loop()
{
    if (first.isActivated || second.isActivated || third.isActivated){
      delay(DELAY);
      if (first.isActivated){
        turnOn(first);
      }
      if (second.isActivated){
        turnOn(second);
      }
      delay(GLOWTIME);
      turnOff(first);
      turnOff(second);
      first.isActivated = 0;
      second.isActivated = 0;
      third.isActivated = 0;
    }
}

int activate(String command) {
    if (command=="first") {
      first.isActivated = 1;
      turnOn(first);
      return 1;
    }
    else if (command=="second") {
      turnOn(second);
      second.isActivated = 1;
      return 1;
    }
    else if (command=="third") {
      third.isActivated = 1;
      return 1;
    }
    else {
      return -1;
    }
}
