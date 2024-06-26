#include <iostream>
#include <string>

int activePlayer = 1;
std::string word;
bool gameFinished = false;

void printHangman(int wrongGuesses) {
    std::cout << "You have " << wrongGuesses << " errors.\n";

    switch (wrongGuesses) {
        case 0:
            std::cout << " ________\n"
                      << "|        |\n"
                      << "|\n"
                      << "|\n"
                      << "|\n"
                      << "|\n"
                      << "|\n"
                      << "|_________\n\n";
            break;
        case 1:
            std::cout << " ________\n"
                      << "|        |\n"
                      << "|        O\n"
                      << "|\n"
                      << "|\n"
                      << "|\n"
                      << "|\n"
                      << "|_________\n\n";
            break;
        case 2:
            std::cout << " ________\n"
                      << "|        |\n"
                      << "|        O\n"
                      << "|        |\n"
                      << "|\n"
                      << "|\n"
                      << "|\n"
                      << "|_________\n\n";
            break;
        case 3:
            std::cout << " ________\n"
                      << "|        |\n"
                      << "|        O\n"
                      << "|       /|\n"
                      << "|\n"
                      << "|\n"
                      << "|\n"
                      << "|_________\n\n";
            break;
        case 4:
            std::cout << " ________\n"
                      << "|        |\n"
                      << "|        O\n"
                      << "|       /|\\ \n"
                      << "|\n"
                      << "|\n"
                      << "|\n"
                      << "|_________\n\n";
            break;
        case 5:
            std::cout << " ________\n"
                      << "|        |\n"
                      << "|        O\n"
                      << "|       /|\\ \n"
                      << "|       / \n"
                      << "|\n"
                      << "|\n"
                      << "|_________\n\n";
            break;
        case 6:
            std::cout << " ________\n"
                      << "|        |\n"
                      << "|        O\n"
                      << "|       /|\\ \n"
                      << "|       / \\ \n"
                      << "|\n"
                      << "|\n"
                      << "|_________\n\n";
            break;
    }
}

bool checkLetter(char letter, const std::string& word) {
    for (char c : word) {
        if (c == letter) {
            return true;
        }
    }
    return false;
}

void replaceLetters(char letter, const std::string& word, std::string& hiddenWord) {
    for (size_t i = 0; i < word.length(); ++i) {
        if (word[i] == letter) {
            hiddenWord[i] = letter;
        }
    }
}

void SwitchActive() {
    activePlayer = (activePlayer == 1) ? 2 : 1;
}

void WinCase(){
	system("cls");
    std::cout << "\nPlayer " << activePlayer << " has won! The word was: " << word << std::endl;
    gameFinished = true;
}

int main() {
    std::cout << "Type the secret word: ";
    std::cin >> word;
    std::string hiddenWord(word.length(), '_');
    int wrongGuesses = 0;
	system("cls");
    std::cout << "Welcome to the hangman game!\n";
    std::cout << "Suggest a letter for a guess or type 'ENTER' to try to guess the word.\n";
    std::cout << "Guess a letter: " << hiddenWord << std::endl;

    while (!gameFinished) {
        char guess;
        std::string input = "";

        do {
            std::cout << "\nPlayer " << activePlayer << ", insert a letter: ";
            std::cin >> input;

            if(input == "ENTER"){
            	std::cout<<"Guess the word: ";
            	std::string user_guess;
            	std::cin>>user_guess;
            	if(user_guess == word){
            		WinCase();
            		break;
				}else{
					wrongGuesses++;
					std::cout<<"Wrong word!"<<std::endl;
            		printHangman(wrongGuesses);
            		SwitchActive();
				}
			}else if (input.length() == 1) {
                guess = input[0];
                break;
            }else if(input.length() > 1){
                std::cout << "Insert just one letter or type 'ENTER' to attempt a full word guess!\n";
            }
        } while (true);
        
        if(gameFinished) return 0;

        if (checkLetter(guess, word)) {
            replaceLetters(guess, word, hiddenWord);
            std::cout << "You guessed right!\n";
            std::cout << hiddenWord << std::endl;
        } else {
            wrongGuesses++;
            printHangman(wrongGuesses);
            std::cout << "Letter not found!\n";
        }

        if (word == hiddenWord) {
            WinCase();
            break;
        }

        if (wrongGuesses == 6) {
            system("cls");
            std::cout << "\nPlayer " << activePlayer << " has lost! The word was: " << word << std::endl;
            gameFinished = true;
            break;
        }

        SwitchActive();
    }

    return 0;
}

