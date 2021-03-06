#pragma once

#include "model.h"
#include "view.h"
#include <ge211.h>

namespace hexapawn{

class Controller : public ge211::Abstract_game{

public:
    explicit Controller(int m = 3, int n = 3);

protected:
    ge211::Dimensions initial_window_dimensions() const override;
    std::string initial_window_title() const override;
    void on_mouse_move(ge211::Position) override;
    void on_mouse_down(ge211::Mouse_button, ge211::Position) override;
    void draw(ge211::Sprite_set&) override;

private:
    Model model_;
    View view_;

    //Logical board column where the mouse was last seen;
    int mouse_column_;

    //Logical board row where the mouse was last seen;
    int mouse_row_;
};
}