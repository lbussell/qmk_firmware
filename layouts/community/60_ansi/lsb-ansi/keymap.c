#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum layers {
    _QWERTY,
    _COLEMAK,
    _DVORAK,
    _GAME,
    _FN,
    _ADJUST
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    DVORAK,
    GAME,
    FN,
    ADJUST
};

#define CTL_ESC LCTL_T(KC_ESC)
#define KC_FN FN

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_60_ansi(
        KC_GESC, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS,  KC_EQL,    KC_BSPC, \
        KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_LBRC, KC_RBRC,  KC_BSLASH, \
        CTL_ESC,   KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,   KC_K,   KC_L,  KC_SCLN, KC_QUOT,        KC_ENT, \
        KC_LSFT,     KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,   KC_COMM, KC_DOT, KC_SLSH,            KC_RSFT, \
        KC_LCTL, KC_LGUI, KC_LALT,                  KC_SPACE,                   KC_RALT,  KC_FN,  KC_RGUI, KC_RCTL),

    [_COLEMAK] = LAYOUT_60_ansi(
        KC_GESC, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS,  KC_EQL,    KC_BSPC, \
        KC_TAB,  KC_Q,  KC_W,  KC_F,  KC_P,  KC_G,  KC_J,  KC_L,  KC_U,  KC_Y, KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLASH, \
        CTL_ESC,   KC_A,  KC_R,  KC_S,  KC_T,  KC_D,  KC_H,  KC_N,   KC_E,   KC_I,  KC_O,  KC_QUOT,          KC_ENT, \
        KC_LSPO,     KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_K,  KC_M,   KC_COMM, KC_DOT, KC_SLSH,            KC_RSPC, \
        KC_LCTL, KC_LGUI, KC_LALT,                  KC_SPACE,                   KC_RALT,  KC_FN,  KC_RGUI, KC_RCTL),

    [_FN] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, QWERTY,  COLEMAK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______,   _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,        _______, \
        _______,     RGB_TOG,  RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______,              _______, \
        _______, _______, _______,                  _______,                                     _______, _______, _______, _______),
 };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
            break;
        case FN:
            if (record->event.pressed) {
                layer_on(_FN);
            } else {
                layer_off(_FN);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
    }
    return true;
}
