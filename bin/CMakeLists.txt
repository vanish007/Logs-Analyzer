add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} 
                        strcmp2 
                        validator
                        perror2 
                        my_structs 
                        string_to_int 
                        arg_parcer 
                        error_processor 
                        stats_viewer 
                        string_concatenator
                        strlen2
                        month_to_num
                        log_processor
                        month_to_days
                        local_time_parcer
                        log_parcer)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
