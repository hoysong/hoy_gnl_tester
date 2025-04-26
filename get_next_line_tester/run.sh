clear
#
#
echo
USER=`whoami`

echo -e "\e[32m.__                       __                   __\e[0m"
echo -e "\e[32m|  |__   ____ ___.__.   _/  |_  ____   _______/  |_  ___________\e[0m"
echo -e "\e[32m|  |  \ /  _ <   |  |   \   __\/ __ \ /  ___/\   __\/ __ \_  __ \ \e[0m"
echo -e "\e[32m|   Y  (  <_> )___  |    |  | \  ___/ \___ \  |  | \  ___/|  | \/\e[0m"
echo -e "\e[32m|___|  /\____// ____|____|__|  \___  >____  > |__|  \___  >__|\e[0m"
echo -en "\e[32m     \/       \/   /_____/         \/     \/            \/\e[0m"
echo -e "\e[47;34mGNL_TESTER\e[0m"
echo
echo "hi $USER wait for compile your project"

bash launch.sh > result.txt
clear
cat result.txt

echo -e "\e[47;34m\e[1m"
echo -e "\e[32mNOMINETTE\e[0m"
norminette ../get_next_line.c ../get_next_line_utils.c ../get_next_line.h


DIFF_CNT=`cat result.txt | grep DIFF_KO | wc -l`
LEAK_CNT=`cat result.txt | grep "ERROR SUMMARY" | wc -l`
NORM_CNT=`norminette ../get_next_line.c ../get_next_line_utils.c ../get_next_line.h | grep Error! | wc -l`

printf "\nDiff_KO    : %d\n" $DIFF_CNT
printf "leaks found: %d\n" $LEAK_CNT
printf "norminette : %d\n" $NORM_CNT

CNT=$(expr $DIFF_CNT + $LEAK_CNT + $NORM_CNT)
if [ ${CNT} -eq 0 ]; then
	echo -e "\e[32mGOOD!\e[0m"
else
	echo -e "\e[31m               -#+=:..-  ... .:.::..:-+##@@  @@        \e[0m" 
	echo -e "\e[31m            .##+:.:..:....:.:::.::..       @@@@        \e[0m" 
	echo -e "\e[31m          -#=--:::.::::::::: :.......:--=-             \e[0m" 
	echo -e "\e[31m   .@@@@@#=:.::.:::...:---:-:--::::--++--=+=-=         \e[0m" 
	echo -e "\e[31m   :@@ :   .. .::.::--:::::::------=*===+---=%#        \e[0m" 
	echo -e "\e[31m     @@@  --:=-:==-:::.-:.-----===*-+:=--:-.-=@*       \e[0m" 
	echo -e "\e[31m       .:-+=++++:-++--=-+#=---#==      +=:-:. -%       \e[0m" 
	echo -e "\e[31m       @++#*=+=+=++=++-+:::*+==-  @@@@ -=:-....=@      \e[0m" 
	echo -e "\e[31m       @=--:-.     -+=++*=+*:=* @ @@@@ --.:-:..:#-     \e[0m" 
	echo -e "\e[31m       @-====-#@@@#  .==++**+**:@@@@@  ::-:::--:-@-    \e[0m" 
	echo -e "\e[31m       @.:--- :@@@@@@ -*%***=*-  @@   ..:.:: ..::=@    \e[0m" 
	echo -e "\e[31m       %:--:--  @@@@@@:+:                 .:...:::+@   \e[0m" 
	echo -e "\e[31m      +#:-=-:-.           .@@@@-    #@@@#=. ::::-=-@   \e[0m" 
	echo -e "\e[31m      @-:...:..        @@@@@@@@@@@@@%%@@@@#+-.=-=-=@   \e[0m" 
	echo -e "\e[31m      @-:-.:.  . :-.: :@# #@@@@@@@ :%@@@@@#*=++***%@   \e[0m" 
	echo -e "\e[31m      @=::::=%@@@@@@@#:@@@@@@@@@. +@@@@@%=+*%%%%*#@@   \e[0m" 
	echo -e "\e[31m      @@==-*%@@@@@@@@@=  %@@@@=.@@@@@@+*+=+#*%%#*@@    \e[0m" 
	echo -e "\e[31m      =@@==##*#**#*@@@@@@%#%@@@@  @@==*%#+*+*+*@@@     \e[0m" 
	echo -e "\e[31m       @@@*#%**%%#+:--+@@@@      @@.+*#+***%%@@@@      \e[0m" 
	echo -e "\e[31m        @@@###***#%#*+=:. #@@@@@@**=#*#*%%@@@@%        \e[0m" 
	echo -e "\e[31m          @@@@##***++#%**++*#=++##%#@@@@@@@            \e[0m" 
	echo -e "\e[31m            @@@@@@@@%#%@%%##%%%%%#%@@@@@@@@            \e[0m" 
	echo -e "\e[31m                 @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \e[0m" 
	echo -e "\e[31m                        @@@@@@@@@@@@@@@@%#@@*- .@@@@@@ \e[0m".
	echo -e "\e[31m                      @@=..=::::.                @***+ \e[0m" 
fi
rm result.txt
