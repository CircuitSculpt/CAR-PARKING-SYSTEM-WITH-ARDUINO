// C++ code
//
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(11, OUTPUT);
}

void loop()
{
  if (0.01723 * readUltrasonicDistance(5, 6) < 30) {
    tone(11, 294, 200); // play tone 50 (D4 = 294 Hz)
    delay(200); // Wait for 200 millisecond(s)
    noTone(11);
  } else {
    if (0.01723 * readUltrasonicDistance(5, 6) < 60) {
      tone(11, 294, 400); // play tone 50 (D4 = 294 Hz)
      delay(800); // Wait for 800 millisecond(s)
      noTone(11);
    } else {
      if (0.01723 * readUltrasonicDistance(5, 6) < 90) {
        tone(11, 294, 600); // play tone 50 (D4 = 294 Hz)
        delay(1500); // Wait for 1500 millisecond(s)
        noTone(11);
      }
    }
  }
}
