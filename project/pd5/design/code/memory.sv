/*
 * -------- REPLACE THIS FILE WITH THE MEMORY MODULE DEVELOPED IN PD1 -----------
 * Module: memory
 *
 * Description: Byte-addressable memory implementation. Supports both read and write.
 *
 * Inputs:
 * 1) clk
 * 2) rst signal
 * 3) AWIDTH address addr_i
 * 4) DWIDTH data to write data_i
 * 5) read enable signal read_en_i
 * 6) write enable signal write_en_i
 *
 * Outputs:
 * 1) DWIDTH data output data_o
 * 2) data out valid signal data_vld_o
 */
/*
 * -------- REPLACE THIS FILE WITH THE MEMORY MODULE DEVELOPED IN PD1 -----------
 * Module: memory
 *
 * Description: Byte-addressable memory implementation. Supports both read and write.
 *
 * Inputs:
 * 1) clk
 * 2) rst signal
 * 3) AWIDTH address addr_i
 * 4) DWIDTH data to write data_i
 * 5) read enable signal read_en_i
 * 6) write enable signal write_en_i
 *
 * Outputs:
 * 1) DWIDTH data output data_o
 * 2) data out valid signal data_vld_o
 */
module memory #(
                // parameters
                parameter int AWIDTH = 32,
                parameter int DWIDTH = 32,
                parameter logic [31:0] BASE_ADDR = 32'h01000000
                ) (
                   // inputs
                   input logic               clk,
                   input logic               rst,
                   input logic [AWIDTH-1:0]  addr_i = BASE_ADDR,
                   input logic [DWIDTH-1:0]  data_i,
                   input logic               write_en_i,
                   input logic [1:0]         memsel_i,
                   // outputs
                   output logic [DWIDTH-1:0] data_o
                   );

    logic [DWIDTH-1:0] temp_memory [0:`MEM_DEPTH-1];
    // Byte-addressable memory
    logic [7:0]        main_memory [0:`MEM_DEPTH-1];  // Byte-addressable memory
    //logic   [AWIDTH-1:0] address;



    initial begin
        $readmemh(`MEM_PATH, temp_memory);
        // Load data from temp_memory into main_memory
        for (int i = 0; i < `LINE_COUNT; i++) begin
            main_memory[4*i]     = temp_memory[i][7:0];
            main_memory[4*i + 1] = temp_memory[i][15:8];
            main_memory[4*i + 2] = temp_memory[i][23:16];
            main_memory[4*i + 3] = temp_memory[i][31:24];
        end
        $display("IMEMORY: Loaded %0d 32-bit words from %s", `LINE_COUNT, `MEM_PATH);
    end

    /*
     * Process definitions to be filled by
     * student below....
     *
     */
    //checks if the addrs is valid, if not, set to 0
    reg [DWIDTH-1:0] data_fetch;
    always_ff @(posedge clk) begin
        //if the addr is invalid, Set to zero
        //4 byte aligns the address, later will need to allow indexing upto the next byte or take a set byte size to return?
        //address = address - (address % 4);

        //for now leave empty
        if(rst && 0)begin
            //for (int i = 0; i < `LINE_COUNT; i++) begin
                // main_memory[i]     = 0;
                // main_memory[i + 1] = 0;
                // main_memory[i + 2] = 0;
                // main_memory[i + 3] = 0;
                        $readmemh(`MEM_PATH, temp_memory);
                // Load data from temp_memory into main_memory
                for (int i = 0; i < `LINE_COUNT; i++) begin
                    main_memory[4*i]     = temp_memory[i][7:0];
                    main_memory[4*i + 1] = temp_memory[i][15:8];
                    main_memory[4*i + 2] = temp_memory[i][23:16];
                    main_memory[4*i + 3] = temp_memory[i][31:24];
                end


            //end
        end

        //writes the data's width into the memory slot
        else if(write_en_i)begin
            for(int j=0; j < (DWIDTH)/8; j++)
                // j<((DWIDTH)/8*(memsel_i == 2) +
                // ((DWIDTH)/8/2)*(memsel_i == 1) +
                // (DWIDTH)/8/4*(memsel_i == 0));j++)
                begin
                main_memory[addr_i - BASE_ADDR +j] <= data_i[j*8+:8];
            end
            // main_memory[address]     = data_i[0*8+7:0*8];
            // main_memory[address + 1] = data_i[1*8+7:1*8];
            // main_memory[address + 2] = data_i[2*8+7:2*8];
            // main_memory[address + 3] = data_i[3*8+7:3*8];
        end
    end

    always_comb begin
        for(int i=0; i<(DWIDTH)/8; i++)
            // j<((DWIDTH)/8*(memsel_i == 2) +
            // ((DWIDTH)/8/2)*(memsel_i == 1) +
            // (DWIDTH)/8/4*(memsel_i == 0));
            // j++)
            begin
                data_fetch[i*8+:8] = main_memory[addr_i - BASE_ADDR + i];
            end
        data_o = data_fetch;

    end

endmodule : memory
