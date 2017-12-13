#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};
#define ALT_TAB LATL(KC_TAB)
#define ALT_SFT_TAB LALT(LSHFT(KC_TAB))
#define CTL_ALT_DEL LALT(LCTL(KC_DEL))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,------------------------------------------------------.           ,--------------------------------------------------.
 * |   `      |   1   |   2   |   3  |   4  |   5  |   \  |           |PntScr|   6  |   7  |   8  |   9  |   0  |   -    |
 * |----------+-------+-------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab     |   Q   |   W   |   E  |   R  |   T  |  f2  |           |  f2  |   Y  |   U  |   I  |   O  |   P  |   =    |
 * |----------+-------+-------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl/Esc |   A   |   S   |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |----------+-------+-------+------+------+------|  f1  |           |  f1  |------+------+------+------+------+--------|
 * | LShift   |   Z   |   X   |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `----------+-------+-------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  Meh   |Alt+Tab|Alt+Tab| Lgui | Lalt |                                       | Left | Down |  Up  | Right|  Meh |
 *   `--------------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        |  L1  |  L2  |       | Ctrl |  Ralt |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      | PgUp |       | PgDn |       |      |
 *                                 | Back | Del  |------|       |------| Enter | [_]  |
 *                                 | Space|      | Home |       | End  |       |      |
 *                                 `--------------------'       `---------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRV,		KC_1,	      KC_2,	KC_3,     KC_4,	  KC_5,	    KC_BSLS,
        KC_TAB, 	KC_Q,	      KC_W,	KC_E,     KC_R,	  KC_T,	    MO(MDIA),
        CTL_T(KC_ESC),	KC_A,	      KC_S,	KC_D,     KC_F,	  KC_G,
        KC_LSFT,	KC_Z,	      KC_X,	KC_C,     KC_V,	  KC_B,	    MO(SYMB),
        MEH_T(KC_NO),	ALT_SFT_TAB,  ALT_TAB,  KC_LGUI,  KC_LALT,
								  TG(SYMB),  TG(MDIA),
									    KC_PGUP,
							KC_BSPC,  KC_DEL,   KC_HOME,
        // right hand
             KC_PSCR,	KC_6,	  KC_7,	    KC_8,     KC_9,   KC_0,	KC_MINS,
             MO(SYMB),	KC_Y,	  KC_U,	    KC_I,     KC_O,   KC_P,     KC_EQL,
                        KC_H,	  KC_J,	    KC_K,     KC_L,   KC_SCLN,	KC_QUOT,
             MO(MDIA),	KC_N,	  KC_M,	    KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
				  KC_LEFT,  KC_DOWN,  KC_UP,  KC_RIGHT,	MEH_T(KC_NO),
             KC_RCTL,	KC_RALT,
             KC_PGDN,
             KC_END,	KC_ENT,	  KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |CTL+ALT+DEL|           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+-----------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |           |           |      |   Up |   7  |   8  |   9  |   +  |   F12  |
 * |---------+------+------+------+------+------|           |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |-----------|           |------| Down |   4  |   5  |   6  |   -  |        |
 * |---------+------+------+------+------+------|           |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |           |           |      |   &  |   1  |   2  |   3  |   *  |        |
 * `---------+------+------+------+------+------------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |   <  |   >  |                                            |   0  |    . |   =  |   /  |      |
 *   `-----------------------------------'                                            `----------------------------------'
 *                                             ,-------------.       ,-------------.
 *                                             |      |      |       |      |      |
 *                                      ,------|------|------|       |------+------+------.
 *                                      |      |      |      |       |      |      |      |
 *                                      |      |      |------|       |------|      |      |
 *                                      |      |      |      |       |      |      |      |
 *                                      `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,	KC_F1,	  KC_F2,    KC_F3,    KC_F4,	KC_F5,	  CTL_ALT_DEL,
       KC_TRNS,	KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,	KC_PIPE,  KC_TRNS,
       KC_TRNS,	KC_HASH,  KC_DLR,   KC_LPRN,  KC_RPRN,	KC_GRV,
       KC_TRNS,	KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,	KC_TILD,  KC_TRNS,
       KC_TRNS,	KC_TRNS,  KC_TRNS,  KC_LT,    KC_GT,
						KC_TRNS,KC_TRNS,
							KC_TRNS,
					KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_PPLS, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PMNS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_PAST, KC_TRNS,
                         KC_0,	 KC_DOT,  KC_EQL,  KC_PSLS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      | Vol Up |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | MsUp |      |      |      |      |           |      | WH_LT| WH_DN| WH_UP| WH_RT|      | Vol Dn |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |MsLeft|MsDown|MsRght|      |      |------|           |------| Left | Down |  Up  |Right |      |  Mute  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |ACL 0 |ACL 1 |ACL 2 |      |      |      |           |      |      |      |      |      |      | PlayPau|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      | Prev | Next |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 | Lclk | Rclk |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN1, KC_BTN2, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
