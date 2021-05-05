#include <iostream>
#include <vector>
#include "play.hpp"

int main() {

    greet();

    while (!board_filled() && !detect_win()){
        play_position();
        update_board();
    }

    end_game();

    return 0;

}