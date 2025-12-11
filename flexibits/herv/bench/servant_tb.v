`default_nettype none
`timescale 1ms/1us
module servant_tb;

   parameter memfile = "";
   parameter memsize = 2097152;
   // parameter memsize = 8192;
   parameter with_csr = 1;

   localparam baud_rate = 57600 * 5;

   reg wb_clk = 1'b0;
   reg wb_rst = 1'b1;

   wire q;

   always  #31 wb_clk <= !wb_clk;
   initial #62 wb_rst <= 1'b0;

//   vlog_tb_utils vtu();

   reg [1023:0] vcd_file;
   initial begin
     if ($value$plusargs("vcd=%s", vcd_file)) begin
   	$dumpfile(vcd_file);
	$dumpvars(1, servant_tb);
     end
   end

   uart_decoder #(baud_rate) uart_decoder (q);

   servant_sim
     #(.memfile  (memfile),
       .memsize  (memsize),
       .with_csr (with_csr))
   dut
     (.wb_clk (wb_clk),
      .wb_rst (wb_rst),
      .pc_adr (),
      .pc_vld (),
      .q      (q));

endmodule
