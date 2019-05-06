I download the code form "https://arduino.stackexchange.com/questions/31027/how-to-turn-a-led-if-ultranonic-hc-sr04-reading-is-on-defined-range-for-some-int"
#define trigPin 7
#define echoPin 8
#define led 13
#define led2 12

long duration, distance, interval = 4000;
int detection = 0;

void setup() {
   Serial.begin (9600);
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(led, OUTPUT);
   pinMode(led2, OUTPUT);
   detection = millis();
}

void loop() {

   ultraSonic();

   if (distance > 0 && distance < 10 && (millis() - detection >= interval)) {
   digitalWrite(led, HIGH);
   digitalWrite(led2, LOW);
   } else {
   digitalWrite(led, LOW);
   digitalWrite(led2, HIGH);
   }

   Serial.print(millis());
   Serial.print(" - ");
   Serial.println(distance);

   delay(250);
}

void ultraSonic() {
   digitalWrite(trigPin, LOW);
   delayMicroseconds(60);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(60);
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   distance = (duration / 2) / 29.1;
}
