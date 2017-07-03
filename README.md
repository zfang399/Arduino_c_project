# Arduino_c_project
Xiangyu Dong , Zhaoyuan Fang <br />
EE 10114 <br />
Professor Fuja <br />
March 24th, 2017 <br />
EE 10114 Project Report <br />
Executive Summary <br />
Our group plans to build a simple horizontal version game with the arduino kit, LCD, piezo, potentiometer and button switch. In the game, users can use a button to control the movement of a digital figure that appears on the screen, to either jump up or down to avoid blocks coming to the figure. Functions such as sound (piezo), speed control (potentiometer) and score display (LCD) are included. The game is interactive and easy-to-play. 
 
Background <br />
Motivation: <br />
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
1. Button switch: The button switch is used to start the game and to ask the figure to jump. By attaching an interrupt of button to the program, we can make change to the display efficiently whenever the button is pushed. 
2. Potentiometer: The potentiometer is used to control the speed of the blocks. At the beginning of the game, the potentiometer is used to adjust the speed of the game, shown by the number of illuminating blocks on the LCD. By connecting the potentiometer to one of the analog input, we can then map the value of analogRead to the interval of the speed. 
Actuators/output:
1. Piezo: Though the piezo can be used both as an actuator and a sensor, we are only using its function as an actuator. In the program, the piezo is virtually connected to the button by an interrupt. Whenever the button is pressed (i.e. the figure jumps up or down), the piezo will make a sound accordingly. When the game ends, similarly, the piezo will also make a sound to mark that.
2. LCD (Liquid Crystal Display): LCD is an important component of our design. The LCD pins are connected to some pins on arduino board. All changes (i.e. graphical progress, figure movement, score display, game speed, etc) are all delivered to the user through the 2*16 screen.
The following is a diagram of our circuit:

Diagram drawn using fritzing (http://fritzing.org/home/) 
Description and Justification of hardware:
The LCD wire connection: 1-GND, 2-5V rail, 3-digital pin 12, 4-digital pin 11, 5-digital pin 10, 6-digital pin 7, 11-digital pin 6, 12-digital pin 5, 13-digital pin 4, 14-digital pin 3, 15- 220Ω resistor and 5V rail, 16-GND. The LCD is thus connected to the arduino uno, and is now able to display the information passed by the program uploaded to the uno.
The button switch: connected to digital pin 2 and the ground respectively. When digital pin 2 senses the falling in voltage (the button is pushed so it is connected to the ground), the program knows.
The piezo: connected to digital pin 7 and the ground respectively. Digital pin 7 is a PWM pin so when the program sets different tones and pin 7 gives different duty cycles, resulting in the different tones of piezo.
The potentiometer: The side potentiometer with two feet is connected to the 5V rail and the ground respectively, and the side with one foot is connected to analog pin A0, which reads the value of voltage across part of the potentiometer and maps it to 0-1023.
 
Software
1. adjustSpeed() receives no value and passes no value. This function reads in the value of volts determined by the potentiometer, and use a map function to map the value to a range between 1 and 16  to determine the speed of the coming blocks. It is later shown on the screen by another function. 
2. initializeGraphics() receives no value and passes no value. This function uses an array to store the appearances of digital figures under different positions and the terrains. The appearances and the terrains are represented by a combination of little grids of the LCD board. The function also includes two for loops to initialize the terrain and stores the appearances to the LCD board. 
3. advanceTerrain() receives two parameters, char* terrain and byte newTerrain. Moves the blocks in the background to the next frame.
4. drawHero() receives four parameters, byte position, char* terrainUpper, char* terrainLower, unsigned int score and returns a boolean value. The function uses a switch to determines the position of the figure. The function uses two if statement to decide if the figure collides with the blocks by checking if the figure’s position is the same as the block’s position.The function also changes the length of the display of the upper row of the screen as the score grows and digits increase. Finally, the function draws the figure on the screen based on its position.
5. buttonPush() receives and passes no parameters. This is used together with the attachInterrupt command. The function sets buttonPushed to true.
 
In the setup() function, an attachInterrupt function is added to change the mode of button to true when volts on digital pin 2 falls. The setup function also initialize the graphics and set up the LCD screen.
 
In the loop() function, the outer if statement checks if the game begins. If the game doesn’t start yet, the LCD screen prints “Choose Speed” and uses adjustSpeed function to let the user choose the speed of game. When the speed is chosen, a for loop is used to draw the indicator of the speed on the second row of the LCD board. After the user has chosen the speed, an if statement is used to check if the user presses the button to start the game. When the program is running out of background blocks, it randomely generates new blocks. When the button is pressed, the graphics is initialized again and the figure is set to running mode on the lower row. Then, advanceTerrain function is called to shift the terrain to the left. If the duration of blocks coming from the right is zero, an if statement checks if the new terrain type is empty. If it is empty, randomly choose a duration of blocks between 2 and 10 on either the upper row or the lower row. Else, set the new terrain type to empty and set the duration of it between 10 and 20. Next, check if the button is pressed, if it is pressed, the piezo makes a quick noise. If the figure collides with the blocks, the piezo makes a noise and ends the game. Otherwise, the figure keeps running by animation of the running positions. At the end of the loop function, delay(SPEED) is added to set the speed of the game.

 
 
Design Post-Mortem

We somehow overestimated the quality of LCD display, and it turns out that we have to stay close to the screen to detect what is going on. In addition, We intended to show the scores after each death, and return to the starting state whenever the button is pressed. However, after many attempts modifying the codes, this is hard to achieve because it will mess up one of the most important parameters [buttonPushed]. As an alternative, we chose to display the scores for five seconds. This change is more of a forced option. If possible, we would try to implement this part, to make it more user-friendly. 
The most interesting feature we have in this project is the tunable speed mode. This feature gives players choices to try different levels of difficulties. 
We think the most difficult part of our project is the part to display the scores. Since it is hard to convert the exact frames passed to the score which is much smaller than the number of frames, we need to coordinate the parameters and be really careful when passing values from function to function. Fortunately, we eventually made all the parameters uniform.
If we do this project again, something to add to our current features may be a function to adjust the brightness of the LCD screen so that players can see easily both during day and night. Furthermore, we would want to improve the program overall to make it more efficient so the user actually see a better effect of animation.
