#include "../../src/kernel/os_api.h"

extern "C" int main(OS_API* api) {
    int win_w = 600;
    int win_h = 700;
    
    api->draw_macos_wallpaper();
    api->blankUI_draw_menubar();
    api->blankUI_draw_dock();
    
    api->blankUI_draw_window(win_w, win_h, (char*)"X (Native ELF)");
    
    // Feed
    api->blankUI_draw_text_color(20, 50, (char*)"Home / For You", 0xFFFFFF);
    
    // Tweet 1
    api->blankUI_draw_text_color(20, 100, (char*)"@airskye", 0x8888FF);
    api->blankUI_draw_text_color(20, 120, (char*)"Just wrote an ELF loader for BlankOS! #OSDev", 0xFFFFFF);
    
    // Tweet 2
    api->blankUI_draw_text_color(20, 180, (char*)"@blankos", 0x8888FF);
    api->blankUI_draw_text_color(20, 200, (char*)"Ethernet support is on the roadmap.", 0xFFFFFF);
    
    api->swap_buffers();
    return 0;
}
