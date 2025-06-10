# RGBong

## Description
A small pong-based game written in C++ and SFML.

## Gameplay
The game is played by two players controlling a single paddle which changes color depending on which player controls the paddle.
![Gameplay](gameplay.png)

## Usage
### Building
Building is done with CMake. The app needs to be executed with a `font.ttf` file containing a font in the execution directory.

### Controls
The game is played using the A, D keys for player 1 and Left, Right arrow keys for player 2.
- A - Move paddle left (Player 1)
- D - Move paddle right (Player 1)
- Left arrow key - Move paddle left (Player 2)
- Right arrow key - Move paddle right (Player 2)
- Space - Pause the game