#!/bin/bash

test_get_int()
{
    # Check that 'get_int' skips white space characters and
    # successfully retrieves the integer.
    local i=42

    assertTrue echo "  $i"   | ./test_get_int > /dev/null
    assertTrue echo "$i  "   | ./test_get_int > /dev/null
    assertTrue echo "\t$i"   | ./test_get_int > /dev/null
    assertTrue echo "$i\t"   | ./test_get_int > /dev/null
    assertTrue echo "  \t$i" | ./test_get_int > /dev/null
    assertTrue echo "$i\t  " | ./test_get_int > /dev/null
    assertTrue echo "\n$i\n" | ./test_get_int > /dev/null

    # Check that 'get_int' fails if reaches EOF.
    assertFalse echo ""      | ./test_get_int > /dev/null

    # Check that 'get_int' fails when receives non-numeric input.
    local s="galaxy"

    assertFalse echo "$s"    | ./test_get_int > /dev/null
    assertFalse echo "$i$s"  | ./test_get_int > /dev/null
    assertFalse echo "$s$i"  | ./test_get_int > /dev/null

    # Check that 'get_int' fails if input does not fit in a signed integer.
    local l=2147483650
    local ll=1000000000000000

    assertFalse echo "$l"    | ./test_get_int > /dev/null
    assertFalse echo "-$l"   | ./test_get_int > /dev/null
    assertFalse echo "$ll"   | ./test_get_int > /dev/null
    assertFalse echo "-$ll"  | ./test_get_int > /dev/null
}
