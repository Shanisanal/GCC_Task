#*************************** CMake Configuration ******************************
# Copyright (c) 2026 Trenser Technologies Pvt. Ltd.
# All Rights Reserved
#******************************************************************************
# 
# Project : LED Toggle Task
# Summary : Build configuration for C-based LED toggle print system.
# Note    : Requires CMake 3.15+
# 
#******************************************************************************

#------------------------------------------------------------------------------
# Project and Toolchain Settings
#------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.15)
project(LedToggle C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

#------------------------------------------------------------------------------ 
# Source Directories and Files 
#------------------------------------------------------------------------------
set(SRC_DIRS appTimer LedToggle)
set(SOURCES "${CMAKE_SOURCE_DIR}/main.c")
foreach(dir ${SRC_DIRS})
    file(GLOB SRC_${dir} ${dir}/*.c)
    list(APPEND SOURCES ${SRC_${dir}})
endforeach()

#------------------------------------------------------------------------------ 
# Output Directories 
#------------------------------------------------------------------------------
set(RELEASE_DIR ${CMAKE_SOURCE_DIR}/release)
set(DEBUG_DIR   ${CMAKE_SOURCE_DIR}/debug)

#------------------------------------------------------------------------------ 
# Compiler Flags 
#------------------------------------------------------------------------------
set(RELEASE_FLAGS -Wall;-Wextra;-O2)
set(DEBUG_FLAGS   -Wall;-Wextra;-O0;-g)

# Function to add a build target
function(add_build target compiler flags outdir)
    file(MAKE_DIRECTORY ${outdir})

    # Object files
    foreach(src ${SOURCES})
        get_filename_component(fname ${src} NAME_WE)

        add_custom_command(
            OUTPUT ${outdir}/${fname}_${target}.o                    
            COMMAND ${compiler} ${flags} -c ${src} -o ${outdir}/${fname}_${target}.o
            DEPENDS ${src}
        )

        add_custom_command(
            OUTPUT ${outdir}/${fname}_${target}.s
            COMMAND ${compiler} ${flags} -S ${src} -o ${outdir}/${fname}_${target}.s
            DEPENDS ${src}
        )

        list(APPEND OBJS ${outdir}/${fname}_${target}.o)
        list(APPEND ASMS ${outdir}/${fname}_${target}.s)
    endforeach()

    # Executable (linked from all objects)
    add_custom_command(
        OUTPUT ${outdir}/ledtoggle_${target}.exe
        COMMAND ${compiler} ${flags} ${OBJS} -o ${outdir}/ledtoggle_${target}.exe
        DEPENDS ${OBJS}
    )

    add_custom_target(${target}_build ALL
        DEPENDS ${OBJS} ${ASMS} ${outdir}/ledtoggle_${target}.exe
    )
endfunction()

#------------------------------------------------------------------------------ 
# Build Targets 
#------------------------------------------------------------------------------
add_build(linux gcc "${RELEASE_FLAGS}" ${RELEASE_DIR})
add_build(rpi   aarch64-linux-gnu-gcc "${RELEASE_FLAGS}" ${RELEASE_DIR})

# Debug builds
add_build(linux_debug gcc "${DEBUG_FLAGS}" ${DEBUG_DIR})
add_build(rpi_debug   aarch64-linux-gnu-gcc "${DEBUG_FLAGS}" ${DEBUG_DIR})

# Convenience targets
add_custom_target(build_all DEPENDS linux_build rpi_build)
add_custom_target(build_debug DEPENDS linux_debug_build rpi_debug_build)

# Clean target
add_custom_target(clean_build
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${RELEASE_DIR} ${DEBUG_DIR}
)

#------------------------------------------------------------------------------
# End of File
#------------------------------------------------------------------------------
