#include <SoftwareSerial.h>

#define FALSE 0
#define TRUE 1

#define PIN_BUZZER 9
#define PIN_FLEX A0

#define PIN_LCD_TX 2
#define PIN_LCD_RX 3

#define PIN_TIMER_BUTTON 7

#define FLEX_THRESHOLD 75
#define FLEX_TOLERANCE 20

#define GAME_STATE_RUNNING 1
#define GAME_STATE_STOPPED 0

#define ROUND_TIME 60

SoftwareSerial lcd(PIN_LCD_RX, PIN_LCD_TX);

int gameState = GAME_STATE_STOPPED;

int score = 0;
char scoreString[3];

int unflexedPosition;
int readyToRead = FALSE;

int startButtonPressed = FALSE;
unsigned long startTime;
unsigned long elapsedTime;
int secondsRemaining;
char timeString[3];

void setup() {
  lcd.begin(9600);
  delay(500);
  
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_FLEX, INPUT);
  pinMode(PIN_TIMER_BUTTON, INPUT_PULLUP);
  
  lcd.write(254); // Move cursor to...
  lcd.write(128); // ...line 1 position 0
  lcd.write("Time:           "); // clear display
  lcd.write(254); // Move cursor to...
  lcd.write(192); // ...line 2 position 0
  lcd.write("Score:          ");

  unflexedPosition = analogRead(PIN_FLEX) + FLEX_TOLERANCE;

  secondsRemaining = ROUND_TIME;

  // Initialize LCD
  updateTime();
  updateScore();
}

void loop() {
  // Check if the game is running
  if(gameState == GAME_STATE_STOPPED)
  {
    if(digitalRead(PIN_TIMER_BUTTON) == LOW)
    {
      startButtonPressed = TRUE;
    }
    else if(startButtonPressed == TRUE)
    {
      startButtonPressed = FALSE;
      gameState = GAME_STATE_RUNNING;
      startTime = millis();
      secondsRemaining = ROUND_TIME;
      score = 0;
      updateTime();
      updateScore();
      tone(PIN_BUZZER, 1600, 200);
    }
  }
  else if(gameState == GAME_STATE_RUNNING)
  {
    // Update clock
    elapsedTime = millis() - startTime;
    int newSecondsRemaining = ROUND_TIME - (elapsedTime / 1000);
    if(newSecondsRemaining != secondsRemaining)
    {
      secondsRemaining = newSecondsRemaining;
      updateTime();

      if(secondsRemaining == 0)
      {
        tone(PIN_BUZZER, 400, 1000);
        gameState = GAME_STATE_STOPPED;
      }
    }

    // Update score
    int flex = analogRead(PIN_FLEX);
  
    if(flex < unflexedPosition)
    {
      readyToRead = TRUE;
    }
    if(flex > (unflexedPosition + FLEX_THRESHOLD) && readyToRead == TRUE)
    {
      readyToRead = FALSE;
      
      score++;
      updateScore();
      
      tone(PIN_BUZZER, 1200, 200);
    }
  }
}

void updateTime()
{
  lcd.write(254); // Move cursor to...
  lcd.write(134); // ...line 1 position 7
  
  sprintf(timeString, "%2d", secondsRemaining);
  lcd.write(timeString);
}

void updateScore()
{      
  lcd.write(254); // Move cursor to...
  lcd.write(199); // ...line 2 position 8
  
  sprintf(scoreString, "%2d", score);
  lcd.write(scoreString);
}

