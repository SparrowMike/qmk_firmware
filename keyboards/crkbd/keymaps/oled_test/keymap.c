#include QMK_KEYBOARD_H

#ifdef TESTER
#   include "./animation/tester.c"
#endif

#ifdef INCLUDE_OCEAN
#   include "./../cornie/animation/ocean_dream.c"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {};


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
#if defined(INCLUDE_OCEAN)
    return OLED_ROTATION_270;
#endif
    return rotation;
}

bool oled_task_user(void) {
    // oled_write_vertical("This is the first line", 0, 0);
    // oled_write_vertical("and the second at the QMK!", 4, 0);

    // oled_clear();

    // static uint32_t anim_timer = 0;

    // if (timer_elapsed32(anim_timer) > 100) { // Adjust interval as needed
    //     update_text_position();
    //     draw_text();
    //     anim_timer = timer_read32();
    // }
#   ifdef INCLUDE_OCEAN
        render_stars();
#   endif

    return false;
}
