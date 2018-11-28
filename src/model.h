#pragma once

#include <ge211.h>

namespace hexapawn{


    //how we decide to represent the 2 players across `board_` or absence thereof.
    enum class Player{
        first, second, neither
    };

    // used to store the logical positons of the selected pawn on the `board_`
    struct posn{
        int x;
        int y;
    };

    /// Returns the other player, if given Player::first or Player::second;
    /// throws ge211::Client_logic_error if given Player::neither.
    Player other_player(Player);

    /// Models a Hexapawn game. The parameters are `m` (the width of the board),
    /// and `n` (the height of the board).

    class Model{

    public:

        explicit Model(int m = 3, int n = 3);

        int m() const { return m_; }
        int n() const { return n_; }
        posn selected() const {return selected_; }

        //used for testing the constructor and rotation
        std::vector<std::vector<Player>> get_board();

        /// Returns Player value at board_[`row_no`][`col_no`]
        ///
        ////// **PRECONDITION:** `col_no < m()`, `row_no <n()`
        const Player& get_cell(int row_no,int col_no) const;


        /// Places the `selected` pawn in the given cell, provided
        /// it's a `legal_move`. If the same cell as the `selected` pawn
        /// is chosen, de-selects the pawn.
        /// **PRECONDITIONS**:
        /// `col_no < m()`, `row_no <n()`
        ///  - `get_column(col_no).size() < n()`
        void place_pawn(int row_no, int col_no);

        /// Selects the pawn chosen by the player, provided the cell is not empty, the pawn is
        /// is the player's pawn and another pawn has not been selected already.
        void select_pawn(int row_no,int col_no);

        /// Checks whether the move chosen by the player is a legal move
        bool legal_move(int row_no,int col_no) const;

        /// Returns whose turn it is, or Player::neither for game over.
        Player get_turn() const { return turn_; };

        /// Returns the winner, or Player::neither when the game is not over.
        Player get_winner() const { return winner_; };

        /// Checks whether row_no and col_no are within the limits of 0<=row_no<m()
        /// and 0<=col_no<n()
        bool is_valid_row_col(int row_no, int col_no);

        /// Rotates `board_` 180 degrees
        void rotate();

    private:
        int m_; //rows of the board
        int n_; //columns of the board

        //contains logical position of selected pawn, if selected. Else -1,-1.
        posn selected_;

        // The current turn;
        Player turn_ = Player::first;

        // The current winner
        Player winner_ = Player::neither;

        //The board
        std::vector<std::vector<Player>> board_;

        /// Updates `winner_` and `turn_` at the end of turn_'s turn.
        /// **PRECONDITION** `col_no` and `row_no` is valid and where the last move
        /// was played.
        void update_winner_and_turn_(int row_no, int col_no);

        /// checks whether a move is available for other_player(turn_)'s pawn at
        /// `row_no`, `col_no` on board
        bool move_available(int row_no,int col_no);

        /// Returns whether there is a pawn at the given position for the current player.
        bool is_good_row_col_(int row_no, int col_no) const;
    };






}

