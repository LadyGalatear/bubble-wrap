#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_items_dot.h>
#include <bn_vector.h>
#include <bn_sprites_mosaic.h>
#include <bn_blending.h>
// #include <bn_log.h>

int main()
{
    bn::core::init();

    bn::backdrop::set_color(bn::color(20, 20, 31));

    bn::vector<bn::sprite_ptr, 10> circles = {};
    for (int x = -40; x <= 40; x += 10)
    {
        bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(x, 40);
        circles.push_back(myCircle);
        // BN_LOG ("x value", x);
    }

    circles[0].set_scale(1.8);
    circles[1].set_scale(0.5);
    circles[2].set_scale(2.0);
    circles[3].set_scale(0.2);

    // 2.0 seems to be the maximum before it becomes a rectangle.
    // 0.2 seems to be the minimum.

    bn::vector<bn::sprite_ptr, 10> rDiagonal = {};
    for (int x = -40, y = 40; x <= 40; x += 10, y -= 10)
    {
        bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(x, y);
        rDiagonal.push_back(myCircle);
    }

    rDiagonal[0].set_horizontal_scale(2.0);
    rDiagonal[1].set_vertical_scale(0.5);
    rDiagonal[2].set_shear(1.3);
    rDiagonal[2].set_rotation_angle(90);

    bn::vector<bn::sprite_ptr, 10> lDiagonal = {};
    for (int x = -40, y = -40; x <= 40; x += 10, y += 10)
    {
        bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(x, y);
        lDiagonal.push_back(myCircle);
    }

    lDiagonal[0].set_mosaic_enabled(true);
    lDiagonal[1].set_blending_enabled(true);

    bn::sprites_mosaic::set_stretch(0.5);
    bn::blending::set_transparency_alpha(0.5);

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