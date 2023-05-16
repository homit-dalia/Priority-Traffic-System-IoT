int SOUNDANALOG = A4;

int button1 = 2;
int R1 = 3;
int G1 = 4;

int button2 = 5;
int R2 = 6;
int G2 = 7;

int button3 = 11;
int R3 = 12;
int G3 = 13;

int button4 = 8;
int R4 = 9;
int G4 = 10;

int delay_green = 2000;

int flash_time = 300; // time is double
int siren_threshold = 800;

void setup() {

  pinMode(SOUND, INPUT);
  pinMode(SOUNDANALOG, INPUT);

  pinMode(button1, INPUT);
  pinMode(R1, OUTPUT);
  pinMode(G1, OUTPUT);

  pinMode(button2, INPUT);
  pinMode(R2, OUTPUT);
  pinMode(G2, OUTPUT);

  pinMode(button3, INPUT);
  pinMode(R3, OUTPUT);
  pinMode(G3, OUTPUT);

  pinMode(button4, INPUT);
  pinMode(R4, OUTPUT);
  pinMode(G4, OUTPUT);

  digitalWrite(R1, HIGH);
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  digitalWrite(R4, HIGH);

  delay(1000);
  Serial.begin(9600);
}

void loop() {
  green_light(G1, R1);
  other_lights_red(R1);

  if(button_pressed(button1, 0)){flash_red_green(R1);}
  siren_sound();    
  delay(delay_green);
  siren_sound();
  green_off(G1);

  green_light(G2, R2);
  other_lights_red(R2);

  if(button_pressed(button2, 1)){flash_red_green(R2);}
  siren_sound();
  delay(delay_green);
  siren_sound();
  green_off(G2);

  green_light(G3, R3);
  other_lights_red(R3);

  if(button_pressed(button3, 2)){flash_red_green(R3);}
  siren_sound();
  delay(delay_green);
  siren_sound();
  green_off(G3);

  green_light(G4, R4);
  other_lights_red(R4);

  if(button_pressed(button4, 3)){flash_red_green(R4);}
  siren_sound(); 
  delay(delay_green);
  siren_sound();
  green_off(G4);

}

void siren_sound(){
  for(int i=0; i<50; i++){
    //Serial.println(analogRead(SOUNDANALOG));
    if(analogRead(SOUNDANALOG) > siren_threshold){
            ambulance_detected(G1);
            digitalWrite(G1,HIGH);
            delay(1000);
            digitalWrite(G1,LOW);
            break;
    }
  delay(50);
  }
}
 
void ambulance_detected(int green){
  digitalWrite(green, HIGH);
  int array[4] = {G1, G2, G3, G4};

  for(int i =0; i<4; i++){
    if(array[i] != green){
      digitalWrite(array[i], LOW);
    }
  }
  for(int i=0; i< 50; i++){
    digitalWrite(R1, HIGH);
    digitalWrite(R2, HIGH);
    digitalWrite(R3, HIGH);
    digitalWrite(R4, HIGH);

    delay(flash_time);

    digitalWrite(R1, LOW);
    digitalWrite(R2, LOW);
    digitalWrite(R3, LOW);
    digitalWrite(R4, LOW);

    delay(flash_time);

  }
}

bool button_pressed(int pin, int value){
  buttonState = digitalRead(pin);
  if (buttonState == HIGH){
      button_pressed_count[value]++;
      Serial.println("Button");
      Serial.println(button_pressed_count[value]);
      return true;
  }
  return false;
}

void flash_red_green(int red){

  for(int i=0; i<15; i++){
    digitalWrite(red, HIGH);
    delay(flash_time);
    digitalWrite(red, LOW);
    delay(flash_time);

  }
}

void green_off(int green){
  digitalWrite(green, LOW);
}

void other_lights_red(int current_pin){
    for (int thisPin = 3; thisPin < 14; thisPin+=3) {
      if(thisPin != current_pin)
        digitalWrite(thisPin, HIGH);
  }
}
void red_light(int green, int red){
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
}
void green_light(int green, int red){
  digitalWrite(green, HIGH);
  digitalWrite(red, LOW);
}
