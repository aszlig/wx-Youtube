.PHONY: clean all wxyoutube
CFLAGS=-g `wx-config --cxxflags`
LIBS=`wx-config --libs` -lcurl

GLOBAL_HEADERS = Enums.hpp
#CPPFILES = $(wildcard *.cpp)
CPPFILES = ProgressBar.cpp Parser.cpp ImageProc.cpp ImageBox.cpp \
	   ThumbnailFrame.cpp VideoInfo.cpp CommentInfo.cpp CommentsBoard.cpp \
	   VideoDescription.cpp EventHandler.hpp Events.cpp EventManager.cpp \
	   DownloadCallback.cpp SearchURL.cpp XMLFeed.cpp FeedFetcherThread.cpp \
	   DownloadThread.cpp VideoEntry.cpp PrefWindow.cpp VideoListCtrl.cpp \
	   MainFrame.cpp MainApp.cpp Extract.cpp

all: wxyoutube

wxyoutube: $(GLOBAL_HEADERS) $(CPPFILES:.cpp=.o)
	$(CXX) -o wx-Youtube $^ $(CFLAGS) $(LIBS)

clean:
	@$(RM) wx-Youtube *.o

%.o: %.cpp %.hpp
	$(CXX) -c -o $@ $< $(CFLAGS)
