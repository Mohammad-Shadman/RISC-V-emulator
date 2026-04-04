/*
    * Module: pd5
    *
    * Description: Top level module that will contain sub-module instantiations.
    *
    * Inputs:
    * 1) clk
    * 2) reset signal
    */

module pd5 #(
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
    logic               pcsel_control;
    logic               immsel_control;
    logic               regwren_control;
    logic               rs1sel_control;
    logic               rs2sel_control;
    logic               memwren_control;
    logic               memren_control;
    logic [1:0]         wbsel_control;
    logic [3:0]         alusel_control;
    logic               flush_control;
    logic [1:0]         memsel_control;

    //alu output
    logic [DWIDTH-1:0] res_alu;

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

    //pipeline regs
    //if/dc
    logic [DWIDTH-1:0] pc_reg_fd;
    logic [DWIDTH-1:0] insn_reg_fd;
    resetReg pc_reg_fd_rr(.clk(clk), .reset(reset), .data_i(pc_fetch), .data_o(pc_reg_fd));
    resetReg insn_reg_fd_rr(.clk(clk), .reset(reset), .data_i(pc_fetch), .data_o(insn_reg_fd));


    //dc/ex
    //control
    /*what we need from control and to where
        pcsel_control : x
        regwren_control : w
        rs12sel_control : x
        memsel_control : m
        alusel_control : x
        wbsel_control : w
        use flush for reseting pipeline registers

     */
    logic               pcsel_reg_de;
    logic               regwren_reg_de;
    logic               regwren_reg_em;
    logic               regwren_reg_mw;
    logic               rs1sel_reg_de;
    logic               rs2sel_reg_de;
    logic               memren_reg_de;
    logic               memren_reg_em;
    logic               memwren_reg_de;
    logic               memwren_reg_em;
    logic [1:0]         wbsel_reg_de;
    logic [1:0]         wbsel_reg_em;
    logic [1:0]         wbsel_reg_mw;
    logic [3:0]         alusel_reg_de;
    logic [1:0]         memsel_reg_de;
    logic [1:0]         memsel_reg_em;

    //decode
    logic [AWIDTH-1:0]  pc_reg_de;
    logic [AWIDTH-1:0]  pc_reg_em;
    logic [AWIDTH-1:0]  pc_reg_mw;
    logic [DWIDTH-1:0]  insn_reg_de;
    logic [6:0]         opcode_reg_de;
    logic [4:0]         rd_reg_de;
    logic [4:0]         rd_reg_em;
    logic [4:0]         rd_reg_mw;
    logic [4:0]         rs1_reg_de;
    logic [4:0]         rs2_reg_de;
    logic [6:0]         funct7_reg_de;
    logic [2:0]         funct3_reg_de;
    logic [4:0]         shamt_reg_de;
    logic [DWIDTH-1:0]  imm_reg_de;
    logic [DWIDTH-1:0]  insn_reg_em;

    //RF
    logic [DWIDTH-1:0] rs1data_reg_de;
    logic [DWIDTH-1:0] rs2data_reg_de;
    logic [DWIDTH-1:0] rs2data_reg_em;

    resetReg #(.DWIDTH(1))pcsel_reg_de_rr(.clk(clk), .reset(reset | flush_control),
    .data_i(pcsel_control), .data_o(pcsel_reg_de));

    resetReg #(.DWIDTH(1))regwren_reg_de_rr(.clk(clk), .reset(reset | flush_control),
    .data_i(regwren_control), .data_o(regwren_reg_de));

    resetReg #(.DWIDTH(1))regwren_reg_em_rr(.clk(clk), .reset(reset | flush_control),
    .data_i(regwren_reg_de), .data_o(regwren_reg_em));

    resetReg #(.DWIDTH(1))regwren_reg_mw_rr(.clk(clk), .reset(reset | flush_control),
    .data_i(regwren_reg_em), .data_o(regwren_reg_mw));

    resetReg #(.DWIDTH(1))rs1sel_reg_de_rr(.clk(clk), .reset(reset | flush_control),
    .data_i(rs1sel_control), .data_o(rs1sel_reg_de));

    resetReg #(.DWIDTH(1))rs2sel_reg_de_rr(.clk(clk), .reset(reset | flush_control),
    .data_i(rs2sel_control), .data_o(rs2sel_reg_de));

    resetReg #(.DWIDTH(1))memwren_reg_de_rr(.clk(clk), .reset(reset | flush_control),
    .data_i(memwren_control), .data_o(memwren_reg_de));

    resetReg #(.DWIDTH(1))memwren_reg_em_rr(.clk(clk), .reset(reset | flush_control),
    .data_i(memwren_reg_de), .data_o(memwren_reg_em));

    resetReg #(.DWIDTH(1))memren_reg_de_rr(.clk(clk), .reset(reset | flush_control),
    .data_i(memren_control), .data_o(memren_reg_de));

    resetReg #(.DWIDTH(1))memren_reg_em_rr(.clk(clk), .reset(reset | flush_control),
    .data_i(memren_reg_de), .data_o(memren_reg_em));

    resetReg #(.DWIDTH(2))wbsel_reg_de_rr(.clk(clk), .reset(reset | flush_control),
    .data_i(wbsel_control), .data_o(wbsel_reg_de));

    resetReg #(.DWIDTH(2))wbsel_reg_em_rr(.clk(clk), .reset(reset | flush_control),
    .data_i(wbsel_reg_de), .data_o(wbsel_reg_em));

    resetReg #(.DWIDTH(2))wbsel_reg_mw_rr(.clk(clk), .reset(reset | flush_control),
    .data_i(wbsel_reg_em), .data_o(wbsel_reg_mw));

    resetReg #(.DWIDTH(4))alusel_reg_de_rr(.clk(clk), .reset(reset | flush_control),
    .data_i(alusel_control), .data_o(alusel_reg_de));

    resetReg #(.DWIDTH(2))memsel_reg_de_rr(.clk(clk), .reset(reset | flush_control),
    .data_i(memsel_control), .data_o(memsel_reg_de));

    resetReg #(.DWIDTH(2))memsel_reg_em_rr(.clk(clk), .reset(reset | flush_control),
    .data_i(memsel_reg_de), .data_o(memsel_reg_de));

    resetReg #(.DWIDTH(AWIDTH)) pc_reg_de_rr (.clk(clk), .reset(reset | flush_control),
    .data_i(pc_decode), .data_o(pc_reg_de));

    resetReg #(.DWIDTH(AWIDTH)) pc_reg_em_rr (.clk(clk), .reset(reset | flush_control),
    .data_i(pc_reg_de), .data_o(pc_reg_em));

    resetReg #(.DWIDTH(AWIDTH)) pc_reg_mw_rr (.clk(clk), .reset(reset | flush_control),
    .data_i(pc_reg_em), .data_o(pc_reg_mw));

    resetReg #(.DWIDTH(DWIDTH)) insn_reg_de_rr (.clk(clk), .reset(reset | flush_control),
    .data_i(insn_decode), .data_o(insn_reg_de));

    resetReg #(.DWIDTH(7)) opcode_reg_de_rr (.clk(clk), .reset(reset | flush_control),
    .data_i(opcode_decode), .data_o(opcode_reg_de));

    resetReg #(.DWIDTH(5)) rd_reg_de_rr (.clk(clk), .reset(reset | flush_control),
    .data_i(rd_decode), .data_o(rd_reg_de));

    resetReg #(.DWIDTH(5)) rs1_reg_de_rr (.clk(clk), .reset(reset | flush_control),
    .data_i(rs1_decode), .data_o(rs1_reg_de));

    resetReg #(.DWIDTH(5)) rs2_reg_de_rr (.clk(clk), .reset(reset | flush_control),
    .data_i(rs2_decode), .data_o(rs2_reg_de));

    resetReg #(.DWIDTH(7)) funct7_reg_de_rr (.clk(clk), .reset(reset | flush_control),
    .data_i(funct7_decode), .data_o(funct7_reg_de));

    resetReg #(.DWIDTH(3)) funct3_reg_de_rr (.clk(clk), .reset(reset | flush_control),
    .data_i(funct3_decode), .data_o(funct3_reg_de));

    resetReg #(.DWIDTH(5)) shamt_reg_de_rr (.clk(clk), .reset(reset | flush_control),
    .data_i(shamt_decode), .data_o(shamt_reg_de));

    resetReg #(.DWIDTH(DWIDTH)) imm_reg_de_rr (.clk(clk), .reset(reset | flush_control),
    .data_i(imm_decode), .data_o(imm_reg_de));

    resetReg #(.DWIDTH(DWIDTH)) rs1data_reg_de_rr(.clk(clk), .reset(reset | flush_control),
    .data_i(rs1data_rf), .data_o(rs1data_reg_de));

    resetReg #(.DWIDTH(DWIDTH)) rs2data_reg_de_rr(.clk(clk), .reset(reset | flush_control),
    .data_i(rs2data_rf), .data_o(rs2data_reg_de));

    resetReg #(.DWIDTH(DWIDTH)) rs2data_reg_em_rr(.clk(clk), .reset(reset | flush_control),
    .data_i(rs2data_reg_de), .data_o(rs2data_reg_em));


    //ex/mem
    logic [DWIDTH-1:0] res_reg_em;
    // logic              branch_reg_em;

    resetReg #(.DWIDTH(DWIDTH)) res_reg_em_rr(.clk(clk), .reset(reset | flush_control),
    .data_i(res_alu), .data_o(res_reg_em));

    // resetReg #(.DWIDTH(1)) branch_reg_em_rr(.clk(clk), .reset(reset),
    // .data_i(branch_bc), .data_o(branch_reg_em));

    //mem/wb
    logic [DWIDTH-1:0] writeback_data_reg_mw;

    resetReg #(.DWIDTH(DWIDTH)) wb_data_reg_em_rr(.clk(clk), .reset(reset | flush_control),
    .data_i(writeback_data_wb), .data_o(writeback_data_reg_mw));

    //logic PCsel;
    always_comb begin
        Asel  = rs1sel_reg_de ? rs1data_reg_de : pc_reg_de;
        Bsel  = rs2sel_reg_de ? rs2data_reg_de : imm_reg_de;
    end


    branch_control #(.DWIDTH(DWIDTH)) bc (
        .opcode_i(opcode_decode),
        .funct3_i(funct3_decode),
        .rs1_i(rs1data_reg_de),
        .rs2_i(rs2data_reg_de),

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
        .insn_i(insn_reg_fd),
        .pc_i(pc_reg_fd),
        .oldRd_de(rd_reg_de),
        .oldRd_em(rd_reg_em),

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
        .regwren_o(regwren_control),
        .rs1sel_o(rs1sel_control),
        .rs2sel_o(rs2sel_control),
        .memsel_o(memsel_control),
        .immsel_o(immsel_control),
        .memren_o(memren_control),
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
        .rd_i(rd_reg_mw),
        .datawb_i(writeback_data_reg_mw),
        .regwren_i(regwren_reg_mw),

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
        .addr_i(res_reg_em),
        .data_i(rs2data_reg_em),
        .read_en_i(memren_reg_em),
        .write_en_i(memwren_reg_em),
        .memsel_i(memsel_reg_em), // for half and byte loads/stores load

        .data_o(data_mem)
    );


    writeback #(.DWIDTH(DWIDTH), .AWIDTH(AWIDTH)) wb(
        .pc_i(pc_reg_em),
        .alu_res_i(res_reg_em),
        .memory_data_i(data_mem),
        .wbsel_i(wbsel_reg_em),
        .brtaken_i(branch_bc),
        .branched_alu_res(res_alu),

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


endmodule : pd5
