PROGRAM		= formula
CXX 		= g++
CXXFLAGS	= -Wall -std=c++14
SOURCEDIR	= sources
INCLUDEDIR	= headers
BUILDDIR	= bin
ASSETSDIR	= assets
SOURCES		= $(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS		= $(patsubst $(SOURCEDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

all: dir $(BUILDDIR)/$(PROGRAM)
	@make run

dir:
	@mkdir -p $(BUILDDIR)

$(BUILDDIR)/$(PROGRAM): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ -I$(INCLUDEDIR)

$(OBJECTS): $(BUILDDIR)/%.o: $(SOURCEDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ -c -I$(INCLUDEDIR)

.PHONY: clean run

clean:
	@rm -rf $(BUILDDIR)

run:
	@echo "===================== PROGRAM EXECUTION ====================="
	@echo ""
	@exec $(BUILDDIR)/$(PROGRAM)
	@echo ""
	@echo "==================== EXECUTION  FINISHED ===================="

