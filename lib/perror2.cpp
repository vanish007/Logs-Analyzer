#include <perror2.h>

void Perror2(int error_code) {

    switch (error_code) {
        case 100: {
            std::cerr << "\n---\n" << "Error 100: Too many 'output' options" << "\n---\n";
            break;
        }
        case 101: {
            std::cerr << "\n---\n" << "Error 101: There are no output path" << "\n---\n";
            break;
        }
        case 200: {
            std::cerr << "\n---\n" << "Error 200: Too many 'print' options" << "\n---\n";
            break;
        }
        case 300: { 
            std::cerr << "\n---\n" << "Error 300: Too many 'stats' options" << "\n---\n";
            break;
        }
        case 301: { 
            std::cerr << "\n---\n" << "Error 301: 'Stats' option only takes number. To solve please pass a number" << "\n---\n";
            break;
        }
        case 400: { 
            std::cerr << "\n---\n" << "Error 400: Too many 'window' options" << "\n---\n";
            break;
        }
        case 401: { 
            std::cerr << "\n---\n" << "Error 401: 'Window' option only takes number. To solve please pass a number" << "\n---\n";
            break;
        }
        case 402: { 
            std::cerr << "\n---\n" << "Error 402: Please input value of 'window' option" << "\n---\n";
            break;
        }
        case 500: { 
            std::cerr << "\n---\n" << "Error 500: Too many 'from' options" << "\n---\n";
            break;
        }
        case 501: { 
            std::cerr << "\n---\n" << "Error 501: 'From' option only takes a number. To solve please pass a number >= 0" << "\n---\n";
            break;
        }
        case 502: { 
            std::cerr << "\n---\n" << "Error 502: Please input value of 'from' option" << "\n---\n";
            break;
        }
        case 600: { 
            std::cerr << "\n---\n" << "Error 600: Too many 'to' options" << "\n---\n";
            break;
        }
        case 601: { 
            std::cerr << "\n---\n" << "Error 601: 'To' option only takes a number. To solve please pass a number >= 0" << "\n---\n";
            break;
        }
        case 602: { 
            std::cerr << "\n---\n" << "Error 602: Please input value of 'to' option" << "\n---\n";
            break;
        }
        case 700: {
            std::cerr << "\n---\n" << "Error 700: There are nothing to do. Please pass log file and options" << "\n---\n";
            break;
        }
        case 701: {
            std::cerr << "\n---\n" << "Error 701: There are no arguments. Program does not know what to do" << "\n---\n";
            break;
        }
        case 702: {
            std::cerr << "\n---\n" << "Error 702: Too many log files. Program could not deside which file to parse" << "\n---\n";
            break;
        }
        case 703: {
            std::cerr << "\n---\n" << "Error 703: There are no log file. Please pass a file to process" << "\n---\n";
            break;
        }
        case 800: {
            std::cerr << "\n---\n" << "Error 800: Program could not find a log file to open. Probably the wrong name or the file does not exists" << "\n---\n";
            break;
        }
        case 900: { 
            std::cerr << "\n---\n" << "Error 900: Too many 'help' options" << "\n---\n";
            break;
        }
        default: {
            std::cerr << "\n---\n" << "Fatal error: program finished with unknown error" << "\n---\n";
            break;
        }
    }
}
