include(GenerateExportHeader)

cmake_minimum_required(VERSION 3.13)
project(libpitcher)


####################PROJECT#####################
cmake_minimum_required(VERSION 3.13)
project(test)
#set(CMAKE_C_FLAGS)
set(BUILD_SHARED_LIBS TRUE)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
################################################

set(PORTAUDIO_DIR "${PROJECT_SOURCE_DIR}/portaudio-lib/")
set(PORTAUDIO_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/portaudio-lib/include")
set(PORTAUDIO_LIB_DIR "${PROJECT_SOURCE_DIR}/portaudio-lib/lib")
link_directories(${PORTAUDIO_LIB_DIR})

#find_path(PORTAUDIO_INCLUDE_DIR NAMES portaudio.h HINTS ${PORTAUDIO_DIR}/include/)
find_library(PORTAUDIO_LIBRARY
        NAMES portaudio_static_x64
        HINTS ${PORTAUDIO_LIB_DIR})

message("portaudio: ${PORTAUDIO_INCLUDE_DIR} | ${PORTAUDIO_LIBRARY}")
message("build ${PROJECT_BINARY_DIR}")

add_library(libpitcher SHARED src/dywapitchtrack.c include/dywapitchtrack.h src/portaudio_helper.c include/portaudio_helper.h include/libpitcher_exports.h)
target_include_directories(libpitcher PRIVATE ${PORTAUDIO_INCLUDE_DIR})
target_link_libraries(libpitcher PRIVATE ${PORTAUDIO_LIBRARY})

add_executable(test executable/main.c)
target_link_libraries(test libpitcher)

#add_custom_command(TARGET test POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_directory ${FFMPEG_SHARED_LIB} ${PROJECT_BINARY_DIR})