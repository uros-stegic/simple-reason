.PHONY: all build clean

all:
	@$(MAKE) -s build
build:
	@mkdir -p build
	@cd build; \
	cmake ..;\
	make;\
	echo "================ Executing program ================";\
	time ./simple-reason;\
	echo "===================================================";

clean:
	@rm -rf build
