gui_open_window Wave
gui_sg_create DcmTo200_group
gui_list_add_group -id Wave.1 {DcmTo200_group}
gui_sg_addsignal -group DcmTo200_group {DcmTo200_tb.test_phase}
gui_set_radix -radix {ascii} -signals {DcmTo200_tb.test_phase}
gui_sg_addsignal -group DcmTo200_group {{Input_clocks}} -divider
gui_sg_addsignal -group DcmTo200_group {DcmTo200_tb.CLK_IN1}
gui_sg_addsignal -group DcmTo200_group {{Output_clocks}} -divider
gui_sg_addsignal -group DcmTo200_group {DcmTo200_tb.dut.clk}
gui_list_expand -id Wave.1 DcmTo200_tb.dut.clk
gui_sg_addsignal -group DcmTo200_group {{Status_control}} -divider
gui_sg_addsignal -group DcmTo200_group {DcmTo200_tb.RESET}
gui_sg_addsignal -group DcmTo200_group {DcmTo200_tb.LOCKED}
gui_sg_addsignal -group DcmTo200_group {{Counters}} -divider
gui_sg_addsignal -group DcmTo200_group {DcmTo200_tb.COUNT}
gui_sg_addsignal -group DcmTo200_group {DcmTo200_tb.dut.counter}
gui_list_expand -id Wave.1 DcmTo200_tb.dut.counter
gui_zoom -window Wave.1 -full
