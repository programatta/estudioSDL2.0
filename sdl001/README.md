# SDL001
Instalamos SDL2 para realizar este ejemplo:

~~~
$ sudo apt install libsdl2-dev libsdl2-2.0-0
~~~

Uso Qt Creator 4.8.1 como IDE de programación.

***Nota:*** Sigo los videos de ***Avery Reed*** de YouTube [Let's Make A Game with C++ and SDL2 - Game ](https://www.youtube.com/watch?v=m4Pow9YsDyc&list=PLVotA8ycjnCs3DNWIbEIpBrjYkhJq11q-) 

## Creación del proyecto.
Se crea el proyecto como **No-Qt-Project**.

En el fichero **.pro** añadimos estas líneas:

~~~
LIBS += -L/usr/lib -lSDL2

INCLUDES += /usr/local/include
~~~

## Funciones utilizadas.

### SDL_Init.
Con esta función inicalizamos la librería con los subsistemas que se le indiquen por parámetro (son flags).

~~~
int SDL_Init(Uint8 flags)
~~~
ej:
~~~
int status = SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER )
~~~

Si todo va bien, el valor retornado es 0.

Ver: [SDL_Init](http://wiki.libsdl.org/SDL_Init?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)

---
### SDL_CreateWindow.
Con esta función creamos una ventana en una posición determidada de la pantalla, con un alto y ancho y una serie de flags.

~~~
SDL_Window* SDL_CreateWindow(const char* title, int x, int y, int w, int h, Uint32 flags)
~~~
ej:
~~~
SDL_Window *mWindow;
mWindow = SDL_CreateWindow(
    "SDL001",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    640,
    480,
    SDL_WINDOW_SHOWN
);
~~~

Si todo da bien, el valor retornado es distinto de **nullptr**.

Ver: [SDL_CreateWindow](http://wiki.libsdl.org/SDL_CreateWindow?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)

---
### SDL_CreateRenderer
Con esta función creamos un contexto 2D para una ventana.

~~~
SDL_Renderer* SDL_CreateRenderer(SDL_Window* window, int index, Uint32 flags)
~~~
ej:
~~~
SDL_Renderer *mRenderer;
mRenderer = SDL_CreateRenderer(
    mWindow,
    -1, //Indicamos el primer driver que acepte el siguiente flag.
    SDL_RENDERER_ACCELERATED
);
~~~

Si todo va bien, el valor retornado es distinto de **nullptr**.

Ver:[SDL_CreateRenderer](http://wiki.libsdl.org/SDL_CreateRenderer?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)

---
### SDL_GetTicks
Con esta función obtenemos el tiempo en milisegundos desde que se inicializó la librería.

~~~
Uint32 SDL_GetTicks(void)
~~~
ej:
~~~
Uint32 mLastFrame;
mLastFrame = SDL_GetTicks();
~~~

Ver:[SDL_GetTicks](http://wiki.libsdl.org/SDL_GetTicks?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)

---
### SDL_SetRenderDrawColor
Con esta función establecemos el color que se va a aplicar a operaciones de dibujo (vale para rectangulos, lineas y borrado de la ventana).

~~~
int SDL_SetRenderDrawColor(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
~~~
ej:
~~~
int status = SDL_SetRenderDrawColor(mRenderer, 255,0,0,255);
~~~

Si todo va bien, el valor retornado es 0. 

Ver:[SDL_SetRenderDrawColor](http://wiki.libsdl.org/SDL_SetRenderDrawColor?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)

---
### SDL_RenderFillRect
Con esta función rellenamos un rectangulo con un color indicado con **SDL_SetRenderDrawColor** o toda la ventana si ponemos **nullptr**.

~~~
int SDL_RenderFillRect(SDL_Renderer* renderer, const SDL_Rect* rect)
~~~
ej:
~~~
int status = SDL_RenderFillRect(mRenderer, nullptr);
~~~

Si todo va bien, el valor retornado es 0. 

Ver:[SDL_RenderFillRect](http://wiki.libsdl.org/SDL_RenderFillRect?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)

---
### SDL_Delay
Con esta función se realiza una pausa en milisegundos.

~~~
void SDL_Delay(Uint32 ms)
~~~
ej:
~~~
SDL_Delay( 2000 );
~~~

Ver:[SDL_Delay](http://wiki.libsdl.org/SDL_Delay?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)

---
### SDL_RenderPresent
Con esta función se actualiza la pantalla con el contenido del renderer.

~~~
void SDL_RenderPresent(SDL_Renderer* renderer)
~~~
ej:
~~~
SDL_RenderPresent( mRenderer );
~~~

Ver:[SDL_RenderPresent](http://wiki.libsdl.org/SDL_RenderPresent?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)

---
### SDL_DestroyRenderer
Con esta función destruimos el contexto de un renderer de una ventana y se liberan las texturas asociadas.

~~~
void SDL_DestroyRenderer(SDL_Renderer* renderer)
~~~
ej:
~~~
SDL_DestroyRenderer( mRenderer );
~~~

Ver:[SDL_DestroyRenderer](http://wiki.libsdl.org/SDL_DestroyRenderer?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)

---
### SDL_DestroyWindow( mWindow )
Con esta función destruimos la ventana.

~~~
void SDL_DestroyWindow(SDL_Window* window)
~~~
ej:
~~~
SDL_DestroyWindow( mWindow );
~~~

Ver:[SDL_DestroyWindow](http://wiki.libsdl.org/SDL_DestroyWindow?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)

---
### SDL_Quit()
Con esta función se funalizan los subsistemas inicados en **SDL_Init()**

~~~
void SDL_Quit(void)
~~~
ej:
~~~
SDL_Quit();
~~~

Ver:[SDL_Quit](http://wiki.libsdl.org/SDL_Quit?highlight=%28%5CbCategoryAPI%5Cb%29%7C%28SDLFunctionTemplate%29)
