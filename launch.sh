#.__                       __                   __                
#|  |__   ____ ___.__.   _/  |_  ____   _______/  |_  ___________ 
#|  |  \ /  _ <   |  |   \   __\/ __ \ /  ___/\   __\/ __ \_  __ \
#|   Y  (  <_> )___  |    |  | \  ___/ \___ \  |  | \  ___/|  | \/
#|___|  /\____// ____|____|__|  \___  >____  > |__|  \___  >__|   
#     \/       \/   /_____/         \/     \/            \/       

FLAGS="-Wall -Wextra -Werror"
CFILES="../get_next_line.c ../get_next_line_utils.c"
LEAK=" ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)"
BF="-D BUFFER_SIZE="
SIZE=0
COUNT=12

#echo -e "\e[47;34m\e[1m"
#echo -e "\e[47;34mBUFFER=0\e[0m"
#
#echo -e "\e[;32mnl_main.c_test\e[0m"
#cc mains/nl_main.c $BF$SIZE $CFILES $FLAGS -g
#valgrind --log-file=log_buff_file --tool=memcheck --leak-check=full ./a.out > prog_output
#LEAK_RESULT=`cat log_buff_file | grep "ERROR" | cut -f 5 -d'='`
#if [ "${LEAK_RESULT}" = "${LEAK}" ];then
#	echo  No_leaks!
#else
#	cat log_buff_file
#fi
#cat prog_output -e > prog_output_e
#DIFF_RESULT=`cat prog_output_e | wc -l`
#if [ ${DIFF_RESULT} -eq 0 ]; then
#	echo -e "\e[34mDiff_ok\e[0m"
#else
#	echo -e "\e[31mDiff_KO\e[0m"
#fi
#rm log_buff_file prog_output prog_output_e
#
#echo -e "\e[;32mno_nl_main.c_test\e[0m"
#cc mains/no_nl_main.c $BF$SIZE $CFILES $FLAGS -g
#valgrind --log-file=log_buff_file --tool=memcheck --leak-check=full ./a.out > prog_output
#LEAK_RESULT=`cat log_buff_file | grep "ERROR" | cut -f 5 -d'='`
#if [ "${LEAK_RESULT}" = "${LEAK}" ];then
#	echo  No_leaks!
#else
#	cat log_buff_file
#fi
#cat prog_output -e > prog_output_e
#DIFF_RESULT=`cat prog_output_e | wc -l`
#if [ ${DIFF_RESULT} -eq 0 ]; then
#	echo -e "\e[34mDiff_ok\e[0m"
#else
#	echo -e "\e[31mDiff_KO\e[0m"
#fi
#rm log_buff_file prog_output prog_output_e
#
#echo -e "\e[;32mnl_btw_str_main.c_test\e[0m"
#cc mains/nl_btw_str_main.c $BF$SIZE $CFILES $FLAGS -g
#valgrind --log-file=log_buff_file --tool=memcheck --leak-check=full ./a.out > prog_output
#LEAK_RESULT=`cat log_buff_file | grep "ERROR" | cut -f 5 -d'='`
#if [ "${LEAK_RESULT}" = "${LEAK}" ];then
#	echo  No_leaks!
#else
#	cat log_buff_file
#fi
#cat prog_output -e > prog_output_e
#DIFF_RESULT=`cat prog_output_e | wc -l`
#if [ ${DIFF_RESULT} -eq 0 ]; then
#	echo -e "\e[34mDiff_ok\e[0m"
#else
#	echo -e "\e[31mDiff_KO\e[0m"
#fi
#rm log_buff_file prog_output prog_output_e
#
#echo -e "\e[;32mothers_main.c_test\e[0m"
#cc mains/others_main.c $BF$SIZE $CFILES $FLAGS -g
#valgrind --log-file=log_buff_file --tool=memcheck --leak-check=full ./a.out > prog_output
#LEAK_RESULT=`cat log_buff_file | grep "ERROR" | cut -f 5 -d'='`
#if [ "${LEAK_RESULT}" = "${LEAK}" ];then
#	echo  No_leaks!
#else
#	cat log_buff_file
#fi
#cat prog_output -e > prog_output_e
#DIFF_RESULT=`cat prog_output_e | wc -l`
#if [ ${DIFF_RESULT} -eq 0 ]; then
#	echo -e "\e[34mDiff_ok\e[0m"
#else
#	echo -e "\e[31mDiff_KO\e[0m"
#fi
#rm log_buff_file prog_output prog_output_e
#
#echo -e "\e[;32mivld_fd\e[0m"
#cc mains/ivld_fd.c $BF$SIZE $CFILES $FLAGS -g
#valgrind --log-file=log_buff_file --tool=memcheck --leak-check=full ./a.out > prog_output
#LEAK_RESULT=`cat log_buff_file | grep "ERROR" | cut -f 5 -d'='`
#if [ "${LEAK_RESULT}" = "${LEAK}" ];then
#	echo  No_leaks!
#else
#	cat log_buff_file
#fi
#cat prog_output -e > prog_output_e
#DIFF_RESULT=`cat prog_output_e | wc -l`
#if [ ${DIFF_RESULT} -eq 0 ]; then
#	echo -e "\e[34mDiff_ok\e[0m"
#else
#	echo -e "\e[31mDiff_KO\e[0m"
#fi
#rm log_buff_file prog_output prog_output_e

