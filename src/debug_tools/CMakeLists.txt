set(DEBUG_TOOLS_SOURCES
    "debug_tools.cpp"
    )

add_library(${DEBUG_TOOLS} STATIC 
    ${DEBUG_TOOLS_HEADERS} 
    ${DEBUG_TOOLS_SOURCES}
    )

target_include_directories(${DEBUG_TOOLS} 
    PUBLIC ${CMAKE_SOURCE_DIR}/include/debug_tools
    )