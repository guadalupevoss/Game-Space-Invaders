#include "highscore.h"

void scoreboard_init(score_t tabla[MAXSCORES])
{
    unsigned int counter;
    FILE *scoreboard_create = fopen("Resources/scoreboard.txt", "a");     //crea el archivo si no esta
    if (scoreboard_create==NULL)
    {
        printf("error de archivo 1\n");
    }
    fclose(scoreboard_create);

    FILE *scoreboard_file = fopen("Resources/scoreboard.txt", "r");     //lee el archivo
    if (scoreboard_file==NULL)
    {
        printf("error de archivo 2\n");
    }

    for(counter=0;counter<=MAXSCORES;counter++)             //limpio la estructura por si tiene datos basura
    {
        strcpy(tabla[counter].name,"-");
        tabla[counter].points=0;
    }


    for(counter=0;counter<=MAXSCORES;counter++)             //lee datos del archivo txt y los guarda en la estructura
    {
        fscanf(scoreboard_file,"%s %lu" ,&tabla[counter].name, &tabla[counter].points);
    }
    fclose(scoreboard_file);
}

int print_scores(ALLEGRO_FONT *fuente_score,ALLEGRO_EVENT_QUEUE *ev_queue)
{
    float       text_x, text_y;
    char        str[MAX_ARR_CARACTER];
    bool        do_exit_score= false;

    ALLEGRO_BITMAP *fondo_lista_high_score;
    ALLEGRO_BITMAP *fondo_score;

        fondo_lista_high_score= al_load_bitmap("Resources/Bitmaps/high_scores.bmp"); //fondo lista de high scores
    if (!fondo_lista_high_score) {
        fprintf(stderr, "failed to create high score bitmap!\n");
        return 0;
    }
        fondo_score= al_load_bitmap("Resources/Bitmaps/fondo_juego.bmp"); //fondo lista de high scores
    if (!fondo_score) {
        fprintf(stderr, "failed to create fondo score bitmap!\n");
        return 0;
    }

    al_convert_mask_to_alpha(fondo_lista_high_score,al_map_rgb(0, 255, 0));
    al_convert_mask_to_alpha(fondo_score,al_map_rgb(0, 255, 0));

    al_register_event_source(ev_queue, al_get_mouse_event_source());

    al_draw_bitmap(fondo_score,0,0,0);
    al_draw_bitmap(fondo_lista_high_score,0,0,0);
    al_flip_display();


    FILE *fp;
    fp= fopen("Resources/scoreboard.txt","r");
    if(fp==NULL)
    {
        printf("Error en fp");
    }

    limpio_arr(str,MAX_ARR_CARACTER);
    text_x=210;
    text_y=200;

    //ESCRIBO LA LISTA
    while(!feof(fp))
    {
        fscanf(fp,"%s", str);
        al_draw_text(fuente_score, al_map_rgb(255,255,255), text_x-1, text_y, ALLEGRO_ALIGN_LEFT, str);
        al_draw_text(fuente_score, al_map_rgb(224,192,0), text_x, text_y, ALLEGRO_ALIGN_LEFT, str);
        limpio_arr(str,MAX_ARR_CARACTER);
        fscanf(fp,"%s", str);
        al_draw_text(fuente_score, al_map_rgb(255,255,255), text_x+DISTANCE_POINTS_PLAYER-1, text_y, ALLEGRO_ALIGN_LEFT, str);
        al_draw_text(fuente_score, al_map_rgb(224,192,0), text_x+DISTANCE_POINTS_PLAYER, text_y, ALLEGRO_ALIGN_LEFT, str);
        limpio_arr(str,MAX_ARR_CARACTER);
        text_y+=FUENTE_SIZE;
    }
   fclose(fp);
   al_flip_display();

    //ME MANTENGO ADENTRO DE LA LISTA HASTA QUE APRIETO LA FLECHA
    while(!do_exit_score)
    {
        ALLEGRO_EVENT ev;

        if (al_get_next_event(ev_queue, &ev))
        {

            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                do_exit_score = true;
            }
            else if((ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)&&(MOUSE_IN_EXIT_SCORE))
            {
                do_exit_score= true;
            }

         }
    }

   al_destroy_bitmap(fondo_score);
   al_destroy_bitmap(fondo_lista_high_score);
   return 1;
}

void limpio_arr(char arr[],int max_caract)
{
    int contador=0;

     while(contador<max_caract)
        {
            arr[contador]='\0';
            ++contador;
        }
}

void enter_new_highscore(char name[NAMELENGHT], unsigned long points, score_t lista_scores[MAXSCORES])
{
    unsigned int counter,stop=0;
    unsigned long points_temp;
    char name_temp[NAMELENGHT];
    if(lista_scores[0].points==0)
    {
        lista_scores[0].points=points;
        strcpy(lista_scores[0].name,name);
    }
    else
    {
        strcpy(lista_scores[MAXSCORES-1].name,name);
        lista_scores[MAXSCORES-1].points=points;
        for(counter=(MAXSCORES-1);((stop==0)&&(counter!=0));counter--)                //ordena el nuevo score en la posicion adecuada
        {
        if(lista_scores[counter].points>=lista_scores[counter-1].points)
            {
                points_temp=lista_scores[counter-1].points;
                strcpy(name_temp,lista_scores[counter-1].name);

                lista_scores[counter-1].points=lista_scores[counter].points;
                strcpy(lista_scores[counter-1].name,lista_scores[counter].name);

                lista_scores[counter].points=points_temp;
                strcpy(lista_scores[counter].name,name_temp);
            }
            else
            {
                stop=1;
            }
        }
    }

    FILE *scoreboard_write = fopen("Resources/scoreboard.txt", "w");
    if (scoreboard_write==NULL)
    {
        printf("Error de apertura de archivo para escritura\n");
    }


    for(counter=0;counter<MAXSCORES;counter++)
    {
        fprintf(scoreboard_write,"%s\t",lista_scores[counter].name);
        fprintf(scoreboard_write,"%lu\t",lista_scores[counter].points);
    }
    fclose(scoreboard_write);
}

