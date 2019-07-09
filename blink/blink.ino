int ledPin = 13;
bool ledValue = LOW;
int buttonPin = 2;
bool buttonValue;
unsigned long currentMillis; //tracks millis
unsigned long previousMillis = 0; //tracks millis
unsigned int interval = 1000; //interval for blinking

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT); //button will have to be an interupt. button bouncing. button held down for a certain amount of time to change state.
}

  
void loop() {
currentMillis=millis();
buttonValue=digitalRead(buttonPin);//outputs either high or low if button is pressed or not- yes is 5V no is 0V
if (buttonValue==LOW){  //if button is pressed
  if (blinking()==false){  //if blinking is off
    bool blinking=true;} // start blinking
  else {
    bool blinking=false; } //stop blinking
}
}
bool blinking(){
    if(currentMillis-previousMillis>interval){
      ledValue=!ledValue;
      previousMillis=millis();
      digitalWrite(ledPin, ledValue);
  }}
