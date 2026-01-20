#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_items_dot.h>
#include <bn_vector.h>
// #include <bn_log.h>

int main()
{
    bn::core::init();

    bn::backdrop::set_color(bn::color(20, 20, 31));

    bn::vector<bn::sprite_ptr, 10> circles = {};
    for (int x = -40; x <= 40; x += 10) {
        bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(x, 40);
        circles.push_back(myCircle);
        // BN_LOG ("x value", x);
    }

    bn::vector<bn::sprite_ptr, 10> rDiagonal = {};
    for (int x = -40, y = 40; x <= 40; x += 10, y -= 10) {
        bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(x, y);
        rDiagonal.push_back(myCircle);
    }

    bn::vector<bn::sprite_ptr, 10> lDiagonal = {};
    for (int x = -40, y = -40; x <= 40; x += 10, y += 10) {
        bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(x, y);
        lDiagonal.push_back(myCircle);
    }

    // bn::sprite_ptr myCircle0 = bn::sprite_items::dot.create_sprite(10, 40);
    // bn::sprite_ptr myCircle1 = bn::sprite_items::dot.create_sprite(-10, 40);
    // bn::sprite_ptr myCircle2 = bn::sprite_items::dot.create_sprite(-30, 40);
    // bn::sprite_ptr myCircle3 = bn::sprite_items::dot.create_sprite(30, 40);

    while (true)
    {
        if (bn::keypad::a_pressed())
        {
            bn::backdrop::set_color(bn::color(31, 20, 20));
        }

        if (bn::keypad::b_pressed())
        {
            bn::backdrop::set_color(bn::color(20, 31, 20));
        }

        if (bn::keypad::l_held() && bn::keypad::r_held())
        {
            bn::backdrop::set_color(bn::color(5, 5, 5));

            for (int i = 0; i < 60; ++i)
            {
                bn::core::update();
            }

            bn::backdrop::set_color(bn::color(31, 20, 31));
        }

        bn::core::update();
    }
}