#include <arg_parcer.h>

void ArgParce(int argc, char* argv[], ArgumentCheck& arg_check, 
                ArgumentValues& arg_values, bool& global_error) {
    // if no arguments are provided, return early
    if (argc <= 1) {
        return;
    }
    // iterate through each command line argument, starting from index 1. 0-index is the name of the program, so we start from 1st
    for (int i = 1; i < argc; ++i) {
        // validate argument for 'output' flag
        int valO = Validate(argv[i], 'o');
        // check if the argument for 'output' is already set
        if (valO && arg_check.output) {
            Perror2(100);  // error for duplicated 'output' argument
            global_error = true;
            return;
        }
        // handle 'output' argument 
        if (valO == 1 && i+1 != argc) {
            arg_check.output = true;
            arg_check.global = true;
            arg_values.output = argv[i+1]; //if i+1 != argc than next argv in value of output
            i++;
            continue;
        } else if (valO == 1 && i+1 == argc) {
            Perror2(101); //error if 'output' was not provided with argument
            global_error = true;
            return;
        } else if (valO == 2 && argv[i][9] != '\0') { //--output=<path> -> [9] is first symbol of the path
            arg_check.output = true;
            arg_check.global = true; 
            arg_values.output = &(argv[i][9]);
            continue;   
        } else if (valO == 2) {
            Perror2(101); // error for invalid 'output' format
            global_error = true;
            return; 
        }


        // validate argument for 'print' flag
        int valP = Validate(argv[i], 'p');
        // check if the argument for 'print' is already set
        if (valP && arg_check.print) {
            Perror2(200); //error for duplicated 'print' argument
            global_error = true;
            return;
        }
        // handle 'print' argument 
        if (valP == 1) {
            arg_check.print = true; //it does not require any additional argv
            arg_check.global = true;
            continue;
        }

        // validate argument for 'help' flag
        int valH = Validate(argv[i], 'h');
        // check if the argument for 'help' is already set
        if (valH && arg_check.help) {
            Perror2(900); //error for duplicated 'help' argument
            global_error = true;
            return;
        }
        // handle 'help' argument 
        if (valH == 1) {
            arg_check.help = true; //it also doesnt require additional info
            continue;
        }

        // validate argument for 'stats' flag
        int valS = Validate(argv[i], 's');
        // check if the argument for 'stats' is already set
        if (valS && arg_check.stats) {
            Perror2(300); //error for duplicated 'stats' argument
            global_error = true;
            return;
        }
        // handle 'stats' argument
        if (valS == 1 && i+1 != argc) { //we check if there is an argument after this
            if (StringToInt(argv[i+1]) != -1) { //if next value is int we can save it
                arg_check.stats = true;
                arg_values.stats = StringToInt(argv[i+1]); 
                arg_check.global = true;
                ++i;
                continue;
            } else {
                Perror2(301);  // error for invalid 'stats' format
                global_error = true;
                return;
            }
        } else if (valS == 1 && i+1 == argc) {
            arg_check.stats = true;
            arg_values.stats = 10; // default stats value
            arg_check.global = true;
            continue;
        } else if (valS == 2 && argv[i][8] != '\0') { //[8] is first symbol of the value
            if (StringToInt(&(argv[i][8])) != -1) {
                arg_check.stats = true;
                arg_values.stats = StringToInt(&(argv[i][8]));
                arg_check.global = true;
                continue;
            } else {
                Perror2(301); // error for invalid 'stats' format
                global_error = true;
                return;
            }
        } else if (valS == 2) {
            arg_check.stats = true;
            arg_values.stats = 10; // default stats value
            arg_check.global = true;
            continue;
        }

         
        // validate argument for 'window' flag
        int valW = Validate(argv[i], 'w');
        // check if the argument for 'window' is already set
        if (valW && arg_check.window) {
            Perror2(400); //error for duplicated 'window' argument
            global_error = true;
            return;
        }
        // handle 'window' argument
        if (valW == 1 && i+1 != argc) {
            if (StringToInt(argv[i+1]) != -1) {
                arg_check.window = true;
                arg_values.window = StringToInt(argv[i+1]);
                arg_check.global = true;
                ++i;
                continue;
            } else {
                Perror2(401); // error for invalid 'window' format
                global_error = true;
                return;
            }
        } else if (valW == 1 && i+1 == argc) {
            Perror2(402); //error if 'window' was not provided with argument
            global_error = true;
            return;
        } else if (valW == 2 && argv[i][9] != '\0') { //[9] is first symbol of the value
            if (StringToInt(&(argv[i][9])) != -1) {
                arg_check.window = true;
                arg_values.window = StringToInt(&(argv[i][9]));
                arg_check.global = true;
                continue;
            } else {
                Perror2(401); // error for invalid 'window' format
                global_error = true;
                return;
            }
        } else if (valW == 2) {
            Perror2(402); //error if 'window' was not provided with argument
            global_error = true;
            return;
        }


        
        // validate argument for 'from' flag
        int valF = Validate(argv[i], 'f');
        // check if the argument for 'from' is already set
        if (valF && arg_check.from) {
            Perror2(500); //error for duplicated 'from' argument
            global_error = true;
            return;
        }
        // handle 'from' argument
        if (valF == 1 && i+1 != argc) {
            if (StringToInt(argv[i+1]) != -1) {
                arg_check.from = true;
                arg_values.from = StringToInt(argv[i+1]);
                arg_check.global = true;
                ++i;
                continue;
            } else {
                Perror2(501);  // error for invalid 'from' format
                global_error = true;
                return;
            }
        } else if (valF == 1 && i+1 == argc) {
            Perror2(502); //error if 'from' was not provided with argument
            global_error = true;
            return;
        } else if (valF == 2 && argv[i][7] != '\0') {
            if (StringToInt(&(argv[i][7])) != -1) {
                arg_check.from = true;
                arg_values.from = StringToInt(&(argv[i][7]));
                arg_check.global = true;
                continue;
            } else {
                Perror2(501);  // error for invalid 'from' format
                global_error = true;
                return;
            }
        } else if (valW == 2) {
            Perror2(502); //error if 'from' was not provided with argument
            global_error = true;
            return;
        }

       
        // validate argument for 'to' flag
        int valT = Validate(argv[i], 't');
        // check if the argument for 'to' is already set
        if (valT && arg_check.to) {
            Perror2(600); //error for duplicated 'to' argument
            global_error = true;
            return;
        }
        // handle 'to' argument 
        if (valT == 1 && i+1 != argc) {
            if (StringToInt(argv[i+1]) != -1) {
                arg_check.to = true;
                arg_values.to = StringToInt(argv[i+1]);
                arg_check.global = true;
                i++;
                continue;
            } else {
                Perror2(601); // error for invalid 'to' format
                global_error = true;
                return;
            }
        } else if (valT == 1 && i+1 == argc) {
            Perror2(602); //error if 'to' was not provided with argument
            global_error = true;
            return;
        } else if (valT == 2 && argv[i][5] != '\0') {
            if (StringToInt(&(argv[i][5])) != -1) {
                arg_check.to = true;
                arg_values.to = StringToInt(&(argv[i][5]));
                arg_check.global = true;
                continue;
            } else {
                Perror2(601); // error for invalid 'to' format
                global_error = true;
                return;
            }
        } else if (valT == 2) {
            Perror2(602); //error if 'from' was not provided with argument
            global_error = true;
            return;
        }
        // handle unknown argument case. it is either log or unknown option
        if (!valO && !valP && !valS && !valW && !valF && !valT &&!valH) { //put it in the end after all of others
            if (arg_check.log) {
                arg_check.error = true; // if log is already checked, set error and exit
                return;
            } else {
                arg_check.log = true; // otherwise, set this argument as a log
                arg_values.log = argv[i];
                continue;
            }
        }
    }
}