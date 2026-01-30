#include <iostream>
#include <cstdlib>
#include <ctime>

bool isValidMove(int userMove, int stones){
    bool check;
    if (userMove < 1 or userMove > 3 or userMove > stones){
        check = false;
    }
    else{
        check = true;
    }
    return check;
}

int getUserMove(int stones){
    bool check = true;
    int userMove;
    while (check){
        std :: cout << "How many stones are you taking?\n";
        std:: cin >> userMove;
        check = isValidMove(userMove, stones);
        if (!check){
            std:: cout << "Invalid amount\n";
            check = true;
        }
        else{
            check = false;
        }
    }
    return userMove;
}

int computerMove(int stones){
    int computerAmount;
    if (stones == 1 || stones == 2){
        computerAmount = 1;
    }
    else if(stones == 3){
        computerAmount = 2;
    }
    else if(stones == 4){
        computerAmount = 3;
    }
    else{
        computerAmount = rand() % 3 +1;
    }
    return computerAmount;
}

bool checkWin(int stones){
    bool check = true;
    if (!stones){
        check = false;
    }
    else{
        check = true;
    }
    return check;
}

int main() {
    int stones = 16;
    bool playGame = true;
    int userMove;
    int computerTurn;
    std:: cout << "Welcome to NIM! The goal of the game is to take the last of the stones." << std::endl << "The pile starts at 16. You may take 1-3 stones at a time. ";

    while (playGame){
        userMove = getUserMove(stones);
        stones = stones - userMove;
        std::cout << "There are " << stones << " stones left.\n";
        if (stones<=0){
            std::cout << "You win!\n";
            break;
        }
        computerTurn = computerMove(stones);
        stones = stones - computerTurn;
        std::cout << "The computer took " << computerTurn << " stones.\n";
        std::cout << "There are " << stones << " stones left.\n";
        if (stones <= 0){
            std::cout << "You lose!\n";
            break;
        }
        playGame = checkWin(stones);
    }
    std::cout << "The game is over. Thank you for playing!\n";

    return 0;
}
