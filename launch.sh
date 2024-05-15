#.__                       __                   __                
#|  |__   ____ ___.__.   _/  |_  ____   _______/  |_  ___________ 
#|  |  \ /  _ <   |  |   \   __\/ __ \ /  ___/\   __\/ __ \_  __ \
#|   Y  (  <_> )___  |    |  | \  ___/ \___ \  |  | \  ___/|  | \/
#|___|  /\____// ____|____|__|  \___  >____  > |__|  \___  >__|   
#     \/       \/   /_____/         \/     \/            \/       
FLAGS="-Wall -Wextra -Werror"
CFILES="../get_next_line.c ../get_next_line_utils.c"
LEAK=" ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)"
SIZE=0
COUNT=12

echo -e "\e[43;31mnl_main.c_test\e[0m"
while [ $SIZE -le $COUNT ]
do
	echo -e "\e[32mSIZE=$SIZE\e[0m"
	cc mains/nl_main.c $CFILES $FLAGS -g
	valgrind --log-file=log_buff_file --tool=memcheck --leak-check=full ./a.out > prog_output
	LEAK_RESULT=`cat log_buff_file | grep "ERROR" | cut -f 5 -d'='`
	if [ "${LEAK_RESULT}" = "${LEAK}" ];then
		echo  No_leaks!
	else
		cat log_buff_file
	fi
	cat cases/nl/* -e > origin_output
	cat prog_output -e > prog_output_e
	DIFF_RESULT=`diff origin_output prog_output_e | wc -l`
	if [ ${DIFF_RESULT} -eq 0 ]; then
		echo Diff_ok!
	else
		echo DIFF_KO
	fi
	rm log_buff_file
	rm prog_output
	rm origin_output
	rm prog_output_e
	((SIZE++))
	echo
done
SIZE=0

echo -e "\e[43;31mno_nl_main.c_test\e[0m"
while [ $SIZE -le $COUNT ]
do
	echo -e "\e[32mSIZE=$SIZE\e[0m"
	cc mains/no_nl_main.c $CFILES $FLAGS -g
	valgrind --log-file=log_buff_file --tool=memcheck --leak-check=full ./a.out > prog_output
	LEAK_RESULT=`cat log_buff_file | grep "ERROR" | cut -f 5 -d'='`
	if [ "${LEAK_RESULT}" = "${LEAK}" ];then
		echo  No_leaks!
	else
		cat log_buff_file
	fi
	cat cases/no_nl/* -e > origin_output
	cat prog_output -e > prog_output_e
	DIFF_RESULT=`diff origin_output prog_output_e | wc -l`
	if [ ${DIFF_RESULT} -eq 0 ]; then
		echo Diff_ok!
	else
		echo DIFF_KO
	fi
	rm log_buff_file prog_output origin_output prog_output_e
	((SIZE++))
	echo
done
SIZE=0

echo -e "\e[43;31mothers_main.c_test\e[0m"
while [ $SIZE -le $COUNT ]
do
	echo -e "\e[32mSIZE=$SIZE\e[0m"
	cc mains/others_main.c $CFILES $FLAGS -g
	valgrind --log-file=log_buff_file --tool=memcheck --leak-check=full ./a.out > prog_output
	LEAK_RESULT=`cat log_buff_file | grep "ERROR" | cut -f 5 -d'='`
	if [ "${LEAK_RESULT}" = "${LEAK}" ];then
		echo  No_leaks!
	else
		cat log_buff_file
	fi
	cat cases/others/* -e > origin_output
	cat prog_output -e > prog_output_e
	DIFF_RESULT=`diff origin_output prog_output_e | wc -l`
	if [ ${DIFF_RESULT} -eq 0 ]; then
		echo Diff_ok!
	else
		echo DIFF_KO
	fi
	rm log_buff_file prog_output origin_output prog_output_e
	((SIZE++))
	echo
done
SIZE=0

echo -e "\e[43;31mnl_btw_str_main.c_test\e[0m"
while [ $SIZE -le $COUNT ]
do
	echo -e "\e[32mSIZE=$SIZE\e[0m"
	cc mains/nl_btw_str_main.c $CFILES $FLAGS -g
	valgrind --log-file=log_buff_file --tool=memcheck --leak-check=full ./a.out > prog_output
	LEAK_RESULT=`cat log_buff_file | grep "ERROR" | cut -f 5 -d'='`
	if [ "${LEAK_RESULT}" = "${LEAK}" ];then
		echo  No_leaks!
	else
		cat log_buff_file
	fi
	cat cases/nl_btw_str/* -e > origin_output
	cat prog_output -e > prog_output_e
	DIFF_RESULT=`diff origin_output prog_output_e | wc -l`
	if [ ${DIFF_RESULT} -eq 0 ]; then
		echo Diff_ok!
	else
		echo DIFF_KO
	fi
	rm log_buff_file prog_output origin_output prog_output_e
	((SIZE++))
	echo
done
SIZE=0
