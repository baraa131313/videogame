#include "bg.h"

void main()
{
bg bg,bg2;
init_bg(&bg);
init_bg(&bg2);
SDL_Init(SDL_INIT_EVERYTHING);
TTF_Init();
SDL_EnableKeyRepeat(60,0);
SDL_Surface *screen =SDL_SetVideoMode(1000,750,32,SDL_SWSURFACE);
int q=0;
animation_start(screen);
musique(1);
SDL_Event event;
int partage = 0;//1 partage, 0 non
while(q==0)
{
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                q=1;
			case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    q=1;
                    break;
                case SDLK_p:
                    if (partage == 1) partage =0;else partage=1;
                    break;
                case SDLK_UP:
                    scrolling(&bg,2,20);
                    break;
                case SDLK_DOWN:
                    scrolling(&bg,2,-20);
                    break;
                case SDLK_LEFT:
                    scrolling(&bg,1,20);
                    break;
                case SDLK_RIGHT:
                    scrolling(&bg,1,-20);
                    break;
		case SDLK_z:
                    scrolling(&bg2,2,20);
                    break;
                case SDLK_s:
                    scrolling(&bg2,2,-20);
                    break;
                case SDLK_q:
                    scrolling(&bg2,1,20);
                    break;
                case SDLK_d:
                    scrolling(&bg2,1,-20);
                    break;
                default:
                    break;
            }
            default:
                break;
        }
    }
animation(&bg);
animation(&bg2);
garder_image_sur_ecran(&bg,screen);
garder_image_sur_ecran(&bg2,screen);
if(partage == 1)
partage_ecran(bg,bg2,screen);
else
afficher_bg(bg,screen);
SDL_Delay(50);
SDL_Flip(screen);
}
SDL_Quit();
}
