cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
set(PROJECT_NAME DominiGamesCheckers)
project(${PROJECT_NAME})

set(BUILD_SHARED_LIBS OFF)
set(CMAKE_CXX_STANDART 17)

file(GLOB sources 
		"${PROJECT_SOURCE_DIR}/include/Controller/*.h"
        "${PROJECT_SOURCE_DIR}/include/Controller/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/Controller/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/Controller/*.c"
		"${PROJECT_SOURCE_DIR}/include/Graphics/*.h"
        "${PROJECT_SOURCE_DIR}/include/Graphics/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/Graphics/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/Graphics/*.c"
		"${PROJECT_SOURCE_DIR}/include/Model/*.h"
        "${PROJECT_SOURCE_DIR}/include/Model/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/Model/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/Model/*.c"
		"${PROJECT_SOURCE_DIR}/include/View/*.h"
        "${PROJECT_SOURCE_DIR}/include/View/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/View/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/View/*.c"
	 	"${PROJECT_SOURCE_DIR}/include/Facades/*.h"
        "${PROJECT_SOURCE_DIR}/include/Facades/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/Facades/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/Facades/*.c"
		"${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/include/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.c"	
)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
add_executable(${PROJECT_NAME} ${sources})

find_package(SFML REQUIRED)

if(SFML_FOUND)
		target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_INCLUDE_DIR})
		target_link_libraries(${PROJECT_NAME} PRIVATE sfml-audio sfml-graphics sfml-system sfml-window sfml-network)
endif()		
