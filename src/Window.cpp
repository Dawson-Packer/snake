#include "../include/Window.h"

Window::Window(int width_, int height_) :
    width(width_), height(height_)
{
        
        SDL_Init(SDL_INIT_VIDEO);
        SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
        SDL_SetWindowTitle(window, "Snake Game");
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        screen_surface = SDL_GetWindowSurface(window);
        icon = SDL_LoadBMP("media/icon.bmp");
        SDL_SetWindowIcon(window, icon);

        isOpen = (window != NULL) ? true : false;

}

void Window::set_title(std::string title) {
    SDL_SetWindowTitle(window, title.c_str());
}

void Window::update(std::vector<_texture> textures) {

    SDL_RenderClear(renderer);
    
    for (int i = 0; i < textures.size(); ++i) {
        
        SDL_Texture* loaded_texture = load_texture(textures[i].path);
        SDL_RenderCopyEx(renderer, loaded_texture, NULL, &textures[i].dim, textures[i].rotation,
        NULL, SDL_FLIP_NONE);
        SDL_DestroyTexture(loaded_texture);
    }

    SDL_RenderPresent(renderer);

}

void Window::close() {

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    isOpen = false;

}


SDL_Surface* Window::load_surface(std::string path)  {

    SDL_Surface* loaded_surface = SDL_LoadBMP(path.c_str());
    if (loaded_surface == NULL) {
		printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
    }
    return loaded_surface;

}

SDL_Texture* Window::load_texture( std::string path ) {

    SDL_Texture* loaded_texture = NULL;
    SDL_Surface* loaded_surface = load_surface(path);

    loaded_texture = SDL_CreateTextureFromSurface(this->renderer, loaded_surface);
    if (loaded_texture == NULL) {
        printf("Unable to load texture %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
    }

    SDL_FreeSurface(loaded_surface);
    return loaded_texture;


}