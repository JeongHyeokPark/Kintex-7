-------------------------------------------------------------------------------
-- Copyright (c) 2022 Xilinx, Inc.
-- All Rights Reserved
-------------------------------------------------------------------------------
--   ____  ____
--  /   /\/   /
-- /___/  \  /    Vendor     : Xilinx
-- \   \   \/     Version    : 14.3
--  \   \         Application: XILINX CORE Generator
--  /   /         Filename   : tel_icon.vhd
-- /___/   /\     Timestamp  : 월  4월 18 17:53:31 KST 2022
-- \   \  /  \
--  \___\/\___\
--
-- Design Name: VHDL Synthesis Wrapper
-------------------------------------------------------------------------------
-- This wrapper is used to integrate with Project Navigator and PlanAhead

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
ENTITY tel_icon IS
  port (
    CONTROL0: inout std_logic_vector(35 downto 0));
END tel_icon;

ARCHITECTURE tel_icon_a OF tel_icon IS
BEGIN

END tel_icon_a;
