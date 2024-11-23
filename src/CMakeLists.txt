project(Burnout5)

add_executable(${PROJECT_NAME} "")
target_sources(${PROJECT_NAME}
    PRIVATE
        main.cpp
        BrnGameModule.cpp
        
    PUBLIC
        types.hpp
        BrnGameModule.hpp
)
