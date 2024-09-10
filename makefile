all: .SILENT

.SILENT:
	cp ../tests/answers/ ./answers -r
	valgrind ./run
	rm *.dot
	lcov --capture --directory ./CMakeFiles/libs.dir/src/libs/ --output-file gcov.info
	lcov --directory . --zerocounters
	lcov --remove gcov.info '/usr/*' --output-file gcov_filtered.info
	genhtml gcov_filtered.info --output-directory html_cov
	rm *.info