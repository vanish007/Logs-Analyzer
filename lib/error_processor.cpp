#include <error_processor.h>

bool ErrorProcess(const bool global_error, const ArgumentCheck arg_check, const ArgumentValues arg_values) {
    if (global_error) {
        return true; // error message was already printed previously in program sp we just exit
    } else if (arg_check.output == false) {
        Perror2(101);
        return true;
    } else if (arg_check.global == false && arg_check.log == false) {
         Perror2(700); //print error if no log file nor options were provided
        if (arg_check.help) {
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cerr << "----HELP----\n'-o <path>' or '--output=<path>' - path to a file to write down requests. if no path was found creates new file\n" <<
                        "'-p' or '--print' - duplicate error requests in consol\n" <<
                        "'-s n' or '--stats=n' - write first n most common request with errors\n" <<
                        "'-w n' or '--window=n' -  output the interval of n seconds which had the most requests\n" <<
                        "'-f n' or '--from=n' - start analyse from nth second\n" <<
                        "'-t n' or '--to=n' -  end analyse at nth second\n------------\n";
        } else {
           
            std::cerr << "Write -h or --help to see the list of commands";
        }
        return true;
    }  else if (arg_check.log == false) {
         Perror2(703); //print error if no log file was provided
        if (arg_check.help) {
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cerr << "----HELP----\n'-o <path>' or '--output=<path>' - path to a file to write down requests. if no path was found creates new file\n" <<
                        "'-p' or '--print' - duplicate error requests in consol\n" <<
                        "'-s n' or '--stats=n' - write first n most common request with errors\n" <<
                        "'-w n' or '--window=n' -  output the interval of n seconds which had the most requests\n" <<
                        "'-f n' or '--from=n' - start analyse from nth second\n" <<
                        "'-t n' or '--to=n' -  end analyse at nth second\n------------\n";
        } else {
           
            std::cerr << "Write -h or --help to see the list of commands";
        }
        return true;
    } else if (arg_check.global == false && arg_check.log && arg_check.error == false) {
        Perror2(701); //print error if no arguments were provided
        if (arg_check.help) {
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cerr << "----HELP----\n'-o <path>' or '--output=<path>' - path to a file to write down requests. if no path was found creates new file\n" <<
                        "'-p' or '--print' - duplicate error requests in consol\n" <<
                        "'-s n' or '--stats=n' - write first n most common request with errors\n" <<
                        "'-w n' or '--window=n' -  output the interval of n seconds which had the most requests\n" <<
                        "'-f n' or '--from=n' - start analyse from nth second\n" <<
                        "'-t n' or '--to=n' -  end analyse at nth second\n------------\n";
        } else {
            
            std::cerr << "Write -h or --help to see the list of commands";
        }
        return true;
    } else if (arg_check.global == false && arg_check.error) {
        Perror2(701); //print error if no arguments were provided
        Perror2(702); // print error if more than 2 log files were provided
        if (arg_check.help) {
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cerr << "----HELP----\n'-o <path>' or '--output=<path>' - path to a file to write down requests. if no path was found creates new file\n" <<
                        "'-p' or '--print' - duplicate error requests in consol\n" <<
                        "'-s n' or '--stats=n' - write first n most common request with errors\n" <<
                        "'-w n' or '--window=n' -  output the interval of n seconds which had the most requests\n" <<
                        "'-f n' or '--from=n' - start analyse from nth second\n" <<
                        "'-t n' or '--to=n' -  end analyse at nth second\n------------\n";
        } else {
         
            std::cerr << "Write -h or --help to see the list of commands";
        }
        return true;
    } else if (arg_check.global && arg_check.error) {
        Perror2(702); // print error if more than 2 log files were provided
        return true;
    }
    return false; //if no errors occured retrun false
}