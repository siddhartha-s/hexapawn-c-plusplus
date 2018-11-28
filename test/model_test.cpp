#include "model.h"
#include <catch.h>

using namespace hexapawn;

TEST_CASE("Testing the constructor for Model")
{
    Model q(3,4);

    std::vector<std::vector<Player>> board = q.get_board();

    CHECK(Player::second == board[0][0]);
    CHECK(Player::second == board[0][1]);
    CHECK(Player::second == board[0][2]);
    CHECK(Player::second == board[0][3]);
    CHECK(Player::neither == board[1][0]);
    CHECK(Player::neither == board[1][1]);
    CHECK(Player::neither == board[1][2]);
    CHECK(Player::neither == board[1][3]);
    CHECK(Player::first == board[2][0]);
    CHECK(Player::first == board[2][1]);
    CHECK(Player::first == board[2][2]);
    CHECK(Player::first == board[2][3]);

    CHECK(q.get_turn() == Player::first);
    CHECK(q.get_winner() == Player::neither);
}

void func1()
{
    Model m(1,2);
}

void func2()
{
    Model m(9,9);
}

TEST_CASE("Testing edge cases for constructor for Mode")
{
    CHECK_THROWS_AS(func1(), std::logic_error);
    CHECK_THROWS_AS(func2(),std::logic_error);
}

TEST_CASE("Testing rotate()")
{
    Model x(3,4);

    x.rotate();

    std::vector<std::vector<Player>> board = x.get_board();

    CHECK(Player::first == board[0][0]);
    CHECK(Player::first == board[0][1]);
    CHECK(Player::first == board[0][2]);
    CHECK(Player::first == board[0][3]);
    CHECK(Player::neither == board[1][0]);
    CHECK(Player::neither == board[1][1]);
    CHECK(Player::neither == board[1][2]);
    CHECK(Player::neither == board[1][3]);
    CHECK(Player::second == board[2][0]);
    CHECK(Player::second == board[2][1]);
    CHECK(Player::second == board[2][2]);
    CHECK(Player::second == board[2][3]);

}

TEST_CASE("Testing Other Player(): Pass case")
{
    CHECK(other_player(Player::first) == Player::second);
    CHECK(other_player(Player::second) == Player::first);
}

TEST_CASE("Testing Other Player(): Fail case")
{
    CHECK_THROWS_AS(other_player(Player::neither),ge211::Client_logic_error);
}

TEST_CASE("Testing get_cell()")
{
    Model q(3,4);
    CHECK(Player::second == q.get_cell(0,0));
    CHECK(Player::neither == q.get_cell(1,0));
    CHECK(Player::first == q.get_cell(2,3));
}

TEST_CASE("Testing 3x3 game"){

    Model q(3,3);
    posn chosen = q.selected();
    CHECK(-1 == chosen.x);
    CHECK(-1 == chosen.y);


    q.select_pawn(1,1);
    chosen = q.selected();
    CHECK(-1 == chosen.x);
    CHECK(-1 == chosen.y);

    q.select_pawn(0,0);
    chosen = q.selected();
    CHECK(-1 == chosen.x);
    CHECK(-1 == chosen.y);

    q.select_pawn(2,1);
    chosen = q.selected();
    CHECK(2 == chosen.x);
    CHECK(1 == chosen.y);

    q.place_pawn(0,0);
    CHECK(q.get_cell(0,0)!=Player::first);

    q.place_pawn(1,0);
    CHECK(q.get_cell(1,0)!=Player::first);

    q.place_pawn(1,1);
    CHECK(q.get_cell(1,1)==Player::first);
    chosen = q.selected();
    CHECK(-1 == chosen.x);
    CHECK(-1 == chosen.y);
    CHECK(q.get_turn()!=Player::first);
    CHECK(q.get_turn()==Player::second);
    CHECK(q.get_winner()==Player::neither);

    //board rotates on change of turn
    CHECK(q.get_cell(1,1)==Player::first);
    CHECK(q.get_cell(0,0)==Player::first);
    CHECK(q.get_cell(2,2)==Player::second);

    q.select_pawn(2,2);
    chosen = q.selected();
    CHECK(2 == chosen.x);
    CHECK(2 == chosen.y);

    q.place_pawn(2,2);
    chosen = q.selected();
    CHECK(-1 == chosen.x);
    CHECK(-1 == chosen.y);
    CHECK(q.get_turn()==Player::second);
    CHECK(q.get_winner()==Player::neither);

    q.select_pawn(2,2);
    chosen = q.selected();
    CHECK(2 == chosen.x);
    CHECK(2 == chosen.y);
    q.place_pawn(1,2);
    chosen = q.selected();
    CHECK(-1 == chosen.x);
    CHECK(-1 == chosen.y);
    CHECK(q.get_cell(1,0)==Player::second); //this is true because the turn changes and the board rotates
    CHECK(q.get_turn()==Player::first);
    CHECK(q.get_winner()==Player::neither);

    CHECK(q.get_cell(0,2)==Player::second);
    CHECK(q.get_cell(1,1)==Player::first);

    CHECK(-1 == chosen.x);
    CHECK(-1 == chosen.y);
    q.select_pawn(1,1);
    chosen = q.selected();
    CHECK(1 == chosen.x);
    CHECK(1 == chosen.y);
    q.place_pawn(0,2);
    chosen = q.selected();
    CHECK(-1 == chosen.x);
    CHECK(-1 == chosen.y);
    CHECK(q.get_turn()==Player::neither);
    CHECK(q.get_winner()==Player::first);

}

TEST_CASE("3x3 game - Game detects no legal moves, previous player wins.")
{
    Model q(3,3);

    CHECK(Player::first == q.get_turn());
    q.select_pawn(2,0);
    q.place_pawn(1,0);

    CHECK(Player::second == q.get_turn());
    q.select_pawn(2,1);
    q.place_pawn(1,1);

    CHECK(Player::first == q.get_turn());
    q.select_pawn(2,2);
    q.place_pawn(1,2);

    CHECK(q.get_turn()== Player::neither);
    CHECK(q.get_winner() == Player::first);
}







