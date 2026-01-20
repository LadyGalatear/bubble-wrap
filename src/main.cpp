#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_items_dot.h>

int main()
{
    bn::core::init();

    bn::backdrop::set_color(bn::color(20, 20, 31));

    bn::sprite_ptr myCircle0 = bn::sprite_items::dot.create_sprite(10, 40);
    bn::sprite_ptr myCircle1 = bn::sprite_items::dot.create_sprite(-10, 40);
    bn::sprite_ptr myCircle2 = bn::sprite_items::dot.create_sprite(-30, 40);
    bn::sprite_ptr myCircle3 = bn::sprite_items::dot.create_sprite(30, 40);

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