add_library(stackLst stackLst.cpp stackLst.hpp)
set_property(TARGET stackLst PROPERTY CXX_STANDARD 20)
target_include_directories(stackLst PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS stackLst)
