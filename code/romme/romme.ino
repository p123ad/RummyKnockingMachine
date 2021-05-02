/**
 * Sketch für das Projekt Romme Klopfmaschine
 * 6 Spieler können haben die Taster vor sich um anzukündigen, dass eine Karte "geklopft" 
 * werden soll. Das Programm detektiert den ersten Knopfdruck und lässt die entsprechende LED
 * leuchten, während alle anderen LEDs aus bleiben.
 */
 #include "pitches.h"
 #include "button.h"
 #include "melody.h"

#define PIEZO_PIN A0

//Define Pins for Buttons and Leds
Button buttons[6] = {(2), (3), (4), (5), (6), (7)};
int leds[6] = {8, 9, 10, 11, 12, 13};



// playing a nice melody
// 1 - nice short melody
// 2 - Mario main theme
// 3 - Mario underworld theme
void playMelody(int song){
  if(song == 1) {
    int size = sizeof(simpleMelody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / simpleMelodyTempo[thisNote];
      tone(PIEZO_PIN, simpleMelody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(PIEZO_PIN);
    }
  }

  if(song == 2) {
    int size = sizeof(marioMelody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / marioTempo[thisNote];
      tone(PIEZO_PIN, marioMelody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(PIEZO_PIN);
    }
  }

  if(song == 3) {
    int size = sizeof(marioUnderworldMelody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / marioUnderworldTempo[thisNote];
      tone(PIEZO_PIN, marioUnderworldMelody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(PIEZO_PIN);
    }
  }
}


//all Leds will blink together 3 times for a short moment
void blinkAllLeds(){
  for(int j = 0; j < 4; j++){
    for(int i = 0; i < 6; i++){
      digitalWrite(leds[i], HIGH);
      }
    delay(150);
    for(int i = 0; i < 6; i++){
      digitalWrite(leds[i], LOW);
      }
    delay(150);
  }
}

//led running light
void rotateLeds(int _delay){
  for(int i = 0; i < 6; i++){
    digitalWrite(leds[i], HIGH);
    delay(_delay);
  }
  for(int i = 0; i < 6; i++){
    digitalWrite(leds[i], LOW);
    delay(_delay);
  }
}

void setup() {
  // initialize buttons and led pins
  for(int i = 0; i < 6; i++){
    buttons[6].begin();
    pinMode(leds[i], OUTPUT);
  }

  // Initialization Show
  rotateLeds(100);
  rotateLeds(100);
  playMelody(2);
  blinkAllLeds();
  playMelody(3);

}

void loop() {
// check which button was pressed at first, then do a little winning show
  for(int i = 0; i < 6; i++){
    if(buttons[i].isPressed() == true){
      blinkAllLeds();
      playMelody(1);
      digitalWrite(leds[i], HIGH);
      delay(3000);
      rotateLeds(80);
      rotateLeds(80);
    }
  }
 
}
