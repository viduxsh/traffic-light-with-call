int carRed = 4;
int carYellow = 3;
int carGreen = 2;
int pedRed = 9;
int pedGreen = 8;
int button = 0;
int crossTime = 5000;
unsigned long changeTime;

void setup() {
pinMode(carRed, OUTPUT);
pinMode(carYellow, OUTPUT);
pinMode(carGreen, OUTPUT);
pinMode(pedRed, OUTPUT);
pinMode(pedGreen, OUTPUT);
pinMode(button, INPUT);
digitalWrite(carGreen, HIGH);
digitalWrite(pedRed, HIGH);
}

void loop() {
int state = digitalRead(button);
if (state == HIGH && (millis() – changeTime) > 5000) {
changeLights();
}
}

void changeLights() {
digitalWrite(carGreen, LOW); // green off
digitalWrite(carYellow, HIGH); // yellow on
delay(2000); // wait 2 seconds

digitalWrite(carYellow, LOW); // yellow off
digitalWrite(carRed, HIGH); // red on
delay(1000); // wait 1 second till its safe

digitalWrite(pedRed, LOW); // ped red off
digitalWrite(pedGreen, HIGH); // ped green on
delay(crossTime); // wait for preset time period

// flash the ped green
for (int x=0; x<10; x++) {
digitalWrite(pedGreen, HIGH);
delay(250);
digitalWrite(pedGreen, LOW);
delay(250);
}

digitalWrite(pedRed, HIGH);
delay(500);

digitalWrite(carYellow, HIGH); // yellow on
digitalWrite(carRed, LOW); //
delay(1000);

digitalWrite(carGreen, HIGH);
digitalWrite(carYellow, LOW);

changeTime = millis();
}
