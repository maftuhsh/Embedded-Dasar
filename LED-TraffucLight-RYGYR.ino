
// MAFTUH SIROJ HAMDANI
// 2412050

int GREEN = 5;
int YELLOW = 4;
int RED = 3;

int DELAY_GREEN  = 5050;  // menggunakan 2 digit NIM dari belakang
int DELAY_YELLOW = 3050;  // menggunakan 2 digit NIM dari belakang
int DELAY_RED    = 4050;  // menggunakan 2 digit NIM dari belakang


// basic functions
void setup()
{
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
}

void loop()
{
  red_light();
  delay(DELAY_RED);

  yellow_light();
  delay(DELAY_YELLOW);
  
  green_light();
  delay(DELAY_GREEN);

  yellow_light();
  delay(DELAY_YELLOW);
}

void green_light()
{
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
}

void yellow_light()
{
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(RED, LOW);
}

void red_light()
{
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, HIGH);
}