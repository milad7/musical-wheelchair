// Tone frequencies
#include "pitches.h"

// ATtiny85 pin 3 as PWM for the buzzer
#define melodyPin 3

// Mario main theme melody
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7, 
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0, 

  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 

  NOTE_G6, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0,NOTE_C7, 
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 

  NOTE_G6, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0,NOTE_C7, 
  NOTE_D7, NOTE_B6, 0, 0
};

// Mario main them tempo
int tempo[] = {
  12, 12, 12, 12, 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12, 

  12, 12, 12, 12,
  12, 12, 12, 12, 
  12, 12, 12, 12, 
  12, 12, 12, 12, 

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};


void setup(void)
{
  pinMode(melodyPin, OUTPUT); 
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(4, INPUT);
}

void loop()
{
  // Play melody
  sing();
}

// Play melody
void sing(){      
     int size = sizeof(melody) / sizeof(int);
     for (int thisNote = 0; thisNote < size; thisNote++) {
       int noteDuration = 1000/tempo[thisNote];
       buzz(melodyPin, melody[thisNote],noteDuration);
       // to distinguish the notes, set a minimum time between them.
       // the note's duration + 30% seems to work well:
       int pauseBetweenNotes = noteDuration *1.2;
       delay(pauseBetweenNotes);
       // stop the tone playing:
       buzz(melodyPin, 0,noteDuration);
    }
    
}

void buzz(int targetPin, long frequency, long length) {
  long delayValue = 50000/frequency/1; // calculate the delay value between transitions
  long numCycles = frequency * length/ 1000; // calculate the number of cycles for proper timing
  for (long i=0; i < numCycles; i++){ // for the calculated length of time...
    digitalWrite(targetPin,HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin,LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  led(random(1,15));
  
}

void led(int number) {
  if(number==1){
    pinMode(2, INPUT);
    pinMode(4, INPUT);
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    digitalWrite(1, LOW); 
    digitalWrite(0, HIGH); // LED 1
  }
  else if(number==2){
    pinMode(2, INPUT);
    pinMode(4, INPUT);
    pinMode(0, OUTPUT);
    pinMode(1, OUTPUT);
    digitalWrite(0, LOW); 
    digitalWrite(1, HIGH); // LED 2
  }
  else if(number==3){
    pinMode(0, INPUT);
    pinMode(4, INPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    digitalWrite(2, LOW); 
    digitalWrite(1, HIGH);     
  }
  else if(number==4){
    pinMode(0, INPUT);
    pinMode(4, INPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    digitalWrite(1, LOW); 
    digitalWrite(2, HIGH);    
  }
  else if(number==5){
    pinMode(2, OUTPUT);
    pinMode(1, INPUT);
    pinMode(0, INPUT);
    pinMode(4, OUTPUT);
    digitalWrite(4, LOW); 
    digitalWrite(2, HIGH); 
  }
  else if(number==6){
    pinMode(1, INPUT);
    pinMode(2, OUTPUT);
    pinMode(0, INPUT);
    pinMode(4, OUTPUT);
    digitalWrite(2, LOW); 
    digitalWrite(4, HIGH);   
  }
  else if(number==7){
    pinMode(1, INPUT);
    pinMode(4, INPUT);
    pinMode(0, OUTPUT);
    pinMode(2, OUTPUT);
    digitalWrite(4, LOW);
    digitalWrite(0, HIGH); // LED 7    
  }
  else if(number==8){
    pinMode(1, INPUT);
    pinMode(4, INPUT);
    pinMode(0, OUTPUT);
    pinMode(2, OUTPUT);
    digitalWrite(0, LOW);
    digitalWrite(2, HIGH); // LED 8    
  }
  else if(number==9){
    pinMode(2, INPUT);
    pinMode(1, OUTPUT);
    pinMode(0, INPUT);
    pinMode(4, OUTPUT);
    digitalWrite(4, LOW); 
    digitalWrite(1, HIGH);     
  }
  else if(number==10){
    pinMode(2, INPUT);
    pinMode(1, OUTPUT);
    pinMode(0, INPUT);
    pinMode(4, OUTPUT);
    digitalWrite(1, LOW); 
    digitalWrite(4, HIGH);    
  }
  else if(number==11){
    pinMode(1, INPUT);
    pinMode(0, OUTPUT);
    pinMode(2, INPUT);
    pinMode(4, OUTPUT);
    digitalWrite(4, LOW);
    digitalWrite(0, HIGH);    
  }
  else if(number==12){
    pinMode(1, INPUT);
    pinMode(0, OUTPUT);
    pinMode(2, INPUT);
    pinMode(4, OUTPUT);
    digitalWrite(0, LOW);
    digitalWrite(4, HIGH);    
  }
  else if(number==13){
    pinMode(0, INPUT);
    pinMode(1, OUTPUT);
    pinMode(2, INPUT);
    pinMode(4, OUTPUT);
    digitalWrite(4, LOW);
    digitalWrite(1, HIGH);    
  }
  else if(number==14){
    pinMode(1, INPUT);
    pinMode(0, OUTPUT);
    pinMode(2, INPUT);
    pinMode(4, OUTPUT);
    digitalWrite(4, LOW);
    digitalWrite(0, HIGH);    
  }
  else if(number==15){
    pinMode(1, INPUT);
    pinMode(0, OUTPUT);
    pinMode(2, INPUT);
    pinMode(4, OUTPUT);
    digitalWrite(0, LOW);
    digitalWrite(4, HIGH);    
  }
  else{
    
  }
}

