#include <nds.h>
#include <stdio.h>

typedef enum {
    SCREEN_TITLE,
    SCREEN_DEMO
} Screen;

static Screen screen = SCREEN_TITLE;
static int star_x = 128;
static int star_y = 112;
static int accent = 0;

static void draw_title(void) {
    consoleClear();
    iprintf("\x1b[2;5H EQU ESTRIA GIRLS DS");
    iprintf("\x1b[5;4H A tiny Nintendo DS homebrew demo");
    iprintf("\x1b[8;3H Press A or START to begin");
    iprintf("\x1b[10;3H D-pad: move star in demo");
    iprintf("\x1b[11;3H X: change accent  B: return");
    iprintf("\x1b[15;2H Prototype only - original placeholder art");
}

static void draw_demo(void) {
    consoleClear();
    iprintf("\x1b[1;2H EQUESTRIA GIRLS DS - DEMO");
    iprintf("\x1b[3;2H Move the star with the D-pad.");
    iprintf("\x1b[4;2H Press X to change its color.");
    iprintf("\x1b[5;2H Press B to return to the title.");
    iprintf("\x1b[8;2H Position: %d, %d", star_x, star_y);
    iprintf("\x1b[10;2H Accent: %s", accent ? "MAGENTA" : "CYAN");
    iprintf("\x1b[14;2H *");
}

int main(void) {
    consoleDemoInit();
    draw_title();

    while (1) {
        scanKeys();
        const int down = keysDown();
        const int held = keysHeld();

        if (screen == SCREEN_TITLE) {
            if (down & (KEY_A | KEY_START)) {
                screen = SCREEN_DEMO;
                draw_demo();
            }
        } else {
            if (down & KEY_B) {
                screen = SCREEN_TITLE;
                draw_title();
            }
            if (down & KEY_X) {
                accent = !accent;
                draw_demo();
            }
            if (held & KEY_LEFT)  star_x -= 2;
            if (held & KEY_RIGHT) star_x += 2;
            if (held & KEY_UP)    star_y -= 2;
            if (held & KEY_DOWN)  star_y += 2;
            if (star_x < 0) star_x = 0;
            if (star_x > 255) star_x = 255;
            if (star_y < 0) star_y = 0;
            if (star_y > 191) star_y = 191;
        }
        swiWaitForVBlank();
    }
    return 0;
}