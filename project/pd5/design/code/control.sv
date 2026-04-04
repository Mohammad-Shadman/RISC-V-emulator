/*
 * Module: control
 *
 * Description: This module sets the control bits (control path) based on the decoded
 * instruction. Note that this is part of the decode stage but housed in a separate
 * module for better readability, debug and design purposes.
 *
 * -------- REPLACE THIS FILE WITH THE MEMORY MODULE DEVELOPED IN PD2 -----------
 */
/*
 * Module: control
 *
 * Description: This module sets the control bits (control path) based on the decoded
 * instruction. Note that this is part of the decode stage but housed in a separate
 * module for better readability, debug and design purposes.
 *
 * Inputs:
 * 1) DWIDTH instruction ins_i
 * 2) 7-bit opcode opcode_i
 * 3) 7-bit funct7 funct7_i
 * 4) 3-bit funct3 funct3_i
 *
 * Outputs:
 * 1) 1-bit PC select pcsel_o
 * 2) 1-bit Immediate select immsel_o
 * 3) 1-bit register write en regwren_o
 * 4) 1-bit rs1 select rs1sel_o
 * 5) 1-bit rs2 select rs2sel_o
 * 6) k-bit ALU select alusel_o
 * 7) 1-bit memory read en memren_o
 * 8) 1-bit memory write en memwren_o
 * 9) 2-bit writeback sel wbsel_o
 */

`include "constants.svh"

module control #(
    parameter int DWIDTH=32
)(
    // inputs
    input logic [DWIDTH-1:0] insn_i,
    input logic [6:0]        opcode_i,
    input logic [6:0]        funct7_i,
    input logic [2:0]        funct3_i,
    //input logic              brlt_i, //bool out of BC
    //input logic              brgt_i, //bool out of BC
    input logic              brtaken_i, //bool out of BC

    // outputs
    //output logic             brun_o,
    output logic             pcsel_o,
    output logic             immsel_o,
    output logic             regwren_o,
    output logic             rs1sel_o,
    output logic             rs2sel_o,
    output logic             memren_o,
    output logic             memwren_o,
    output logic [1:0]       wbsel_o,
    output logic [3:0]       alusel_o,
    output logic             flush_o,
    output logic [1:0]       memsel_o
);

    /*
        * Process definitions to be filled by
        * student below...
        */
    logic cond;
    logic [3:0] alu_op;
    logic [2:0] temp;

    always_comb begin
        //for sub and sra opps
        temp = funct3_i%4;
        memsel_o = temp[1:0];

        //alu_op[2:0] = funct3_i;
        if ((funct3_i == 0 || funct3_i == 5) &&  funct7_i == 7'h20 &&
            (opcode_i == OP_R || opcode_i == OP_IA)) begin
            alu_op[2:0] = ~funct3_i;
            alu_op[3] = 1;
        end
        else begin
            alu_op[2:0] = funct3_i;
            alu_op[3] = 0;
        end
        //brun_o  = 0;
        flush_o = 0;
//        cond = 0;

        //based on opcode, we set the different controls, some values can be "dont cares" as they
        // will not be used, but verilator does not support the value x or z so we emplicetly use 0
        case(opcode_i)
            OP_R : begin
                pcsel_o   = PC_ADD4;
                immsel_o  = 0;
                regwren_o = 1;
                rs1sel_o  = 1;
                rs2sel_o  = 1;
                memren_o  = 0;
                memwren_o = 0;
                wbsel_o   = WB_ALU;
                alusel_o  = alu_op;
            end

            OP_IA : begin
                pcsel_o   = PC_ADD4;
                immsel_o  = 1;
                regwren_o = 1;
                rs1sel_o  = 1;
                rs2sel_o  = 0;
                memren_o  = 0;
                memwren_o = 0;
                wbsel_o   = WB_ALU;
                alusel_o  = alu_op;
            end

            OP_IL: begin
                pcsel_o   = PC_ADD4;
                immsel_o  = 1;
                regwren_o = 1;
                rs1sel_o  = 1;
                rs2sel_o  = 0;
                memren_o  = 1;
                memwren_o = 0;
                wbsel_o   = WB_MEM;
                alusel_o  = ALU_ADD;
            end

            OP_IJ: begin
                pcsel_o   = PC_IMMI;
                immsel_o  = 1;
                regwren_o = 1;
                rs1sel_o  = 1;
                rs2sel_o  = 0;
                memren_o  = 0;
                memwren_o = 0;
                wbsel_o   = WB_PC4;
                alusel_o  = ALU_ADD;
                flush_o   = 1;
            end

            OP_S: begin
                pcsel_o   = PC_ADD4;
                immsel_o  = 1;
                regwren_o = 0;
                rs1sel_o  = 1;
                rs2sel_o  = 1;
                memren_o  = 0;
                memwren_o = 1;
                wbsel_o   = WB_ALU;//dont care
                alusel_o  = ALU_ADD;
            end

            OP_B: begin
                pcsel_o   = PC_IMMI && brtaken_i;
                immsel_o  = 1;
                regwren_o = 0;
                rs1sel_o  = 0;
                rs2sel_o  = 0;
                memren_o  = 0;
                memwren_o = 0;
                wbsel_o   = WB_ALU;//dont care
                alusel_o  = ALU_ADD;
                flush_o   = brtaken_i; // default dont take branch
            end

            OP_U: begin
                pcsel_o   = PC_ADD4;
                immsel_o  = 1;
                regwren_o = 1;
                rs1sel_o  = 0;
                rs2sel_o  = 0;
                memren_o  = 1;
                memwren_o = 0;
                wbsel_o   = WB_ALU;
                alusel_o  = ALU_ADD;
            end

            OP_UPC: begin
                pcsel_o   = PC_ADD4;
                immsel_o  = 1;
                regwren_o = 1;
                rs1sel_o  = 0;
                rs2sel_o  = 0;
                memren_o  = 1;
                memwren_o = 0;
                wbsel_o   = WB_ALU;
                alusel_o  = ALU_ADD;
                flush_o   = 0;
            end

            OP_J: begin
                pcsel_o   = PC_IMMI;
                immsel_o  = 1;
                regwren_o = 1;
                rs1sel_o  = 0;
                rs2sel_o  = 0;
                memren_o  = 1;
                memwren_o = 0;
                wbsel_o   = WB_PC4;
                alusel_o  = ALU_ADD;
                flush_o   = 1;
            end
            //nop opcode 0x00
            default : begin
                pcsel_o   = PC_ADD4;
                immsel_o  = 0;
                regwren_o = 0;
                rs1sel_o  = 0;
                rs2sel_o  = 0;
                memren_o  = 0;
                memwren_o = 0;
                alusel_o  = ALU_NULL;
                wbsel_o   = 0;
                flush_o   = 1;
            end

        endcase
    end


endmodule : control
