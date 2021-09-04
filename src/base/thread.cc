// #include "Thread.h"

// using namespace seahorse;

// Thread::Thread(ThreadFunc func,std::unique_ptr<void*> funcAddOnArg):
// _threadArg(*this,funcAddOnArg.release()),
// _func(func),
// _isRunning(false),
// _isBusy(false),
// _thread(nullptr){

// }

// Thread::~Thread(){
//     if(_isBusy){
//         // TODO 需要添加机制
//     }
//     if(_isRunning){
//         stop();
//     }
// }

// void Thread::run(bool join){
//     if(!_thread){
//         _thread.reset(new std::thread(_func));
//     }
//     else{
//         if(!_isRunning){
//         }
//     }
// }

// void Thread::stop(bool rightnow){
//     if(_isBusy){

//     }
//     if(_isRunning){
//         if(rightnow){
//             _threadArg._keepRuning=2;
//         }
//         else{
//             _threadArg._keepRuning=1;
//         }
//     }
//     // TODO 鲁棒性
// }

// void Thread::join(){
//     if(_isRunning){
//         if(_thread){
//             if(_thread->joinable()){
//                 _thread->join();
//             }
//         }
//     }
// }