SET(cyclorEditor_src resources.c main.c)
ADD_EXECUTABLE(cyclorEditor ${cyclorEditor_src})
TARGET_LINK_LIBRARIES(cyclorEditor SDL SDL_ttf)
