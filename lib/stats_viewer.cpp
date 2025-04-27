#include <stats_viewer.h>

void StatsViewe(const ArgumentCheck arg_check, const ArgumentValues arg_values) {
    if (arg_check.help) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << "----HELP----\n'-o <path>' or '--output=<path>' - path to a file to write down requests. if no path was found creates new file\n" <<
                        "'-p' or '--print' - duplicate error requests in consol\n" <<
                        "'-s n' or '--stats=n' - write first n most common request with errors\n" <<
                        "'-w n' or '--window=n' -  output the interval of n seconds which had the most requests\n" <<
                        "'-f n' or '--from=n' - start analyse from nth second\n" <<
                        "'-t n' or '--to=n' -  end analyse at nth second\n------------\n";
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "***STATS***\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    if (arg_values.output != nullptr) {
        std::cout << "output: " << arg_check.output << " values: " << arg_values.output << '\n';
    } else {
        std::cout << "output: " << arg_check.output << " values: " << 0 << '\n';
    }
    if (arg_values.log != nullptr) {
        std::cout << "log: " << arg_check.log << " values: " << arg_values.log << '\n';
    } else {
        std::cout << "log: " << arg_check.log << " values: " << 0 << '\n';
    }
    std::cout << "print: " << arg_check.print << '\n';
    std::cout << "stats: " << arg_check.stats << " values: " << arg_values.stats << '\n';
    std::cout << "window: " << arg_check.window << " values: " << arg_values.window << '\n';
    std::cout << "from: " << arg_check.from << " values: " << arg_values.from << '\n';
    std::cout << "to: " << arg_check.to << " values: " << arg_values.to << '\n';
    std::cout << "help: " << arg_check.help << '\n';
    std::cout << "***********\n";
}