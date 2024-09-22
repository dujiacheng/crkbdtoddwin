#include QMK_KEYBOARD_H

#include "shortcuts.h"


process_record_result_t process_shortcut_keycode(uint16_t keycode ) {
    bool isWindows = is_windows();

    switch (keycode) {
            // Select All
        case MC_COPY:
            if (!isWindows) {
                SEND_STRING(SS_LGUI("c"));
            } else {
                SEND_STRING(SS_LCTL("c"));
            }
            return PROCESS_RECORD_RETURN_FALSE;

        case MC_PAST:
            if (!isWindows) {
                SEND_STRING(SS_LGUI("v"));
            } else {
                SEND_STRING(SS_LCTL("v"));
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_D:
            if (!isWindows) {
                SEND_STRING(SS_LGUI("d"));
            } else {
                SEND_STRING(SS_LCTL("d"));
            }
            return PROCESS_RECORD_RETURN_FALSE;    
    }

    return PROCESS_RECORD_CONTINUE;
}

process_record_result_t process_shortcuts(uint16_t keycode ,keyrecord_t *record ) {

    if (record != NULL && !record->event.pressed) {
        return PROCESS_RECORD_CONTINUE;
    }// 检查按键是否按下 ， 按键抬起时不执行任何操作


    process_record_result_t result = process_shortcut_keycode(keycode );


    return result;
}