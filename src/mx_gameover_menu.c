#include "DEC2020.h"

#define GAMEOVERMENU_MENUBUTTON_X 705
#define GAMEOVERMENU_MENUBUTTON_Y 825
#define GAMEOVERMENU_MENUBUTTON_WIDTH 189
#define GAMEOVERMENU_MENUBUTTON_HEIGHT 32
#define GAMEOVERMENU_LEADER_X 540
#define GAMEOVERMENU_LEADER_Y 727
#define GAMEOVERMENU_LEADER_WIDTH 525
#define GAMEOVERMENU_LEADER_HEIGHT 33
#define GAMEOVERMENU_RESTARTBUTTON_X 540
#define GAMEOVERMENU_RESTARTBUTTON_Y 605
#define GAMEOVERMENU_RESTARTBUTTON_WIDTH 525
#define GAMEOVERMENU_RESTARTBUTTON_HEIGHT 57

#define RESTART_BUTTON_PNG "resource/blue.png"
#define QUIT_BUTTON_PNG "resource/red.png"

int mx_gameover_menu(SDL_Renderer *renderer, t_gamestate *game) {
    uint clicked = 0;
    int running = 1;
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (SDL_QUIT == event.type){

        }
        if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
            running = 0;

        if (event.type == SDL_MOUSEBUTTONDOWN) {
            if (event.button.button == SDL_BUTTON_LEFT
                && event.button.x >= GAMEOVERMENU_RESTARTBUTTON_X
                && event.button.x <= GAMEOVERMENU_RESTARTBUTTON_X + GAMEOVERMENU_RESTARTBUTTON_WIDTH
                && event.button.y >= GAMEOVERMENU_RESTARTBUTTON_Y
                && event.button.y <= GAMEOVERMENU_RESTARTBUTTON_Y + GAMEOVERMENU_RESTARTBUTTON_HEIGHT)
                clicked = 1;
            if (event.button.button == SDL_BUTTON_LEFT
                && event.button.x >= GAMEOVERMENU_LEADER_X
                && event.button.x <= GAMEOVERMENU_LEADER_X + GAMEOVERMENU_LEADER_WIDTH
                && event.button.y >= GAMEOVERMENU_LEADER_Y
                && event.button.y <= GAMEOVERMENU_LEADER_Y + GAMEOVERMENU_LEADER_HEIGHT)
                clicked = 2;
            if (event.button.button == SDL_BUTTON_LEFT
                && event.button.x >= GAMEOVERMENU_MENUBUTTON_X
                && event.button.x <= GAMEOVERMENU_MENUBUTTON_X + GAMEOVERMENU_MENUBUTTON_WIDTH
                && event.button.y >= GAMEOVERMENU_MENUBUTTON_Y
                && event.button.y <= GAMEOVERMENU_MENUBUTTON_Y + GAMEOVERMENU_MENUBUTTON_HEIGHT)
                clicked = 3;
        }
    }
    SDL_Rect background_rect = {0, 0, W_WIDTH, W_HEIGHT};
    SDL_Texture *tex;
    switch (clicked) {
        case 1:
            running = 2;
            tex = mx_get_texture(game, TEX_BACKGROUND_GAMEOVER_RETRY);
            write(2, "!!", 2);
            mx_restart_gamestate(game);
            write(2, "@@@", 3);
            mx_set_battle_scene(game);
            break;
        case 2:
            running = 2;
            tex = mx_get_texture(game, TEX_BACKGROUND_GAMEOVER_LEADER);
            break;
        case 3:
            running = 2;
            tex = mx_get_texture(game, TEX_BACKGROUND_GAMEOVER_MENU);
            mx_restart_gamestate(game);
            mx_set_start_scene(game);
            break;
        default:
            tex = mx_get_texture(game, TEX_BACKGROUND_GAMEOVER);
            break;
    }
    SDL_RenderCopy(renderer, tex, NULL, &background_rect);

    return running;
}
