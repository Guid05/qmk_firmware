#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _COLEMAK,
  _GAMING,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = QK_USER,
    KC_COLEMAK,
    KC_GAMING,
};

// Left-hand home row mods QWERTY 
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods QWERTY
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// Left-hand home row mods COLEMAK
#define COLK_A LGUI_T(KC_A)
#define COLK_R LALT_T(KC_R)
#define COLK_S LCTL_T(KC_S)
#define COLK_T LSFT_T(KC_T)

// Right-hand home row mods COLEMAK
#define COLK_N RSFT_T(KC_N)
#define COLK_E RCTL_T(KC_E)
#define COLK_I LALT_T(KC_I)
#define COLK_O RGUI_T(KC_O)

// thumb cluster mod tap
#define RGUI_DEL RGUI_T(KC_DEL)
#define ESC_LALT LALT_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    |      |      |      |      |      |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LSHIFT|A/LGUI|S/LALT|D/LCTL|F/LSFT|   G  |-------.    ,-------|   H  |J/RSFT|K/RCTL|L/RALT|;/RGUI|  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | ESC  | TAB  | /Space  /       \Enter \  |BackSP|BackSP| DEL  |
 *                   |      | LALT |LOWER |/       /         \      \ |RAISE |      | RGUI |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_GRV,
  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_MINS,
  KC_LSFT,   HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,                     KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN, KC_QUOT,
  KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   KC_RSFT,
                          KC_LGUI, ESC_LALT, LT(_LOWER, KC_TAB), KC_SPC, KC_ENT, LT(_RAISE, KC_BSPC), KC_BSPC, RGUI_DEL
),

/* COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    |      |      |      |      |      |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LSHIFT|A/LGUI|R/LALT|S/LCTL|T/LSFT|   D  |-------.    ,-------|   H  |N/RSFT|E/RCTL|I/RALT|O/RGUI|  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | ESC  | TAB  | /Space  /       \Enter \  |BackSP|BackSP| DEL  |
 *                   |      | LALT |LOWER |/       /         \      \ |RAISE |      | RGUI |
 *                   `----------------------------'           '------''--------------------'
 */

 [_COLEMAK] = LAYOUT(
  KC_ESC,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_GRV,
  KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,   KC_MINS,
  KC_LSFT,   COLK_A,  COLK_R,  COLK_S,  COLK_T,  KC_D,                     KC_H,    COLK_N,  COLK_E,  COLK_I,  COLK_O,    KC_QUOT,
  KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   KC_RSFT,
                          KC_LGUI, ESC_LALT, LT(_LOWER, KC_TAB), KC_SPC, KC_ENT, LT(_RAISE, KC_BSPC), KC_BSPC, RGUI_DEL
),

/* GAMING
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LSHIFT|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | ESC  | TAB  | /Space  /       \Enter \  |BackSP|BackSP| DEL  |
 *                   |      | LALT |LOWER |/       /         \      \ |RAISE |      | RGUI |
 *                   `----------------------------'           '------''--------------------'
 */

 [_GAMING] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                        KC_LGUI, ESC_LALT, LT(_LOWER, KC_TAB), KC_SPC, KC_ENT, LT(_RAISE, KC_BSPC), KC_BSPC, RGUI_DEL
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | ESC  | TAB  | /Space  /       \Enter \  |BackSP|BackSP| DEL  |
 *                   |      | LALT |LOWER |/       /         \      \ |RAISE |      | RGUI |
 *                   `----------------------------'           '------''--------------------'
 */

[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
  _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | ESC  | TAB  | /Space  /       \Enter \  |BackSP|BackSP| DEL  |
 *                   |      | LALT |LOWER |/       /         \      \ |RAISE |      | RGUI |
 *                   `----------------------------'           '------''--------------------'
 */


