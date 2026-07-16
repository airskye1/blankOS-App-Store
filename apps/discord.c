#include "../../src/sdk/blankC/blankC.h"

// Networking stubs pointing to Discord's actual API
extern char* http_get_with_auth(char* url, char* token);
extern void http_post_with_auth(char* url, char* token, char* payload);

// The user's Discord bot token or OAuth token stored in blankReg
extern char* blankReg_read_string(char* key);

void render_discord_sidebar(char* json_servers) {
    // Parse JSON to get server list
    // Use bUI_button to draw server icons vertically on the left
}

void render_discord_chat(char* json_messages) {
    // Parse JSON to get messages
    // Use bUI_text to draw messages in the main window
}

void discord_main(void) {
    bUI_window(1000, 700, "Discord for BlankOS");
    
    char* token = blankReg_read_string("apps/discord/token");
    if (!token) {
        bUI_text(400, 300, "Please login to Discord in settings.");
        return;
    }
    
    // Fetch user's servers via actual Discord API
    char* servers = http_get_with_auth("https://discord.com/api/v10/users/@me/guilds", token);
    render_discord_sidebar(servers);
    
    // Fetch messages for a specific channel
    char* messages = http_get_with_auth("https://discord.com/api/v10/channels/123456789/messages", token);
    render_discord_chat(messages);
    
    // Stub for sending a message
    // http_post_with_auth("https://discord.com/api/v10/channels/123456789/messages", token, "{\"content\": \"Hello from BlankOS!\"}");
}