int test_new_score(unsigned long points,score_t scores[MAXSCORES])           //testea si un score nuevo entra en los highscores o no. devuelve 1 si entra, 0 si no
{
    int i=0;
    if(points>=scores[MAXSCORES-1].points)
    {
       i=1;
    }
    return i;
}


void read_keyboard(char arr_char[],ALLEGRO_EVENT_QUEUE *ev_queue,ALLEGRO_FONT *fuente_score,ALLEGRO_BITMAP* fondo_read)
{
    bool exit_keyboard = false;

    int     character_counter=0;
    limpio_arr(arr_char,NAMELENGHT);

        if (!al_install_keyboard()) {
        fprintf(stderr, "failed to initialize the keyboard!\n");
        }


    al_register_event_source(ev_queue, al_get_keyboard_event_source()); //REGISTRAMOS EL TECLADO

    while (!exit_keyboard)
    {
        ALLEGRO_EVENT event;

        //  1° TOMA EL ÚLTIMO EVENTO DE LA COLA DE EVENTOS
        if (al_get_next_event(ev_queue, &event))
        {

            if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                exit_keyboard = true;
            }

            if(character_counter<NAMELENGHT)
            {
                if (event.type == ALLEGRO_EVENT_KEY_DOWN)
                {
                    switch (event.keyboard.keycode)
                    {
                    case ALLEGRO_KEY_A:
                        arr_char[character_counter]='A';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_B:
                        arr_char[character_counter]='B';
                        printf("%s",arr_char);
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_C:
                        arr_char[character_counter]='C';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_D:
                        arr_char[character_counter]='D';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_E:
                        arr_char[character_counter]='E';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_F:
                        arr_char[character_counter]='F';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_G:
                        arr_char[character_counter]='G';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_H:
                        arr_char[character_counter]='H';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_I:
                        arr_char[character_counter]='I';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_J:
                        arr_char[character_counter]='J';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_K:
                        arr_char[character_counter]='K';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_L:
                        arr_char[character_counter]='L';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_M:
                        arr_char[character_counter]='M';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_N:
                        arr_char[character_counter]='N';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_P:
                        arr_char[character_counter]='P';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_O:
                        arr_char[character_counter]='O';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_Q:
                        arr_char[character_counter]='Q';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_R:
                        arr_char[character_counter]='R';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_S:
                        arr_char[character_counter]='S';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_T:
                        arr_char[character_counter]='T';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_U:
                        arr_char[character_counter]='U';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_V:
                        arr_char[character_counter]='V';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_W:
                        arr_char[character_counter]='W';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_X:
                        arr_char[character_counter]='X';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_Y:
                        arr_char[character_counter]='Y';
                        ++character_counter;
                        break;
                    case ALLEGRO_KEY_Z:
                        arr_char[character_counter]='Z';
                        ++character_counter;
                        break;
                    }

                }
            }

            if (event.type == ALLEGRO_EVENT_KEY_UP)
            {
               switch (event.keyboard.keycode)
                {
                    case ALLEGRO_KEY_BACKSPACE:
                        if(character_counter>0)
                        {
                        --character_counter;
                        arr_char[character_counter]='\0';
                        }
                        break;
                    case ALLEGRO_KEY_ENTER:
                        if(character_counter>0)
                        {
                            exit_keyboard = true;
                        }

                        break;

                }
            }

            al_draw_bitmap(fondo_read, 0, 0, 0);

            if(character_counter==NAMELENGHT)
            {
                al_draw_text(fuente_score, al_map_rgb(255,255,255), MESSAGE_X-2, MESSAGE_Y, ALLEGRO_ALIGN_LEFT, "CHARACTER LIMIT REACHED");
                al_draw_text(fuente_score, al_map_rgb(224,192,0), MESSAGE_X, MESSAGE_Y, ALLEGRO_ALIGN_LEFT, "CHARACTER LIMIT REACHED");
            }


            al_draw_text(fuente_score, al_map_rgb(255,255,255), ENTER_PLAYER_NAME_X-2,ENTER_PLAYER_NAME_Y, ALLEGRO_ALIGN_LEFT, "ENTER PLAYER NAME:");
            al_draw_text(fuente_score, al_map_rgb(224,192,0), ENTER_PLAYER_NAME_X,ENTER_PLAYER_NAME_Y, ALLEGRO_ALIGN_LEFT, "ENTER PLAYER NAME:");
            al_draw_text(fuente_score,al_map_rgb(255,255,255), PLAYER_NAME_X-2, PLAYER_NAME_Y, ALLEGRO_ALIGN_LEFT, arr_char);
            al_draw_text(fuente_score,al_map_rgb(224,192,0), PLAYER_NAME_X, PLAYER_NAME_Y, ALLEGRO_ALIGN_LEFT, arr_char);
            al_flip_display();
    }
    }

}