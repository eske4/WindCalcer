set(UI_SOURCES
    "UI.cpp"
    )

add_library(${UI_LIBRARY} STATIC 
    ${UI_HEADERS} 
    ${UI_SOURCES}
    )

target_include_directories(${UI_LIBRARY} 
    PUBLIC ${CMAKE_SOURCE_DIR}/include/UI
    )
