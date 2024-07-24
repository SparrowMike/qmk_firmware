#include QMK_KEYBOARD_H

#ifdef INCLUDE_LAYERS
#   include "./../cornie/animation/layers.h"
#endif

#ifdef INCLUDE_LOGO
#   include "./../cornie/animation/corne_logo.h"
#endif

#ifdef INCLUDE_CAT
#   include "./../cornie/animation/bongo.c"
#endif

#ifdef INCLUDE_OCEAN
#   include "./../cornie/animation/ocean_dream.c"
#endif

#ifdef INCLUDE_ARASAKA
#   include "./../cornie/animation/arasaka.c"
#endif

#ifdef INCLUDE_LUNA
#   include "./../cornie/animation/luna.c"
#endif

#ifdef INCLUDE_BARS
#   include "./../cornie/animation/music-bars.c"
#endif

enum layers {
    _BASE,
    _FIRST,
    _SECOND,
    _THIRD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

    [_FIRST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_SECOND] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [_THIRD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LCTL:
        case KC_RCTL:
#ifdef INCLUDE_OCEAN
            is_calm = (record->event.pressed) ? true : false;
#endif

#ifdef INCLUDE_LUNA
            if (record->event.pressed) {
              isSneaking = true;
            } else {
              isSneaking = false;
            }
#endif
            break;
        case KC_SPC:
#ifdef INCLUDE_LUNA
            if (record->event.pressed) {
              isJumping = true;
              showedJump = false;
            } else {
              isJumping = false;
            }
#endif
            break;
    }
    return true;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
#if defined(INCLUDE_ARASAKA) || defined(INCLUDE_OCEAN)
    return OLED_ROTATION_270;
#else
    return OLED_ROTATION_180;
#endif
    }
    return rotation;
}

bool oled_task_user(){
    oled_set_brightness(0);

#if OLED_TIMEOUT > 0
    /* the animation prevents the normal timeout from occuring */
    if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
        return oled_off();
    } else {
        oled_on();
    }
#endif

    if (is_keyboard_master()) {

#   ifdef INCLUDE_LAYERS
        switch (get_highest_layer(layer_state)) {
            case _BASE:
                oled_write_raw_P(qwerty_img, sizeof(qwerty_img));
                break;
            case _FIRST:
                oled_write_raw_P(lower_img, sizeof(lower_img));
                break;
            case _SECOND:
                oled_write_raw_P(raise_img, sizeof(raise_img));
                break;
            case _THIRD:
                oled_write_raw_P(adjust_img, sizeof(adjust_img));
                break;
        }
#   endif

#ifdef INCLUDE_LOGO
        oled_set_cursor(0, 12);
        oled_write_raw_P(corne_logo, sizeof(corne_logo));
#endif

#ifdef INCLUDE_LUNA

        led_usb_state = host_keyboard_led_state();
        render_luna(0, 13);
#endif

        // Display LED status
        // led_t led_state = host_keyboard_led_state();
        // oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
        // oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
        // oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    } else {

#   ifdef INCLUDE_CAT
        draw_bongo(false);
#   endif

#   ifdef INCLUDE_OCEAN
        render_stars();
#   endif

#   ifdef INCLUDE_ARASAKA
        arasaka_draw();
#   endif

#   ifdef INCLUDE_BARS
        oled_render_anim();
#   endif
    }

    return false;
}
#endif
