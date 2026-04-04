module resetReg#(
    parameter int DWIDTH = 32)(
    input logic  clk,
    input logic  reset,
    input logic  [DWIDTH-1:0] data_i,
    output logic [DWIDTH-1:0] data_o
);

    always_ff @(posedge clk) begin
        if(reset) begin
            data_o <= 0;
        end
        else data_o <= data_i;
    end


endmodule: resetReg
