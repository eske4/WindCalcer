set(FILE_DIALOG_SOURCES
    "file_dialog.cpp"
    )

add_library(${FILE_DIALOG} STATIC 
    ${FILE_DIALOG_HEADERS} 
    ${FILE_DIALOG_SOURCES}
    )

target_include_directories(${FILE_DIALOG} 
    PUBLIC ${CMAKE_SOURCE_DIR}/include/file_dialog
    )
target_link_libraries(${FILE_DIALOG} 
    PUBLIC portable_file_dialogs
)