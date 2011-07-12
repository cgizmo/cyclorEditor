SET(cyclorEditor_src main.c)
ADD_EXECUTABLE(cyclorEditor ${cyclorEditor_src})
TARGET_LINK_LIBRARIES(cyclorEditor SDL)
