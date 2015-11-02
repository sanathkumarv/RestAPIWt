librttr.a : *.o
	g++ -c -I /RestAPIWt/tools/rttr-0.9.0/src *.cpp -std=c++0x
	g++ -c -I /RestAPIWt/tools/rttr-0.9.0/src detail/*.cpp -std=c++0x
	ar -cr  librttr.a *.o
	ranlib librttr.a