[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |QWRTY |COLMK |GAMES |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | ESC  | TAB  | /Space  /       \Enter \  |BackSP|BackSP| DEL  |
 *                   |      | LALT |LOWER |/       /         \      \ |RAISE |      | RGUI |
 *                   `----------------------------'           '------''--------------------'
 */

  [_ADJUST] = LAYOUT(
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_QWERTY, KC_COLEMAK, KC_GAMING, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef QUICK_TAP_TERM_PER_KEY

// Hold backspace on double tap
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_RAISE, KC_BSPC):
            return QUICK_TAP_TERM + 180;
        default:
            return QUICK_TAP_TERM;
    }
}

#endif

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_90;  // flips the display 180 degrees if offhand
  return OLED_ROTATION_270;
}

#define frame_size 512

static const char PROGMEM static_logo[] = {
    0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x70, 0x38, 0x18, 0x0c, 0x0c, 0xce, 0xe6, 0xf6, 0xf6, 0xfe, 
    0xfe, 0xf6, 0xf6, 0xe6, 0x8e, 0x0c, 0x1c, 0x18, 0x38, 0x70, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 
    0x00, 0xf8, 0xfe, 0xe7, 0xf9, 0xf8, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xfb, 0xe7, 0x0f, 0x1f, 0xff, 
    0xff, 0x1f, 0x0f, 0xf7, 0xf9, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xf3, 0x4f, 0xfe, 0xf8, 0x00, 
    0x00, 0x1f, 0x7f, 0xf0, 0xc3, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x0f, 0x1c, 0x38, 0x70, 0xff, 
    0xff, 0x78, 0x3c, 0x1f, 0x0f, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0xc3, 0xf0, 0x7f, 0x1f, 0x00, 
    0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0e, 0x1c, 0x18, 0x30, 0x30, 0x70, 0x60, 0x60, 0x60, 0x7f, 
    0x7f, 0x60, 0x60, 0x60, 0x70, 0x30, 0x38, 0x18, 0x1c, 0x0e, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00
};

static const char PROGMEM arasaka[frame_size] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xf8, 0x7c, 0x3e, 0x1f, 0x1f, 0x1f, 
  0x1c, 0x1e, 0x1f, 0x1f, 0x1f, 0x9f, 0xdf, 0x9f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc3, 0x3f, 0xff, 0xff, 0xf8, 0xe0, 0xc0, 0xc0, 0xc0, 
  0xc0, 0xc0, 0xe0, 0xf8, 0xff, 0xff, 0x3f, 0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x7f, 0xfe, 0xf9, 0xf1, 0xc3, 0x83, 0x03, 0x03, 
  0x03, 0x83, 0xc3, 0xf1, 0xf9, 0xfc, 0x3f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x78, 0x78, 0x7b, 0x7f, 0x7f, 0x7f, 0x7e, 0x7c, 
  0x3e, 0x1f, 0x7f, 0x7f, 0x7b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xf8, 0x7c, 0x3e, 0x1f, 0x1f, 0x1f, 
  0x1c, 0x1e, 0x1f, 0x1f, 0x1f, 0x9f, 0xdf, 0x9f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3f, 0xff, 0xff, 0xf8, 0xe0, 0xc0, 0xc0, 0xc0, 
  0xc0, 0xc0, 0xe0, 0xf8, 0xff, 0xff, 0x3f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xe1, 0x01, 0x03, 0x03, 0x07, 0x07, 
  0x87, 0xc3, 0xf3, 0xf9, 0xf9, 0xf8, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0xc0, 0xe0, 0xf8, 0xfc, 0xfe, 
  0x3f, 0x1f, 0x07, 0x07, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x8f, 0xc3, 0xc1, 0xc0, 
  0x00, 0x9e, 0xde, 0xde, 0xdf, 0xdf, 0xcf, 0xc7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0xfc, 0xfe, 0x1f, 0x0f, 0x07, 0x07, 0x07, 
  0x07, 0x07, 0x07, 0x07, 0xc7, 0xe7, 0xf7, 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x3f, 0x7f, 0x7e, 0xf8, 0xf0, 0xf0, 0xf0, 
  0xf0, 0xf0, 0xf8, 0x7e, 0x7f, 0x3f, 0x0f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf8, 0xf8, 0xfc, 0xfc, 0x3c, 0x3c, 0x01, 0x01, 
  0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x80, 
  0xc0, 0xf0, 0xf8, 0xfe, 0x7f, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x8f, 0xcf, 0xef, 0xef, 0xef, 
  0x87, 0xc3, 0xef, 0xef, 0xef, 0xe0, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xfc, 0xfe, 0xff, 0x0f, 0x07, 0x03, 0x03, 0x03, 
  0x03, 0x03, 0x03, 0x03, 0xe3, 0xf3, 0xfb, 0xf3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1f, 0x3f, 0x3f, 0x7c, 0x78, 0xf8, 0xf8, 
  0xf8, 0x78, 0x7c, 0x3f, 0x3f, 0x1f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


/* status variables */
int   current_wpm = 0;

static void print_status_narrow(void) {
  /* Print current mode*/
    oled_set_cursor(0, 0);
    oled_write_raw_P(static_logo, sizeof(static_logo));

    oled_set_cursor(0, 5);

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write("QWRTY", false);
            break;
        case _COLEMAK:
            oled_write("COLMK", false);
            break;
        case _GAMING:
            oled_write("GAMES", false);
            break;
        default:
            oled_write("UNDEF", false);
    }

    oled_set_cursor(0, 7);
    oled_write("LAYER", false);
    oled_set_cursor(0, 8);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write("Base ", false);
            break;
        case _RAISE:
            oled_write("Raise", false);
            break;
        case _LOWER:
            oled_write("Lower", false);
            break;
        case _ADJUST:
            oled_write("Adj  ", false);
            break;
        default:
            oled_write("Undef", false);
    }

    /* WPM START*/
    uint8_t n = get_current_wpm();
    char    wpm_str[4];
    oled_set_cursor(0, 10);
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + (n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);

    oled_set_cursor(0, 11);
    oled_write("wpm", false);

    /* WPM END*/

    oled_set_cursor(0, 13);
    oled_write("-----", false);

}

bool oled_task_user(void) {
  /* KEYBOARD  VARIABLES START */

    current_wpm   = get_current_wpm();

    /* KEYBOARD WPM VARIABLES END */

  if (is_keyboard_master()) {
    print_status_narrow();
  } else {
    oled_write_raw_P(arasaka, frame_size);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_GAMING:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAMING);
            }
            return false;

  }
  return true;
}
