// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "rgblight.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_1x1(
        RGB_MOD
    )
};

void keyboard_post_init_user(void) {
    // enables Rgb, without saving settings
    rgblight_enable();
    rgblight_sethsv_noeeprom(180, 255, 255); // sets the color to teal/cyan without saving
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_set();
}
