# U-Can’t Card Game - C++ Project
This project simulates a card game where two players, each taking the role of a Professor, compete against each other. Player 1 is Professor Plagiarist, and Player 2 is Professor Piffle-Paper. The game begins with each Professor drawing the first card from their deck, which is read from respective data files (`plagiarist.txt` and `piffle-paper.txt`). The game proceeds through a series of rounds where players draw and play cards, attacking their opponent's cards and prestige.

## What Does This Project Do?
This project implements a turn-based card game simulation in C++. It reads card data from input files, simulates drawing and playing cards, and handles the interactions between different types of cards and players. The simulation includes:

- Dynamic deck and hand management for each player.
- Simulated coin toss to choose which card to play.
- Different card types with unique behaviors, implemented using polymorphism.
- Attack mechanics where cards reduce the opponent's prestige or the resilience of their cards.
- Game flow control for up to 30 rounds, with conditions for early termination if a player's prestige reaches zero.
- Output messages to track the game state, moves, and results of each action.

## Game Mechanics
### Basic Flow
- **Setup**: Each player has a deck of cards loaded from text files.
- **Starting Hand**: Each player draws the first card from their deck to form their starting hand.
- **Rounds**: The game is played over a maximum of 30 rounds. Each round consists of:
  - Drawing one card into the player's hand (maximum of 2 cards in hand).
  - Choosing a card to play on the table by simulating a coin toss.
  - Using the card to attack the opponent or their cards on the table.
  - Reducing the opponent's prestige or the resilience of their cards based on the attack.
- **End Game**: The game ends if a professor's prestige drops to zero or after 30 rounds. The professor with the highest prestige wins.

### Cards and Attacks
- **Card Types**: Cards can be of different types such as students or admin duties, each with unique behaviors.
- **Attributes**: Cards have power and resilience points. Student cards can attack, reducing the opponent's cards' resilience.
- **Polymorphism**: Different card types behave differently, implemented through a hierarchy of classes.
- **Admin Cards**: Special cards like `Plagiarism Hearing` and `Course Accreditation` have immediate effects on the game.

### Advanced Features
- **Dynamic Memory**: All objects (cards and professors) are stored in dynamic memory using STL containers.
- **Smart Pointers**: Utilise smart pointers to manage dynamic memory and avoid memory leaks.

## File Format
### Card Data Files
- Each line in the data files (`plagiarist.txt` and `piffle-paper.txt`) represents a card.
- Format: `<type> <name> <power> <additional attributes>`

### Seed File
- A file named `seed.txt` contains the seed for the random number generator to ensure reproducible results.

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/AdnanAliMumtaz/The-Winnowing-Game.git
    cd u-cant-card-game
    ```

2. Build the project:
    - Use your preferred C++ build system (e.g., `cmake`, `make`).

3. Run the simulation:
    - Execute the compiled binary.

## Usage
The game starts by displaying a welcome message and proceeds through 30 rounds where players draw and play cards. The game outputs messages for each action, showing the current state and outcomes. The game ends either when a professor's prestige reaches zero or after 30 rounds, declaring the professor with the highest prestige as the winner.
