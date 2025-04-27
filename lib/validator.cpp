#include <validator.h>

int Validate(char* arg, char ref) {
    if (StrCmp2(ref, 'o')) {
        const char* correct_arguments[] = {"-o", "--output", "--output="};

        int size =  sizeof(correct_arguments) / sizeof(correct_arguments[0]);

        for (int i = 0; i < size; ++i) {
            if (StrCmp2(arg, correct_arguments[i], 9)) {
                if (i == 2) {
                    return 2;
                } else {
                    return 1;
                }
            }
        }
        return 0;
    } else if (StrCmp2(ref, 'p')) {
        const char* correct_arguments[] = {"-p", "--print"};

        int size =  sizeof(correct_arguments) / sizeof(correct_arguments[0]);

        for (int i = 0; i < size; ++i) {
            if (StrCmp2(arg, correct_arguments[i]) == 0) {
                return 1;
            }
        }
        return 0;
    } else if (StrCmp2(ref, 's')) {
        const char* correct_arguments[] = {"-s", "--stats", "--stats="};

        int size =  sizeof(correct_arguments) / sizeof(correct_arguments[0]);

        for (int i = 0; i < size; ++i) {
            if (StrCmp2(arg, correct_arguments[i], 8)) {
                if (i == 2) {
                    return 2;
                } else {
                    return 1;
                }
            }
        }
        return 0;
    } else if (StrCmp2(ref, 'w')) {
        const char* correct_arguments[] = {"-w", "--window", "--window="};

        int size =  sizeof(correct_arguments) / sizeof(correct_arguments[0]);

        for (int i = 0; i < size; ++i) {
            if (StrCmp2(arg, correct_arguments[i], 9)) {
                if (i == 2) {
                    return 2;
                } else {
                    return 1;
                }
            }
        }
        return 0;
    } else if (StrCmp2(ref, 'f')) {
        const char* correct_arguments[] = {"-f", "--from", "--from="};

        int size =  sizeof(correct_arguments) / sizeof(correct_arguments[0]);

        for (int i = 0; i < size; ++i) {
            if (StrCmp2(arg, correct_arguments[i], 7)) {
                if (i == 2) {
                    return 2;
                } else {
                    return 1;
                }
            }
        }
        return 0;
    } else if (StrCmp2(ref, 't')) {
        const char* correct_arguments[] = {"-t", "--to", "--to="};

        int size =  sizeof(correct_arguments) / sizeof(correct_arguments[0]);

        for (int i = 0; i < size; ++i) {
            if (StrCmp2(arg, correct_arguments[i], 5)) {
                if (i == 2) {
                    return 2;
                } else {
                    return 1;
                }
            }
        }
        return 0;
    } else if (StrCmp2(ref, 'h')) {
        const char* correct_arguments[] = {"-h", "--help"};

        int size =  sizeof(correct_arguments) / sizeof(correct_arguments[0]);

        for (int i = 0; i < size; ++i) {
            if (StrCmp2(arg, correct_arguments[i]) == 0) {
                return 1;
            }
        }
        return 0;
    }
    return 0;
}
