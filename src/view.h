#pragma once
#include "model.h"
#include <ge211.h>

namespace hexapawn{

    //the radius of each rendered pawn
    int const token_radius = 50;
    //the length or breadth of each tile on the board
    int const tile_dimension = 100;

    // Colors of rendered tokens.
    ge211::Color const first_color       = ge211::Color::medium_red();
    ge211::Color const second_color      = ge211::Color::medium_blue();
    ge211::Color const first_move_color  = first_color.lighten(0.3).fade_out(0.6);
    ge211::Color const second_move_color = second_color.lighten(0.3).fade_out(0.6);
    ge211::Color const white_tile_color        = ge211::Color::white();
    ge211::Color const highlighted_color       = ge211::Color::medium_yellow().fade_out(0.6);
    ge211::Color const blackcolor                   = ge211::Color::black();


    class View
    {
    public:
        /// The view has const& access to the model--it can see it but cannot
        /// change it.
        explicit View(Model const&);

        /// Renders the current state of the model.
        void draw(ge211::Sprite_set&, int mouse_column, int mouse_row) const;

        /// The actual screen dimensions of the required game window.
        ge211::Dimensions screen_dimensions() const;

        /// Converts a logical board position to a physical screen position.
        ge211::Position board_to_screen(ge211::Position) const;

        /// Converts a physical screen position to a logical board position.
        ge211::Position screen_to_board(ge211::Position) const;

    private:
        /// The model.
        Model const& model_;

        /// The sprites.
        ge211::Circle_sprite const player1_token_{token_radius, first_color};
        ge211::Circle_sprite const player2_token_{token_radius, second_color};
        ge211::Circle_sprite const move1_token_{token_radius, first_move_color};
        ge211::Circle_sprite const move2_token_{token_radius, second_move_color};
        ge211::Rectangle_sprite const white_square{{tile_dimension,tile_dimension},white_tile_color};
        ge211::Rectangle_sprite const highlight {{tile_dimension,tile_dimension},highlighted_color};
        ge211::Rectangle_sprite const black_box {{screen_dimensions().width,screen_dimensions().height},blackcolor};
        ge211::Font sans {"sans.ttf", 30};
        ge211::Text_sprite const W1message{"Player 1 wins!", sans};
        ge211::Text_sprite const W2message{"Player 2 wins!", sans};
    };



}