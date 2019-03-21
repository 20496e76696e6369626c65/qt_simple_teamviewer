#include "../include/key_mapper.h"

#ifdef Q_OS_LINUX

#include <X11/keysymdef.h>
#include <X11/Intrinsic.h>

KeyMapper::KeyMapper() {
    key_map_[ Qt::Key_Escape ] = XK_Escape;
    key_map_[ Qt::Key_Tab ] = XK_Tab;
    key_map_[ Qt::Key_Backtab ] = XK_ISO_Left_Tab;
    key_map_[ Qt::Key_Backspace ] = XK_BackSpace;
    key_map_[ Qt::Key_Return ] = XK_Return;
    key_map_[ Qt::Key_Insert ] = XK_Insert;
    key_map_[ Qt::Key_Delete ] = XK_Delete;
    key_map_[ Qt::Key_Pause ] = XK_Pause;
    key_map_[ Qt::Key_Print ] = XK_Print;
    key_map_[ Qt::Key_SysReq ] = 0x1005FF60;

    key_map_[ Qt::Key_Home ] = XK_Home;
    key_map_[ Qt::Key_End ] = XK_End;
    key_map_[ Qt::Key_Left ] = XK_Left;
    key_map_[ Qt::Key_Up ] = XK_Up;
    key_map_[ Qt::Key_Right ] = XK_Right;
    key_map_[ Qt::Key_Down ] = XK_Down;
    key_map_[ Qt::Key_PageUp ] = XK_Prior;
    key_map_[ Qt::Key_PageDown ] = XK_Next;

    key_map_[ Qt::Key_Shift ] = XK_Shift_L;
    key_map_[ Qt::Key_Control ] = XK_Control_L;
    key_map_[ Qt::Key_Meta ] = XK_Meta_L;
    key_map_[ Qt::Key_Alt ] = XK_Alt_L;
    key_map_[ Qt::Key_CapsLock ] = XK_Caps_Lock;
    key_map_[ Qt::Key_NumLock ] = XK_Num_Lock;
    key_map_[ Qt::Key_ScrollLock ] = XK_Scroll_Lock;
    key_map_[ Qt::Key_Super_L ] = XK_Super_L;
    key_map_[ Qt::Key_Super_R ] = XK_Super_R;
    key_map_[ Qt::Key_Menu ] = XK_Menu;
    key_map_[ Qt::Key_Hyper_L ] = XK_Hyper_L;
    key_map_[ Qt::Key_Hyper_R ] = XK_Hyper_R;
    key_map_[ Qt::Key_Help ] = XK_Help;
    key_map_[ Qt::Key_F11 ] = 0x1005FF10;
    key_map_[ Qt::Key_F12 ] = 0x1005FF11;

    key_map_[ Qt::Key_Space ] = XK_space;
    key_map_[ Qt::Key_Enter ] = XK_KP_Enter;
    key_map_[ Qt::Key_F1 ] = XK_KP_F1;
    key_map_[ Qt::Key_F2 ] = XK_KP_F2;
    key_map_[ Qt::Key_F3 ] = XK_KP_F3;
    key_map_[ Qt::Key_F4 ] = XK_KP_F4;
    key_map_[ Qt::Key_Clear ] = XK_KP_Begin;

    key_map_[ Qt::Key_0 ] = XK_0;
    key_map_[ Qt::Key_1 ] = XK_1;
    key_map_[ Qt::Key_2 ] = XK_2;
    key_map_[ Qt::Key_3 ] = XK_3;
    key_map_[ Qt::Key_4 ] = XK_4;
    key_map_[ Qt::Key_5 ] = XK_5;
    key_map_[ Qt::Key_6 ] = XK_6;
    key_map_[ Qt::Key_7 ] = XK_7;
    key_map_[ Qt::Key_8 ] = XK_8;
    key_map_[ Qt::Key_9 ] = XK_9;

    key_map_[ Qt::Key_BracketLeft ] = XK_bracketleft;
    key_map_[ Qt::Key_BracketRight ] = XK_bracketright;

    key_map_[ Qt::Key_A ] = XK_a;
    key_map_[ Qt::Key_B ] = XK_b;
    key_map_[ Qt::Key_C ] = XK_c;
    key_map_[ Qt::Key_D ] = XK_d;
    key_map_[ Qt::Key_E ] = XK_e;
    key_map_[ Qt::Key_F ] = XK_f;
    key_map_[ Qt::Key_G ] = XK_g;
    key_map_[ Qt::Key_H ] = XK_h;
    key_map_[ Qt::Key_I ] = XK_i;
    key_map_[ Qt::Key_J ] = XK_j;
    key_map_[ Qt::Key_K ] = XK_k;
    key_map_[ Qt::Key_L ] = XK_l;
    key_map_[ Qt::Key_M ] = XK_m;
    key_map_[ Qt::Key_N ] = XK_n;
    key_map_[ Qt::Key_O ] = XK_o;
    key_map_[ Qt::Key_P ] = XK_p;
    key_map_[ Qt::Key_Q ] = XK_q;
    key_map_[ Qt::Key_R ] = XK_r;
    key_map_[ Qt::Key_S ] = XK_s;
    key_map_[ Qt::Key_T ] = XK_t;
    key_map_[ Qt::Key_U ] = XK_u;
    key_map_[ Qt::Key_V ] = XK_v;
    key_map_[ Qt::Key_W ] = XK_w;
    key_map_[ Qt::Key_X ] = XK_x;
    key_map_[ Qt::Key_Y ] = XK_y;
    key_map_[ Qt::Key_Z ] = XK_z;
}

uint KeyMapper::FindNativeVirtualKeyCode( Qt::Key key_code ) {
    uint code = 0;

    Display* display = XOpenDisplay( nullptr );
    if( display ) {
        if( key_map_.contains( key_code ) ) {
            code = XKeysymToKeycode( display, key_map_[ key_code ] );
        }
        XCloseDisplay( display );
    }

    return code;
}



#endif
