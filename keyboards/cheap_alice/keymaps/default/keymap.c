// Copyright 2024 %YOUR_FULL_NAME% (@%YOUR_GITHUB_USERNAME%)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_2,    KC_MINS, KC_GRV,  KC_1,    KC_EQL,  KC_BSPC,
        KC_PGUP, KC_P,    KC_TAB,  KC_Q,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_PGDN, KC_CAPS, KC_A,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_DOT,  KC_SLSH, KC_LSFT, KC_UP,
        KC_LCTL, KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_3,    KC_4,    KC_5,    KC_6,
        KC_W,    KC_E,    KC_R,    KC_T,
        KC_S,    KC_D,    KC_F,    KC_G,
        KC_X,    KC_C,    KC_V,    KC_B,
        KC_SPC,  KC_LGUI, KC_LALT, KC_7,    KC_8,    KC_9,    KC_0,
        KC_Y,    KC_U,    KC_I,    KC_O,
        KC_H,    KC_J,    KC_K,    KC_L,
        KC_B,    KC_N,    KC_M,    KC_COMM,
        KC_SPC,  KC_LALT
    )
};
