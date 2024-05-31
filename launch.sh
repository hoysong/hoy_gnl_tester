
FLAGS="-Wall -Wextra -Werror"
VLGND_FLG="--log-file=val_log --leak-check=full --tool=memcheck"
CFILES="../get_next_line.c ../get_next_line_utils.c"
NO_LEAK=" ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)"
BF="-D BUFFER_SIZE="
COUNT=12

del_dummys() {
	if [ $1 -eq 1 ]; then
		rm $2
	fi
}

tester_init() {
	ORIGIN=`ls | grep origin_output | wc -l`
	del_dummys ${ORIGIN} origin_output
	PROG=`ls | grep prog_output | wc -l`
	del_dummys ${PROG} prog_output
	VAL_LOG=`ls | grep val_log | wc -l`
	del_dummys ${VAL_LOG} val_log
	AOUT=`ls | grep a.out | wc -l`
	del_dummys ${AOUT} a.out
}

run_ivld_fd() {
	SIZE=1
	echo -e "\e[47;1;34mtest_file: $1\e[0m" #gen while line
	echo "==============================test_file: $1==============================" >> trace
	echo >> trace

	while [ $SIZE -le $COUNT ]
	do
		echo -en "\e[1;32mbuff=$SIZE \e[0m"
		echo "[buff=$SIZE]" >> trace

		cc $1 $BF$SIZE $CFILES $FLAGS
		valgrind $VLGND_FLG ./a.out | cat -e > prog_output
		echo -n "(null)(null)" > origin_output
		DIFF_RESULT=`diff origin_output prog_output | wc -l`
		if [ ${DIFF_RESULT} -eq 0 ]; then
			echo -n diff_ok!
		else
			echo -en "\e[31mDIFF_KO\e[0m"

			echo "============diff_ko============" >> trace

			echo "origin_output == $1" >> trace
			cat origin_output >> trace
			echo >> trace
			echo "your_output" >> trace
			cat prog_output >> trace
			echo
			echo "===============================" >> trace
			echo >> trace
		fi

		echo -n " / "

		LEAK_RESULT=`cat val_log | grep "ERROR" | cut -f 5 -d'='`
		if [ "${LEAK_RESULT}" = "${NO_LEAK}" ]; then
			echo -n No_leaks!
		else
#			cat val_log
			echo -en "\e[31mLEAK_KO\e[0m"
			cat	val_log >> trace
			echo >> trace
		fi

		((SIZE++))
		echo
	done
	echo
}

run_test() {
	SIZE=1
	echo -e "\e[47;1;34mtest_file: $1\e[0m" #gen while line
	echo "==============================test_file: $1==============================" >> trace
	echo >> trace

	while [ $SIZE -le $COUNT ]
	do
		echo -en "\e[1;32mbuff=$SIZE \e[0m"
		echo "[buff=$SIZE]" >> trace

		cc $1 $BF$SIZE $CFILES $FLAGS
		valgrind $VLGND_FLG ./a.out | cat -e > prog_output
		cat -e $2* > origin_output
		DIFF_RESULT=`diff origin_output prog_output | wc -l`
		if [ ${DIFF_RESULT} -eq 0 ]; then
			echo -n diff_ok!
		else
			echo -en "\e[31mDIFF_KO\e[0m"

			echo "============diff_ko============" >> trace

			echo "origin_output == $1" >> trace
			cat origin_output >> trace
			echo >> trace
			echo "your_output" >> trace
			cat prog_output >> trace
			echo "===============================" >> trace
			echo >> trace
		fi

		echo -n " / "

		LEAK_RESULT=`cat val_log | grep "ERROR" | cut -f 5 -d'='`
		if [ "${LEAK_RESULT}" = "${NO_LEAK}" ]; then
			echo -n No_leaks!
		else
#			cat val_log
			echo -en "\e[31mLEAK_KO\e[0m"
			cat	val_log >> trace
			echo >> trace
		fi

		((SIZE++))
		echo
	done
	echo
}

#start main
	clear
	echo "launching hoy_tester"
	echo -e "\e[1;32m.__                       __                   __                \e[0m"
	echo -e "\e[1;32m|  |__   ____ ___.__.   _/  |_  ____   _______/  |_  ___________ \e[0m"
	echo -e "\e[1;32m|  |  \ /  _ <   |  |   \   __\/ __ \ /  ___/\   __\/ __ \_  __ \ \e[0m"
	echo -e "\e[1;32m|   Y  (  <_> )___  |    |  | \  ___/ \___ \  |  | \  ___/|  | \/ \e[0m"
	echo -e "\e[1;32m|___|  /\____// ____|____|__|  \___  >____  > |__|  \___  >__|   \e[0m"
	echo -e "\e[1;32m     \/       \/   /_____/         \/     \/            \/       \e[0m"
	echo

	TRACE=`ls | grep trace | wc -l`
	del_dummys ${TRACE} trace
	tester_init
	run_test mains/nl_main.c cases/nl/
	run_test mains/no_nl_main.c cases/no_nl/
	run_test mains/nl_btw_str_main.c cases/nl_btw_str/
	run_test mains/others_main.c cases/others/
	run_ivld_fd mains/ivld_fd.c
	tester_init
	echo "check your trace file to see more information."
#end main
