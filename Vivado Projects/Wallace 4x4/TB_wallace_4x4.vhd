library IEEE;
use IEEE.STD_LOGIC_1164.all;




entity Tb_wallace_4x4 is
--  Port ( );
end Tb_wallace_4x4;

architecture Behavioral of Tb_wallace_4x4 is

component wallace_4x4 is
	port(
		A_in : in std_logic_vector(3 downto 0);
		B_in : in std_logic_vector(3 downto 0);
		-- Output:
		result : out std_logic_vector(7 downto 0)
	);
end component;	

signal A_in : std_logic_vector(3 downto 0);
signal B_in : std_logic_vector(3 downto 0);
signal result : std_logic_vector(7 downto 0);

begin

uut: wallace_4x4 port map(

        A_in => A_in,
        B_in => B_in,
        result => result
        
             

);

-- Test Case:

stim_procc: process
begin

A_in <= "0110";
B_in <= "0100";
wait for 20ns;

A_in <= "1010";
B_in <= "1110";
wait for 20ns;

A_in <= "1000";
B_in <= "1111";
wait for 20ns;

A_in <= "0000";
B_in <= "0111";
wait for 20ns;

A_in <= "1111";
B_in <= "1111";
wait for 20ns;

A_in <= "0001";
B_in <= "0100";
wait for 20ns;

A_in <= "1111";
B_in <= "0001";
wait for 20ns;

A_in <= "1110";
B_in <= "0001";
wait for 20ns;

A_in <= "1111";
B_in <= "0001";
wait for 20ns;

A_in <= "1110";
B_in <= "0011";
wait for 20ns;

A_in <= "1110";
B_in <= "0111";
wait for 20ns;





wait;

end process;

end Behavioral;
