### Main Functions and Their Roles:

1. **`limpaTela()`**:
    - Clears the console screen. It calls the `system("CLS")` command which is specific to Windows. For cross-platform compatibility, you might consider using alternative methods.
2. **`retornaPalavraAleatoria()`**:
    - Returns a random word from a predefined list of fruits. It generates a random index to select a word from the array.
3. **`retornapalavraComMascara(int tamanhoDaPalavra)`**:
    - Generates a masked version of the word (e.g., "apple" becomes "_____") based on the word's length. This mask is updated as the user guesses correct letters.
4. **`exibeStatus()`**:
    - Displays the current game status including the masked word, number of remaining attempts, letters that have been guessed, and any messages to the user.
5. **`jogar(int numeroDeJogadores)`**:
    - The core function where the gameplay happens. It handles single-player and multiplayer modes, processes guesses, updates game status, and checks win/lose conditions.
6. **`menuInicial()`**:
    - Provides a start menu for the game where users can choose to start playing, view game information, or exit. It handles user input for these choices.
7. **`main()`**:
    - Initializes the game by seeding the random number generator for better randomness and calls the `menuInicial()` to start the menu.
    
    ### Gameplay Flow:
    
    - The game can be played alone or with another player. In single-player mode, the game selects a random word. In multiplayer, one player enters a word for others to guess.
    - The player guesses letters one by one and can also attempt to guess the entire word.
    - The game tracks the number of guesses and informs the player of correct or incorrect guesses.
    - The game ends either when the player guesses the word correctly or exhausts the allowed number of guesses.
    
    ### Additional Features and Details:
    
    - The game checks if a guessed letter has already been attempted and informs the player.
    - It displays a masked word that reveals letters as correct guesses are made.
    - After the game concludes, it offers options to restart the game or exit.
    
    This program utilizes basic C++ features such as arrays, loops, conditionals, and I/O operations, making it a good example of how to implement simple interactive games. It also includes handling for user input errors and game state updates.
