#include "../include/key_mapper.h"

#ifdef Q_OS_WIN32

#include <windows.h>

KeyMapper::KeyMapper() {
    key_map_[ Qt::Key_Cancel ] = VK_CANCEL;
    key_map_[ Qt::Key_Backspace ] = VK_BACK;
    key_map_[ Qt::Key_Tab ] = VK_TAB;
    key_map_[ Qt::Key_Clear ] = VK_CLEAR;
    key_map_[ Qt::Key_Return ] = VK_RETURN;
    key_map_[ Qt::Key_Shift ] = VK_SHIFT;
    key_map_[ Qt::Key_Control ] = VK_CONTROL;
    key_map_[ Qt::Key_Alt ] = VK_MENU;
    key_map_[ Qt::Key_Pause ] = VK_PAUSE;
    key_map_[ Qt::Key_CapsLock ] = VK_CAPITAL;
    key_map_[ Qt::Key_Escape ] = VK_ESCAPE;
    key_map_[ Qt::Key_Mode_switch ] = VK_MODECHANGE;
    key_map_[ Qt::Key_Space ] = VK_SPACE;
    key_map_[ Qt::Key_PageUp ] = VK_PRIOR;
    key_map_[ Qt::Key_PageDown ] = VK_NEXT;
    key_map_[ Qt::Key_End ] = VK_END;
    key_map_[ Qt::Key_Home ] = VK_HOME;
    key_map_[ Qt::Key_Left ] = VK_LEFT;
    key_map_[ Qt::Key_Up ] = VK_UP;
    key_map_[ Qt::Key_Right ] = VK_RIGHT;
    key_map_[ Qt::Key_Down ] = VK_DOWN;
    key_map_[ Qt::Key_Select ] = VK_SELECT;
    key_map_[ Qt::Key_Printer ] = VK_PRINT;
    key_map_[ Qt::Key_Execute ] = VK_EXECUTE;
    key_map_[ Qt::Key_Print ] = VK_SNAPSHOT;
    key_map_[ Qt::Key_Insert ] = VK_INSERT;
    key_map_[ Qt::Key_Delete ] = VK_DELETE;
    key_map_[ Qt::Key_Help ] = VK_HELP;
    key_map_[ Qt::Key_0 ] = 0x30; //  (VK_0)              | 0 key
    key_map_[ Qt::Key_1 ] = 0x31; //  (VK_1)              | 1 key
    key_map_[ Qt::Key_2 ] = 0x32; //  (VK_2)              | 2 key
    key_map_[ Qt::Key_3 ] = 0x33; //  (VK_3)              | 3 key
    key_map_[ Qt::Key_4 ] = 0x34; //  (VK_4)              | 4 key
    key_map_[ Qt::Key_5 ] = 0x35; //  (VK_5)              | 5 key
    key_map_[ Qt::Key_6 ] = 0x36; //  (VK_6)              | 6 key
    key_map_[ Qt::Key_7 ] = 0x37; //  (VK_7)              | 7 key
    key_map_[ Qt::Key_8 ] = 0x38; //  (VK_8)              | 8 key
    key_map_[ Qt::Key_9 ] = 0x39; //  (VK_9)              | 9 key
    key_map_[ Qt::Key_A ] = 0x41; //  (VK_A)              | A key
    key_map_[ Qt::Key_B ] = 0x42; //  (VK_B)              | B key
    key_map_[ Qt::Key_C ] = 0x43; //  (VK_C)              | C key
    key_map_[ Qt::Key_D ] = 0x44; //  (VK_D)              | D key
    key_map_[ Qt::Key_E ] = 0x45; //  (VK_E)              | E key
    key_map_[ Qt::Key_F ] = 0x46; //  (VK_F)              | F key
    key_map_[ Qt::Key_G ] = 0x47; //  (VK_G)              | G key
    key_map_[ Qt::Key_H ] = 0x48; //  (VK_H)              | H key
    key_map_[ Qt::Key_I ] = 0x49; //  (VK_I)              | I key
    key_map_[ Qt::Key_J ] = 0x4A; //  (VK_J)              | J key
    key_map_[ Qt::Key_K ] = 0x4B; //  (VK_K)              | K key
    key_map_[ Qt::Key_L ] = 0x4C; //  (VK_L)              | L key
    key_map_[ Qt::Key_M ] = 0x4D; //  (VK_M)              | M key
    key_map_[ Qt::Key_N ] = 0x4E; //  (VK_N)              | N key
    key_map_[ Qt::Key_O ] = 0x4F; //  (VK_O)              | O key
    key_map_[ Qt::Key_P ] = 0x50; //  (VK_P)              | P key
    key_map_[ Qt::Key_Q ] = 0x51; //  (VK_Q)              | Q key
    key_map_[ Qt::Key_R ] = 0x52; //  (VK_R)              | R key
    key_map_[ Qt::Key_S ] = 0x53; //  (VK_S)              | S key
    key_map_[ Qt::Key_T ] = 0x54; //  (VK_T)              | T key
    key_map_[ Qt::Key_U ] = 0x55; //  (VK_U)              | U key
    key_map_[ Qt::Key_V ] = 0x56; //  (VK_V)              | V key
    key_map_[ Qt::Key_W ] = 0x57; //  (VK_W)              | W key
    key_map_[ Qt::Key_X ] = 0x58; //  (VK_X)              | X key
    key_map_[ Qt::Key_Y ] = 0x59; //  (VK_Y)              | Y key
    key_map_[ Qt::Key_Z ] = 0x5A; //  (VK_Z)              | Z key
    key_map_[ Qt::Key_Meta ] = VK_LWIN;
    key_map_[ Qt::Key_Menu ] = VK_APPS;
    key_map_[ Qt::Key_Sleep ] = VK_SLEEP;
    key_map_[ Qt::Key_0 ] = VK_NUMPAD0;
    key_map_[ Qt::Key_1 ] = VK_NUMPAD1;
    key_map_[ Qt::Key_2 ] = VK_NUMPAD2;
    key_map_[ Qt::Key_3 ] = VK_NUMPAD3;
    key_map_[ Qt::Key_4 ] = VK_NUMPAD4;
    key_map_[ Qt::Key_5 ] = VK_NUMPAD5;
    key_map_[ Qt::Key_6 ] = VK_NUMPAD6;
    key_map_[ Qt::Key_7 ] = VK_NUMPAD7;
    key_map_[ Qt::Key_8 ] = VK_NUMPAD8;
    key_map_[ Qt::Key_9 ] = VK_NUMPAD9;
    key_map_[ Qt::Key_F1 ] = VK_F1;
    key_map_[ Qt::Key_F2 ] = VK_F2;
    key_map_[ Qt::Key_F3 ] = VK_F3;
    key_map_[ Qt::Key_F4 ] = VK_F4;
    key_map_[ Qt::Key_F5 ] = VK_F5;
    key_map_[ Qt::Key_F6 ] = VK_F6;
    key_map_[ Qt::Key_F7 ] = VK_F7;
    key_map_[ Qt::Key_F8 ] = VK_F8;
    key_map_[ Qt::Key_F9 ] = VK_F9;
    key_map_[ Qt::Key_F10 ] = VK_F10;
    key_map_[ Qt::Key_F11 ] = VK_F11;
    key_map_[ Qt::Key_F12 ] = VK_F12;
    key_map_[ Qt::Key_F13 ] = VK_F13;
    key_map_[ Qt::Key_F14 ] = VK_F14;
    key_map_[ Qt::Key_F15 ] = VK_F15;
    key_map_[ Qt::Key_F16 ] = VK_F16;
    key_map_[ Qt::Key_F17 ] = VK_F17;
    key_map_[ Qt::Key_F18 ] = VK_F18;
    key_map_[ Qt::Key_F19 ] = VK_F19;
    key_map_[ Qt::Key_F20 ] = VK_F20;
    key_map_[ Qt::Key_F21 ] = VK_F21;
    key_map_[ Qt::Key_F22 ] = VK_F22;
    key_map_[ Qt::Key_F23 ] = VK_F23;
    key_map_[ Qt::Key_F24 ] = VK_F24;
    key_map_[ Qt::Key_NumLock ] = VK_NUMLOCK;
    key_map_[ Qt::Key_ScrollLock ] = VK_SCROLL;
    key_map_[ Qt::Key_Back ] = VK_BROWSER_BACK;
    key_map_[ Qt::Key_Forward ] = VK_BROWSER_FORWARD;
    key_map_[ Qt::Key_Refresh ] = VK_BROWSER_REFRESH;
    key_map_[ Qt::Key_Stop ] = VK_BROWSER_STOP;
    key_map_[ Qt::Key_Search ] = VK_BROWSER_SEARCH;
    key_map_[ Qt::Key_Favorites ] = VK_BROWSER_FAVORITES;
    key_map_[ Qt::Key_HomePage ] = VK_BROWSER_HOME;
    key_map_[ Qt::Key_VolumeMute ] = VK_VOLUME_MUTE;
    key_map_[ Qt::Key_VolumeDown ] = VK_VOLUME_DOWN;
    key_map_[ Qt::Key_VolumeUp ] = VK_VOLUME_UP;
    key_map_[ Qt::Key_MediaNext ] = VK_MEDIA_NEXT_TRACK;
    key_map_[ Qt::Key_MediaPrevious ] = VK_MEDIA_PREV_TRACK;
    key_map_[ Qt::Key_MediaStop ] = VK_MEDIA_STOP;
    key_map_[ Qt::Key_MediaPlay ] = VK_MEDIA_PLAY_PAUSE;
    key_map_[ Qt::Key_LaunchMail ] = VK_LAUNCH_MAIL;
    key_map_[ Qt::Key_LaunchMedia ] = VK_LAUNCH_MEDIA_SELECT;
    key_map_[ Qt::Key_Launch0 ] = VK_LAUNCH_APP1;
    key_map_[ Qt::Key_Launch1 ] = VK_LAUNCH_APP2;

    key_map_[ Qt::Key_Play ] = VK_PLAY;
    key_map_[ Qt::Key_Zoom ] = VK_ZOOM;
}

uint KeyMapper::FindNativeVirtualKeyCode( Qt::Key key_code ) {
    uint code = 0;

    if( key_map_.contains( key_code ) ) {
        code = key_map_[ key_code ];
    }

    return code;
}
#endif



