/*
 * Module: pd2
 *
 * Description: Top level module that will contain sub-module instantiations.
 *
 * Inputs:
 * 1) clk
 * 2) reset signal
 */

module pd2 #(
    parameter int AWIDTH = 32,
    parameter int DWIDTH = 32)(
    input logic clk,
    input logic reset
);

    logic                brun_oC;
    logic                pcsel_oC;
    logic                immsel_oC;
    logic                regwren_oC;
    logic                rs1sel_oC;
    logic                rs2sel_oC;
    logic                memren_oC;
    logic                memwren_oC;
    logic [1:0]          wbsel_oC;
    logic [3:0]          alusel_oC;
    logic                flush_oC;

    logic [DWIDTH - 1:0] insn_i;
    logic [DWIDTH - 1:0] pc_i;
    logic [AWIDTH-1:0]   pc_oD;
    logic [DWIDTH-1:0]   insn_oD;
    logic [6:0]          opcode_oD;
    logic [4:0]          rd_oD;
    logic [4:0]          rs1_oD;
    logic [4:0]          rs2_oD;
    logic [6:0]          funct7_oD;
    logic [2:0]          funct3_oD;
    logic [4:0]          shamt_oD;
    logic [DWIDTH-1:0]   imm_oD;

    logic [AWIDTH - 1:0] pc_oF;
    logic [DWIDTH - 1:0] insn_oF;

    /* verilator lint_off PINMISSING */
    fetch #(.DWIDTH(DWIDTH), .AWIDTH(AWIDTH))Fetch(
        .clk(clk), .rst(reset), .pc_o(pc_oF), .insn_o(insn_oF));

    assign pc_i   = pc_oF;
    assign insn_i = insn_oF;

    /* verilator lint_off PINMISSING */
    control #(.DWIDTH(DWIDTH)) Control(
        .insn_i(insn_oF), .opcode_i(opcode_oD), .funct3_i(funct3_oD), .funct7_i(funct7_oD),
        .pcsel_o(pcsel_oC),  .immsel_o(immsel_oC), .regwren_o(regwren_oC),.rs1sel_o(rs1sel_oC),
        .rs2sel_o(rs2sel_oC), .memren_o(memren_oC), .memwren_o(memwren_oC),.wbsel_o(wbsel_oC),
        .alusel_o(alusel_oC), .flush_o(flush_oC));
    /*
        * Instantiate other submodules and
        * probes. To be filled by student...
        *
    */

    /* verilator lint_off PINMISSING */
    decode #(.DWIDTH(DWIDTH), .AWIDTH(AWIDTH)) Decode(
        .clk(clk), .rst(reset),
        .insn_i(insn_oF), .pc_i(pc_oF), .pc_o(pc_oD), .insn_o(insn_oD),
        .opcode_o(opcode_oD), .rd_o(rd_oD), .rs1_o(rs1_oD), .rs2_o(rs2_oD),
        .funct7_o(funct7_oD), .funct3_o(funct3_oD), .shamt_o(shamt_oD), .imm_o(imm_oD));

endmodule : pd2
