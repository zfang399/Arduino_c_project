# Arduino_c_project
Xiangyu Dong , Zhaoyuan Fang
EE 10114
Professor Fuja
March 24th
EE 10114 Project Report
Executive Summary
Our group plans to build a simple horizontal version game with the arduino kit, LCD, piezo, potentiometer and button switch. In the game, users can use a button to control the movement of a digital figure that appears on the screen, to either jump up or down to avoid blocks coming to the figure. Functions such as sound (piezo), speed control (potentiometer) and score display (LCD) are included. The game is interactive and easy-to-play. 
 
Background
Motivation:
The game we are making changes to is very similar to the popular parkour games that can be easily found in an app store. Although with limits of the length of the LCD screen, it is still exciting to change a plain LCD board into a playground. Played under a normal speed, the game is a good way to kill boring time; played under a high speed, the game can bring great excitement as it challenges a player’s cooperation of eyes and hands. It also integrates sounds and score display, which add more fun to the game.
Attribution:
Our idea comes from an online project, which implements the basic gist of the game --- jumping, avoiding blocks, and showing the score. After understanding the logic of the game, we decided to make the following changes to the game, in order to make the game more player-friendly and interesting.
1.     Sound --- We would like to incorporate the sound into the game. When the button is pressed, the piezo will make a sound of jumping. When the figure collides with a block, the piezo will make a different sound simulating the collision.
2.     User-controlled speed --- At the beginning of the game, we want the player to choose the speed of the blocks coming to the figure. The player can choose from a range of number by turning the knob on the potentiometer. The current speed relative to the max speed is reflected by the number of illuminating LCD blocks. This function will make the game more interesting and friendlier to the player.
3.     Highest score --- The player will be able to compare his score with the highest score he has ever achieved. When the user breaks his own record and set a new score, the arduino will play a “twinkle twinkle little star” to congratulate the user.
Environmental Scan
There are some devices like ours existing in the marketplace, but most of them are embedded in a much more complicated product. For example, the T-Rex Game of Chrome (appears when the Google browser is disconnected to the Internet) is similar to our design.
 
Functional Description and Product Operation
In the game, a digital figure appears on the screen, and users can use a button to control the movement of the person to jump up or down to avoid blocks coming to the figure. Before the game starts, the user can turn the potentiometer to adjust the speed of the blocks coming to the figure. To start the game, the user simply needs to press the button. When the game starts, blocks with random length will come to the user. To avoid running into the blocks, the user presses the button, and the position of the digital figure will change accordingly, jumping up or down. Meanwhile the button is pressed, the piezo will make a sound to make the jump more vivid. On the upper right hand corner of the LCD screen, the user’s current score will be displayed. If the figure collides into the blocks, the game is over. At the same time of collision, a piezo will make a beep, and the LCD will display the final screen, showing the score of this round the and highest score the player has achieved. After several seconds, the game will return to the initial state. From there, the game is restarted and the user can choose  to play again. 
 
Hardware
Sensors/input:
Button switch: The button switch is used to start the game and to ask the figure to jump. By attaching an interrupt of button to the program, we can make change to the display efficiently whenever the button is pushed. 
Potentiometer: The potentiometer is used to control the speed of the blocks. At the beginning of the game, the potentiometer is used to adjust the speed of the game, shown by the number of illuminating blocks on the LCD. By connecting the potentiometer to one of the analog input, we can then map the value of analogRead to the interval of the speed. 
Actuators/output:
Piezo: Though the piezo can be used both as an actuator and a sensor, we are only using its function as an actuator. In the program, the piezo is virtually connected to the button by an interrupt. Whenever the button is pressed (i.e. the figure jumps up or down), the piezo will make a sound accordingly. When the game ends, similarly, the piezo will also make a sound to mark that.
LCD (Liquid Crystal Display): LCD is an important component of our design. The LCD pins are connected to some pins on arduino board. All changes (i.e. graphical progress, figure movement, score display, game speed, etc) are all delivered to the user through the 2*16 screen.
The following is a diagram of our circuit:

