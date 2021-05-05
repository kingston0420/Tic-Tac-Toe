#include <iostream>
#include <vector>
#include "play.hpp"

//board postition
std::vector<std::string> board = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
//position to play
int position; 
int player=1;

bool board_filled(){
    for (int i=0; i<board.size(); i++){
        if (board[i]==" "){
            return false;
        }
    }
    return true;
}

void update_board(){
    std::cout << "     |     |      \n";
    std::cout << "  "<<board[0]<<"  |  "<<board[1]<<"  |  "<<board[2]<<"   \n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
    std::cout << "  "<<board[3]<<"  |  "<<board[4]<<"  |  "<<board[5]<<"   \n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
    std::cout << "  "<<board[6]<<"  |  "<<board[7]<<"  |  "<<board[8]<<"   \n";
    std::cout << "     |     |      \n\n";
}

void play_position() {
    std::cout << "Player" << player << "'s turn. Please enter position to play (1~9):";
    std::cin >> position;
    if (position<1 || position>9){
        std::cout << "Invalid input. Make sure input is in range (1~9)\n";
    }
    else if (board[position-1]!=" "){
        std::cout << "Invalid input. This position is already filled\n";
    }
    else{
        if (player == 1){
            board[position-1]= "✖";
            player++;
        }
        else{
            board[position-1]= "⊙";
            player--;
        }
    }
}

void greet(){
    std::cout << "Welcome to the game of Tic-Tac-Toe!\n";
    std::cout << "Press [Enter] to begin: ";
    std::cin.ignore();
    std::cout << "\n";
  
    std::cout << "Player 1) ✖\n";
    std::cout << "Player 2) ⊙\n\n";

    std::cout << "Here's the 3 x 3 grid:\n\n";

    std::cout << "     |     |      \n";
    std::cout << "  1  |  2  |  3   \n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
    std::cout << "  4  |  5  |  6   \n";
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
    std::cout << "  7  |  8  |  9   \n";
    std::cout << "     |     |      \n\n";
}

bool detect_win(){
    if (board[0]!=" " && board[0]==board[1] && board[1]==board[2]){
        return true;
    }
    else if (board[3]!=" " && board[3]==board[4] && board[4]==board[5]){
        return true;
    }
    else if (board[3]!=" " && board[3]==board[4] && board[4]==board[5]){
        return true;
    }
    else if (board[6]!=" " && board[6]==board[7] && board[7]==board[8]){
        return true;
    }
    else if (board[0]!=" " && board[0]==board[3] && board[3]==board[6]){
        return true;
    }
    else if (board[1]!=" " && board[1]==board[4] && board[4]==board[7]){
        return true;
    }
    else if (board[2]!=" " && board[2]==board[5] && board[5]==board[8]){
        return true;
    }
    else if (board[0]!=" " && board[0]==board[4] && board[4]==board[8]){
        return true;
    }
    else if (board[2]!=" " && board[2]==board[4] && board[4]==board[6]){
        return true;
    }
    else{
        return false;
    }
}

void end_game(){
    if (detect_win()){
        if (player == 1){
            player++;
        }
        else{
            player--;
        }
        std::cout << "Player" << player << " has won\n";
    }
    else if (board_filled()){
        std::cout << "Game over. It's a tie\n";
    }
}
