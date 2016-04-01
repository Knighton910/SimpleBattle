cmake_minimum_required (VERSION 2.6)
project (StarBattle)

add_subdirectory(../../oxygine-framework oxygine-framework)

add_definitions(${OXYGINE_DEFINITIONS})
include_directories(${OXYGINE_INCLUDE_DIRS})
link_directories(${OXYGINE_LIBRARY_DIRS})

add_subdirectory(../../oxygine-sound oxygine-sound)
include_directories(${OXYGINESOUND_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -ggdb")

include_directories(
    ../src )

add_executable(StarBattle
	        ../src/app.cpp
	        ../src/config.cpp
	        ../src/main.cpp
            ../src/gun.cpp
            ../src/Menu.cpp
            ../src/Bullet.cpp
            ../src/ship.cpp
            ../src/Plot/Plot.cpp
            ../src/Plot/PlotLine.cpp
            ../src/Plot/Row.cpp
            ../src/Plot/PlotPoint.cpp
            ../src/Plot/PlotBet.cpp)

target_link_libraries(StarBattle
	${OXYGINE_CORE_LIBS} ${OXYGINESOUND_LIBS})
