cmake_minimum_required(VERSION 3.10)

# set the project name
project(Doomu)

# bring in LDLIBS
set(LIBS GL glfw dl)

# bring the headers
include_directories(include)

# glad.c as well?
file(GLOB SOURCES 
    "src/*.cpp"
    "src/glad.c"
)

add_executable(Doomu ${SOURCES})
target_link_libraries(Doomu ${LIBS})
