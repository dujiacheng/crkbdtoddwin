//qmk compile -kb crkbd -km markstos
// qmk flash -c -kb crkbd -km markstos

//qmk compile -kb crkbd -km todd 
// C:\Users\zccpf\qmk_firmware\.build

#include QMK_KEYBOARD_H
 

#include "oneshot.h"
#include "swapper.h"
#include "layer_lock.h"

//#include "definitions/layers.h"
#include "definitions/keycodes.h"
//#include "definitions/keymap_blocks.h"
#include "features/achordion.h"
 
 
#include "features/os_toggle.h"
// #include "features/macros.h"
 
#include "features/shortcuts.h"
#include "features/repeat_key.h"

//#include "features/custom_shift.h"
 


enum custom_keycodes {
  SELWORD = SAFE_RANGE, 
  
  OS_CTRL,
  OS_ALT,
  OS_CMD,
  OS_CAPS, // for use as Globe on iPadOS, via remapping in Settings.app
  APP_SWITCH_FRWD, // cmd-tab but holds cmd between invocations
  SW_LANG,
  LLOCK = SAFE_RANGE,


  // QWERTY = SAFE_RANGE,
  LOWERR,
  RAISE,
  WINDOWS,
  RSE_SPACE,
  LOW_SPC,
  FUNC,
  BACKLIT,  
  HOME_A,
  HOME_S,  
  HOME_D,
  HOME_F,

  HOME_QUOT,
  HOME_L,
  HOME_K,
  HOME_J,
  ALTREP,
  MY_MACRO,

};


#define NAV MO(_NAV)
#define WINNAV MO(_WINNAV)
#define WINDOWS DF(_WINDOWS)
#define FUNC MO(_FUNC)
#define NUM MO(_NUM)
#define RAISE MO(_RAISE)
#define NAVGEMMELL MO(_NAVGEMMELL) 

#define ENT_SHFT RSFT_T(KC_ENT)

enum combos {
    HJ_LALT,
    JK_SFT,
    KL_GUI,
    LQUOT_CTL,
    GF_LALT,
    FD_SFT,
    DS_CTL,
    SA_LALT,
    UPDOWN_SFT,
    FIVESIX_STF

};

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};

const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM lquot_combo[] = {KC_L, KC_QUOT, COMBO_END};

const uint16_t PROGMEM gf_combo[] = {KC_G, KC_F, COMBO_END};
//const uint16_t PROGMEM fd_combo[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM ds_combo[] = {KC_D, KC_S, COMBO_END};
const uint16_t PROGMEM sa_combo[] = {KC_S, KC_A, COMBO_END};
const uint16_t PROGMEM fivesix_combo[] = {KC_5, KC_6, COMBO_END};

const uint16_t PROGMEM updown_combo[] = {KC_DOWN, KC_UP, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  // Add commonly used dash to home row
 //[DF_DASH]    = COMBO(df_combo, KC_MINS),

  // right hand home row


    [HJ_LALT]    = COMBO(hj_combo, KC_LALT),
    //[JK_SFT]    = COMBO(jk_combo, KC_RSFT),
    [UPDOWN_SFT]    = COMBO(updown_combo, KC_LSFT),
    [KL_GUI]    = COMBO(kl_combo, KC_APP), 
    [LQUOT_CTL]    = COMBO(lquot_combo, KC_LCTL), 


    // left hand home row
    [GF_LALT]    = COMBO(gf_combo, KC_LALT),
    //[FD_SFT]    = COMBO(fd_combo, KC_RSFT),
    [DS_CTL]    = COMBO(ds_combo, KC_LGUI), 
    [SA_LALT]    = COMBO(sa_combo, KC_LCTL), 
    [FIVESIX_STF]  =  COMBO(fivesix_combo, KC_LSFT), 

};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layers {
  _QWERTY,
  _LOWERR,
  _RAISE,
  _FUNC,
  _BUTTON,

  _BASE,
  _NAV,
  _WINNAV,
  _NUM,
  _ADJUST,
  _NAVGEMMELL,
  _WINDOWS,
};

