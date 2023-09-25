#include "../include/Window.h"

Window::Window( int width_, int height_ ) :
    width( width_ ), height( height_ )
{
        SDL_Init( SDL_INIT_VIDEO );
        SDL_CreateWindowAndRenderer( width, height, 0, &window, &renderer );
        SDL_SetWindowTitle( window, "Snake Game" );
        SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );
        SDL_RenderClear( renderer );
        SDL_RenderPresent( renderer );
        bool media_loaded = load_media();
        isOpen = ( window != NULL || !media_loaded ) ? true : false;

}

bool Window::load_media() {

    bool success = true;
    all_surfaces[ KEYPRESS_UP ] = load_surface( "../media/background.bmp" );
    std::cout << "All surfaces loaded" << '\n';
    screen_surface = SDL_GetWindowSurface(window);
    return success;

}

void Window::update() {
    while (SDL_PollEvent( &event )) {
        
        if ( event.type == SDL_QUIT ) this->close();

        // Keyboard Input
        else if ( event.type == SDL_KEYDOWN ) {
            switch ( event.key.keysym.sym ) {
                case SDLK_UP : {top_surface = all_surfaces[ KEYPRESS_UP ]; std::cout << "Key Press: KEY UP" << '\n';} break;
            }
        }
    }
    SDL_BlitSurface( top_surface, NULL, screen_surface, NULL );
    SDL_UpdateWindowSurface( this->window );

}

void Window::close() {

    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    for (int i = 0; i < INPUT_TOTAL; ++i) {
        SDL_FreeSurface( all_surfaces[ i ] );
        all_surfaces[i] = NULL;
    }
    isOpen = false;

}


SDL_Surface* Window::load_surface(std::string path) {

    SDL_Surface* loaded_surface = SDL_LoadBMP( path.c_str() );
    if (loaded_surface == NULL) {
		printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }
    return loaded_surface;

}