#Hogwarts_0.3
Hogwarts 0.3 is a two-dimensional game developed using Object-Oriented Programming (C++) that has an interactive interface and a quest for the participant.

The game is built using an external graphics library called "Simple DirectMedia Layer (SDL)" .
The project includes SDL2, SDL2_image-2.0.1, SDL2_mixer-2.0.0, and SDL_ttf-2.20.0, used for involving graphics and audio in the game. 
These libraries are implemented in C++ program source files such as: 
Game.h, Game.cpp, main.cpp, map.h, map.cpp, ECS.cpp, Audio.h, UILabel.h, textureManager.h, textureManager.cpp, and many more.

##Links
SDL2 : "https://github.com/libsdl-org/SDL/releases/tag/release-2.24.0"
SDL2_image-2.0.1: "https://github.com/libsdl-org/SDL_image/releases"
SDL2_MIXER-2.0.0: "https://github.com/libsdl-org/SDL_mixer/releases"
sdl_ttf-2.20.0: "https://github.com/libsdl-org/SDL_ttf/releases"

PLACE THEM IN THE PROJECT DIRECTORY OR ANY OTHER DESIRED DIRECTORIES

##IN MICROSOFT VISUAL STUDIO
Include the Hogwarts_0.3 folder in the project.
Select project properties and set to All Platforms
Place the include files of all the above SDL folders as additional include files in the project properties (C/C++).
Include additional library directories in the linker section of project properties.
Add the additional Dependencies: Name of the .lib files of all the above mentioned SDL directories.
Include .dll (Dynamic Link Library: a type of file that contains instructions that other programs can call upon to do certain things)
files in the the game folder that includes the visual studio solution file.

##Some snippets of the project
![dashboard](https://user-images.githubusercontent.com/83694747/226179358-216b4e1a-f080-438d-a55f-0868d692115f.png)
![instructions](https://user-images.githubusercontent.com/83694747/226179360-0806f06b-7645-4197-90ae-64043e42f830.png)
![level1](https://user-images.githubusercontent.com/83694747/226179361-92683606-ee61-4edb-99eb-363a44a781f7.png)
