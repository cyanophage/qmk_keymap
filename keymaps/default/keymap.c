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
 *
 * qmk compile -j 16 --clean -kb tranquility -km default
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _RAISE,
    _NUMPAD,
    _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    STERL = SAFE_RANGE,
    ACUTEE,
    ACUTEA,
    RINGO,
    CEDILLA,
    ALT_F4,
    HELLO,
    YOUCOMBO,
    FLCOMBO
};

const uint16_t PROGMEM test_combo1[] = {KC_H, KC_M, COMBO_END};
const uint16_t PROGMEM test_combo4[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM test_combo8[] = {KC_F, KC_H, COMBO_END};
const uint16_t PROGMEM test_combo9[] = {KC_COMM, KC_QUOT, COMBO_END};
const uint16_t PROGMEM test_combo10[] = {KC_QUOT, KC_DOT, COMBO_END};
const uint16_t PROGMEM test_combo11[] = {KC_V, KC_P, COMBO_END};

combo_t key_combos[] = {
    COMBO(test_combo1, KC_K),
    COMBO(test_combo4, YOUCOMBO),
    COMBO(test_combo8, FLCOMBO),
    COMBO(test_combo9, KC_MINS),
    COMBO(test_combo10, LSFT(KC_SCLN)),
    COMBO(test_combo11, KC_SLSH)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        QK_GESC,  KC_1,  KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,   KC_8,       KC_9,   KC_0, KC_EQL,
        KC_TAB,   KC_F,  KC_W,    KC_H,    KC_M,    KC_Z,         KC_Q,    KC_O,   KC_U,       KC_Y,   KC_B, KC_J,
        KC_LCTL,  KC_S,  KC_N,    KC_R,    KC_T,MT(MOD_RCTL,KC_K),KC_MINS, KC_A,   KC_E,       KC_I,   KC_C, MT(MOD_RCTL,KC_X),
        KC_BSLS,  KC_V,  KC_P,    KC_L,    KC_D,    KC_SLSH,      KC_SCLN, KC_COMM,KC_QUOT,    KC_DOT, KC_G, KC_ENT,
                         KC_LGUI, KC_LALT, KC_LSFT, MO(_NUMPAD),  KC_BSPC, KC_SPC, MO(_RAISE), KC_APP
    ),
    [_RAISE] = LAYOUT(
        QK_GESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,    KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_DEL,
        KC_TRNS,  A(KC_B), A(KC_F), KC_LPRN, KC_RPRN, KC_AMPR, LSFT(KC_SCLN),KC_LBRC,KC_RBRC,  KC_LCBR, KC_RCBR, KC_MINS,
        KC_TRNS,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_CIRC,    KC_ASTR,  KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT, LSFT(KC_SCLN),
        KC_TRNS,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    STERL,    KC_PIPE, KC_EQL,   KC_PLUS, KC_MINS, KC_TRNS,
                           KC_TRNS, KC_TRNS, KC_LSFT, KC_TRNS,    KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS
    ),
    [_NUMPAD] = LAYOUT(
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,     KC_CALC, KC_PSLS, KC_PAST,  KC_F11,   KC_F12, KC_TRNS,
        KC_TRNS,  KC_F1,   KC_BTN5, KC_BTN2, KC_BTN1, KC_0,        KC_TRNS, KC_P7,   KC_P8,    KC_P9,    KC_PMNS, KC_TRNS,
        KC_TRNS,  KC_6,    KC_7,    KC_8,    KC_9,    KC_SPC,      KC_DOT,  KC_P4,   KC_P5,    KC_P6,    KC_PPLS, KC_GRAVE,
        KC_ENT,   KC_Y,    KC_X,    C(KC_V), C(KC_C), C(KC_X),     KC_TRNS, KC_P1,   KC_P2,    KC_P3,    KC_EQL,  KC_TRNS,
                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_P0,   KC_TRNS,  KC_TRNS
    ),
    [_ADJUST] = LAYOUT(
        QK_BOOT,  ALT_F4,  KC_TRNS, KC_TRNS, DF(_GRAPHENE), DF(_TRANQ),  DF(_BASE), DF(_QWERTY), DF(_HDVIB),  DF(_CARBYNE),  KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,    KC_F9,    KC_F10,  KC_F11,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, ACUTEA,  ACUTEE,  RINGO,  KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, HELLO,   KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
                           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS
    )
};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _RAISE, _NUMPAD, _ADJUST);
}

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
        case ACUTEE:
            if (record->event.pressed) {
                // when keycode ACUTEE is pressed
                register_code(KC_ALGR);
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P3);
                tap_code(KC_P3);
                unregister_code(KC_ALGR);
            } else {
                // when keycode ACUTEE is released
            }
            break;
        case ACUTEA:
            if (record->event.pressed) {
                // when keycode ACUTEE is pressed
                register_code(KC_ALGR);
                tap_code(KC_P0);
                tap_code(KC_P2);
                tap_code(KC_P2);
                tap_code(KC_P5);
                unregister_code(KC_ALGR);
            } else {
                // when keycode ACUTEE is released
            }
            break;
        case RINGO:
            if (record->event.pressed) {
                // when keycode ACUTEE is pressed
                register_code(KC_ALGR);
                tap_code(KC_P1);
                tap_code(KC_P3);
                tap_code(KC_P4);
                unregister_code(KC_ALGR);
            } else {
                // when keycode ACUTEE is released
            }
            break;
        case YOUCOMBO:
            if (record->event.pressed) {
                tap_code(KC_Y);
                tap_code(KC_O);
                tap_code(KC_U);
            }
            break;
        case FLCOMBO:
            if (record->event.pressed) {
                tap_code(KC_F);
                unregister_code(KC_LSFT);
                tap_code(KC_L);
            }
            break;
        case ALT_F4:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_F4);
                unregister_code(KC_LALT);
            }
            break;
        case HELLO:
            if (record->event.pressed) {
                SEND_STRING("hello");
            }
            return false;
        case CEDILLA:
            if (record->event.pressed) {
                // when keycode CEDILLA is pressed
                if (get_mods() & MOD_BIT(KC_LSFT)) {
                    unregister_code(KC_LSFT);
                    register_code(KC_ALGR);
                    tap_code(KC_P0);
                    tap_code(KC_P1);
                    tap_code(KC_P9);
                    tap_code(KC_P9);
                    unregister_code(KC_ALGR);
                } else {
                    register_code(KC_ALGR);
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P3);
                    tap_code(KC_P1);
                    unregister_code(KC_ALGR);
                }
            } else {
                // when keycode CEDILLA is released
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
