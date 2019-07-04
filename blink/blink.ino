int ledPin = 13;
int ledValue = LOW;
int buttonPin = 2;
int buttonValue = HIGH;
unsigned long currentMillis; //tracks millis
unsigned long previousMillis = 0; //tracks millis
unsigned long interval = 1000; //interval for blinking
unsigned long buttonpress = 0; //stores time button was presse

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

  
void loop() {
buttonValue=digitalRead(buttonPin);//outputs either high or low if button is pressed or not
ledValue=digitalRead(ledPin);
if (buttonValue==LOW){  
  if (blinking==false){
    bool blinking=true;}
  else {
    bool blinking=false; }
}
}
bool blinking(){
    if(currentMillis-previousMillis>interval){
    previousMillis-currentMillis;
    if(ledValue==LOW){
      ledValue=HIGH;}
    else {
      ledValue=LOW;}
  digitalWrite(ledPin, ledValue);
  }
}
