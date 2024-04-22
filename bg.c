#include "bg.h"
void init_bg(bg *bg) 
{
char ch[50]; 
for(int i=1;i<31;i++)//boucle pour charger les images background
{
sprintf(ch,"backgrounds/%d.jpg",i);
bg->images[i-1] = IMG_Load(ch);
}
bg->pos.w=bg->images[1]->w;
bg->pos.h=bg->images[1]->h;
bg->camera.x=0;
bg->camera.y=0;
bg->camera.w=bg->images[1]->w;
bg->camera.h=bg->images[1]->h;
bg->anim=0;
}
void scrolling(bg *bg,int d,int pas)
{//on scrolle verticalement ou horizontalement
if(d==1) bg->camera.x-=pas;
if(d==2) bg->camera.y-=pas;
}
void garder_image_sur_ecran(bg *bg, SDL_Surface *screen)
{
// garder l'image sur l'ecran 
//ki bsh tokhrej taswira mel ajneb tarja3 
if(bg->camera.x<0) bg->camera.x=0;
if(bg->camera.y<0) bg->camera.y=0;
if(bg->camera.x>bg->camera.w-screen->w) bg->camera.x=bg->camera.w-screen->w;
if(bg->camera.y>bg->camera.h-screen->h) bg->camera.y=bg->camera.h-screen->h;
}
void afficher_bg(bg bg,SDL_Surface *screen)
{
SDL_BlitSurface(bg.images[bg.anim],&bg.camera,screen,NULL);
SDL_Delay(50);
//image,shnowa bsh taffichi menha,3la shnowa bsh tafficheha,win bsh tafficheha
}
void animation(bg* bg)
{//anim malezmch tfout 50 khater edheka nb d'images
bg->anim++;
if(bg->anim==31)bg->anim=0;
}

void animation_start(SDL_Surface *screen)
{//animation début
//principe enou taswiret lbackground loula tji mel yssar lel ymin 9bal ma tebda jeu
SDL_Surface *image;
image= IMG_Load("backgrounds/1.jpg");
SDL_Rect pos;pos.x=screen->w+1000;pos.y=0;
SDL_Delay(500);//pause 0.5 secondes
while(pos.x>10)
{
SDL_BlitSurface(image,NULL,screen,&pos);
pos.x-=10;
SDL_Flip(screen);//actualiser
}
}

void musique(int stage)
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);//initialisation audio
	Mix_Music *musique; //Création du pointeur de type Mix_Music
    char nom_musique[40];
	sprintf(nom_musique,"musiques/%d.mp3",stage); 
	musique = Mix_LoadMUS(nom_musique); //Chargement de la musique
    Mix_PlayMusic(musique, -1);//-1:boucle infinie
	Mix_VolumeMusic(128);
}

void partage_ecran(bg bg1,bg bg2,SDL_Surface *screen)
{
SDL_BlitSurface(bg1.images[bg1.anim],&bg1.camera,screen,NULL);//affichage bg1
bg2.pos.x=screen->w/2;//pos bg2 = chtar l ecran
SDL_BlitSurface(bg2.images[bg2.anim],&bg2.camera,screen,&bg2.pos);//affichage bg2
}

