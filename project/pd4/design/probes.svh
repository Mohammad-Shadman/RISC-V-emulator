// ----  Probes  ----
`define PROBE_F_PC                pc_fetch
`define PROBE_F_INSN              insn_fetch

`define PROBE_D_PC                pc_decode
`define PROBE_D_OPCODE            opcode_decode
`define PROBE_D_RD                rd_decode
`define PROBE_D_FUNCT3            funct3_decode
`define PROBE_D_RS1               rs1_decode
`define PROBE_D_RS2               rs2_decode
`define PROBE_D_FUNCT7            funct7_decode
`define PROBE_D_IMM               imm_decode
`define PROBE_D_SHAMT             shamt_decode

`define PROBE_R_WRITE_ENABLE      regwren_control
`define PROBE_R_WRITE_DESTINATION rd_decode
`define PROBE_R_WRITE_DATA        datawb_rf
`define PROBE_R_READ_RS1          rs1_decode
`define PROBE_R_READ_RS2          rs2_decode
`define PROBE_R_READ_RS1_DATA     rs1data_rf
`define PROBE_R_READ_RS2_DATA     rs2data_rf

`define PROBE_E_PC                pc_decode
`define PROBE_E_ALU_RES           res_alu
`define PROBE_E_BR_TAKEN          branch_bc

`define PROBE_M_PC                pc_decode
`define PROBE_M_ADDRESS           res_alu
`define PROBE_M_SIZE_ENCODED      memsel_control
`define PROBE_M_DATA              data_mem

`define PROBE_W_PC                pc_decode
`define PROBE_W_ENABLE            regwren_control
`define PROBE_W_DESTINATION       rd_decode
`define PROBE_W_DATA              writeback_data_wb

// ----  Probes  ----

// ----  Top module  ----
`define TOP_MODULE  pd4
// ----  Top module  ----
