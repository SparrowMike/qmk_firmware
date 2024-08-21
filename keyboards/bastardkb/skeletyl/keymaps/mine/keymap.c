#include QMK_KEYBOARD_H

enum {
    TD_RALT_CAPS,
};

enum layers {
    _BASE,
    _FIRST,
    _SECOND,
    _THIRD
};

enum custom_keycodes {
    BK_TAB = SAFE_RANGE,
};

enum combo_events {
    DOT_SLASH_GRV,
    L_SEMI_QUOTE,
    ESC_QW,
    COMMA_DOT_ESC,
    M_COMMA_ESC,
    OP_CAPS,
    CMD_Z,
    CMD_X,
    CMD_C,
    CMD_V,
    ANGLE_BRACKETS_TAB,
};

const uint16_t PROGMEM dot_slash_grv_combo[]  = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM angle_brackets_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM m_comma_esc_combo[]    = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM esc_qw_combo[]  = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM l_semi_combo[]  = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM m_angle_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM op_caps_combo[] = {KC_O, KC_P, COMBO_END};

const uint16_t PROGMEM cmd_z_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM cmd_x_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cmd_c_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cmd_v_combo[] = {KC_V, KC_B, COMBO_END};

combo_t key_combos[] = {
    [ESC_QW]  = COMBO(esc_qw_combo, KC_ESC),
    [OP_CAPS] = COMBO(op_caps_combo, KC_CAPS),
    [M_COMMA_ESC] = COMBO(m_comma_esc_combo, KC_ESC),
    [ANGLE_BRACKETS_TAB] = COMBO(angle_brackets_combo, KC_TAB),
    // [M_ANGLE_BK_TAB] = COMBO(m_angle_combo, S(KC_TAB)),
    [DOT_SLASH_GRV]  = COMBO(dot_slash_grv_combo, KC_GRV),
    [L_SEMI_QUOTE]   = COMBO_ACTION(l_semi_combo),

    [CMD_Z] = COMBO_ACTION(cmd_z_combo),
    [CMD_X] = COMBO_ACTION(cmd_x_combo),
    [CMD_C] = COMBO_ACTION(cmd_c_combo),
    [CMD_V] = COMBO_ACTION(cmd_v_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case CMD_Z:
            if (pressed) {
                register_code(KC_LGUI);
                register_code(KC_Z);
            } else {
                unregister_code(KC_Z);
                unregister_code(KC_LGUI);
            }
            break;
        case CMD_X:
            if (pressed) {
                register_code(KC_LGUI);
                register_code(KC_X);
            } else {
                unregister_code(KC_X);
                unregister_code(KC_LGUI);
            }
            break;
        case CMD_C:
            if (pressed) {
                register_code(KC_LGUI);
                register_code(KC_C);
            } else {
                unregister_code(KC_C);
                unregister_code(KC_LGUI);
            }
            break;
        case CMD_V:
            if (pressed) {
                register_code(KC_LGUI);
                register_code(KC_V);
            } else {
                unregister_code(KC_V);
                unregister_code(KC_LGUI);
            }
            break;
        case L_SEMI_QUOTE:
            if (pressed) {
                register_code(KC_QUOT);
            } else {
                unregister_code(KC_QUOT);
            }
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_RALT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_RALT, KC_CAPS),
};

#define HM_A LCTL_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LGUI_T(KC_D)
#define HM_F LSFT_T(KC_F)

#define HM_J RSFT_T(KC_J)
#define HM_K RGUI_T(KC_K)
/* #define HM_L RALT_T(KC_L) */
/* #define HM_SCLN RCTL_T(KC_SCLN) */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3(
        //,--------------------------------------------.                    ,--------------------------------------------.
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        HM_A,    HM_S,    HM_D,    HM_F,    KC_G,                           KC_H,    HM_J,    HM_K,    KC_L,   KC_SCLN,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_N,    KC_M,  KC_COMM,  KC_DOT,  KC_SLSH,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                   MO(_SECOND),MO(_FIRST),KC_ENT,   KC_SPC, KC_BSPC, MO(_SECOND)
                                   //`--------------------------'  `--------------------------'

    ),
    [_FIRST] = LAYOUT_split_3x5_3(
        //,--------------------------------------------.                    ,--------------------------------------------.
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_MINS, KC_EQL,  KC_GRV,  KC_LBRC, KC_RBRC,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                   KC_TRNS, KC_TRNS,  KC_TRNS,      KC_TRNS, KC_TRNS, KC_ESC
                                   //`--------------------------'  `--------------------------'

    ),
    [_SECOND] = LAYOUT_split_3x5_3(
        //,--------------------------------------------.                    ,--------------------------------------------.
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_TRNS, KC_MUTE, KC_MPRV, KC_MNXT, KC_MPLY,                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        RGB_TOG, RGB_RMOD,RGB_MOD, RGB_VAD, RGB_VAI,                        KC_TRNS, KC_VOLD, KC_VOLU, BK_TAB,  KC_TRNS,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
                                   //`--------------------------'  `--------------------------'
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BK_TAB:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
                unregister_code(KC_LSFT);
            }
            return false;

    }
    return true;
}
