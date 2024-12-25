// Copyright 2022 Will Winder (@winder)
// SPDX-License-Identifier: GPL-2.0-or-later
//
// qmk compile -kb chocofly/v1 -km winger_skv
// qmk flash -kb chocofly/v1 -km winger_skv
//
#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
};

#define FN_1 MO(_LOWER)
#define FN_2 MO(_RAISE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
                 KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                          KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS ,
                 KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                          KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC,
                 KC_LALT, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_MUTE,                                 KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
                 KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_GRV, KC_RBRC, /**/  KC_BSLS , KC_EQL, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                                                     KC_LGUI, KC_LCTL, FN_2   , KC_ENT, /**/  KC_SPC  , FN_2 ,  KC_RALT, KC_RGUI
    ),
    [_LOWER] = LAYOUT(
                 _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                                          KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
                 KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                          KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
                 KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, _______,                                 KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
                 _______, KC_EQL , KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______, _______, /**/ _______, _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                                                     _______, _______, _______, _______, /**/ _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT(
                 KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10 , KC_F11,
                 _______, KC_0,    KC_7,    KC_8,    KC_9,    KC_BSPC,                                          KC_DEL,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX,
                 _______, KC_0,    KC_4,    KC_5,    KC_6,    KC_DEL,  _______,                                 KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
                 _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_PDOT, _______, _______, /**/ _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                                     _______, _______, _______, _______, /**/ _______, _______, _______, _______
    ),
};



#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code_delay(KC_VOLD, 10);
        } else {
            tap_code_delay(KC_VOLU, 10);
        }
    }
    return true;
}
#endif