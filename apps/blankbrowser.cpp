#include "../../src/kernel/os_api.h"

extern "C" int main(OS_API* api) {
    int win_w = 800;
    int win_h = 600;
    
    api->draw_macos_wallpaper();
    api->blankUI_draw_menubar();
    api->blankUI_draw_dock();
    
    api->blankUI_draw_window(win_w, win_h, (char*)"BlankBrowser (Native ELF)");
    
    // URL Bar
    api->blankUI_draw_button(50, 50, 700, 30, (char*)"https://google.com");
    
    // Browser Content
    api->blankUI_draw_text_color(50, 100, (char*)"Connecting via EFI_HTTP_PROTOCOL (Simulated)...", 0xAAAAAA);
    api->blankUI_draw_text_color(50, 130, (char*)"Error: No route to host. (Physical network not bridged in VM)", 0xFF8888);
    
    api->swap_buffers();
    return 0;
}
