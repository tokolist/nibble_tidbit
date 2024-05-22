#include QMK_KEYBOARD_H
#include "common/bitc_led.h"

enum layer_names {
  _MA,
  _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MA] = LAYOUT_ansi(
             KC_ESC,  KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,       KC_MINS,    KC_EQL,      KC_BSPC, KC_PGUP,            KC_ESC,  KC_PSCR,       KC_PSLS,
    KC_MUTE, KC_TAB,  KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,       KC_LBRC,    KC_RBRC,     KC_ENT,  KC_PGDN, KC_P7,     KC_P8,   KC_P9,         KC_PAST,
    _______, KC_CAPS, KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,    KC_QUOT,                 KC_BSLS, KC_HOME, KC_P4,     KC_P5,   KC_P6,         KC_PMNS,
    KC_DEL,  KC_LSFT, KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,    KC_RSFT,                 KC_UP,   KC_END,  KC_P1,     KC_P2,   KC_P3,         KC_PPLS,
    MO(_FN), KC_LCTL, KC_LGUI,   KC_LALT,                         KC_SPC,                          KC_RALT,   MO(_FN),   KC_RCTL,                KC_LEFT,     KC_DOWN, KC_RGHT, MO(_FN),   KC_P0,   KC_PDOT,       KC_PENT
  ),
  [_FN] = LAYOUT_ansi(
             KC_GRV,  KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,     KC_F11,    KC_F12,       QK_BOOT, RGB_HUI,            _______, RALT(KC_PSCR), _______,
    RGB_TOG, _______, RGB_M_P,   RGB_M_B,   RGB_M_R,   RGB_M_SW,  RGB_M_SN,  RGB_M_K,   RGB_M_X,   RGB_M_G,   RGB_M_T,   KC_PAUS,    KC_INS,    _______,      _______, RGB_HUD, _______,   _______, _______,       _______,
    _______, _______, _______,   KC_SCRL,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,    _______,                 _______, RGB_SAI, _______,   _______, _______,       _______,
    _______, _______, _______,   _______,   _______,   _______,   _______,   KC_NUM,    _______,   _______,   _______,   _______,    _______,                 _______, RGB_SAD, _______,   _______, _______,       QK_BOOT,
    _______, _______, _______,   _______,                         _______,                         _______,   _______,   _______,               _______,      _______, _______, _______,   _______, _______,       _______
  ),

};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [1] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};
#endif

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res) {
		if (is_keyboard_left()) {
			set_bitc_LED(led_state.caps_lock ? LED_DIM : LED_OFF);
		} else {
			set_bitc_LED(led_state.num_lock ? LED_DIM : LED_OFF);
		}
    }
    return res;
}
