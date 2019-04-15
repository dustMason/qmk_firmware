#include QMK_KEYBOARD_H
#include "tapdance.c"

#define VOLUP KC__VOLUP
#define VOLDN KC__VOLDOWN

// TapDance for Command keys: tap for { and }, hold for LGUI/RGUI
#define KC_LCMBR TD(LGUI_LBRACE)
#define KC_RCMBR TD(RGUI_RBRACE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
  KC_GESC, KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  KC_HOME, \
  KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_PGUP, \
  KC_LCTL, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN, \
  KC_LSPO, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,                   KC_UP,   KC_END,  \
  MO(1),   KC_LALT, KC_LCMBR,               KC_SPC,                         KC_RCMBR, KC_RALT,                   KC_LEFT, KC_DOWN, KC_RGHT),

// - minus/equals => brightness down/up
// - space        => play/pause
// - WASD         => volume up, prev track, volume down, next track
// - HJKL         => vim style arrow keys
// - R            => RESET
[1] = LAYOUT(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BRID, KC_BRIU, KC_TRNS, KC_TRNS,  KC_TRNS, \
  KC_TRNS, KC_TRNS, VOLUP,   KC_TRNS, RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, \
  KC_TRNS, KC_MRWD, VOLDN,   KC_MFFD, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,          KC_TRNS,           KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS,                   KC_MPLY,                            KC_TRNS, KC_TRNS,                    KC_TRNS, KC_TRNS, KC_TRNS),
};

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//  return true;
//}

void matrix_init_user(void) { }
void matrix_scan_user(void) { }
void led_set_user(uint8_t usb_led) { }
