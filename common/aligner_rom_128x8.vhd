library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
library UNISIM;
use UNISIM.VComponents.all;

entity aligner_rom_128x8 is port(
	a:   in  std_logic_vector(6 downto 0);
	spo: out std_logic_vector(7 downto 0)
); end aligner_rom_128x8;

architecture Behavioral of aligner_rom_128x8 is

begin
   rom128x1_aligner_rom_0 : ROM128X1
   generic map (INIT => X"0000000000FF000000FF0000000000FF")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      A5 => a(5),
      A6 => a(6),
      O => spo(0)
   );

   rom128x1_aligner_rom_1 : ROM128X1
   generic map (INIT => X"00000000000001FF000001FF01FF0000")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      A5 => a(5),
      A6 => a(6),
      O => spo(1)
   );

   rom128x1_aligner_rom_2 : ROM128X1
   generic map (INIT => X"0000000000FF00FF00FF00FF00FF00FF")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      A5 => a(5),
      A6 => a(6),
      O => spo(2)
   );

   rom128x1_aligner_rom_3 : ROM128X1
   generic map (INIT => X"0000000000FF010000FF0100010000FF")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      A5 => a(5),
      A6 => a(6),
      O => spo(3)
   );

   rom128x1_aligner_rom_4 : ROM128X1
   generic map (INIT => X"00000000000000000000000000000000")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      A5 => a(5),
      A6 => a(6),
      O => spo(4)
   );

   rom128x1_aligner_rom_5 : ROM128X1
   generic map (INIT => X"0000000000FF00FF00FF00FF00FF00FF")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      A5 => a(5),
      A6 => a(6),
      O => spo(5)
   );

   rom128x1_aligner_rom_6 : ROM128X1
   generic map (INIT => X"00000000000000000000000000000000")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      A5 => a(5),
      A6 => a(6),
      O => spo(6)
   );

   rom128x1_aligner_rom_7 : ROM128X1
   generic map (INIT => X"00000000000000000000000000000000")
   port map (
      A0 => a(0),
      A1 => a(1),
      A2 => a(2),
      A3 => a(3),
      A4 => a(4),
      A5 => a(5),
      A6 => a(6),
      O => spo(7)
   );


end Behavioral;

