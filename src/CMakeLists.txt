add_library(pisa-runtime
    ${PROJECT_SOURCE_DIR}/src/simdbp_query_processor.cpp
)
target_link_libraries(pisa-runtime PUBLIC pisa PRIVATE project_warnings project_options)
target_include_directories(pisa-runtime
    PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)

add_executable(query
    ${PROJECT_SOURCE_DIR}/src/query.cpp
)
target_link_libraries(query PRIVATE project_warnings project_options pisa-runtime)
target_include_directories(query
    PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
