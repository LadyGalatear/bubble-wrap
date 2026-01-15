#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>

int main() {
    bn::core::init();

    bn::backdrop::set_color(bn::color(20, 20, 31));

    while(true) {
        bn::core::update();
    }
}