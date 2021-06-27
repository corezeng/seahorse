#include"Inotify.h"

using namespace seahorse;

Inotify::Inotify(){
    _inotifyFd=inotify_init();
}

Inotify::~Inotify(){

}

int Inotify::addWatchFile(const seahorse::chars& filePath,
                          std::function<void(void*,const seahorse::chars&)> action){

    _watchFiles.push_back(filePath);

}