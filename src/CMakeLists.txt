#find_package(pisa REQUIRED)
include(FetchContent)
FetchContent_Declare(pisa
  GIT_REPOSITORY    git@github.com:pisa-engine/pisa.git
  GIT_TAG           origin/install-targets
  CMAKE_ARGS        PISA_BUILD_TOOLS=OFF
                    PISA_ENABLE_TESTING=OFF
                    PISA_ENABLE_BENCHMARKING=OFF
)
FetchContent_MakeAvailable(pisa)

add_executable(pisa-runtime ${PROJECT_SOURCE_DIR}/src/query.cpp)
target_link_libraries(pisa-runtime PRIVATE project_warnings project_options pisa_target)
target_include_directories(pisa-runtime
    PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
