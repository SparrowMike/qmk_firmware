TAP_DANCE_ENABLE = yes
OLED_ENABLE = yes
OLED_DRIVER = ssd1306

WPM_ENABLE = yes
LTO_ENABLE = yes
RGBLIGHT_ENABLE = yes

MOUSEKEY_ENABLE  = no # Mouse keys(+4700)

WPM_ENABLE = yes

OLED_DRIVER_ENABLE = yes
OCEAN_DREAM_ENABLE = yes
BONGO_ENABLE = no

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)

    ifdef OCEAN_DREAM_ENABLE
        ifeq ($(strip $(OCEAN_DREAM_ENABLE)), yes)
            SRC += ./animation/ocean_dream.c
            OPT_DEFS += -DOCEAN_DREAM_ENABLE
        endif
    endif
    ifndef OCEAN_DREAM_ENABLE
        SRC += ./animation/ocean_dream.c
        OPT_DEFS += -DOCEAN_DREAM_ENABLE
    endif
endif
