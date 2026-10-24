/*
  IAMC - Alcohol Detection and Vehicle Interlock (teaching prototype)
  Arduino Uno + MQ-3 analog output
  Outputs: buzzer D8, active-low relay driver D9, status LEDs D5/D6

  SAFETY: This is a classroom prototype, not a certified breathalyzer or
  road-ready vehicle controller. Never connect a microcontroller pin directly
  to a vehicle starter circuit. Use a properly rated isolated automotive
  interface and fail-safe review before any real deployment.
*/
const byte SENSOR_PIN = A0;
const byte GREEN_LED = 5;
const byte RED_LED = 6;
const byte BUZZER_PIN = 8;
const byte RELAY_PIN = 9; // relay module input; active LOW means engine permit
const int TRIP_THRESHOLD = 500; // illustrative ADC threshold; calibrate on hardware
const unsigned long SAMPLE_INTERVAL_MS = 100;
const unsigned long WARMUP_MS = 20000;

unsigned long startedAt;
unsigned long lastSampleAt;
int filteredReading = 0;
bool filterInitialized = false;

void setSafeState() {
  digitalWrite(RELAY_PIN, HIGH); // de-energize active-low relay: inhibit start
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);
  noTone(BUZZER_PIN);
}

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
  setSafeState();
  Serial.begin(9600);
  startedAt = millis();
  Serial.println(F("IAMC alcohol detector - sensor warm-up"));
}

void loop() {
  const unsigned long now = millis();
  if (now - lastSampleAt < SAMPLE_INTERVAL_MS) return;
  lastSampleAt = now;

  const int raw = analogRead(SENSOR_PIN);
  if (!filterInitialized) {
    filteredReading = raw;
    filterInitialized = true;
  } else {
    filteredReading = (filteredReading * 3 + raw) / 4; // light smoothing
  }

  Serial.print(F("raw="));
  Serial.print(raw);
  Serial.print(F(" filtered="));
  Serial.println(filteredReading);

  if (now - startedAt < WARMUP_MS) {
    setSafeState();
    Serial.println(F("WARMUP: start inhibited"));
    return;
  }

  if (filteredReading >= TRIP_THRESHOLD) {
    setSafeState();
    tone(BUZZER_PIN, 2200);
    Serial.println(F("ALCOHOL ABOVE SET THRESHOLD: start inhibited"));
  } else {
    digitalWrite(RELAY_PIN, LOW); // energize active-low relay module: permit start
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    noTone(BUZZER_PIN);
    Serial.println(F("BELOW SET THRESHOLD: start permitted"));
  }
}