Diagram drawn using fritzing (http://fritzing.org/home/) 
Description and Justification of hardware:
The LCD wire connection: 1-GND, 2-5V rail, 3-digital pin 12, 4-digital pin 11, 5-digital pin 10, 6-digital pin 7, 11-digital pin 6, 12-digital pin 5, 13-digital pin 4, 14-digital pin 3, 15- 220Ω resistor and 5V rail, 16-GND. The LCD is thus connected to the arduino uno, and is now able to display the information passed by the program uploaded to the uno.
The button switch: connected to digital pin 2 and the ground respectively. When digital pin 2 senses the falling in voltage (the button is pushed so it is connected to the ground), the program knows.
The piezo: connected to digital pin 7 and the ground respectively. Digital pin 7 is a PWM pin so when the program sets different tones and pin 7 gives different duty cycles, resulting in the different tones of piezo.
The potentiometer: The side potentiometer with two feet is connected to the 5V rail and the ground respectively, and the side with one foot is connected to analog pin A0, which reads the value of voltage across part of the potentiometer and maps it to 0-1023.
 
Software
adjustSpeed() receives no value and passes no value. This function reads in the value of volts determined by the potentiometer, and use a map function to map the value to a range between 1 and 16  to determine the speed of the coming blocks. It is later shown on the screen by another function. 
 
initializeGraphics() receives no value and passes no value. This function uses an array to store the appearances of digital figures under different positions and the terrains. The appearances and the terrains are represented by a combination of little grids of the LCD board. The function also includes two for loops to initialize the terrain and stores the appearances to the LCD board. 
 
advanceTerrain() receives two parameters, char* terrain and byte newTerrain. Moves the blocks in the background to the next frame.
 
drawHero() receives four parameters, byte position, char* terrainUpper, char* terrainLower, unsigned int score and returns a boolean value. The function uses a switch to determines the position of the figure. The function uses two if statement to decide if the figure collides with the blocks by checking if the figure’s position is the same as the block’s position.The function also changes the length of the display of the upper row of the screen as the score grows and digits increase. Finally, the function draws the figure on the screen based on its position.
 
buttonPush() receives and passes no parameters. This is used together with the attachInterrupt command. The function sets buttonPushed to true.
 
In the setup() function, an attachInterrupt function is added to change the mode of button to true when volts on digital pin 2 falls. The setup function also initialize the graphics and set up the LCD screen.
 
In the loop() function, the outer if statement checks if the game begins. If the game doesn’t start yet, the LCD screen prints “Choose Speed” and uses adjustSpeed function to let the user choose the speed of game. When the speed is chosen, a for loop is used to draw the indicator of the speed on the second row of the LCD board. After the user has chosen the speed, an if statement is used to check if the user presses the button to start the game. When the program is running out of background blocks, it randomely generates new blocks. When the button is pressed, the graphics is initialized again and the figure is set to running mode on the lower row. Then, advanceTerrain function is called to shift the terrain to the left. If the duration of blocks coming from the right is zero, an if statement checks if the new terrain type is empty. If it is empty, randomly choose a duration of blocks between 2 and 10 on either the upper row or the lower row. Else, set the new terrain type to empty and set the duration of it between 10 and 20. Next, check if the button is pressed, if it is pressed, the piezo makes a quick noise. If the figure collides with the blocks, the piezo makes a noise and ends the game. Otherwise, the figure keeps running by animation of the running positions. At the end of the loop function, delay(SPEED) is added to set the speed of the game.

 
 
Design Post-Mortem


We somehow overestimated the quality of LCD display, and it turns out that we have to stay close to the screen to detect what is going on. In addition, We intended to show the scores after each death, and return to the starting state whenever the button is pressed. However, after many attempts modifying the codes, this is hard to achieve because it will mess up one of the most important parameters [buttonPushed]. As an alternative, we chose to display the scores for five seconds. This change is more of a forced option. If possible, we would try to implement this part, to make it more user-friendly. 
The most interesting feature we have in this project is the tunable speed mode. This feature gives players choices to try different levels of difficulties. 
We think the most difficult part of our project is the part to display the scores. Since it is hard to convert the exact frames passed to the score which is much smaller than the number of frames, we need to coordinate the parameters and be really careful when passing values from function to function. Fortunately, we eventually made all the parameters uniform.
If we do this project again, something to add to our current features may be a function to adjust the brightness of the LCD screen so that players can see easily both during day and night. Furthermore, we would want to improve the program overall to make it more efficient so the user actually see a better effect of animation.
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
Appendix
Arduino C Code:
#include <LiquidCrystal.h>
 
#define PIN_BUTTON 2
#define PIN_AUTOPLAY 1
#define PIN_READWRITE 10
#define PIN_CONTRAST 12
 
#define SPRITE_RUN1 1
#define SPRITE_RUN2 2
#define SPRITE_JUMP 3
#define SPRITE_JUMP_UPPER '.'         // Use the '.' character for the head
#define SPRITE_JUMP_LOWER 4
#define SPRITE_TERRAIN_EMPTY ' '      // User the ' ' character
#define SPRITE_TERRAIN_SOLID 5
#define SPRITE_TERRAIN_SOLID_RIGHT 6
#define SPRITE_TERRAIN_SOLID_LEFT 7
 
#define HERO_HORIZONTAL_POSITION 1    // Horizontal position of hero on screen
 
#define TERRAIN_WIDTH 16
#define TERRAIN_EMPTY 0
#define TERRAIN_LOWER_BLOCK 1
#define TERRAIN_UPPER_BLOCK 2
 
#define HERO_POSITION_OFF 0          // Hero is invisible
#define HERO_POSITION_RUN_LOWER_1 1  // Hero is running on lower row (pose 1)
#define HERO_POSITION_RUN_LOWER_2 2  //                              (pose 2)
 
#define HERO_POSITION_JUMP_1 3       // Starting a jump
#define HERO_POSITION_JUMP_2 4       // Half-way up
#define HERO_POSITION_JUMP_3 5       // Jump is on upper row
#define HERO_POSITION_JUMP_4 6       // Jump is on upper row
#define HERO_POSITION_JUMP_5 7       // Jump is on upper row
#define HERO_POSITION_JUMP_6 8       // Jump is on upper row
#define HERO_POSITION_JUMP_7 9       // Half-way down
#define HERO_POSITION_JUMP_8 10      // About to land
 
#define HERO_POSITION_RUN_UPPER_1 11 // Hero is running on upper row (pose 1)
#define HERO_POSITION_RUN_UPPER_2 12 //                              (pose 2)
 
LiquidCrystal lcd(11, 7, 6, 5, 4, 3);
static char terrainUpper[TERRAIN_WIDTH + 1];
static char terrainLower[TERRAIN_WIDTH + 1];
static bool buttonPushed = false;
 
int SPEED;
int Blocks;
int SCORE = 0;
 
void adjustSpeed(){
  SPEED = analogRead(0);
  Blocks = map(SPEED,0,1023,1,16);
  SPEED = 1600/Blocks;
}
 
void initializeGraphics(){
  static byte graphics[] = {
    // Run position 1
    B01100,
    B01100,
    B00000,
    B01110,
    B11100,
    B01100,
    B11010,
    B10011,
    // Run position 2
    B01100,
    B01100,
    B00000,
    B01100,
    B01100,
    B01100,
    B01100,
    B01110,
    // Jump
    B01100,
    B01100,
    B00000,
    B11110,
    B01101,
    B11111,
    B10000,
    B00000,
    // Jump lower
    B11110,
    B01101,
    B11111,
    B10000,
    B00000,
    B00000,
    B00000,
    B00000,
    // Ground
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    // Ground right
    B00011,
    B00011,
    B00011,
    B00011,
    B00011,
    B00011,
    B00011,
    B00011,
    // Ground left
    B11000,
    B11000,
    B11000,
    B11000,
    B11000,
    B11000,
    B11000,
    B11000,
  };
  int i;
  // Skip using character 0, this allows lcd.print() to be used to
  // quickly draw multiple characters
  for (i = 0; i < 7; ++i) {
    lcd.createChar(i + 1, &graphics[i * 8]);
  }
  for (i = 0; i < TERRAIN_WIDTH; ++i) {
    terrainUpper[i] = SPRITE_TERRAIN_EMPTY;
    terrainLower[i] = SPRITE_TERRAIN_EMPTY;
  }
}
 
// Slide the terrain to the left in half-character increments
//
void advanceTerrain(char* terrain, byte newTerrain){
  for (int i = 0; i < TERRAIN_WIDTH; ++i) {
    char current = terrain[i];
    char next = (i == TERRAIN_WIDTH-1) ? newTerrain : terrain[i+1];
    switch (current){
      case SPRITE_TERRAIN_EMPTY:
        terrain[i] = (next == SPRITE_TERRAIN_SOLID) ? SPRITE_TERRAIN_SOLID_RIGHT : SPRITE_TERRAIN_EMPTY;
        break;
      case SPRITE_TERRAIN_SOLID:
        terrain[i] = (next == SPRITE_TERRAIN_EMPTY) ? SPRITE_TERRAIN_SOLID_LEFT : SPRITE_TERRAIN_SOLID;
        break;
      case SPRITE_TERRAIN_SOLID_RIGHT:
        terrain[i] = SPRITE_TERRAIN_SOLID;
        break;
      case SPRITE_TERRAIN_SOLID_LEFT:
        terrain[i] = SPRITE_TERRAIN_EMPTY;
        break;
    }
  }
}
 
bool drawHero(byte position, char* terrainUpper, char* terrainLower, unsigned int score) {
  bool collide = false;
  char upperSave = terrainUpper[HERO_HORIZONTAL_POSITION];
  char lowerSave = terrainLower[HERO_HORIZONTAL_POSITION];
  byte upper, lower;
  switch (position) {
    case HERO_POSITION_OFF:
      upper = lower = SPRITE_TERRAIN_EMPTY;
      break;
    case HERO_POSITION_RUN_LOWER_1:
      upper = SPRITE_TERRAIN_EMPTY;
      lower = SPRITE_RUN1;
      break;
    case HERO_POSITION_RUN_LOWER_2:
      upper = SPRITE_TERRAIN_EMPTY;
      lower = SPRITE_RUN2;
      break;
    case HERO_POSITION_JUMP_1:
    case HERO_POSITION_JUMP_8:
      upper = SPRITE_TERRAIN_EMPTY;
      lower = SPRITE_JUMP;
      break;
    case HERO_POSITION_JUMP_2:
    case HERO_POSITION_JUMP_7:
      upper = SPRITE_JUMP_UPPER;
      lower = SPRITE_JUMP_LOWER;
      break;
    case HERO_POSITION_JUMP_3:
    case HERO_POSITION_JUMP_4:
    case HERO_POSITION_JUMP_5:
    case HERO_POSITION_JUMP_6:
      upper = SPRITE_JUMP;
      lower = SPRITE_TERRAIN_EMPTY;
      break;
    case HERO_POSITION_RUN_UPPER_1:
      upper = SPRITE_RUN1;
      lower = SPRITE_TERRAIN_EMPTY;
      break;
    case HERO_POSITION_RUN_UPPER_2:
      upper = SPRITE_RUN2;
      lower = SPRITE_TERRAIN_EMPTY;
      break;
  }
  if (upper != ' ') {
    terrainUpper[HERO_HORIZONTAL_POSITION] = upper;
    collide = (upperSave == SPRITE_TERRAIN_EMPTY) ? false : true;
  }
  if (lower != ' ') {
    terrainLower[HERO_HORIZONTAL_POSITION] = lower;
    collide |= (lowerSave == SPRITE_TERRAIN_EMPTY) ? false : true;
  }
  
  byte digits = (score > 9999) ? 5 : (score > 999) ? 4 : (score > 99) ? 3 : (score > 9) ? 2 : 1;
  
  // Draw the scene
  terrainUpper[TERRAIN_WIDTH] = '\0';
  terrainLower[TERRAIN_WIDTH] = '\0';
  char temp = terrainUpper[16-digits];
  terrainUpper[16-digits] = '\0';
  lcd.setCursor(0,0);
  lcd.print(terrainUpper);
  terrainUpper[16-digits] = temp;  
  lcd.setCursor(0,1);
  lcd.print(terrainLower);
  
  lcd.setCursor(16 - digits,0);
  lcd.print(score);
 
  terrainUpper[HERO_HORIZONTAL_POSITION] = upperSave;
  terrainLower[HERO_HORIZONTAL_POSITION] = lowerSave;
  return collide;
}
 
// Handle the button push as an interrupt
void buttonPush() {
  buttonPushed = true;
}
 
void setup(){
  pinMode(PIN_READWRITE, OUTPUT);
  digitalWrite(PIN_READWRITE, LOW);
  pinMode(PIN_CONTRAST, OUTPUT);
  digitalWrite(PIN_CONTRAST, LOW);
  pinMode(PIN_BUTTON, INPUT);
  digitalWrite(PIN_BUTTON, HIGH);
  pinMode(PIN_AUTOPLAY, OUTPUT);
  digitalWrite(PIN_AUTOPLAY, HIGH);
  
  // Digital pin 2 maps to interrupt 0
  attachInterrupt(0/*PIN_BUTTON*/, buttonPush, FALLING);
  
  initializeGraphics();
  
  lcd.begin(16, 2);
}
 
void loop(){
  static byte heroPos = HERO_POSITION_RUN_LOWER_1;
  static byte newTerrainType = TERRAIN_EMPTY;
  static byte newTerrainDuration = 1;
  static bool playing = false;
  static bool blink = false;
  static unsigned int distance = 0;
  
  if (!playing) {
    drawHero((blink) ? HERO_POSITION_OFF : heroPos, terrainUpper, terrainLower, distance >> 3);
    if (blink) {
      lcd.setCursor(0,0);
      lcd.print("Choose Speed");
    }
    adjustSpeed();
    lcd.setCursor(0,2);
    char c[15]="";
    for (int i=0;i<=Blocks-1;i++){
      c[i]='*';
    }
    lcd.print(c);
    delay(250);
    blink = !blink;
    if (buttonPushed) {
      initializeGraphics();
      heroPos = HERO_POSITION_RUN_LOWER_1;
      playing = true;
      buttonPushed = false;
      distance = 0;
    }
    return;
  }
 
  // Shift the terrain to the left
  advanceTerrain(terrainLower, newTerrainType == TERRAIN_LOWER_BLOCK ? SPRITE_TERRAIN_SOLID : SPRITE_TERRAIN_EMPTY);
  advanceTerrain(terrainUpper, newTerrainType == TERRAIN_UPPER_BLOCK ? SPRITE_TERRAIN_SOLID : SPRITE_TERRAIN_EMPTY);
  
  // Make new terrain to enter on the right
  if (--newTerrainDuration == 0) {
    if (newTerrainType == TERRAIN_EMPTY) {
      newTerrainType = (random(3) == 0) ? TERRAIN_UPPER_BLOCK : TERRAIN_LOWER_BLOCK;
      newTerrainDuration = 2 + random(10);
    } else {
      newTerrainType = TERRAIN_EMPTY;
      newTerrainDuration = 10 + random(10);
    }
  }
    
  if (buttonPushed) {
    if (heroPos <= HERO_POSITION_RUN_LOWER_2) heroPos = HERO_POSITION_JUMP_1;
    buttonPushed = false;
    tone (9,500);
    delay (50);
    noTone (9);
  }  
 
  if (drawHero(heroPos, terrainUpper, terrainLower, distance >> 3)) {
    distance=distance>>3;
    playing = false; // The hero collided with something. Too bad.
    tone (9,500);
    delay (200);
    noTone (9);
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    byte digits = (distance > 9999) ? 5 : (distance > 999) ? 4 : (distance > 99) ? 3 : (distance > 9) ? 2 : 1;
    lcd.print("Your score ");
    lcd.setCursor(16-digits,0);
    lcd.print(distance);
    if (distance > SCORE) {
      lcd.setCursor(0,1);
      lcd.print("Highest score ");
      byte digits = (distance > 9999) ? 5 : (distance > 999) ? 4 : (distance > 99) ? 3 : (distance > 9) ? 2 : 1;
      lcd.setCursor(16-digits,1);
      SCORE=distance;
      lcd.print(SCORE);
      tone (9,1912);
      delay(500);
      noTone(9);
      delay(100);
      tone (9,1912);
      delay(500);
      noTone(9);
      delay(100);
      tone (9,2864);
      delay(500);
      noTone(9);
      delay(100);
      tone (9,2864);
      delay(500);
      noTone(9);
      delay(100);
      tone (9,3100);
      delay(500);
      noTone(9);
      delay(100);
      tone (9,3100);
      delay(500);
      noTone(9);
      delay(100);
      tone (9,2864);
      delay(500);
      noTone(9);
      delay(500);
      tone (9,2550);
      delay(500);
      noTone(9);
      delay(100);
      tone (9,2550);
      delay(500);
      noTone(9);
      delay(100);
      tone (9,2250);
      delay(500);
      noTone(9);
      delay(100);
      tone (9,2250);
      delay(500);
      noTone(9);
      delay(100);
      tone (9,2028);
      delay(500);
      noTone(9);
      delay(100);
      tone (9,2028);
      delay(500);
      noTone(9);
      delay(100);
      tone (9,1900);
      delay(500);
      noTone(9);
      delay(100);
      delay(3000);
    }
    else {
      lcd.setCursor(0,1);
      lcd.print("Highest score ");
      byte digits = (SCORE > 9999) ? 5 : (SCORE > 999) ? 4 : (SCORE > 99) ? 3 : (SCORE > 9) ? 2 : 1;
      lcd.setCursor(16-digits,1);
      lcd.print(SCORE);
      delay(5000);
    }
  } else {
    if (heroPos == HERO_POSITION_RUN_LOWER_2 || heroPos == HERO_POSITION_JUMP_8) {
      heroPos = HERO_POSITION_RUN_LOWER_1;
    } else if ((heroPos >= HERO_POSITION_JUMP_3 && heroPos <= HERO_POSITION_JUMP_5) && terrainLower[HERO_HORIZONTAL_POSITION] != SPRITE_TERRAIN_EMPTY) {
      heroPos = HERO_POSITION_RUN_UPPER_1;
    } else if (heroPos >= HERO_POSITION_RUN_UPPER_1 && terrainLower[HERO_HORIZONTAL_POSITION] == SPRITE_TERRAIN_EMPTY) {
      heroPos = HERO_POSITION_JUMP_5;
    } else if (heroPos == HERO_POSITION_RUN_UPPER_2) {
      heroPos = HERO_POSITION_RUN_UPPER_1;
    } else {
      ++heroPos;
    }
    ++distance;
    
    digitalWrite(PIN_AUTOPLAY, terrainLower[HERO_HORIZONTAL_POSITION + 2] == SPRITE_TERRAIN_EMPTY ? HIGH : LOW);
  }
  delay(SPEED);
  
}
 
 
