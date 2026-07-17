#include "../../src/kernel/os_api.h"

extern "C" int main(OS_API* api) {
    int win_w = 700;
    int win_h = 500;
    
    api->draw_macos_wallpaper();
    api->blankUI_draw_menubar();
    api->blankUI_draw_dock();
    
    api->blankUI_draw_window(win_w, win_h, (char*)"Settings (Native ELF)");
    
    // Sidebar
    api->blankUI_draw_button(0, 0, 150, win_h, (char*)"");
    api->blankUI_draw_text_color(20, 50, (char*)"Wi-Fi", 0xFFFFFF);
    api->blankUI_draw_text_color(20, 100, (char*)"Bluetooth", 0xFFFFFF);
    api->blankUI_draw_text_color(20, 150, (char*)"Network", 0xFFFFFF);
    
    // Main Area
    api->blankUI_draw_text_color(170, 50, (char*)"Wi-Fi Hardware", 0xFFFFFF);
    api->blankUI_draw_text_color(170, 80, (char*)"Status: PCI Scanning...", 0xAAAAAA);
    
    api->blankUI_draw_text_color(170, 150, (char*)"Bluetooth Hardware", 0xFFFFFF);
    api->blankUI_draw_text_color(170, 180, (char*)"Status: USB HCI Scanning...", 0xAAAAAA);
    
    api->swap_buffers();
    return 0;
}
