#!/bin/bash

ARGC=$#
MIN_ARGC="2"

if [ $ARGC -ne $MIN_ARGC ]; then
    echo Expected 2 arguments, min and max.
    exit;
fi

make -C ../

MIN=$1
MAX=$2

echo Creating random sequence between $MIN and $MAX.

SEQ=$(seq -f "%.0f" $MIN $MAX | sort -R | tr '\n' ' ')

echo $SEQ

echo Running push_swap...

../push_swap $SEQ > ops.log
OPCOUNT=$(cat ops.log | wc -l)

echo "sa :$(cat ops.log | grep -x ^sa | wc -l)"
echo "sb :$(cat ops.log | grep -x ^sb | wc -l)"
echo "ss :$(cat ops.log | grep -x ^ss | wc -l)"
echo "pa :$(cat ops.log | grep -x ^pa | wc -l)"
echo "pb :$(cat ops.log | grep -x ^pb | wc -l)"
echo "ra :$(cat ops.log | grep -x ^ra | wc -l)"
echo "rb :$(cat ops.log | grep -x ^rb | wc -l)"
echo "rr :$(cat ops.log | grep -x ^rr | wc -l)"
echo "rra:$(cat ops.log | grep -x ^rra | wc -l)"
echo "rrb:$(cat ops.log | grep -x ^rrb | wc -l)"
echo "rrr:$(cat ops.log | grep -x ^rrr | wc -l)"

echo Total: $OPCOUNT
echo Running checker...

cat ops.log | ./checker $SEQ
