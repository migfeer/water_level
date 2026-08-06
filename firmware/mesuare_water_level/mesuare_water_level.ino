//Vertical level sensors
const int level1 = 6;
const int level2 = 5;
const int level3 = 4;
const int level4 = 3;



void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(level1, INPUT);
  pinMode(level2, INPUT);
  pinMode(level3, INPUT);
  pinMode(level4, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (!digitalRead(level1) && digitalRead(level2) && digitalRead(level3) && digitalRead(level4)){
    Serial.println("25%");
  } 
  if (!digitalRead(level1) && !digitalRead(level2) && digitalRead(level3) && digitalRead(level4))
  {
    Serial.println("50%");
  }
  else if (!digitalRead(level1) && !digitalRead(level2) && !digitalRead(level3) && digitalRead(level4))
  {
    Serial.println("75%");
  }
  else if (!digitalRead(level1) && !digitalRead(level2) && !digitalRead(level3) && !digitalRead(level4))
  {
    Serial.println("100%");
  }

  delay(1000);

}
