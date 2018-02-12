#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DVORAK 0
#define _FN1 1
#define _FN2 2
#define _FN3 3
#define _numpad 16

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  FN1,
  FN2,
  FN3,
  numpad,
};

enum {    //macro
  okwow=SAFE_RANGE,
};

enum {    //tapdance
  commadot=0,
  curlybrace,
  paren,
  brace
};

qk_tap_dance_action_t tap_dance_actions[]={
  [commadot]=ACTION_TAP_DANCE_DOUBLE(KC_PCMM, KC_PDOT),
  [curlybrace]=ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
  [paren]=ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
  [brace]=ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC)
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |FN1 |Space |Space |FN2 | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = KEYMAP( \
  KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_MINS, \
  KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT, \
  KC_LALT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_SLSH, \
  KC_LCTL,  KC_LGUI, _FN3, _FN2, _FN1, SFT_T(KC_SPC), KC_BSPC, KC_DELETE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT \
),

/* FN1
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |      |   \  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_FN1] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, TD(paren), TD(curlybrace), TD(brace), KC_DEL, \
  KC_TAB,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7, KC_8, KC_9, KC_0, KC_PIPE, \
  okwow,   KC_F23,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS),S(KC_NUBS),_______, _______, _______, \
  _______, _______, _______, _______, DVORAK, SFT_T(KC_SPC), KC_BSPC, KC_DELETE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT \
),

/* FN2
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_FN2] = KEYMAP( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

[_FN3] = KEYMAP(\
  KC_A, KC_B, KC_C, KC_D, KC_E, KC_F, KC_G, KC_H, KC_I, KC_J, KC_K, KC_L,
  KC_A, KC_B, KC_C, KC_D, KC_E, KC_F, KC_G, KC_H, KC_I, KC_J, KC_K, KC_L,
  KC_A, KC_B, KC_C, KC_D, KC_E, KC_F, KC_G, KC_H, KC_I, KC_J, KC_K, KC_L,
  KC_A, KC_B, KC_C, KC_D, KC_E, KC_F, KC_G, KC_H, KC_I, KC_J, KC_K, KC_L
),

[_numpad] = KEYMAP(\
  KC_NLCK, _______, KC_PMNS, KC_P7, KC_P8, KC_P9,        KC_P7, KC_P8, KC_P9, KC_PMNS, _______, KC_NLCK,
  _______, KC_BSPC, KC_PPLS, KC_P4, KC_P5, KC_P6,        KC_P4, KC_P5, KC_P6, KC_PPLS, KC_BSPC, _______,
  _______, _______, KC_PAST, KC_P3, KC_P2, KC_P1,        KC_P3, KC_P2, KC_P1, KC_PAST, _______, _______,
  DVORAK, _______, KC_PSLS, KC_P0, TD(commadot), KC_PENT,  KC_P0, TD(commadot), KC_PENT, KC_PSLS, _______, DVORAK
)

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case FN1:
      if (record->event.pressed) {
        layer_on(_FN1);
      } else {
        layer_off(_FN1);
      }
      return false;
      break;
    case FN2:
      if (record->event.pressed) {
        layer_on(_FN2);
      } else {
        layer_off(_FN2);
      }
      return false;
      break;
    case FN3:
      if (record->event.pressed) {
        layer_on(_FN3);
      } else {
        layer_off(_FN3);
      }
      return false;
      break;
    case numpad:
      if (record->event.pressed) {
        layer_on(_numpad);
      } else {
        layer_off(_numpad);
      }
      return false;
      break;
      if (record->event.pressed){   //macro stuff
        switch (keycode)
          case okwow:
            SEND_STRING("confringe");
            return false;
            break;
      }                             //till here
  }
  return true;
}
