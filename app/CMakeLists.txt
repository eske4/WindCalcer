set(EXE_SOURCES
    "main.cpp"
)

add_executable(${EXECUTABLE_NAME} ${EXE_SOURCES})
include_directories("${CMAKE_BINARY_DIR}/configured_files/include")
target_link_libraries(${EXECUTABLE_NAME} PUBLIC 
    ${FILE_DIALOG}
    ${UI_LIBRARY}
    ${GET_DATA_LIBRARY}
    )
