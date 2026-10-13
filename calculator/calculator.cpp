#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>

const double PI = 3.14159265358979323846;

void printHelp() {
    std::cout << "Usage: calculator [OPTIONS] VALUE\n"
              << "Trigonometric calculator (variant 10)\n\n"
              << "Options:\n"
              << "  -o, --operation <op>   Operation: asin | acos\n"
              << "  -d, --degrees          Use degrees (default: radians)\n"
              << "  -r, --radians          Use radians\n"
              << "  -h, --help             Show this help\n\n"
              << "Examples:\n"
              << "  calculator -o asin 0.5\n"
              << "  calculator -o acos 0.5 --degrees\n";
}

int main(int argc, char* argv[]) {
    std::string operation;
    double value = 0.0;
    bool haveValue = false;
    bool degrees = false;

    if (argc == 1) {
        printHelp();
        return 0;
    }

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-h" || arg == "--help") {
            printHelp();
            return 0;
        }
        else if (arg == "-o" || arg == "--operation") {
            if (i + 1 >= argc) {
                std::cerr << "Error: operation requires an argument\n";
                return 1;
            }
            operation = argv[++i];
        }
        else if (arg == "-d" || arg == "--degrees") {
            degrees = true;
        }
        else if (arg == "-r" || arg == "--radians") {
            degrees = false;
        }
        else {
            char* endptr = nullptr;
            value = std::strtod(arg.c_str(), &endptr);
            if (*endptr != '\0') {
                std::cerr << "Error: invalid number '" << arg << "'\n";
                return 1;
            }
            haveValue = true;
        }
    }

    if (operation.empty()) {
        std::cerr << "Error: operation not specified. Use -h for help.\n";
        return 1;
    }
    if (!haveValue) {
        std::cerr << "Error: operand not specified. Use -h for help.\n";
        return 1;
    }

    double result = 0.0;

    if (operation == "asin") {
        if (value < -1.0 || value > 1.0) {
            std::cerr << "Error: asin is defined only for [-1, 1]\n";
            return 1;
        }
        result = std::asin(value);
        if (degrees) result = result * 180.0 / PI;
    }
    else if (operation == "acos") {
        if (value < -1.0 || value > 1.0) {
            std::cerr << "Error: acos is defined only for [-1, 1]\n";
            return 1;
        }
        result = std::acos(value);
        if (degrees) result = result * 180.0 / PI;
    }
    else {
        std::cerr << "Error: unknown operation '" << operation << "'\n";
        return 1;
    }

    std::cout << std::fixed << std::setprecision(6)
              << operation << "(" << value << ") = " << result
              << (degrees ? " degrees" : " radians") << std::endl;

    return 0;
}
