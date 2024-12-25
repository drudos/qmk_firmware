// Copyright 2022 Viatly Volkov (@vlkv)
// SPDX-License-Identifier: GPL-2.0-or-later
/*
qmk compile -kb chocofly/v1 -km default_1
qmk flash -kb chocofly/v1 -km default_1
*/

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
};

#define LFN_1 LALT_T(KC_ENT)
#define LFN_2 LT(_LOWER,KC_LBRC)
#define LFN_3 LCTL_T(KC_EQL)

//#define RFN_1 RALT_T(KC_SPC)
#define RFN_2 LT(_LOWER,KC_RBRC)
#define RFN_3 RCTL_T(KC_MINS)

#define GM_1 TG(_RAISE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
                 KC_ESC,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                 KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
                 KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_MUTE,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
                 SC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_F1,   KC_APP,  KC_PSCR, GM_1,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_RSPC,
                                                     KC_LGUI, LFN_3,   LFN_2,   LFN_1,   KC_SPC,  RFN_2,   RFN_3,   KC_RALT
    ),
    [_LOWER] = LAYOUT(
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, KC_0,    KC_7,    KC_8,    KC_9,    KC_BSPC,                                     KC_DEL,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX,
                 _______, KC_0,    KC_4,    KC_5,    KC_6,    KC_DEL,  _______,                            KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,
                 _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_COMM, XXXXXXX, _______, _______, _______, KC_DOT,  XXXXXXX, KC_APP,  XXXXXXX, XXXXXXX, _______,
                                                     _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT(
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, _______, _______, _______, _______, _______,                                     XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, _______, _______, _______, _______, _______, _______,                            XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                                     _______, _______, _______, _______, _______, _______, _______, _______
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
