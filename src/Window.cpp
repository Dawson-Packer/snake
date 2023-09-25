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

void Window::set_title(std::string title) {
    SDL_SetWindowTitle( window, title.c_str() );
}

bool Window::load_media() {

    bool success = true;
    preloaded_surfaces[ SURFACE_KEYPRESS_UP ] = load_surface( "../media/background.bmp" );
    screen_surface = SDL_GetWindowSurface(window);
    return success;

}

void Window::update_surface( int surface_type) {
    
    top_surface = preloaded_surfaces[ surface_type ];
    SDL_BlitSurface( top_surface, NULL, screen_surface, NULL );
    SDL_UpdateWindowSurface( this->window );


}

void Window::close() {

    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    for (int i = 0; i < SURFACE_TOTAL; ++i) {
        SDL_FreeSurface( preloaded_surfaces[ i ] );
        preloaded_surfaces[i] = NULL;
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