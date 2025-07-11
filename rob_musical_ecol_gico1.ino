const int Button1 = 2; // Pino do primeiro Botão
const int Button2 = 3; // Pino do segundo Botão
const int Buzzer = 4; // Pino do buzzer

int song1[] = {262, 294, 330, 349,
               392, 440, 494, 523}; // Frequências para a primeira música
int song2[] = {392, 440, 494, 523, 
               587, 659, 698, 784}; // Frequências para a segunda música

void setup() {
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  int touchValue1 = digitalRead(Button1);
  int touchValue2 = digitalRead(Button2);

  if (touchValue1 == HIGH) {
    playSong(song1);
    delay(100);
  }

  if (touchValue2 == HIGH) {
    playSong(song2);
    delay(100);
  }
}

void playSong(int song[]) {
  int songLength = 8;

  for (int i = 0; i < songLength; i++) {
    int noteDuration = 500;
    tone(Buzzer, song[i], noteDuration);
    delay(noteDuration);
    noTone(Buzzer);
  }
}