// For _QWERTY layer
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_AGR  OSM(MOD_RALT)
#define OSL_FUN  OSL(_FUNC)
#define OSM_SFT  OSM(MOD_LSFT) 
#define OSM_ALT  OSM(MOD_LALT) 

// 按完进入该层， 敲击一次后，就退出该层
#define GUI_ENT  GUI_T(KC_SPC)
#define LOW_SPC LT(_LOWERR, KC_SPC)
#define NAV_SPC LT(_NAV, KC_SPC)
#define NAV_REP LT(_NAV, REPEAT)
 
#define LOW_ESC LT(_LOWERR, KC_ESC)
#define GUI_ESC  GUI_T(KC_ESC)

#define RSE_BSP  LT(_RAISE, KC_BSPC)
#define RSE_ENT  LT(_RAISE, KC_ENT)
#define RSE_SPACE LT(MOD_LSFT, KC_SPC)

#define HOME_A LALT_T(KC_A)
#define HOME_S LCTL_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

#define HOME_QUOT LALT_T(KC_QUOT)
#define HOME_L LCTL_T(KC_L)
#define HOME_K LGUI_T(KC_K)
#define HOME_J RSFT_T(KC_J)


#define NAV_UND LT(NAV, KC_MINS)
#define LALT_ESC LT(MOD_LALT, KC_ESC)

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_FIND LGUI(KC_F)
#define KC_MAC_REDO LSFT(LGUI(KC_Z))
#define KC_MAC_CUT LGUI(KC_X)

#define KC_MAC_SAVE LGUI(KC_S)
#define KC_MAC_CLOSE LGUI(KC_W)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_MAC_LOCK_SCRN LCTL(LGUI(KC_Q))
#define KC_MAC_PREV_TAB LGUI(LSFT(KC_LBRC))
#define KC_MAC_NEXT_TAB LGUI(LSFT(KC_RBRC))
#define KC_MAC_SPOTLIGHT LGUI(KC_SPC)

#define KC_WIN_UNDO LCTL(KC_Z)
#define KC_WIN_FIND LCTL(KC_F)
#define KC_WIN_REDO LSFT(LCTL(KC_Z))
#define KC_WIN_CUT LCTL(KC_X)
#define KC_WIN_TAB_R LCTL(KC_TAB)

#define KC_WIN_SAVE LCTL(KC_S)
#define KC_WIN_SLEEP LGUI(KC_L)
#define KC_WIN_CLOSE LCTL(KC_W)
#define KC_WIN_COPY LCTL(KC_C)
#define KC_WIN_PASTE LCTL(KC_V)
#define ALT_X LALT(KC_X)
#define KC_WIN_LOCK_SCRN LCTL(LCTL(KC_Q))


#define KC_EN_DASH LALT(KC_MINUS)
#define KC_EM_DASH LSFT(LALT(KC_MINUS))


#define HOME G(KC_LEFT)
#define END G(KC_RGHT)
#define SCREENSHOT G(S(KC_4))
#define TRANSLATE G(S(KC_6))
#define PYCRUN LCTL(LSFT(KC_R))



#define SPACE_L LCTL(KC_LEFT)
#define SPACE_R LCTL(KC_RGHT)

