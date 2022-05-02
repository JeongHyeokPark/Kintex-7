-------------------------------------------------------------------------------
-- Copyright (c) 2022 Xilinx, Inc.
-- All Rights Reserved
-------------------------------------------------------------------------------
--   ____  ____
--  /   /\/   /
-- /___/  \  /    Vendor     : Xilinx
-- \   \   \/     Version    : 14.3
--  \   \         Application: XILINX CORE Generator
--  /   /         Filename   : tel_ila_trig64.vhd
-- /___/   /\     Timestamp  : 월  4월 18 17:56:19 KST 2022
-- \   \  /  \
--  \___\/\___\
--
-- Design Name: VHDL Synthesis Wrapper
-------------------------------------------------------------------------------
-- This wrapper is used to integrate with Project Navigator and PlanAhead

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
ENTITY tel_ila_trig64 IS
  port (
    CONTROL: inout std_logic_vector(35 downto 0);
    CLK: in std_logic;
    TRIG0: in std_logic_vector(63 downto 0));
END tel_ila_trig64;

ARCHITECTURE tel_ila_trig64_a OF tel_ila_trig64 IS
BEGIN

END tel_ila_trig64_a;
