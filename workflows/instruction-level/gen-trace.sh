#!/bin/bash

if [ "$#" -ne 2 ]; then
	exit 1
fi

file=$1
trace_dir=$2
TRACE_FILE=$trace_dir/$(basename $file).tr

# Start spike
spike -l --isa=rv32e $file 2> $TRACE_FILE &
SPIKE_PID=$!

on_ctrl_c() {
	kill $SPIKE_PID
	wait $SPIKE_PID 2>/dev/null
	exit 1
}

trap on_ctrl_c SIGINT

while [ ! -f $TRACE_FILE ]; do
	sleep 1
done

echo "Tracing $file"
while true; do
	sleep 1
	last_line=$(tail -n 1 "$TRACE_FILE" 2>/dev/null)
	if [[ $last_line == *"pc + 0x0"* ]]; then
		echo "Trace complete"
		kill $SPIKE_PID
		break
	fi
	echo $last_line
done

wait $SPIKE_PID 2>/dev/null

