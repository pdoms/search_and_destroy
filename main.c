#include<stdio.h>
#include<stdint.h>
#include<SDL2/SDL.h>
#include<string.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define BUFFER_CAP 1024

void scc(int code) {
    if (code < 0) {
        fprintf(stderr, "SDL ERROR: %s\n", SDL_GetError());
    }
}

void *scp(void *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "SDL ERROR  %s\n", SDL_GetError());
    }
    return ptr;
}

char buffer[BUFFER_CAP];
size_t buffer_size = 0;
size_t buffer_cursor = 0;

int main() {
    

    
    scc(SDL_Init(SDL_INIT_VIDEO));

    SDL_Window *window = scp(SDL_CreateWindow("Search And Destroy", 0,0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE));

    SDL_Renderer *renderer = scp(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED));

    int quit = 1;

    while (quit > 0) {
        SDL_Event event = {0};

        while (SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT: 
                    {
                        quit = 0;
                    }
                    break;
                case SDL_TEXTINPUT: {
                    size_t text_size = strlen(event.text.text);
                    memcpy(buffer + buffer_size, event.text.text, text_size);
                    buffer_size += text_size;
                    buffer_cursor = buffer_size;
                                    }
                    break;
            }
        }
        scc(SDL_SetRenderDrawColor(renderer, 0,0,0,0));
        scc(SDL_RenderClear(renderer));
        SDL_RenderPresent(renderer);
    }

    printf("GOT HERE %s", buffer); 



    SDL_Quit();

    return 0;
}



