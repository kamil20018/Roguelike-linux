# Roguelike - now linux compatible

I've decided to stop using visual studio on windows and swtiched to vscode on Ubuntu. Now you can easily set up and run my project on most linux distributions.


## Required tools
- cmake
- git
- a package manager of some sorts

## Build and run instructions
1. Clone the project from github
2. Run the following command to install the sfml library (assuming that apt is your package manager):
>sudo apt-get install libsfml-dev
3. Run the following command to build and run the project:
>./run.sh -sa
4. Hopefully you've managed to run the game