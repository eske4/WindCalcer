cmake_minimum_required(VERSION 3.26.3)

project(WindCalcer VERSION 0.1.2 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

set(FILE_DIALOG file_dialog)
set(UI_LIBRARY ui_library)
set(GET_DATA_LIBRARY get_data_library)
set(EXECUTABLE_NAME WindCalcer)
set(DEBUG_TOOLS debug_tools)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(AddGitSubmodule)
include(${CMAKE_SOURCE_DIR}/external/vcpkg/scripts/buildsystems/vcpkg.cmake)

enable_testing()

find_package(Boost REQUIRED)
find_package(GTest CONFIG REQUIRED)


add_git_submodule(external/file_dialog)

add_subdirectory(configured)
add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(app)
add_subdirectory(tests)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_GENERATOR "NSIS")
include(CPack)