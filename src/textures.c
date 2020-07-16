#include "DEC2020.h"
#include "textures.h"

#define TEXTURES_COUNT 84

SDL_Texture **mx_init_textures(SDL_Renderer *renderer){
    char *paths[TEXTURES_COUNT] = {"/resource/Textures/Background/Start.png",
                    "/resource/Textures/Background/Start_click_start.png",
                    "/resource/Textures/Background/Start_click_leaderboard.png",
                    "/resource/Textures/Background/Start_click_quit.png",
                    "/resource/Textures/Background/map.png",
                    "/resource/Textures/Background/Gameover.png",
                    "/resource/Textures/Background/Gameover_retry.png",
                    "/resource/Textures/Background/Gameover_leader.png",
                    "/resource/Textures/Background/Gameover_menu.png",
                    "/resource/Textures/Background/Leaderboard.png",
                    "/resource/Textures/target.png",
                    "/resource/Textures/tank_hull/blue_tank_hull_1.png",
                    "/resource/Textures/tank_hull/blue_tank_hull_2.png",
                    "/resource/Textures/tank_hull/green_tank_hull_1.png",
                    "/resource/Textures/tank_hull/green_tank_hull_2.png",
                    "/resource/Textures/tank_hull/red_tank_hull_1.png",
                    "/resource/Textures/tank_hull/red_tank_hull_2.png",
                    "/resource/Textures/tank_tower/Blue_gun_1.png",
                    "/resource/Textures/tank_tower/Blue_gun_2.png",
                    "/resource/Textures/tank_tower/Blue_gun_3.png",
                    "/resource/Textures/tank_tower/Green_gun_1.png",
                    "/resource/Textures/tank_tower/Green_gun_2.png",
                    "/resource/Textures/tank_tower/Green_gun_3.png",
                    "/resource/Textures/tank_tower/Red_gun_1.png",
                    "/resource/Textures/tank_tower/Red_gun_2.png",
                    "/resource/Textures/tank_tower/Red_gun_3.png",
                    "/resource/Textures/enemy/bug_1_1.png",
                    "/resource/Textures/enemy/bug_1_2.png",
                    "/resource/Textures/enemy/bug_1_d1.png",
                    "/resource/Textures/enemy/bug_1_d2.png",
                    "/resource/Textures/enemy/bug_1_d3.png",
                    "/resource/Textures/enemy/bug_1_d4.png",
                    "/resource/Textures/enemy/bug_1_d5.png",
                    "/resource/Textures/enemy/bug_1_d6.png",
                    "/resource/Textures/enemy/bug_1_d7.png",
                    "/resource/Textures/enemy/bug_1_d8.png",
                    "/resource/Textures/enemy/bug_1_d9.png",
                    "/resource/Textures/enemy/bug_2_1.png",
                    "/resource/Textures/enemy/bug_2_2.png",
                    "/resource/Textures/enemy/bug_2_d1.png",
                    "/resource/Textures/enemy/bug_2_d2.png",
                    "/resource/Textures/enemy/bug_2_d3.png",
                    "/resource/Textures/enemy/bug_2_d4.png",
                    "/resource/Textures/enemy/bug_2_d5.png",
                    "/resource/Textures/enemy/bug_2_d6.png",
                    "/resource/Textures/enemy/bug_2_d7.png",
                    "/resource/Textures/enemy/bug_2_d8.png",
                    "/resource/Textures/enemy/bug_2_d9.png",
                    "/resource/Textures/enemy/bug_3_1.png",
                    "/resource/Textures/enemy/bug_3_2.png",
                    "/resource/Textures/enemy/bug_3_d1.png",
                    "/resource/Textures/enemy/bug_3_d2.png",
                    "/resource/Textures/enemy/bug_3_d3.png",
                    "/resource/Textures/enemy/bug_3_d4.png",
                    "/resource/Textures/enemy/bug_3_d5.png",
                    "/resource/Textures/enemy/bug_3_d6.png",
                    "/resource/Textures/enemy/bug_3_d7.png",
                    "/resource/Textures/enemy/bug_3_d8.png",
                    "/resource/Textures/enemy/bug_3_d9.png",
                    "/resource/Textures/bullet_1.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_1.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_2.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_3.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_4.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_5.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_6.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_7.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_8.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_9.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_10.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_11.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_12.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_13.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_14.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_15.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_16.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_17.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_18.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_19.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_20.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_21.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_22.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_23.png",
                    "/resource/Textures/tank_explosion/Tank_red_exp_24.png"
    };
    SDL_Texture **textures = (SDL_Texture**)malloc (TEXTURES_COUNT * sizeof(SDL_Texture**));
    for (int i = 0; i < TEXTURES_COUNT; i++){
        textures[i] = IMG_LoadTexture(renderer, paths[i]);
    }
    return textures;
}

void mx_free_textures(SDL_Texture **tex){
    free(tex);
    // for (int i = 0; i < TEXTURES_COUNT; i++){
    //     free(tex[i]);
    // }
}

SDL_Texture *mx_get_texture(t_gamestate *game, enum e_textures deskr){
    return (game->textures[deskr]);
}
