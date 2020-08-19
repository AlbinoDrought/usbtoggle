#define LED_1 2

#define RELAY D5

#define DELAY_NO_SERIAL_DATA 500

bool relayPowered = false;
char command = char(0);

void setup() {
  pinMode(RELAY, OUTPUT);
  pinMode(LED_1, OUTPUT);

  enableRelay();

  Serial.begin(9600);
}

void enableRelay() {
  relayPowered = true;
  digitalWrite(RELAY, LOW);
}

void disableRelay() {
  relayPowered = false;
  digitalWrite(RELAY, HIGH);
}

void loop() {
  if (Serial.available() <= 0) {
    delay(DELAY_NO_SERIAL_DATA);
    return;
  }

  command = char(Serial.read());

  switch (command) {
    case 'E':
      enableRelay();
      break;
    case 'D':
      disableRelay();
      break;
  }

  if (relayPowered) {
    Serial.print('E');
  } else {
    Serial.print('D');
  }
}
