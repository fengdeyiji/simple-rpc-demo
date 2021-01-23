
all:
	g++ main_test.cpp ./lib/rpc_monitor.cpp ./user/user_message.cpp -I./lib/ -I./user -std=c++11 -o test
clean:
	rm -rf *.o test