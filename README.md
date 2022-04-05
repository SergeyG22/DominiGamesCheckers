### SmartCheckers 
![CI - Windows](https://github.com/SergeyG22/DominiGamesCheckers/actions/workflows/windows_builds.yml/badge.svg)<br>
[![CI - linux](https://github.com/SergeyG22/DominiGamesCheckers/actions/workflows/linux_builds.yml/badge.svg)](https://github.com/SergeyG22/DominiGamesCheckers/actions/workflows/linux_builds.yml)<br>
Not tested under MacOS (no distribution).<br><br>
Сheckers game with artificial intelligence elements.
The players take turns.
The first one who collects a row of nine pieces in the opponent's position wins.<br><br>

### Rules of the game

Choose a chess piece, make a move. The opponent will also make a move. 
The winner is the one who puts all nine chess pieces on the opponent's position.

### Installing dependencies

Python interpreter and the Conan package manager must be installed.
CMake 3.13 or higher should also be installed.

To install Conan, enter the following command:

```
pip3 install conan 
```

To check that the Conan is installed correctly enter in cmd:

```
conan --version
```

Download the sources and install the required dependencies:

```
git clone https://github.com/SergeyG22/DominiGamesCheckers.git
cd DominiGamesCheckers
cd cmake
conan install ../scripts
```

To switch between Debug and Release builds:

```
cd cmake
conan install -s build_type=Debug ../scripts 
```
```
cd cmake
conan install -s build_type=Release ../scripts 
```

### Building from source

```
cd DominiGamesCheckers
mkdir build
cd build
cmake ..
```

### Keyboard control

```
 [W] - move up
 [S] - move down
 [A] - move left
 [D] - move right
```

### Mouse control

```
 [left mouse button] - select a shape
```

### Preview
![hippo](https://github.com/SergeyG22/DominiGamesCheckers/blob/main/doc/animations/animation.gif)
