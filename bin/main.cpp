#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

#include <my_structs.h>

#include <arg_parcer.h>
#include <log_parcer.h>
#include <error_processor.h>
#include <stats_viewer.h>

int main(int argc, char* argv[]) {
    ArgumentCheck arg_check;
    ArgumentValues arg_values;
    bool global_error = false;


    ArgParce(argc, argv, arg_check, arg_values, global_error);
    if (ErrorProcess(global_error, arg_check, arg_values)) exit(EXIT_FAILURE);
    StatsViewe(arg_check, arg_values);


    std::ifstream fin; //opens file to read
    const char* t1 = ConcatenateString("../../", arg_values.log);
    fin.open(t1);
    delete [] t1;
    if (!fin.is_open()) { //if no file was found exits;
        fin.close();
        Perror2(800); //error: no log file was found
        exit(EXIT_FAILURE);
    }
    std::ofstream fout; //opens file to write info
    const char* t2 = ConcatenateString("../../", arg_values.output);
    fout.open(t2);
    delete [] t2;


    char n;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Is everything correct?" << std::endl 
              << "Press y/n: " << std::endl;
    std::cin >> n;


    if (n == 'y') {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "Preparing..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "Program started" << std::endl;

        LogParce(arg_check, arg_values, fin, fout);

        fin.close();
        fout.close();

        std::cout << "Program finished" << std::endl;
    } else {
        std::cout << "Program finished so you can rewrite info." 
        << " Warning: you can only write 'y' or 'n'";

        fin.close();
        fout.close();

        exit(EXIT_FAILURE);
    }


    return EXIT_SUCCESS;
}