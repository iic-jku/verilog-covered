module main1;

wire    a;
reg     b, c;

dut_and dut( a, b, c );

initial begin
	$dumpfile( "merge1a.vcd" );
	$dumpvars( 0, main1 );
	b = 1'b0;
	c = 1'b0;
	#5;
	$finish;
end

endmodule
