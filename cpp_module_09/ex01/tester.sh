echo "testing ./RPN "3 4 +""
./RPN "3 4 +"

echo "testing ./RPN '5 1 2 + 4 * + 3 -'"
./RPN "5 1 2 + 4 * + 3 -"

echo "testing ./RPN '7 2 3 * -'"
./RPN "7 2 3 * -"

echo "testing ./RPN 9 5 /"
./RPN "9 5 /"

echo "testing ./RPN 2 3 4 + *"
./RPN "2 3 4 + *"

echo "testing ./RPN 6 3 2 - /"
./RPN "6 3 2 - /"

echo "testing ./RPN 1 2 8 * + 3 -"
./RPN "1 2 8 * + 3 -"

echo "testing ./RPN 4 6 + 3 2 + *"
./RPN "4 6 + 3 2 + *"

echo "testing ./RPN 5 1 2 + 4 * 3 - +"
./RPN "5 1 2 + 4 * 3 - +"

echo "testing ./RPN 8 2 + 5 * 9 +"
./RPN "8 2 + 5 * 9 +"

echo "testing ./RPN 10 2 8 * + 3 -"
./RPN "10 2 8 * + 3 -"

echo "testing ./RPN 10 2 8 * + 3 -"
./RPN "10 -2 8 * + 3 -"

echo "testing ./RPN 2147483649 2 8 * + 3 -"
./RPN "10 2 8 * + 3 -"




