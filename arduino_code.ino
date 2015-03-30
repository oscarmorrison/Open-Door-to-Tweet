const int buttonPin = 8;
const int ledPin = 13;
const int speakerPin = 9;

const int toneA =  261;
const int toneB =  329;

int buttonState = 0;

int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
int numTones = 10;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, LOW);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin, HIGH);
    Serial.println("ON");
    beep();
    delay(1000);
  }
}

void beep(){
 for (int i = 0; i < numTones; i++)
  {
    tone(speakerPin, tones[i]);
    delay(50);
  }
  noTone(speakerPin);
}
