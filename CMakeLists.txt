cmake_minimum_required(VERSION 3.29)
project(RBX-CPP VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

add_executable(rbx-cpp main.cpp
        rbx/rbxcpp.h
        rbx/classes/services.h
        rbx/classes/baseinstance.h
        rbx/classes/connection.h
        rbx/classes/replicatedstorage.h
        rbx/lib/buffer.h
        rbx/lib/coroutine.h
        rbx/lib/debug.h
        rbx/types/buffer_t.h
        rbx/types/coroutine_t.h
)

target_include_directories(rbx-cpp PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/rbx>
        $<INSTALL_INTERFACE:include/rbxcpp>
)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/rbx/ DESTINATION include/rbxcpp)
install(TARGETS rbx-cpp DESTINATION bin)

include(CPack)

set(CPACK_PACKAGE_NAME "rbxcpp")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "rbx-cpp: C++ framework for Roblox development")
set(CPACK_GENERATOR "TGZ;ZIP;DEB;RPM")
# set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
