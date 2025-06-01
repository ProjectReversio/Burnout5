cmake_minimum_required(VERSION 3.19)
project(Burnout)

add_subdirectory(src)
add_subdirectory(vendor)

set(CMAKE_CONFIGURATION_TYPES
        "PC_Internal;PC_External;PC_Artist;X360_Internal;X360_External;X360_Artist;Internal_PS3;External_PS3;Artist_PS3"
        CACHE STRING "" FORCE
)

target_compile_definitions(Burnout PRIVATE
        $<$<CONFIG:PC_Internal>:    B5_PLATFORM_PC>
        $<$<CONFIG:PC_External>:    B5_PLATFORM_PC>
        $<$<CONFIG:PC_Artist>:      B5_PLATFORM_PC>
        $<$<CONFIG:X360_Internal>:  B5_PLATFORM_X360>
        $<$<CONFIG:X360_External>:  B5_PLATFORM_X360>
        $<$<CONFIG:X360_Artist>:    B5_PLATFORM_X360>
        $<$<CONFIG:Internal_PS3>:   B5_PLATFORM_PS3>
        $<$<CONFIG:External_PS3>:   B5_PLATFORM_PS3>
        $<$<CONFIG:Artist_PS3>:     B5_PLATFORM_PS3>
)

target_compile_definitions(Burnout PRIVATE
        $<$<OR:$<CONFIG:PC_External>,$<CONFIG:X360_External>,$<CONFIG:External_PS3>>:NDEBUG>
)