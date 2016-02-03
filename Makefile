all:
	g++ *.cpp Log/*.cpp
run:
	./a.out
clean:
	rm a.out
get-dependancies:
	git clone https://github.com/srz2/CPlusPlus-Log-.git Log
rm-dependancies:
	rm -rf Log
