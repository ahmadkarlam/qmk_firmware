/*
Copyright 2022 Joe Scotto
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum {
    TD_A_ESC,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_A_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_ESC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_3x10_6(
        KC_Q,         KC_W,      KC_E,    KC_R,    KC_T,           KC_Y,          KC_U,          KC_I,       KC_O,   KC_P,
        TD(TD_A_ESC), KC_S,      KC_D,    KC_F,    KC_G,           KC_H,          KC_J,          KC_K,       KC_L,   KC_SCLN,
        LSFT_T(KC_Z),   KC_X,      KC_C,    KC_V,    KC_B,           KC_N,          KC_M,          KC_COMMA,   KC_DOT, KC_SLSH,
             LCTL_T(KC_TAB), LGUI_T(KC_ESC), LT(1, KC_BSPC),           LT(2, KC_SPC), LALT_T(KC_ENT), KC_DEL
    ),
    [1] = LAYOUT_ortho_3x10_6(
        _______, _______, _______, _______, _______,        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
        KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, _______,        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, _______, _______, _______, _______,        KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                KC_LCTL, KC_LGUI, _______,        MO(3), KC_LSFT, KC_DEL
    ),
    [2] = LAYOUT_ortho_3x10_6(
        KC_1, KC_2, KC_3, KC_4, KC_5,        KC_6, KC_7, KC_8, KC_9, KC_0,
        KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, _______,      _______, KC_RSFT, KC_RALT, KC_RGUI, KC_RCTL,
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
                KC_LCTL, KC_LGUI, MO(3),        _______, KC_LSFT, KC_DEL
    ),
    [3] = LAYOUT_ortho_3x10_6(
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, QK_RBT,
        _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,
                          _______, _______, _______,      _______, _______, _______
    )
};