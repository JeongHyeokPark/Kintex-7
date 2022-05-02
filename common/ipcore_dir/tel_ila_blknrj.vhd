-------------------------------------------------------------------------------
-- Copyright (c) 2022 Xilinx, Inc.
-- All Rights Reserved
-------------------------------------------------------------------------------
--   ____  ____
--  /   /\/   /
-- /___/  \  /    Vendor     : Xilinx
-- \   \   \/     Version    : 14.3
--  \   \         Application: XILINX CORE Generator
--  /   /         Filename   : tel_ila_blknrj.vhd
-- /___/   /\     Timestamp  : 월  4월 18 18:08:22 KST 2022
-- \   \  /  \
--  \___\/\___\
--
-- Design Name: VHDL Synthesis Wrapper
-------------------------------------------------------------------------------
-- This wrapper is used to integrate with Project Navigator and PlanAhead

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
ENTITY tel_ila_blknrj IS
  port (
    CONTROL: inout std_logic_vector(35 downto 0);
    CLK: in std_logic;
    TRIG0: in std_logic_vector(79 downto 0));
END tel_ila_blknrj;

ARCHITECTURE tel_ila_blknrj_a OF tel_ila_blknrj IS
BEGIN

END tel_ila_blknrj_a;
