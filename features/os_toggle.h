#pragma once

#include QMK_KEYBOARD_H

#include "os_detection.h"
#include "../definitions/keycodes.h"
#include "../definitions/process_record.h"



bool                    is_macos(void);
bool                    is_windows(void);
process_record_result_t process_os_toggle(uint16_t keycode, keyrecord_t *record);
