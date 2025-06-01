project(Burnout)

add_executable(${PROJECT_NAME} "")
target_sources(${PROJECT_NAME}
    PRIVATE
        main.cpp
        GameSource/Game/BrnGameModule.cpp
        GameShared/GameClasses/Module/CgsModule.cpp
        GameShared/GameClasses/Module/CgsDataBuffer.cpp
        GameShared/GameClasses/Module/CgsDataStructure.cpp
        GameShared/GameClasses/Module/CgsModuleSingleBuffered.cpp
        
    PUBLIC
        types.hpp
        GameSource/Game/BrnGameModule.hpp
        GameShared/GameClasses/Core/CgsAssert.h
        GameShared/GameClasses/Module/CgsModule.h
        GameShared/GameClasses/Module/CgsDataBuffer.h
        GameShared/GameClasses/Module/CgsDataStructure.h
        GameShared/GameClasses/Module/CgsModuleSingleBuffered.h
        GameShared/GameClasses/Module/CgsModuleSingleBufferedTemplate.h
        GameShared/GameClasses/Containers/CgsFlagSet.h
)

target_link_libraries(${PROJECT_NAME} EAThread)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_NAME "${PROJECT_NAME}_$<CONFIG>"
)