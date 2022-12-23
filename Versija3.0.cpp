#include "funkcijos.hpp"

int main() {
    int x = print_pradzia();
    while (x != 0) {
        if (x == 1) { testas(); }
        else if (x == 2) { testas2(); }
        else if (x == 3) { failo_gen(); }
        else if (x == 4) { f_nusk(); }
        else { duom_ivedimas(); }
        x = print_pradzia();
    }
    exit(0);
};
