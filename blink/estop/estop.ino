int ledPin = 13;
int buttonPin = 2;
int interval = 1000;
bool isEstopped = true;
bool ledState = true;
bool isBPress = false;
unsigned long previousMillis = millis();

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin,ledState);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool ButtonState=digitalRead(buttonPin); //creates a button state from an input
  if (ButtonState = LOW){ // if the button is pressed, make the button had been pressed to true if it is false and change the estop state
    if (isBPress == false)
      isBPress = true; //changing it to true so the next time it runs through it knows the message to change estop already went through
      isEstopped =! isEstopped;}
  else{ //if the button is not pressed but the button press is true, change it back to false
    if (isBPress == true)
      isBPress = false;} //changes it back to false so that the next time the button is pressed, it will change the estop
      
  if (isEstopped == true){ //keeps LED on if estopped
    ledState = true;
    digitalWrite(ledPin,ledState);}
  else{ //runs blink all other times
    blinkLED();}
}

void blinkLED(){ //causes LED to blink
    if(millis()-previousMillis>interval){ //if time has exceeded the interval
      ledState=!ledState; //make led turn on if off and off if on
      previousMillis=millis(); //resets previous millis to create a new time interval right when the new led state has started
      digitalWrite(ledPin, ledState); //sends to LED
    }}
