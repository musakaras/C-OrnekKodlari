target:hw

hw:    hw.cpp
		g++ -std=c++11 hw.cpp -o hw

clean:
	rm hw
