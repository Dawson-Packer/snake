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
        screen_surface = SDL_GetWindowSurface(window);
        //bool media_loaded = load_media();
        icon = SDL_LoadBMP( "../media/icon.bmp" );
        SDL_SetWindowIcon( window, icon );
        //update_surface( SURFACE_DEFAULT );

        isOpen = ( window != NULL ) ? true : false;

}

void Window::set_title(std::string title) {
    SDL_SetWindowTitle( window, title.c_str() );
}

/*bool Window::load_media( std::vector<_texture> textures, std::vector<_surface> surfaces ) {

    bool success = true;
    icon = SDL_LoadBMP( "../media/icon.bmp" );

    for ( int i = 0; i < textures.size(); ++i ) all_textures[ i ] = load_texture( textures[ i ].path );

    for ( int i = 0; i < surfaces.size(); ++i ) preloaded_surfaces[ i ] = load_surface( surfaces[ i ].path );

    screen_surface = SDL_GetWindowSurface(window);
    return success;

}*/

void Window::update( std::vector<_texture> textures, std::vector<_surface> surfaces ) {

    for ( int i = 0; i < surfaces.size(); ++i ) {
        
        SDL_BlitSurface( load_surface( surfaces[ i ].path ), NULL, screen_surface, NULL );

    }
    SDL_UpdateWindowSurface( this->window );
    /*for ( int i = 0; i < textures.size(); ++i) {

        SDL_Texture* current_texture = load_texture( textures[ i ].path );
        current_texture.render( textures[ i ].x_pos, textures[ i ].y_pos );

    }*/

}

/*void Window::render_surface( int surface_type) {
    
    top_surface = preloaded_surfaces[ surface_type ];
    SDL_BlitSurface( top_surface, NULL, screen_surface, NULL );
    SDL_UpdateWindowSurface( this->window );


}

void Window::render_texture( int texture_id, int x, int y ) {
    
    all_textures[ TEXTURE_TOTAL ].render( x, y );
    SDL_RenderPresent( renderer );

}*/

void Window::close() {

    SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow( window );
    isOpen = false;

}


SDL_Surface* Window::load_surface( std::string path)  {

    SDL_Surface* loaded_surface = SDL_LoadBMP( path.c_str() );
    if (loaded_surface == NULL) {
		printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }
    return loaded_surface;

}

SDL_Texture* Window::load_texture( std::string path ) {

    SDL_Texture* loaded_texture = NULL;
    SDL_Surface* loaded_surface = load_surface( path );

    loaded_texture = SDL_CreateTextureFromSurface( this->renderer, loaded_surface );
    if (loaded_texture == NULL) {
        printf( "Unable to load texture %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }

    SDL_FreeSurface( loaded_surface );
    return loaded_texture;


}