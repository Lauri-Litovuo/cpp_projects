echo "This is a test" > test1.txt
echo "file1:"
cat test1.txt
echo "file2:"
echo "Nothing to replace" > test2.txt
cat test2.txt

# Run some simple test cases
echo "\nReplacing 'test' with 'success' in test1.txt"
./mySed test1.txt test success
cat test1.txt.replace

echo "\nReplacing 'abc' with 'xyz' in test2.txt"
./mySed test2.txt abc xyz
cat test2.txt.replace

echo "\nempty file"
touch empty.txt
./mySed empty.txt test exam
cat empty.txt.replace

echo "\nnonexistent file"
./mySed nonexistent.txt test