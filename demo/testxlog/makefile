CC=g++
INCLUDE=-I../xlog
CTAG=-L./ $(INCLUDE) -g
OUT=testxlog
LIBS=-lxlog
SOCC=$(CC) $+ -o $@ -shared -fPIC
OCC=$(CC) $+ -c $(CTAG)
OBJ=testxlog.o
$(OUT):$(OBJ) libxlog.so
	$(CC) $(OBJ) -o $@ $(LIBS) $(CTAG)
testxlog.o:testxlog.cpp
	$(OCC)
libxlog.so:../xlog/xlog.cpp ../xlog/xlog.h
	$(SOCC)
clean:
	rm *.o -rf
	rm *.so -rf
	rm testxlog -rf





