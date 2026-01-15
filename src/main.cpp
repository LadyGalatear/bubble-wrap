#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_backdrop.h>
#include <bn_color.h>

int main() {
    bn::core::init();

    bn::backdrop::set_color(bn::color(20, 20, 31));

    while(true) {
        if (bn::keypad::a_pressed()) {
            bn::backdrop::set_color(bn::color(31, 20, 20));
        }

        if (bn::keypad::b_pressed()) {
            bn::backdrop::set_color(bn::color(20, 31, 20));
        }

        if (bn::keypad::l_held() && bn::keypad::r_held()) {
            bn::backdrop::set_color(bn::color(5, 5, 5));

            for (int i = 0; i < 60; ++i) {
                bn::core::update();
            }

            bn::backdrop::set_color(bn::color(15, 10, 15));
        }

        bn::core::update();
    }
}