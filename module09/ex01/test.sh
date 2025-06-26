#! /bin/bash

echo "TEST \"\"" > logs
./RPN "" >>  logs
echo >> logs

echo "TEST \" \"" >> logs
./RPN " " >>  logs
echo >> logs

echo "TEST \"  \"" >> logs
./RPN "  " >>  logs
echo >> logs

echo "TEST \"a\"" >> logs
./RPN "a" >>  logs
echo >> logs

echo "TEST \"+\"" >> logs
./RPN "+" >>  logs
echo >> logs

echo "TEST \" + \"" >> logs
./RPN " + " >>  logs
echo >> logs

echo "TEST \" -\"" >> logs
./RPN "+" >>  logs
echo >> logs

echo "TEST \"* \"" >> logs
./RPN " + " >>  logs
echo >> logs

echo "TEST \"1\"" >> logs
./RPN "1" >>  logs
echo >> logs

echo "TEST \" 2\"" >> logs
./RPN " 2" >>  logs
echo >> logs

echo "TEST \"3 \"" >> logs
./RPN "3 " >>  logs
echo >> logs

echo "TEST \"12\"" >> logs
./RPN "12" >>  logs
echo >> logs

echo "TEST \" 2 3\"" >> logs
./RPN " 2 3" >>  logs
echo >> logs

echo "TEST \"3 4 \"" >> logs
./RPN "3 4 " >>  logs
echo >> logs

echo "TEST \"2 -\"" >> logs
./RPN "8 -" >>  logs
echo >> logs

echo "TEST \"+12\"" >> logs
./RPN "+12" >>  logs
echo >> logs

echo "TEST \" +23\"" >> logs
./RPN " +23" >>  logs
echo >> logs

echo "TEST \" + 34\"" >> logs
./RPN " + 34" >>  logs
echo >> logs

echo "TEST \" + 4 5\"" >> logs
./RPN " + 4 5" >>  logs
echo >> logs

echo "TEST \" 4 + 5\"" >> logs
./RPN "4 + 5" >>  logs
echo >> logs

echo "TEST \"6 7 - +\"" >> logs
./RPN "6 7 - +" >>  logs
echo >> logs

echo "TEST \"8 9 - + -\"" >> logs
./RPN "8 9 - + -" >>  logs
echo >> logs

echo "TEST \"7 6 - + 0\"" >> logs
./RPN "7 6 - + 0" >>  logs
echo >> logs

echo "TEST \"7 6 -+\"" >> logs
./RPN "7 6 -+" >>  logs
echo >> logs

echo "TEST \"5 6 -\"" >> logs
./RPN "5 6 -" >>  logs
echo >> logs

echo "TEST \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" >> logs
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" >> logs
echo >> logs

echo "TEST \"7 7 * 7 -\"" >> logs
./RPN "7 7 * 7 -" >> logs
echo >> logs

echo "TEST \"1 2 * 2 / 2 * 2 4 - +\"" >> logs
./RPN "1 2 * 2 / 2 * 2 4 - +" >> logs
echo >> logs

echo "TEST \"1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /\"" >> logs
./RPN "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /" >> logs
echo >> logs

echo "TEST \"(1 + 1)\"" >> logs
./RPN "(1 + 1)" >> logs
echo >> logs
