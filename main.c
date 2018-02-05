/**********************************************HEX GAME*********************************************************************/
#include "Jouer.c" /*Le fichier Jouer.c Contient toutes les fonction utiliser et meme les include des bibliothéque
                     et d'autre fichier .h et .c*/
#define Larg 1229 // La largeur de la fenetre declarer en define pour plus de controle
#define Haut 768  // La Hauteur de la fenetre

int main ( int argc, char** argv )
 {
    /*************************************************Les Données**************************************************/


    /*************Les Entier**********************/
    //Le type Uint16 utiliser au lieu du type int pour assurer la portabilité de l'application
    Uint16 flag=1 ;
    Uint16 i=0,j=0 ;
    Uint16 Test ;
    Uint16 x,y;

    /*************Les Surfaces********************/

    SDL_Surface *Table = NULL ;
    SDL_Surface *Menu = NULL ;
    SDL_Surface *Menu_Ordinateur = NULL;
    SDL_Surface *Menu_Aide = NULL ;
    SDL_Surface *Joueur1_Gagne = NULL ;
    SDL_Surface *Joueur2_Gagne = NULL ;
    SDL_Surface *Joueur_Gagne = NULL ;
    SDL_Surface *Ordinateur_Gagne = NULL ;
    SDL_Surface *Joueur_Commencer = NULL ;
    SDL_Surface *Ordinateur_Commencer = NULL ;
    SDL_Surface *Joueur1_Commencer = NULL ;
    SDL_Surface *Joueur2_Commencer = NULL ;
    SDL_Surface *Fleche = NULL ;
    SDL_Surface *Screen = NULL ;
    SDL_Surface *Pion = NULL ;
    SDL_Surface *icon = NULL ;
    /*****************************************************************************************************************/

    /**************************************************Code**********************************************************/

     /****************Screen***************************************/
  //  SDL_WM_SetCaption("HEX GAME",NULL);
  //  SDL_WM_SetIcon(IMG_Load("./Design/Hex_Game_Logo.png"),NULL);
     //La forme de la fenetre et la profendeur des couleur pzr bit et d'autre parametre
    Screen = SDL_SetVideoMode(Larg,Haut,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN);
    SDL_FillRect(Screen,NULL,SDL_MapRGB(Screen->format,255,255,255));
    SDL_Flip(Screen);

    /*************Initialisation*****************/
    // initialisation des diferents surface utiliser dans La fonction Main
    Table = IMG_Load("./Design/table_1.png");
    Menu = IMG_Load("./Design/Menu1.png");
    Menu_Ordinateur = IMG_Load("./Design/Ordinateur_Menu.png");
    Menu_Aide = IMG_Load("./Design/Menu_Aide.png");
    Fleche = IMG_Load("./Design/Fleche.png");
    Fleche_Inverse = IMG_Load("./Design/Fleche_Inverse.png");
    Joueur1_Gagne = IMG_Load("./Design/Joueur1_Gagne.png");
    Joueur2_Gagne = IMG_Load("./Design/Joueur2_Gagne.png");
    Joueur_Gagne = IMG_Load("./Design/Joueur_Gagne.png");
    Ordinateur_Gagne = IMG_Load("./Design/Ordinateur_Gagne.png");
    Ordinateur_Commencer = IMG_Load("./Design/Ordinateur_Commencer.png");
    Joueur_Commencer = IMG_Load("./Design/Joueur_Commencer.png");
    Joueur1_Commencer = IMG_Load("./Design/Joueur1_Commencer.png");
    Joueur2_Commencer = IMG_Load("./Design/Joueur2_Commencer.png");

/****************************************Menu Principale**********************************************/
   Menu_Principale:
   /******Initialisation des parametre du jeux*******/
            srand(time(NULL));
            Initialisation(Pos_Pion);//Description de cette fonction est dans Jouer.c
          for(i=0;i<9;i++)
                 for(j=0;j<9;j++){
                      Hex[i][j].etat = Vide ;
                      Hex[i][j].teste = 0 ;
                      }
   /*************************************************/
    BlitImage(Menu,Screen,0,0);
    flag=1;
    while(flag){
        SDL_WaitEvent(&mEvent);
        switch(mEvent.type){
                case SDL_QUIT:
                    flag = 0;
                    break;
                case SDL_MOUSEMOTION:
                    x=mEvent.motion.x;
                    y=mEvent.motion.y;
                      if(x>463&&x<800&&y>243&&y<306)
                         BlitImage(Fleche,Screen,412,256);
                    else if(x>512&&x<907&&y>333&&y<392)
                         BlitImage(Fleche,Screen,465,343);
                    else if(x>560&&x<691&&y>414&&y<470)
                         BlitImage(Fleche,Screen,514,425);
                    else if(x>547&&x<673&&y>488&&y<550)
                         BlitImage(Fleche,Screen,496,498);
                    else BlitImage(Menu,Screen,0,0);
                    break;
                case SDL_MOUSEBUTTONUP:
                     x=mEvent.button.x;
                     y=mEvent.button.y;
                    if(x>463&&x<800&&y>243&&y<306)
                         goto JoueurVsJoueur;
                    if(x>512&&x<907&&y>333&&y<392)
                         goto Menu_Ordinateur;
                    if(x>560&&x<691&&y>414&&y<470)
                        goto Aide ;
                    if(x>547&&x<673&&y>488&&y<550)
                       exit(0);
                   break;
        }
    }


/*******************************************Aide****************************************************/
Aide:
BlitImage(Menu_Aide,Screen,0,0);
                        while(flag){
                            SDL_WaitEvent(&mEvent);
                            switch(mEvent.type){
                                case SDL_MOUSEMOTION:
                                     x = mEvent.motion.x;
                                     y = mEvent.motion.y;
                                    if(x>168&&x<324&&y>676&&y<743)
                                        BlitImage(Fleche_Inverse,Screen,312,703);
                                    else BlitImage(Menu_Aide,Screen,0,0);
                                    break;
                                case SDL_MOUSEBUTTONUP:
                                       x = mEvent.button.x;
                                      y = mEvent.button.y;
                                    if(x>168&&x<324&&y>676&&y<743)
                                        goto Menu_Principale;
                                    break;
                                }
                        }

 /**************************************************************************************************/
 /************************************* Menu Niveaux Ordinateur ************************************/
Menu_Ordinateur:
 BlitImage(Menu_Ordinateur,Screen,0,0);
    flag=1;
    while(flag){
        SDL_WaitEvent(&mEvent);
        switch(mEvent.type){
                case SDL_QUIT:
                    flag = 0;
                    break;
                case SDL_MOUSEMOTION:
                    x=mEvent.motion.x;
                    y=mEvent.motion.y;
                      if(x>472&&x<571&&y>242&&y<295)
                         BlitImage(Fleche,Screen,412,256);
                    else if(x>526&&x<650&&y>334&&y<400)
                         BlitImage(Fleche,Screen,465,343);
                    else if(x>560&&x<691&&y>414&&y<470)
                         BlitImage(Fleche,Screen,514,425);
                    else BlitImage(Menu_Ordinateur,Screen,0,0);
                    break;
                case SDL_MOUSEBUTTONUP:
                     x=mEvent.button.x;
                     y=mEvent.button.y;
                    if(x>472&&x<571&&y>242&&y<295)
                         goto JoueurVsOrdinateur1;
                    if(x>526&&x<650&&y>334&&y<400)
                         goto JoueurVsOrdinateur2;
                    if(x>560&&x<691&&y>414&&y<470)
                        goto Menu_Principale;
                   break;
        }
    }

 /**************************************************************************************************/
/*************************************Joueur1 VS Joueur2*******************************************/
  JoueurVsJoueur:
  BlitImage(Table,Screen,0,0);
  int First , Last ,Random ;

   Random = (rand() % (2 - 1 + 1)) + 1;
   if (Random == 1){
     First = 1;
     Last = 2;
      BlitImage(Joueur1_Commencer,Screen,0,0);
        int flag = 1;
                    while(flag){
                        SDL_WaitEvent(&mEvent);
                        switch(mEvent.type){
                    case SDL_MOUSEBUTTONUP:
                        int x = mEvent.button.x;
                        int y = mEvent.button.y;
                        if(x>562&&x<677&&y>525&&y<578){
                                flag = 0 ;
                                BlitImage(Table,Screen,0,0);
                                }
                                }
                     }
   }
   else if(Random == 2){
        First = 2;
        Last  = 1;
         BlitImage(Joueur2_Commencer,Screen,0,0);
        int flag = 1;
                    while(flag){
                        SDL_WaitEvent(&mEvent);
                        switch(mEvent.type){
                    case SDL_MOUSEBUTTONUP:
                        int x = mEvent.button.x;
                        int y = mEvent.button.y;
                        if(x>562&&x<677&&y>525&&y<578){
                                flag = 0 ;
                                BlitImage(Table,Screen,0,0);
                                }
                           }
                     }
   }
   flag = 1 ;
   while(flag){
   if(Joueur_Humain(First,Noir,Screen,Table)) goto Menu_Principale;
        if(TestNoir(Hex)){
                            if(First == 1)
                                BlitImage(Joueur1_Gagne,Screen,0,0);
                            if(First == 2)
                                BlitImage(Joueur2_Gagne,Screen,0,0);
                    int flag = 1;
                    while(flag){
                        SDL_WaitEvent(&mEvent);
                        switch(mEvent.type){
                    case SDL_MOUSEBUTTONUP:
                        int x = mEvent.button.x;
                        int y = mEvent.button.y;
                        if(x>559&&x<677&&y>526&&y<572){
                                flag = 0 ;
                                goto Menu_Principale;}
                           }
                     }
    }
   if(Joueur_Humain(Last,Blanc,Screen,Table)) goto Menu_Principale;
        if(TestBlanc(Hex)){
                            if(Last == 1)
                                BlitImage(Joueur1_Gagne,Screen,0,0);
                            if(Last == 2)
                                BlitImage(Joueur2_Gagne,Screen,0,0);
                    int flag = 1;
                    while(flag){
                        SDL_WaitEvent(&mEvent);
                        switch(mEvent.type){
                    case SDL_MOUSEBUTTONUP:
                        int x = mEvent.button.x;
                        int y = mEvent.button.y;
                        if(x>559&&x<677&&y>526&&y<572){
                                flag = 0 ;
                                goto Menu_Principale;}
                           }
                     }
        }
   }
/*******************************************************************************************/
/***************************************Joueur Vs Ordinateur Niveau 1********************************/
 JoueurVsOrdinateur1:
      fprintf(stdout,"Hello");
     BlitImage(Table,Screen,0,0);
     Test = 0;
     Etat Ordi_Etat , Joueur_Etat;
     Random = (rand() % (2 - 1 + 1)) + 1;
     if(Random == 1){
        Joueur_Etat = Noir;
        Ordi_Etat = Blanc;
                 BlitImage(Joueur_Commencer,Screen,0,0);
        int flag = 1;
                    while(flag){
                        SDL_WaitEvent(&mEvent);
                        switch(mEvent.type){
                    case SDL_MOUSEBUTTONUP:
                        int x = mEvent.button.x;
                        int y = mEvent.button.y;
                        if(x>562&&x<677&&y>525&&y<578){
                                flag = 0 ;
                                BlitImage(Table,Screen,0,0);
                                }
                           }
                     }
        }
     else if(Random == 2){
        Joueur_Etat = Blanc;
        Ordi_Etat = Noir ;
                 BlitImage(Ordinateur_Commencer,Screen,0,0);
        int flag = 1;
                    while(flag){
                        SDL_WaitEvent(&mEvent);
                        switch(mEvent.type){
                    case SDL_MOUSEBUTTONUP:
                        int x = mEvent.button.x;
                        int y = mEvent.button.y;
                        if(x>562&&x<677&&y>525&&y<578){
                                flag = 0 ;
                                BlitImage(Table,Screen,0,0);
                                }
                           }
                     }
        goto Ordi_Turn1;
     }
 flag = 1 ;
   while(flag){
        Joueur_Etat = Noir;
  // if(Joueur(0,Joueur_Etat,Screen,Table))
  if(Joueur_Humain(0,Joueur_Etat,Screen,Table)) goto Menu_Principale;
        if(Joueur_Etat == Noir) Test = TestNoir(Hex);
        if(Joueur_Etat == Blanc) Test = TestBlanc(Hex);
          if(Test == 1){
               BlitImage(Joueur_Gagne,Screen,0,0);
                               int flag = 1;
                    while(flag){
                        SDL_WaitEvent(&mEvent);
                        switch(mEvent.type){
                    case SDL_MOUSEBUTTONUP:
                        int x = mEvent.button.x;
                        int y = mEvent.button.y;
                        if(x>559&&x<677&&y>526&&y<572){
                                flag = 0 ;
                                goto Menu_Principale;}
                           }
                     }
    }

 Ordi_Turn1:
     Ordi_Etat = Blanc;
     if(Joueur_Ordinateur1(Ordi_Etat,Screen,Table)) goto Menu_Principale;
        if(Ordi_Etat == Noir) Test = TestNoir(Hex);
        if(Ordi_Etat == Blanc) Test = TestBlanc(Hex);
        if(Test == 1){
           BlitImage(Ordinateur_Gagne,Screen,0,0);
                               int flag = 1;
                    while(flag){
                        SDL_WaitEvent(&mEvent);
                        switch(mEvent.type){
                    case SDL_MOUSEBUTTONUP:
                        int x = mEvent.button.x;
                        int y = mEvent.button.y;
                        if(x>559&&x<677&&y>526&&y<572){
                                flag = 0 ;
                                goto Menu_Principale;}
                           }
                     }
    }
   }
/*******************************************************************************************************/
/**********************************Joueur Vs Ordinateur Niveau 2****************************************/
JoueurVsOrdinateur2:
     BlitImage(Table,Screen,0,0);
     Test = 0;
     Random = (rand() % (2 - 1 + 1)) + 1;
     if(Random == 1){
        Joueur_Etat = Noir;
        Ordi_Etat = Blanc;
                 BlitImage(Joueur_Commencer,Screen,0,0);
        int flag = 1;
                    while(flag){
                        SDL_WaitEvent(&mEvent);
                        switch(mEvent.type){
                    case SDL_MOUSEBUTTONUP:
                        int x = mEvent.button.x;
                        int y = mEvent.button.y;
                        if(x>562&&x<677&&y>525&&y<578){
                                flag = 0 ;
                                BlitImage(Table,Screen,0,0);
                                }
                           }
                     }
        }
     else if(Random == 2){

        Ordi_Etat = Noir ;
        Joueur_Etat = Blanc;
                 BlitImage(Ordinateur_Commencer,Screen,0,0);
        int flag = 1;
                    while(flag){
                        SDL_WaitEvent(&mEvent);
                        switch(mEvent.type){
                    case SDL_MOUSEBUTTONUP:
                        int x = mEvent.button.x;
                        int y = mEvent.button.y;
                        if(x>562&&x<677&&y>525&&y<578){
                                flag = 0 ;
                                BlitImage(Table,Screen,0,0);
                                }
                           }
                     }
        goto Ordi_Turn2;
     }
 flag = 1 ;
   while(flag){
  if(Joueur_Humain(0,Joueur_Etat,Screen,Table)) goto Menu_Principale;
        if(Joueur_Etat == Noir) Test = TestNoir(Hex);
        if(Joueur_Etat == Blanc) Test = TestBlanc(Hex);
          if(Test == 1){
               BlitImage(Joueur_Gagne,Screen,0,0);
                               int flag = 1;
                    while(flag){
                        SDL_WaitEvent(&mEvent);
                        switch(mEvent.type){
                    case SDL_MOUSEBUTTONUP:
                        int x = mEvent.button.x;
                        int y = mEvent.button.y;
                        if(x>559&&x<677&&y>526&&y<572){
                                flag = 0 ;
                                goto Menu_Principale;}
                           }
                     }
    }

 Ordi_Turn2:
   if(Joueur_Ordinateur2(Ordi_Etat, Joueur_Etat, Screen,Table)) goto Menu_Principale;
  // if(Joueur_Ordinateur1(Ordi_Etat,Screen,Table)) goto Menu_Principale;
        if(Ordi_Etat == Noir) Test = TestNoir(Hex);
        if(Ordi_Etat == Blanc) Test = TestBlanc(Hex);
        if(Test == 1){
           BlitImage(Ordinateur_Gagne,Screen,0,0);
                               int flag = 1;
                    while(flag){
                        SDL_WaitEvent(&mEvent);
                        switch(mEvent.type){
                    case SDL_MOUSEBUTTONUP:
                        int x = mEvent.button.x;
                        int y = mEvent.button.y;
                        if(x>559&&x<677&&y>526&&y<572){
                                flag = 0 ;
                                goto Menu_Principale;}
                           }
                     }
    }
   }
/****************************************************************************************/
pause();

    SDL_FreeSurface(Joueur1_Commencer);
    SDL_FreeSurface(Joueur1_Gagne);
    SDL_FreeSurface(Joueur2_Commencer);
    SDL_FreeSurface(Joueur2_Gagne);
    SDL_FreeSurface(Joueur_Commencer);
    SDL_FreeSurface(Joueur_Gagne);
    SDL_FreeSurface(Ordinateur_Commencer);
    SDL_FreeSurface(Ordinateur_Gagne);
    SDL_FreeSurface(Fleche_Inverse);
    SDL_FreeSurface(Fleche);
    SDL_FreeSurface(Menu_Aide);
    SDL_FreeSurface(Menu);
    SDL_FreeSurface(Table);
    SDL_FreeSurface(Screen);
    SDL_FreeSurface(Fleche);
    SDL_FreeSurface(Fleche_Inverse);

    SDL_Quit();

return EXIT_SUCCESS;
}
