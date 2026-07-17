#include "../../src/kernel/os_api.h"

// Basic string matching since we have no stdlib
bool str_eq(const char* a, const char* b) {
    while (*a && *b) {
        if (*a != *b) return false;
        a++; b++;
    }
    return (*a == *b);
}

extern "C" int main(OS_API* api) {
    int win_w = 800;
    int win_h = 600;
    
    bool running = true;
    while (running) {
        api->draw_macos_wallpaper();
        api->blankUI_draw_menubar();
        api->blankUI_draw_dock();
        
        api->blankUI_draw_window(win_w, win_h, (char*)"Discord (Native ELF)");
        
        // Sidebar
        api->blankUI_draw_button(0, 0, 80, win_h, (char*)""); 
        api->blankUI_draw_text_color(20, 50, (char*)"S1", 0xFFFFFF);
        api->blankUI_draw_text_color(20, 100, (char*)"S2", 0xFFFFFF);
        
        // Main Chat Area
        api->blankUI_draw_text_color(100, 50, (char*)"#general", 0xAAAAAA);
        api->blankUI_draw_text_color(100, 100, (char*)"airskye: Ethernet support is coming!", 0xDDDDDD);
        api->blankUI_draw_text_color(100, 130, (char*)"user: This ELF loader is amazing.", 0xDDDDDD);
        
        // Input box
        api->blankUI_draw_button(100, win_h - 60, win_w - 120, 40, (char*)"Message #general");
        
        // Handle input (Simplified hit test for closing)
        // Wait, we need cursor position from SystemTable
        // But api->blankUI_hit_test_window_close takes cursor coords.
        // We can just rely on the OS sending a close signal or we check mouse state.
        
        api->swap_buffers();
        
        // Mock break condition to let OS regain control (since we don't have preemptive multitasking yet)
        // In a real scenario, this would block on an event loop.
        break; 
    }
    return 0;
}
