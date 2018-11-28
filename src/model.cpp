#include "model.h"
#include <ge211.h>
#include <cassert>
#include<iostream>

namespace hexapawn{


    bool operator==(posn a, posn b){
        return (a.x==b.x and a.y==b.y);
    }

    Player other_player(Player p) {
        switch (p) {
            case Player::first: return Player::second;
            case Player::second: return Player::first;
            default:
                throw ge211::Client_logic_error("other_player: not a player");
        }
    }

    Model::Model(int r, int c)
    : m_(r),n_(c)
    {
        if((m_<3 or m_>8) or (n_<3 or n_>8))
        {
            throw std::logic_error("Beyond bounds of screen");
        }

        for(int i=0; i<m_; i++){
            board_.emplace_back();
            for(int j=0; j<n_;j++){
                if(i==0) {
                    board_[i].push_back(Player::second);
                }
                else if (i==m_-1){
                    board_[i].push_back(Player::first);
                }
                else{
                    board_[i].push_back(Player::neither);
                }

            }
        }

        selected_ = {-1,-1};
    }

    void Model::rotate(){

        for(int i=0;i<m_;i++) {
            for(int j=0,k=n_-1;j<k;j++,k--) {
                std::swap(board_[i][j],board_[i][k]);
            }
        }

        for(int j=0;j<n_;j++) {
            for(int i=0, k=m_-1; i<k; i++, k--) {
                std::swap(board_[i][j],board_[k][j]);
            }
        }
    }

    const Player& Model::get_cell(int row_no, int col_no) const {
        assert(0<=row_no<m_);
        assert(0<=col_no<n_);

        return board_[row_no][col_no];
    }

    bool Model::is_good_row_col_(int row_no, int col_no) const {
        return get_cell(row_no, col_no) == turn_;
    }

    std::vector<std::vector<Player>> Model::get_board() {
        return board_;
    }

    void Model::select_pawn(int row_no, int col_no) {
        if(is_good_row_col_(row_no,col_no)){
            selected_={row_no,col_no};
        }
    }

    void Model::place_pawn(int row_no, int col_no) {

        if (selected_.x == -1 or selected_.y == -1){
            return;
        }
        else if(row_no==selected_.x and col_no==selected_.y){
            selected_ = {-1,-1};
            return;
        }
        else if(legal_move(row_no,col_no)){
            board_[row_no][col_no]=turn_;
            board_[selected_.x][selected_.y]=Player::neither;
            selected_ = {-1,-1};
            update_winner_and_turn_(row_no,col_no);
        }
    }

    bool Model::legal_move(int row_no, int col_no) const {

        if(col_no==selected_.y and row_no == selected_.x-1 and board_[row_no][col_no]==Player::neither){
            return true;
        }
        else if(abs(col_no-selected_.y)==1 and row_no == selected_.x-1 and board_[row_no][col_no]==other_player(turn_)){
            return true;
        }
        else{
            return false;
        }
    }

    void Model::update_winner_and_turn_(int row_no, int col_no) {

        //has turn_ won the game?
        bool turn_won = false;

        for(int i = 0; i<n_; i++){
            if(board_[0][i]==turn_)
                turn_won = true;
        }

        Player opp = other_player(turn_);
        bool opp_has_moves = false;
        for(int i=0; i < m_; i++){
            for(int j = 0; j<n_; j++){
                if(board_[i][j]== opp and move_available(i,j)){
                    opp_has_moves = true;
                    break;
                }
            }
        }

        if (!opp_has_moves or turn_won){
            winner_ = turn_;
            turn_ = Player::neither;
        }
        else
        {
            rotate();
            turn_ = opp;
        }
    }

    bool Model::move_available(int row_no, int col_no) {
        bool can_play = false;

        if (board_[row_no+1][col_no]== Player::neither) {
            can_play = true;
        }
        else if(row_no==0 and board_[row_no+1][col_no+1]==turn_){
            can_play=true;
        }
        else if(row_no==n_-1 and board_[row_no+1][col_no-1]==turn_){
            can_play = true;
        }
        else if(board_[row_no+1][col_no+1]==turn_ or board_[row_no+1][col_no-1]==turn_){
            can_play = true;
        }
            return can_play;
    }

    bool Model::is_valid_row_col(int row_no, int col_no) {
            return 0 <= row_no && row_no < m_ &&
                   0 <= col_no && col_no < n_;
    }

}







