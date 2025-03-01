cmake_minimum_required(VERSION 3.28)
project(FatRayTracer LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

# Automatically find all header files in include/Core
file(GLOB CORE_HEADERS include/RTimpl/Core/*.h)
file(GLOB RS_CORE_HEADERS include/RSimpl/Core/*.h)
# Automatically find all source files in src/Core
file(GLOB CORE_SOURCES src/RTimpl/Core/*.cpp)
file(GLOB RS_CORE_SOURCES src/RSimpl/Core/*.cpp)

# Automatically find all header files in include/Render
file(GLOB RENDER_HEADERS include/RTimpl/Render/*.h)
file(GLOB RS_RENDER_HEADERS include/RSimpl/Render/*.h)
# Automatically find all source files in src/Render
file(GLOB RENDER_SOURCES src/RTimpl/Render/*.cpp)
file(GLOB RS_RENDER_SOURCES src/RSimpl/Render/*.cpp)

# Automatically find all header files in include/Utils
file(GLOB UTILS_HEADERS include/Utils/*.h)
# Automatically find all source files in src/Utils
file(GLOB UTILS_SOURCES src/Utils/*.cpp)



# Add main.cpp and the core sources to the executable
add_executable(FatRayTracer src/main.cpp ${CORE_SOURCES} ${RENDER_SOURCES} ${UTILS_SOURCES} ${RS_CORE_SOURCES} ${RS_RENDER_SOURCES})
# Specify the include directories
target_include_directories(FatRayTracer PRIVATE include)

target_link_libraries(FatRayTracer PRIVATE sfml-graphics)
target_compile_features(FatRayTracer PRIVATE cxx_std_17)
target_compile_options(FatRayTracer PRIVATE -O3)
if(WIN32)
    add_custom_command(
        TARGET FatRayTracer
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:FatRayTracer>
        VERBATIM)
endif()
