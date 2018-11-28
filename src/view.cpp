#include "view.h"
#include<iostream>

namespace hexapawn{

    bool operator!=(posn a, posn b){
        return a.x!=b.x or a.y != b.y;
    }


    View::View(const Model& model)
            : model_(model)
    {
        }

    void View::draw(ge211::Sprite_set &sprites, int mouse_column, int mouse_row) const {

        for(int i=0; i<model_.m();i++) {
            for (int j = 0; j < model_.n(); j++) {

                if ((i + j) % 2 == 0) {
                    auto const& sprite = white_square;
                    sprites.add_sprite(sprite, board_to_screen({j, i}), 1);

                }

                Player cell = model_.get_cell(i, j);

                if (cell == Player::first) {
                    auto const& layer_two = player1_token_;
                    sprites.add_sprite(layer_two, board_to_screen({j, i}), 3);
                } else if (cell == Player::second) {
                    auto const& layer_two = player2_token_;
                    sprites.add_sprite(layer_two, board_to_screen({j, i}), 3);
                }
            }
        }

        posn selected = model_.selected();

        bool is_selected = selected.x != -1 or selected.y != -1;

        if(is_selected){
            sprites.add_sprite(highlight,board_to_screen({selected.y, selected.x}),2);
            if(model_.legal_move(selected.x-1,selected.y)){
                sprites.add_sprite(highlight,board_to_screen({selected.y, selected.x-1}),2);
            }
            if(model_.legal_move(selected.x-1,selected.y-1)){
                sprites.add_sprite(highlight,board_to_screen({selected.y-1, selected.x-1}),2);
            }
            if(model_.legal_move(selected.x-1,selected.y+1)){
                sprites.add_sprite(highlight,board_to_screen({selected.y+1, selected.x-1}),2);
            }
        }


        if(is_selected and model_.legal_move(mouse_row,mouse_column)){

            auto row_no = mouse_row;
            auto col_no = mouse_column;
            Player player = model_.get_turn();

                    if(row_no<model_.m() && col_no<model_.n() && player != Player::neither){
                        auto const& sprite =
                                player == Player::first ? move1_token_ : move2_token_;
                        sprites.add_sprite(sprite, board_to_screen({col_no, row_no}),4);
                    }

        }



          if(model_.get_winner()!=Player::neither) {
            auto const& w_sprite =
                              model_.get_winner()==Player::first? W1message : W2message;
            sprites.add_sprite(black_box, {0, 0}, 5);
            sprites.add_sprite(w_sprite, {0, 0}, 5);

        }
    }

    ge211::Position View::board_to_screen(ge211::Position board_pos) const
    {
        int x = 2 * token_radius * board_pos.x;
        int y = 2 * token_radius * (model_.m() - board_pos.y - 1);
        return {x, y};
    }

    ge211::Position View::screen_to_board(ge211::Position screen_pos) const
    {
        int col_no = screen_pos.x / (2 * token_radius);
        int row_no = model_.m() - screen_pos.y / (2 * token_radius) - 1;
        return {col_no, row_no};
    }


    ge211::Dimensions View::screen_dimensions() const
    {
        return {2 * token_radius * model_.n(),
                2 * token_radius * model_.m()};
    }

}