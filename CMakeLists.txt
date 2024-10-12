cmake_minimum_required(VERSION 3.28 )

set(PROJECT_NAME StarFox)
project(${PROJECT_NAME})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(${PROJECT_NAME} 
src/main.cpp
src/Player.cpp
src/Player.h 
src/ClassAnimationManager.cpp
src/ClassAnimationManager.h
src/Bullet.h
src/Bullet.cpp
src/Entity.cpp 
src/Entity.h
src/Enemy.cpp
src/Enemy.h
src/Map.h 
src/Map.cpp 
img/SpriteList.png
)

FILE(
    COPY "${CMAKE_CURRENT_SOURCE_DIR}/img"
    DESTINATION "${CMAKE_CURRENT_BINARY_DIR}"
)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME}
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
        VERBATIM)
endif()
