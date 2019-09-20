for i in {1..100};
	do
	a=$(python -c "import random; print ' '.join({str(random.randrange(-10000, 10000)) for x in range(500)})");
	out=$(./push_swap $a | ./checker $a);
	if [[ $out != 'OK' ]]; then
		echo "$out\n";
#		echo "$a\n" > out.txt;
#		break;
	fi
	done
