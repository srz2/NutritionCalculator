all:
	g++ *.cpp Log/*.cpp -o n-cal
run:
	./n-cal
clean:
	rm n-cal
get-dependancies:
	git clone https://github.com/srz2/CPlusPlus-Log-.git Log
rm-dependancies:
	rm -rf Log
