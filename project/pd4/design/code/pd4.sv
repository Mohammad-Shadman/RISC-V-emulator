/*
    * Module: pd4
    *
    * Description: Top level module that will contain sub-module instantiations.
    *
    * Inputs:
    * 1) clk
    * 2) reset signal
    */

module pd4 #(
    parameter int AWIDTH = 32,
    parameter int DWIDTH = 32)(
    input logic clk,
    input logic reset
    );

    /*
        * Instantiate other submodules and
        * probes. To be filled by student...
        *
        */

    //fetch outputs
    logic [AWIDTH-1:0] insn_fetch;
    logic [DWIDTH-1:0] pc_fetch;

    //decode outputs
    logic  [AWIDTH-1:0] pc_decode;
    logic  [DWIDTH-1:0] insn_decode;
    logic  [6:0]        opcode_decode;
    logic  [4:0]        rd_decode;
    logic  [4:0]        rs1_decode;
    logic  [4:0]        rs2_decode;
    logic  [6:0]        funct7_decode;
    logic  [2:0]        funct3_decode;
    logic  [4:0]        shamt_decode;
    logic  [DWIDTH-1:0] imm_decode;

    //control outputs
    logic               brun_control;
    logic               pcsel_control;
    logic               immsel_control;
    logic               regwren_control;
    logic               rs1sel_control;
    logic               rs2sel_control;
    logic               memren_control;
    logic               memwren_control;
    logic [1:0]         wbsel_control;
    logic [3:0]         alusel_control;
    logic               flush_control;
    logic [1:0]         memsel_control;

    //alu output
    logic [DWIDTH-1:0] datawb_rf;
    logic [DWIDTH-1:0] res_alu;
    logic              brtaken_alu;

    //rf outputs
    logic [DWIDTH-1:0] rs1data_rf;
    logic [DWIDTH-1:0] rs2data_rf;

    //bc output
    logic              branch_bc;

    //wb output
    logic [DWIDTH-1:0] writeback_data_wb;
    logic [AWIDTH-1:0] next_pc_wb       ;

    //muxes
    logic [DWIDTH-1:0] Asel;
    logic [DWIDTH-1:0] Bsel;

    //memory output
    logic [DWIDTH-1:0] data_mem;

    //logic PCsel;
    always_comb begin
        Asel  = rs1sel_control ? rs1data_rf : pc_decode;
        Bsel  = rs2sel_control && opcode_decode != OP_S ? rs2data_rf : imm_decode;
        //PCsel = pcsel_control && brtaken_alu;
    end


    branch_control #(.DWIDTH(DWIDTH)) bc (
        .opcode_i(opcode_decode),
        .funct3_i(funct3_decode),
        .rs1_i(rs1data_rf),
        .rs2_i(rs2data_rf),

        .branch_o(branch_bc)
    );
    fetch #(.DWIDTH(DWIDTH), .AWIDTH(AWIDTH)) fs(
        .clk(clk),
        .rst(reset),
        .res_i(res_alu),
        .pcsel_i(pcsel_control),

        .insn_o(insn_fetch),
        .pc_o(pc_fetch));

    decode #(.DWIDTH(DWIDTH), .AWIDTH(AWIDTH)) decode (
        .clk(clk),
        .rst(reset),
        .insn_i(insn_fetch),
        .pc_i(pc_fetch),

        .pc_o(pc_decode),
        .insn_o(insn_decode),
        .opcode_o(opcode_decode),
        .rd_o(rd_decode),
        .rs1_o(rs1_decode),
        .rs2_o(rs2_decode),
        .funct7_o(funct7_decode),
        .funct3_o(funct3_decode),
        .shamt_o(shamt_decode),
        .imm_o(imm_decode)
    );

    control #(.DWIDTH(DWIDTH)) ctl(
        .insn_i(insn_decode),
        .opcode_i(opcode_decode),
        .funct7_i(funct7_decode),
        .funct3_i(funct3_decode),
        .brtaken_i(branch_bc),

        .pcsel_o(pcsel_control),
        .immsel_o(immsel_control),
        .regwren_o(regwren_control),
        .rs1sel_o(rs1sel_control),
        .rs2sel_o(rs2sel_control),
        .memren_o(memren_control),
        .memsel_o(memsel_control),
        .memwren_o(memwren_control),
        .wbsel_o(wbsel_control),
        .alusel_o(alusel_control),
        .flush_o(flush_control)
    );

    register_file #(.DWIDTH(DWIDTH)) RF (
        .clk(clk),
        .rst(reset),
        .rs1_i(rs1_decode),
        .rs2_i(rs2_decode),
        .rd_i(rd_decode),
        .datawb_i(writeback_data_wb),
        .regwren_i(regwren_control),

        .rs1data_o(rs1data_rf),
        .rs2data_o(rs2data_rf)
    );

    alu #(.DWIDTH(DWIDTH),.AWIDTH(AWIDTH)) ex(
        .aluSel_i(alusel_control),
        .opcode_i(opcode_decode),
        .pc_i(pc_decode),
        .rs1_i(Asel),
        .rs2_i(Bsel),

        .res_o(res_alu)
    );

    memory #(.DWIDTH(DWIDTH), .AWIDTH(AWIDTH)) dmem(
        .clk(clk),
        .rst(reset),
        .addr_i(res_alu),
        .data_i(rs2data_rf),
        .read_en_i(memren_control),
        .write_en_i(memwren_control),
        .memsel_i(memsel_control), // for half and byte loads/stores load

        .data_o(data_mem)
    );


    writeback #(.DWIDTH(DWIDTH), .AWIDTH(AWIDTH)) wb(
        .pc_i(pc_decode),
        .alu_res_i(res_alu),
        .memory_data_i(data_mem),
        .wbsel_i(wbsel_control),
        .brtaken_i(branch_bc),

        .writeback_data_o(writeback_data_wb),
        .next_pc_o(next_pc_wb)
    );

    // program termination logic
    reg is_program = 0;
    always_ff @(posedge clk) begin
        if (insn_fetch == 32'h00000073) $finish;  // directly terminate if see ecall
        if (insn_fetch == 32'h00008067) is_program = 1;  // if see ret instruction,it is simple program test
        // [TODO] Change register_file_0.registers[2] to the appropriate x2 register based on your module instantiations...
        if (is_program && (RF.RF[2] == 32'h01000000 + `MEM_DEPTH)) $finish;
    end

endmodule : pd4
