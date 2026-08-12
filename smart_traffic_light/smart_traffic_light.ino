// -------- Traffic Light Pins --------
const int RED_LED = 32;
const int YELLOW_LED = 33;
const int GREEN_LED =25 ;

// -------- HC-SR04 Pins --------
const int TRIG_PIN = 19;
const int ECHO_PIN = 18;

// -------- Traffic Light Timings --------
const int NORMAL_GREEN_TIME = 5000;   // 5 seconds
const int BUSY_GREEN_TIME = 10000;    // 10 seconds
const int YELLOW_TIME = 2000;         // 2 seconds

void setup() {

  // Traffic light LEDs
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  // Ultrasonic sensor
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(115200);
}

float getDistance() {

  // Make sure TRIG starts LOW
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Send ultrasonic pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure time taken by echo
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance in cm
  float distance = duration * 0.0343 / 2;

  return distance;
}

void loop() {

  // -------- Measure Vehicle Distance --------
  float distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // -------- RED OFF, GREEN ON --------
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);

  // Decide green-light duration
  if (distance < 100) {

    // Vehicle detected
    Serial.println("Vehicle detected - BUSY ROAD");

    delay(BUSY_GREEN_TIME);

  } else {

    // No vehicle nearby
    Serial.println("No vehicle detected - NORMAL");

    delay(NORMAL_GREEN_TIME);
  }

  // -------- GREEN OFF, YELLOW ON --------
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);

  delay(YELLOW_TIME);

  // -------- YELLOW OFF, RED ON --------
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, HIGH);

  delay(3000);
}