// For _RAISE layer 
#define CTL_ESC  LCTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(  
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_F1,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,MY_MACRO  ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
 KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H    ,KC_J    ,KC_K    ,KC_L  ,KC_QUOT , KC_ENT ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  KC_LSFT,   KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,                             KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH , TG_WIN ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       KC_APP, WINNAV, LOW_SPC, MT(MOD_RSFT, KC_SPC) ,  RAISE  ,KC_LALT
                                      //`----------KC_LGUI----------'  `--------------------------'
  ),     


   [_WINNAV] = LAYOUT( 
       _______, KC_ESC,KC_WIN_CLOSE,KC_WIN_TAB_R, APP_SWITCH_FRWD,SCREENSHOT,    KC_HOME,   SPACE_L,    KC_UP,   SPACE_R,     KC_BSPC,_______,
       _______,KC_ENT,KC_WIN_SAVE,MC_D,KC_WIN_FIND,TRANSLATE,               KC_CAPS, KC_LEFT, KC_DOWN, KC_WIN_SLEEP, KC_ENT,OSM(MOD_LCTL),
       _______,KC_WIN_UNDO,KC_WIN_CUT,KC_WIN_COPY,KC_WIN_PASTE,PYCRUN,     KC_END, KC_PGDN, KC_PGUP, SW_LANG,  KC_DEL,_______,
                                   ALT_X,  _______, KC_LGUI,              _______, _______, _______
  ),
  
   [_NAV] = LAYOUT( 
       _______, KC_ESC,KC_MAC_CLOSE,KC_WIN_TAB_R, APP_SWITCH_FRWD,SCREENSHOT,    KC_HOME,   SPACE_L,    KC_UP,   SPACE_R,     KC_BSPC,_______,
       _______,KC_ENT,KC_MAC_SAVE,MC_D,KC_MAC_FIND,TRANSLATE,               KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,OSM(MOD_LCTL),
       _______,KC_MAC_UNDO,KC_MAC_CUT,KC_MAC_COPY,KC_MAC_PASTE,PYCRUN,     KC_END, KC_PGDN, KC_PGUP, SW_LANG,  KC_DEL,_______,
                                   OS_ALT,  _______, _______,              _______, WINNAV, _______
  ),

     
  [_RAISE] = LAYOUT(  
  //,---------------------------------------------  KC_LBRC, KC_RBRC                   ,---------....,,-----------------------------------------------------.
      KC_MPLY, KC_ESC , KC_7,    KC_8,    KC_9,  KC_LBRC,                      KC_RBRC, KC_VOLD, KC_TAB, KC_BSPC, KC_VOLU,MY_MACRO ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_MINS, KC_4,    KC_5,   KC_6,  KC_EQL,                      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_ENT,  ALTREP ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_GRV  , KC_1,    KC_2,   KC_3, KC_BSLS,                      KC_MINS, KC_MPRV, KC_COMM,KC_DOT, KC_COLN, KC_SCLN ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          FUNC,  KC_0, OSM_SFT,    RAISE  , KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),                                         
//KC_DEL , XXXXXXX, KC_UNDS, KC_PLUS, KC_PGUP   
// KC_HOME, KC_END , KC_MINS, KC_EQL , KC_PGDN    
//KC_LT  , KC_GT  , KC_COPY, KC_PSTE, KC_SCLN

  [_NAVGEMMELL] = LAYOUT(
      _______, KC_ESC,      APP_SWITCH_FRWD,    XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_PGUP,     KC_MAC_PREV_TAB,  KC_UP,           KC_MAC_NEXT_TAB, KC_BSPC, _______,
      _______, KC_LALT,   KC_LCTL, KC_LCMD,  KC_LSFT, XXXXXXX,                    KC_PGDN,      KC_LEFT,          KC_DOWN,         KC_RIGHT,        XXXXXXX, _______,
      _______, KC_MAC_UNDO, KC_MAC_CUT, KC_MAC_COPY,    KC_MAC_PASTE,           KC_MAC_REDO,  XXXXXXX,       KC_MAC_SPOTLIGHT, XXXXXXX, XXXXXXX,   KC_ENT,  _______,
                                          _______, _______, _______,            _______, _______, _______
  ),
  [_LOWERR] = LAYOUT(
      _______,  _______,  KC_F1, KC_F2 , KC_F3, KC_F10 ,                   KC_AMPR, KC_VOLD, KC_VOLU, _______, _______,_______,
      _______,  _______,    KC_F4, KC_PLUS, KC_EQL , KC_INS,                   KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_PERC,_______,
      _______, _______,    KC_SLSH, KC_ASTR, KC_CIRC, XXXXXXX,                  KC_TILD, KC_DLR , KC_LCBR, KC_RCBR, _______,_______,
                                          _______, _______, _______,            KC_LSFT, _______, _______
  ), 

  [_FUNC] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_F1  , KC_F2  , KC_F3   , KC_F4 ,  KC_F5 ,                     KC_F6   , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,_______ ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_F11 , KC_F12 , XXXXXXX, XXXXXXX,  XXXXXXX ,                  XXXXXXX , KC_LSFT , KC_LCMD, KC_LCTL, KC_LALT,_______ ,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX , KC_VOLD, KC_VOLU, XXXXXXX, QK_BOOT,XXXXXXX ,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, FUNC   , XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case LT(_RAISE, KC_BSPC):
            return TAPPING_TERM_THUMB;
      case LT(_LOWERR, KC_TAB):
            return TAPPING_TERM_THUMB;
      default:
            return TAPPING_TERM;
    }
}  

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case NAV:
    case NUM:
    //case B_NUM:
    //case SPC_NAV:
    //case KC_ESC:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case NAV:
    case NUM:
    //case B_NUM:
    //case SPC_NAV:
    case KC_LSFT:
    //case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
    case OS_CAPS:
        return true;
    default:
        return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;
