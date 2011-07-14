EXECUTE_PROCESS ( 
  COMMAND sdl-config --libs
  OUTPUT_VARIABLE SDL_LIBS 
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

SET(cyclorEditor_src map.c helper.c resources.c main.c)
ADD_EXECUTABLE(cyclorEditor ${cyclorEditor_src})
TARGET_LINK_LIBRARIES(cyclorEditor ${SDL_LIBS} SDLmain SDL_ttf)

