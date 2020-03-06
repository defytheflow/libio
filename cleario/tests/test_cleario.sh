#!/bin/bash

# Test suites for 'cleario' library.
# Last tested: March 6, 2020.

test_get_int()
{
    local i=42
    local l=2147483650
    local ll=1000000000000000
    local s="galaxy"

    # Check that 'get_int' skips white space characters and
    # successfully retrieves the integer.
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
    assertFalse echo "$s"    | ./test_get_int > /dev/null
    assertFalse echo "$i$s"  | ./test_get_int > /dev/null
    assertFalse echo "$s$i"  | ./test_get_int > /dev/null

    # Check that 'get_int' fails if input does not fit in a SIGNED INTEGER.
    assertFalse echo "$l"    | ./test_get_int > /dev/null
    assertFalse echo "-$l"   | ./test_get_int > /dev/null
    assertFalse echo "$ll"   | ./test_get_int > /dev/null
    assertFalse echo "-$ll"  | ./test_get_int > /dev/null
}

test_get_float()
{
    local f=42.0
    local lf="99999999999999999999999999999999999999999.999999999"
    local s="galaxy"

    # Check that 'get_float' skips white space characters and
    # successfully retrieves the integer.
    assertTrue echo "  $f"   | ./test_get_float > /dev/null
    assertTrue echo "$f  "   | ./test_get_float > /dev/null
    assertTrue echo "\t$f"   | ./test_get_float > /dev/null
    assertTrue echo "$f\t"   | ./test_get_float > /dev/null
    assertTrue echo "  \t$f" | ./test_get_float > /dev/null
    assertTrue echo "$f\t  " | ./test_get_float > /dev/null
    assertTrue echo "\n$f\n" | ./test_get_float > /dev/null

    # Check that 'get_float' fails if reaches EOF.
    assertFalse echo ""      | ./test_get_float > /dev/null

    # Check that 'get_float' fails when receives non-numeric input.
    assertFalse echo "$s"    | ./test_get_float > /dev/null
    assertFalse echo "$f$s"  | ./test_get_float > /dev/null
    assertFalse echo "$s$f"  | ./test_get_float > /dev/null

    # Check that 'get_float' fails if input does not fit in a FLOAT.
    assertFalse echo "$lf"    | ./test_get_float > /dev/null
    assertFalse echo "-$lf"   | ./test_get_float > /dev/null
}

test_get_string()
{
    local s="galaxy"

    # Check that 'get_string' skips white space characters and
    # successfully retrieves the string.
    assertTrue echo "  $s"   | ./test_get_string > /dev/null
    assertTrue echo "$s  "   | ./test_get_string > /dev/null
    assertTrue echo "\t$s"   | ./test_get_string > /dev/null
    assertTrue echo "$s\t"   | ./test_get_string > /dev/null
    assertTrue echo "  \t$s" | ./test_get_string > /dev/null
    assertTrue echo "$s\t  " | ./test_get_string > /dev/null
    assertTrue echo "\n$s\n" | ./test_get_string > /dev/null

    # Check that 'get_string' fails if reaches EOF.
    assertFalse echo ""      | ./test_get_string > /dev/null
}
