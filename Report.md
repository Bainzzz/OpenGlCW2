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

<img width="1202" height="824" alt="test2" src="https://github.com/user-attachments/assets/7aff6132-be77-41f4-86d4-196ec8675930" />

**Ingame Images**


<img width="1276" height="776" alt="game" src="https://github.com/user-attachments/assets/7e166358-869d-4bec-853c-067f95075dd6" />

<img width="876" height="356" alt="terminal" src="https://github.com/user-attachments/assets/4571db02-3483-493a-80a8-28da18939f52" />

**Game Mechanics and Implementation**

