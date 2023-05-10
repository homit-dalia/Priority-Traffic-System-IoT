int SOUND = 1;

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

int delay_red = 5000;
int delay_green = 5000;

int flash_time = 150; // time is double

int buttonState = 0;
int button_prev_state[4];
int button_pressed_count[4];

void setup() {
  pinMode(SOUND, INPUT);

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
}

void loop() {
  
  green_light(G1, R1);
  other_lights_red(R1);
  if(button_pressed(button1, 0)){flash_red_green(R1);}
  // flash_red_green(R1);
  // ambulance_detected(G1);
  delay(delay_green);
  green_off(G1);

  green_light(G2, R2);
  other_lights_red(R2);
  if(button_pressed(button2, 1)){flash_red_green(R2);}
  delay(delay_green);
  green_off(G2);

  green_light(G3, R3);
  other_lights_red(R3);
  if(button_pressed(button3, 2)){flash_red_green(R3);}
  delay(delay_green);
  green_off(G3);

  green_light(G4, R4);
  other_lights_red(R4);
  if(button_pressed(button4, 3)){flash_red_green(R4);}
  delay(delay_green);
  green_off(G4);

}

bool siren_sound(){

}

// void flash_all_red_lights(int dont_flash){
//   int lights[3];
//   int j=0
//   for (int i=1; i < 4;i++){
//       if(dont_flash != i){
//         lights[j] = i
//       }
//   }
//   for(int i=0; i< 50; i++){
//     digitalWrite(red, HIGH);
//   }
// }

void ambulance_detected(int green){
  digitalWrite(green, HIGH);
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
  if (buttonState != button_prev_state[value]){
    if(buttonState != HIGH){
      button_pressed_count[value]++;
      Serial.println("Button");
      Serial.println(button_pressed_count[value]);
      return true;
    }
  }
  return false;
}

void flash_red_green(int red){
  
  for(int i=0; i<30; i++){
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