oneshot_state os_caps_state = os_up_unqueued;

bool app_switch_frwd_active = false;
bool sw_lang_active = false;

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
  if ((mods & MOD_MASK_CTRL)) {   // Was Ctrl held?
    switch (keycode) {
      case KC_A: return C(KC_C);  // Ctrl + Y reverses to Ctrl + Z.
      case KC_C: return C(KC_V);  // Ctrl + Z reverses to Ctrl + Y.
    }
  }

  switch (keycode) {
    case MY_MACRO: return MY_MACRO;  // MY_MACRO is its own alternate.
  }
  return KC_TRNS;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
   // if (!process_repeat_key(keycode, record, REPEAT)) { return false; }
    // if (!process_repeat_key_with_alt(keycode, record, REPEAT, KC_LALT)) {
    //   return false;
    // }
    // switch (keycode) {
    //   case MY_MACRO:
    //     if (get_repeat_key_count() > 0) {        // Repeating.
    //       if (record->event.pressed) {
    //         SEND_STRING("repeat!");    
    //       }
    //     } else if (get_repeat_key_count() < 0) { // Alternate repeating.
    //       if (record->event.pressed) {
    //         SEND_STRING("alternate!");    
    //       }
    //     } else {                                 // Used normally.
    //       if (record->event.pressed) {  
    //         SEND_STRING("macro");
    //       }
    //     }
    //     return false;
   
    // // Other macros...
    // }


    //if (!process_achordion(keycode, record)) { return false; }

    // switch (process_shortcuts(keycode, record)) {
    //     case PROCESS_RECORD_RETURN_TRUE:
    //         return true;
    //     case PROCESS_RECORD_RETURN_FALSE:
    //         return false;
    //     default:
    //         break;
    // };
    // // Process OS toggle
    // switch (process_os_toggle(keycode, record)) {
    //     case PROCESS_RECORD_RETURN_TRUE:
    //         return true;
    //     case PROCESS_RECORD_RETURN_FALSE:
    //         return false;
    //     default:
    //         break;
    // };
    
    update_swapper(
        &app_switch_frwd_active, KC_LALT, KC_TAB, APP_SWITCH_FRWD,
        keycode, record
    ); 
    // update_swapper(
    //     &sw_lang_active, KC_LCTL, KC_SPC, SW_LANG,
    //     keycode, record
    // );

    // update_oneshot(
    //     &os_shft_state, KC_LSFT, OS_SHFT,
    //     keycode, record
    // );
    // update_oneshot(
    //     &os_ctrl_state, KC_LCTL, OS_CTRL,
    //     keycode, record
    // );
    // update_oneshot(
    //     &os_alt_state, KC_LALT, OS_ALT,
    //     keycode, record
    // );
    // update_oneshot(
    //     &os_cmd_state, KC_LCMD, OS_CMD,
    //     keycode, record
    // );
    // update_oneshot(
    //     &os_caps_state, KC_CAPS, OS_CAPS,
    //     keycode, record
    // );

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _NUM, _ADJUST);
}