library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
library UNISIM;
use UNISIM.VComponents.all;

entity micro_wire_rom is port(
	a:   in  std_logic_vector(4 downto 0);
	spo: out std_logic_vector(31 downto 0)
); end micro_wire_rom;

architecture Behavioral of micro_wire_rom is

begin

   rom32x1_micro_wire_rom_0 : ROM32X1
   generic map (INIT => X"02EA9754")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(0)
   );

   rom32x1_micro_wire_rom_1 : ROM32X1
   generic map (INIT => X"03B31D98")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(1)
   );

   rom32x1_micro_wire_rom_2 : ROM32X1
   generic map (INIT => X"033C19E0")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(2)
   );

   rom32x1_micro_wire_rom_3 : ROM32X1
   generic map (INIT => X"03C01E00")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(3)
   );

   rom32x1_micro_wire_rom_4 : ROM32X1
   generic map (INIT => X"00000000")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(4)
   );

   rom32x1_micro_wire_rom_5 : ROM32X1
   generic map (INIT => X"00000000")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(5)
   );

   rom32x1_micro_wire_rom_6 : ROM32X1
   generic map (INIT => X"00000000")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(6)
   );

   rom32x1_micro_wire_rom_7 : ROM32X1
   generic map (INIT => X"00000000")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(7)
   );

   rom32x1_micro_wire_rom_8 : ROM32X1
   generic map (INIT => X"013FE9FF")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(8)
   );

   rom32x1_micro_wire_rom_9 : ROM32X1
   generic map (INIT => X"00600200")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(9)
   );

   rom32x1_micro_wire_rom_10 : ROM32X1
   generic map (INIT => X"02201000")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(10)
   );

   rom32x1_micro_wire_rom_11 : ROM32X1
   generic map (INIT => X"00400200")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(11)
   );

   rom32x1_micro_wire_rom_12 : ROM32X1
   generic map (INIT => X"02000000")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(12)
   );

   rom32x1_micro_wire_rom_13 : ROM32X1
   generic map (INIT => X"00400200")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(13)
   );

   rom32x1_micro_wire_rom_14 : ROM32X1
   generic map (INIT => X"00000000")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(14)
   );

   rom32x1_micro_wire_rom_15 : ROM32X1
   generic map (INIT => X"00800400")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(15)
   );

   rom32x1_micro_wire_rom_16 : ROM32X1
   generic map (INIT => X"003FE1FF")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(16)
   );

   rom32x1_micro_wire_rom_17 : ROM32X1
   generic map (INIT => X"00FFE600")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(17)
   );

   rom32x1_micro_wire_rom_18 : ROM32X1
   generic map (INIT => X"00000000")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(18)
   );

   rom32x1_micro_wire_rom_19 : ROM32X1
   generic map (INIT => X"00000000")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(19)
   );

   rom32x1_micro_wire_rom_20 : ROM32X1
   generic map (INIT => X"01000800")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(20)
   );

   rom32x1_micro_wire_rom_21 : ROM32X1
   generic map (INIT => X"01000800")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(21)
   );

   rom32x1_micro_wire_rom_22 : ROM32X1
   generic map (INIT => X"00000000")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(22)
   );

   rom32x1_micro_wire_rom_23 : ROM32X1
   generic map (INIT => X"00800400")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(23)
   );

   rom32x1_micro_wire_rom_24 : ROM32X1
   generic map (INIT => X"01000800")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(24)
   );

   rom32x1_micro_wire_rom_25 : ROM32X1
   generic map (INIT => X"00000000")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(25)
   );

   rom32x1_micro_wire_rom_26 : ROM32X1
   generic map (INIT => X"00000000")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(26)
   );

   rom32x1_micro_wire_rom_27 : ROM32X1
   generic map (INIT => X"01000800")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(27)
   );

   rom32x1_micro_wire_rom_28 : ROM32X1
   generic map (INIT => X"00000000")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(28)
   );

   rom32x1_micro_wire_rom_29 : ROM32X1
   generic map (INIT => X"01400A00")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(29)
   );

   rom32x1_micro_wire_rom_30 : ROM32X1
   generic map (INIT => X"02001000")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(30)
   );

   rom32x1_micro_wire_rom_31 : ROM32X1
   generic map (INIT => X"00402201")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      O => spo(31)
   );


end Behavioral;

