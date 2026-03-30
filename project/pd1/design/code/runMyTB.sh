#/bin/bash

[[ -d obj_dir ]] && rm -rf obj_dir

verilator --top test_Mem test_Mem.sv memory.sv --binary --trace -o testMem +define+LINE_COUNT=$( wc -l ../../verif/data/test1.pattern |  awk  '{print $1}') +define+MEM_DEPTH=1048576 +define+MEM_PATH=\"/home/mo/school/4201/RISCV/project/pd1/verif/data/test1.patten\" --timing

make -C obj_dir -f obj_dir/Vtest_Mem.mk  
