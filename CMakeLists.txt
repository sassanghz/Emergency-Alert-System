cmake_minimum_required(VERSION 3.10)
project(emergency_alert_system C)

# Set C standard
set(CMAKE_C_STANDARD 11)

# Add the include directory
include_directories(include)

# Specify source files
set(SOURCES
        src/contact.c
        src/alert.c
        src/utils.c
        src/main.c
)

# Add executable target
add_executable(emergency_alert_system ${SOURCES})

# Link libraries if needed
# For example, if you need to link with libcurl
# target_link_libraries(emergency_alert_system PRIVATE curl)
