#include "../../src/kernel/os_api.h"

extern "C" int main(OS_API* api) {
    int win_w = 400;
    int win_h = 300;
    
    api->draw_macos_wallpaper();
    api->blankUI_draw_menubar();
    api->blankUI_draw_dock();
    
    api->blankUI_draw_window(win_w, win_h, (char*)"BlankDrop (Native ELF)");
    
    api->blankUI_draw_text_color(50, 50, (char*)"Discovering devices...", 0xFFFFFF);
    api->blankUI_draw_button(50, 100, 300, 50, (char*)"No devices found.");
    
    api->swap_buffers();
    return 0;
}
