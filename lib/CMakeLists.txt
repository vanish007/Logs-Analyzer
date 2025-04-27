add_library(strcmp2 strcmp2.h strcmp2.cpp)
target_include_directories(strcmp2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(validator validator.h validator.cpp)
target_include_directories(validator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(perror2 perror2.h perror2.cpp)
target_include_directories(perror2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(my_structs my_structs.h my_structs.cpp)
target_include_directories(my_structs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(string_to_int string_to_int.h string_to_int.cpp)
target_include_directories(string_to_int PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(arg_parcer arg_parcer.h arg_parcer.cpp)
target_include_directories(arg_parcer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(error_processor error_processor.h error_processor.cpp)
target_include_directories(error_processor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(stats_viewer stats_viewer.h stats_viewer.cpp)
target_include_directories(stats_viewer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(string_concatenator string_concatenator.h string_concatenator.cpp)
target_include_directories(string_concatenator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(strlen2 strlen2.h strlen2.cpp)
target_include_directories(strlen2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(month_to_num month_to_num.h month_to_num.cpp)
target_include_directories(month_to_num PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(log_processor log_processor.h log_processor.cpp)
target_include_directories(log_processor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(month_to_days month_to_days.h month_to_days.cpp)
target_include_directories(month_to_days PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(local_time_parcer local_time_parcer.h local_time_parcer.cpp)
target_include_directories(local_time_parcer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(log_parcer log_parcer.h log_parcer.cpp)
target_include_directories(log_parcer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
