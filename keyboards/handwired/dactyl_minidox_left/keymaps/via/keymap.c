// Copyright 2022 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "rgblight.h"

enum layers{
    _BASE,
    _RAISE,
    _LOWER,
    _BLANK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   MO(_RAISE), KC_BSPC, KC_SPC,           KC_SPC,  KC_ENT,  KC_RALT
    ),
    [_RAISE] = LAYOUT_split_3x5_3(
        _______, RGB_TOG, RGB_MOD, _______, _______,                            _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______,
                                   _______, _______, _______,          _______, _______, _______                                          
    ),
    [_LOWER] = LAYOUT_split_3x5_3(
        _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______,
                                   _______, _______, _______,          _______, _______, _______
    ),
    [_BLANK] = LAYOUT_split_3x5_3(
        _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______,
                                   _______, _______, _______,          _______, _______, _______
    )
};

void keyboard_post_init_user(void) {
    // enables Rgb, without saving settings
    rgblight_enable();
    rgblight_sethsv_noeeprom(180, 255, 255); // sets the color to teal/cyan without saving
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_set();
}