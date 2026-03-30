/*
 * Good practice to define constants and refer to them in the
 * design files. An example of some constants are provided to you
 * as a starting point
 *
 */
`ifndef CONSTANTS_SVH_
`define CONSTANTS_SVH_

parameter logic [31:0] ZERO = 32'd0;

//opcodes
parameter logic [6:0] OP_R     = 7'b0110011;
parameter logic [6:0] OP_IA    = 7'b0010011;
parameter logic [6:0] OP_IL    = 7'b0000011;
parameter logic [6:0] OP_IJ    = 7'b1100111;
parameter logic [6:0] OP_S     = 7'b0100011;
parameter logic [6:0] OP_B     = 7'b1100011;
parameter logic [6:0] OP_U     = 7'b0110111;
parameter logic [6:0] OP_UPC   = 7'b0010111;
parameter logic [6:0] OP_J     = 7'b1101111;


/*
 alu opps needed
 +-----------+----------+---------+
 | opperation| code     | types   |
 +-----------+----------+---------+
 | add       | 0        | r,i     |
 +-----------+----------+---------+
 | sub       | f        | r       |
 +-----------+----------+---------+
 | xor       | 4        | r,i     |
 +-----------+----------+---------+
 | or        | 6        | r,i     |
 +-----------+----------+---------+
 | and       | 7        | r,i     |
 +-----------+----------+---------+
 | sll       | 1        | r,i     |
 +-----------+----------+---------+
 | srl       | 5        | r,i     |
 +-----------+----------+---------+
 | sra       | a        | r,i     |
 +-----------+----------+---------+
 | slt       | 2        | r,i     |
 +-----------+----------+---------+
 | sltu      | 3        | r,i     |
 +-----------+----------+---------+
 */

//wb codes
parameter logic [1:0] WB_PC4   = 2'h0;
parameter logic [1:0] WB_ALU   = 2'h1;
parameter logic [1:0] WB_MEM   = 2'h2;

//pc select codes
parameter logic PC_ADD4  = 1'h0;
parameter logic PC_IMMI  = 1'h1;

parameter logic [3:0] ALU_ADD   = 4'h0;
parameter logic [3:0] ALU_SUB   = 4'hf;
parameter logic [3:0] ALU_XOR   = 4'h4;
parameter logic [3:0] ALU_OR    = 4'h6;
parameter logic [3:0] ALU_AND   = 4'h7;
parameter logic [3:0] ALU_SLL   = 4'h1;
parameter logic [3:0] ALU_SRL   = 4'h5;
parameter logic [3:0] ALU_SRA   = 4'ha;
parameter logic [3:0] ALU_SLT   = 4'h2;
parameter logic [3:0] ALU_SLTU  = 4'h3;



//func 3 and 7 for R type
parameter logic [2:0] FR_ADD   = 3'h0;
parameter logic [2:0] FR_SUB   = 3'h0; // if 0 and inst_i[21:28] == 2 ~FR_ADD
parameter logic [2:0] FR_XOR   = 3'h4;
parameter logic [2:0] FR_OR    = 3'h6;
parameter logic [2:0] FR_AND   = 3'h7;
parameter logic [2:0] FR_SLL   = 3'h1;
parameter logic [2:0] FR_SRL   = 3'h5;
parameter logic [2:0] FR_SRA   = 3'h5; // if 5 and inst_i[21:28] == 2 // ~0101 = 1010 . msb extend
parameter logic [2:0] FR_SLT   = 3'h2;
parameter logic [2:0] FR_SLTU  = 3'h3; // 0 extend

//func 3 for IA type
parameter logic [2:0] FIA_ADD  = 3'h0;
parameter logic [2:0] FIA_XOR  = 3'h4;
parameter logic [2:0] FIA_OR   = 3'h6;
parameter logic [2:0] FIA_AND  = 3'h7;
parameter logic [2:0] FIA_SLL  = 3'h1;
parameter logic [2:0] FIA_SRL  = 3'h5;
parameter logic [2:0] FIA_SRA  = 3'h5; // if f3 is 5 and inst_i[31:28] == 2, (+~inst_i[14:12])
                                       // ~0101 = 1010. msb extend
parameter logic [2:0] FIA_SLT  = 3'h2;
parameter logic [2:0] FIA_SLTU = 3'h3; // 0 extend

//func 3 for IL type
parameter logic [2:0] FIL_LB   = 3'h0;
parameter logic [2:0] FIL_LH   = 3'h1;
parameter logic [2:0] FIL_LW   = 3'h2;
parameter logic [2:0] FIL_LBU  = 3'h4; // 0 extend
parameter logic [2:0] FIL_LHU  = 3'h5; // 0 extend

//func 3 for S type
parameter logic [2:0] FS_SB    = 3'h0;
parameter logic [2:0] FS_SH    = 3'h1;
parameter logic [2:0] FS_SW    = 3'h2;

//func 3 for B type
parameter logic [2:0] FB_BEQ   = 3'h0;
parameter logic [2:0] FB_BNE   = 3'h1;
parameter logic [2:0] FB_BLT   = 3'h4;
parameter logic [2:0] FB_BGE   = 3'h5;
parameter logic [2:0] FB_BLTU  = 3'h6;
parameter logic [2:0] FB_BGEU  = 3'h7;








`endif
