# markstos: enable media keys
EXTRAKEY_ENABLE = yes

# markstos: smaller file size, little down-side
LTO_ENABLE = yes

COMBO_ENABLE = yes

#miryoku Auto Shift  
#AUTO_SHIFT_ENABLE = yes

#这将启用 OS 检测功能，该功能允许键盘检测它连接到的操作系统并相应地调整其行为。
OS_DETECTION_ENABLE = yes

# This is for RGB *underglow*
# https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md
RGBLIGHT_ENABLE = no

#SRC += oneshot.c
SRC += swapper.c
#SRC += layer_lock.c
#SRC += features/os_toggle.c
#SRC += features/shortcuts.c
SRC += features/repeat_key.c
SRC += features/select_word.c

#SRC += features/achordion.c