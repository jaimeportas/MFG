#ifndef GRAPHICS_H
#define GRAPHICS_H


/* Graphics class
 * Holds all information dealing with graphics for the game
 */

#include <map>
#include <string>
#include <SDL.h>
#include "globals.h"


struct SDL_Window;
struct SDL_Renderer;

class Graphics
{
public:
  Graphics();
  ~Graphics();

  /* SDL_Surface* loadimage
   * Loads an image into the _spriteSheets map if it doesn�t already exist.
   * As a result, each image will only ever be loaded once.
   * Returns the image from the map regardless of whether or not it was just loaded.
   */
  SDL_Surface* loadImage(const std::string &filePath);

  /* void blitSurface
   * Draws a texture to a certain part of the screen.
   */
  void blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);
  void blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle, const double rot);

  void DrawRectangle(const SDL_Rect *destinationRectangle, const Color color);
  void DrawLinie(const Vector2 p1, const Vector2 p2, const Color color);


  /* void flip
   * Renders everthing to the screen.
   */
  void flip();
  
  /* void clear
   * Clear the screen.
   */
  void clear();

  /* SDL_Renderer* getRenderer
   * Returns the renderer
   */
  SDL_Renderer* getRenderer() const;



private:
  SDL_Window*    _window;
  SDL_Renderer*  _renderer;

  std::map<std::string, SDL_Surface*> _spriteSheets;

  int Graphics::SetColor(Color color);
};

#endif
