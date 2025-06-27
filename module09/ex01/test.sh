#! /bin/bash

OUTPUT=logs

echo "TEST \"\"" > "$OUTPUT"
./RPN "" >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \" \"" >> "$OUTPUT"
./RPN " " >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"  \"" >> "$OUTPUT"
./RPN "  " >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"a\"" >> "$OUTPUT"
./RPN "a" >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"+\"" >> "$OUTPUT"
./RPN "+" >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \" + \"" >> "$OUTPUT"
./RPN " + " >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \" -\"" >> "$OUTPUT"
./RPN "+" >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"* \"" >> "$OUTPUT"
./RPN " + " >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1\"" >> "$OUTPUT"
./RPN "1" >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \" 2\"" >> "$OUTPUT"
./RPN " 2" >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"3 \"" >> "$OUTPUT"
./RPN "3 " >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"12\"" >> "$OUTPUT"
./RPN "12" >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \" 2 3\"" >> "$OUTPUT"
./RPN " 2 3" >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"3 4 \"" >> "$OUTPUT"
./RPN "3 4 " >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"2 -\"" >> "$OUTPUT"
./RPN "8 -" >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"+12\"" >> "$OUTPUT"
./RPN "+12" >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \" +23\"" >> "$OUTPUT"
./RPN " +23" >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \" + 34\"" >> "$OUTPUT"
./RPN " + 34" >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \" + 4 5\"" >> "$OUTPUT"
./RPN " + 4 5" >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \" 4 + 5\"" >> "$OUTPUT"
./RPN "4 + 5" >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"6 7 - +\"" >> "$OUTPUT"
./RPN "6 7 - +" >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"8 9 - + -\"" >> "$OUTPUT"
./RPN "8 9 - + -" >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"7 6 - + 0\"" >> "$OUTPUT"
./RPN "7 6 - + 0" >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"7 6 -+\"" >> "$OUTPUT"
./RPN "7 6 -+" >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"5 6 -\"" >> "$OUTPUT"
./RPN "5 6 -" >>  "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" >> "$OUTPUT"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"7 7 * 7 -\"" >> "$OUTPUT"
./RPN "7 7 * 7 -" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2 * 2 / 2 * 2 4 - +\"" >> "$OUTPUT"
./RPN "1 2 * 2 / 2 * 2 4 - +" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /\"" >> "$OUTPUT"
./RPN "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"(1 + 1)\"" >> "$OUTPUT"
./RPN "(1 + 1)" >> "$OUTPUT"
echo >> "$OUTPUT"

#gpt tests
echo "GPT TESTS" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"4 2 /\"" >> "$OUTPUT"
./RPN "4 2 /" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"9 3 /\"" >> "$OUTPUT"
./RPN "9 3 /" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"5 1 2 + 4 * + 3 -\"" >> "$OUTPUT"
./RPN "5 1 2 + 4 * + 3 -" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"2 3 8 + 5 - *\"" >> "$OUTPUT"
./RPN "2 3 8 + 5 - *" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"9 3 / 2 * 5 +\"" >> "$OUTPUT"
./RPN "9 3 / 2 * 5 +" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2 3 4 5 + + + +\"" >> "$OUTPUT"
./RPN "1 2 3 4 5 + + + +" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2 + 3 4 + *\"" >> "$OUTPUT"
./RPN "1 2 + 3 4 + *" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2 3 +\"" >> "$OUTPUT"
./RPN "1 2 3 +" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2 + +\"" >> "$OUTPUT"
./RPN "1 2 + +" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2 3 + -\"" >> "$OUTPUT"
./RPN "1 2 3 + -" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2 3 4 +\"" >> "$OUTPUT"
./RPN "1 2 3 4 +" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2 3 4 + *\"" >> "$OUTPUT"
./RPN "1 2 3 4 + *" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2 3 4 + * *\"" >> "$OUTPUT"
./RPN "1 2 3 4 + * *" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2 3 4 + * * *\"" >> "$OUTPUT"
./RPN "1 2 3 4 + * * *" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 0 /\"" >> "$OUTPUT"
./RPN "1 0 /" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"0 0 /\"" >> "$OUTPUT"
./RPN "0 0 /" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"-1 -2 +\"" >> "$OUTPUT"
./RPN "-1 -2 +" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"-3 4 *\"" >> "$OUTPUT"
./RPN "-3 4 *" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"3 -4 *\"" >> "$OUTPUT"
./RPN "3 -4 *" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"-3 -4 *\"" >> "$OUTPUT"
./RPN "-3 -4 *" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1000000 1000000 *\"" >> "$OUTPUT"
./RPN "1000000 1000000 *" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2 3 4 5 6 7 8 9 + + + + + + + +\"" >> "$OUTPUT"
./RPN "1 2 3 4 5 6 7 8 9 + + + + + + + +" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2 + 3 4 + 5 6 + + +\"" >> "$OUTPUT"
./RPN "1 2 + 3 4 + 5 6 + + +" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2 + 3 4 + 5 6 + +\"" >> "$OUTPUT"
./RPN "1 2 + 3 4 + 5 6 + +" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2 + 3 4 + 5 6 +\"" >> "$OUTPUT"
./RPN "1 2 + 3 4 + 5 6 +" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2 + 3 4 + 5 6\"" >> "$OUTPUT"
./RPN "1 2 + 3 4 + 5 6" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2 + 3 4 + 5\"" >> "$OUTPUT"
./RPN "1 2 + 3 4 + 5" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2 + 3 4 +\"" >> "$OUTPUT"
./RPN "1 2 + 3 4 +" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2 + 3 4 + +\"" >> "$OUTPUT"
./RPN "1 2 + 3 4 + +" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2 + 3 4\"" >> "$OUTPUT"
./RPN "1 2 + 3 4" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2 + 3\"" >> "$OUTPUT"
./RPN "1 2 + 3" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2 +\"" >> "$OUTPUT"
./RPN "1 2 +" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1 2\"" >> "$OUTPUT"
./RPN "1 2" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"1\"" >> "$OUTPUT"
./RPN "1" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"\"" >> "$OUTPUT"
./RPN "" >> "$OUTPUT"
echo >> "$OUTPUT"

echo "TEST \"0 1 /\"" >> "$OUTPUT"
./RPN "0 1 /" >> "$OUTPUT"
echo >> "$OUTPUT"