SIZE=1
echo -e "\e[47;34m\e[1m"
echo -e "\e[47;34mnl_main.c_test\e[0m"
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
		echo -e "\e[34mDiff_ok\e[0m"
	else
		echo -e "\e[31mDiff_KO\e[0m"
	fi
	rm log_buff_file prog_output origin_output prog_output_e
	((SIZE++))
done
SIZE=1

echo -e "\e[47;34m\e[1m"
echo -e "\e[47;34mno_nl_main.c_test\e[0m"
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
		echo -e "\e[34mDiff_ok\e[0m"
	else
		echo -e "\e[31mDiff_KO\e[0m"
	fi
	rm log_buff_file prog_output origin_output prog_output_e
	((SIZE++))
done
SIZE=1

echo -e "\e[47;34m\e[1m"
echo -e "\e[47;34mnl_btw_str_main.c_test\e[0m"
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
		echo -e "\e[34mDiff_ok\e[0m"
	else
		echo -e "\e[31mDiff_KO\e[0m"
	fi
	rm log_buff_file prog_output origin_output prog_output_e
	((SIZE++))
done
SIZE=1

echo -e "\e[47;34m\e[1m"
echo -e "\e[47;34mothers_main.c_test\e[0m"
while [ $SIZE -le 5 ]
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
		echo -e "\e[34mDiff_ok\e[0m"
	else
		echo -e "\e[31mDiff_KO\e[0m"
	fi
	rm log_buff_file prog_output origin_output prog_output_e
	((SIZE++))
done
SIZE=1

echo -e "\e[47;34m\e[1m"
echo -e "\e[47;34minvaild_fd.c_test\e[0m"
while [ $SIZE -le 5 ]
do
	echo -e "\e[32mSIZE=$SIZE\e[0m"
	cc mains/ivld_fd.c $CFILES $FLAGS -g
	valgrind --log-file=log_buff_file --tool=memcheck --leak-check=full ./a.out > prog_output
	LEAK_RESULT=`cat log_buff_file | grep "ERROR" | cut -f 5 -d'='`
	if [ "${LEAK_RESULT}" = "${LEAK}" ];then
		echo  No_leaks!
	else
		cat log_buff_file
	fi
	echo -n "(null)(null)" > origin_output
	cat prog_output -e > prog_output_e
	DIFF_RESULT=`diff origin_output prog_output_e | wc -l`
	if [ ${DIFF_RESULT} -eq 0 ]; then
		echo -e "\e[34mDiff_ok\e[0m"
	else
		echo -e "\e[31mDiff_KO\e[0m"
	fi
	rm log_buff_file prog_output origin_output prog_output_e
	((SIZE++))
done
SIZE=1
rm a.out
