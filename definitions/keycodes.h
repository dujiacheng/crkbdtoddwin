#pragma once

 

// clang-format off

// Tap dance codes
 
 

// Custom keycodes

enum {
    CUSTOM_KEYCODE_START = SAFE_RANGE,

    MC_SECRET_1,

    // Toggle codes
    OS_ACNT, TG_WIN, TG_MAC, TG_CASE, TG_ACNT, 

    // Select Word/Line
    MC_SELW, MC_SELL,
    
    // Swapper
    MC_MODP, MC_MODM, MC_SWLE, MC_SWRI, 
    
    // Begin macros that can be shifted
    SFT_MACRO_START,

    // Common shortcuts
    MC_SELC, MC_SAVE, MC_UNDO, MC_COPY, MC_SCOP, MC_CLOS, 
    MC_PAST, MC_SPAS, MC_LOCK, MC_FULL, MC_FIND, MC_Z0R,
    MC_D, 

    // App Shortcuts
    MC_PREV, MC_TABS, MC_CALC, MC_MIC, MC_CAM,

    // IDE shortcuts
    MC_QUIK, MC_AUCO, MC_COMT, MC_STIN, MC_STOV, MC_DOWN,
    MC_QDOC, MC_FSYM, MC_RUN, MC_DBUG, MC_BUID, MC_BREK,
    MC_PROJ, MC_RECE, MC_SWAP, MC_FIUS, MC_REFC, 

    // Begin macros used to write text
    STR_MACRO_START,

    MC_BTIC, MC_DQUO, MC_SQUO, MC_CIRC, MC_TILD, MC_ORDO, MC_ORDA,
    MC_EUR, MC_LTE, MC_GTE, MC_DDS, MC_ENT, MC_TAB, MC_ESC, MC_ESCC, 
    TG_NUMC, MC_EXLM, MC_QUES, MC_ESAV, MC_SENT, MC_DEG, MC_DELW, MC_LY,
    MC_CUR, MC_CURS, MC_DAR, MC_SAR, MC_DEQ, MC_NEQ, MC_BRAC, MC_SEC, 
    MC_DAND, MC_DPIP, MC_OESC, MC_SOES, MC_TISL, MC_SVI, MC_CVI, MC_0P,
    REPEAT, MAGIC, MC_JOIN, MC_EENT, MC_DEND, MC_US, MC_BR,

    // End macros that can be shifted
    SFT_MACRO_END,

    // Start macros for accented letters
    ACCENT_MACRO_START,

    MC_GV_A, MC_CR_A, MC_SQ_A, MC_QU, MC_AH,
    MC_SQ_U, MC_CR_O, MC_SQ_O, MC_SQ_I,
    MC_CR_E, MC_SQ_C, MC_SQ_E, MC_TL_A, MC_TL_O,

    // End macros for accented letters
    ACCENT_MACRO_END,
    
    // End macros used to write text
    STR_MACRO_END,

#ifndef MOUSE_ENABLE
    OM_U,
    OM_D,
    OM_L,
    OM_R,
    OM_BTNS,
    OM_HLDS,
    OM_RELS,
    OM_W_U,
    OM_W_D,
    OM_BTN1,
    OM_BTN2,
#endif

    CUSTOM_KEYCODE_END
};


// clang-format on