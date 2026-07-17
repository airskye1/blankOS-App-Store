#include "../../src/kernel/os_api.h"

extern "C" int main(OS_API* api) {
    int win_w = 900;
    int win_h = 600;
    
    api->draw_macos_wallpaper();
    api->blankUI_draw_menubar();
    api->blankUI_draw_dock();
    
    api->blankUI_draw_window(win_w, win_h, (char*)"YouTube (Native ELF)");
    
    // Video player mock
    api->blankUI_draw_button(50, 50, 500, 300, (char*)"[ VIDEO PLAYER MOCK ]");
    api->blankUI_draw_text_color(50, 370, (char*)"Building a Custom OS from Scratch", 0xFFFFFF);
    api->blankUI_draw_text_color(50, 400, (char*)"1M views - 1 day ago", 0xAAAAAA);
    
    // Suggested videos
    api->blankUI_draw_button(580, 50, 300, 80, (char*)"Recommended 1");
    api->blankUI_draw_button(580, 150, 300, 80, (char*)"Recommended 2");
    api->blankUI_draw_button(580, 250, 300, 80, (char*)"Recommended 3");
    
    api->swap_buffers();
    return 0;
}
