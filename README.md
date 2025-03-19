
<img src="./chesstutis_logo.png" alt="Chesstutis Logo" width="200"/>


# Chesstutis

Chesstutis is a UCI C++ chess engine that I am developing as a learning project. The primary goal of this project is to deepen my understanding of chess algorithms and artificial intelligence. I am implementing the minimax algorithm with alpha-beta pruning to evaluate the best possible moves. This project allows me to explore the complexities of game theory and improve my programming skills.

# 1. Choosing A Board Representation
- The first step I will be taking in making this chess engine is choosing a board representation. There are many options to choose from for representing the board. Some common ones are bitboards, and 2D arrays.
- In addition to storing where each piece is located on the board, you also need to to store whos move it is, if either player has castling rights, and keeping track of previous moves for 50-move rule and draw by repitition.
- Each separate board representation will share methods that will be defined in the BoardRepresentation.hpp file

 ### Bitboards
 - 

# 2. Move Generation
- Rules of chess (movement, capturing, castling, en passant, promotion)
- Turn management
- Move validation and legality checks

# 3. Board Evaluation
- Heuristics for evaluating board positions
- Piece values and positional advantages
- Evaluation functions and scoring

# 4. Minimax Algorithm
- Implementation of the minimax algorithm
- Alpha-beta pruning optimization
- Depth control and iterative deepening
- Move ordering and search enhancements
- Performance considerations and optimizations
- Example of minimax in action
- Testing and debugging the algorithm
- Future improvements and enhancements
- Integration with the overall chess engine
- Handling special cases and edge scenarios
- Comparison with other search algorithms
- Practical applications and use cases
- Challenges and limitations
- Resources for further learning
# Resources

[simple minimax for chess](https://www.freecodecamp.org/news/simple-chess-ai-step-by-step-1d55a9266977/)

[C++ chess engine](https://ameye.dev/notes/chess-engine/)

[Chess Programming Wiki](https://www.chessprogramming.org/Main_Page)

[The Fascinating Programming of a Chess Engine - Bartek Spitza](https://youtu.be/w4FFX_otR-4?si=H6WCkaijLwwXqMZ7)

[Algorithms Explained – minimax and alpha-beta pruning - Sebastian Lague](https://youtu.be/l-hh51ncgDI?si=zrX8d2f7Ov7V-2IE)

[Coding adventure: Chess - Sebastian Lague](https://youtu.be/U4ogK0MIzqk?si=vrmSiL612RTlVxej)

[Coding Adventure: Making a Better Chess bot - Sebastian Lague](https://youtu.be/_vqlIPDR2TU?si=hVpPM-5AWTl2Fn6t)