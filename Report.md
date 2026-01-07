# OpenGlCW2
**Gameplay**

*My OpenGL project is a simple time based shooter where the player must aim at the targets, using the mouse, and then use left click to shoot at them and gain score. After shooting at the target it will dissapear to which another target will spawn in, ensuring 5 targets are on screen at all times. the player can also move aorund the stage using WASD, The goal of the game is for the player to try to obtain the highest score they can within a minute, the project serving as a bit of competitive fun as well as a simple little aim warmup game. After a minute has passed the player will be unable to shoot or move and must pres ESC to close the game, on the terminal the player's score will be displayed so they can return to try beat their score.*

**Dependencies Used**
*the project uses only approved external libraries as specified in the module guidlines, these include;*
* *GLFW for window creation and input handling*
* *GLAD for loading OpenGL core fucntions*
* *GLM for vector and matrix mathematics*

*also, the project takes use of lots of standard C++ headers which include;*
* \<iostream\>  
* \<vector\>
* \<string\>
* \<fstream\>
* \<sstream\>

**AI Implementation**
 
*AI, Grok, was used extensively throughout the development of this coursework, it initially took a similar role as CW1, providing as a means for debugging, finding simple errors in my code and acting as a learning tool, but as development continued I ended up relying on the tool a lot more, using Grok to generate solutions for bugs, such as for my shooting mechanic, where pressing the left click would just destroy all targets, after using AI, i was able to quickly find the fix for this bug and then continue developement on other features, however as I continued to use AI for generating solutions I found my own code was harder and harder to follow which led to me relying on the tool even more, so I decided to stop development a bit sooner as to ensure I wasn't just blindly following AI for the rest of the project as I still wanted the work to be my own*

*The best thing AI did was keep me on task however, after developing a feature, I would tell grok to which I would receive the next task to get on with, this was very useful as I was able to effectively stay organised and save myself lots of time, This led to me getting an effective project done in a reasonable amount of time. 

*In summary AI was mainly used for:*
* *Code debugging*
* *Bug Fixing*
* *Teaching tool*
* *Guide to keep me on track*
* *Shader Writing*

**Test Cases**

<img width="1252" height="1002" alt="TEst 3" src="https://github.com/user-attachments/assets/e95c04b4-a537-4f80-93a2-5c70ca399440" />




**Ingame Images**

*screenshot of the game and terminal scoring system, yellow boxes are the targets, player must shoot, the player walks on the gray floor* 


<img width="1276" height="776" alt="game" src="https://github.com/user-attachments/assets/7e166358-869d-4bec-853c-067f95075dd6" />


*as players shoot the targets the terminal will display if a shot was a miss or a hit, if it was a hit the score will increase by +1*


<img width="876" height="356" alt="terminal" src="https://github.com/user-attachments/assets/4571db02-3483-493a-80a8-28da18939f52" />



**Game Mechanics and Implementation**

*My aim training project utilises simple, classic game mechanics. This keeps the program easy to understand and useful for a bit of quick fun, or a small warmup game before playing something more competitive. These mechanics include:

* *WASD for Movement and mouse movement to look around. Floor collison is achieved by clamping the y position of the camera.*

<img width="400" height="300" alt="movment" src="https://github.com/user-attachments/assets/752c29df-24a1-4617-9a53-e0ac9bef483d" />

* *Left Mouse click for Shooting. The shooting mecahnic utilises simple raycasting where left click fires a ray along the camera.Front, The hit detection uses bounding sphere intersection with a dot-product aim check.*

 <img width="420" height="72" alt="raycast" src="https://github.com/user-attachments/assets/938fea33-5b17-41ed-8224-3371657d2aa7" />

* *Timer. A 60 second countdown is updated each frame using deltaTime*

<img width="710" height="266" alt="time" src="https://github.com/user-attachments/assets/1353d5b3-7b7a-4fdc-90b9-e3626308011b" />

 *When time expires, input is disabled and the final score is printed to the console*

* *Scoring System. The scoring is incremented on succesful hits and printed to the console for feedback*

<img width="400" height="114" alt="feedback" src="https://github.com/user-attachments/assets/a1f33eeb-fb88-4f99-91e0-ba7e203124b2" />

* *Respawning targets. targets respawn at random positions using rand(). Height is randomised vertically. Providing infinite gameplay.*


<img width="1004" height="146" alt="respawn" src="https://github.com/user-attachments/assets/845583b4-477a-4276-9eac-b53946b8d940" />



*1. Game Loop Pattern*
*Application follows a fixed time game loop, seperating input, update and render phases for fram rate independence. The use of deltaTime ensures smooth movement depsite frame rate.*

<img width="300" height="150" alt="deltatime" src="https://github.com/user-attachments/assets/ce5585b0-0c8f-4879-99fb-69414f3e1217" />


*2. Reusable Components*
*game objects are composed of reusable components:*

* *Camera class, in camera.h, encapsulates position, orientation and movement logic*
* *Shader class manages shader loading and uniform setting*
* *Rendering objects such as floor, targets and crosshair use seperate VAO/VBO setups for independent drawing*

*3. Game Over* 
*Game state is controlled by boolean gameOver tag. When the timer reaches zero, gameOver = true, disabling all controls apart from ESC, to allow for the game to be closed.*

<img width="278" height="58" alt="gameover" src="https://github.com/user-attachments/assets/40f00fa4-496d-40d8-8f5b-52f33d3fe0af" />

*4. Targets*
*Targets are allocated in an array, instead of being created or destroyed. When hit a target is just recylcled and has its position updated.*

<img width="392" height="174" alt="target" src="https://github.com/user-attachments/assets/123a737f-10e5-4fe4-b92c-20b5b58f2729" />
