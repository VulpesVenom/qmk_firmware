/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
};

// Custom stuff from Wes
// Emoji
enum unicode_names {
	WOOP,
	TECH,
	TICK,
	RUDE
};

const uint32_t PROGMEM unicode_map[] = {
	[WOOP] = 0x1F389,
    [TECH] = 0x1F4BB,  // ‽
    [TICK] = 0x2713, // 🐍
    [RUDE] = 0x1F595,
};

enum custom_keycodes {
	MACRO1 = SAFE_RANGE,
	MACRO2,
	MACRO3,
	MACRO4,
	MACRO5,
	MACRO6,
	MACRO7,
	MACRO8,
	MACRO9,
	MACRO0	
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
	switch (keycode) {
		case MACRO1:
			if (record->event.pressed) {
				SEND_STRING("v8ZYJUunJz2D7Sfj");
			} else {
				// when keycode is released
			}
			break;
		case MACRO2:
			if (record->event.pressed) {
				SEND_STRING("h3kbHh8VL5nQ5QCr");
			} else {
				// when keycode is released
			}
			break;
		case MACRO3:
		    if (record->event.pressed) {
		        SEND_STRING("!4hhTh3S3r3n1ty");
		    } else {
		        // when keycode is released
		    }
		    break;
		case MACRO4:
		    if (record->event.pressed) {
		        SEND_STRING("Hippo Enrollment3");
		    } else {
		        // when keycode is released
		    }
		    break;
		case MACRO5:
		    if (record->event.pressed) {
		        SEND_STRING(SS_LCTL("c") SS_LCTL(SS_LSFT("5")) SS_DELAY(1000) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_LCTL("v") SS_TAP(X_TAB) "wstone" SS_TAP(X_TAB) "Hippo Enrollment3" SS_TAP(X_ENT));
		    } else {
		        // when keycode is released
		    }
		    break;
		case MACRO6:
		    if (record->event.pressed) {
		        SEND_STRING(SS_LCTL(SS_LSFT("6")));
		    } else {
		        // when keycode is released
		    }
		    break;
		case MACRO7:
		    if (record->event.pressed) {
		        SEND_STRING(SS_LCTL("c") SS_LCTL(SS_LSFT("7")));
		    } else {
		        // when keycode is released
		    }
		    break;
		case MACRO8:
		    if (record->event.pressed) {
		        SEND_STRING("C0mpareCompla!nts");
		    } else {
		        // when keycode is released
		    }
		    break;
		case MACRO9:
		    if (record->event.pressed) {
		        SEND_STRING(SS_LCTL(SS_LSFT("9")));
		    } else {
		        // when keycode is released
		    }
		    break;
		case MACRO0:
		    if (record->event.pressed) {
		        SEND_STRING(SS_LCTL(SS_LSFT("0")));
		    } else {
		        // when keycode is released
		    }
		    break;
	}
	return true;
};

// Should show the macro etc. keys on upper layer
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) == 3) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED) {
                	if (keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    	rgb_matrix_set_color(index, RGB_GREEN);
                    } else {
                    	rgb_matrix_set_color(index, RGB_BLACK);
                    }
                }
            }
        }
    }
    return false;
};
// End custom stuff from Wes

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_109(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,    KC_PSCR,  UC_LINX, RGB_MOD,  UM(WOOP),    UM(TECH),    UM(TICK),     UM(RUDE),
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        LT(3,KC_MS_BTN2),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                   KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_LCMMD, KC_LOPTN, LT(WIN_FN,KC_APP), KC_LCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [MAC_FN] = LAYOUT_ansi_109(
        UC_LINX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     RGB_TOG,    _______,  DF(2),  RGB_TOG,  _______,  _______,  _______,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,  
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______),
    [WIN_BASE] = LAYOUT_ansi_109(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,    KC_PSCR,  DF(2), RGB_MOD,  UM(WOOP),    UM(TECH),    UM(TICK),     UM(RUDE),
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,    KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,    KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        LT(3,KC_MS_BTN2),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                   KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,              KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_LWIN,  LT(WIN_FN,KC_APP), KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [WIN_FN] = LAYOUT_ansi_109(
        UC_WIN,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    RGB_TOG,    _______,  DF(2),  RGB_TOG,  _______,  _______,  _______,  _______,
        _______,  MACRO1,  MACRO2,  MACRO3,  MACRO4,  MACRO5,  MACRO6,  MACRO7,  MACRO8,  MACRO9, MACRO0,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                  _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,              _______,            _______,  _______,  _______,  
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,    _______,  _______,  _______,  _______,            _______,  _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};
#endif // ENCODER_MAP_ENABLE

// clang-format on
//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//    if (!process_record_keychron_common(keycode, record)) {
//        return false;
//    }
//    return true;
//}
