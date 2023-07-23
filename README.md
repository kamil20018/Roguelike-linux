# Roguelike - now linux compatible

I've decided to stop using visual studio on windows and swtiched to vscode on Ubuntu. Now you can easily set up and run my project on most linux distributions.


## Required tools
- cmake
- git
- a package manager of some sorts

## Build and run instructions
1. Run the following command to install the sfml library (assuming that apt is your package manager):
>sudo apt-get install libsfml-dev
2. Clone the project from github
3. Create a `build` folder in the root folder
4. Run the following command:
>cmake -S . -B build
5. Go to the build folder
6. Run the following commands to build the c++ code and run the binary:
>cmake --build .

>./bin/game
7. Hopefully you've managed to run the game