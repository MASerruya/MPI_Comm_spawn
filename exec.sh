if [ -z $1 ]; then
	echo "./exec.sh 1 (for one machine) || ./exec.sh 2 (for two machines)"
elif [ $1 -eq 1 ]; then
	mpirun -np 1 --hostfile machines2 commSizeVar worker 5
elif [ $1 -eq 2 ]; then
	mpirun -np 1 --hostfile machines commSizeVar worker 5
else
	echo "Exclusive execution for one or two machines."
fi
