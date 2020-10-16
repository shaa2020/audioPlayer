gc = /usr/bin/gcc
dependencies += -lstdc++ -lopenal -lpthread src/*.cpp
all:
	${gc} main.cpp -o audioPlayer ${dependencies}

clean: 
	rm audioPlayer