Mock Linux Shell
CSCE 313 (adapted from assignment)

Pseudo Linux Shell with support for cd, commands,
quotes, background processes, input and output
re-direction, and piping between processes.

Run using ./shell (must be run on a Linux
distribution such as Ubuntu).

Runs like a regular Linux Shell. Examples:
cd ..
cd -
ls -l
echo "Hello World"
sleep 5 &
sleep 5
ps aux > a.txt
grep root < a.txt > b.txt
ls -l | grep shell