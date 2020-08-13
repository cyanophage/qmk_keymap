/* Copyright 2020 Cyanophage
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _RAISE,
    _NUMPAD
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    STERL = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_GESC,  KC_1,  KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,   KC_8,       KC_9,  KC_0, KC_EQL,
        KC_TAB,   KC_W,  KC_L,    KC_R,    KC_D,    KC_Z,         KC_Q,    KC_G,   KC_U,       KC_B,  KC_J, KC_MINS,
        KC_LCTL,  KC_S,  KC_H,    KC_N,    KC_T,    KC_COMM,      KC_DOT,  KC_A,   KC_E,       KC_O,  KC_I, KC_QUOT,
        KC_BSLS,  KC_F,  KC_M,    KC_V,    KC_C,    KC_SLSH,      KC_SCLN, KC_P,   KC_X,       KC_K,  KC_Y, KC_ENT,
                         KC_LGUI, KC_LALT, KC_LSFT, MO(_NUMPAD),  KC_BSPC, KC_SPC, MO(_RAISE), KC_RCTL
    ),
    [_RAISE] = LAYOUT(
        KC_GESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_DEL,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_LPRN, KC_RPRN, KC_TRNS,    KC_TRNS, KC_LBRC, KC_RBRC,  KC_LCBR, KC_RCBR, KC_MINS,
        KC_TRNS,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_TRNS,    KC_TRNS, KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT, KC_ENT,
        KC_TRNS,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    STERL,   KC_PIPE, KC_EQL,   KC_PLUS, KC_MINS, KC_TRNS,
                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS
    ),
    [_NUMPAD] = LAYOUT(
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_PSLS, KC_PAST,  KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_BTN2, KC_BTN2, KC_BTN1, KC_TRNS,    KC_TRNS, KC_7,    KC_8,     KC_9,    KC_PMNS, KC_TRNS,
        KC_TRNS,  KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, KC_TRNS,    KC_TRNS, KC_4,    KC_5,     KC_6,    KC_PPLS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_WH_D, KC_WH_U, KC_TRNS,    KC_TRNS, KC_1,    KC_2,     KC_3,    KC_PPLS, KC_TRNS,
                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_0,    KC_TRNS,  KC_TRNS
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case STERL:
            if (record->event.pressed) {
                // when keycode STERL is pressed
                SEND_STRING("£");
            } else {
                // when keycode STERL is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
