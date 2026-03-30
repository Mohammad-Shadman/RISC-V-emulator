#include <verilated.h>
#include "obj_dir/Vtest_Mem.h"


int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Vtest_Mem top;
    while (!Verilated::gotFinish()) {
        top.eval();
    }
    return 0;
}
