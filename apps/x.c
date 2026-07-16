#include "../../src/sdk/blankC/blankC.h"

// Networking stubs
extern char* http_get_with_auth(char* url, char* token);
extern void http_post_with_auth(char* url, char* token, char* payload);

extern char* blankReg_read_string(char* key);

void render_x_timeline(char* json_tweets) {
    // Parse JSON
    // Loop through tweets:
    // Render profile picture circle
    // Render username (bold)
    // Render tweet text
}

void x_main(void) {
    bUI_window(600, 900, "X (Twitter) for BlankOS");
    
    char* token = blankReg_read_string("apps/x/bearer_token");
    
    // Fetch actual X timeline via API v2
    char* timeline = http_get_with_auth("https://api.twitter.com/2/users/12345/tweets", token);
    
    if (timeline) {
        render_x_timeline(timeline);
    }
    
    // Stub for posting a tweet
    // http_post_with_auth("https://api.twitter.com/2/tweets", token, "{\"text\": \"Posting from my custom BlankOS!\"}");
}
