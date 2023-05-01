set(DATA_COLLECTOR_SOURCES
    "getWindProData.cpp"
    )

add_library(${GET_DATA_LIBRARY} STATIC 
    ${DATA_COLLECTOR_HEADERS} 
    ${DATA_COLLECTOR_SOURCES}
    )

target_include_directories(${GET_DATA_LIBRARY} 
    PUBLIC ${CMAKE_SOURCE_DIR}/include/data_collector
    )
target_link_libraries(${GET_DATA_LIBRARY} 
    PUBLIC Boost::boost
    )