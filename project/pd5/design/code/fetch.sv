/*
 * Module: fetch
 *
 * Description: Fetch stage
 *
 * -------- REPLACE THIS FILE WITH THE MEMORY MODULE DEVELOPED IN PD1 -----------
 *
 * Inputs:
 * 1) clk
 * 2) rst signal
 *
 * Outputs:
 * 1) AWIDTH wide program counter pc_o
 * 2) DWIDTH wide instruction output insn_o
 */
/*
 * Module: fetch
 *
 * Description: Fetch stage
 *
 * -------- REPLACE THIS FILE WITH THE MEMORY MODULE DEVELOPED IN PD1 -----------
 *
 * Inputs:
 * 1) clk
 * 2) rst signal
 *
 * Outputs:
 * 1) AWIDTH wide program counter pc_o
 * 2) DWIDTH wide instruction output insn_o
 */

`include "constants.svh"

module fetch #(
    parameter int DWIDTH=32,
    parameter int AWIDTH=32,
    parameter int BASEADDR=32'h01000000
               )(
                 // inputs
                 input logic                 clk,
                 input logic                 rst,
                 input logic                 pcsel_i,
                 input logic [DWIDTH - 1:0]  res_i,
                 // outputs
                 output logic [AWIDTH - 1:0] pc_o,
                 output logic [DWIDTH - 1:0] insn_o
);
    /*
     * Process definitions to be filled by
     * student below...
    */

    //read only memory
    memory #( .AWIDTH(AWIDTH),
              .DWIDTH(DWIDTH),
              .BASE_ADDR(BASEADDR)
              ) Imem
    (.clk(clk),
     .rst(rst),
     .addr_i(pc_o),
     .data_i(0),
     .read_en_i(1),
     .write_en_i(0),
     .memsel_i(2),

     .data_o(insn_o)
     );

    //starts at base
    initial begin
        pc_o = BASEADDR;
        //insn_o = 0;

    end

    //if rst then we restart the pc at base, else we move byte by byte
    always_ff @(posedge clk) begin
        if (rst)begin
            pc_o <= BASEADDR;
        end
        else begin
            pc_o <= pcsel_i == PC_ADD4 ? pc_o + 4 : res_i;
        end
    end

endmodule : fetch
