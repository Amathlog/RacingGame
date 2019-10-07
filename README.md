# Racing game
This is a remake of the CarRacing environment included in Gym for Reinforcement Learning, in C++ using SDL2 and Box2d

## Build

### Linux
First be sure to install cmake, sdl2 and g++.
```bash
git clone https://github.com/Amathlog/RacingGame.git
cd RacingGame
mkdir build
cd build
cmake ..
make
```

### Windows
Install Visual Studio (tested with VS2017) and CMake.
Assuming cmake and git are in PATH.
```bash
git clone https://github.com/Amathlog/RacingGame.git
cd RacingGame
mkdir build
cd build
cmake ..
```

Then open the Visual Studio solution, set RacingGame as a startup project and hit F5.